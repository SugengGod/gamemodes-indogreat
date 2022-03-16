// Animations script for Millennial Roleplay
#define COLOR_GRAD1  0xB4B5B7FF
#define COLOR_GRAD2  0xBFC0C2FF
#define COLOR_GRAD3  0xCBCCCEFF
#define COLOR_GRAD4  0xD8D8D8FF
#define COLOR_GRAD5  0xE3E3E3FF
#define COLOR_GRAD6  0xF0F0F0FF
#define COLOR_GREEN  0x32CD32FF
#define COLOR_ERROR  0xF9B64AFF
#define SERVER_COLOR 0xF16481ff
IsCLowrider(carid)
{
	new Cars[] = { 536, 575, 567};
	for(new i = 0; i < sizeof(Cars); i++)
	{
		if(GetVehicleModel(carid) == Cars[i]) return 1;
	}
	return 0;
}


CMD:animlist(playerid, params[])
{
	SendClientMessage(playerid, COLOR_GREEN, "Available Animations:");
	SendClientMessage(playerid, COLOR_GRAD1, "/handsup /drunk /bomb /rob /laugh /lookout /robman /crossarms /sit /siteat /hide /vomit /eat");
	SendClientMessage(playerid, COLOR_GRAD2, "/wave /slapass /deal /taichi /crack /smoke /chat /dance /fucku /drinkwater /pedmove /bat /aim");
	SendClientMessage(playerid, COLOR_GRAD3, "/checktime /sleep /blob /opendoor /wavedown /shakehand /reload /cpr /dive /showoff /box /tag");
	SendClientMessage(playerid, COLOR_GRAD4, "/goggles /cry /dj /cheer /throw /robbed /hurt /nobreath /bar /getjiggy /fallover /rap /piss");
	SendClientMessage(playerid, COLOR_GRAD5, "/salute /crabs /washhands /signal /stop /gesture /jerkoff /idles /lowrider /carchat /bj /fuckme");
	SendClientMessage(playerid, COLOR_GRAD6, "/blowjob /spank /sunbathe /kiss /snatch /sneak /copa /sexy /holdup /misc /bodypush /walkstyle");
	SendClientMessage(playerid, COLOR_GRAD6, "/lowbodypush /headbutt /airkick /doorkick /leftslap /elbow /coprun /sitonchair /lean /wank /walk");
	SendClientMessage(playerid, COLOR_GRAD4, "/point /tired /injured /fishing /dodge /scratch /what /come /hitch /shifty /traffic /ghands");
	SendClientMessage(playerid, COLOR_GREEN, "Use /stopani to stop an animation.");
	return 1;
}

CMD:animhelp(playerid, params[])
{
	return callcmd::animlist(playerid, params);
}
CMD:stopani(playerid, params[])
{
	return callcmd::stopanim(playerid, params);
}

CMD:bodypush(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
    ApplyAnimation(playerid,"GANGS","shake_cara",4.0,0,0,0,0,0);
	return 1;
}

CMD:lowbodypush(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
    ApplyAnimation(playerid,"GANGS","shake_carSH",4.0,0,0,0,0,0);
	return 1;
}

CMD:headbutt(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
    ApplyAnimation(playerid,"WAYFARER","WF_Fwd",4.0,0,0,0,0,0);
	return 1;
}

CMD:airkick(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
    ApplyAnimation(playerid,"FIGHT_C","FightC_M",4.0,0,1,1,0,0);
	return 1;
}

CMD:doorkick(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
    ApplyAnimation(playerid,"POLICE","Door_Kick",4.0,0,0,0,0,0);
	return 1;
}

CMD:leftslap(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","BIKE_elbowL",4.0,0,0,0,0,0);
	return 1;
}

CMD:elbow(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
    ApplyAnimation(playerid,"FIGHT_D","FightD_3",4.0,0,1,1,0,0);
	return 1;
}

CMD:coprun(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
    ApplyAnimation(playerid,"SWORD","sword_block",50.0,0,1,1,1,1);
	return 1;
}

CMD:piss(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
   	SetPlayerSpecialAction(playerid, 68);
	return 1;
}

CMD:sneak(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	ApplyAnimationEx(playerid, "PED", "Player_Sneak", 4.1, 1, 1, 1, 1, 1);
	return 1;
}

CMD:drunk(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
   	ApplyAnimationEx(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 1);
    return 1;
}

