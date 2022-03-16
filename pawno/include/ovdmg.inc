/* * * * * * * * * * * * * * * * * * * * * * * *
 *                                   	       *
 *      SA-MP Include Empty Vehicle Damage     *
 *                                   	       *
 *          © Copyright 2014, Petricko         *
 *                                   	       *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include <a_samp>

#pragma tabsize 0

new IspodNules[MAX_VEHICLES];
new ED[MAX_VEHICLES];
//new arr_Engine[MAX_VEHICLES char];

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
	            if(health >= 0 && EVN_VehicleHasDriver(hitid))
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
	       	    	if(health < 250 && ED[hitid] == 0)
	    	    	{
	    	    	    SetTimerEx("EVN_RespawnVehicle", 10000, 0, "i", hitid);
	    	    	    ED[hitid] = 1;
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
					arr_Engine{hitid} = 0;
				}
        }
    }
    #if defined EVN_OnPlayerWeaponShot
       EVN_OnPlayerWeaponShot( playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ );
    #endif
    return 1;
}

#if defined _ALS_OnPlayerWeaponShot
    #undef OnPlayerWeaponShot
#else
    #define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot EVN_OnPlayerWeaponShot
#if defined EVN_OnPlayerWeaponShot
    forward EVN_OnPlayerWeaponShot( playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ );
#endif

public OnVehicleSpawn(vehicleid)
{
	IspodNules[vehicleid] = 0;
	ED[vehicleid] = 0;
	SetVehicleHealth(vehicleid, 1000);
    #if defined EVN_OnVehicleSpawn
       EVN_OnVehicleSpawn(vehicleid);
    #endif
    return 1;
}

#if defined _ALS_OnVehicleSpawn
    #undef OnVehicleSpawn
#else
    #define _ALS_OnVehicleSpawn
#endif
#define OnVehicleSpawn EVN_OnVehicleSpawn
#if defined EVN_OnVehicleSpawn
    forward EVN_OnVehicleSpawn(vehicleid);
#endif

forward EVN_RespawnVehicle(vehicleid);
public EVN_RespawnVehicle(vehicleid)
{
	SetVehicleToRespawn(vehicleid);
	ED[vehicleid] = 0;
	return 1;
}


forward EVN_VehicleHasDriver(vehicleid);
public EVN_VehicleHasDriver(vehicleid)
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
