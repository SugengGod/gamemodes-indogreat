/*
								seif_fight - Fighting Styles for SA-MP 0.2.2 by Seif
*/
/*x---------------------------------Important-------------------------------------x*/
//**INCLUDES**//
#include <a_samp>
/*x---------------------------------Defining-------------------------------------x*/
//**DEFINES**//
#define CJ		0
#define STREET  1
#define KUNGFU  2
#define BOX     3
//**COLORS*//
#define GREEN 			0x21DD00FF
#define RED 			0xE60000FF
#define ADMIN_RED 		0xFB0000FF
#define YELLOW 			0xFFFF00FF
#define ORANGE 			0xF97804FF
#define LIGHTRED 		0xFF8080FF
#define LIGHTBLUE 		0x00C2ECFF
#define PURPLE 			0xB360FDFF
#define BLUE 			0x1229FAFF
#define LIGHTGREEN 		0x38FF06FF
#define DARKPINK 		0xE100E1FF
#define DARKGREEN 		0x008040FF
#define ANNOUNCEMENT 	0x6AF7E1FF
#define GREY 			0xCECECEFF
#define PINK 			0xD52DFFFF
#define DARKGREY    	0x626262FF
#define AQUAGREEN   	0x03D687FF
#define NICESKY 		0x99FFFFAA
#define WHITE 			0xFFFFFFFF
//**VARIABLES**//
new anim[MAX_PLAYERS];
new delay[MAX_PLAYERS];
new FightStyle[MAX_PLAYERS];
new hit[MAX_PLAYERS];
//**FORWARDS**//
forward ClearAnim(playerid);
forward IncreaseAnim(playerid);
/*x---------------------------------CallBacks-------------------------------------x*/
Fight_OnPlayerConnect(playerid)
{
    anim[playerid] = 1;
	delay[playerid] = 0;
	FightStyle[playerid] = 0;
	hit[playerid] = 0;
	return 1;
}

