/*
							seif_cursor by Seif - A SA-MP 0.2.2 cursor
*/
/*x---------------------------------Important-------------------------------------x*/
//**INCLUDES**//
#include <a_samp>
//**PRAGMAS**//

//**MISC**//

/*x---------------------------------Defining-------------------------------------x*/
//**KEYS**//
#define CURSOR_UP       KEY_UP
#define CURSOR_DOWN     KEY_DOWN
#define CURSOR_RIGHT    KEY_RIGHT
#define CURSOR_LEFT     KEY_LEFT
#define CURSOR_BOOST    KEY_SPRINT
#define CURSOR_CLICK    KEY_FIRE
#define CURSOR_TOGGLE   KEY_WALK+KEY_SPRINT // ON FOOT: walk + sprint to be able to toggle on/off cursor usage
#define CURSOR_TOGGLE_V KEY_FIRE+320 // WHEN INSIDE VEHICLES: fire + look behind to be able to toggle on/off cursor usage

#define DEFAULT_SPEED   5
#define DEFAULT_SPEED2  10

#define ENABLE_SPEEDCOMMAND_ADJUST // If uncommented, it will enable players to adjust cursor's speeds with a command

#define MAX_BOXES       50
//**VARIABLES**//
new Text:Cursorpt1[MAX_PLAYERS];
new Text:Cursorpt2[MAX_PLAYERS];
new Text:Cursorpt3[MAX_PLAYERS];
new Text:Cursorpt4[MAX_PLAYERS];
new Text:CursorBox[MAX_BOXES];

new Float:CursorX[MAX_PLAYERS];
new Float:CursorY[MAX_PLAYERS];
new Float:cursorposx[MAX_PLAYERS];
new Float:cursorposy[MAX_PLAYERS];
new Float:BoxX[MAX_BOXES];
new Float:BoxY[MAX_BOXES];
new Float:BoxX2[MAX_BOXES];

new CursorSpeed[MAX_PLAYERS];
new Cursorx2Speed[MAX_PLAYERS];
new cursortime[MAX_PLAYERS];
new bool:CursorMode[MAX_PLAYERS];

new boxes;
// **FORWARDS** //
forward CreateCursor();
forward UpdateCursor(playerid, Float:x, Float:y);
forward GetCursorPos(playerid, &Float:x, &Float:y);
forward IsHoldingKey(playerid);
forward ShowCursorForPlayer(playerid);
forward HideCursorForPlayer(playerid);
forward KillCursor();
forward Cursor_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
forward Cursor_OnPlayerCommandText(playerid, cmdtext[]);
forward Cursor_OnPlayerConnect(playerid);
forward OnPlayerClickCursor(playerid, Float:x, Float:y);
forward CursorActivity(playerid);
forward CursorToPoint(playerid, Float:radius, Float:x, Float:y);
forward CursorClick(playerid);
/*x---------------------------------CallBacks-------------------------------------x*/
public ShowCursorForPlayer(playerid)
{
	TextDrawShowForPlayer(playerid, Cursorpt1[playerid]);
	TextDrawShowForPlayer(playerid, Cursorpt2[playerid]);
	TextDrawShowForPlayer(playerid, Cursorpt3[playerid]);
	TextDrawShowForPlayer(playerid, Cursorpt4[playerid]);
}

public HideCursorForPlayer(playerid)
{
	TextDrawHideForPlayer(playerid, Cursorpt1[playerid]);
	TextDrawHideForPlayer(playerid, Cursorpt2[playerid]);
	TextDrawHideForPlayer(playerid, Cursorpt3[playerid]);
	TextDrawHideForPlayer(playerid, Cursorpt4[playerid]);
}

public Cursor_OnPlayerConnect(playerid)
{
	for(new i = 0; i < MAX_BOXES; i++)
	{
		TextDrawShowForPlayer(playerid, CursorBox[i]);
	}
	HideCursorForPlayer(playerid);
	CursorMode[playerid] = false;
	CursorSpeed[playerid] = DEFAULT_SPEED;
	Cursorx2Speed[playerid] = DEFAULT_SPEED2;
	return 1;
}

public KillCursor()
{
    for(new i = 0; i < GetMaxPlayers(); i++)
	{
		TextDrawDestroy(Cursorpt1[i]);
		TextDrawDestroy(Cursorpt2[i]);
		TextDrawDestroy(Cursorpt3[i]);
		TextDrawDestroy(Cursorpt4[i]);
	}
	/*if (playerid == INVALID_PLAYER_ID)
	{
		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			TextDrawDestroy(Cursorpt1[i]);
			TextDrawDestroy(Cursorpt2[i]);
			TextDrawDestroy(Cursorpt3[i]);
			TextDrawDestroy(Cursorpt4[i]);
		}
	}
	else
	{
	    TextDrawDestroy(Cursorpt1[playerid]);
		TextDrawDestroy(Cursorpt2[playerid]);
		TextDrawDestroy(Cursorpt3[playerid]);
		TextDrawDestroy(Cursorpt4[playerid]);
	}*/
}