CMD:bomb(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
   	ApplyAnimationEx(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:rob(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	ApplyAnimationEx(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, 1);
	return 1;
}

CMD:laugh(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	ApplyAnimationEx(playerid, "RAPPING", "Laugh_01", 4.0, 1, 0, 0, 0, 0);
	return 1;
}

CMD:lookout(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
   	ApplyAnimationEx(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:robman(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:hide(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:vomit(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "FOOD", "EAT_Vomit_P", 3.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:slapass(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:crack(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "CRACK", "crckdeth1", 4.1, 0, 0, 0, 1, 0);
        case 2: ApplyAnimationEx(playerid, "CRACK", "crckdeth2", 4.1, 1, 0, 0, 0, 0);
        case 3: ApplyAnimationEx(playerid, "CRACK", "crckdeth3", 4.1, 0, 0, 0, 1, 0);
        case 4: ApplyAnimationEx(playerid, "CRACK", "crckdeth4", 4.1, 0, 0, 0, 1, 0);
	    default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /crack [1-4]");
	}
    return 1;
}

CMD:fucku(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:taichi(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:drinkwater(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:checktime(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_watch", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:sleep(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "CRACK", "crckdeth4", 4.0, 0, 1, 1, 1, 0);
    return 1;
}

CMD:blob(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "CRACK", "crckidle1", 4.0, 0, 1, 1, 1, 0);
    return 1;
}

CMD:opendoor(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "AIRPORT", "thrw_barl_thrw", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:wavedown(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "BD_FIRE", "BD_Panic_01", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:cpr(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "MEDIC", "CPR", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:dive(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "DODGE", "Crush_Jump", 4.0, 0, 1, 1, 1, 0);
    return 1;
}

CMD:showoff(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "Freeweights", "gym_free_celebrate", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:goggles(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "goggles", "goggles_put_on", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:cry(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "GRAVEYARD", "mrnF_loop", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:throw(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "GRENADE", "WEAPON_throw", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:robbed(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "SHOP", "SHP_Rob_GiveCash", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:hurt(playerid)
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "SWAT", "gnstwall_injurd", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
CMD:handsup(playerid)
{
	if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_HANDSUP);
	return 1;
}
CMD:box(playerid)
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "GYMNASIUM", "GYMshadowbox", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:washhands(playerid)
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "BD_FIRE", "wash_up", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:crabs(playerid)
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "MISC", "Scratchballs_01", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:salute(playerid)
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "ON_LOOKERS", "Pointup_loop", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:jerkoff(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "PAULNMAC", "wank_out", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:stop(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
    ApplyAnimationEx(playerid, "PED", "endchat_01", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:rap(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "RAPPING", "RAP_A_Loop", 4.0, 1, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "RAPPING", "RAP_B_Loop", 4.0, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "RAPPING", "RAP_C_Loop", 4.0, 1, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /rap [1-3]");
	}
	return 1;
}

CMD:wank(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "PAULNMAC", "wank_in", 4.0, 1, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "PAULNMAC", "wank_loop", 4.0, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "PAULNMAC", "wank_out", 4.0, 1, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /wank [1-3]");
	}
	return 1;
}

CMD:chat(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkA", 4.1, 1, 1, 1, 1, 1);
		case 3: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkB", 4.1, 1, 1, 1, 1, 1);
		case 4: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkC", 4.1, 1, 1, 1, 1, 1);
		case 5: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkD", 4.1, 1, 1, 1, 1, 1);
        case 6: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkE", 4.1, 1, 1, 1, 1, 1);
		case 7: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkF", 4.1, 1, 1, 1, 1, 1);
		case 8: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkG", 4.1, 1, 1, 1, 1, 1);
		case 9: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkH", 4.1, 1, 1, 1, 1, 1);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /chat [1-9]");
	}
	return 1;
}

CMD:sitdown(playerid, params[])
	return callcmd::sitonchair(playerid, params);
	
CMD:sitonchair(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "Attractors", "Stepsit_in", 4.0, 0, 0, 0, 1, 0);
		case 2: ApplyAnimationEx(playerid, "CRIB", "PED_Console_Loop", 4.0, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "INT_HOUSE", "LOU_In", 4.0, 0, 0, 0, 1, 1);
		case 4: ApplyAnimationEx(playerid, "MISC", "SEAT_LR", 4.0, 1, 0, 0, 0, 0);
		case 5: ApplyAnimationEx(playerid, "MISC", "Seat_talk_01", 4.0, 1, 0, 0, 0, 0);
		case 6: ApplyAnimationEx(playerid, "MISC", "Seat_talk_02", 4.0, 1, 0, 0, 0, 0);
		case 7: ApplyAnimationEx(playerid, "ped", "SEAT_down", 4.0, 0, 0, 0, 1, 1);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /sitonchair [1-7]");
	}
	return 1;
}

CMD:bat(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid,"BASEBALL","Bat_IDLE",4.1, 0, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "CRACK", "Bbalbat_Idle_01", 4.0, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "CRACK", "Bbalbat_Idle_02", 4.0, 1, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /bat [1-3]");
	}
	return 1;
}

CMD:lean(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "GANGS", "leanIDLE", 4.0, 0, 0, 0, 1, 0);
		case 2: ApplyAnimationEx(playerid, "MISC", "Plyrlean_loop", 4.0, 0, 0, 0, 1, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /lean [1-2]");
	}
	return 1;
}

CMD:gesture(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "GHANDS", "gsign1", 4.0, 0, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "GHANDS", "gsign1LH", 4.0, 0, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "GHANDS", "gsign2", 4.0, 0, 0, 0, 0, 0);
	case 4: ApplyAnimationEx(playerid, "GHANDS", "gsign2LH", 4.0, 0, 0, 0, 0, 0);
	case 5: ApplyAnimationEx(playerid, "GHANDS", "gsign3", 4.0, 0, 0, 0, 0, 0);
	case 6: ApplyAnimationEx(playerid, "GHANDS", "gsign3LH", 4.0, 0, 0, 0, 0, 0);
	case 7: ApplyAnimationEx(playerid, "GHANDS", "gsign4", 4.0, 0, 0, 0, 0, 0);
	case 8: ApplyAnimationEx(playerid, "GHANDS", "gsign4LH", 4.0, 0, 0, 0, 0, 0);
	case 9: ApplyAnimationEx(playerid, "GHANDS", "gsign5", 4.0, 0, 0, 0, 0, 0);
	case 10: ApplyAnimationEx(playerid, "GHANDS", "gsign5", 4.0, 0, 0, 0, 0, 0);
	case 11: ApplyAnimationEx(playerid, "GHANDS", "gsign5LH", 4.0, 0, 0, 0, 0, 0);
	case 12: ApplyAnimationEx(playerid, "GANGS", "Invite_No", 4.0, 0, 0, 0, 0, 0);
	case 13: ApplyAnimationEx(playerid, "GANGS", "Invite_Yes", 4.0, 0, 0, 0, 0, 0);
	case 14: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkD", 4.0, 0, 0, 0, 0, 0);
	case 15: ApplyAnimationEx(playerid, "GANGS", "smkcig_prtl", 4.0, 0, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /gesture [1-15]");
	}
	return 1;
}

CMD:lay(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "BEACH", "Lay_Bac_Loop", 4.0, 1, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "BEACH", "SitnWait_loop_W", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /lay [1-3]");
	}
	return 1;
}

CMD:wave(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "KISSING", "gfwave2", 4.0, 1, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "PED", "endchat_03", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /wave [1-3]");
	}
	return 1;
}

CMD:signal(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Come", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Stop", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /signal [1-2]");
	}
	return 1;
}

CMD:nobreath(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "PED", "IDLE_tired", 4.0, 1, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "FAT", "IDLE_tired", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /nobreath [1-3]");
	}
	return 1;
}

CMD:fallover(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "KNIFE", "KILL_Knife_Ped_Die", 4.0, 0, 1, 1, 1, 0);
	case 2: ApplyAnimationEx(playerid, "PED", "KO_shot_face", 4.0, 0, 1, 1, 1, 0);
	case 3: ApplyAnimationEx(playerid, "PED", "KO_shot_stom", 4.0, 0, 1, 1, 1, 0);
	case 4: ApplyAnimationEx(playerid, "PED", "BIKE_fallR", 4.1, 0, 1, 1, 1, 0);
	case 5: ApplyAnimationEx(playerid, "PED", "BIKE_fall_off", 4.1, 0, 1, 1, 1, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /fallover [1-5]");
	}
	return 1;
}

CMD:pedmove(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "PED", "JOG_femaleA", 4.0, 1, 1, 1, 1, 1);
	case 2: ApplyAnimationEx(playerid, "PED", "JOG_maleA", 4.0, 1, 1, 1, 1, 1);
	case 3: ApplyAnimationEx(playerid, "PED", "WOMAN_walkfatold", 4.0, 1, 1, 1, 1, 1);
	case 4: ApplyAnimationEx(playerid, "PED", "run_fat", 4.0, 1, 1, 1, 1, 1);
	case 5: ApplyAnimationEx(playerid, "PED", "run_fatold", 4.0, 1, 1, 1, 1, 1);
	case 6: ApplyAnimationEx(playerid, "PED", "run_old", 4.0, 1, 1, 1, 1, 1);
	case 7: ApplyAnimationEx(playerid, "PED", "Run_Wuzi", 4.0, 1, 1, 1, 1, 1);
	case 8: ApplyAnimationEx(playerid, "PED", "swat_run", 4.0, 1, 1, 1, 1, 1);
	case 9: ApplyAnimationEx(playerid, "PED", "WALK_fat", 4.0, 1, 1, 1, 1, 1);
	case 10: ApplyAnimationEx(playerid, "PED", "WALK_fatold", 4.0, 1, 1, 1, 1, 1);
	case 11: ApplyAnimationEx(playerid, "PED", "WALK_gang1", 4.0, 1, 1, 1, 1, 1);
	case 12: ApplyAnimationEx(playerid, "PED", "WALK_gang2", 4.0, 1, 1, 1, 1, 1);
	case 13: ApplyAnimationEx(playerid, "PED", "WALK_old", 4.0, 1, 1, 1, 1, 1);
	case 14: ApplyAnimationEx(playerid, "PED", "WALK_shuffle", 4.0, 1, 1, 1, 1, 1);
	case 15: ApplyAnimationEx(playerid, "PED", "woman_run", 4.0, 1, 1, 1, 1, 1);
	case 16: ApplyAnimationEx(playerid, "PED", "WOMAN_runbusy", 4.0, 1, 1, 1, 1, 1);
	case 17: ApplyAnimationEx(playerid, "PED", "WOMAN_runfatold", 4.0, 1, 1, 1, 1, 1);
	case 18: ApplyAnimationEx(playerid, "PED", "woman_runpanic", 4.0, 1, 1, 1, 1, 1);
	case 19: ApplyAnimationEx(playerid, "PED", "WOMAN_runsexy", 4.0, 1, 1, 1, 1, 1);
	case 20: ApplyAnimationEx(playerid, "PED", "WOMAN_walkbusy", 4.0, 1, 1, 1, 1, 1);
	case 21: ApplyAnimationEx(playerid, "PED", "WOMAN_walkfatold", 4.0, 1, 1, 1, 1, 1);
	case 22: ApplyAnimationEx(playerid, "PED", "WOMAN_walknorm", 4.0, 1, 1, 1, 1, 1);
	case 23: ApplyAnimationEx(playerid, "PED", "WOMAN_walkold", 4.0, 1, 1, 1, 1, 1);
	case 24: ApplyAnimationEx(playerid, "PED", "WOMAN_walkpro", 4.0, 1, 1, 1, 1, 1);
	case 25: ApplyAnimationEx(playerid, "PED", "WOMAN_walksexy", 4.0, 1, 1, 1, 1, 1);
	case 26: ApplyAnimationEx(playerid, "PED", "WOMAN_walkshop", 4.0, 1, 1, 1, 1, 1);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /pedmove [1-26]");
	}
	return 1;
}

CMD:getjiggy(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "DANCING", "DAN_Down_A", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "DANCING", "DAN_Left_A", 4.0, 1, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "DANCING", "DAN_Loop_A", 4.0, 1, 0, 0, 0, 0);
	case 4: ApplyAnimationEx(playerid, "DANCING", "DAN_Right_A", 4.0, 1, 0, 0, 0, 0);
	case 5: ApplyAnimationEx(playerid, "DANCING", "DAN_Up_A", 4.0, 1, 0, 0, 0, 0);
	case 6: ApplyAnimationEx(playerid, "DANCING", "dnce_M_a", 4.0, 1, 0, 0, 0, 0);
	case 7: ApplyAnimationEx(playerid, "DANCING", "dnce_M_b", 4.0, 1, 0, 0, 0, 0);
	case 8: ApplyAnimationEx(playerid, "DANCING", "dnce_M_c", 4.0, 1, 0, 0, 0, 0);
	case 9: ApplyAnimationEx(playerid, "DANCING", "dnce_M_c", 4.0, 1, 0, 0, 0, 0);
	case 10: ApplyAnimationEx(playerid, "DANCING", "dnce_M_d", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /getjiggy [1-10]");
	}
	return 1;
}