Fight_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
   	if ((oldkeys & 16 && newkeys & KEY_HANDBRAKE || newkeys & 16 && oldkeys & KEY_HANDBRAKE || newkeys & 16 && newkeys & KEY_HANDBRAKE) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
	    if (FightStyle[playerid] == STREET)
	    {
	    	if (anim[playerid] == 1 && delay[playerid] == 0 && hit[playerid] == 0)
			{
				ApplyAnimation(playerid,"FIGHT_D","FightD_3",4.1,0,1,1,1,0);
				delay[playerid] = 1;
				SetTimerEx("IncreaseAnim",1000,false,"i",playerid);
				new Float:X,Float:Y,Float:Z,Float:A;
				new Float:iX,Float:iY,Float:iZ,Float:iA;
				GetPlayerPos(playerid,X,Y,Z);
				GetPlayerFacingAngle(playerid,A);
				for(new i = 0; i < GetMaxPlayers(); i++)
				{
				    if (!IsPlayerConnected(i)) continue;
				    GetPlayerPos(i,iX,iY,iZ);
			    	if (i != playerid)
			    	{
			    	    Fight_GetXYInFrontOfPlayer(i, iX, iY, 2);
			     	   	if (Fight_PlayerToPoint(playerid, 2, iX, iY, iZ))
			     	   	{
			     	   		GetPlayerFacingAngle(i,iA);
			     	   	    if((iA >= ((A-180)-30) && iA <=((A-180)+30)) || (iA >= ((A+180)-30) && iA <=((A+180)+30)))
			     	   	    {
			     	   	        iX -= (2.0 * floatsin(-iA, degrees));
								iY -= (2.0 * floatcos(-iA, degrees));
                     			SetPlayerPos(i, iX, iY, iZ);
				     	        SetPlayerFacingAngle(i, A-180);
				     	  	 	new Float:hp;
				     		   	GetPlayerHealth(i, hp);
				    	    	SetPlayerHealth(i, hp-2);
				     		   	ApplyAnimation(i,"FIGHT_D","HitD_1",4.1,0,1,1,1,0);
				     		   	hit[i] = 1;
				    	    	SetTimerEx("ClearAnim",1000,false,"i",i);
			    	    	}
			    	    	else
							{
								SetTimerEx("ClearAnim",1000,false,"i",i);
							}
						}
			    	}
				}
			}
			else if (anim[playerid] == 2 && delay[playerid] == 0 && hit[playerid] == 0)
			{
			    ApplyAnimation(playerid,"FIGHT_D","FightD_2",4.1,0,1,1,1,0);
				delay[playerid] = 1;
				SetTimerEx("IncreaseAnim",2000,false,"i",playerid);
				new Float:X,Float:Y,Float:Z,Float:A;
				new Float:iX,Float:iY,Float:iZ,Float:iA;
				GetPlayerPos(playerid,X,Y,Z);
				GetPlayerFacingAngle(playerid,A);
				for(new i = 0; i < GetMaxPlayers(); i++)
				{
				    if (!IsPlayerConnected(i)) continue;
				    GetPlayerPos(i,iX,iY,iZ);
			    	if (i != playerid)
			    	{
			    	    Fight_GetXYInFrontOfPlayer(i, iX, iY, 2);
			     	   	if (Fight_PlayerToPoint(playerid, 2, iX, iY, iZ))
			     	   	{
			     	   		GetPlayerFacingAngle(i,iA);
			     	   	    if((iA >= ((A-180)-30) && iA <=((A-180)+30)) || (iA >= ((A+180)-30) && iA <=((A+180)+30)))
			     	   	    {
			     	   	        iX -= (2.0 * floatsin(-iA, degrees));
								iY -= (2.0 * floatcos(-iA, degrees));
                     			SetPlayerPos(i, iX, iY, iZ);
				     	        SetPlayerFacingAngle(i, A-180);
				     	  	 	new Float:hp;
				     		   	GetPlayerHealth(i, hp);
				    	    	SetPlayerHealth(i, hp-5);
				     		   	ApplyAnimation(i,"FIGHT_D","HitD_2",4.1,0,1,1,1,0);
				     		   	hit[i] = 1;
				    	    	SetTimerEx("ClearAnim",2000,false,"i",i);
			    	    	}
			    	    	else
							{
								SetTimerEx("ClearAnim",2000,false,"i",i);
							}
						}
			    	}
				}
			}
		}

		else if (FightStyle[playerid] == KUNGFU)
	    {
	        if (anim[playerid] == 1 && delay[playerid] == 0 && hit[playerid] == 0)
			{
				ApplyAnimation(playerid,"FIGHT_C","FightC_2",4.1,0,1,1,1,0);
				delay[playerid] = 1;
				SetTimerEx("IncreaseAnim",1000,false,"i",playerid);
				new Float:X,Float:Y,Float:Z,Float:A;
				new Float:iX,Float:iY,Float:iZ,Float:iA;
				GetPlayerPos(playerid,X,Y,Z);
				GetPlayerFacingAngle(playerid,A);
				for(new i = 0; i < GetMaxPlayers(); i++)
				{
				    if (!IsPlayerConnected(i)) continue;
				    GetPlayerPos(i,iX,iY,iZ);
			    	if (i != playerid)
			    	{
			    	    Fight_GetXYInFrontOfPlayer(i, iX, iY, 2);
			     	   	if (Fight_PlayerToPoint(playerid, 2, iX, iY, iZ))
			     	   	{
			     	   		GetPlayerFacingAngle(i,iA);
			     	   	    if((iA >= ((A-180)-30) && iA <=((A-180)+30)) || (iA >= ((A+180)-30) && iA <=((A+180)+30)))
			     	   	    {
			     	   	        iX -= (2.0 * floatsin(-iA, degrees));
								iY -= (2.0 * floatcos(-iA, degrees));
                     			SetPlayerPos(i, iX, iY, iZ);
				     	        SetPlayerFacingAngle(i, A-180);
				     	  	 	new Float:hp;
				     		   	GetPlayerHealth(i, hp);
				    	    	SetPlayerHealth(i, hp-2.5);
				     		   	ApplyAnimation(i,"FIGHT_C","HitC_2",4.1,0,1,1,1,0);
				     		   	hit[i] = 1;
				    	    	SetTimerEx("ClearAnim",1000,false,"i",i);
			    	    	}
			    	    	else
							{
								SetTimerEx("ClearAnim",1000,false,"i",i);
							}
						}
			    	}
				}
			}
			else if (anim[playerid] == 2 && delay[playerid] == 0 && hit[playerid] == 0)
			{
			    ApplyAnimation(playerid,"FIGHT_C","FightC_3",4.1,0,1,1,1,0);
				delay[playerid] = 1;
				SetTimerEx("IncreaseAnim",1500,false,"i",playerid);
				new Float:X,Float:Y,Float:Z,Float:A;
				new Float:iX,Float:iY,Float:iZ,Float:iA;
				GetPlayerPos(playerid,X,Y,Z);
				GetPlayerFacingAngle(playerid,A);
				for(new i = 0; i < GetMaxPlayers(); i++)
				{
				    if (!IsPlayerConnected(i)) continue;
				    GetPlayerPos(i,iX,iY,iZ);
			    	if (i != playerid)
			    	{
			    	    Fight_GetXYInFrontOfPlayer(i, iX, iY, 2);
			     	   	if (Fight_PlayerToPoint(playerid, 2, iX, iY, iZ))
			     	   	{
			     	   		GetPlayerFacingAngle(i,iA);
			     	   	    if((iA >= ((A-180)-30) && iA <=((A-180)+30)) || (iA >= ((A+180)-30) && iA <=((A+180)+30)))
			     	   	    {
			     	   	        iX -= (2.0 * floatsin(-iA, degrees));
								iY -= (2.0 * floatcos(-iA, degrees));
                     			SetPlayerPos(i, iX, iY, iZ);
				     	        SetPlayerFacingAngle(i, A-180);
				     	  	 	new Float:hp;
				     		   	GetPlayerHealth(i, hp);
				    	    	SetPlayerHealth(i, hp-5);
				     		   	ApplyAnimation(i,"FIGHT_C","HitC_3",4.1,0,1,1,1,0);
				     		   	hit[i] = 1;
				    	    	SetTimerEx("ClearAnim",1500,false,"i",i);
			    	    	}
			    	    	else
							{
								SetTimerEx("ClearAnim",1500,false,"i",i);
							}
						}
			    	}
				}
			}
		}

		else if (FightStyle[playerid] == BOX)
	    {
	        if (anim[playerid] == 1 && delay[playerid] == 0 && hit[playerid] == 0)
			{
				ApplyAnimation(playerid,"FIGHT_B","FightB_2",4.1,0,1,1,1,0);
				delay[playerid] = 1;
				SetTimerEx("IncreaseAnim",1000,false,"i",playerid);
				new Float:X,Float:Y,Float:Z,Float:A;
				new Float:iX,Float:iY,Float:iZ,Float:iA;
				GetPlayerPos(playerid,X,Y,Z);
				GetPlayerFacingAngle(playerid,A);
				for(new i = 0; i < GetMaxPlayers(); i++)
				{
				    if (!IsPlayerConnected(i)) continue;
				    GetPlayerPos(i,iX,iY,iZ);
			    	if (i != playerid)
			    	{
			    	    Fight_GetXYInFrontOfPlayer(i, iX, iY, 2);
			     	   	if (Fight_PlayerToPoint(playerid, 2, iX, iY, iZ))
			     	   	{
			     	   		GetPlayerFacingAngle(i,iA);
			     	   	    if((iA >= ((A-180)-30) && iA <=((A-180)+30)) || (iA >= ((A+180)-30) && iA <=((A+180)+30)))
			     	   	    {
			     	   	        iX -= (2.0 * floatsin(-iA, degrees));
								iY -= (2.0 * floatcos(-iA, degrees));
                     			SetPlayerPos(i, iX, iY, iZ);
				     	        SetPlayerFacingAngle(i, A-180);
				     	  	 	new Float:hp;
				     		   	GetPlayerHealth(i, hp);
				    	    	SetPlayerHealth(i, hp-2);
				     		   	ApplyAnimation(i,"FIGHT_B","HitB_2",4.1,0,1,1,1,0);
				     		   	hit[i] = 1;
				    	    	SetTimerEx("ClearAnim",1000,false,"i",i);
			    	    	}
			    	    	else
							{
								SetTimerEx("ClearAnim",1000,false,"i",i);
							}
						}
			    	}
				}
			}
			else if (anim[playerid] == 2 && delay[playerid] == 0 && hit[playerid] == 0)
			{
			    ApplyAnimation(playerid,"FIGHT_B","FightB_3",4.1,0,1,1,1,0);
				delay[playerid] = 1;
				SetTimerEx("IncreaseAnim",1500,false,"i",playerid);
				new Float:X,Float:Y,Float:Z,Float:A;
				new Float:iX,Float:iY,Float:iZ,Float:iA;
				GetPlayerPos(playerid,X,Y,Z);
				GetPlayerFacingAngle(playerid,A);
				for(new i = 0; i < GetMaxPlayers(); i++)
				{
				    if (!IsPlayerConnected(i)) continue;
				    GetPlayerPos(i,iX,iY,iZ);
			    	if (i != playerid)
			    	{
			    	    Fight_GetXYInFrontOfPlayer(i, iX, iY, 2);
			     	   	if (Fight_PlayerToPoint(playerid, 2, iX, iY, iZ))
			     	   	{
			     	   		GetPlayerFacingAngle(i,iA);
			     	   	    if((iA >= ((A-180)-30) && iA <=((A-180)+30)) || (iA >= ((A+180)-30) && iA <=((A+180)+30)))
			     	   	    {
			     	   	        iX -= (2.0 * floatsin(-iA, degrees));
								iY -= (2.0 * floatcos(-iA, degrees));
                     			SetPlayerPos(i, iX, iY, iZ);
				     	        SetPlayerFacingAngle(i, A-180);
				     	  	 	new Float:hp;
				     		   	GetPlayerHealth(i, hp);
				    	    	SetPlayerHealth(i, hp-5);
				     		   	ApplyAnimation(i,"FIGHT_B","HitB_3",4.1,0,1,1,1,0);
				     		   	hit[i] = 1;
				    	    	SetTimerEx("ClearAnim",1500,false,"i",i);
			    	    	}
			    	    	else
							{
								SetTimerEx("ClearAnim",1500,false,"i",i);
							}
						}
			    	}
				}
			}
		}
	}
	return 1;
}

