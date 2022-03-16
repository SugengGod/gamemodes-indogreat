#include <a_samp>

#define MAX_FLARES 80

enum FlaresInfo
{
	fCreated,
    Float:sX,
    Float:sY,
    Float:sZ,
    sObject,
};
new FlareInfo[MAX_FLARES][FlaresInfo];

stock CreateFlare(Float:x,Float:y,Float:z,Float:Angle)
{
    for(new i = 0; i < sizeof(FlareInfo); i++)
  	{
  	    if(FlareInfo[i][fCreated] == 0)
  	    {
            FlareInfo[i][fCreated]=1;
            FlareInfo[i][sX]=x;
            FlareInfo[i][sY]=y;
            FlareInfo[i][sZ]=z-0.1;
            FlareInfo[i][sObject] = CreateObject(18728, x, y, z-2.0, 0, 0, Angle-90, 500);
	        return 1;
  	    }
  	}
  	return 0;
}

stock DeleteAllFlare()
{
    for(new i = 0; i < sizeof(FlareInfo); i++)
  	{
  	    if(FlareInfo[i][fCreated] == 1)
  	    {
  	        FlareInfo[i][fCreated]=0;
            FlareInfo[i][sX]=0.0;
            FlareInfo[i][sY]=0.0;
            FlareInfo[i][sZ]=0.0;
            DestroyObject(FlareInfo[i][sObject]);
  	    }
	}
    return 0;
}

stock DeleteClosestFlare(playerid)
{
    for(new i = 0; i < sizeof(FlareInfo); i++)
  	{
  	    if(IsPlayerInRangeOfPoint(playerid, 2.0, FlareInfo[i][sX], FlareInfo[i][sY], FlareInfo[i][sZ]))
        {
  	        if(FlareInfo[i][fCreated] == 1)
            {
                FlareInfo[i][fCreated]=0;
                FlareInfo[i][sX]=0.0;
                FlareInfo[i][sY]=0.0;
                FlareInfo[i][sZ]=0.0;
                DestroyObject(FlareInfo[i][sObject]);
                return 1;
  	        }
  	    }
  	}
    return 0;
}