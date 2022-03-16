/*
+---------------------------------------------------------------------------+
¦                        JunkBuster Anti-Cheat                              ¦
¦                                  by                                       ¦
¦                           Double-O-Seven                                  ¦
¦                                                                           ¦
¦ This is the JunkBuster Client include. Use it in all of your scripts!		¦
¦ Be careful: You must run the JunkBuster filterscript or none of the		¦
¦ functions below will work!                                                ¦
+---------------------------------------------------------------------------+
*/

#if defined _JB_included
	#endinput
#endif
#define _JB_included

#include <a_samp>

#define Public:%0(%1) 	forward %0(%1); \
						public %0(%1)

#if !defined isnull
	#define isnull(%1) \
				((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

/*
native GetPlayerFPS(playerid);
native GetPlayerSpeed(playerid,get3d=false);
native AntiBugKill(playerid);
native CheckText(playerid,text[]);
native GodModeCheck(playerid);
native AllowWeaponForPlayer(playerid,weaponid);
native ForbidWeaponForPlayer(playerid,weaponid,antibugkill);
native ResetForbiddenWeaponsForPlayer(playerid,antibugkill);
native IsForbiddenWeapon(weaponid);
native IsWeaponForbiddenForPlayer(playerid,weaponid);
native AddWeaponPickup(Float:x,Float:y,Float:z,weaponid,ammo,worldid);
native PlayerReportPlayer(playerid,reporterid,report[]);
native SetPlayerSpawnKillProtected(playerid,set);
*/

//==============================================================================

/*
You have to add these callbacks yourself and you can do with what you want:
BUT: You don't have to use these callbacks at all... I just thought they can be helpful for whatever, I don't know.
*/
forward OnJunkBusterBan(playerid,reason[]);
forward OnJunkBusterKick(playerid,reason[]);
forward OnJunkBusterReport(playerid,reason[],details[]);

//You SHOULD add this function to your adminscript etc. to guarantee admin immunity and correct working reports!
forward IsPlayerAdminCall(playerid);

/*
Put for example this into your gamemode (example for Godfather):

public IsPlayerAdminCall(playerid)
	return (PlayerInfo[playerid][pAdmin] >= 1);

AGAIN: This is an example and may only work for the Godfather script.HTTP

You have to create a function which fits to your OWN gamemode!
*/

//==============================================================================

//Don't let noobs crash your server by abusing the % symbol in inputtext.
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new len=strlen(inputtext);
	for(new i=0;i<len;i++)
	    if(inputtext[i]=='%')
	        inputtext[i]='#';
	        
	if(!len)
		return CallLocalFunction("JB_OnDialogResponse","iiiis",playerid, dialogid, response, listitem, "\1");
    return CallLocalFunction("JB_OnDialogResponse","iiiis",playerid, dialogid, response, listitem, inputtext);
}

//OnDialogResponse
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse JB_OnDialogResponse
forward JB_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);

//==============================================================================

//EXISTING functions which JunkBuster MUST overwrite!

stock JBC_PutPlayerInVehicle(playerid,vehicleid,seatid)
	return CallRemoteFunction("JB_PutPlayerInVehicle","iii",playerid,vehicleid,seatid);
	
stock JBC_GivePlayerMoney(playerid,amount)
	return CallRemoteFunction("JB_GivePlayerMoney","ii",playerid,amount);
	
stock JBC_ResetPlayerMoney(playerid)
	return CallRemoteFunction("JB_ResetPlayerMoney","i",playerid);

stock JBC_GetPlayerMoney(playerid)
	return CallRemoteFunction("JB_GetPlayerMoney","i",playerid);
	
stock JBC_SetPlayerPos(playerid,Float:x,Float:y,Float:z)
	return CallRemoteFunction("JB_SetPlayerPos","ifff",playerid,x,y,z);

stock JBC_SetVehiclePos(vehicleid,Float:x,Float:y,Float:z)
	return CallRemoteFunction("JB_SetVehiclePos","ifff",vehicleid,x,y,z);
	
stock JBC_SetVehicleVelocity(vehicleid,Float:x,Float:y,Float:z)
	return CallRemoteFunction("JB_SetVehicleVelocity","ifff",vehicleid,x,y,z);
	
stock JBC_GivePlayerWeapon(playerid,weaponid,ammo)
	return CallRemoteFunction("JB_GivePlayerWeapon","iii",playerid,weaponid,ammo);
	
