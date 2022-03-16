/*
        *****************
        Advanced Gang Zones v2.2.1
        by beijind.
        *****************
*/

#include <a_samp>

#define NUMDIS 25.0
#define LETTER_STROKE 3.5 
#define LETTER_XSQUASH 0.7
#define BORDER_SIZE 1.5
#define ZCOLOR_NUMBER 0x050505AA
#define ZCOLOR_BORDER 0x050505AA


enum zoneInfo
{
	bool:zExists,             // Is used to check wether a gang zone exists or not.
	bool:zIsUsingNumbers,     // Is used to check wether a gang zone is with numbers or not.
	bool:zIsUsingBorders,     // Is used to check wether a gang zone is with borders or not.
	Float:zPosCords[4],       // Holds gang zone coordinates.
	zMainID,                  // Holds the main gang zone ID.
	npart[5],                 // Holds gang zones IDs which were used to create the first number.
	npart2[5],                // Holds gang zones IDs which were used to create the second number.
	border[4]                 // Holds gang zones IDs which were used to create borders.
}
new zGangZones[1024][zoneInfo];
new zGangZonesCreated;

// Reset all variables.
public OnGameModeInit()
{
    zGangZonesCreated = 0;
    for(new z=0; z<sizeof(zGangZones); z++)
	{
	   zGangZones[z][zExists] = false;
	   zGangZones[z][zIsUsingNumbers] = false;
	   zGangZones[z][zIsUsingBorders] = false;
	   for(new nump=0;nump<5;nump++)
	   {
	     zGangZones[z][npart][nump] = -1;
	     zGangZones[z][npart2][nump] = -1;
	   }
	}
    return CallLocalFunction("Hook_OnGameModeInit", "");
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Hook_OnGameModeInit

forward OnGameModeInit();

// Shows a gang zone for all.
stock ShowZoneForAll(zoneid,color,ncolor = ZCOLOR_NUMBER,bcolor = ZCOLOR_BORDER)
{
	if(!zGangZones[zoneid][zExists])return 0;

	//
	GangZoneShowForAll(zGangZones[zoneid][zMainID],color);

	//
	if(zGangZones[zoneid][zIsUsingNumbers])
	{
       for(new nump; nump<5; nump++)
	   {
	      if(zGangZones[zoneid][npart][nump] != -1)
		  {
		     GangZoneShowForAll(zGangZones[zoneid][npart][nump],ncolor);
		  }
		  if(zGangZones[zoneid][npart2][nump] != -1)
		  {
		     GangZoneShowForAll(zGangZones[zoneid][npart2][nump],ncolor);
		  }
	   }
	}

	//
	if(zGangZones[zoneid][zIsUsingBorders])
	{
       GangZoneShowForAll(zGangZones[zoneid][border][0],bcolor);
	   GangZoneShowForAll(zGangZones[zoneid][border][1],bcolor);
       GangZoneShowForAll(zGangZones[zoneid][border][2],bcolor);
	   GangZoneShowForAll(zGangZones[zoneid][border][3],bcolor);
    }
    return 1;
}

// Shows a gang zone for a single player.
stock ShowZoneForPlayer(playerid,zoneid,color,ncolor = ZCOLOR_NUMBER,bcolor = ZCOLOR_BORDER)
{
	if(!zGangZones[zoneid][zExists])return 0;
		
	//
	GangZoneShowForPlayer(playerid,zGangZones[zoneid][zMainID],color);

	//
	if(zGangZones[zoneid][zIsUsingNumbers])
	{
       for(new nump; nump<5; nump++)
	   {
	      if(zGangZones[zoneid][npart][nump] != -1)
		  {
		     GangZoneShowForPlayer(playerid,zGangZones[zoneid][npart][nump],ncolor);
		  }
		  if(zGangZones[zoneid][npart2][nump] != -1)
		  {
		     GangZoneShowForPlayer(playerid,zGangZones[zoneid][npart2][nump],ncolor);
		  }
	   }
	}

	//
	if(zGangZones[zoneid][zIsUsingBorders])
	{
       GangZoneShowForPlayer(playerid,zGangZones[zoneid][border][0],bcolor);
	   GangZoneShowForPlayer(playerid,zGangZones[zoneid][border][1],bcolor);
       GangZoneShowForPlayer(playerid,zGangZones[zoneid][border][2],bcolor);
	   GangZoneShowForPlayer(playerid,zGangZones[zoneid][border][3],bcolor);
    }
    return 1;
}

// Hides a gang zone for all.
stock HideZoneForAll(zoneid)
{
	if(!zGangZones[zoneid][zExists])return 0;

	//
	GangZoneHideForAll(zGangZones[zoneid][zMainID]);

	//
	if(zGangZones[zoneid][zIsUsingNumbers])
	{
       for(new nump; nump<5; nump++)
	   {
	      if(zGangZones[zoneid][npart][nump] != -1)
		  {
		     GangZoneHideForAll(zGangZones[zoneid][npart][nump]);
		  }
		  if(zGangZones[zoneid][npart2][nump] != -1)
		  {
		     GangZoneHideForAll(zGangZones[zoneid][npart2][nump]);
		  }
	   }
	}

	//
	if(zGangZones[zoneid][zIsUsingBorders])
	{
       GangZoneHideForAll(zGangZones[zoneid][border][0]);
	   GangZoneHideForAll(zGangZones[zoneid][border][1]);
       GangZoneHideForAll(zGangZones[zoneid][border][2]);
	   GangZoneHideForAll(zGangZones[zoneid][border][3]);
    }
    return 1;
}

// Hides a gang zone for a single player.
stock HideZoneForPlayer(playerid,zoneid)
{
	if(!zGangZones[zoneid][zExists])return 0;
		
	//
	GangZoneHideForPlayer(playerid,zGangZones[zoneid][zMainID]);

	//
	if(zGangZones[zoneid][zIsUsingNumbers])
	{
       for(new nump; nump<5; nump++)
	   {
	      if(zGangZones[zoneid][npart][nump] != -1)
		  {
		     GangZoneHideForPlayer(playerid,zGangZones[zoneid][npart][nump]);
		  }
		  if(zGangZones[zoneid][npart2][nump] != -1)
		  {
		     GangZoneHideForPlayer(playerid,zGangZones[zoneid][npart2][nump]);
		  }
	   }
	}

	//
	if(zGangZones[zoneid][zIsUsingBorders])
	{
       GangZoneHideForPlayer(playerid,zGangZones[zoneid][border][0]);
	   GangZoneHideForPlayer(playerid,zGangZones[zoneid][border][1]);
       GangZoneHideForPlayer(playerid,zGangZones[zoneid][border][2]);
	   GangZoneHideForPlayer(playerid,zGangZones[zoneid][border][3]);
    }
    return 1;
}

// Creates a gang zone.
stock CreateZone(Float:gzMinX, Float:gzMinY, Float:gzMaxX, Float:gzMaxY)
{
    new gid = GangZoneCreate(gzMinX,gzMinY,gzMaxX,gzMaxY);
    zGangZones[zGangZonesCreated][zExists] = true;
    zGangZones[zGangZonesCreated][zMainID] = gid;
    zGangZones[zGangZonesCreated][zPosCords][0] = gzMinX;
    zGangZones[zGangZonesCreated][zPosCords][1] = gzMinY;
    zGangZones[zGangZonesCreated][zPosCords][2] = gzMaxX;
    zGangZones[zGangZonesCreated][zPosCords][3] = gzMaxY;
    zGangZonesCreated += 1;
	return (zGangZonesCreated-1);
}

// Destroys a gang zone.
stock DestroyZone(zoneid)
{
    if(!zGangZones[zoneid][zExists])return 0;
    
    //
    GangZoneDestroy(zGangZones[zoneid][zMainID]);
    
    //
    if(zGangZones[zoneid][zIsUsingNumbers])
    {
       for(new numpart;numpart < 5;numpart++)
	   {
		  if(zGangZones[zoneid][npart][numpart] != -1)
		  {
	         GangZoneDestroy(zGangZones[zoneid][npart][numpart]);
	         zGangZones[zoneid][npart][numpart] = -1;
		  }
		  
		  if(zGangZones[zoneid][npart2][numpart] != -1)
		  {
	         GangZoneDestroy(zGangZones[zoneid][npart2][numpart]);
	         zGangZones[zoneid][npart2][numpart] = -1;
		  }
	   }
	   zGangZones[zoneid][zIsUsingNumbers] = false;
    }

	//
    if(zGangZones[zoneid][zIsUsingBorders])
    {
       for(new bord;bord < 4;bord++)GangZoneDestroy(zGangZones[zoneid][border][bord]);
       zGangZones[zoneid][zIsUsingBorders] = false;
    }
    
    zGangZones[zoneid][zExists] = false;
    zGangZonesCreated -= 1;
	return 1;
}

// Creates a number.
stock CreateZoneNumber(zoneid,gznumber,Float:numsize = 0.7)
{
	if(!zGangZones[zoneid][zExists])return 0;
	if(zGangZones[zoneid][zIsUsingNumbers])return 0;
	if(numsize <= 0.0)return 0;
	
	//
	new Float:centposx,Float:centposy;
	centposx = (zGangZones[zoneid][zPosCords][0]+zGangZones[zoneid][zPosCords][2]) / 2;
	centposy = (zGangZones[zoneid][zPosCords][1]+zGangZones[zoneid][zPosCords][3]) / 2;
	
	//
	if(gznumber >= 0 && gznumber <= 9)
	{
       agz_GangZoneCreateFirstNumber(zoneid,gznumber,centposx,centposy,numsize);
       zGangZones[zoneid][zIsUsingNumbers] = true;
       return 1;
	}
	else if(gznumber > 9 && gznumber <= 99)
	{
	   new temp[3],gznum1[2],gznum2[2];
	   format(temp,sizeof temp,"%d",gznumber);
	   strmid(gznum1,temp,0,1);
	   strmid(gznum2,temp,1,2);

	   agz_GangZoneCreateFirstNumber(zoneid,strval(gznum1),centposx-(NUMDIS*numsize),centposy,numsize);
	   agz_GangZoneCreateSecondNumber(zoneid,strval(gznum2),centposx+(NUMDIS*numsize),centposy,numsize);
	   zGangZones[zoneid][zIsUsingNumbers] = true;
	   return 1;
	}
	else return 0;
}

// Destroys a number.
stock DestroyZoneNumber(zoneid)
{
	if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingNumbers])return 0;
	
    for(new numpart;numpart < 5;numpart++)
	{
	   if(zGangZones[zoneid][npart][numpart] != -1)
	   {
	      GangZoneDestroy(zGangZones[zoneid][npart][numpart]);
	      zGangZones[zoneid][npart][numpart] = -1;
	   }

	   if(zGangZones[zoneid][npart2][numpart] != -1)
	   {
	      GangZoneDestroy(zGangZones[zoneid][npart2][numpart]);
	      zGangZones[zoneid][npart2][numpart] = -1;
	   }
	}
	
	zGangZones[zoneid][zIsUsingNumbers] = false;
	return 1;
}


