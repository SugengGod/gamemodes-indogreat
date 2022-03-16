/*
*
*
*	rStreamer v1.2 by [WsR]RyDeR
*
*/

#include <a_samp>

stock CreateStreamedObject(oID,Float:X,Float:Y,Float:Z,Float:rX,Float:rY,Float:rZ, Float:ViewD)
{
	CallRemoteFunction("R_CreateStreamedObject","ifffffff",oID,Float:X,Float:Y,Float:Z,Float:rX,Float:rY,Float:rZ, Float:ViewD);
	return 1;
}

stock DestroyStreamedObject(dID)
{
	CallRemoteFunction("R_DestroyStreamedObject","i",dID);
	return 1;
}

stock rStreamDisconnect(playerid)
{
    CallRemoteFunction("R_OnPlayerDisconnect","i",playerid);
}

stock rStreamConnect(playerid)
{
    CallRemoteFunction("R_OnPlayerConnect","i",playerid);
}