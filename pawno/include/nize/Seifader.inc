/*
							Seifader - Screen Fader by Seif
*/
/*x---------------------------------Important-------------------------------------x*/
//**INCLUDES**//
#include <a_samp>
//**PRAGMAS**//

//**MISC**//

/*x---------------------------------Defining-------------------------------------x*/
//**COLORS*//

	//Some colors I made
/*#define GREEN 			0x21DD00FF
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
#define WHITE 			0xFFFFFFFF*/
//**MISC**//
#define MAX_FADES       100
//**VARIABLES**//
new colorfade[MAX_FADES];
new Text:screenfade[MAX_FADES];
new FadeAvailability[MAX_FADES];
new Text:PlayerColorFade[MAX_PLAYERS][MAX_FADES];
// **FORWARDS** //
forward ScreenFade(playerid, color, speed, maxalpha, fadeid);
forward ScreenFadeColor(playerid, color, speed, maxalpha, fadeid);
forward OnPlayerScreenFade(playerid, color, speed);
forward OnPlayerScreenColorFade(playerid, color, speed);
// **NATIVES** //
/*
	native Seifader_OnInit();
	native RemovePlayerColorFade(playerid);
	native FadePlayerScreen(playerid, color, speed);
	native FadePlayerScreenToColor(playerid, color, speed);
	native GetAlpha(color); // extra function
*/
/*x---------------------------------CallBacks-------------------------------------x*/
Seifader_OnExit()
{
    for(new all = 0; all < MAX_PLAYERS; all++) TextDrawDestroy(screenfade[all]);
}

stock FadePlayerScreen(playerid, color, speed)
{
	new fadeid = FindFadeID();
	new maxalpha = GetAlpha(color);
    screenfade[fadeid] = TextDrawCreate(0.0, 0.0, "_");
	TextDrawFont(screenfade[fadeid], 1);
	TextDrawLetterSize(screenfade[fadeid], 0.0, 50.0);
	TextDrawUseBox(screenfade[fadeid], true);
	TextDrawColor(screenfade[fadeid], 0);
	colorfade[fadeid] = color;
    TextDrawBoxColor(screenfade[fadeid], color);
	TextDrawShowForPlayer(playerid, screenfade[fadeid]);
	FadeAvailability[fadeid] = 1;
	SetTimerEx("ScreenFade", 100, 0, "ddddd", playerid, color, speed, maxalpha, fadeid);
}

stock FadePlayerScreenToColor(playerid, color, speed)
{
	new fadeid = FindFadeID();
	new maxalpha = GetAlpha(color);
    PlayerColorFade[playerid][fadeid] = TextDrawCreate(0.0, 0.0, "_");
	TextDrawFont(PlayerColorFade[playerid][fadeid], 1);
	TextDrawLetterSize(PlayerColorFade[playerid][fadeid], 0.0, 50.0);
	TextDrawUseBox(PlayerColorFade[playerid][fadeid], true);
	TextDrawColor(PlayerColorFade[playerid][fadeid], 0);
	color -= maxalpha;
	colorfade[fadeid] = color;
    TextDrawBoxColor(PlayerColorFade[playerid][fadeid], color);
	TextDrawShowForPlayer(playerid, PlayerColorFade[playerid][fadeid]);
	FadeAvailability[fadeid] = 1;
	SetTimerEx("ScreenFadeColor", 100, 0, "ddddd", playerid, color, speed, maxalpha, fadeid);
}

public ScreenFade(playerid, color, speed, maxalpha, fadeid)
{
	if (color <= (colorfade[fadeid] - maxalpha))
	{
	    TextDrawDestroy(screenfade[fadeid]);
	    OnPlayerScreenFade(playerid, color, speed);
	    FadeAvailability[fadeid] = 0;
	}
	else
	{
		color -= speed;
		if (color <= (colorfade[fadeid] - maxalpha)) color = (colorfade[fadeid] - maxalpha);
		TextDrawBoxColor(screenfade[fadeid], color);
		TextDrawShowForPlayer(playerid, screenfade[fadeid]);
		SetTimerEx("ScreenFade", 100, 0, "ddddd", playerid, color, speed, maxalpha, fadeid);
 	}
}

public ScreenFadeColor(playerid, color, speed, maxalpha, fadeid)
{
	if (color >= (colorfade[fadeid] + maxalpha))
	{
	    FADE_FINISH:
	    OnPlayerScreenColorFade(playerid, color, speed);
	    FadeAvailability[fadeid] = 0;
	}
	else
	{
		color += speed;
		if (color >= (colorfade[fadeid] + maxalpha)) goto FADE_FINISH;
		TextDrawBoxColor(PlayerColorFade[playerid][fadeid], color);
		TextDrawShowForPlayer(playerid, PlayerColorFade[playerid][fadeid]);
		SetTimerEx("ScreenFadeColor", 100, 0, "ddddd", playerid, color, speed, maxalpha, fadeid);
 	}
}

forward RemovePlayerColorFade(playerid);
public  RemovePlayerColorFade(playerid)
{
	for(new i; i < MAX_FADES; i++)
	{
		TextDrawDestroy(PlayerColorFade[playerid][i]);
	}
}

stock FindFadeID()
{
	for(new f = 0; f < MAX_FADES; f++)
	{
	    if (FadeAvailability[f] == 0)
	    {
	        printf("found fade id: %d", f);
	        return f;
	    }
	}
	return -1;
}

stock GetAlpha(color)
{
	return color&0xFF;
}

/*public OnPlayerScreenFade(playerid, color, speed)
{
	return 1;
}

public OnPlayerScreenColorFade(playerid, color, speed)
{
	return 1;
}*/