CMD:stripclub(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "STRIP", "PLY_CASH", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "STRIP", "PUN_CASH", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /stripclub [1-2]");
	}
	return 1;
}

CMD:smoke(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "SMOKING", "M_smk_in", 4.0, 0, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /smoke [1-2]");
	}
	return 1;
}

CMD:dj(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "SCRATCHING", "scdldlp", 4.0, 1, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "SCRATCHING", "scdlulp", 4.0, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "SCRATCHING", "scdrdlp", 4.0, 1, 0, 0, 0, 0);
		case 4: ApplyAnimationEx(playerid, "SCRATCHING", "scdrulp", 4.0, 1, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /dj [1-4]");
	}
	return 1;
}

CMD:reload(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "BUDDY", "buddy_reload", 4.1, 0, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "PYTHON", "python_reload", 4.1, 0, 0, 0, 0, 0);
        case 3: ApplyAnimationEx(playerid, "UZI", "UZI_reload", 4.1, 0, 0, 0, 0, 0);
        case 4: ApplyAnimationEx(playerid, "RIFLE", "RIFLE_load", 4.1, 0, 0, 0, 0, 0);
	    default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /reload [1-4]");
	}
	return 1;
}

CMD:tag(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "GRAFFITI", "graffiti_Chkout", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "GRAFFITI", "spraycan_fire", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /tag [1-2]");
	}
	return 1;
}

