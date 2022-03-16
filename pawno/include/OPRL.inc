/*______________________________________________________________________________
						OPRL.inc - OnPlayerRconLogin
						        By Lordzy.
							Version : 1.3
	"OPRL" AKA "OnPlayerRconLogin" is an include which procies a callback called
	OnPlayerRconLogin which gets called when a player logins as RCON. This is
	called only when a player ID logs in, not if an IP does.
      This Source Code Form is subject to the
      terms of the Mozilla Public License, v.
      2.0. If a copy of the MPL was not
      distributed with this file, You can
      obtain one at
      http://mozilla.org/MPL/2.0/.
      Thanks to :
	  Konstantinos for showing a better method in calling OPRL. (Based on v1.2)
	  SA-MP Team for SA-MP.
Author : Lordz™ AKA Lordzy.
Changelogs:
v1.0
01-02-2014
• Initial Release.
v1.2
02-02-2014
• Include has been optimized! Thanks to Konstantinos for showing a better method
  to callout "OnPlayerRconLogin"
Callbacks:
OnPlayerRconLogin(playerid);
v1.3
13-09-2014
• Defining of FILTERSCRIPT constant is no longer required before including this
  include in case if it's used for filterscripts. Thanks to Y_Less for the tip.
• Removed useless timer call.
• Fixed player array values while connections.
______________________________________________________________________________*/

#if defined _OnPlayerRconLogin_included
	#endinput
#endif

#define _OnPlayerRconLogin_included



static
	bool:OPRL_IsPlayerAdmin[MAX_PLAYERS],
	bool:OPRL_Init = true;

public OnPlayerConnect(playerid) {

	OPRL_IsPlayerAdmin[playerid] = false;
	#if defined OPRL_OnPlayerConnect
	    OPRL_OnPlayerConnect(playerid);
	#endif
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect OPRL_OnPlayerConnect

#if defined OPRL_OnPlayerConnect
forward OPRL_OnPlayerConnect(playerid);
#endif


static stock OPRL_CheckRCONAdmin(playerid) {

	if(IsPlayerAdmin(playerid) && OPRL_IsPlayerAdmin[playerid] == false) {

		OPRL_IsPlayerAdmin[playerid] = true;
		CallLocalFunction("OnPlayerRconLogin", "i", playerid);
	}
	else if(!IsPlayerAdmin(playerid) && OPRL_IsPlayerAdmin[playerid] == true) {

	    OPRL_IsPlayerAdmin[playerid] = false;
	}
	return 1;
}


public OnFilterScriptInit() {

	if(OPRL_Init) {
	
	    OPRL_Init = false;
		for(new i = 0, j = GetMaxPlayers(); i< j; i++) {

		    if(IsPlayerAdmin(i)) OPRL_IsPlayerAdmin[i] = true;
		    else OPRL_IsPlayerAdmin[i] = false;
		}
	}
	#if defined OPRL_OnFilterScriptInit
	    OPRL_OnFilterScriptInit();
	#endif
	return 1;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit OPRL_OnFilterScriptInit

#if defined OPRL_OnFilterScriptInit
forward OPRL_OnFilterScriptInit();
#endif




public OnGameModeInit() {

	if(OPRL_Init) {
	
	    OPRL_Init = false;
	    
		for(new i = 0, j = GetMaxPlayers(); i< j; i++) {

		    if(IsPlayerAdmin(i)) OPRL_IsPlayerAdmin[i] = true;
		    else OPRL_IsPlayerAdmin[i] = false;
		}
	}
	#if defined ORPL_OnGameModeInit
	    OPRL_OnGameModeInit();
	#endif
	return 1;
}


#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit OPRL_OnGameModeInit

#if defined OPRL_OnGameModeInit
forward OPRL_OnGameModeInit();
#endif


public OnRconLoginAttempt(ip[], password[], success) {

	if(success) SetTimerEx("OPRL_GetRconPlayer", 1000, false, "s", ip);
	#if defined OPRL_OnRconLoginAttempt
		OPRL_OnRconLoginAttempt(ip, password, success);
	#endif
	return 1;
}

#if defined _ALS_OnRconLoginAttempt
	#undef OnRconLoginAttempt
#else
	#define _ALS_OnRconLoginAttempt
#endif

#define OnRconLoginAttempt OPRL_OnRconLoginAttempt

#if defined OPRL_OnRconLoginAttempt
forward OPRL_OnRconLoginAttempt(ip[], password[], success);
#endif

forward OPRL_GetRconPlayer(ip[]);

public OPRL_GetRconPlayer(ip[]) {

	new
		OPRL_IP[16];
	for(new i = 0, j = GetMaxPlayers(); i< j; i++) {

		if(IsPlayerAdmin(i) && !OPRL_IsPlayerAdmin[i]) {

			GetPlayerIp(i, OPRL_IP, sizeof(OPRL_IP));
			if(!strcmp(ip, OPRL_IP, false)) {

			    OPRL_CheckRCONAdmin(i);
			    break;
			}
		}
	}
	return 1;
}

forward OnPlayerRconLogin(playerid);

/* Copyright(c) 2014 - "OPRL3.inc" */