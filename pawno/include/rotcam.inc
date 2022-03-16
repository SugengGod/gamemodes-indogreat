/*
	ROTATING CAMERA SYSTEM
	--------- ---- -- ------ ---------
	COPYRIGHT 2008 BY RAFAEL RAVEDUTTI
	--------- ---- -- ------ ---------
*/

#include <a_samp>

//Directions
#define DIRECTION_RIGHT         0
#define DIRECTION_LEFT          1
#define DIRECTION_MANUAL        2

new Float:CameraAngle[MAX_PLAYERS];
new Float:CameraRotatePosition[MAX_PLAYERS][3];
new CameraTimer[MAX_PLAYERS];
new CheckKeyTimer[MAX_PLAYERS];
new PlayerPressedKey[MAX_PLAYERS];
new Float:SavePos[MAX_PLAYERS][3];
new CameraActivated[MAX_PLAYERS] = 0;

forward SetPlayerCameraRotatePlayer(playerid, playa, timerchange, Float:addang, Float:distance, direction);
forward SetPlayerCameraRotateVehicle(playerid, vehicleid, timerchange, Float:addang, Float:distance, direction);
forward SetPlayerCameraRotateObject(playerid, objectid, timerchange, Float:addang, Float:distance, direction);
forward SetPlayerCameraRotatePos(playerid, Float:X, Float:Y, Float:Z, timerchange, Float:addang, Float:distance, direction);
forward StopPlayerCameraRotate(playerid);
forward UpdateCamera(playerid, typedest, destid, Float:addition, Float:distance, direction);
forward CheckKey(playerid);

/*Natives
native SetPlayerCameraRotatePlayer(playerid, playa, timerchange, Float:addang, Float:distance, direction);
native SetPlayerCameraRotateVehicle(playerid, vehicleid, timerchange, Float:addang, Float:distance, direction);
native SetPlayerCameraRotateObject(playerid, objectid, timerchange, Float:addang, Float:distance, direction);
native SetPlayerCameraRotatePos(playerid, Float:X, Float:Y, Float:Z, timerchange, Float:addang, Float:distance, direction);
native StopPlayerCameraRotate(playerid);
*/

public SetPlayerCameraRotatePlayer(playerid, playa, timerchange, Float:addang, Float:distance, direction)
{
    if(CameraActivated[playerid] == 1) StopPlayerCameraRotate(playerid);
	CameraActivated[playerid] = 1;
	PlayerPressedKey[playerid] = 0;
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	if(pos[0] != 0 && pos[1] != 0 && pos[2] != 0) GetPlayerPos(playerid, SavePos[playerid][0], SavePos[playerid][1], SavePos[playerid][2]);
	if(playa != playerid) TogglePlayerControllable(playerid,false);
	if(direction == DIRECTION_MANUAL)
	{
	    CheckKeyTimer[playerid] = SetTimerEx("CheckKey",100,1,"d",playerid);
	}
	GetPlayerFacingAngle(playa,CameraAngle[playerid]);
	CameraTimer[playerid] = SetTimerEx("UpdateCamera",timerchange,1,"dddddd",playerid,1,playa,addang,distance,direction);
}

public SetPlayerCameraRotateVehicle(playerid, vehicleid, timerchange, Float:addang, Float:distance, direction)
{
    if(CameraActivated[playerid] == 1) StopPlayerCameraRotate(playerid);
	CameraActivated[playerid] = 1;
	PlayerPressedKey[playerid] = 0;
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	if(pos[0] != 0 && pos[1] != 0 && pos[2] != 0) GetPlayerPos(playerid, SavePos[playerid][0], SavePos[playerid][1], SavePos[playerid][2]);
    TogglePlayerControllable(playerid,false);
	if(direction == DIRECTION_MANUAL)
	{
	    CheckKeyTimer[playerid] = SetTimerEx("CheckKey",100,1,"d",playerid);
	}
	GetVehicleZAngle(vehicleid,CameraAngle[playerid]);
    CameraTimer[playerid] = SetTimerEx("UpdateCamera",timerchange,1,"dddddd",playerid,2,vehicleid,addang,distance,direction);
}

public SetPlayerCameraRotateObject(playerid, objectid, timerchange, Float:addang, Float:distance, direction)
{
    if(CameraActivated[playerid] == 1) StopPlayerCameraRotate(playerid);
	CameraActivated[playerid] = 1;
	PlayerPressedKey[playerid] = 0;
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	if(pos[0] != 0 && pos[1] != 0 && pos[2] != 0) GetPlayerPos(playerid, SavePos[playerid][0], SavePos[playerid][1], SavePos[playerid][2]);
    TogglePlayerControllable(playerid,false);
	if(direction == DIRECTION_MANUAL)
	{
	    CheckKeyTimer[playerid] = SetTimerEx("CheckKey",100,1,"d",playerid);
	}
    CameraAngle[playerid] = 0.0;
    CameraTimer[playerid] = SetTimerEx("UpdateCamera",timerchange,1,"dddddd",playerid,3,objectid,addang,distance,direction);
}

