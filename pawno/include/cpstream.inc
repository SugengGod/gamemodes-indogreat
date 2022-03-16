/*               Checkpoint Streamer by Emmet_

         With this script, you can create checkpoints around San Andreas!
         Basically, the nearest checkpoint is shown to you (because you can
         only show 1 checkpoint at a time).

		 You can create checkpoints under OnGameModeInit using CreateCheckpoint.
		 They are shown automatically. Enjoy!
*/

#include <a_samp>

#define MAX_CHECKPOINTS 50

enum CP_DATA
{
	Float:CheckpointX,
	Float:CheckpointY,
	Float:CheckpointZ,
	Float:CheckpointSize,
	CheckpointExists,
	CheckpointTimer
};

new CheckpointData[MAX_CHECKPOINTS + 1][CP_DATA];
new CheckpointStreamed[MAX_PLAYERS];

forward StreamCheckpoint(cpid);

stock CreateCheckpoint(Float:cpx, Float:cpy, Float:cpz, Float:cpsize)
{
	new
	    checkpointid;
	for (new i = 1; i <= MAX_CHECKPOINTS; i ++)
	{
	    if (CheckpointData[i][CheckpointExists] == 0)
		{
			checkpointid = i;
			break;
		}
	}
	if (checkpointid != 0)
	{
		CheckpointData[checkpointid][CheckpointX] = cpx;
		CheckpointData[checkpointid][CheckpointY] = cpy;
		CheckpointData[checkpointid][CheckpointZ] = cpz;
		CheckpointData[checkpointid][CheckpointSize] = cpsize;
		CheckpointData[checkpointid][CheckpointExists] = 1;
		CheckpointData[checkpointid][CheckpointTimer] = SetTimerEx("StreamCheckpoint", 200, true, "i", checkpointid);
		return checkpointid;
	}
	return 0;
}

stock DestroyCheckpoint(cpid)
{
	if (CheckpointData[cpid][CheckpointExists])
	{
	    for (new i = 0; i < MAX_PLAYERS; i ++)
	    {
	        if (CheckpointStreamed[i] > 0)
	        {
	            CheckpointStreamed[i] = 0;
				DisablePlayerCheckpoint(i);
			}
		}
		CheckpointData[cpid][CheckpointX] = 0.0;
		CheckpointData[cpid][CheckpointY] = 0.0;
		CheckpointData[cpid][CheckpointZ] = 0.0;
		CheckpointData[cpid][CheckpointSize] = 0.0;
		CheckpointData[cpid][CheckpointExists] = 0;
		KillTimer(CheckpointData[cpid][CheckpointTimer]);
		return 1;
	}
	return 0;
}

stock ShowPlayerCheckpoint(playerid, cpid)
{
	if (IsPlayerConnected(playerid))
	{
		if (CheckpointData[cpid][CheckpointExists])
		{
  			CheckpointStreamed[playerid] = cpid;
     		SetPlayerCheckpoint(playerid, CheckpointData[cpid][CheckpointX], CheckpointData[cpid][CheckpointY], CheckpointData[cpid][CheckpointZ], CheckpointData[cpid][CheckpointSize]);
			return 1;
		}
	}
	return 0;
}

public StreamCheckpoint(cpid)
{
	for (new i = 0; i < MAX_PLAYERS; i ++)
	{
	    if (CheckpointData[cpid][CheckpointExists])
	    {
	        if (CheckpointStreamed[i] != cpid)
	        {
	        	if (IsPlayerInRangeOfPoint(i, (CheckpointData[cpid][CheckpointSize] + 1.0), CheckpointData[cpid][CheckpointX], CheckpointData[cpid][CheckpointY], CheckpointData[cpid][CheckpointZ]))
	        	{
	            	ShowPlayerCheckpoint(i, cpid);
				}
			}
		}
	}
	return 1;
}

stock GetPlayerCheckpointID(playerid)
	return CheckpointStreamed[playerid];
	