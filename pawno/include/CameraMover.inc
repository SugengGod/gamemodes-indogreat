/*
 *  Southclaw's Cinematic Camera Script
 *
 *		Version 2.5
 *
 *			Easy file loaded data
 *			Easy to create cameras
 *			Edit data without recompiling script!
 *			Full editor support added (Editor is now an FS)
 *          Shift data array functions
 *          More controls
 *          Project editor coming soon!
 */
#include <sscanf2>

// Generic Definitions
#define YELLOW 0xFFFF00FF
#define RED 0xAA3333AA
#define Msg SendClientMessage // I'm not the only one this lazy right?

#define MAX_CAMERAS			16	// Max cameras that can be loaded at once
#define MAX_CAMNODE			16	// Max camera nodes that can be loaded for one camera
#define MAX_CAMFILE_LEN		64	// Length for file names in loading and saving
#define MAX_CAMDATA			9   // Amount data of cells in cam_Data

#define CAMERA_FILE			"Cameras/%s.cam"

#define DEFAULT_MOVETIME    3000
#define DEFAULT_WAITTIME    0
#define DEFAULT_MOVETYPE    CAMERA_MOVE

enum ENUM_DATA_TYPES
{
	p_CamID,
	p_Node
}
enum CAM_DATA_ENUM
{
	Float:cam_cPosX,		// Position coords
	Float:cam_cPosY,
	Float:cam_cPosZ,
	Float:cam_lPosX,		// Lookat coords
	Float:cam_lPosY,
	Float:cam_lPosZ,
	cam_moveTime,			// Time in MS to move between each node
	cam_waitTime,			// Time in MS to wait before moving
	cam_moveType			// Camera move type (Cut or Move)
}


new
	camData[MAX_CAMERAS][MAX_CAMNODE][CAM_DATA_ENUM],
	camFilename[MAX_CAMERAS][MAX_CAMFILE_LEN],
	camNodeTimer[MAX_CAMERAS],      // For stopping the timer when the camera pauses
	camMaxNodes[MAX_CAMERAS],		// Maximum nodes for this camera
	bool:camIdUsed[MAX_CAMERAS],	// Determines whether the ID is used or not
	bool:camPaused[MAX_CAMERAS],	// Determines whether the camera is paused
	bool:camMoving[MAX_CAMERAS],	// True whem the camera moves from one node to another
	gPlayerCamData[MAX_PLAYERS][ENUM_DATA_TYPES],
	Float:camPausePos[MAX_CAMERAS][6];

forward internal_OnCamMove(playerid, node, bool:cont);
forward OnCameraReachNode(playerid, camera, node);
forward UpdateFreeCam(playerid);

