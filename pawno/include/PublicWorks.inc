// PROJECT LOS ANGELES ROLEPLAY
// (C) 2010 GTAPoliceMods.com 

#include <a_samp>

#define MAX_DIVERTS 80
#define MAX_ROADCLOSED 80

// DIVERT SIGNS

enum dInfo
{
	dCreated,
    Float:dX,
    Float:dY,
    Float:dZ,
    dObject,
};
new DivertInfo[MAX_DIVERTS][dInfo];

stock CreateDivert(Float:x,Float:y,Float:z,Float:Angle)
{
    for(new i = 0; i < sizeof(DivertInfo); i++)
  	{
  	    if(DivertInfo[i][dCreated] == 0)
  	    {
            DivertInfo[i][dCreated]=1;
            DivertInfo[i][dX]=x;
            DivertInfo[i][dY]=y;
            DivertInfo[i][dZ]=z-0.7;
            DivertInfo[i][dObject] = CreateObject(1425, x, y, z-0.9, 0, 0, Angle, 500);
	        return 1;
  	    }
  	}
  	return 0;
}

stock DeleteAllDivert()
{
    for(new i = 0; i < sizeof(DivertInfo); i++)
  	{
  	    if(DivertInfo[i][dCreated] == 1)
  	    {
  	        DivertInfo[i][dCreated]=0;
            DivertInfo[i][dX]=0.0;
            DivertInfo[i][dY]=0.0;
            DivertInfo[i][dZ]=0.0;
            DestroyObject(DivertInfo[i][dObject]);
  	    }
	}
    return 0;
}

stock DeleteClosestDivert(playerid)
{
    for(new i = 0; i < sizeof(DivertInfo); i++)
  	{
  	    if(IsPlayerInRangeOfPoint(playerid, 2.0, DivertInfo[i][dX], DivertInfo[i][dY], DivertInfo[i][dZ]))
        {
  	        if(DivertInfo[i][dCreated] == 1)
            {
                DivertInfo[i][dCreated]=0;
                DivertInfo[i][dX]=0.0;
                DivertInfo[i][dY]=0.0;
                DivertInfo[i][dZ]=0.0;
                DestroyObject(DivertInfo[i][dObject]);
                return 1;
  	        }
  	    }
  	}
    return 0;
}

///////

enum LCInfo
{
	LCCreated,
    Float:LCX,
    Float:LCY,
    Float:LCZ,
    LCObject,
};
new LineClosedInfo[MAX_ROADCLOSED][LCInfo];

stock CreateLineClosed(Float:x,Float:y,Float:z,Float:Angle)
{
    for(new i = 0; i < sizeof(LineClosedInfo); i++)
  	{
  	    if(LineClosedInfo[i][LCCreated] == 0)
  	    {
            LineClosedInfo[i][LCCreated]=1;
            LineClosedInfo[i][LCX]=x;
            LineClosedInfo[i][LCY]=y;
            LineClosedInfo[i][LCZ]=z-0.7;
            LineClosedInfo[i][LCObject] = CreateObject(3091, x, y, z-0.9, 0, 0, Angle, 500);
	        return 1;
  	    }
  	}
  	return 0;
}

stock DeleteAllLineClosed()
{
    for(new i = 0; i < sizeof(LineClosedInfo); i++)
  	{
  	    if(LineClosedInfo[i][LCCreated] == 1)
  	    {
  	        LineClosedInfo[i][LCCreated]=0;
            LineClosedInfo[i][LCX]=0.0;
            LineClosedInfo[i][LCY]=0.0;
            LineClosedInfo[i][LCZ]=0.0;
            DestroyObject(LineClosedInfo[i][LCObject]);
  	    }
	}
    return 0;
}

stock DeleteClosestLineClosed(playerid)
{
    for(new i = 0; i < sizeof(LineClosedInfo); i++)
  	{
  	    if(IsPlayerInRangeOfPoint(playerid, 2.0, LineClosedInfo[i][LCX], LineClosedInfo[i][LCY], LineClosedInfo[i][LCZ]))
        {
  	        if(LineClosedInfo[i][LCCreated] == 1)
            {
                LineClosedInfo[i][LCCreated]=0;
                LineClosedInfo[i][LCX]=0.0;
                LineClosedInfo[i][LCY]=0.0;
                LineClosedInfo[i][LCZ]=0.0;
                DestroyObject(LineClosedInfo[i][LCObject]);
                return 1;
  	        }
  	    }
  	}
    return 0;
}