CMD:deal(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "DEALER", "DEALER_DEAL", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "DEALER", "shop_pay", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /deal [1-2]");
	}
	return 1;
}

CMD:crossarms(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);
		case 2: ApplyAnimationEx(playerid, "DEALER", "DEALER_IDLE", 4.0, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "GRAVEYARD", "mrnM_loop", 4.0, 1, 0, 0, 0, 0);
		case 4: ApplyAnimationEx(playerid, "GRAVEYARD", "prst_loopa", 4.0, 1, 0, 0, 0, 0);
		case 5: ApplyAnimationEx(playerid, "DEALER", "DEALER_IDLE_01", 4.0, 1, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /crossarms [1-5]");
	}
	return 1;
}

CMD:cheer(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "ON_LOOKERS", "shout_01", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "ON_LOOKERS", "shout_02", 4.0, 1, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "ON_LOOKERS", "shout_in", 4.0, 1, 0, 0, 0, 0);
	case 4: ApplyAnimationEx(playerid, "RIOT", "RIOT_ANGRY_B", 4.0, 1, 0, 0, 0, 0);
	case 5: ApplyAnimationEx(playerid, "RIOT", "RIOT_CHANT", 4.0, 1, 0, 0, 0, 0);
	case 6: ApplyAnimationEx(playerid, "RIOT", "RIOT_shout", 4.0, 1, 0, 0, 0, 0);
	case 7: ApplyAnimationEx(playerid, "STRIP", "PUN_HOLLER", 4.0, 1, 0, 0, 0, 0);
	case 8: ApplyAnimationEx(playerid, "OTB", "wtchrace_win", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /cheer [1-8]");
	}
	return 1;
}

CMD:sit(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "BEACH", "Lay_Bac_Loop", 4.0, 1, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "BEACH", "ParkSit_W_loop", 4.0, 1, 0, 0, 0, 0);
	case 4: ApplyAnimationEx(playerid, "BEACH", "SitnWait_loop_W", 4.0, 1, 0, 0, 0, 0);
	case 5: ApplyAnimationEx(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /sit [1-5]");
	}
	return 1;
}

CMD:siteat(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "FOOD", "FF_Sit_Eat3", 4.0, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "FOOD", "FF_Sit_Eat2", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /siteat [1-2]");
	}
	return 1;
}

CMD:bar(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "BAR", "Barcustom_get", 4.0, 0, 1, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "BAR", "Barserve_bottle", 4.0, 0, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "BAR", "Barserve_give", 4.0, 0, 0, 0, 0, 0);
	case 4: ApplyAnimationEx(playerid, "BAR", "dnk_stndM_loop", 4.0, 0, 0, 0, 0, 0);
	case 5: ApplyAnimationEx(playerid, "BAR", "BARman_idle", 4.0, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /bar [1-5]");
	}
	return 1;
}

