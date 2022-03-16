//  ---------------------------------------------------------------------
//  -------------------- Dynamic Radio Stations.inc ---------------------
//  ------------------------- (c) Jochemd 2012 --------------------------
//  ---------------------------------------------------------------------

//------------------------------------------- Includes -------------------------------------------
#include "YSI\y_hooks"

//------------------------------------------- Macro's -------------------------------------------
#define USE_TEXTDRAW_SET 2
#define MAX_RADIO_STATIONS 20
#define TEXTDRAW_DISAPPEAR_TIME 2000
#define NAME_SIZE 30
#define LINK_SIZE 70

#define GetVehicleRadioStation(%1) v_VehicleInfo[%1][RadioPlaying]

//------------------------------------------- Enumerations -------------------------------------------
enum r_info
{
	r_Name[NAME_SIZE],
	r_Link[LINK_SIZE]
};

enum v_info
{
	RadioPlaying,
	Text:r_Draw
};

//------------------------------------------- Declarations -------------------------------------------
new r_RadioInfo[MAX_RADIO_STATIONS][r_info];
new v_VehicleInfo[MAX_VEHICLES][v_info];
new RadioCount = 0;

//------------------------------------------- Forwards -------------------------------------------
forward HideRadioTextdraw(playerid, vehicleid);

//------------------------------------------- Stocks -------------------------------------------
stock IsPlayerInSameVehicle(playerid, asplayerid)
{
	if(GetPlayerVehicleID(playerid) == GetPlayerVehicleID(asplayerid)) return 1;
	else return 0;
}

stock InitializeScript()
{
	for(new v = 0; v < MAX_VEHICLES; v ++)
	{
		#if USE_TEXTDRAW_SET == 0
			v_VehicleInfo[v][r_Draw] = TextDrawCreate(309.000000, 9.000000, "Radio");
			TextDrawAlignment(v_VehicleInfo[v][r_Draw], 2);
			TextDrawBackgroundColor(v_VehicleInfo[v][r_Draw], 255);
			TextDrawFont(v_VehicleInfo[v][r_Draw], 1);
			TextDrawLetterSize(v_VehicleInfo[v][r_Draw], 0.500000, 1.500000);
			TextDrawColor(v_VehicleInfo[v][r_Draw], -1);
			TextDrawSetOutline(v_VehicleInfo[v][r_Draw], 1);
			TextDrawSetProportional(v_VehicleInfo[v][r_Draw], 1);
		#elseif USE_TEXTDRAW_SET == 1
			v_VehicleInfo[v][r_Draw] = TextDrawCreate(309.000000, 20.000000, "Radio");
			TextDrawAlignment(v_VehicleInfo[v][r_Draw], 2);
			TextDrawBackgroundColor(v_VehicleInfo[v][r_Draw], 255);
			TextDrawFont(v_VehicleInfo[v][r_Draw], 2);
			TextDrawLetterSize(v_VehicleInfo[v][r_Draw], 0.519999, 2.000000);
			TextDrawColor(v_VehicleInfo[v][r_Draw], -1384447745);
			TextDrawSetOutline(v_VehicleInfo[v][r_Draw], 1);
			TextDrawSetProportional(v_VehicleInfo[v][r_Draw], 1);
		#elseif USE_TEXTDRAW_SET == 2
			v_VehicleInfo[v][r_Draw] = TextDrawCreate(95.000000, 304.000000, "Listening to: ~n~~w~Radio");
			TextDrawAlignment(v_VehicleInfo[v][r_Draw], 2);
			TextDrawBackgroundColor(v_VehicleInfo[v][r_Draw], 255);
			TextDrawFont(v_VehicleInfo[v][r_Draw], 1);
			TextDrawLetterSize(v_VehicleInfo[v][r_Draw], 0.400000, 1.899999);
			TextDrawColor(v_VehicleInfo[v][r_Draw], 1002045439);
			TextDrawSetOutline(v_VehicleInfo[v][r_Draw], 1);
			TextDrawSetProportional(v_VehicleInfo[v][r_Draw], 1);
		#endif
	}
	AddRadioStation("Radio Off","Off",0);
}

stock AddRadioStation(name[NAME_SIZE], link[LINK_SIZE], m = 1)
{
	if(RadioCount < MAX_RADIO_STATIONS)
	{
		format(r_RadioInfo[RadioCount][r_Name],NAME_SIZE,"%s",name);
		format(r_RadioInfo[RadioCount][r_Link],LINK_SIZE,"%s",link);
		if(m) printf("Dynamic Radio System: Created a radio station: \"ID %d\", Name: '%s'",RadioCount,name);
		RadioCount ++;
		return RadioCount -1;
	}
	else
	{
		printf("Error: Please increase MAX_RADIO_STATIONS, you are trying to create more than %d radio stations!",MAX_RADIO_STATIONS);
		return -1;
	}
}

