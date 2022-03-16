/*

"Player/ Object Load" by Dustin/ Las Venturas CNR.
http://forum.sa-mp.com/showthread.php?t=191112

Current Script Version: v0.3a

Changes:
- v0.2a - Timer set down, now 3100.
- v0.3a - It unfreezes the player properly.

Credits:

Dustin/ Las Venturas CNR - Main scripting.
Zh3r0 - Mentioned the bug will not unfreezing the player.*/

#include <a_samp>

new Loaded[MAX_PLAYERS];
forward LoadPlayer();

stock Pause(playerid)
{
	TogglePlayerControllable(playerid,false);
    GameTextForPlayer(playerid, "~g~objects loading, please wait...", 5000,1);
	Loaded[playerid] = 1;
   	new Float:x, Float:y, Float:z;
   	GetPlayerPos(playerid, x, y, z);
 	SetPlayerPos(playerid,x,y,z+1);
    SetTimer("LoadPlayer",3100,false);

}

public LoadPlayer()
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(Loaded[i] == 1)
			{
			TogglePlayerControllable(i,true);
			Loaded[i] = 0;
			}
		}
	}
}