public Cursor_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (newkeys == CURSOR_TOGGLE || newkeys == CURSOR_TOGGLE_V)
	{
	    if (CursorMode[playerid] == false)
		{
		    ShowCursorForPlayer(playerid);
			TogglePlayerControllable(playerid, false);
		  	cursortime[playerid] = SetTimerEx("IsHoldingKey",100,1,"d",playerid);
		   	CursorMode[playerid] = true;
		}
		else
		{
		  	HideCursorForPlayer(playerid);
		  	TogglePlayerControllable(playerid, true);
		  	KillTimer(cursortime[playerid]);
		  	CursorMode[playerid] = false;
		}
	}

    if (newkeys == CURSOR_CLICK)
    {
        if (CursorMode[playerid] == true)
        {
	        if (!IsPlayerInAnyVehicle(playerid)) ClearAnimations(playerid);
	        new Float:x,Float:y;
	        GetCursorPos(playerid,x,y);
	        TextDrawColor(Cursorpt1[playerid], 0xE60000FF);
	        TextDrawColor(Cursorpt2[playerid], 0xE60000FF);
	        TextDrawColor(Cursorpt3[playerid], 0xE60000FF);
	        TextDrawColor(Cursorpt4[playerid], 0xE60000FF);
	        ShowCursorForPlayer(playerid);
	        OnPlayerClickCursor(playerid, x, y);

	        SetTimerEx("CursorClick",300,0,"d",playerid);
        }
    }
}

