// This is a example of how to use the include.
// The commands you see are ZCMD include's and are better for when making new commands.
// To learn more just google search for the ZCMD include to learn how it is used!

#include <a_samp>
#include <zcmd>

#include <cadesystem>

#define COLOR_YELLOW	0xFFFF00AA

public OnFilterScriptInit()
{
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

CMD:createcone(playerid, params[])
{
	new Float:x, Float:y, Float:z, Float:angle;
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, angle);
	CreateCone(x, y, z, angle);
	SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have created a cone!");
	return 1;
}

CMD:destroyallcones(playerid, params[])
{
    DeleteAllCone();
    SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have destroyed all cones!");
	return 1;
}

CMD:deletecone(playerid, params[]) // This just deletes the closest cone!
{
    DeleteClosestCone(playerid);
    SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have destroyed a cone!");
	return 1;
}

CMD:createspike(playerid, params[])
{
	new Float:x, Float:y, Float:z, Float:angle;
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, angle);
	CreateStrip(x, y, z, angle);
	SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have created a spike!");
	return 1;
}

CMD:destroyallspikes(playerid, params[])
{
    DeleteAllStrip();
    SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have destroyed all spikes!");
	return 1;
}

CMD:deletespikes(playerid, params[]) // This just deletes the closest barrier!
{
    DeleteClosestStrip(playerid);
    SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have destroyed a spike!");
	return 1;
}

CMD:createbarrier(playerid, params[])
{
	new Float:x, Float:y, Float:z, Float:angle;
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, angle);
	CreateBarrier(x, y, z, angle);
	SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have created a barrier!");
	return 1;
}

CMD:destroyallbarriers(playerid, params[])
{
    DeleteAllBarrier();
    SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have destroyed all barriers!");
	return 1;
}

CMD:deletebarrier(playerid, params[]) // This just deletes the closest barrier!
{
    DeleteClosestBarrier(playerid);
    SendClientMessage(playerid, COLOR_YELLOW, "(INFO) You have destroyed a barrier!");
	return 1;
}
