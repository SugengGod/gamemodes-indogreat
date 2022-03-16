#if defined _GP_included
	#endinput
#endif

#define _GP_included
#pragma library Pcash

/*
native GivePlayerMoneyEx(playerid, money)
native ResetPlayerMoneyEx(playerid)
native GetPlayerMoneyEx(playerid)
*/

new GP[MAX_PLAYERS];

stock GivePlayerMoneyEx(playerid, money) {

	GP[playerid] = GP[playerid] + money;
	return GP[playerid];
}

stock ResetPlayerMoneyEx(playerid) {

	GP[playerid] = 0;
	return GP[playerid];
}

stock GetPlayerMoneyEx(playerid) {

	return GP[playerid];
}