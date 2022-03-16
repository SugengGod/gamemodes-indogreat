/****************************************************************************************************
 *                                                                                                  *
 *                                           Santa Gifts                                            *
 *                                                                                                  *
 * Copyright © 2017 Abyss Morgan. All rights reserved.                                              *
 *                                                                                                  *
 * Download: https://github.com/AbyssMorgan/SA-MP/tree/master/include/event                         *
 * Publication: http://forum.sa-mp.com/showthread.php?t=595265                                      *
 * Website: http://8.ct8.pl                                                                         *
 *                                                                                                  *
 * Plugins: Streamer, ColAndreas/MapAndreas                                                         *
 * Modules: 3DTryg, StreamerFunction                                                                *
 *                                                                                                  *
 * File Version: 1.4.2                                                                              *
 * SA:MP Version: 0.3.7 (REQUIRE)                                                                   *
 * Streamer Version: 2.9.1                                                                          *
 * MapAndreas Version: 1.2.1                                                                        *
 * ColAndreas Version: 1.4.0                                                                        *
 * 3DTryg Version: 4.5.2                                                                            *
 * StreamerFunction Version: 2.8.0                                                                  *
 *                                                                                                  *
 * Callbacks:                                                                                       *
 * OnSantaPickupReward(playerid);                                                                   *
 *                                                                                                  *
 ****************************************************************************************************/

#if (!defined GetPlayerPoolSize || !defined GetSVarInt)
	#error [ADM] This include requires SA:MP version 0.3.7 (github.com/AbyssMorgan/SA-MP/blob/master/samp/include)
#endif

#if ((defined Streamer_AppendArrayData) && (defined INVALID_STREAMER_ID) && (!defined STREAMER_TYPE_ACTOR))
	#error [ADM] You need Streamer v2.9.1 (github.com/samp-incognito/samp-streamer-plugin/releases)
#endif

//Check Version 3DTryg.inc
#if !defined _3D_Tryg
	#error [ADM] You need 3DTryg.inc v4.5.2 (github.com/AbyssMorgan/SA-MP/blob/master/include/SAM/3DTryg.inc)
#elseif !defined Tryg3D_Version
	#error [ADM] Update you 3DTryg.inc to v4.5.2 (github.com/AbyssMorgan/SA-MP/blob/master/include/SAM/3DTryg.inc)
#elseif (Tryg3D_Version < 40502)
	#error [ADM] Update you 3DTryg.inc to v4.5.2 (github.com/AbyssMorgan/SA-MP/blob/master/include/SAM/3DTryg.inc)
#endif

//Check Version StreamerFunction.inc
#if !defined _streamer_spec
	#error [ADM] You need StreamerFunction.inc v2.8.0 (github.com/AbyssMorgan/SA-MP/blob/master/include/SAM/StreamerFunction.inc)
#elseif !defined Streamer_Spec_Version
	#error [ADM] Update you StreamerFunction.inc to v2.8.0 (github.com/AbyssMorgan/SA-MP/blob/master/include/SAM/StreamerFunction.inc)
#elseif (Streamer_Spec_Version < 20800)
	#error [ADM] Update you StreamerFunction.inc to v2.8.0 (github.com/AbyssMorgan/SA-MP/blob/master/include/SAM/StreamerFunction.inc)
#endif

#if !defined Tryg3D_MapAndreasFindZ
	#error [ADM] You need ColAndreas/MapAndreas
#endif

#if defined _santa_gifts
	#endinput
#endif
#define _santa_gifts

#define	MAX_SANTAGIFTS			(100)
#define REFRESH_SANTAGIFTS		(2*60*60*1000)	//2 hour

new SantaGift[MAX_SANTAGIFTS],
	SantaTimer[1];

#if defined SANTA_IS_EASTER_EVENT
	//Easter
	new SantaPickupModel[][1] = {
		{19341},
		{19342},
		{19343},
		{19344},
		{19345}
	};
#elseif defined SANTA_IS_EASTER_HALLOWEEN
	//Halloween
	new SantaPickupModel[][1] = {
		{19320},	//pumpkin
		{19527},	//cauldron
		{19339}		//coffin
	};
#else
	//Christmas
	new SantaPickupModel[][1] = {
		{19054},
		{19055},
		{19056},
		{19057},
		{19058}
	};
#endif

stock SantaInit(){
	#if defined Tryg3D_ColAndreas
		Tryg3D::SafeColAndreasInit();
		if(!Tryg3D::IsColAndreasInit()){
			if(GetSVarInt("ADM:Logging:Disable") == 0){
				printf("[ADM] Error: Invalid ColAndreas Memory.");
			}
			return 0;
		}
	#elseif defined Tryg3D_MapAndreas
		Tryg3D::SafeMapAndreasInit();
		if(!Tryg3D::IsMapAndreasInit()){
			if(GetSVarInt("ADM:Logging:Disable") == 0){
				printf("[ADM] Error: Invalid MapAndreas Memory.");
			}
			return 0;
		}
	#endif
	for(new i = 0; i < MAX_SANTAGIFTS; i++){
		SantaGiftCreate(i);
	}
	SantaTimer[0] = SetTimerEx("SantaReset",REFRESH_SANTAGIFTS,true,"d",1);
	return 1;
}