stock JBC_ResetPlayerWeapons(playerid)
	return CallRemoteFunction("JB_ResetPlayerWeapons","i",playerid);
	
stock JBC_SetPlayerHealth(playerid,Float:health)
	return CallRemoteFunction("JB_SetPlayerHealth","if",playerid,health);
	
stock JBC_SetPlayerArmour(playerid,Float:armour)
	return CallRemoteFunction("JB_SetPlayerArmour","if",playerid,armour);
	
stock JBC_SetVehicleHealth(vehicleid,Float:health)
	return CallRemoteFunction("JB_SetVehicleHealth","if",vehicleid,health);
	
stock JBC_TogglePlayerControllable(playerid,toggle)
	return CallRemoteFunction("JB_TogglePlayerControllable","ii",playerid,toggle);
	
stock JBC_SetPlayerSpecialAction(playerid,actionid)
	return CallRemoteFunction("JB_SetPlayerSpecialAction","ii",playerid,actionid);
	
stock JBC_SetPlayerRaceCheckpoint(playerid,type,Float:x,Float:y,Float:z,Float:nextx,Float:nexty,Float:nextz,Float:size)
	return CallRemoteFunction("JB_SetPlayerRaceCheckpoint","iifffffff",playerid,type,x,y,z,nextx,nexty,nextz,size);
	
stock JBC_AddStaticPickup(model,type,Float:X,Float:Y,Float:Z,virtualworld=0)
	return CallRemoteFunction("JB_AddStaticPickup","iifffi",model,type,X,Y,Z,virtualworld);
	
stock JBC_CreatePickup(model,type,Float:X,Float:Y,Float:Z,virtualworld=0)
	return CallRemoteFunction("JB_CreatePickup","iifffi",model,type,X,Y,Z,virtualworld);
	
stock JBC_DestroyPickup(pickupid)
	return CallRemoteFunction("JB_DestroyPickup","i",pickupid);
	
stock JBC_AddPlayerClass(modelid,Float:spawn_x,Float:spawn_y,Float:spawn_z,Float:z_angle,weapon1,weapon1_ammo,weapon2,weapon2_ammo,weapon3,weapon3_ammo)
	return CallRemoteFunction("JB_AddPlayerClass","iffffiiiiii",modelid,spawn_x,spawn_y,spawn_z,z_angle,weapon1,weapon1_ammo,weapon2,weapon2_ammo,weapon3,weapon3_ammo);
	
stock JBC_AddPlayerClassEx(teamid,modelid,Float:spawn_x,Float:spawn_y,Float:spawn_z,Float:z_angle,weapon1,weapon1_ammo,weapon2,weapon2_ammo,weapon3,weapon3_ammo)
	return CallRemoteFunction("JB_AddPlayerClassEx","iiffffiiiiii",teamid,modelid,spawn_x,spawn_y,spawn_z,z_angle,weapon1,weapon1_ammo,weapon2,weapon2_ammo,weapon3,weapon3_ammo);
	
stock JBC_SetSpawnInfo(playerid,team,skin,Float:x,Float:y,Float:z,Float:rotation,weapon1,weapon1_ammo,weapon2,weapon2_ammo,weapon3,weapon3_ammo)
	return CallRemoteFunction("JB_SetSpawnInfo","iiiffffiiiiii",playerid,team,skin,x,y,z,rotation,weapon1,weapon1_ammo,weapon2,weapon2_ammo,weapon3,weapon3_ammo);

//NEW functions given to you by JunkBuster!

stock JBC_GetPlayerFPS(playerid)
	return CallRemoteFunction("GetPlayerFPS","i",playerid);

stock JBC_GetPlayerSpeed(playerid,get3d=false)
	return CallRemoteFunction("JB_GetPlayerSpeed","ii",playerid,get3d);

stock JBC_AntiBugKill(playerid)//This basically respawns the player.
	return CallRemoteFunction("AntiBugKill","i",playerid);

stock JBC_CheckText(playerid,text[])//return 1: something forbidden found, return 0: everything OK!
	return CallRemoteFunction("CheckText","is",playerid,text);

stock JBC_GodModeCheck(playerid)
	return CallRemoteFunction("GodModeCheck","i",playerid);

stock JBC_AllowWeaponForPlayer(playerid,weaponid)
	return CallRemoteFunction("AllowWeaponForPlayer","ii",playerid,weaponid);

