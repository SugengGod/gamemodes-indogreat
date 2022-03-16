#include <a_samp>

#define MAX_CUSTOM_MENUS 	64
#define MAX_MENU_ITEMS      24

enum custom_menu_enum
{
	menuTitle[64],
 	Float:menuX,
 	Float:menuY,
	Text:menuTD
};

new stock CustomMenuEnum[MAX_CUSTOM_MENUS + 1][custom_menu_enum];
new stock CustomMenuItems[MAX_CUSTOM_MENUS + 1][MAX_MENU_ITEMS + 1][32];
new stock Text:CustomMenuItemTextdraw[MAX_CUSTOM_MENUS + 1][MAX_MENU_ITEMS + 1];
new stock CustomMenuItemCount[MAX_CUSTOM_MENUS + 1];
new stock Float:CustomMenuY[MAX_CUSTOM_MENUS + 1];
new stock CustomMenuCount;

new stock MenuItemHandle[MAX_PLAYERS];
new stock MenuHandle[MAX_PLAYERS];

forward MenuUpdate(playerid, menuid);
forward OnPlayerSelectMenuItem(playerid, menuid, itemid);

stock CreateCustomMenu(title[], Float:x, Float:y, color = -1347440641)
{
	if (CustomMenuCount == MAX_CUSTOM_MENUS)
	    return printf("The menu limit of %d has been reached. Please raise MAX_CUSTOM_MENUS to a higher number.", MAX_CUSTOM_MENUS);
	
	CustomMenuCount += 1;
	
    CustomMenuEnum[CustomMenuCount][menuTD] = TextDrawCreate(x, y, title);
	TextDrawBackgroundColor(CustomMenuEnum[CustomMenuCount][menuTD], 255);
	TextDrawFont(CustomMenuEnum[CustomMenuCount][menuTD], 3);
	TextDrawLetterSize(CustomMenuEnum[CustomMenuCount][menuTD], 0.430, 1.5);
	TextDrawColor(CustomMenuEnum[CustomMenuCount][menuTD], -1);
	TextDrawSetOutline(CustomMenuEnum[CustomMenuCount][menuTD], 1);
	TextDrawSetProportional(CustomMenuEnum[CustomMenuCount][menuTD], 1);
	TextDrawUseBox(CustomMenuEnum[CustomMenuCount][menuTD], 1);
	TextDrawBoxColor(CustomMenuEnum[CustomMenuCount][menuTD], color);
	TextDrawTextSize(CustomMenuEnum[CustomMenuCount][menuTD], 444.0, 0.0);

	format(CustomMenuEnum[CustomMenuCount][menuTitle], 64, title);
	CustomMenuEnum[CustomMenuCount][menuX] = x;
	CustomMenuEnum[CustomMenuCount][menuY] = y;
	CustomMenuY[CustomMenuCount] = 138.0;
	return CustomMenuCount;
}

stock AddCustomMenuItem(menuid, itemname[], color = -1347440641)
{
    if (CustomMenuItemCount[menuid] == MAX_MENU_ITEMS)
	    return printf("The menu item limit of %d has been reached. Please raise MAX_MENU_ITEMS to a higher number.", MAX_MENU_ITEMS);
	    
	CustomMenuItemCount[menuid] += 1;
	CustomMenuY[menuid] += 15.0;
	
    CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]] = TextDrawCreate(CustomMenuEnum[menuid][menuX], CustomMenuY[menuid], itemname);
	TextDrawBackgroundColor(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], 255);
	TextDrawFont(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], 1);
	TextDrawLetterSize(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], 0.469, 1.50);
	TextDrawColor(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], -1);
	TextDrawSetOutline(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], 1);
	TextDrawSetProportional(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], 1);
	TextDrawUseBox(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], 1);
	TextDrawBoxColor(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], color);
	TextDrawTextSize(CustomMenuItemTextdraw[menuid][CustomMenuItemCount[menuid]], 444.0, 0.0);
	
	format(CustomMenuItems[menuid][CustomMenuItemCount[menuid]], 32, itemname);
	return 1;
}

