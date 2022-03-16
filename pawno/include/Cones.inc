// FORT CARSON ROLEPLAY
// SV R1.600b+
// (C) 2010 GTAPoliceMods.com 

#include <a_samp>

#define MAX_CONES 80

enum cInfo
{
	cCreated,
    Float:sX,
    Float:sY,
    Float:sZ,
    sObject,
};
new ConeInfo[MAX_CONES][cInfo];

stock CreateCone(Float:x,Float:y,Float:z,Float:Angle)
{
    for(new i = 0; i < sizeof(ConeInfo); i++)
  	{
  	    if(ConeInfo[i][cCreated] == 0)
  	    {
            ConeInfo[i][cCreated]=1;
            ConeInfo[i][sX]=x;
            ConeInfo[i][sY]=y;
            ConeInfo[i][sZ]=z-0.7;
            ConeInfo[i][sObject] = CreateObject(1238, x, y, z-0.9, 0, 0, Angle-90, 500);
	        return 1;
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
  	        ConeInfo[i][cCreated]=0;
            ConeInfo[i][sX]=0.0;
            ConeInfo[i][sY]=0.0;
            ConeInfo[i][sZ]=0.0;
            DestroyObject(ConeInfo[i][sObject]);
  	    }
	}
    return 0;
}

stock DeleteClosestCone(playerid)
{
    for(new i = 0; i < sizeof(ConeInfo); i++)
  	{
  	    if(IsPlayerInRangeOfPoint(playerid, 2.0, ConeInfo[i][sX], ConeInfo[i][sY], ConeInfo[i][sZ]))
        {
  	        if(ConeInfo[i][cCreated] == 1)
            {
                ConeInfo[i][cCreated]=0;
                ConeInfo[i][sX]=0.0;
                ConeInfo[i][sY]=0.0;
                ConeInfo[i][sZ]=0.0;
                DestroyObject(ConeInfo[i][sObject]);
                return 1;
  	        }
  	    }
  	}
    return 0;
}