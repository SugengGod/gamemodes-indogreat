///****************************************************************************//
/*                           Fire-Script
								by
							Sniperwolfes
*/
//****************************************************************************//


#include <a_samp>
//======================================
#define Labels // 3D Labels above the Fires showing the Health?
#define LoseHealth // Should Players and Vehicles lose Health if they stand in the fire?
//======================================
#define Holding(%0) \
	((newkeys & (%0)) == (%0))
#define MaxFire 80 // How many fires max.?
forward OnFireKill(ID, killerid);
forward f_OnPlayerUpdate(playerid);
//forward VehicleToPoint(Float:radi, vehicleid, Float:x, Float:y, Float:z);
forward HealthDown();
forward f_init();


public f_init()
{
	#if defined LoseHealth
		SetTimer("HealthDown", 600, 1);
	#endif
}	


new
    FireObj[MaxFire],
    Float:FirePos[MaxFire][3],
	TotalFires = 0,
	FireHealth[MaxFire],
	FireHealthMax[MaxFire];

#if defined Labels
new Text3D:FireText[MaxFire];
#endif

stock AddFire(Float:x, Float:y, Float:z, Health)
{
    TotalFires++;
	new ID = TotalFires;
	FireObj[ID] = CreateObject(3461, x, y, z-2.61, 0, 0, 0.0);
	FirePos[ID][0] = x, FirePos[ID][1] = y, FirePos[ID][2] = z;
	FireHealth[ID] = Health;
	FireHealthMax[ID] = Health;
	#if defined Labels
	    new string[128];
	    format(string, sizeof(string), "%d/%d", FireHealth[ID], FireHealthMax[ID]);
	    FireText[ID] = Create3DTextLabel(string, 0xFFFFFFFFF, x, y, z, 20, 0);
	#endif
}
stock DeleteFire(ID)
{
	DestroyObject(FireObj[ID]);
	TotalFires--;
	FirePos[ID][0] = 0, FirePos[ID][1] = 0, FirePos[ID][2] = 0;
	#if defined Labels
	    Delete3DTextLabel(FireText[ID]);
	#endif
}
stock DeleteAllFire()
{
	new ID;
	for(ID = 0; ID<MaxFire; ID++)
	{
		DestroyObject(FireObj[ID]);
		TotalFires= 0;
		FirePos[ID][0] = 0, FirePos[ID][1] = 0, FirePos[ID][2] = 0;
		#if defined Labels
	    	Delete3DTextLabel(FireText[i]);
		#endif
	}
}
stock IsValidFire(ID)
{
	if( (FirePos[ID][0] != 0) && (FirePos[ID][1] != 0) && (FirePos[ID][2] != 0) ) return true;
	else return false;
}

stock GetClosestFire(playerid)
{
	new i;
	for(i = 0; i<MaxFire; i++)
	{
	    if(IsValidFire(i) && IsPlayerInRangeOfPoint(playerid, 1, FirePos[i][0],  FirePos[i][1],  FirePos[i][2]))
	    {
	        return i;
		}
	}
	return 0;
}


public f_OnPlayerUpdate(playerid)
{
	new newkeys,l,u;
	GetPlayerKeys(playerid, newkeys, l, u);
	new i;
	if(Holding(KEY_FIRE))
	{
        if(GetPlayerWeapon(playerid) == 42)
        {
            for(i = 0; i<MaxFire; i++)
 	    	{
 	        	if(IsValidFire(i))
 	        	{
 	        	    if(PlayerFaces(playerid, FirePos[i][0],  FirePos[i][1],  FirePos[i][2], 1) && IsPlayerInRangeOfPoint(playerid, 4, FirePos[i][0],  FirePos[i][1],  FirePos[i][2]))
 	        		{
			    		FireHealth[i]-=2;
					    #if defined Labels
				    		new string[128];
					    	format(string, sizeof(string), "%d/%d", FireHealth[i], FireHealthMax[i]);
							Update3DTextLabelText(FireText[i], 0xFFFFFFFF, string);
					    	//Delete3DTextLabel(FireText[i]);
						//FireText[i] = Create3DTextLabel(string, 0xFFFFFFFF, FirePos[i][0],  FirePos[i][1],  FirePos[i][2], 20, 0);
					    #endif
					    if(FireHealth[i] <= 0)
					    {
							DeleteFire(i);
							CallRemoteFunction("OnFireDeath", "dd", i, playerid);
						}
					}
				}
			}
		}
	}
	return 1;
}


/*Float:DistanceCameraTargetToLocation(Float:CamX, Float:CamY, Float:CamZ,   Float:ObjX, Float:ObjY, Float:ObjZ,   Float:FrX, Float:FrY, Float:FrZ) {

	new Float:TGTDistance;
	TGTDistance = floatsqroot((CamX - ObjX) * (CamX - ObjX) + (CamY - ObjY) * (CamY - ObjY) + (CamZ - ObjZ) * (CamZ - ObjZ));
	new Float:tmpX, Float:tmpY, Float:tmpZ;
	tmpX = FrX * TGTDistance + CamX;
	tmpY = FrY * TGTDistance + CamY;
	tmpZ = FrZ * TGTDistance + CamZ;
	return floatsqroot((tmpX - ObjX) * (tmpX - ObjX) + (tmpY - ObjY) * (tmpY - ObjY) + (tmpZ - ObjZ) * (tmpZ - ObjZ));
}*/

stock PlayerFaces(playerid, Float:x, Float:y, Float:z, Float:radius)
{
        new Float:cx,Float:cy,Float:cz,Float:fx,Float:fy,Float:fz;
        GetPlayerCameraPos(playerid, cx, cy, cz);
        GetPlayerCameraFrontVector(playerid, fx, fy, fz);
        return (radius >= DistanceCameraTargetToLocation(cx, cy, cz, x, y, z, fx, fy, fz));
}

/*public VehicleToPoint(Float:radi, vehicleid, Float:x, Float:y, Float:z)
{
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetVehiclePos(vehicleid, oldposx, oldposy, oldposz);
		tempposx = (oldposx -x);
		tempposy = (oldposy -y);
		tempposz = (oldposz -z);
		//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return 1;
		}
		return 0;
}*/

public HealthDown()
{
	new i,v,p;
	for(i = 0; i<MaxFire; i++)
	{
		if(IsValidFire(i))
		{
			for(p = 0; p<MAX_PLAYERS; p++)
			{
				if(IsPlayerInRangeOfPoint(p, 1, FirePos[i][0], FirePos[i][1], FirePos[i][2]) && !IsPlayerInAnyVehicle(p))
				{
	  				new Float:HP;
		    		GetPlayerHealth(p, HP);
	  				SetPlayerHealth(p, HP-4);
				}	
			}
			for(v = 0; v<MAX_VEHICLES; v++)
			{
				if(VehicleToPoint(2, v, FirePos[i][0], FirePos[i][1], FirePos[i][2]))
				{
					new Float:HP;
		    		GetVehicleHealth(v, HP);
	  				SetVehicleHealth(v, HP-30);
				}
			}
		}
	}
}