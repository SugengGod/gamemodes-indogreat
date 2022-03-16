/*
    SA-MP DNS Plugin v2.4
    Copyright © 2010 Incognito

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _dns_included
	#endinput
#endif
#define _dns_included
#pragma library dns

// Natives

native dns(const host[], extra = 0);
native rdns(const ip[], extra = 0);

// Callbacks

forward OnDNS(host[], ip[], extra);
forward OnReverseDNS(ip[], host[], extra);

// Stock Function

stock
	GetPlayerHost(playerid)
{
	new
		ip[16];
	GetPlayerIp(playerid, ip, sizeof(ip));
	rdns(ip, playerid);
	return 1;
}