forward IncreaseAnim(playerid);
public  IncreaseAnim(playerid)
{
	if (anim[playerid] == 1) ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0),anim[playerid] = 2,delay[playerid] = 0;
	else if (anim[playerid] == 2) ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0),anim[playerid] = 1,delay[playerid] = 0;
}

forward ClearAnim(playerid);
public  ClearAnim(playerid)
{
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    hit[playerid] = 0;
}

stock Fight_PlayerToPoint(playerid,Float:radi, Float:px, Float:py, Float:pz)
{
    if(IsPlayerConnected(playerid))
	{
		new Float:x, Float:y, Float:z;
		new Float:ox, Float:oy, Float:oz;
		GetPlayerPos(playerid, ox, oy, oz);
		x = (ox -px);
		y = (oy -py);
		z = (oz -pz);
		if (((x < radi) && (x > -radi)) && ((y < radi) && (y > -radi)) && ((z < radi) && (z > -radi))) return 1;
	}
	return 0;
}

Fight_GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{	// Created by Y_Less

	new Float:a;

	GetPlayerPos(playerid, x, y, a);
	GetPlayerFacingAngle(playerid, a);

	if (GetPlayerVehicleID(playerid)) {
	    GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
	}

	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

SetPlayerFightingStyle(playerid, style)
{
	if (style >= 0 && style <= 3) FightStyle[playerid] = style;
	else FightStyle[playerid] = 0;
}

GetPlayerFightingStyle(playerid) return FightStyle[playerid];