stock LoadCameraMover(filename[])
{
	new id;
	while(camIdUsed[id] && id<=MAX_CAMERAS)id++;
	if(id == MAX_CAMERAS)return print("ERROR: Camera ID limit reached");

	#define TMP_LOAD		(0)	// The cell that SSCANF loads into
	#define TMP_KEEP		(1)	// The cell that carries over to the next loop itteration
	#define TMP_DATA_COUNT  (3)	// Number of cells in 'tmpData'


	format(camFilename[id], MAX_CAMFILE_LEN, "Cameras/%s.cam", filename);
	if(!fexist(camFilename[id]))return printf("ERROR: Camera data file '%s' not found", camFilename[id]);

	new
	    File:camFile,
	    line[128],
	    idx,
		tmpData[2][TMP_DATA_COUNT]; // optional data: cam_moveTime, cam_waitTime, cam_moveType

	// Default values in case no values are defined in the file
	tmpData[1][0] = 3000;
	tmpData[1][1] = 0;
	tmpData[1][2] = CAMERA_MOVE;

	camFile = fopen(camFilename[id], io_read);

	while(fread(camFile, line, 128))
	{
		if (idx == MAX_CAMNODE)
		{
			print("ERROR: Camera node limit reached");
			break;
		}
		if (!sscanf(line, "p<,>ffffffD(-1)D(-1)D(-1)", // Too much for one line
			camData[id][idx][cam_cPosX], camData[id][idx][cam_cPosY], camData[id][idx][cam_cPosZ],
			camData[id][idx][cam_lPosX], camData[id][idx][cam_lPosY], camData[id][idx][cam_lPosZ],
			tmpData[TMP_LOAD][0], tmpData[TMP_LOAD][1], tmpData[TMP_LOAD][2] ))
		{
			for(new c;c<TMP_DATA_COUNT;c++) // c = cell reference
			{
				if (tmpData[TMP_LOAD][c] == -1) tmpData[TMP_LOAD][c] = tmpData[TMP_KEEP][c]; // If it an optional param has -1 set it's detault value
				else tmpData[TMP_KEEP][c] = tmpData[TMP_LOAD][c]; // Otherwise set the default value to the value just read
				// This method means that you can define timings for a set of coordinates
				// simply by defining the top one as what you want and leaving the rest blank
				// These settings will be default until the next line is found with optional params
			}
			camData[id][idx][cam_moveTime] = tmpData[TMP_LOAD][0]; // Set the values to the global array cell of this camera
			camData[id][idx][cam_waitTime] = tmpData[TMP_LOAD][1];
			camData[id][idx][cam_moveType] = tmpData[TMP_LOAD][2];
		}
		idx++;
	}
	camMaxNodes[id] = idx - 1;
	camIdUsed[id] = true;
	fclose(camFile);
	return id;
}
stock ClearCameraID(id)
{
	for(new n;n<=camMaxNodes[camera];n++)
	    for(new e;e<sizeof(camData[id][n]);e++)
			camData[id][n][CAM_DATA_ENUM:e]=0;

	camNodeTimer[id] = -1;
	camMaxNodes[id] = 0;
	camIdUsed[id] = false;
	camPaused[id] = false;
	camMoving[id] = false;
	gPlayerCamData[id] = {0, ...}
	camPausePos[id] = {0.0, ...}
}

stock PlayCameraMover(playerid, camera, startnode=0)
{
    gPlayerCamData[playerid][p_Node] = startnode;
    gPlayerCamData[playerid][p_CamID] = camera;

	TogglePlayerControllable(playerid, false);
    MoveCameraToNextNode(playerid);
}
stock PauseCameraMover(playerid)
{
	new
		tmpCam = gPlayerCamData[playerid][p_CamID],
		Float:vX,
		Float:vY,
		Float:vZ;

	GetPlayerCameraPos(playerid, camPausePos[tmpCam][0], camPausePos[tmpCam][1], camPausePos[tmpCam][2]);
	GetPlayerCameraFrontVector(playerid, vX, vY, vZ);

	camPausePos[tmpCam][3]=camPausePos[tmpCam][0]+vX;
	camPausePos[tmpCam][4]=camPausePos[tmpCam][1]+vZ;
	camPausePos[tmpCam][5]=camPausePos[tmpCam][2]+vZ;

	SetPlayerCameraPos(playerid, camPausePos[tmpCam][0], camPausePos[tmpCam][1], camPausePos[tmpCam][2]);
	SetPlayerCameraLookAt(playerid, camPausePos[tmpCam][3], camPausePos[tmpCam][4], camPausePos[tmpCam][5]);

	if(camNodeTimer[tmpCam]!=-1)KillTimer(camNodeTimer[tmpCam]);
	camPaused[tmpCam]=true;
}