CMD:dance(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	new count, animname[32], animlib[32];
	if(GetPlayerAnimationIndex(playerid) != 0) ClearAnimations(playerid);
	switch(strval(params))
	{
		case 1: SetPlayerSpecialAction(playerid, 5);
		case 2: SetPlayerSpecialAction(playerid, 6);
		case 3: SetPlayerSpecialAction(playerid, 7);
		case 4: SetPlayerSpecialAction(playerid, 8);
		case 5: ApplyAnimationEx(playerid, "DANCING", "DAN_Down_A", 4.1, 1, 0, 0, 0, 0);
		case 6: ApplyAnimationEx(playerid, "DANCING", "DAN_Left_A", 4.1, 1, 0, 0, 0, 0);
		case 7: ApplyAnimationEx(playerid, "DANCING", "DAN_Loop_A", 4.1, 1, 0, 0, 0, 0);
		case 8: ApplyAnimationEx(playerid, "DANCING", "DAN_Right_A", 4.1, 1, 0, 0, 0, 0);
		case 9: ApplyAnimationEx(playerid, "DANCING", "DAN_Up_A", 4.1, 1, 0, 0, 0, 0);
        case 10: ApplyAnimationEx(playerid, "DANCING", "dnce_M_a", 4.1, 1, 0, 0, 0, 0);
		case 11: ApplyAnimationEx(playerid, "DANCING", "dnce_M_b", 4.1, 1, 0, 0, 0, 0);
		case 12: ApplyAnimationEx(playerid, "DANCING", "dnce_M_c", 4.1, 1, 0, 0, 0, 0);
		case 13: ApplyAnimationEx(playerid, "DANCING", "dnce_M_d", 4.1, 1, 0, 0, 0, 0);
		case 14: ApplyAnimationEx(playerid, "DANCING", "dnce_M_e", 4.1, 1, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /dance [1-14]");
	}
	foreach(new i : Player) {
	    if(IsPlayerInRangeOfPlayer(i, playerid, 20.0))
		{
		    GetAnimationName(GetPlayerAnimationIndex(i), animlib, sizeof(animlib), animname, sizeof(animname));

			if((SPECIAL_ACTION_DANCE1 <= GetPlayerSpecialAction(i) <= SPECIAL_ACTION_DANCE4) || !strcmp(animlib, "DANCING", true))
			{
			    count++;
			}
	    }
	}
	if(count >= 5) {
	    foreach(new i : Player)
	    {
	        if(IsPlayerInRangeOfPlayer(i, playerid, 20.0))
			{
		    	GetAnimationName(GetPlayerAnimationIndex(i), animlib, sizeof(animlib), animname, sizeof(animname));
	        }
		}
	}
	return 1;
}

CMD:spank(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "SNM", "SPANKINGW", 4.1, 1, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "SNM", "SPANKINGP", 4.1, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "SNM", "SPANKEDW", 4.1, 1, 0, 0, 0, 0);
		case 4: ApplyAnimationEx(playerid, "SNM", "SPANKEDP", 4.1, 1, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /spank [1-4]");
	}
	return 1;
}

CMD:sexy(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "STRIP", "strip_E", 4.1, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "STRIP", "strip_G", 4.1, 1, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "STRIP", "STR_A2B", 4.1, 0, 0, 0, 0, 0);
	case 4: ApplyAnimationEx(playerid, "STRIP", "STR_Loop_A", 4.1, 1, 0, 0, 0, 0);
	case 5: ApplyAnimationEx(playerid, "STRIP", "STR_Loop_B", 4.1, 1, 0, 0, 0, 0);
	case 6: ApplyAnimationEx(playerid, "STRIP", "STR_Loop_C", 4.1, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /sexy [1-6]");
	}
	return 1;
}

CMD:holdup(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "POOL", "POOL_ChalkCue", 4.1, 0, 1, 1, 1, 1);
	case 2: ApplyAnimationEx(playerid, "POOL", "POOL_Idle_Stance", 4.1, 0, 1, 1, 1, 1);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /holdup [1-2]");
	}
	return 1;
}

CMD:stickjup(playerid, params[])
{
    ApplyAnimationEx(playerid, "POOL", "POOL_Idle_Stance", 4.1, 0, 1, 1, 1, 1);
    return 1;
}

CMD:copa(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Away", 4.1, 0, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Come", 4.1, 0, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Left", 4.1, 0, 0, 0, 0, 0);
	case 4: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Stop", 4.1, 0, 0, 0, 0, 0);
	case 5: ApplyAnimationEx(playerid, "POLICE", "Cop_move_FWD", 4.1, 1, 1, 1, 1, 1);
	case 6: ApplyAnimationEx(playerid, "POLICE", "crm_drgbst_01", 4.1, 0, 0, 0, 1, 5000);
	case 7: ApplyAnimationEx(playerid, "POLICE", "Door_Kick", 4.1, 0, 1, 1, 1, 1);
	case 8: ApplyAnimationEx(playerid, "POLICE", "plc_drgbst_01", 4.1, 0, 0, 0, 0, 5000);
	case 9: ApplyAnimationEx(playerid, "POLICE", "plc_drgbst_02", 4.1, 0, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /copa [1-9]");
	}
	return 1;
}

CMD:misc(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	//case 1: ApplyAnimationEx(playerid, "CAR", "Fixn_Car_Loop", 4.1, 1, 0, 0, 0, 0);
	case 1: ApplyAnimationEx(playerid, "CAR", "flag_drop", 4.1, 0, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "PED", "bomber", 4.1, 0, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /misc [1-2]");
	}
	return 1;
}

CMD:snatch(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "PED", "BIKE_elbowL", 4.1, 0, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "PED", "BIKE_elbowR", 4.1, 0, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /snatch [1-2]");
	}
	return 1;
}

CMD:blowjob(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_LOOP_P", 4.1, 1, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_LOOP_P", 4.1, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /blowjob [1-2]");
	}
	return 1;
}

CMD:kiss(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "KISSING", "Playa_Kiss_01", 4.1, 0, 0, 0, 0, 0);
	case 2: ApplyAnimationEx(playerid, "KISSING", "Playa_Kiss_02", 4.1, 0, 0, 0, 0, 0);
	case 3: ApplyAnimationEx(playerid, "KISSING", "Playa_Kiss_03", 4.1, 0, 0, 0, 0, 0);
	case 4: ApplyAnimationEx(playerid, "KISSING", "Grlfrd_Kiss_01", 4.1, 0, 0, 0, 0, 0);
	case 5: ApplyAnimationEx(playerid, "KISSING", "Grlfrd_Kiss_02", 4.1, 0, 0, 0, 0, 0);
	case 6: ApplyAnimationEx(playerid, "KISSING", "Grlfrd_Kiss_03", 4.1, 0, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /kiss [1-6]");
	}
	return 1;
}