// Creates borders.
stock CreateZoneBorders(zoneid)
{
	if(!zGangZones[zoneid][zExists])return 0;
	if(zGangZones[zoneid][zIsUsingBorders])return 0;

	//
    new Float:gzMinX = zGangZones[zoneid][zPosCords][0];
    new Float:gzMinY = zGangZones[zoneid][zPosCords][1];
    new Float:gzMaxX = zGangZones[zoneid][zPosCords][2];
    new Float:gzMaxY = zGangZones[zoneid][zPosCords][3];

	//
	zGangZones[zoneid][border][0] = GangZoneCreate(gzMinX-BORDER_SIZE, gzMinY+BORDER_SIZE, gzMinX+BORDER_SIZE, gzMaxY-BORDER_SIZE); // Left
	zGangZones[zoneid][border][1] = GangZoneCreate(gzMinX-BORDER_SIZE, gzMaxY-BORDER_SIZE, gzMaxX+BORDER_SIZE, gzMaxY+BORDER_SIZE); // Bottom
	zGangZones[zoneid][border][2] = GangZoneCreate(gzMaxX-BORDER_SIZE, gzMinY+BORDER_SIZE, gzMaxX+BORDER_SIZE, gzMaxY-BORDER_SIZE); // Right
	zGangZones[zoneid][border][3] = GangZoneCreate(gzMinX-BORDER_SIZE, gzMinY-BORDER_SIZE, gzMaxX+BORDER_SIZE, gzMinY+BORDER_SIZE); // Top

    zGangZones[zoneid][zIsUsingBorders] = true;
	return 1;
}