MoveCameraToNextNode(playerid, bool:editing = false)
{
	new
		tmpCam = gPlayerCamData[playerid][p_CamID],
		tmpNode = gPlayerCamData[playerid][p_Node],
		nextNode = tmpNode+1;

	if(nextNode > camMaxNodes[tmpCam])return 1; // Player has reached the last node

	if(camPaused[tmpCam]) // Move the camera from the paused position
	{
		InterpolateCameraPos(playerid,
			camPausePos[tmpCam][0],	camPausePos[tmpCam][1],	camPausePos[tmpCam][2],
			camData[tmpCam][nextNode][cam_cPosX], camData[tmpCam][nextNode][cam_cPosY], camData[tmpCam][nextNode][cam_cPosZ],
			camData[tmpCam][tmpNode][cam_moveTime], camData[tmpCam][tmpNode][cam_moveType]);

		InterpolateCameraLookAt(playerid,
			camPausePos[tmpCam][3],	camPausePos[tmpCam][4],	camPausePos[tmpCam][5],
			camData[tmpCam][nextNode][cam_lPosX], camData[tmpCam][nextNode][cam_lPosY], camData[tmpCam][nextNode][cam_lPosZ],
			camData[tmpCam][tmpNode][cam_moveTime], camData[tmpCam][tmpNode][cam_moveType]);

		camPausePos[tmpCam][0]=0.0;
		camPausePos[tmpCam][1]=0.0;
		camPausePos[tmpCam][2]=0.0;
		camPausePos[tmpCam][3]=0.0;
		camPausePos[tmpCam][4]=0.0;
		camPausePos[tmpCam][5]=0.0;

        camPaused[tmpCam] = false;
	}
	else // Move the camera from the node
	{
		InterpolateCameraPos(playerid,
			camData[tmpCam][tmpNode][cam_cPosX], camData[tmpCam][tmpNode][cam_cPosY], camData[tmpCam][tmpNode][cam_cPosZ],
			camData[tmpCam][nextNode][cam_cPosX], camData[tmpCam][nextNode][cam_cPosY], camData[tmpCam][nextNode][cam_cPosZ],
			camData[tmpCam][tmpNode][cam_moveTime], camData[tmpCam][tmpNode][cam_moveType]);

		InterpolateCameraLookAt(playerid,
			camData[tmpCam][tmpNode][cam_lPosX], camData[tmpCam][tmpNode][cam_lPosY], camData[tmpCam][tmpNode][cam_lPosZ],
			camData[tmpCam][nextNode][cam_lPosX], camData[tmpCam][nextNode][cam_lPosY], camData[tmpCam][nextNode][cam_lPosZ],
			camData[tmpCam][tmpNode][cam_moveTime], camData[tmpCam][tmpNode][cam_moveType]);
	}
	TogglePlayerControllable(playerid, false);
	SetPlayerPos(playerid, camData[tmpCam][nextNode][cam_lPosX], camData[tmpCam][nextNode][cam_lPosY], camData[tmpCam][nextNode][cam_lPosZ]-50.0);

	CallLocalFunction("OnCameraLeaveNode", "ddd", playerid, tmpCam, tmpNode);
	if(!editing)camNodeTimer[tmpCam] = SetTimerEx("internal_OnCamMove", camData[tmpCam][tmpNode][cam_moveTime], false, "ddd", playerid, nextNode, true);
	else camNodeTimer[tmpCam] = SetTimerEx("editor_OnCamMove", camData[tmpCam][tmpNode][cam_moveTime], false, "ddd", playerid, nextNode, false);
	return 1;
}

public internal_OnCamMove(playerid, node, bool:cont)
{
	new
		tmpCam = gPlayerCamData[playerid][p_CamID],
		externResult;

	externResult = CallLocalFunction("OnCameraReachNode", "ddd", playerid, tmpCam, node);

	gPlayerCamData[playerid][p_Node]++;

	if(externResult)cont = false;
	if(cont && node <= camMaxNodes[tmpCam])
	{
		MoveCameraToNextNode(playerid);
	}

	return 1;
}

// Returning data to be used externally
/*
	cam_moveTime,			// Time in MS to move between each node
	cam_waitTime,			// Time in MS to wait before moving
	cam_moveType			// Camera move type (Cut or Move)

*/
stock GetCameraNodeMoveTime(camera, node)
	return camData[camera][node][cam_moveTime];

stock GetCameraNodeWaitTime(camera, node)
	return camData[camera][node][cam_waitTime];

stock GetCameraNodeMoveType(camera, node)
	return camData[camera][node][cam_moveType];


stock SetCameraNodeMoveTime(camera, node, time)
    camData[camera][node][cam_moveTime] = time;

stock SetCameraNodeWaitTime(camera, node, time)
    camData[camera][node][cam_waitTime] = time;

stock SetCameraNodeMoveType(camera, node, type)
    camData[camera][node][cam_moveType] = type;


stock GetCameraMaxNodes(camera)
	return camMaxNodes[camera];

stock GetPlayerCameraID(playerid)
	return gPlayerCamData[playerid][p_CamID];

stock GetPlayerCurrentNode(playerid)
	return gPlayerCamData[playerid][p_Node];


stock IsCameraValid(camera)
	return camIdUsed[p_CamID];

stock IsCameraPaused(camera)
	return camPaused[p_CamID];

stock IsCameraMoving(camera)
	return camMoving[p_CamID];