CMD:idles(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "PLAYIDLES", "shift", 4.1, 1, 1, 1, 1, 1);
	case 2: ApplyAnimationEx(playerid, "PLAYIDLES", "shldr", 4.1, 1, 1, 1, 1, 1);
	case 3: ApplyAnimationEx(playerid, "PLAYIDLES", "stretch", 4.1, 1, 1, 1, 1, 1);
	case 4: ApplyAnimationEx(playerid, "PLAYIDLES", "strleg", 4.1, 1, 1, 1, 1, 1);
	case 5: ApplyAnimationEx(playerid, "PLAYIDLES", "time", 4.1, 1, 1, 1, 1, 1);
	case 6: ApplyAnimationEx(playerid, "COP_AMBIENT", "Copbrowse_loop", 4.1, 1, 0, 0, 0, 0);
	case 7: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_loop", 4.1, 1, 0, 0, 0, 0);
	case 8: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_shake", 4.1, 1, 0, 0, 0, 0);
	case 9: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_think", 4.1, 1, 0, 0, 0, 0);
	case 10: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_watch", 4.1, 1, 0, 0, 0, 0);
	case 11: ApplyAnimationEx(playerid, "PED", "roadcross", 4.1, 1, 0, 0, 0, 0);
	case 12: ApplyAnimationEx(playerid, "PED", "roadcross_female", 4.1, 1, 0, 0, 0, 0);
	case 13: ApplyAnimationEx(playerid, "PED", "roadcross_gang", 4.1, 1, 0, 0, 0, 0);
	case 14: ApplyAnimationEx(playerid, "PED", "roadcross_old", 4.1, 1, 0, 0, 0, 0);
	case 15: ApplyAnimationEx(playerid, "PED", "woman_idlestance", 4.1, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /idles [1-15]");
	}
	return 1;
}

CMD:sunbathe(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "SUNBATHE", "batherdown", 4.1, 0, 1, 1, 1, 1);
	case 2: ApplyAnimationEx(playerid, "SUNBATHE", "batherup", 4.1, 0, 1, 1, 1, 1);
	case 3: ApplyAnimationEx(playerid, "SUNBATHE", "Lay_Bac_in", 4.1, 0, 1, 1, 1, 1);
	case 4: ApplyAnimationEx(playerid, "SUNBATHE", "Lay_Bac_out", 4.1, 0, 1, 1, 1, 1);
	case 5: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_M_IdleA", 4.1, 0, 1, 1, 1, 1);
	case 6: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_M_IdleB", 4.1, 0, 1, 1, 1, 1);
	case 7: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_M_IdleC", 4.1, 0, 1, 1, 1, 1);
	case 8: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_M_in", 4.1, 0, 1, 1, 1, 1);
	case 9: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_M_out", 4.1, 0, 1, 1, 1, 1);
	case 10: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_W_idleA", 4.1, 0, 1, 1, 1, 1);
	case 11: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_W_idleB", 4.1, 0, 1, 1, 1, 1);
	case 12: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_W_idleC", 4.1, 0, 1, 1, 1, 1);
	case 13: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_W_in", 4.1, 0, 1, 1, 1, 1);
	case 14: ApplyAnimationEx(playerid, "SUNBATHE", "ParkSit_W_out", 4.1, 0, 1, 1, 1, 1);
	case 15: ApplyAnimationEx(playerid, "SUNBATHE", "SBATHE_F_LieB2Sit", 4.1, 0, 1, 1, 1, 1);
	case 16: ApplyAnimationEx(playerid, "SUNBATHE", "SBATHE_F_Out", 4.1, 0, 1, 1, 1, 1);
	case 17: ApplyAnimationEx(playerid, "SUNBATHE", "SitnWait_in_W", 4.1, 0, 1, 1, 1, 1);
	case 18: ApplyAnimationEx(playerid, "SUNBATHE", "SitnWait_out_W", 4.1, 0, 1, 1, 1, 1);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /sunbathe [1-18]");
	}
	return 1;
}

CMD:lowrider(playerid, params[])
{
    if(!CanPlayerVehAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} This animation requires you to be inside a vehicle.");
	if(IsCLowrider(GetPlayerVehicleID(playerid)))
	{
		switch(strval(params))
		{
		case 1: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_bdbnce", 4.1, 0, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_hair", 4.1, 0, 1, 1, 1, 1);
		case 3: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_hurry", 4.1, 0, 1, 1, 1, 1);
		case 4: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_idleloop", 4.1, 0, 1, 1, 1, 1);
		case 5: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_idle_to_l0", 4.1, 0, 1, 1, 1, 1);
		case 6: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l0_bnce", 4.1, 0, 1, 1, 1, 1);
		case 7: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l0_loop", 4.1, 0, 1, 1, 1, 1);
		case 8: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l0_to_l1", 4.1, 0, 1, 1, 1, 1);
		case 9: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l12_to_l0", 4.1, 0, 1, 1, 1, 1);
		case 10: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l1_bnce", 4.1, 0, 1, 1, 1, 1);
		case 11: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l1_loop", 4.1, 0, 1, 1, 1, 1);
		case 12: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l1_to_l2", 4.1, 0, 1, 1, 1, 1);
		case 13: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l2_bnce", 4.1, 0, 1, 1, 1, 1);
		case 14: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l2_loop", 4.1, 0, 1, 1, 1, 1);
		case 15: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l2_to_l3", 4.1, 0, 1, 1, 1, 1);
		case 16: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l345_to_l1", 4.1, 0, 1, 1, 1, 1);
		case 17: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l3_bnce", 4.1, 0, 1, 1, 1, 1);
		case 18: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l3_loop", 4.1, 0, 1, 1, 1, 1);
		case 19: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l3_to_l4", 4.1, 0, 1, 1, 1, 1);
		case 20: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l4_bnce", 4.1, 0, 1, 1, 1, 1);
		case 21: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l4_loop", 4.1, 0, 1, 1, 1, 1);
		case 22: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l4_to_l5", 4.1, 0, 1, 1, 1, 1);
		case 23: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l5_bnce", 4.1, 0, 1, 1, 1, 1);
		case 24: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l5_loop", 4.1, 0, 1, 1, 1, 1);
		case 25: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkB", 4.1, 0, 1, 1, 1, 1);
		case 26: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkC", 4.1, 0, 1, 1, 1, 1);
		case 27: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkD", 4.1, 0, 1, 1, 1, 1);
		case 28: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkE", 4.1, 0, 1, 1, 1, 1);
		case 29: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkF", 4.1, 0, 1, 1, 1, 1);
		case 30: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkG", 4.1, 0, 1, 1, 1, 1);
		case 31: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkH", 4.1, 0, 1, 1, 1, 1);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /lowrider [1-31]");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} This animation requires you to be in a convertible lowrider.");
	}
	return 1;
}