// Destroys borders.
stock DestroyZoneBorders(zoneid)
{
	if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingBorders])return 0;

    for(new bord;bord < 4;bord++)
	   GangZoneDestroy(zGangZones[zoneid][border][bord]);

	zGangZones[zoneid][zIsUsingBorders] = false;
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Make a gang zone flash for player.
stock ZoneFlashForPlayer(playerid,zoneid,color)
{
    if(!zGangZones[zoneid][zExists])return 0;
	
	GangZoneFlashForPlayer(playerid,zGangZones[zoneid][zMainID],color);
    return 1;
}

// Make a gang zone stop flash for player.
stock ZoneStopFlashForPlayer(playerid,zoneid)
{
    if(!zGangZones[zoneid][zExists])return 0;
	
	GangZoneStopFlashForPlayer(playerid,zGangZones[zoneid][zMainID]);
    return 1;
}

// Make a gang zone flash for all.
stock ZoneFlashForAll(zoneid,color)
{
    if(!zGangZones[zoneid][zExists])return 0;
	
	GangZoneFlashForAll(zGangZones[zoneid][zMainID],color);
    return 1;
}

// Make a gang zone stop flash for all.
stock ZoneStopFlashForAll(zoneid)
{
    if(!zGangZones[zoneid][zExists])return 0;
	
	GangZoneStopFlashForAll(zGangZones[zoneid][zMainID]);
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Make borders flash for player.
stock ZoneBordersFlashForPlayer(playerid,zoneid,color)
{
    if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingBorders])return 0;
	
	GangZoneFlashForPlayer(playerid,zGangZones[zoneid][border][0],color);
	GangZoneFlashForPlayer(playerid,zGangZones[zoneid][border][1],color);
    GangZoneFlashForPlayer(playerid,zGangZones[zoneid][border][2],color);
	GangZoneFlashForPlayer(playerid,zGangZones[zoneid][border][3],color);
    return 1;
}