public CreateCursor()
{
	for(new p; p < GetMaxPlayers(); p++)
	{
	    CursorX[p] = 222.000000;
		CursorY[p] = 278.000000;

	    Cursorpt1[p] = TextDrawCreate(222.000000,278.000000,"l");
		Cursorpt2[p] = TextDrawCreate(223.000000,279.000000,\"\");
		Cursorpt3[p] = TextDrawCreate(223.000000,285.000000,"-");
		Cursorpt4[p] = TextDrawCreate(227.000000,290.000000,\"\");
		TextDrawAlignment(Cursorpt1[p],0);
		TextDrawAlignment(Cursorpt2[p],0);
		TextDrawAlignment(Cursorpt3[p],0);
		TextDrawAlignment(Cursorpt4[p],0);
		TextDrawBackgroundColor(Cursorpt1[p],0x000000ff);
		TextDrawBackgroundColor(Cursorpt2[p],0x000000ff);
		TextDrawBackgroundColor(Cursorpt3[p],0x000000ff);
		TextDrawBackgroundColor(Cursorpt4[p],0x000000ff);
		TextDrawFont(Cursorpt1[p],1);
		TextDrawLetterSize(Cursorpt1[p],0.199999,1.600000);
		TextDrawFont(Cursorpt2[p],2);
		TextDrawLetterSize(Cursorpt2[p],0.499998,1.300000);
		TextDrawFont(Cursorpt4[p],2);
		TextDrawLetterSize(Cursorpt4[p],0.199998,0.599999);
		TextDrawColor(Cursorpt1[p],0xffffffff);
		TextDrawColor(Cursorpt2[p],0xffffffff);
		TextDrawFont(Cursorpt3[p],0);
		TextDrawLetterSize(Cursorpt3[p],0.699999,1.100000);
		TextDrawColor(Cursorpt3[p],0xffffffff);
		TextDrawColor(Cursorpt4[p],0xffffffff);
		TextDrawSetOutline(Cursorpt1[p],1);
		TextDrawSetOutline(Cursorpt2[p],1);
		TextDrawSetOutline(Cursorpt3[p],1);
		TextDrawSetOutline(Cursorpt4[p],1);
		TextDrawSetProportional(Cursorpt1[p],1);
		TextDrawSetProportional(Cursorpt2[p],1);
		TextDrawSetProportional(Cursorpt3[p],1);
		TextDrawSetProportional(Cursorpt4[p],1);
		TextDrawSetShadow(Cursorpt1[p],1);
		TextDrawSetShadow(Cursorpt2[p],1);
		TextDrawSetShadow(Cursorpt3[p],1);
		TextDrawSetShadow(Cursorpt4[p],1);

		CursorSpeed[p] = DEFAULT_SPEED;
		Cursorx2Speed[p] = DEFAULT_SPEED2;
		CursorMode[p] = false;
	}
}

public UpdateCursor(playerid, Float:x,Float:y)
{
	new i = playerid;
	TextDrawDestroy(Cursorpt1[i]);
	TextDrawDestroy(Cursorpt2[i]);
	TextDrawDestroy(Cursorpt3[i]);
	TextDrawDestroy(Cursorpt4[i]);

	Cursorpt1[i] = TextDrawCreate(x,y,"l");
	Cursorpt2[i] = TextDrawCreate(x+1,y+1,\"\");
	Cursorpt3[i] = TextDrawCreate(x+1,y+7,"-");
	Cursorpt4[i] = TextDrawCreate(x+5,y+12,\"\");
	TextDrawAlignment(Cursorpt1[i],0);
	TextDrawAlignment(Cursorpt2[i],0);
	TextDrawAlignment(Cursorpt3[i],0);
	TextDrawAlignment(Cursorpt4[i],0);
	TextDrawBackgroundColor(Cursorpt1[i],0x000000ff);
	TextDrawBackgroundColor(Cursorpt2[i],0x000000ff);
	TextDrawBackgroundColor(Cursorpt3[i],0x000000ff);
	TextDrawBackgroundColor(Cursorpt4[i],0x000000ff);
	TextDrawFont(Cursorpt1[i],1);
	TextDrawLetterSize(Cursorpt1[i],0.199999,1.600000);
	TextDrawFont(Cursorpt2[i],2);
	TextDrawLetterSize(Cursorpt2[i],0.499998,1.300000);
	TextDrawFont(Cursorpt3[i],0);
	TextDrawLetterSize(Cursorpt3[i],0.699999,1.100000);
	TextDrawFont(Cursorpt4[i],2);
	TextDrawLetterSize(Cursorpt4[i],0.199998,0.599999);
	TextDrawColor(Cursorpt1[i],0xffffffff);
	TextDrawColor(Cursorpt2[i],0xffffffff);
	TextDrawColor(Cursorpt3[i],0xffffffff);
	TextDrawColor(Cursorpt4[i],0xffffffff);
	TextDrawSetOutline(Cursorpt1[i],1);
	TextDrawSetOutline(Cursorpt2[i],1);
	TextDrawSetOutline(Cursorpt3[i],1);
	TextDrawSetOutline(Cursorpt4[i],1);
	TextDrawSetProportional(Cursorpt1[i],1);
	TextDrawSetProportional(Cursorpt2[i],1);
	TextDrawSetProportional(Cursorpt3[i],1);
	TextDrawSetProportional(Cursorpt4[i],1);
	TextDrawSetShadow(Cursorpt1[i],1);
	TextDrawSetShadow(Cursorpt2[i],1);
	TextDrawSetShadow(Cursorpt3[i],1);
	TextDrawSetShadow(Cursorpt4[i],1);
	ShowCursorForPlayer(playerid);
	CursorX[i] = x;
	CursorY[i] = y;
}

public GetCursorPos(playerid, &Float:x, &Float:y)
{
	x = CursorX[playerid];
	y = CursorY[playerid];
}

public IsHoldingKey(playerid)
{
	new keys, updown, leftright;
	GetPlayerKeys(playerid, keys, updown, leftright);
	
  	if (updown == CURSOR_UP)
	{
 		new Float:x,Float:y;
	   	GetCursorPos(playerid,x,y);
	   	UpdateCursor(playerid, x,y-CursorSpeed[playerid]);
	}
	else if (updown == CURSOR_DOWN)
	{
	    new Float:x,Float:y;
	    GetCursorPos(playerid,x,y);
	    UpdateCursor(playerid, x,y+CursorSpeed[playerid]);
	}
	if (leftright == CURSOR_RIGHT)
	{
	    new Float:x,Float:y;
	    GetCursorPos(playerid,x,y);
	    UpdateCursor(playerid, x+CursorSpeed[playerid],y);
	}
	else if (leftright == CURSOR_LEFT)
	{
	    new Float:x,Float:y;
	    GetCursorPos(playerid,x,y);
	    UpdateCursor(playerid, x-CursorSpeed[playerid],y);
	}
		
	if (updown == CURSOR_UP && keys & CURSOR_BOOST)
	{
	    new Float:x,Float:y;
	    GetCursorPos(playerid,x,y);
	    UpdateCursor(playerid, x,y-Cursorx2Speed[playerid]);
	}
	else if (updown == CURSOR_DOWN && keys & CURSOR_BOOST)
	{
	    new Float:x,Float:y;
	    GetCursorPos(playerid,x,y);
	    UpdateCursor(playerid, x,y+Cursorx2Speed[playerid]);
	}
	if (leftright == CURSOR_RIGHT && keys & CURSOR_BOOST)
	{
	    new Float:x,Float:y;
	    GetCursorPos(playerid,x,y);
	    UpdateCursor(playerid, x+Cursorx2Speed[playerid],y);
	}
	else if (leftright == CURSOR_LEFT && keys & CURSOR_BOOST)
	{
	    new Float:x,Float:y;
	    GetCursorPos(playerid,x,y);
	    UpdateCursor(playerid, x-Cursorx2Speed[playerid],y);
	}
}

public Cursor_OnPlayerCommandText(playerid, cmdtext[])
{
	#if defined ENABLE_SPEEDCOMMAND_ADJUST
	    new entry[20],ccmd[20], idx;
	    ccmd = cursor_strtok(cmdtext,idx);
		if (!strcmp(ccmd, "/cursorspeed", true))
		{
		    entry = cursor_strtok(cmdtext, idx);
		    if (!strlen(entry)) return 1;
      		new speed = strval(entry);
		    CursorSpeed[playerid] = speed;
		    new frm[128];
		    format(frm, sizeof(frm), "Cursor speed set to: %d. (default:%d)", speed, DEFAULT_SPEED);
			SendClientMessage(playerid, 0xF97804FF, frm);
	        return 1;
		}
		if (!strcmp(ccmd, "/cursorspeed2", true))
		{
		    entry = cursor_strtok(cmdtext, idx);
		    if (!strlen(entry)) return 1;
      		new speed = strval(entry);
		    Cursorx2Speed[playerid] = speed;
		    new frm[128];
		    format(frm, sizeof(frm), "Cursor x2 speed set to: %d. (default:%d)", speed, DEFAULT_SPEED2);
			SendClientMessage(playerid, 0xF97804FF, frm);
	        return 1;
		}
	#endif
	return 0;
}

public CursorActivity(playerid)
{
	new Float:x,Float:y;
	GetCursorPos(playerid,x,y);
	if (cursorposx[playerid] == x && cursorposy[playerid] == y)
	{
	    HideCursorForPlayer(playerid);
	    SetTimerEx("CursorActivity",3000,0,"d",playerid);
	}
	else
	{
	    cursorposx[playerid] = x;
	    cursorposy[playerid] = y;
	    ShowCursorForPlayer(playerid);
	    SetTimerEx("CursorActivity",3000,0,"d",playerid);
	}
}

public CursorToPoint(playerid, Float:radius, Float:x, Float:y)
{
    new Float:cx, Float:cy;
	new Float:ox, Float:oy;
 	GetCursorPos(playerid, ox, oy);
  	cx = (ox -x);
	cy = (oy -y);
	if (((cx < radius) && (cx > -radius)) && ((cy < radius) && (cy > -radius))) return 1;
	return 0;
}

forward CursorInBox(playerid, boxid);
public  CursorInBox(playerid, boxid)
{
	new Float:x, Float:y;
	new Float:X, Float:Y;
	GetCursorPos(playerid, x, y);
	GetBoxPos(boxid, X, Y);
	if ((x >= X && x <= BoxX2[boxid]) && (y >= Y && y <= Y+5)) return 1;
	return 0;
}

public CursorClick(playerid)
{
	new Float:X,Float:Y;
	GetCursorPos(playerid, X, Y);
	UpdateCursor(playerid, X,Y);
}

forward GetBoxPos(boxid, &Float:x, &Float:y);
public  GetBoxPos(boxid, &Float:x, &Float:y)
{
	x = BoxX[boxid];
	y = BoxY[boxid];
}

forward AddButton(Float:x, Float:y, color, name[]);
public  AddButton(Float:x, Float:y, color, name[])
{
	new times = 10;
	boxes++;
    CursorBox[boxes] = TextDrawCreate(x, y, name);
	TextDrawUseBox(CursorBox[boxes],1);
	TextDrawBoxColor(CursorBox[boxes],color);
	TextDrawTextSize(CursorBox[boxes],x+(strlen(name)*times),0.000000);
	TextDrawAlignment(CursorBox[boxes],0);
	TextDrawBackgroundColor(CursorBox[boxes],0x000000ff);
	TextDrawFont(CursorBox[boxes],1);
	TextDrawLetterSize(CursorBox[boxes],0.500000,0.750000);
	TextDrawColor(CursorBox[boxes],0xffffffff);
	TextDrawSetOutline(CursorBox[boxes],1);
	TextDrawSetProportional(CursorBox[boxes],1);
	TextDrawSetShadow(CursorBox[boxes],1);
	BoxX[boxes] = x-1.0;
	BoxY[boxes] = y-3.0;
	BoxX2[boxes] = BoxX[boxes]+(strlen(name)*times);
	TextDrawShowForAll(CursorBox[boxes]);
	return boxes;
}

forward DeleteButtons();
public  DeleteButtons()
{
	for(new b = 1; b < MAX_BOXES; b++) TextDrawDestroy(CursorBox[b]);
}

stock cursor_strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

/*public OnPlayerClickCursor(playerid, Float:x, Float:y)
{
	return 1;
}*/
