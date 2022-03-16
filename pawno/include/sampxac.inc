/* AntiCheat by Bauer */

#include <a_samp>
#include <a_players>

stock Bauer_ResetPlayerMoney(playerid)
{
	//Osigurava Igraca
    SetPVarInt(playerid, "SiguranNovac", 1);
    //Resetuje Novac Igraca
	ResetPlayerMoney(playerid);
	return 1;
}
stock Bauer_SetPlayerHealth(playerid,Float:hp)
{
	SetPVarInt(playerid,"HpProtected",1);
	SetPlayerHealth(playerid,hp);
	return 1;
}
stock Bauer_GivePlayerMoney(playerid, money)
{
	//Osigurava Igraca
    SetPVarInt(playerid, "Money", 1);
    //Daje novac
	GivePlayerMoney(playerid, money);
	SetPVarInt(playerid, "Moneyyy", GetPlayerMoney(playerid));
	return 1;
}
stock Bauer_SetPlayerArmour(playerid,Float:armor)
{
	SetPVarFloat(playerid,"ArmorProtect",1);
	SetPlayerArmour(playerid,armor);
	SetPVarFloat(playerid, armour, armor);
}