// Make borders flash for player.
stock ZoneBordersStopFlashForPlayer(playerid,zoneid)
{
    if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingBorders])return 0;
	
	GangZoneStopFlashForPlayer(playerid,zGangZones[zoneid][border][0]);
	GangZoneStopFlashForPlayer(playerid,zGangZones[zoneid][border][1]);
    GangZoneStopFlashForPlayer(playerid,zGangZones[zoneid][border][2]);
	GangZoneStopFlashForPlayer(playerid,zGangZones[zoneid][border][3]);
    return 1;
}

// Make borders flash for all.
stock ZoneBordersFlashForAll(zoneid,color)
{
    if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingBorders])return 0;
	
	GangZoneFlashForAll(zGangZones[zoneid][border][0],color);
	GangZoneFlashForAll(zGangZones[zoneid][border][1],color);
    GangZoneFlashForAll(zGangZones[zoneid][border][2],color);
	GangZoneFlashForAll(zGangZones[zoneid][border][3],color);
    return 1;
}

// Make borders stop flash for all.
stock ZoneBordersStopFlashForAll(zoneid)
{
    if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingBorders])return 0;
	
	GangZoneStopFlashForAll(zGangZones[zoneid][border][0]);
	GangZoneStopFlashForAll(zGangZones[zoneid][border][1]);
    GangZoneStopFlashForAll(zGangZones[zoneid][border][2]);
	GangZoneStopFlashForAll(zGangZones[zoneid][border][3]);
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Make a number flash for player.
stock ZoneNumberFlashForPlayer(playerid,zoneid,color)
{
    if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingNumbers])return 0;
	
	for(new nump; nump<5; nump++)
	{
	      if(zGangZones[zoneid][npart][nump] != -1)
		  {
		     GangZoneFlashForPlayer(playerid,zGangZones[zoneid][npart][nump],color);
		  }
		  if(zGangZones[zoneid][npart2][nump] != -1)
		  {
		     GangZoneFlashForPlayer(playerid,zGangZones[zoneid][npart2][nump],color);
		  }
	}
    return 1;
}

