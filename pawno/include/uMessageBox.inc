/*
								uMessageBox Include
*/


#if defined _uMessageBox_included
	#endinput
#endif

#define _uMessageBox_included

#define Timer: Timer_

/*
	Hooking part
*/
#define S_ALS(%0_%1(%2)) %0_%1(%2) <%0:y>
#define chain%0_%1(%2)%3; {state %0:y;%0_%1(%2);}
#define redirect%0_%1(%2)%3; forward%0_%1(%2);stock%0@%1(%2)<%0:y>{}public%0_%1(%2)<%0:n>%3;public%0_%1(%2)<>%3;

/*
	Defines
*/
#define TITLE_X   		(10)
#define TITLE_Y   		(100)
#define TITLE_W      	(100)
#define TITLE_H         (20)
#define TITLE_COLOR 	0x000000AA

#define CONTENT_X   	(10)
#define CONTENT_Y   	(114)
#define CONTENT_W       (100)
#define CONTENT_H       (50)
#define CONTENT_COLOR   0x00000066

#define DEFAULT_TIMEOUT	(5000) // Equals to 5 seconds

/*
	Global variables
*/
new
	Timer:uMsgBox_Hide     	[ MAX_PLAYERS ],
	bool: uMsgBox_Active    [ MAX_PLAYERS ],
	bool: uMsgBox_Init      [ MAX_PLAYERS ],
	Text: uMsgBox_Title		[ MAX_PLAYERS ],
	Text: uMsgBox_Content	[ MAX_PLAYERS ];

/*
	Stocks, Publics
*/
stock
	InitPlayerTextDraws( playerid )
{
	if( uMsgBox_Init[ playerid ] )
	{
		printf( "uMessageBox.inc: trying to init textdraws for player when already initialised.");
		return 1;
	}
	
	uMsgBox_Title[ playerid ] 	= TextDrawCreate( TITLE_X, TITLE_Y, " " );
	uMsgBox_Content[ playerid ] = TextDrawCreate( CONTENT_X, CONTENT_Y, " " );
	
	TextDrawFont			( uMsgBox_Title[ playerid ], 2 );
	TextDrawSetProportional	( uMsgBox_Title[ playerid ], true );
	TextDrawUseBox          ( uMsgBox_Title[ playerid ], true );
	TextDrawBoxColor        ( uMsgBox_Title[ playerid ], TITLE_COLOR );
	TextDrawLetterSize      ( uMsgBox_Title[ playerid ], 0.3, 1.5 );
	TextDrawSetShadow       ( uMsgBox_Title[ playerid ], false );
	TextDrawSetOutline      ( uMsgBox_Title[ playerid ], true );
	TextDrawTextSize        ( uMsgBox_Title[ playerid ], TITLE_X + TITLE_W, 1);
	
	TextDrawFont			( uMsgBox_Content[ playerid ], 1 );
	TextDrawSetProportional	( uMsgBox_Content[ playerid ], true );
	TextDrawUseBox          ( uMsgBox_Content[ playerid ], true );
	TextDrawBoxColor        ( uMsgBox_Content[ playerid ], CONTENT_COLOR );
	TextDrawLetterSize      ( uMsgBox_Content[ playerid ], 0.2, 1.2 );
	TextDrawSetShadow       ( uMsgBox_Content[ playerid ], false );
	TextDrawSetOutline      ( uMsgBox_Content[ playerid ], true );
	TextDrawTextSize        ( uMsgBox_Content[ playerid ], CONTENT_X + CONTENT_W, 1 );
	
	uMsgBox_Init[ playerid ] = true;
	
	return 1;
}

stock
	ShowPlayerMessageBox( playerid, title[], content[], sound = 0, timeout = DEFAULT_TIMEOUT )
{
	if( uMsgBox_Active[ playerid ] )
	    printf( "uMessageBox.inc: trying to show message box when already showing.");
	else
	if( !uMsgBox_Init[ playerid ] )
	    printf( "uMessageBox.inc: trying to show message box when not initialised.");
	else
	{
	    if( sound )
	        PlayerPlaySound( playerid, sound, 0, 0, 0 );
	        
	    TextDrawSetString( uMsgBox_Title[ playerid ], title );
	    TextDrawSetString( uMsgBox_Content[ playerid ], content );
	    
	    TextDrawShowForPlayer( playerid, uMsgBox_Title[ playerid ] );
	    TextDrawShowForPlayer( playerid, uMsgBox_Content[ playerid ] );
	    
	    uMsgBox_Active[ playerid ] = true;
	    
	    Timer:uMsgBox_Hide[ playerid ] = SetTimerEx( "OnMessageBoxHide", timeout, false, "d", playerid );
	}
}

stock
	HidePlayerMessageBox( playerid )
{
    TextDrawHideForPlayer( playerid, uMsgBox_Title[ playerid ] );
	TextDrawHideForPlayer( playerid, uMsgBox_Content[ playerid ] );

	uMsgBox_Active[ playerid ] = false;
}

stock
	UpdatePlayerMessageBox( playerid, title[] = "", content[] = "", timeout = 0 )
{
	if( uMsgBox_Active[ playerid ] == false )
		printf( "uMessageBox.inc: trying to update an existing message box when none exists.");
	else
	{
	    if( strlen( title ) > 0 )
	        TextDrawSetString( uMsgBox_Title[ playerid ], title );
	        
		if( strlen( content ) > 0 )
		    TextDrawSetString( uMsgBox_Content[ playerid ], content );
	
	    if( timeout )
	    {
	        KillTimer( Timer:uMsgBox_Hide[ playerid ] );
	        Timer:uMsgBox_Hide[ playerid ] = SetTimerEx( "OnMessageBoxHide", timeout, false, "d", playerid );
		}
	}
}

stock
	KillPlayerMessageBox( playerid )
{
	TextDrawDestroy( uMsgBox_Title[ playerid ] );
	TextDrawDestroy( uMsgBox_Content[ playerid ] );
	
	uMsgBox_Active[ playerid ] 	= false;
	uMsgBox_Init[ playerid ] 	= false;
	
	return 1;
}

forward
	OnMessageBoxHide( playerid );
public
	OnMessageBoxHide( playerid )
{
	if( !IsPlayerConnected( playerid ) || uMsgBox_Active[ playerid ] == false )
	{
	    KillTimer( Timer:uMsgBox_Hide[ playerid ] );
	    return 1;
	}
	
	HidePlayerMessageBox( playerid );
	
	return 1;
}

/*
	OnPlayerConnect hook
*/
public OnPlayerConnect( playerid )
	return InitPlayerTextDraws( playerid );

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect uMessageBox_OnPlayerConnect
forward uMessageBox_OnPlayerConnect( playerid );

/*
	OnPlayerDisconnect hook
*/
public OnPlayerDisconnect( playerid, reason )
	return KillPlayerMessageBox( playerid );

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect uMessageBox_OnPlayerDisconnect
forward uMessageBox_OnPlayerDisconnect( playerid, reason );