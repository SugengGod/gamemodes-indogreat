/*
--0000---00---00---00000---000000---00000----
-00------00---00---00--00--00-------00--00---
--0000---00---00---00000---000000---00000----
-----00--00---00---00------00-------00--00---
--0000----000000---00------000000---00---00--

--0000----00----00000----000000----0000---00000--00000--
-00-----000000--00--00---00-------00--00---00-0000-00---
--0000----00----00000----000000---000000---00--00--00---
-----00---00----00--00---00-------00--00---00------00---
--0000----00----00---00--000000---00--00--000------000--

by Sim

native CreateStreamObject(modelid,Float:X,Float:Y,Float:Z,Float:RX,Float:RY,Float:RZ)
native DestroyStreamObject(objectid)
native StreamPlayer(playerid, Float:X, Float:Y, Float:Z)
native MoveStreamObject(objectid, Float:TargetX, Float:TargetY, Float:TargetZ, Float:Speed)
native StopStreamObject(objectid)
native ClearPlayerObjects(playerid)
native ClearAllObjects()
native
native // CALLBACK():
native OnStreamObjectMoved(objectid)
*/

#if defined _SUPER_STREAM_INCLUDED
	#endinput
#endif
#define _SUPER_STREAM_INCLUDED

#include <a_samp>

forward OnStreamObjectMoved(objectid);

//----------------------------------------------------------
stock CreateStreamObject(modelid, Float:xpos, Float:ypos, Float:zpos, Float:xrot, Float:yrot, Float:zrot)
{
	return CallRemoteFunction("core_CreateObject","iffffff", modelid, xpos, ypos, zpos, xrot, yrot, zrot);
}

//----------------------------------------------------------

stock DestroyStreamObject(objectid)
{
	return CallRemoteFunction("core_DestroyObject","i",objectid);
}

//-----------------------------------------------------------

stock StreamPlayer(playerid, Float:X, Float:Y, Float:Z)
{
	return CallRemoteFunction("StreamPlayer", "ifff", playerid, X, Y, Z);
}

//----------------------------------------------------------

stock MoveStreamObject(objectid, Float:TargetX, Float:TargetY, Float:TargetZ, Float:Speed)
{
	return CallRemoteFunction("core_MoveObject","iffff", objectid, TargetX, TargetY, TargetZ, Speed);
}

//----------------------------------------------------------

stock StopStreamObject(objectid)
{
	return CallRemoteFunction("core_StopObject","i", objectid);
}

//----------------------------------------------------------

stock ClearPlayerObjects(playerid)
{
	return CallRemoteFunction("core_ClearPlayerObjects","i", playerid);
}

//----------------------------------------------------------

stock ClearAllObjects()
{
	return CallRemoteFunction("core_ClearAllObjects","");
}