// Make a number flash for player.
stock ZoneNumberStopFlashForPlayer(playerid,zoneid)
{
    if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingNumbers])return 0;
	
	for(new nump; nump<5; nump++)
	{
	      if(zGangZones[zoneid][npart][nump] != -1)
		  {
		     GangZoneStopFlashForPlayer(playerid,zGangZones[zoneid][npart][nump]);
		  }
		  if(zGangZones[zoneid][npart2][nump] != -1)
		  {
		     GangZoneStopFlashForPlayer(playerid,zGangZones[zoneid][npart2][nump]);
		  }
	}
    return 1;
}

// Make a number flash for all.
stock ZoneNumberFlashForAll(zoneid,color)
{
    if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingNumbers])return 0;
	
	for(new nump; nump<5; nump++)
	{
	      if(zGangZones[zoneid][npart][nump] != -1)
		  {
		     GangZoneFlashForAll(zGangZones[zoneid][npart][nump],color);
		  }
		  if(zGangZones[zoneid][npart2][nump] != -1)
		  {
		     GangZoneFlashForAll(zGangZones[zoneid][npart2][nump],color);
		  }
	}
    return 1;
}

// Make a number stop flash for all.
stock ZoneNumberStopFlashForAll(zoneid)
{
    if(!zGangZones[zoneid][zExists])return 0;
	if(!zGangZones[zoneid][zIsUsingNumbers])return 0;
	
	for(new nump; nump<5; nump++)
	{
	      if(zGangZones[zoneid][npart][nump] != -1)
		  {
		     GangZoneStopFlashForAll(zGangZones[zoneid][npart][nump]);
		  }
		  if(zGangZones[zoneid][npart2][nump] != -1)
		  {
		     GangZoneStopFlashForAll(zGangZones[zoneid][npart2][nump]);
		  }
	}
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Creates the first number.
stock agz_GangZoneCreateFirstNumber(gzid,gznum,Float:centposx,Float:centposy,Float:numsize)
{
	// Welcome to the ugly part.
	switch(gznum)
	{
	  case 0:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisx = 20.0*numsize*LETTER_XSQUASH;
		new Float:gsdisy = 20.0*numsize;
        zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gsdisy-gztk,centposx+gsdisx+gztk,centposy-gsdisy+gztk); // Down of 0
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gsdisy+gztk,centposx+gsdisx+gztk,centposy+gsdisy-gztk); // Up of 0
        zGangZones[gzid][npart][2] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gsdisy+gztk,centposx-gsdisx+gztk,centposy+gsdisy-gztk); // Left of 0
        zGangZones[gzid][npart][3] = GangZoneCreate(centposx+gsdisx-gztk,centposy-gsdisy+gztk,centposx+gsdisx+gztk,centposy+gsdisy-gztk); // Right of 0
	  }
	  case 1:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gztk,centposy-gsdisy-gztk,centposx+gztk,centposy+gsdisy+gztk);
	  }
	  case 2:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gsdisx,centposy+gsdisy-gztk,centposx+gsdisx,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx+gsdisx-gztk-gztk,centposy+gztk,centposx+gsdisx,centposy+gsdisy-gztk); // Right Stick
		zGangZones[gzid][npart][2] = GangZoneCreate(centposx-gsdisx,centposy-gztk,centposx+gsdisx,centposy+gztk); // Middle
		zGangZones[gzid][npart][3] = GangZoneCreate(centposx-gsdisx,centposy-gsdisy+gztk,centposx-gsdisx+gztk+gztk,centposy-gztk); // Left Stick
        zGangZones[gzid][npart][4] = GangZoneCreate(centposx-gsdisx,centposy-gsdisy-gztk,centposx+gsdisx,centposy-gsdisy+gztk); // Down
	  }
	  case 3:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gsdisx,centposy+gsdisy-gztk,centposx+gsdisx,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx+gsdisx,centposy-gsdisy-gztk,centposx+gsdisx+gztk+gztk,centposy+gsdisy+gztk); // Stick
		zGangZones[gzid][npart][2] = GangZoneCreate(centposx-gsdisx,centposy-gztk,centposx+gsdisx,centposy+gztk); // Middle
		zGangZones[gzid][npart][3] = GangZoneCreate(centposx-gsdisx,centposy-gsdisy-gztk,centposx+gsdisx,centposy-gsdisy+gztk); // Down
	  }
	  case 4:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gsdisx,centposy+gsdisy,centposx-gsdisx+gztk+gztk,centposy+gztk); // Left
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx-gsdisx,centposy-gztk,centposx+gsdisx,centposy+gztk);// Middle
		zGangZones[gzid][npart][2] = GangZoneCreate(centposx+gsdisx,centposy-gsdisy,centposx+gsdisx+gztk+gztk,centposy+gsdisy); // Stick
	  }
	  case 5:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gsdisy-gztk,centposx+gsdisx+gztk,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gztk,centposx-gsdisx+gztk,centposy+gsdisy-gztk); // Left Stick
		zGangZones[gzid][npart][2] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gztk,centposx+gsdisx+gztk,centposy+gztk); // Middle
		zGangZones[gzid][npart][3] = GangZoneCreate(centposx+gsdisx-gztk,centposy-gztk,centposx+gsdisx+gztk,centposy-gsdisy+gztk); // Right Stick
		zGangZones[gzid][npart][4] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gsdisy-gztk,centposx+gsdisx+gztk,centposy-gsdisy+gztk); // Down
	  }
	  case 6:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gsdisx,centposy+gsdisy-gztk,centposx+gsdisx,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx-gsdisx-gztk-gztk,centposy+gsdisy+gztk,centposx-gsdisx,centposy-gsdisy-gztk); // Main Left Stick
		zGangZones[gzid][npart][2] = GangZoneCreate(centposx-gsdisx,centposy-gztk,centposx+gsdisx,centposy+gztk); // Middle
		zGangZones[gzid][npart][3] = GangZoneCreate(centposx-gsdisx,centposy-gsdisy-gztk,centposx+gsdisx,centposy-gsdisy+gztk); // Down
		zGangZones[gzid][npart][4] = GangZoneCreate(centposx+gsdisx-gztk-gztk,centposy-gsdisy+gztk,centposx+gsdisx,centposy-gztk); // Right small stick
	  }
	  case 7:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 15.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx+gsdisx-gztk,centposy-gsdisy-gztk,centposx+gsdisx+gztk,centposy+gsdisy-gztk); // Stick of 7
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx-gsdisx-gsdisx,centposy+gsdisy-gztk,centposx+gsdisx+gztk,centposy+gsdisy+gztk); // Up of 7
	  }
	  case 8:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gsdisy+gztk,centposx-gsdisx+gztk,centposy-gsdisy-gztk); // Left stick
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx+gsdisx-gztk,centposy+gsdisy+gztk,centposx+gsdisx+gztk,centposy-gsdisy-gztk); // Right stick
		zGangZones[gzid][npart][2] = GangZoneCreate(centposx-gsdisx+gztk,centposy+gsdisy-gztk,centposx+gsdisx-gztk,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart][3] = GangZoneCreate(centposx-gsdisx+gztk,centposy-gztk,centposx+gsdisx-gztk,centposy+gztk); // Center
		zGangZones[gzid][npart][4] = GangZoneCreate(centposx-gsdisx+gztk,centposy-gsdisy-gztk,centposx+gsdisx-gztk,centposy-gsdisy+gztk); // Down
	  }
	  case 9:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart][0] = GangZoneCreate(centposx-gsdisx-gztk,centposy,centposx-gsdisx+gztk,centposy+gsdisy-gztk); // Left Stick
		zGangZones[gzid][npart][1] = GangZoneCreate(centposx+gsdisx,centposy-gsdisy-gztk,centposx+gsdisx+gztk+gztk,centposy+gsdisy+gztk); // Right Stick
		zGangZones[gzid][npart][2] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gsdisy-gztk,centposx+gsdisx,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart][3] = GangZoneCreate(centposx-gsdisx+gztk,centposy,centposx+gsdisx,centposy+gztk+gztk); // Middle
		zGangZones[gzid][npart][4] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gsdisy-gztk,centposx+gsdisx,centposy-gsdisy+gztk); // Down
	  }
	}
}