forward SantaPickUp(playerid,pickupid);
forward SantaReset(tec);
forward SantaGiftCreate(giftid);
forward SantaGiftReset(giftid);

new bool:CRC_SantaInit = true,
	bool:CRC_SantaExit = true;

//Hook: OnGameModeInit
public OnGameModeInit(){
	if(CRC_SantaInit){
		CRC_SantaInit = false;
		if(!SantaInit()) printf("[ADM] Error: Failed to init Santa.inc");
	}
	#if defined SantaOnGameModeInit
		SantaOnGameModeInit();
	#endif
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit SantaOnGameModeInit
#if defined SantaOnGameModeInit
	forward SantaOnGameModeInit();
#endif

//Hook: OnFilterScriptInit
public OnFilterScriptInit(){
	if(CRC_SantaInit){
		CRC_SantaInit = false;
		if(!SantaInit()) printf("[ADM] Error: Failed to init Santa.inc");
	}
	#if defined SantaOnFilterScriptInit
		SantaOnFilterScriptInit();
	#endif
	return 1;
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit SantaOnFilterScriptInit
#if defined SantaOnFilterScriptInit
	forward SantaOnFilterScriptInit();
#endif

//Hook: OnFilterScriptExit
public OnFilterScriptExit(){
	if(CRC_SantaExit){
		CRC_SantaExit = false;
		KillTimer(SantaTimer[0]);
	}
	#if defined SantaOnFilterScriptExit
		SantaOnFilterScriptExit();
	#endif
	return 1;
}

#if defined _ALS_OnFilterScriptExit
	#undef OnFilterScriptExit
#else
	#define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit SantaOnFilterScriptExit
#if defined SantaOnFilterScriptExit
	forward SantaOnFilterScriptExit();
#endif

forward OnSantaPickupReward(playerid);

public SantaPickUp(playerid,pickupid){
	for(new i = 0; i < MAX_SANTAGIFTS; i++){
		if(pickupid == SantaGift[i]){
			SantaGiftReset(i);
			CallLocalFunction("OnSantaPickupReward","d",playerid);
			return 1;
		}
	}
	return 1;
}

//OnPlayerPickUpDynamicPickup
public OnPlayerPickUpDynamicPickup(playerid,pickupid){
	SantaPickUp(playerid,pickupid);
	#if defined Santa_OnPlayerPickUpPickup
		Santa_OnPlayerPickUpPickup(playerid,pickupid);
	#endif
	return 1;
}

#if defined _LS_OnPlayerPickUpDynamicPickup
	#undef OnPlayerPickUpDynamicPickup
#else
	#define _LS_OnPlayerPickUpDynamicPickup
#endif
#define OnPlayerPickUpDynamicPickup Santa_OnPlayerPickUpPickup
#if defined Santa_OnPlayerPickUpPickup
	forward Santa_OnPlayerPickUpPickup(playerid,pickupid);
#endif

public SantaReset(tec){
	for(new i = 0; i < MAX_SANTAGIFTS; i++){
		SantaGiftReset(i);
	}
	return 1;
}

public SantaGiftCreate(giftid){
	new smodel = random(sizeof(SantaPickupModel)), Float:piox, Float:pioy, Float:pioz;
	
	GetRandomPointInRectangle(-3000.0,-3000.0,3000.0,3000.0,piox,pioy);
	while(IsPointInWater(piox,pioy,0.0)){
		GetRandomPointInRectangle(-3000.0,-3000.0,3000.0,3000.0,piox,pioy);
	}
	Tryg3D::MapAndreasFindZ(piox,pioy,pioz);

	pioz+=1.0;
	SantaGift[giftid] = CreateDynamicPickup(SantaPickupModel[smodel][0],2,piox,pioy,pioz,0,0);
	return 1;
}

public SantaGiftReset(giftid){
	new smodel = random(sizeof(SantaPickupModel)), Float:piox, Float:pioy, Float:pioz;
	
	GetRandomPointInRectangle(-3000.0,-3000.0,3000.0,3000.0,piox,pioy);
	while(IsPointInWater(piox,pioy,0.0)){
		GetRandomPointInRectangle(-3000.0,-3000.0,3000.0,3000.0,piox,pioy);
	}
	Tryg3D::MapAndreasFindZ(piox,pioy,pioz);
	
	pioz+=1.0;
	SetDynamicPickupPos(SantaGift[giftid],piox,pioy,pioz);
	SetDynamicPickupModel(SantaGift[giftid],SantaPickupModel[smodel][0]);
	return 1;
}

//EOF