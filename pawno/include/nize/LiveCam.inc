/***********************************************************************************************
	livecam.inc | Watch through cameras that camera mans hold !
	            by: iAmir
				Download : https://github.com/AmyrAhmady/LiveCam
		Functions :
		    GivePlayerCamera(playerid);
			RemovePlayerCamera(playerid);
			IsPlayerRecording(playerid);
			IsPlayerWatchingCamera(playerid);
			IsPlayerWatchingPlayerCamera(playerid , cameraman);
			StartPlayerWatchingCamera(playerid , cameraman);
			StopPlayerWatchingCamera(playerid);

************************************************************************************************/

#include <a_samp>

enum _playerCameraStats
{
	bool:playerWatching,
	playerWatchingPlayer,
	bool:playerRecording,
	playerCameraTimer
}

new _playerCamera[MAX_PLAYERS][_playerCameraStats];

#define __pc _playerCamera[playerid]

stock GivePlayerCamera(playerid)
{
   	__pc[playerRecording] = true;
	ClearAnimations(playerid);
	SetPlayerSpecialAction(playerid , SPECIAL_ACTION_USECELLPHONE);
	SetPlayerAttachedObject(playerid,0,19615,6,-0.024000,-0.000000,0.020998,-16.799999,49.300083,-3.600008,0.851000,0.470998,0.834999 , 0xFF666666 , 0xFF666666);
	SetPlayerAttachedObject(playerid,1,19623,6,0.183999,-0.038000,-0.057000,70.100051,-2.600011,31.100006,1.000000,1.000000,1.000000 , 0xFF333333 , 0xFF333333);
	return 1;
}

stock RemovePlayerCamera(playerid)
{
    __pc[playerRecording] = false;
	ClearAnimations(playerid);
	SetPlayerSpecialAction(playerid , SPECIAL_ACTION_NONE);
	RemovePlayerAttachedObject(playerid , 0 );
	RemovePlayerAttachedObject(playerid , 1 );
	return 1;
}

stock bool:IsPlayerRecording(playerid)
{
	return __pc[playerRecording];
}

stock bool:IsPlayerWatchingCamera(playerid)
{
	return __pc[playerWatching];
}

stock bool:IsPlayerWatchingPlayerCamera(playerid , cameraman)
{
	if(__pc[playerWatchingPlayer] == cameraman) return true;
	return false;
}

stock StartPlayerWatchingCamera(playerid , cameraman)
{
	if(!_playerCamera[cameraman][playerRecording] || !IsPlayerConnected(cameraman)) return 0;
	__pc[playerWatching] = true;
	__pc[playerWatchingPlayer] = cameraman;
	__pc[playerCameraTimer] = SetTimerEx("OnPlayerCameraUpdate" , 5 , 1 , "ii" , playerid , cameraman);
	return 1;
}

stock StopPlayerWatchingCamera(playerid)
{
	__pc[playerWatching] = false;
	__pc[playerWatchingPlayer] = INVALID_PLAYER_ID;
	SetCameraBehindPlayer(playerid);
	KillTimer(__pc[playerCameraTimer]);
	return 1;
}

stock GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{
	new Float:a;
	GetPlayerPos(playerid, x, y, a);
	GetPlayerFacingAngle(playerid, a);
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

public OnPlayerConnect(playerid)
{
    __pc[playerRecording]=false;
    __pc[playerWatching]=false;
    __pc[playerWatchingPlayer] = INVALID_PLAYER_ID;
    return CallLocalFunction("_pc_OnPlayerConnect", "i", playerid);
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect _pc_OnPlayerConnect
forward _pc_OnPlayerConnect(playerid);

forward OnPlayerCameraUpdate(playerid , cameraman);
public OnPlayerCameraUpdate(playerid , cameraman)
{
    if(__pc[playerWatching])
    {
        if(_playerCamera[cameraman][playerRecording])
        {
        	new Float:x , Float:y , Float:z;
        	GetPlayerPos(cameraman, x , y , z);
    		GetXYInFrontOfPlayer(cameraman , x , y , 0.6);
        	SetPlayerCameraPos(playerid , x ,y ,z+0.8);
        	GetPlayerPos(cameraman , x ,y ,z);
        	GetXYInFrontOfPlayer(cameraman , x , y , 10.0);
        	SetPlayerCameraLookAt(playerid , x , y , z+0.8 );
        } else StopPlayerWatchingCamera(playerid);
    }
    return 1;
}