stock SetRadioStation(vehicleid, stationid)
{
	new timer = -1;
	v_VehicleInfo[vehicleid][RadioPlaying] = stationid;
	#if USE_TEXTDRAW_SET == 2
		new string[50];
		format(string,sizeof(string),"Listening to: ~n~~w~%s",r_RadioInfo[stationid][r_Name]);
		TextDrawSetString(v_VehicleInfo[vehicleid][r_Draw],string);
	#else
		TextDrawSetString(v_VehicleInfo[vehicleid][r_Draw],r_RadioInfo[stationid][r_Name]);
	#endif
	for(new i = 0; i < MAX_PLAYERS; i ++)
	{
		if(IsPlayerConnected(i))
		{
			if(GetPlayerVehicleID(i) == vehicleid)
			{
				timer = GetPVarInt(i,"ID_HideRadioTextdraw");
				if(timer != -1)
				{
					TextDrawHideForPlayer(i,v_VehicleInfo[vehicleid][r_Draw]);
					KillTimer(timer);
				}
				TextDrawShowForPlayer(i,v_VehicleInfo[vehicleid][r_Draw]);
				SetPVarInt(i,"ID_HideRadioTextdraw",SetTimerEx("HideRadioTextdraw",TEXTDRAW_DISAPPEAR_TIME,false,"ii",i,vehicleid));
				PlayAudioStreamForPlayer(i,r_RadioInfo[stationid][r_Link]);
			}
		}
	}
	return 1;
}

//------------------------------------------- Functions -------------------------------------------
Hook:D_OnGameModeInit() InitializeScript();
Hook:D_OnFilterScriptInit() InitializeScript();

Hook:D_OnPlayerConnect(playerid)
{
	SetPVarInt(playerid,"ID_HideRadioTextdraw",-1);
	SetPVarInt(playerid,"ID_OldVehicle",-1);
	return 1;
}

Hook:D_OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
		new vehicleid = GetPlayerVehicleID(playerid),
			playingid = v_VehicleInfo[vehicleid][RadioPlaying];
		#if USE_TEXTDRAW_SET == 2
			new string[50];
			format(string,sizeof(string),"Listening to: ~n~~w~%s",r_RadioInfo[playingid][r_Name]);
			TextDrawSetString(v_VehicleInfo[vehicleid][r_Draw],string);
		#else
			TextDrawSetString(v_VehicleInfo[vehicleid][r_Draw],r_RadioInfo[playingid][r_Name]);
		#endif
		TextDrawShowForPlayer(playerid,v_VehicleInfo[vehicleid][r_Draw]);
		SetPVarInt(playerid,"ID_HideRadioTextdraw",SetTimerEx("HideRadioTextdraw",TEXTDRAW_DISAPPEAR_TIME,false,"ii",playerid,vehicleid));
		PlayAudioStreamForPlayer(playerid,r_RadioInfo[playingid][r_Link]);
		SetPVarInt(playerid,"ID_OldVehicle",vehicleid);
		return 1;
	}
	if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)
	{
		new vehicleid = GetPVarInt(playerid,"ID_OldVehicle"),
			timer = GetPVarInt(playerid,"ID_HideRadioTextdraw");
		if(timer != -1)
		{
			TextDrawHideForPlayer(playerid,v_VehicleInfo[vehicleid][r_Draw]);
			KillTimer(timer);
		}
		StopAudioStreamForPlayer(playerid);
	}
	return 1;
}

Hook:D_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		if(newkeys & KEY_YES)
		{
			new vehicleid = GetPlayerVehicleID(playerid),newstation = v_VehicleInfo[vehicleid][RadioPlaying] + 1;
			if(newstation == RadioCount) newstation = 0;	
			SetRadioStation(vehicleid,newstation);
			return 1;
		}
		else if(newkeys & KEY_NO)
		{
			new vehicleid = GetPlayerVehicleID(playerid),newstation = v_VehicleInfo[vehicleid][RadioPlaying] - 1;
			if(newstation == -1) newstation = RadioCount - 1;	
			SetRadioStation(vehicleid,newstation);
			return 1;
		}
	}
	return 1;
}

public HideRadioTextdraw(playerid, vehicleid)
{
	TextDrawHideForPlayer(playerid,v_VehicleInfo[vehicleid][r_Draw]);
	SetPVarInt(playerid,"ID_HideRadioTextdraw",-1);
	return 1;
}