public SetPlayerCameraRotatePos(playerid, Float:X, Float:Y, Float:Z, timerchange, Float:addang, Float:distance, direction)
{
    if(CameraActivated[playerid] == 1) StopPlayerCameraRotate(playerid);
	CameraActivated[playerid] = 1;
	PlayerPressedKey[playerid] = 0;
    new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	if(pos[0] != 0 && pos[1] != 0 && pos[2] != 0) GetPlayerPos(playerid, SavePos[playerid][0], SavePos[playerid][1], SavePos[playerid][2]);
    TogglePlayerControllable(playerid,false);
	if(direction == DIRECTION_MANUAL)
	{
	    CheckKeyTimer[playerid] = SetTimerEx("CheckKey",1,1,"d",playerid);
	}
    CameraAngle[playerid] = 0.0;
    CameraRotatePosition[playerid][0] = X;
    CameraRotatePosition[playerid][1] = Y;
    CameraRotatePosition[playerid][2] = Z;
    CameraTimer[playerid] = SetTimerEx("UpdateCamera",timerchange,1,"dddddd",playerid,4,-1,addang,distance,direction);
}

public StopPlayerCameraRotate(playerid)
{
    KillTimer(CheckKeyTimer[playerid]);
	KillTimer(CameraTimer[playerid]);
	PlayerPressedKey[playerid] = 0;
	CameraActivated[playerid] = 0;
	if(SavePos[playerid][0] != 0 && SavePos[playerid][1] != 0 && SavePos[playerid][2] != 0) SetPlayerPos(playerid, SavePos[playerid][0], SavePos[playerid][1], SavePos[playerid][2]);
	SetCameraBehindPlayer(playerid);
	TogglePlayerControllable(playerid,true);
}

public UpdateCamera(playerid, typedest, destid, Float:addition, Float:distance, direction)
{
	if((typedest != 1 && typedest != 2 && typedest != 3 && typedest != 4) || !IsPlayerConnected(playerid) || (typedest == 1 && !IsPlayerConnected(destid)) || (typedest != 4 && destid == -1) || (direction != DIRECTION_RIGHT && direction != DIRECTION_LEFT && direction != DIRECTION_MANUAL))
	{
		StopPlayerCameraRotate(playerid);
	}
	else
	{
	    new Float:X[2],Float:Y[2],Float:Z;
		if(typedest == 1) { GetPlayerPos(destid,X[0],Y[0],Z); }
		else if(typedest == 2) { GetVehiclePos(destid,X[0],Y[0],Z); }
		else if(typedest == 3) { GetObjectPos(destid,X[0],Y[0],Z); }
		else
		{
		    X[0] =  CameraRotatePosition[playerid][0];
		    Y[0] =  CameraRotatePosition[playerid][1];
		    Z 	 =  CameraRotatePosition[playerid][2];
		}
		CamRot_GetXYInFrontOfPosition(X[0],Y[0],CameraAngle[playerid],distance,X[1],Y[1]);
		new x = 0;
		if(typedest == 4)
		{
		    new Float:PlayerX,Float:PlayerY,Float:PlayerZ;
		    GetPlayerPos(playerid,PlayerX,PlayerY,PlayerZ);
		    x = ((((PlayerX - X[0]) * (PlayerX - X[0])) + ((PlayerY - Y[0]) * (PlayerY - Y[0])) + ((PlayerZ - Z) * (PlayerZ - Z))) < distance + 1) || (PlayerX == 0 && PlayerY == 0 && PlayerZ == 0);
		}
		if((typedest != 1 || destid != playerid) && (x == 0)) SetPlayerPos(playerid,X[0],Y[0],Z - 5.0);
	    SetPlayerCameraPos(playerid,X[1],Y[1],Z);
	    SetPlayerCameraLookAt(playerid,X[0],Y[0],Z);
	    if(direction == DIRECTION_RIGHT) CameraAngle[playerid] += addition;
	    else if(direction == DIRECTION_LEFT) CameraAngle[playerid] -= addition;
	    else
	    {
	        if(PlayerPressedKey[playerid] == 16384)
			{
		 		CameraAngle[playerid] += addition;
		 		PlayerPressedKey[playerid] = 0;
			}
	        if(PlayerPressedKey[playerid] == 8192)
			{
		 		CameraAngle[playerid] -= addition;
			  	PlayerPressedKey[playerid] = 0;
			}
	    }
	}
}

public CheckKey(playerid)
{
    new key[2];
    GetPlayerKeys(playerid, key[1], key[0], key[0]);
    PlayerPressedKey[playerid] = key[1];
}

stock CamRot_GetXYInFrontOfPosition(Float:X, Float:Y, Float:ang, Float:distance, &Float:destX, &Float:destY)
{
    destX = X + (distance * floatsin(-ang, degrees));
	destY = Y + (distance * floatcos(-ang, degrees));
}