CMD:carchat(playerid, params[])
{
    if(!CanPlayerVehAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} This animation requires you to be inside a vehicle.");
	switch(strval(params))
	{
	case 1: ApplyAnimationEx(playerid, "CAR_CHAT", "carfone_in", 4.1, 0, 1, 1, 1, 1);
	case 2: ApplyAnimationEx(playerid, "CAR_CHAT", "carfone_loopA", 4.1, 0, 1, 1, 1, 1);
	case 3: ApplyAnimationEx(playerid, "CAR_CHAT", "carfone_loopA_to_B", 4.1, 0, 1, 1, 1, 1);
	case 4: ApplyAnimationEx(playerid, "CAR_CHAT", "carfone_loopB", 4.1, 0, 1, 1, 1, 1);
	case 5: ApplyAnimationEx(playerid, "CAR_CHAT", "carfone_loopB_to_A", 4.1, 0, 1, 1, 1, 1);
	case 6: ApplyAnimationEx(playerid, "CAR_CHAT", "carfone_out", 4.1, 0, 1, 1, 1, 1);
	case 7: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc1_BL", 4.1, 0, 1, 1, 1, 1);
	case 8: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc1_BR", 4.1, 0, 1, 1, 1, 1);
	case 9: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc1_FL", 4.1, 0, 1, 1, 1, 1);
	case 10: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc1_FR", 4.1, 0, 1, 1, 1, 1);
	case 11: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc2_FL", 4.1, 0, 1, 1, 1, 1);
	case 12: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc3_BR", 4.1, 0, 1, 1, 1, 1);
	case 13: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc3_FL", 4.1, 0, 1, 1, 1, 1);
	case 14: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc3_FR", 4.1, 0, 1, 1, 1, 1);
	case 15: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc4_BL", 4.1, 0, 1, 1, 1, 1);
	case 16: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc4_BR", 4.1, 0, 1, 1, 1, 1);
	case 17: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc4_FL", 4.1, 0, 1, 1, 1, 1);
	case 18: ApplyAnimationEx(playerid, "CAR_CHAT", "CAR_Sc4_FR", 4.1, 0, 1, 1, 1, 1);
	case 19: ApplyAnimationEx(playerid, "CAR", "Sit_relaxed", 4.1, 0, 1, 1, 1, 1);
	//case 20: ApplyAnimationEx(playerid, "CAR", "Tap_hand", 4.1, 1, 0, 0, 0, 0);
	default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /carchat [1-19]");
	}
	return 1;
}

// New anims
CMD:point(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "ON_LOOKERS", "panic_point", 4.1, 0, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "ON_LOOKERS", "point_loop", 4.1, 1, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /point [1-2]");
	}

	return 1;
}
CMD:tired(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "PED", "IDLE_tired", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "FAT", "IDLE_tired", 4.1, 1, 0, 0, 0, 0);
	    default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /tired [1-2]");
	}

	return 1;
}


CMD:injured(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "SWAT", "gnstwall_injurd", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "SWEET", "Sweet_injuredloop", 4.1, 1, 0, 0, 0, 0);
	    default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /injured [1-2]");
	}

	return 1;
}

CMD:aim(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "SHOP", "ROB_loop", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "PED", "ARRESTgun", 4.1, 0, 0, 0, 1, 0);
	    default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /aim [1-2]");
	}

	return 1;
}