stock JBC_ForbidWeaponForPlayer(playerid,weaponid,antibugkill)
	return CallRemoteFunction("ForbidWeaponForPlayer","iii",playerid,weaponid,antibugkill);

stock JBC_ResetFWeaponsForPlayer(playerid,antibugkill)
	return CallRemoteFunction("ResetForbiddenWeaponsForPlayer","ii",playerid,antibugkill);

stock JBC_IsForbiddenWeapon(weaponid)
    return CallRemoteFunction("IsForbiddenWeapon","i",weaponid);

stock JBC_IsWeaponForbiddenForPlayer(playerid,weaponid)
    return CallRemoteFunction("IsForbiddenWeaponForPlayer","ii",playerid,weaponid);

stock JBC_AddWeaponPickup(Float:x,Float:y,Float:z,weaponid,ammo,worldid=0)
	return CallRemoteFunction("AddWeaponPickup","fffiii",x,y,z,weaponid,ammo,worldid);
	
stock JBC_SetPlayerSpawnKillProtected(playerid,set)
	return CallRemoteFunction("SetPlayerSpawnKillProtected","ii",playerid,set);
	
/*
Use PlayerReportPlayer(playerid,reporterid,report[]) to let JunkBuster know
that a player has reported another player.

DESCRIPTION:
- 'playerid' is the ID of the player who has been reported. Maybe a cheater? Let it JunkBuster know!
- 'reporterid' is the ID of the player who has reported the other player.
- 'report' is the report. If it contains 'god' or 'mod' JunkBuster will check the 'playerid' for godmode.

IMPORTANT:
JunkBuster will not react on every report. A player can't get spammed with GodModeCheck.
Spamming GodModeCheck on a player can end up with a kick/ban even when the player is innoncent. (Tested)
*/
	
stock PlayerReportPlayer(playerid,reporterid,report[])
{
	if(IsPlayerConnected(playerid) && IsPlayerConnected(reporterid) && !isnull(report))
		return CallRemoteFunction("OnPlayerReport","iis",playerid,reporterid,report);
	return 0;
}

//==============================================================================
	
#define PutPlayerInVehicle 				JBC_PutPlayerInVehicle
#define GivePlayerMoney 				JBC_GivePlayerMoney
#define ResetPlayerMoney 				JBC_ResetPlayerMoney
#define GetPlayerMoney 					JBC_GetPlayerMoney
#define SetPlayerPos 					JBC_SetPlayerPos
#define SetVehiclePos 					JBC_SetVehiclePos
#define GivePlayerWeapon 				JBC_GivePlayerWeapon
#define ResetPlayerWeapons              JBC_ResetPlayerWeapons
#define SetPlayerHealth 				JBC_SetPlayerHealth
#define SetPlayerArmour 				JBC_SetPlayerArmour
#define SetVehicleHealth 				JBC_SetVehicleHealth
#define GetPlayerFPS                	JBC_GetPlayerFPS
#define GetPlayerSpeed                  JBC_GetPlayerSpeed
#define TogglePlayerControllable 		JBC_TogglePlayerControllable
#define SetVehicleVelocity 				JBC_SetVehicleVelocity
#define SetPlayerSpecialAction 			JBC_SetPlayerSpecialAction
#define SetPlayerRaceCheckpoint 		JBC_SetPlayerRaceCheckpoint
#define AddStaticPickup                 JBC_AddStaticPickup
#define CreatePickup                    JBC_CreatePickup
#define DestroyPickup                   JBC_DestroyPickup
#define AddPlayerClass                  JBC_AddPlayerClass
#define AddPlayerClassEx                JBC_AddPlayerClassEx
#define SetSpawnInfo                    JBC_SetSpawnInfo
#define AntiBugKill                 	JBC_AntiBugKill
#define CheckText                   	JBC_CheckText
#define GodModeCheck                    JBC_GodModeCheck
#define AllowWeaponForPlayer    		JBC_AllowWeaponForPlayer
#define ForbidWeaponForPlayer       	JBC_ForbidWeaponForPlayer
#define ResetForbiddenWeaponsForPlayer 	JBC_ResetFWeaponsForPlayer
#define IsForbiddenWeapon               JBC_IsForbiddenWeapon
#define IsForbiddenWeaponForPlayer      JBC_IsForbiddenWeaponForPlayer
#define AddWeaponPickup             	JBC_AddWeaponPickup
#define SetPlayerSpawnKillProtected 	JBC_SetPlayerSpawnKillProtected