stock ShowPlayerCustomMenu(playerid, menuid)
{
	if (MenuHandle[playerid]) HidePlayerCustomMenu(playerid);
	TextDrawShowForPlayer(playerid, CustomMenuEnum[menuid][menuTD]);
	for (new i = 1; i <= CustomMenuItemCount[menuid]; i += 1)
	{
 		if (i == 1)
		{
  			TextDrawColor(CustomMenuItemTextdraw[menuid][i], 286392319);
		}
		else
		{
  			TextDrawColor(CustomMenuItemTextdraw[menuid][i], -1);
		}
		TextDrawShowForPlayer(playerid, CustomMenuItemTextdraw[menuid][i]);
	}
	MenuItemHandle[playerid] = 1;
	MenuHandle[playerid] = menuid;
	TogglePlayerControllable(playerid, 0);
	return 1;
}

stock DestroyCustomMenu(menuid)
{
	for (new i = 0; i < MAX_PLAYERS; i += 1)
	{
	    if (MenuHandle[i] == menuid)
	    {
			HidePlayerCustomMenu(i);
		}
	}
	TextDrawDestroy(CustomMenuEnum[menuid][menuTD]);
	for (new i = 1; i <= CustomMenuItemCount[menuid]; i += 1)
	{
	    TextDrawDestroy(CustomMenuItemTextdraw[menuid][i]);
	}
	CustomMenuItemCount[menuid] = 0;
	CustomMenuCount -= 1;
	return 1;
}

stock menu_OnPlayerUpdate(playerid)
{
    new
	    keys,
	    updown,
	    leftright;

	GetPlayerKeys(playerid, keys, updown, leftright);

	if (updown > 0)
	{
	    if (MenuItemHandle[playerid] == CustomMenuItemCount[MenuHandle[playerid]]) return 1;
	    if (keys & KEY_SECONDARY_ATTACK) return 1;
	    MenuItemHandle[playerid] += 1;
	    
		TextDrawHideForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]-1]);
        TextDrawHideForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]]);

		TextDrawColor(CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]-1], -1);
		TextDrawColor(CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]], 286392319);
		
		TextDrawShowForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]-1]);
        TextDrawShowForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]]);
	}
	else if(updown < 0)
	{
	    if (MenuItemHandle[playerid] == 1) return 1;
	    if (keys & KEY_SECONDARY_ATTACK) return 1;
	    MenuItemHandle[playerid] -= 1;

        TextDrawHideForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]+1]);
        TextDrawHideForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]]);

	    TextDrawColor(CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]+1], -1);
	    TextDrawColor(CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]], 286392319);
	    
	    TextDrawShowForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]+1]);
        TextDrawShowForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][MenuItemHandle[playerid]]);
	}
	return 1;
}

stock HidePlayerCustomMenu(playerid)
{
	TextDrawHideForPlayer(playerid, CustomMenuEnum[MenuHandle[playerid]][menuTD]);
	for (new i = 1; i <= CustomMenuItemCount[MenuHandle[playerid]]; i += 1)
	{
		TextDrawHideForPlayer(playerid, CustomMenuItemTextdraw[MenuHandle[playerid]][i]);
	}
	MenuItemHandle[playerid] = 0;
	MenuHandle[playerid] = 0;
	TogglePlayerControllable(playerid, 1);
	return 1;
}

stock menu_OnPlayerDisconnect(playerid)
{
	HidePlayerCustomMenu(playerid);
	return 1;
}

stock menu_OnFilterScriptExit()
{
	for (new i = 1; i <= CustomMenuCount; i += 1)
	{
	    DestroyCustomMenu(i);
	}
	return 1;
}

stock menu_OnGameModeExit()
{
	return menu_OnFilterScriptExit();
}

stock menu_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	#pragma unused oldkeys
	if ((newkeys & KEY_SECONDARY_ATTACK) && (MenuHandle[playerid]))
	{
		if (funcidx("OnPlayerSelectMenuItem") != -1)
		{
		    CallRemoteFunction("OnPlayerSelectMenuItem", "ddd", playerid, MenuHandle[playerid], MenuItemHandle[playerid]);
		}
		return 1;
	}
	return 1;
}

stock GetPlayerMenuID(playerid)
{
	return MenuHandle[playerid];
}

stock GetPlayerItemID(playerid)
{
	return MenuItemHandle[playerid];
}