CMD:dodge(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	ApplyAnimationEx(playerid, "DODGE", "Crush_Jump", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:scratch(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	ApplyAnimationEx(playerid, "MISC", "Scratchballs_01", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:what(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid)) return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");

	ApplyAnimationEx(playerid, "RIOT", "RIOT_ANGRY", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:wash(playerid)
	return callcmd::washhands(playerid);

CMD:come(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	ApplyAnimationEx(playerid, "WUZI", "Wuzi_follow", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:hitch(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	ApplyAnimationEx(playerid, "MISC", "Hiker_Pose", 4.1, 0, 0, 0, 1, 0);
	return 1;
}
CMD:shifty(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	ApplyAnimationEx(playerid, "SHOP", "ROB_Shifty", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:traffic(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Stop", 4.1, 0, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Come", 4.1, 0, 0, 0, 0, 0);
	    default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /traffic [1-2]");
	}

	return 1;
}

CMD:ghands(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "GHANDS", "gsign1", 4.1, 0, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "GHANDS", "gsign1LH", 4.1, 0, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "GHANDS", "gsign2", 4.1, 0, 0, 0, 0, 0);
		case 4: ApplyAnimationEx(playerid, "GHANDS", "gsign2LH", 4.1, 0, 0, 0, 0, 0);
		case 5: ApplyAnimationEx(playerid, "GHANDS", "gsign3", 4.1, 0, 0, 0, 0, 0);
        case 6: ApplyAnimationEx(playerid, "GHANDS", "gsign3LH", 4.1, 0, 0, 0, 0, 0);
		case 7: ApplyAnimationEx(playerid, "GHANDS", "gsign4", 4.1, 0, 0, 0, 0, 0);
		case 8: ApplyAnimationEx(playerid, "GHANDS", "gsign4LH", 4.1, 0, 0, 0, 0, 0);
		case 9: ApplyAnimationEx(playerid, "GHANDS", "gsign5", 4.1, 0, 0, 0, 0, 0);
		case 10: ApplyAnimationEx(playerid, "GHANDS", "gsign5LH", 4.1, 0, 0, 0, 0, 0);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /ghands [1-10]");
	}

	return 1;
}

CMD:walk(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "PED", "WALK_gang1", 4.1, 1, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "PED", "WALK_gang2", 4.1, 1, 1, 1, 1, 1);
		case 3: ApplyAnimationEx(playerid, "PED", "WALK_civi", 4.1, 1, 1, 1, 1, 1);
		case 4: ApplyAnimationEx(playerid, "PED", "WALK_armed", 4.1, 1, 1, 1, 1, 1);
		case 5: ApplyAnimationEx(playerid, "PED", "WALK_fat", 4.1, 1, 1, 1, 1, 1);
        case 6: ApplyAnimationEx(playerid, "PED", "WALK_fatold", 4.1, 1, 1, 1, 1, 1);
		case 7: ApplyAnimationEx(playerid, "PED", "WALK_old", 4.1, 1, 1, 1, 1, 1);
		case 8: ApplyAnimationEx(playerid, "PED", "WALK_player", 4.1, 1, 1, 1, 1, 1);
		case 9: ApplyAnimationEx(playerid, "PED", "WALK_shuffle", 4.1, 1, 1, 1, 1, 1);
		case 10: ApplyAnimationEx(playerid, "PED", "WALK_Wuzi", 4.1, 1, 1, 1, 1, 1);
		case 11: ApplyAnimationEx(playerid, "PED", "WOMAN_walkbusy", 4.1, 1, 1, 1, 1, 1);
		case 12: ApplyAnimationEx(playerid, "PED", "WOMAN_walkfatold", 4.1, 1, 1, 1, 1, 1);
		case 13: ApplyAnimationEx(playerid, "PED", "WOMAN_walknorm", 4.1, 1, 1, 1, 1, 1);
		case 14: ApplyAnimationEx(playerid, "PED", "WOMAN_walksexy", 4.1, 1, 1, 1, 1, 1);
		case 15: ApplyAnimationEx(playerid, "PED", "WOMAN_walkpro", 4.1, 1, 1, 1, 1, 1);
		default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /walk [1-15]");
	}

	return 1;
}

CMD:fuckme(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "SNM", "SPANKING_IDLEW", 4.1, 0, 1, 1, 1, 0);
		case 2: ApplyAnimationEx(playerid, "SNM", "SPANKING_IDLEP", 4.1, 0, 1, 1, 1, 0);
		case 3: ApplyAnimationEx(playerid, "SNM", "SPANKINGW", 4.1, 0, 1, 1, 1, 0);
		case 4: ApplyAnimationEx(playerid, "SNM", "SPANKINGP", 4.1, 0, 1, 1, 1, 0);
		case 5: ApplyAnimationEx(playerid, "SNM", "SPANKEDW", 4.1, 0, 1, 1, 1, 0);
		case 6: ApplyAnimationEx(playerid, "SNM", "SPANKEDP", 4.1, 0, 1, 1, 1, 0);
		case 7: ApplyAnimationEx(playerid, "SNM", "SPANKING_ENDW", 4.1, 0, 1, 1, 1, 0);
		case 8: ApplyAnimationEx(playerid, "SNM", "SPANKING_ENDP", 4.1, 0, 1, 1, 1, 0);
        default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /fuckme [1-8]");
	}

	return 1;
}

CMD:bj(playerid, params[])
{
    if(!CanPlayerUseAnims(playerid))
	{
	    return SendClientMessage(playerid, COLOR_ERROR, "[ERROR]{ffffff} You're currently unable to use animations at this moment.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_START_P", 4.1, 0, 1, 1, 1, 0);
		case 2: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_START_W", 4.1, 0, 1, 1, 1, 0);
		case 3: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_LOOP_P", 4.1, 0, 1, 1, 1, 0);
		case 4: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_LOOP_W", 4.1, 0, 1, 1, 1, 0);
		case 5: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_END_P", 4.1, 0, 1, 1, 1, 0);
		case 6: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_END_W", 4.1, 0, 1, 1, 1, 0);
		case 7: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_START_P", 4.1, 0, 1, 1, 1, 0);
		case 8: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_START_W", 4.1, 0, 1, 1, 1, 0);
		case 9: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_LOOP_P", 4.1, 1, 0, 0, 0, 0);
		case 10: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_LOOP_W", 4.1, 1, 0, 0, 0, 0);
		case 11: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_END_P", 4.1, 0, 1, 1, 1, 0);
		case 12: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_END_W", 4.1, 0, 1, 1, 1, 0);
        default: SendClientMessage(playerid, SERVER_COLOR, "[USAGE]{ffffff} /bj [1-12]");
	}

	return 1;
}
