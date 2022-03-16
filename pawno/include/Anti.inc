/*

				ANTI-SYSTEM BY HY
				
				
1. Anti-High Ping (300) ;
2. Anti-Jetpack ;
3. Anti-Money Hack ;
4. Anti-Weapon Hack ; Weapon Blocker ;
5. Anti-Health Hack ;
6. Anti-Armour Hack ;
7. Anti-Vehicle Speed Hack ;
8. Anti-Command Spam ;
9. Anti-Fly Car ;
10. Anti C-BUG System ;

*/


//------------------------------------------------------------------------------
#include <a_samp>
//------------------------------------------------------------------------------
forward PingChecker();
forward AntiJetpack();
forward GivePlayerMoneyEx(playerid,ammount);
forward CheckMoney();
//------------------------------------------------------------------------------
new bool:PingChecked[MAX_PLAYERS];
new OldMoney[MAX_PLAYERS];
new NewMoney[MAX_PLAYERS];
new Float:pHealth, Float:pArmour;
//------------------------------------------------------------------------------

public OnGameModeInit()
{
    SetTimer("PingChecker", 60000, true);
    SetTimer("CheckMoney",5000,true);
	return 1;
}

public PingChecker()
{
    for(new i;i < MAX_PLAYERS;i++)
    {
        if(IsPlayerConnected(i))
        {
            if(GetPlayerPing(i) > 300 && PingChecked[i] == false) 
            {
                SendClientMessage(i, -1, "[SERVER]: {15FF00}We checked you, and you got High-Ping. Please solve it or you will get kicked !");
                PingChecked[i] = true;
            }
            if(GetPlayerPing(i) > 300 && PingChecked[i] == true) 
            {
                new pName[MAX_PLAYER_NAME] , string[MAX_PLAYER_NAME*2];
                GetPlayerName(i, pName, sizeof(pName));
                format(string, sizeof(string), "{FF0000}[SERVER]: {FFCC33}%s {15FF00}was kicked by {FF0000}AdmBot ! {FFFFFF}|| {FFFF00}Reason: {15FF00}High-Ping;", pName);
                SendClientMessageToAll(-1, string);
                SendClientMessage(i, -1, "{FF0000}[SERVER]: {FFCC33}You got kicked from High-Ping !");
                Kick(i);
            }
        }
    }
    return 1;
}

public AntiJetpack()
{
    new playerid;
    if (GetPlayerSpecialAction(playerid) == 2)
    {
        new string[128],name[MAX_PLAYER_NAME];
        GetPlayerName(playerid,name,sizeof(name));
        format(string,sizeof(string),"{FF0000}[SERVER]: {FFCC33}%s {15FF00}got kicked by {FF0000}AdmBot ! {FFFFFF}|| {FFFF00}Reason: {15FF00}Jetpack Hack",name);
        SendClientMessageToAll(-1,string);
        Kick(playerid);
    }
}

public GivePlayerMoneyEx(playerid,ammount)
{
      OldMoney[playerid] = GetPlayerMoney(playerid);
      NewMoney[playerid] = ammount;
      GivePlayerMoney(playerid,ammount);

      return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_FIRE && ForbiddenWeap(playerid) && !IsPlayerAdmin(playerid))
    {
        new pname[MAX_PLAYER_NAME];
        new string[124];
        GetPlayerName(playerid, pname, sizeof(pname));
        format(string, sizeof(string), "[SERVER]: {FFCC33}%s {15FF00}has been kicked by {FF0000}AdminBot! {FFFFFF}|| {FFFF00}Reason: {15FF00}Weapon Hack !", pname);
        SendClientMessageToAll(-1,string);
        print(string);
        SetTimerEx("KickTimer", 10, false, "i", playerid);
        BanEx(playerid,string);
        return 1;
	}
	if(pHealth >= 100.1)
	{
	    Kick(playerid);
	}
	if(pArmour >= 100.1)
	{
	    Kick(playerid);
	}
    return 0;
}

public CheckMoney()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i))
        {
            if(GetPlayerMoney(i) > NewMoney[i])
            {
                ResetPlayerMoney(i);
                GivePlayerMoney(i,OldMoney[i]);
            }
		}
    }
    return 1;
}

public OnPlayerText(playerid, text[])
{
   new lol = GetTickCount();
   if(GetTickCount() - lol < 3000)
   {
    SendClientMessage(playerid,-1,"{FF0000}[SERVER]: {15FF00}You need to wait 3 seconds before write a command again !");
   }
   return 1;
}

stock ForbiddenWeap(playerid)
{
    new wp = GetPlayerWeapon(playerid);
    if( wp == 38 || wp == 37 || wp == 36 || wp == 35)
    {
        return true;
    }
    return false;
}

stock GetVehicleVelocityVehicle(vehicle)
{
    new Float:Velocity[3], output[80];
	GetVehicleVelocity(GetPlayerVehicleID(playerid), Velocity[0], Velocity[1], Velocity[2]);
	if(Velocity >= 500)
	{
		Kick(playerid);
	}
}

forward OnPlayerCBug(playerid);
public OnPlayerCBug(playerid)
{
    new playername[MAX_PLAYER_NAME];
    GetPlayerName(playerid, playername, sizeof(playername));
    new str2[128];
    new string[128];
    format(str2, sizeof(str2), "{FF0000}[SERVER]: {15FF00}%s made C-BUG, so he got slaped !", playername);
    new Float:Health; GetPlayerHealth(playerid,Health); SetPlayerHealth(playerid,Health-10);
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    SetPlayerPos(playerid, x, y, z+15);
    PlayerPlaySound(playerid,1190,0.0,0.0,0.0); PlayerPlaySound(playerid,1190,0.0,0.0,0.0);
    SendClientMessageToAll(-1, string);
    return 1;
}