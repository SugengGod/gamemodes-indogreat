forward GivePlayerDrunkLevel(playerid,level);
forward SetPlayerMoney(playerid,money);
forward GivePlayerHealth(playerid,health);
forward GivePlayerArmour(playerid,armour);
forward GivePlayerScore(playerid,score);
forward GivePlayerWantedLevel(playerid,level);
public GivePlayerDrunkLevel(playerid,level)
{
	new dLevel = GetPlayerDrunkLevel(playerid);
	SetPlayerDrunkLevel(playerid,dLevel+level);
	return 1;
}

public SetPlayerMoney(playerid,money)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid,money);
	return 1;
}

public GivePlayerHealth(playerid,health)
{
	new Float: pHealth;
	GetPlayerHealth(playerid,pHealth);
	SetPlayerHealth(playerid,pHealth+health);
	return 1;
}

public GivePlayerArmour(playerid,armour)
{
	new Float: pArmour;
	GetPlayerArmour(playerid,pArmour);
	SetPlayerArmour(playerid,pArmour+armour);
	return 1;
}

public GivePlayerScore(playerid,score)
{
	new pScore = GetPlayerScore(playerid);
	SetPlayerScore(playerid,pScore+score);
	return 1;
}

public GivePlayerWantedLevel(playerid,level)
{
	new pLevel = GetPlayerWantedLevel(playerid);
	SetPlayerWantedLevel(playerid,pLevel+level);
	return 1;
}


/*

native GivePlayerDrunkLevel(playerid,level);
native SetPlayerMoney(playerid,money);
native GivePlayerHealth(playerid,health);
native GivePlayerArmour(playerid,armour);
native GivePlayerScore(playerid,score);
native GivePlayerWantedLevel(playerid,level);
*/