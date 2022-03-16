#include <a_samp>
forward OnPlayerCameraFinish(playerid);
forward DestroyCameraForPlayer(playerid);
forward UpdatePlayerCameraPosition(playerid);
forward LastCameraPos(playerid, &Float:x, &Float:y, &Float:z);
#define INVALID_CAMERA  -1
#define INVALID_TIMER   -1
enum _Cam
{
    camObjID,
    camTimer,
    bool:camSyncSurroundings,
    Float:camEndPX,
    Float:camEndPY,
    Float:camEndPZ,
    camOVW,
    bool:camUVW,
    Float:camLPX,
    Float:camLPY,
    Float:camLPZ,
}
new Cam[MAX_PLAYERS][_Cam];
public OnGameModeInit()
{
    for(new s = 0; s < MAX_PLAYERS; s++) {
        Cam[s][camObjID] = INVALID_CAMERA;
        Cam[s][camTimer] = INVALID_TIMER;
    }
    return CallLocalFunction("NC_OnGameModeInit", "");
}
#if defined _ALS_OnGameModeInit
#undef OnGameModeInit
#else
#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit NC_OnGameModeInit
forward NC_OnGameModeInit();
public DestroyCameraForPlayer(playerid)
{
    if(Cam[playerid][camObjID] != INVALID_CAMERA) {
        DestroyPlayerObject(playerid, Cam[playerid][camObjID]);
    }
    if(Cam[playerid][camTimer] != INVALID_TIMER) {  KillTimer(Cam[playerid][camTimer]), Cam[playerid][camTimer] = INVALID_TIMER; }
    Cam[playerid][camObjID] = INVALID_CAMERA, Cam[playerid][camObjID] = 0, Cam[playerid][camSyncSurroundings] = false, Cam[playerid][camEndPX] = 0, Cam[playerid][camEndPY] = 0, Cam[playerid][camEndPZ] = 0, Cam[playerid][camOVW] = 0, Cam[playerid][camUVW] = false;
    return true;
}
stock SetCameraPosForPlayer(playerid, Float:startx, Float:starty, Float:startz, Float:endx, Float:endy, Float:endz, Float:speed, bool:sync_surroundings=false, bool:rand_vw=false)
{
    if(Cam[playerid][camObjID] != INVALID_CAMERA) { DestroyCameraForPlayer(playerid); }
    if(rand_vw) {
        Cam[playerid][camOVW] = GetPlayerVirtualWorld(playerid);
        SetPlayerVirtualWorld(playerid, random(10000));
        Cam[playerid][camUVW] = true;
    }
    Cam[playerid][camObjID] = CreatePlayerObject( playerid, 0, startx, starty, startz, 0, 0, 0 );
    Cam[playerid][camEndPX] = endx, Cam[playerid][camEndPY] = endy, Cam[playerid][camEndPZ] = endz;
    MovePlayerObject(playerid, Cam[playerid][camObjID], Cam[playerid][camEndPX], Cam[playerid][camEndPY], Cam[playerid][camEndPZ], speed);
    Cam[playerid][camTimer] = SetTimerEx("UpdatePlayerCameraPosition", 50, true, "i", playerid);
    if(sync_surroundings) { Cam[playerid][camSyncSurroundings] = true; }
    return false;
}
public LastCameraPos(playerid, &Float:x, &Float:y, &Float:z)
{
    x = Cam[playerid][camLPX], y = Cam[playerid][camLPY], z = Cam[playerid][camLPZ];
    return true;
}
public UpdatePlayerCameraPosition(playerid)
{
    if(Cam[playerid][camObjID] != INVALID_CAMERA) {
        new Float:x, Float:y, Float:z;
        GetPlayerObjectPos(playerid, Cam[playerid][camObjID], x, y, z);
        if(x == Cam[playerid][camEndPX] && y == Cam[playerid][camEndPY] && z == Cam[playerid][camEndPZ]) {
            Cam[playerid][camLPX] = x, Cam[playerid][camLPY] = y, Cam[playerid][camLPZ] = z;
            if(Cam[playerid][camUVW]) { SetPlayerVirtualWorld(playerid, Cam[playerid][camOVW]); }
            DestroyCameraForPlayer(playerid);
            return CallLocalFunction("OnPlayerCameraFinish","i",playerid);
        }
        else {
            if(Cam[playerid][camSyncSurroundings]) {
                SetPlayerPos(playerid, x, y, z-5.00);
            }
            SetPlayerCameraPos(playerid, x, y, z);
            SetPlayerCameraLookAt(playerid, Cam[playerid][camEndPX], Cam[playerid][camEndPY], Cam[playerid][camEndPZ]);
        }
        return true;
    }
    return false;
}
