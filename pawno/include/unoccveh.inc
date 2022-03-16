/* * * * * * * * * * * * * * * * * * * * * * * *
 *                                   	       *
 *      SA-MP Include Empty Vehicle Damage     *
 *                                   	       *
 *          © Copyright 2014, Petricko         *
 *                                   	       *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include <a_samp>

new IspodNule[MAX_VEHICLES];
new EB[MAX_VEHICLES];
new arr_Engine[MAX_VEHICLES char];

public OnPlayerWeaponShot( playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ )
{
	new Float:health;
    switch( hittype )
    {
        case BULLET_HIT_TYPE_VEHICLE:
        {
        	GetVehicleHealth(hitid, health);
			for(new i=0; i<MAX_PLAYERS; i++)
			{
	            if(health >= 0 && !EVD_VehicleHasDriver(hitid))
				{
				    if(weaponid == 22) SetVehicleHealth(hitid, health -25);
				    if(weaponid == 23) SetVehicleHealth(hitid, health -40);
				    if(weaponid == 24) SetVehicleHealth(hitid, health -75);
				    if(weaponid == 25) SetVehicleHealth(hitid, health -150);
				    if(weaponid == 26) SetVehicleHealth(hitid, health -80);
				    if(weaponid == 27) SetVehicleHealth(hitid, health -60);
				    if(weaponid == 28) SetVehicleHealth(hitid, health -20);
				    if(weaponid == 29) SetVehicleHealth(hitid, health -25);
				    if(weaponid == 30) SetVehicleHealth(hitid, health -30);
				    if(weaponid == 31) SetVehicleHealth(hitid, health -35);
				    if(weaponid == 32) SetVehicleHealth(hitid, health -20);
				    if(weaponid == 33) SetVehicleHealth(hitid, health -75);
				    if(weaponid == 34) SetVehicleHealth(hitid, health -125);
				    if(weaponid == 35) SetVehicleHealth(hitid, health -1000);
				    if(weaponid == 36) SetVehicleHealth(hitid, health -1000);
				    if(weaponid == 37) SetVehicleHealth(hitid, health -200);
				    if(weaponid == 38) SetVehicleHealth(hitid, health -100);
	       	    	if(health < 250 && EB[hitid] == 0)
	    	    	{
	    	    	    SetTimerEx("EVD_RespawnVehicle", 10000, 0, "i", hitid);
	    	    	    EB[hitid] = 1;
	    	    	}
	            }
			}
            /*if(health <= 0 && IspodNules[hitid] == 0)
			{
				IspodNules[hitid] = 1;
				GetVehiclePos(hitid, X, Y, Z );
				CreateExplosion(X, Y, Z, 1, 5);
			}*/

			static
				arrVehParams[7];

			if(health < 275.0)
				{
					SetVehicleHealth(hitid, 251.0);
					GetVehicleParamsEx(hitid, arrVehParams[0], arrVehParams[1], arrVehParams[2], arrVehParams[3], arrVehParams[4], arrVehParams[5], arrVehParams[6]);
					if(arrVehParams[0] == VEHICLE_PARAMS_ON) SetVehicleParamsEx(hitid,VEHICLE_PARAMS_OFF, arrVehParams[1], arrVehParams[2], arrVehParams[3], arrVehParams[4], arrVehParams[5], arrVehParams[6]);
					GameTextForPlayer(playerid, "~r~Totalled!", 2500, 3);
					arr_Engine{hitid} = 0;
				}
        }
    }
    #if defined EVD_OnPlayerWeaponShot
       EVD_OnPlayerWeaponShot( playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ );
    #endif
    return 1;
}

#if defined _ALS_OnPlayerWeaponShot
    #undef OnPlayerWeaponShot
#else
    #define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot EVD_OnPlayerWeaponShot
#if defined EVD_OnPlayerWeaponShot
    forward EVD_OnPlayerWeaponShot( playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ );
#endif

public OnVehicleSpawn(vehicleid)
{
	IspodNule[vehicleid] = 0;
	EB[vehicleid] = 0;
	SetVehicleHealth(vehicleid, 1000);
    #if defined EVD_OnVehicleSpawn
       EVD_OnVehicleSpawn(vehicleid);
    #endif
    return 1;
}

#if defined _ALS_OnVehicleSpawn
    #undef OnVehicleSpawn
#else
    #define _ALS_OnVehicleSpawn
#endif
#define OnVehicleSpawn EVD_OnVehicleSpawn
#if defined EVD_OnVehicleSpawn
    forward EVD_OnVehicleSpawn(vehicleid);
#endif

forward EVD_RespawnVehicle(vehicleid);
public EVD_RespawnVehicle(vehicleid)
{
	SetVehicleToRespawn(vehicleid);
	EB[vehicleid] = 0;
	return 1;
}


forward EVD_VehicleHasDriver(vehicleid);
public EVD_VehicleHasDriver(vehicleid)
{
     for(new i=0;i<=MAX_PLAYERS;i++)
     {
           if(IsPlayerInAnyVehicle(i))
           {
                if(GetPlayerVehicleID(i)==vehicleid)
                {
                       if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
                       {
                             return 1;
                        }
                 }
           }
     }
     return 0;
}
