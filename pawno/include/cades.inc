// Include created by McGuiness

// Stocks:
// stock CreateBarrier(Float:x, Float:y, Float:z, Float:Angel)
// stock DeleteAllBarrier()
// stock DeleteClosestBarrier(playerid)
// stock CreateCone(Float:x, Float:y, Float:z, Float:Angel)
// stock DeleteAllCone()
// stock DeleteClosestCone(playerid)

#include <a_samp>

#define MAX_CONES			200
#define MAX_BARRIERS		200
#define MAX_SPIKESTRIPS		200

enum cone
{
	cCreated,
	Float:cX,
	Float:cY,
	Float:cZ,
	cObject
};
new ConeInfo[MAX_CONES][cone];

enum barrier
{
	bCreated,
	Float:bX,
	Float:bY,
	Float:bZ,
	bObject
};
new BarrierInfo[MAX_BARRIERS][barrier];

enum spike
{
	sCreated,
    Float:sX,
    Float:sY,
    Float:sZ,
    sObject,
};
new SpikeInfo[MAX_SPIKESTRIPS][spike];

stock CreateBarrier(Float:x, Float:y, Float:z, Float:Angle)
{
	for(new i = 0; i < sizeof(BarrierInfo); i++)
	{
		if(BarrierInfo[i][bCreated] == 0)
		{
			BarrierInfo[i][bCreated] = 1;
			BarrierInfo[i][bX] = x;
			BarrierInfo[i][bY] = y;
			BarrierInfo[i][bZ] = z-0.7;
			BarrierInfo[i][bObject] = CreateObject(1459, x, y, z-0.9, 0, 0, Angle-90);
		}
	}
	return 0;
}

stock DeleteAllBarrier()
{
	for(new i = 0; i < sizeof(BarrierInfo); i++)
	{
		if(BarrierInfo[i][bCreated] == 1)
		{
			BarrierInfo[i][bCreated] = 0;
			BarrierInfo[i][bX] = 0.0;
			BarrierInfo[i][bY] = 0.0;
			BarrierInfo[i][bZ] = 0.0;
			DestroyObject(BarrierInfo[i][bObject]);
		}
	}
	return 0;
}

stock DeleteClosestBarrier(playerid)
{
	for(new i = 0; i < sizeof(BarrierInfo); i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, BarrierInfo[i][bX], BarrierInfo[i][bY], BarrierInfo[i][bZ]))
        {
			if(BarrierInfo[i][bCreated] == 1)
			{
				BarrierInfo[i][bCreated] = 0;
				BarrierInfo[i][bX] = 0.0;
				BarrierInfo[i][bY] = 0.0;
				BarrierInfo[i][bZ] = 0.0;
				DestroyObject(BarrierInfo[i][bObject]);
			}
		}
	}
	return 0;
}

stock CreateCone(Float:x, Float:y, Float:z, Float:Angle)
{
	for(new i = 0; i < sizeof(ConeInfo); i++)
	{
		if(ConeInfo[i][cCreated] == 0)
		{
			ConeInfo[i][cCreated] = 1;
			ConeInfo[i][cX] = x;
			ConeInfo[i][cY] = y;
			ConeInfo[i][cZ] = z-0.7;
			ConeInfo[i][cObject] = CreateObject(1238, x, y, z-0.9, 0, 0, Angle-90);
		}
	}
	return 0;
}

stock DeleteAllCone()
{
	for(new i = 0; i < sizeof(ConeInfo); i++)
	{
		if(ConeInfo[i][cCreated] == 1)
		{
			ConeInfo[i][cCreated] = 0;
			ConeInfo[i][cX] = 0.0;
			ConeInfo[i][cY] = 0.0;
			ConeInfo[i][cZ] = 0.0;
			DestroyObject(ConeInfo[i][cObject]);
		}
	}
	return 0;
}

stock DeleteClosestCone(playerid)
{
	for(new i = 0; i < sizeof(ConeInfo); i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, ConeInfo[i][cX], ConeInfo[i][cY], ConeInfo[i][cZ]))
        {
			if(ConeInfo[i][cCreated] == 1)
			{
				ConeInfo[i][cCreated] = 0;
				ConeInfo[i][cX] = 0.0;
				ConeInfo[i][cY] = 0.0;
				ConeInfo[i][cZ] = 0.0;
				DestroyObject(ConeInfo[i][cObject]);
			}
		}
	}
	return 0;
}

stock CreateStrip(Float:x,Float:y,Float:z,Float:Angle)
{
    for(new i = 0; i < sizeof(SpikeInfo); i++)
  	{
  	    if(SpikeInfo[i][sCreated] == 0)
  	    {
            SpikeInfo[i][sCreated]= 1;
            SpikeInfo[i][sX]= x;
            SpikeInfo[i][sY]= y;
            SpikeInfo[i][sZ]= z-0.7;
            SpikeInfo[i][sObject] = CreateObject(2899, x, y, z-0.9, 0, 0, Angle-90);
	        return 1;
  	    }
  	}
  	return 0;
}

stock DeleteAllStrip()
{
    for(new i = 0; i < sizeof(SpikeInfo); i++)
  	{
  	    if(SpikeInfo[i][sCreated] == 1)
  	    {
  	        SpikeInfo[i][sCreated]= 0;
            SpikeInfo[i][sX]= 0.0;
            SpikeInfo[i][sY]= 0.0;
            SpikeInfo[i][sZ]= 0.0;
            DestroyObject(SpikeInfo[i][sObject]);
  	    }
	}
    return 0;
}

stock DeleteClosestStrip(playerid)
{
    for(new i = 0; i < sizeof(SpikeInfo); i++)
  	{
  	    if(IsPlayerInRangeOfPoint(playerid, 2.0, SpikeInfo[i][sX], SpikeInfo[i][sY], SpikeInfo[i][sZ]))
        {
  	        if(SpikeInfo[i][sCreated] == 1)
            {
                SpikeInfo[i][sCreated]= 0;
                SpikeInfo[i][sX]= 0.0;
                SpikeInfo[i][sY]= 0.0;
                SpikeInfo[i][sZ]= 0.0;
                DestroyObject(SpikeInfo[i][sObject]);
                return 1;
  	        }
  	    }
  	}
    return 0;
}

public OnPlayerUpdate(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;

    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        for(new i = 0; i < sizeof(SpikeInfo); i++)
  	    {
  	        if(IsPlayerInRangeOfPoint(playerid, 3.0, SpikeInfo[i][sX], SpikeInfo[i][sY], SpikeInfo[i][sZ]))
            {
  	            if(SpikeInfo[i][sCreated] == 1)
  	            {
  	                new panels, doors, lights, tires;
  	                new carid = GetPlayerVehicleID(playerid);
		            GetVehicleDamageStatus(carid, panels, doors, lights, tires);
		            tires = encode_tires(1, 1, 1, 1);
		            UpdateVehicleDamageStatus(carid, panels, doors, lights, tires);
  	                return 0;
  	            }
  	        }
  	    }
  	}

	return 1;
}

encode_tires(tires1, tires2, tires3, tires4) {

	return tires1 | (tires2 << 1) | (tires3 << 2) | (tires4 << 3);

}