// Creates additional number (if number is greater than 9).
stock agz_GangZoneCreateSecondNumber(gzid,gznum,Float:centposx,Float:centposy,Float:numsize)
{
    // Welcome to the ugly part.
	switch(gznum)
	{
	  case 0:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisx = 20.0*numsize*LETTER_XSQUASH;
		new Float:gsdisy = 20.0*numsize;
        zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gsdisy-gztk,centposx+gsdisx+gztk,centposy-gsdisy+gztk); // Down of 0
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gsdisy+gztk,centposx+gsdisx+gztk,centposy+gsdisy-gztk); // Up of 0
        zGangZones[gzid][npart2][2] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gsdisy+gztk,centposx-gsdisx+gztk,centposy+gsdisy-gztk); // Left of 0
        zGangZones[gzid][npart2][3] = GangZoneCreate(centposx+gsdisx-gztk,centposy-gsdisy+gztk,centposx+gsdisx+gztk,centposy+gsdisy-gztk); // Right of 0
	  }
	  case 1:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gztk,centposy-gsdisy-gztk,centposx+gztk,centposy+gsdisy+gztk);
	  }
	  case 2:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gsdisx,centposy+gsdisy-gztk,centposx+gsdisx,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx+gsdisx-gztk-gztk,centposy+gztk,centposx+gsdisx,centposy+gsdisy-gztk); // Right Stick
		zGangZones[gzid][npart2][2] = GangZoneCreate(centposx-gsdisx,centposy-gztk,centposx+gsdisx,centposy+gztk); // Middle
		zGangZones[gzid][npart2][3] = GangZoneCreate(centposx-gsdisx,centposy-gsdisy+gztk,centposx-gsdisx+gztk+gztk,centposy-gztk); // Left Stick
        zGangZones[gzid][npart2][4] = GangZoneCreate(centposx-gsdisx,centposy-gsdisy-gztk,centposx+gsdisx,centposy-gsdisy+gztk); // Down
	  }
	  case 3:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gsdisx,centposy+gsdisy-gztk,centposx+gsdisx,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx+gsdisx,centposy-gsdisy-gztk,centposx+gsdisx+gztk+gztk,centposy+gsdisy+gztk); // Stick
		zGangZones[gzid][npart2][2] = GangZoneCreate(centposx-gsdisx,centposy-gztk,centposx+gsdisx,centposy+gztk); // Middle
		zGangZones[gzid][npart2][3] = GangZoneCreate(centposx-gsdisx,centposy-gsdisy-gztk,centposx+gsdisx,centposy-gsdisy+gztk); // Down
	  }
	  case 4:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gsdisx,centposy+gsdisy,centposx-gsdisx+gztk+gztk,centposy+gztk); // Left
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx-gsdisx,centposy-gztk,centposx+gsdisx,centposy+gztk);// Middle
		zGangZones[gzid][npart2][2] = GangZoneCreate(centposx+gsdisx,centposy-gsdisy,centposx+gsdisx+gztk+gztk,centposy+gsdisy); // Stick
	  }
	  case 5:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gsdisy-gztk,centposx+gsdisx+gztk,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gztk,centposx-gsdisx+gztk,centposy+gsdisy-gztk); // Left Stick
		zGangZones[gzid][npart2][2] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gztk,centposx+gsdisx+gztk,centposy+gztk); // Middle
		zGangZones[gzid][npart2][3] = GangZoneCreate(centposx+gsdisx-gztk,centposy-gztk,centposx+gsdisx+gztk,centposy-gsdisy+gztk); // Right Stick
		zGangZones[gzid][npart2][4] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gsdisy-gztk,centposx+gsdisx+gztk,centposy-gsdisy+gztk); // Down
	  }
	  case 6:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gsdisx,centposy+gsdisy-gztk,centposx+gsdisx,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx-gsdisx-gztk-gztk,centposy+gsdisy+gztk,centposx-gsdisx,centposy-gsdisy-gztk); // Main Left Stick
		zGangZones[gzid][npart2][2] = GangZoneCreate(centposx-gsdisx,centposy-gztk,centposx+gsdisx,centposy+gztk); // Middle
		zGangZones[gzid][npart2][3] = GangZoneCreate(centposx-gsdisx,centposy-gsdisy-gztk,centposx+gsdisx,centposy-gsdisy+gztk); // Down
		zGangZones[gzid][npart2][4] = GangZoneCreate(centposx+gsdisx-gztk-gztk,centposy-gsdisy+gztk,centposx+gsdisx,centposy-gztk); // Right small stick
	  }
	  case 7:
	  {
		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 15.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx+gsdisx-gztk,centposy-gsdisy-gztk,centposx+gsdisx+gztk,centposy+gsdisy-gztk); // Stick of 7
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx-gsdisx-gsdisx,centposy+gsdisy-gztk,centposx+gsdisx+gztk,centposy+gsdisy+gztk); // Up of 7
	  }
	  case 8:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gsdisy+gztk,centposx-gsdisx+gztk,centposy-gsdisy-gztk); // Left stick
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx+gsdisx-gztk,centposy+gsdisy+gztk,centposx+gsdisx+gztk,centposy-gsdisy-gztk); // Right stick
		zGangZones[gzid][npart2][2] = GangZoneCreate(centposx-gsdisx+gztk,centposy+gsdisy-gztk,centposx+gsdisx-gztk,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart2][3] = GangZoneCreate(centposx-gsdisx+gztk,centposy-gztk,centposx+gsdisx-gztk,centposy+gztk); // Center
		zGangZones[gzid][npart2][4] = GangZoneCreate(centposx-gsdisx+gztk,centposy-gsdisy-gztk,centposx+gsdisx-gztk,centposy-gsdisy+gztk); // Down
	  }
	  case 9:
	  {
  		new Float:gztk = LETTER_STROKE*numsize;
		new Float:gsdisy = 20.0*numsize;
		new Float:gsdisx = 25.0*numsize*LETTER_XSQUASH;
		zGangZones[gzid][npart2][0] = GangZoneCreate(centposx-gsdisx-gztk,centposy,centposx-gsdisx+gztk,centposy+gsdisy-gztk); // Left Stick
		zGangZones[gzid][npart2][1] = GangZoneCreate(centposx+gsdisx,centposy-gsdisy-gztk,centposx+gsdisx+gztk+gztk,centposy+gsdisy+gztk); // Right Stick
		zGangZones[gzid][npart2][2] = GangZoneCreate(centposx-gsdisx-gztk,centposy+gsdisy-gztk,centposx+gsdisx,centposy+gsdisy+gztk); // Up
		zGangZones[gzid][npart2][3] = GangZoneCreate(centposx-gsdisx+gztk,centposy,centposx+gsdisx,centposy+gztk+gztk); // Middle
		zGangZones[gzid][npart2][4] = GangZoneCreate(centposx-gsdisx-gztk,centposy-gsdisy-gztk,centposx+gsdisx,centposy-gsdisy+gztk); // Down
	  }
	}
}
