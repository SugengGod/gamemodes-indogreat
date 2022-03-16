/*
	--- Edited by zerruv for Millennial Roleplay
	Extremely simple CBug detector/Anti-CBug
	Version 1.1 (1/23/2014)

	Made by Mauzen (msoll(at)web.de)
	Special thanks to pds2k12
	
	This include allows to unsync extra deagle shots automatically,
	and calls OnPlayerCBug once a cbug was detected.
	
	Use as you like, but dont remove this header.	
*/

#if (!defined VectorSize)
	#error "The Anti-CBug include requires at least SA-MP 0.3z RC3"
#endif


// The minimum intervals between two shots, everything below that
// is treated as CBug
#define CBUG_INTERVAL_DEAGLE	650
#define CBUG_INTERVAL_SHOTGUN	1050
#define CBUG_INTERVAL_COUNTRY	850
#define CBUG_INTERVAL_SNIPER 	850

// Used for getting shot intervals
new lastDShot[MAX_PLAYERS];

// If 1, extra cbug shots are unsynced automatically
new removeCBugs = 1;
// If 1, OnPlayerCBug is called on cbug usages
new alertCBugs = 1;

// Callback forward
forward OnPlayerCBug(playerid, weaponid, interval);


public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{	
	// Avoid driveby false alarms
	if (!IsPlayerInAnyVehicle(playerid) && (removeCBugs || alertCBugs))
	{
		new interval = 0;
		switch (weaponid)
		{
			case 24: interval = CBUG_INTERVAL_DEAGLE;
			case 25: interval = CBUG_INTERVAL_SHOTGUN;
			case 33: interval = CBUG_INTERVAL_COUNTRY;
			case 34: interval = CBUG_INTERVAL_SNIPER;
		}
		
		// Check if used weapon is a CBug-Weapon
		if (interval > 0) {		
			// Check if time difference is positive to avoid GetTickCount-reset false alarms
			if (GetTickCount() - lastDShot[playerid] < interval && GetTickCount() - lastDShot[playerid] >= 0)
			{				
				if (alertCBugs) CallLocalFunction("OnPlayerCBug", "iii", playerid, weaponid, GetTickCount() - lastDShot[playerid]);
				return !removeCBugs;
			}
			lastDShot[playerid] = GetTickCount();
		}
	}
	#if defined ACBUG_OnPlayerWeaponShot
		return ACBUG_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerWeaponShot
	#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot ACBUG_OnPlayerWeaponShot
#if defined ACBUG_OnPlayerWeaponShot
    forward ACBUG_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
#endif