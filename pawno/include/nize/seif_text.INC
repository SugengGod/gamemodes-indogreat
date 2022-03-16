#
/ * X --------------------------------- Importante ------------- ------------------------ X * /
#
//**INCLUDES**// / / INCLUI ** ** / /
#
#include <a_samp> # Include <a_samp>
#
/*x---------------------------------Defining-------------------------------------x*/ / * X --------------------------------- Definir ------------- ------------------------ X * /
#
//**VARIABLES**// / / ** VARIÁVEIS ** / /
#
new Text:Text [ 100 ] ; Novo Texto: Text [100];
#
new gametextdrawforplayer; Novo gametextdrawforplayer;
#
new gametextdraw; Novo gametextdraw;
#
//**FORWARDS**// / / ** FORWARDS ** / /
#
forward GameTextRemoval ( textid ) ; Encaminhar GameTextRemoval (textid);
#
//**NATIVES**// / / ** NATIVES ** / /
#
/* / *
#
native DisplayTextForPlayer(playerid, text[], time, font); Nativas DisplayTextForPlayer (playerid, texto [], o tempo, font);
#
native DisplayTextForAll(text[], time, font); Nativas DisplayTextForAll (texto [], o tempo, font);
#
*/ * /
#
/*x---------------------------------CallBacks-------------------------------------x*/ / * X --------------------------------- CallBacks ------------- ------------------------ X * /
#
stock DisplayTextForPlayer ( playerid, text [ ] , time , font, style ) // Max Fonts: 3(0-3)   <->   Max Styles: 4(1-4) Stock DisplayTextForPlayer (playerid, texto [], o tempo, fonte, estilo) / / Max Fontes: 3 (0-3) <-> Max Estilos: 4 (1-4)
#
{ (
#
if ( gametextdrawforplayer >= 99 ) gametextdrawforplayer = 0 ; If (gametextdrawforplayer> = 99) gametextdrawforplayer = 0;
#
gametextdrawforplayer++; Gametextdrawforplayer + +;
#
new Float :TEXTX, Float :TEXTY; Nova bóia: TEXTX, bóia: TEXTY;
#
if ( style == 1 ) TEXTX = 231 , TEXTY = 61 ; If (estilo == 1) TEXTX = 231, TEXTY = 61;
#
else if ( style == 2 ) TEXTX = 246 , TEXTY = 142 ; Outro caso (estilo == 2) TEXTX = 246, TEXTY = 142;
#
else if ( style == 3 ) TEXTX = 401 , TEXTY = 376 ; Outro caso (estilo == 3) TEXTX = 401, TEXTY = 376;
#
else if ( style == 4 ) TEXTX = 1 , TEXTY = 376 ; Outro caso (estilo == 4) TEXTX = 1, TEXTY = 376;
#
else TEXTX = 246 , TEXTY = 142 ; Outra TEXTX = 246, TEXTY = 142;
#
Text [ gametextdrawforplayer ] = TextDrawCreate ( TEXTX,TEXTY,text ) ; Texto [gametextdrawforplayer] = TextDrawCreate (TEXTX, TEXTY, texto);
#
TextDrawAlignment ( Text [ gametextdrawforplayer ] , 0 ) ; TextDrawAlignment (Texto [gametextdrawforplayer], 0);
#
TextDrawBackgroundColor ( Text [ gametextdrawforplayer ] ,0x000000ff ) ; TextDrawBackgroundColor (Texto [gametextdrawforplayer], 0x000000ff);
#
TextDrawFont ( Text [ gametextdrawforplayer ] ,font ) ; TextDrawFont (Texto [gametextdrawforplayer], font);
#
TextDrawLetterSize ( Text [ gametextdrawforplayer ] , 0.500000 , 2.000000 ) ; TextDrawLetterSize (Texto [gametextdrawforplayer], 0,500000, 2,000000);
#
TextDrawColor ( Text [ gametextdrawforplayer ] ,0xffffffff ) ; TextDrawColor (Texto [gametextdrawforplayer], 0xffffffff);
#
TextDrawSetOutline ( Text [ gametextdrawforplayer ] , 1 ) ; TextDrawSetOutline (Texto [gametextdrawforplayer], 1);
#
TextDrawSetProportional ( Text [ gametextdrawforplayer ] , 1 ) ; TextDrawSetProportional (Texto [gametextdrawforplayer], 1);
#
TextDrawSetShadow ( Text [ gametextdrawforplayer ] , 1 ) ; TextDrawSetShadow (Texto [gametextdrawforplayer], 1);
#
TextDrawShowForPlayer ( playerid,Text [ gametextdrawforplayer ] ) ; TextDrawShowForPlayer (playerid, Text [gametextdrawforplayer]);
#
SetTimerEx ( "GameTextRemoval" , time * 1000 , false , "d" ,gametextdrawforplayer ) ; SetTimerEx (1000);
#
} )
#
#
stock DisplayTextForAll ( text [ ] , time , font, style ) // Max Fonts: 3(0-3)   <->   Max Styles: 4(1-4) Stock DisplayTextForAll (texto [], o tempo, fonte, estilo) / / Max Fontes: 3 (0-3) <-> Max Estilos: 4 (1-4)
#
{ (
#
if ( gametextdraw >= 99 ) gametextdraw = 0 ; If (gametextdraw> = 99) gametextdraw = 0;
#
gametextdraw++; Gametextdraw + +;
#
new Float :TEXTX, Float :TEXTY; Nova bóia: TEXTX, bóia: TEXTY;
#
if ( style == 1 ) TEXTX = 231 , TEXTY = 142 ; If (estilo == 1) TEXTX = 231, TEXTY = 142;
#
else if ( style == 2 ) TEXTX = 246 , TEXTY = 142 ; Outro caso (estilo == 2) TEXTX = 246, TEXTY = 142;
#
else if ( style == 3 ) TEXTX = 401 , TEXTY = 376 ; Outro caso (estilo == 3) TEXTX = 401, TEXTY = 376;
#
else if ( style == 4 ) TEXTX = 1 , TEXTY = 376 ; Outro caso (estilo == 4) TEXTX = 1, TEXTY = 376;
#
else TEXTX = 246 , TEXTY = 142 ; Outra TEXTX = 246, TEXTY = 142;
#
Text [ gametextdraw ] = TextDrawCreate ( TEXTX,TEXTY,text ) ; Texto [gametextdraw] = TextDrawCreate (TEXTX, TEXTY, texto);
#
TextDrawAlignment ( Text [ gametextdraw ] , 0 ) ; TextDrawAlignment (Texto [gametextdraw], 0);
#
TextDrawBackgroundColor ( Text [ gametextdraw ] ,0x000000ff ) ; TextDrawBackgroundColor (Texto [gametextdraw], 0x000000ff);
#
TextDrawFont ( Text [ gametextdraw ] ,font ) ; TextDrawFont (Texto [gametextdraw], font);
#
TextDrawLetterSize ( Text [ gametextdraw ] , 0.500000 , 2.000000 ) ; TextDrawLetterSize (Texto [gametextdraw], 0,500000, 2,000000);
#
TextDrawColor ( Text [ gametextdraw ] ,0xffffffff ) ; TextDrawColor (Texto [gametextdraw], 0xffffffff);
#
TextDrawSetOutline ( Text [ gametextdraw ] , 1 ) ; TextDrawSetOutline (Texto [gametextdraw], 1);
#
TextDrawSetProportional ( Text [ gametextdraw ] , 1 ) ; TextDrawSetProportional (Texto [gametextdraw], 1);
#
TextDrawSetShadow ( Text [ gametextdraw ] , 1 ) ; TextDrawSetShadow (Texto [gametextdraw], 1);
#
TextDrawShowForAll ( Text [ gametextdraw ] ) ; TextDrawShowForAll (Texto [gametextdraw]);
#
SetTimerEx ( "GameTextRemoval" , time * 1000 , false , "d" ,gametextdraw ) ; SetTimerEx (1000);
#
} )
#
#
public GameTextRemoval ( textid ) GameTextRemoval público (textid)
#
{ (
#
TextDrawDestroy ( Text [ textid ] ) ; TextDrawDestroy (Texto [textid]);
#
return true ; Retornar true;
#
} ) 