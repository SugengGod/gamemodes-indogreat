/*______________________________________________________________________________


						Auto AFK detector!
							By Lordz.
							 2013!
______________________________________________________________________________*/



#if defined _included_autoafk
 #endinput
#endif

#define _included_autoafk

#tryinclude <a_samp>

/*
native bool:IsPlayerPaused(playerid);
*/

new L_pTicks[MAX_PLAYERS],
	L_pAFK[MAX_PLAYERS],
	L_pisSpawned[MAX_PLAYERS];


stock ExecuteLAFK()
{
 SetTimer("L_AFKDETECT", 500, true);
 return 1;
}
forward L_AFKDETECT();

#if defined FILTERSCRIPT
public OnFilterScriptInit() { ExecuteLAFK(); CallLocalFunction("L_AFK_OnFS", ""); return 1; }
forward L_AFK_OnFS();
 #if defined _ALS_OnFilterScriptInit
  #undef OnFilterScriptInit
 #else
  #define _ALS_OnFilterScriptInit
 #endif

#define OnFilterScriptInit L_AFK_OnFS

#else
public OnGameModeInit() { ExecuteLAFK(); CallLocalFunction("L_AFK_OnGM", ""); return 1; }
forward L_AFK_OnGM();
 #if defined _ALS_OnGameModeInit
  #undef OnGameModeInit
 #else
  #define _ALS_OnGameModeInit
 #endif

#define OnGameModeInit L_AFK_OnGM
#endif

public OnPlayerUpdate(playerid)
{
 L_pTicks[playerid] = GetTickCount();
 if(L_pAFK[playerid] == 1)
 {
  L_pAFK[playerid] = 0;
  CallLocalFunction("OnPlayerResume", "i", playerid);
 }
 CallLocalFunction("L_AFK_OPU", "i", playerid);
 return 1;
}

forward L_AFK_OPU(playerid);

#if defined _ALS_OnPlayerUpdate
 #undef OnPlayerUpdate
#else
 #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate L_AFK_OPU

public OnPlayerConnect(playerid)
{
 L_pAFK[playerid] = 0;
 L_pTicks[playerid] = 0;
 L_pisSpawned[playerid] = 0;
 CallLocalFunction("L_AFK_OPC", "i", playerid);
 return 1;
}

forward L_AFK_OPC(playerid);

#if defined _ALS_OnPlayerConnect
 #undef OnPlayerConnect
#else
 #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect L_AFK_OPC

public OnPlayerSpawn(playerid)
{
 L_pisSpawned[playerid] = 1;
 CallLocalFunction("L_AFK_OPS", "i", playerid);
 return 1;
}

forward L_AFK_OPS(playerid);

#if defined _ALS_OnPlayerSpawn
 #undef OnPlayerSpawn
#else
 #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn L_AFK_OPS

public OnPlayerDeath(playerid, killerid, reason)
{
 L_pisSpawned[playerid] = 0;
 CallLocalFunction("L_AFK_OPD", "iii", playerid, killerid, reason);
 return 1;
}

forward L_AFK_OPD(playerid, killerid, reason);

#if defined _ALS_OnPlayerDeath
 #undef OnPlayerDeath
#else
 #define _ALS_OnPlayerDeath
#endif

#define OnPlayerDeath L_AFK_OPD

public L_AFKDETECT()
{
 new tick = GetTickCount();
 for(new i; i< GetMaxPlayers(); i++)
 {
  if(!IsPlayerConnected(i)) continue;
  if(L_pAFK[i] != 0) continue;
  if(L_pisSpawned[i] != 1) continue;
  if((tick - L_pTicks[i]) >= 4500)
  {
   if(GetPlayerState(i) >= 1 && GetPlayerState(i) <= 3)
   {
	L_pAFK[i] = 1;
	CallLocalFunction("OnPlayerPause", "i", i);
   }
  }
 }
 return 1;
}

forward OnPlayerPause(playerid);
forward OnPlayerResume(playerid);

stock bool:IsPlayerPaused(playerid)
{
 if(L_pAFK[playerid] == 1) return true;
 else return false;
}
