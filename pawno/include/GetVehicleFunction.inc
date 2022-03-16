/*
Vehicle functions by Mike (MP2)
http://forum.sa-mp.com/showthread.php?t=339088

FEATURES:
- Random vehicle colors (-1 in CreateVehicle) are synced between players
- GetVehicleInterior function
- GetVehicleColor function
- ChangeVehicleColor works with -1 (random) colors
- Siren automatically added to Ladder Firetruck

CHANGELOG:
1.2 (05/05/2015)
- Updated for 0.3.7 (added siren parameter for CreateVehicle and AddStaticVehicleEx
- Removed 'interior' parameter from CreateVehicle/AddStaticVehicleEx to keep in line
	with SA-MP's functions. Use LinkVehicleToInterior or SetVehicleInterior instead.
- Commented out some unfinished code. May get around to finishing it.
- AddStaticVehicle and AddStaticVehicleEx no longer re-direct to CreateVehicle.
	They use their own respective functions
- Using y_hooks again...
- Added GetVehicleSeatCount and GetVehicleModelSeatCount

1.1.3 (10th of February 2013):
- Fixed a bug that caused OnVehicleSpawn to not be called. Caused by another array index out of bounds issue due to me not checking whether a vehicle colour was set to -1 (-1 is an invalid array index).

1.1.2 (7th of February 2013):
- y_hooks no longer used (proper plug-n-play)
- Hooked 'OnVehicleRespray' (reported missing by 'im'

1.1.1 (22nd of January 2013):
- Fixed out of bounds array index issue with vehicle ID 2000.

1.1 (4th of May 2012):
- Removing a paintjob now restores the vehicle's color (fixes SA:MP bug where vehicle became white)
- Added 'GetVehiclePaintjob' function
- Added RemoveVehiclePaintjob (simple macro ('redirect') to ChangeVehiclePaintjob)

1.0 (2nd of May 2012):
- Initial Release

NOTE	This include relies on YSI's y_hooks, which can be found here:
		http://forum.sa-mp.com/showthread.php?t=570884

*/

#include <YSI\y_hooks>

/*
// Fake Natives - Type 'function(' in pawno to show syntax pop-up
native SetVehicleInterior(vehicleid, interior);
native GetVehicleInterior(vehicleid);
native GetVehicleColor(vehicleid, &color1, &color2);
native GetVehicleColour(vehicleid, &color1, &color2);
native GetVehicleColours(vehicleid, &color1, &color2);
native GetVehicleColors(vehicleid, &color1, &color2);
native GetVehiclePaintjob(vehicleid);

native IsVehicleModelAircraft(modelid);
native IsVehicleAircraft(vehicleid);

native GetVehicleModelType(modelid);
native GetVehicleType(vehicleid);

native GetVehicleSeatCount(vehicleid);
native GetVehicleModelSeatCount(modelid);

*/

#define VTYPE_ROAD 0
#define VTYPE_BIKE 1
#define VTYPE_PLANE 2
#define VTYPE_HELI 3
#define VTYPE_BOAT 4
#define VTYPE_TRAIN 5

#define VEHICLE_TYPE_ROAD VTYPE_ROAD
#define VEHICLE_TYPE_BIKE VTYPE_BIKE
#define VEHICLE_TYPE_PLANE VTYPE_PLANE
#define VEHICLE_TYPE_HELI VTYPE_HELI
#define VEHICLE_TYPE_BOAT VTYPE_BOAT
#define VEHCLE_TYPE_TRAIN VTYPE_TRAIN

forward OnVehicleCreated(vehicleid);

#if !defined isodd
#define isodd(%1) \
	((%1) & 1)
#endif

new gVehicleColors[][] = {
{4,1, 123,1, 113,1, 101,1, 75,1, 62,1, 40,1, 36,1, -1}, // Landstalker
{41,41, 47,47, 52,52, 66,66, 74,74, 87,87,91,91, 113,113, -1}, // Bravura
{10,10, 13,13, 22,22, 30,30, 39,39, 90,90, 98,98, 110,110, -1}, // Buffalo
{36,1, 37,1, 30,1, 28,1, 25,1, 40,1, 101,1, 113,1, -1}, // Linerunner
{113,39, 119,50, 123,92, 109,100, 101,101, 95,105, 83,110, 66,25, -1}, // Perennial
{11,1, 24,1, 36,1, 40,1, 75,1, 91,1, 123,1, 4,1, -1}, // Landstalker
{1,1, -1}, // Dumper
{3,1, -1}, // Firetruck
{26,26, -1}, // Trashmaster
{1,1, -1}, // Stretch
{4,1, 9,1, 10,1, 25,1, 36,1, 40,1, 45,1, 84,1, -1}, // Manana
{12,1, 64,1, 123,1, 116,1, 112,1, 106,1, 80,1, 75,1, -1}, // Infernus
{9,1, 10,8, 11,1, 25,8, 27,1, 29,8, 30,1, 37,8, -1}, // Voodoo
{87,1, 88,1, 91,1, 105,1, 109,1, 119,1, 4,1, 25,1, -1}, // Pony
{25,1, 28,1, 43,1, 67,1, 72,1, 9,1, 95,1, 24,1, -1}, // Mule
{20,1, 25,1, 36,1, 40,1, 62,1, 75,1, 92,1, 0,1, -1}, // Cheetah
{1,3, -1}, // Ambulance
{0,0, -1}, // Leviathan
{119,119, 117,227, 114,114, 108,108, 95,95, 81,81, 61,61, 41,41, -1}, // Moonbeam
{45,75, 47,76, 33,75, 13,76, 54,75, 69,76, 59,75, 87,76, -1}, // Esperanto
{6,1, -1}, // Taxi
{4,1, 13,1, 25,1, 30,1, 36,1, 40,1, 75,1, 95,1, -1}, // Washington
{96,25, 97,25, 101,25, 111,31, 113,36, 83,57, 67,59, -1}, // Bobcat
{1,16, 1,56, 1,17, 1,53, 1,5, 1,35, -1}, // Mr.Whoopie/Mr.Whoopee
{1,0, 2,2, 3,2, 3,6, 6,16, 15,30, 24,53, 35,61, -1}, // BF Injection
{43,0, -1}, // Hunter
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Premier
{0,1, -1}, // Enforcer
{4,75, -1}, // Securicar
{12,12, 13,13, 14,14, 1,2, 2,1, 1,3, 3,1, 10,10, -1}, // Banshee
{46,26, -1}, // Predator
{71,59, 75,59, 92,72, 47,74, 55,83, 59,83, 71,87, 82,87, -1}, // Bus
{43,0, -1}, // Rhino
{43,0, -1}, // Barracks
{1,1, 12,12, 2,2, 6,6, 4,4, 46,46, 53,53, -1}, // Hotknife
{1, 1, -1}, // Articulated Trailer 1
{83,1, 87,1, 92,1, 95,1, 109,1, 119,45, 11,1, -1}, // Previon
{54,7, 79,7, 87,7, 95,16, 98,20, 105,20, 123,20, 125,21, -1}, // Coach
{6,76, -1}, // Cabbie
{57,8, 8,17, 43,21, 54,38, 67,8, 37,78, 65,79, 25,78, -1}, // Stallion
{34,34, 32,32, 20,20, 110,110, 66,66, 84,84, 118,118, 121,121, -1}, // Rumpo
{2,96, 79,42, 82,54, 67,86, 126,96, 70,96, 110,54, 67,98, -1}, // RC Bandit
{0,0, 11,105, 25,109, 36,0, 40,36, 75,36, 0,36, 0,109, -1}, // Romero
{4,1, 20,1, 24,1, 25,1, 36,1, 40,1, 54,1, 84,1, -1}, // Packer
{32,36, 32,42, 32,53, 32,66, 32,14, 32,32, -1}, // Monster
{34,34, 35,35, 37,37, 39,39, 41,41, 43,43, 45,45, 47,47, -1}, // Admiral
{-1}, // Squallo - 4 colors two of which can not be changed, will not be synced
{75,2, -1}, // Seasparrow
{3,6, -1}, // Pizzaboy
{1,74, -1}, // Tram
{1,1, -1}, // Articulated Trailer 2 [NO COLORS]
{123,123, 125,125, 36,36, 16,16, 18,18, 46,46, 61,61, 75,75, -1}, // Turismo
{1,3, 1,5, 1,16, 1,22, 1,35, 1,44, 1,53, 1,57, -1}, // Speeder
{56,56, -1}, // Reefer
{26,26, -1}, // Tropic
{84,15, 84,58, 84,31, 32,74, 43,31, 1,31, 77,31, 32,74, -1}, // Flatbed
{84,63, 91,63, 102,65, 105,72, 110,93, 121,93, 12,95, 23,1, -1}, // Yankee
{58,1, 2,1, 63,1, 18,1, 32,1, 45,1, 13,1, 34,1, -1}, // Caddy
{91,1, 101,1, 109,1, 113,1, 4,1, 25,1, 30,1, 36,1, -1}, // Solair
{26,26, 28,28, 44,44, 51,51, 57,57, 72,72, 106,106, 112,112, -1}, // Berkley's RC Van (Topfun)
{1,3, 1,9, 1,18, 1,30, 17,23, 46,23, 46,32, 57,34, -1}, // Skimmer
{36,1, 37,1, 43,1, 53,1, 61,1, 75,1, 79,1, 88,1, -1}, // PCJ-600
{12,12, 13,13, 14,14, 1,2, 2,1, 1,3, 3,1, 10,10, -1}, // Faggio
{79,79, 84,84, 7,7, 11,11, 19,19, 22,22, 36,36, 53,53, -1}, // Freeway
{14,75, -1}, // RC Baron
{14,75, -1}, // RC Raider
{67,76, 68,76, 78,76, 2,76, 16,76, 18,76, 25,76, 45,88, -1}, // Glendale
{51,1, 58,8, 60,1, 68,8, 2,1, 13,8, 22,1, 36,8, -1}, // Oceanic
{6,6, 46,46, 53,53, 3,3, -1}, // Sanchez
{1,3, -1}, // Sparrow
{43,0, -1}, // Patriot
{120,117, 103,111, 120,114, 74,91, 120,112, 74,83, 120,113, 66,71, -1}, // Quad
{56,15, 56,53, -1}, // Coastguard
{56,15, 56,53, -1}, // Dinghy
{97,1, 81,1, 105,1, 110,1, 91,1, 74,1, 84,1, 83,1, -1}, // Hermes
{2,39, 9,39, 17,1, 21,1, 33,0, 37,0, 41,29, 56,29, -1}, // Sabre
{6,7, 7,6, 1,6, 89,91, 119,117, 103,102, 77,87, 71,77, -1}, // Rustler
{92,1, 94,1, 101,1, 121,1, 0,1, 22,1, 36,1, 75,1, -1}, // ZR-350
{72,1, 66,1, 59,1, 45,1, 40,1, 39,1, 35,1, 20,1, -1}, // Walton
{27,36, 59,36, 60,35, 55,41, 54,31, 49,23, 45,32, 40,29, -1}, // Regina
{73,45, 12,12, 2,2, 6,6, 4,4, 46,46, 53,53, -1}, // Comet
{1,1, 3,3, 6,6, 46,46, 65,9, 14,1, 12,9, 26,1, -1}, // BMX
{41,41, 48,48, 52,52, 64,64, 71,71, 85,85, 10,10, 62,62, -1}, // Burrito
{-1}, // Camper [4 colors - can not be synced]
{12,35, 50,32, 40,26, 66,36, -1}, // Marquis
{1,73, 1,74, 1,75, 1,76, 1,77, 1,78, 1,79, -1}, // Baggage
{1,1, -1}, // Dozer
{26,14, 29,42, 26,57, 54,29, 26,3, 3,29, 12,39, 74,35, -1}, // Maverick
{2,26, 2,29, -1}, // News Macerick/News Helicopter
{13,118, 14,123, 120,123, 112,120, 84,110, 76,102, -1}, // Rancher
{0,0, -1}, // FBI Rancher
{40,65, 71,72, 52,66, 64,72, 30,72, 60,72, -1}, // Virgo
{30,26, 77,26, 81,27, 24,55, 28,56, 49,59, 52,69, 71,107, -1}, // Greenwood
{36,13, -1}, // Jetmax
{36,117, 36,13, 42,30, 42,33, 54,36, 75,79, 92,101, 98,109, -1}, // Hotring Racer
{123,124, 119,122, 118,117, 116,115, 114,108, 101,106, 88,99, 5,6, -1}, // Sandking
{74,72, 66,72, 53,56, 37,19, 22,22, 20,20, 9,14, 0,0, -1}, // Blista Compact
{0,1, -1}, // Police Maverick/Police Helicopter
{11,123, 13,120, 20,117, 24,112, 27,107, 36,105, 37,107, 43,93, -1}, // Boxville
{109,25, 109,32, 112,32, 10,32, 30,44, 32,52, 84,66, 84,69, -1}, // Benson
{75,84, 40,84, 40,110, 28,119, 25,119, 21,119, 13,119, 4,119, -1}, // Mesa
{14,75, -1}, // RC Goblin
{7,94, 36,88, 51,75, 53,75 ,58,67, 75,67, 75,61, 79,62, -1}, // Hotring Racer A
{83,66, 87,74, 87,75, 98,83, 101,100, 103,101, 117,116, 123,36, -1}, // Hotring Racer B
{51,39, 57,38, 45,29, 34,9, 65,9, 14,1, 12,9, 26,1, -1}, // Bloodring Banger
{13,118, 14,123, 120,123, 112,120, 84,110, 76,102, -1}, // Rancher (LURE)
{3,3, 6,6, 7,7, 52,52, 76,76, -1}, // Super GT
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Elegant
{1,1, -1}, // Journey
{7,1, 74,1, 61,1, 16,1, 25,1, 30,1, 36,1, 53,1, -1}, // Bike
{43,43, 46,46, 39,39, 28,28, 16,16, 6,6, 5,5, 2,2, -1}, // Mountain Bike
{3,90, 4,90, 7,68, 8,66, 12,60, 27,97, 34,51, 37,51, -1}, // Beagle
{17,39, 15,123, 32,112, 45,88, 52,71, 57,67, 61,96, 96,96, -1}, // Cropduster
{38,51, 21,36, 21,34, 30,34, 54,34, 55,20, 48,18, 51,6, -1}, // Stuntplane
{10,1, 25,1, 28,1, 36,1, 40,1, 54,1, 75,1, 113,1, -1}, // Tanker
{13,76, 24,77, 63,78, 42,76, 54,77, 39,78, 11,76, 62,77, -1}, // Roadtrain
{116,1, 119,1, 122,1, 4,1, 9,1, 24,1, 27,1, 36,1, -1}, // Nebula
{37,36, 36,36, 40,36, 43,41, 47,41, 51,72, 54,75, 55,84, -1}, // Majestic
{2,39, 9,39, 17,1, 21,1, 33,0, 37,0, 41,29, 56,29, -1}, // Buccaneer
{1,1, -1}, // Shamal
{-1}, // Hydra [NO DATA FOUND]
{74,74, 75,13, 87,118, 92,3, 115,118, 25,118, 36,0, 118,118, -1}, // FCR-900
{3,3, 3,8, 6,25, 7,79, 8,82, 36,105, 39,106, 51,118, -1}, // NRG-500
{-1}, // Cop Bike [NO DATA FOUND]
{-1}, // Cement [4 colors - not synced]
{1,1, 17,20, 18,20, 22,30, 36,43, 44,51, 52,54, -1}, // Towtruck
{2,39, 9,39, 17,1, 21,1, 33,0, 37,0, 41,29, 56,29, -1}, // Fortune
{52,1, 53,1, 66,1, 75,1, 76,1, 81,1, 95,1, 109,1, -1}, // Cadrona
{-1}, // FBI Truck [ NO DATA FOUND]
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Willard
{110,1, 111,1, 112,1, 114,1, 119,1, 122,1, 4,1, 13,1, -1}, // Forklift
{2,35, 36,2, 51,53, 91,2, 11,22, 40,35, -1}, // Tractor
{-1}, // Combine [NO DATA FOUND]
{73,1, 74,1, 75,1, 77,1, 79,1, 83,1, 84,1, 91,1, -1}, // Feltzer
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Remington
{3,1, 28,1, 31,1, 55,1, 66,1, 97,1, 123,1, 118,1, -1}, // Slamvan
{9,1, 12,1, 26,96, 30,96, 32,1, 37,1, 57,96, 71,96, -1}, // Blade
{1,1, -1}, // Freight
{1,1, -1}, // Streak
{96,67, 86,70, 79,74, 70,86, 61,98, 75,75, 75,91, -1}, // Vortex
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Vincent
{51,1, 58,8, 60,1, 68,8, 2,1, 13,8, 22,1, 36,8, -1}, // Bullet
{13,118, 24,118, 31,93, 32,92, 45,92, 113,92, 119,113, 122,113, -1}, // Clover
{76,8, 32,8, 43,8, 67,8, 11,11, 8,90, 2,2, 83,13, -1}, // Sadler
{3,1, -1}, // Firetruck LA (Ladder Truck)
{50,1, 47,1, 44,96, 40,96, 39,1, 30,1, 28,96, 9,96, -1}, // Hustler
{62,37, 78,38, 2,62, 3,87, 2,78, 113,78, 119,62, 7,78, -1}, // Intruder
{122,1, 123,1, 125,1, 10,1, 24,1, 37,1, 55,1, 66,1, -1}, // Primo
{1,1, -1}, // Cargobob
{74,39, 72,39, 75,39, 79,39, 83,36, 84,36, 89,35, 91,35, -1}, // Tampa
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Sunrise
{67,1, 72,1, 75,1, 83,1, 91,1, 101,1, 109,1, 20,1, -1}, // Merit
{56,56, 49,49, 26,124, -1}, // Utility
{38,9, 55,23, 61,74, 71,87, 91,87, 98,114, 102,119, 111,3, -1}, // Nevada
{53,32, 15,32, 45,32, 34,30, 65,32, 14,32, 12,32, 43,32, -1}, // Yosemite
{51,1, 58,1, 60,1, 68,1, 2,1, 13,1, 22,1, 36,1, -1}, // Windsor
{1,1, -1}, // Monster A
{1,1, -1}, // Monster B
{112,1, 116,1, 117,1, 24,1, 30,1, 35,1, 36,1, 40,1, -1}, // Uranus
{51,1, 58,8, 60,1, 68,8, 2,1, 13,8, 22,1, 36,8, -1}, // Jester
{52,39, 9,39, 17,1, 21,1, 33,0, 37,0, 41,29, 56,29, -1}, // Sultan
{57,8, 8,17, 43,21, 54,38, 67,8, 37,78, 65,79, 25,78, -1}, // Stratum
{36,1, 35,1, 17,1, 11,1, 116,1, 113,1, 101,1, 92,1, -1}, // Elegy
{1,6, -1}, // Raindance
{-1}, // RC Tiger [NO DATA FOUND]
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Flash
{109,1, 30,8, 95,1, 84,8, 83,1, 72,8, 71,1, 52,8, -1}, // Tahoma
{97,96, 88,64, 90,96, 93,64, 97,96, 99,81, 102,114, 114,1, -1}, // Savanna
{2,39, 9,39, 17,1, 21,1, 33,0, 37,0, 41,29, 56,29, -1}, // Bandito
{1,1, -1}, // Freight Flat Carriage
{1,1, -1}, // Streak Carriage
{2,35, 36,2, 51,53, 91,2, 11,22, 40,35, -1}, // Kart
{94,1, 101,1, 116,1, 117,1, 4,1, 25,1, 30,1, 37,1, -1}, // Mower
{91,38, 115,43, 85,6, 79,7, 78,8, 77,18, 79,18, 86,24, -1}, // Duneride
{26,26, -1}, // Sweeper
{12,1, 19,96, 31,64, 25,96, 38,1, 51,96, 57,1, 66,96, -1}, // Broadway
{67,1, 68,96, 72,1, 74,8, 75,96, 76,8, 79,1, 84,96, -1}, // Tornado
{1,3, 8,7, 8,10, 8,16, 23,31, 40,44, -1}, // AT-400
{1,1, -1}, // DFT-30
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Huntley
{92,92, 81,81, 67,67, 66,66, 61,61, 53,53, 51,51, 47,47, 43,43, -1}, // Stafford
{54,1, 58,1, 66,1, 72,1, 75,1, 87,1, 101,1, 36,1, -1}, // BF-400
{41,10, 41,20, 49,11, 56,123, 110,113, 112,116, 114,118, 119,101, -1}, // Newsvan/news Van
{1,1, -1}, // Tug
{1,1, -1}, // Petrol Trailer
{37,37, 42,42, 53,53, 62,62, 7,7, 10,10, 11,11, 15,15, -1}, // Emperor
{119,1, 122,1, 8,1, 10,1, 13,1, 25,1, 27,1, 32,1, -1}, // Wayfarer
{36,1, 40,1, 43,1, 53,1, 72,1, 75,1, 95,1, 101,1, -1}, // Euros
{1,1, -1}, // Hotdog
{37,37, 31,31, 23,23, 22,22, 7,7, 124,124, 114,114, 112,112, -1}, // Club
{-1}, // Freight Box Carriage [NO DATA FOUND]
{1,1, -1}, // Articulated Trailer 3
{1,1, -1}, // Andromada
{51,1, 58,8, 60,1, 68,8, 2,1, 13,8, 22,1, 36,8, -1}, // Dodo
{-1}, // RC Cam [NO DATA FOUND]
{112,20, -1}, // Launch
{0,1, -1}, // Cop Car LSPD
{0,1, -1}, // Cop Car SFPD
{0,1, -1}, // Cop Car LVPD
{0,1, -1}, // Cop Car Ranger (Police Ranger)
{81,8, 32,8, 43,8, 67,8, 11,11, 8,90, 2,2, 83,13, -1}, // Picador
{1,1, -1}, // Swatvan S.W.A.T Van
{58,1, 69,1, 75,77, 18,1, 32,1, 45,45, 13,1, 34,1, -1}, // Alpha
{58,1, 69,1, 75,77, 18,1, 32,1, 45,45, 13,1, 34,1, -1}, // Phoenix
{67,76, 68,76, 78,76, 2,76, 16,76, 18,76, 25,76, 45,88, -1}, // Glendale Shit
{61,8, 32,8, 43,8, 67,8, 11,11, 8,90, 2,2, 83,13, -1}, // Sadler Shit
{-1}, // Baggage Box A [NO DATA FOUND]
{-1}, // Baggage Box B [NO DATA FOUND]
{1,1, -1}, // Tug Stairs
{36,36, -1}, // Burglary Boxville
{-1}, // Farm Plow Trailer [NO DATA FOUND]
{-1} // Utility Trailer [NO DATA FOUND]
};

new stock const VFUNC_vTypeArray[] = {
VTYPE_ROAD, // Landstalker
VTYPE_ROAD, // Bravura
VTYPE_ROAD, // Buffalo
VTYPE_ROAD, // Linerunner
VTYPE_ROAD, // Perenniel
VTYPE_ROAD, // Sentinel
VTYPE_ROAD, // Dumper
VTYPE_ROAD, // Firetruck
VTYPE_ROAD, // Trashmaster
VTYPE_ROAD, // Stretch
VTYPE_ROAD, // Manana
VTYPE_ROAD, // Infernus
VTYPE_ROAD, // Voodoo
VTYPE_ROAD, // Pony
VTYPE_ROAD, // Mule
VTYPE_ROAD, // Cheetah
VTYPE_ROAD, // Ambulance
VTYPE_HELI, // Leviathan
VTYPE_ROAD, // Moonbeam
VTYPE_ROAD, // Esperanto
VTYPE_ROAD, // Taxi
VTYPE_ROAD, // Washington
VTYPE_ROAD, // Bobcat
VTYPE_ROAD, // Mr Whoopee (Ice-Cream Truck)
VTYPE_ROAD, // BF Injection
VTYPE_HELI, // Hunter
VTYPE_ROAD, // Permier
VTYPE_ROAD, // Enforcer
VTYPE_ROAD, // Securicar
VTYPE_ROAD, // Banshee
VTYPE_BOAT, // Predator
VTYPE_ROAD, // Bus
VTYPE_ROAD, // Rhino
VTYPE_ROAD, // Barracks
VTYPE_ROAD, // Hotknife
VTYPE_ROAD, // Articulated Trailer 1
VTYPE_ROAD, // Previon
VTYPE_ROAD, // Coach
VTYPE_ROAD, // Cab
VTYPE_ROAD, // Stallion
VTYPE_ROAD, // Rumpo
VTYPE_ROAD, // RC Bandit
VTYPE_ROAD, // Romero
VTYPE_ROAD, // Packer
VTYPE_ROAD, // Monster
VTYPE_ROAD, // Admiral
VTYPE_BOAT, // Squallo
VTYPE_HELI, // Seasparrow
VTYPE_BIKE, // Pizzaboy
VTYPE_ROAD, // Tram
VTYPE_ROAD, // Art Trailer 2
VTYPE_ROAD, // Turismo
VTYPE_BOAT, // Speeder
VTYPE_BOAT, // Reefer
VTYPE_BOAT, // Tropic
VTYPE_ROAD, // Flatbed
VTYPE_ROAD, // Yankee
VTYPE_ROAD, // Caddy
VTYPE_ROAD, // Solair
VTYPE_ROAD, // Topfun
VTYPE_PLANE, // Skimmer
VTYPE_BIKE, // PCJ-600
VTYPE_BIKE, // Faggio
VTYPE_BIKE, // Freeway
VTYPE_PLANE, // RC Baron
VTYPE_HELI, // RC Raider
VTYPE_ROAD, // Glendale
VTYPE_ROAD, // Oceanic
VTYPE_BIKE, // Sanchez
VTYPE_HELI, // Sparrow
VTYPE_ROAD, // Patriot
VTYPE_ROAD, // Quad
VTYPE_BOAT, // Coastguard
VTYPE_BOAT, // Dinghy
VTYPE_ROAD, // Hermes
VTYPE_ROAD, // Sasbre
VTYPE_PLANE, // Rustler
VTYPE_ROAD, // ZR-350
VTYPE_ROAD, // Walton
VTYPE_ROAD, // Regina
VTYPE_ROAD, // Comet
VTYPE_BIKE, // BMX
VTYPE_ROAD, // Burrito
VTYPE_ROAD, // Camper
VTYPE_BOAT, // Marquis
VTYPE_ROAD, // Baggage
VTYPE_ROAD, // Dozer
VTYPE_HELI, // Maverick
VTYPE_HELI, // News Heli
VTYPE_ROAD, // Rancher
VTYPE_ROAD, // FBI Rancher
VTYPE_ROAD, // Virgo
VTYPE_ROAD, // Greenwood
VTYPE_BOAT, // Jetmax
VTYPE_ROAD, // Hotring
VTYPE_ROAD, // Sandking
VTYPE_ROAD, // Blista Compact
VTYPE_HELI, // Police Maverick (polmav)
VTYPE_ROAD, // Boxville
VTYPE_ROAD, // Benson
VTYPE_ROAD, // Mesa
VTYPE_HELI, // RC Goblin
VTYPE_ROAD, // Hotring
VTYPE_ROAD, // Hotring
VTYPE_ROAD, // Bloodring Bander
VTYPE_ROAD, // Rancher
VTYPE_ROAD, // Super GT
VTYPE_ROAD, // Elegant
VTYPE_ROAD, // Journey
VTYPE_BIKE, // Bike
VTYPE_BIKE, // Mountain Bike
VTYPE_PLANE, // Beagle
VTYPE_PLANE, // Cropduster
VTYPE_PLANE, // Stuntplane
VTYPE_ROAD, // Tanker
VTYPE_ROAD, // Roadtrain
VTYPE_ROAD, // Nebula
VTYPE_ROAD, // Majestic
VTYPE_ROAD, // Buccaneer
VTYPE_PLANE, // Shamal
VTYPE_PLANE, // Hydra
VTYPE_BIKE, // FCR-900
VTYPE_BIKE, // NRG-500
VTYPE_BIKE, // HPV (Cop Bike)
VTYPE_ROAD, // Cement
VTYPE_ROAD, // Towtruck
VTYPE_ROAD, // Fortune
VTYPE_ROAD, // Cadrona
VTYPE_ROAD, // FBI Truck
VTYPE_ROAD, // Willard
VTYPE_ROAD, // Forklift
VTYPE_ROAD, // Tractor
VTYPE_ROAD, // Combine
VTYPE_ROAD, // Feltzer
VTYPE_ROAD, // Remington
VTYPE_ROAD, // Slamvan
VTYPE_ROAD, // Blade
VTYPE_TRAIN, // Freight
VTYPE_TRAIN, // Brownstreak
VTYPE_ROAD, // Vortex
VTYPE_ROAD, // Vincent
VTYPE_ROAD, // Bullet
VTYPE_ROAD, // Clover
VTYPE_ROAD, // Sadler
VTYPE_ROAD, // Firetruck
VTYPE_ROAD, // Hustler
VTYPE_ROAD, // Intruder
VTYPE_ROAD, // Primo
VTYPE_HELI, // Cargobob
VTYPE_ROAD, // Tampa
VTYPE_ROAD, // Sunrise
VTYPE_ROAD, // Merit
VTYPE_ROAD, // Utility
VTYPE_PLANE, // Nevada
VTYPE_ROAD, // Yosemite
VTYPE_ROAD, // Windsor
VTYPE_ROAD, // Monster
VTYPE_ROAD, // Monster
VTYPE_ROAD, // Uranus
VTYPE_ROAD, // Jester
VTYPE_ROAD, // Sultan
VTYPE_ROAD, // Stratum
VTYPE_ROAD, // Elegy
VTYPE_HELI, // Raindance
VTYPE_ROAD, // RC Tiger
VTYPE_ROAD, // Flash
VTYPE_ROAD, // Tahoma
VTYPE_ROAD, // Savanna
VTYPE_ROAD, // Bandito
VTYPE_TRAIN, // Carriage
VTYPE_TRAIN, // Carriage
VTYPE_ROAD, // Kart
VTYPE_ROAD, // Mower
VTYPE_ROAD, // Done
VTYPE_ROAD, // Sweeper
VTYPE_ROAD, // Broadway
VTYPE_ROAD, // Tornado
VTYPE_PLANE, // AT-400
VTYPE_ROAD, // DFT-30
VTYPE_ROAD, // Huntley
VTYPE_ROAD, // Stafford
VTYPE_BIKE, // BF-400
VTYPE_ROAD, // Newsvan
VTYPE_ROAD, // Tug
VTYPE_ROAD, // Petrol Trailer
VTYPE_ROAD, // Emperor
VTYPE_BIKE, // Wayfarer
VTYPE_ROAD, // Euros
VTYPE_ROAD, // Hotdog
VTYPE_ROAD, // Club
VTYPE_TRAIN, // Freight Box Trailer
VTYPE_ROAD, // Artic Trailer
VTYPE_PLANE, // Androm
VTYPE_PLANE, // Dodo
VTYPE_ROAD, // RC Cam
VTYPE_BOAT, // Launch
VTYPE_ROAD, // LSPD
VTYPE_ROAD, // SFPD
VTYPE_ROAD, // LVPD
VTYPE_ROAD, // Police Ranger
VTYPE_ROAD, // Picador
VTYPE_ROAD, // S.W.A.T
VTYPE_ROAD, // Alpha
VTYPE_ROAD, // Phoenix
VTYPE_ROAD, // Glendale Shit
VTYPE_ROAD, // Sadler Shit
VTYPE_ROAD, // Baggage
VTYPE_ROAD, // Baggage
VTYPE_ROAD, // Stairs
VTYPE_ROAD, // Boxville
VTYPE_ROAD, // Plow
VTYPE_ROAD // Utility Trailer
};

// Functions for vehicle types

#define IsVehicleModelAircraft(%0) (VFUNC_vTypeArray[%0-400] == VTYPE_PLANE || VFUNC_vTypeArray[%0-400] == VTYPE_HELI)
#define IsVehicleAircraft(%0) (VFUNC_vTypeArray[GetVehicleModel(%0)-400] == VTYPE_PLANE || VFUNC_vTypeArray[GetVehicleModel(%0)-400] == VTYPE_HELI)


#define GetVehicleModelType(%0) VFUNC_vTypeArray[%0-400]
#define GetVehicleType(%0) VFUNC_vTypeArray[GetVehicleModel(%0)-400]

enum VFUNC_VDATA_ENUM
{
	gVeh_Interior,
	gVeh_Color1,
	gVeh_Color2,
	gVeh_SpawnColor1,
	gVeh_SpawnColor2,
	gVeh_Paintjob
}

new vehicleData[MAX_VEHICLES+1][VFUNC_VDATA_ENUM];

stock vfunc_CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, siren=0)
{
	if(modelid < 400 || modelid > 610) return 0; // Invalid model
	
	if(modelid == 569 || modelid == 570 || modelid == 537 || modelid == 538) // Trains, use AddStaticVehicle
	{
		new vid = AddStaticVehicle(modelid, x, y, z, rotation, color1, color2);
		return vid;
	}
	
	new c1 = color1, c2 = color2;
	
	// Add siren to ladder firetruck
	if(modelid == 544) siren = 1;

	if((color1 == -1 || color2 == -1) && gVehicleColors[modelid-400][0] != -1) // Random colors, yay!
	{
		// Get the max index
		new index;
		for(new i=0; i<20; i++)
		{
		    if(gVehicleColors[modelid-400][i] == -1)
			{
				index = i;
				break;
			}
		}
		new RandCol = random(index);
		if(isodd(RandCol)) RandCol--;
		if(color1 == -1) c1 = gVehicleColors[modelid-400][RandCol];
		if(color2 == -1) c2 = gVehicleColors[modelid-400][RandCol+1];
	}
	new vid = CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, c1, c2, respawn_delay, siren);
	
	vehicleData[vid][gVeh_Interior] = 0;
	vehicleData[vid][gVeh_Color1] = c1;
	vehicleData[vid][gVeh_Color2] = c2;

	vehicleData[vid][gVeh_SpawnColor1] = color1;
	vehicleData[vid][gVeh_SpawnColor2] = color2;
	
	vehicleData[vid][gVeh_Paintjob] = 3;
	
	CallRemoteFunction("OnVehicleCreated", "i", vid);
	return vid;
}

#if defined _ALS_CreateVehicle
	#undef CreateVehicle
#else
	#define _ALS_CreateVehicle
#endif
#define CreateVehicle vfunc_CreateVehicle

stock vfunc_AddStaticVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, color1, color2)
{
	if(modelid < 400 || modelid > 610) return 0; // Invalid model

	if(modelid == 569 || modelid == 570 || modelid == 537 || modelid == 538) // Trains, use AddStaticVehicle
	{
		new vid = AddStaticVehicle(modelid, x, y, z, rotation, color1, color2);
		return vid;
	}

	new c1 = color1, c2 = color2;

	if((color1 == -1 || color2 == -1) && gVehicleColors[modelid-400][0] != -1) // Random colors, yay!
	{
		// Get the max index
		new index;
		for(new i=0; i<20; i++)
		{
		    if(gVehicleColors[modelid-400][i] == -1)
			{
				index = i;
				break;
			}
		}
		new RandCol = random(index);
		if(isodd(RandCol)) RandCol--;
		if(color1 == -1) c1 = gVehicleColors[modelid-400][RandCol];
		if(color2 == -1) c2 = gVehicleColors[modelid-400][RandCol+1];
	}
	new vid = AddStaticVehicle(modelid, Float:x, Float:y, Float:z, Float:rotation, c1, c2);

	vehicleData[vid][gVeh_Interior] = 0;
	vehicleData[vid][gVeh_Color1] = c1;
	vehicleData[vid][gVeh_Color2] = c2;

	vehicleData[vid][gVeh_SpawnColor1] = color1;
	vehicleData[vid][gVeh_SpawnColor2] = color2;

	vehicleData[vid][gVeh_Paintjob] = 3;

	CallRemoteFunction("OnVehicleCreated", "i", vid);
	
	return vid;
}
#if defined _ALS_AddStaticVehicle
	#undef AddStaticVehicle
#else
	#define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle vfunc_AddStaticVehicle

stock vfunc_AddStaticVehicleEx(modelid, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, siren=0)
{
	if(modelid < 400 || modelid > 610) return 0; // Invalid model

	if(modelid == 569 || modelid == 570 || modelid == 537 || modelid == 538) // Trains, use AddStaticVehicle
	{
		new vid = AddStaticVehicle(modelid, x, y, z, rotation, color1, color2);
		return vid;
	}

	new c1 = color1, c2 = color2;

	// Add siren to ladder firetruck
	if(modelid == 544) siren = 1;

	if((color1 == -1 || color2 == -1) && gVehicleColors[modelid-400][0] != -1) // Random colors, yay!
	{
		// Get the max index
		new index;
		for(new i=0; i<20; i++)
		{
		    if(gVehicleColors[modelid-400][i] == -1)
			{
				index = i;
				break;
			}
		}
		new RandCol = random(index);
		if(isodd(RandCol)) RandCol--;
		if(color1 == -1) c1 = gVehicleColors[modelid-400][RandCol];
		if(color2 == -1) c2 = gVehicleColors[modelid-400][RandCol+1];
	}
	new vid = AddStaticVehicleEx(modelid, Float:x, Float:y, Float:z, Float:rotation, c1, c2, respawn_delay, siren);

	vehicleData[vid][gVeh_Interior] = 0;
	vehicleData[vid][gVeh_Color1] = c1;
	vehicleData[vid][gVeh_Color2] = c2;

	vehicleData[vid][gVeh_SpawnColor1] = color1;
	vehicleData[vid][gVeh_SpawnColor2] = color2;

	vehicleData[vid][gVeh_Paintjob] = 3;

	CallRemoteFunction("OnVehicleCreated", "i", vid);
	
	return vid;
}
#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx
#else
	#define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx vfunc_AddStaticVehicleEx

stock vfunc_LinkVehicleToInterior(vehicleid, interior)
{
	if(vehicleid < 1 || vehicleid > MAX_VEHICLES) return 0; // Invalid vehicleid
	vehicleData[vehicleid][gVeh_Interior] = interior;
	return LinkVehicleToInterior(vehicleid, interior);
}

#if defined _ALS_LinkVehicleToInterior
	#undef LinkVehicleToInterior
#else
	#define _ALS_LinkVehicleToInterior
#endif
#define LinkVehicleToInterior vfunc_LinkVehicleToInterior

#if !defined SetVehicleInterior
#define SetVehicleInterior LinkVehicleToInterior
#endif

#if !defined GetVehicleInterior
stock GetVehicleInterior(vehicleid)
{
	if(vehicleid < 1 || vehicleid > MAX_VEHICLES) return 0; // Invalid vehicleid
	return vehicleData[vehicleid][gVeh_Interior];
}
#endif

#if !defined GetVehicleColor
stock GetVehicleColor(vehicleid, &color1, &color2)
{
	if(vehicleid < 1 || vehicleid > MAX_VEHICLES) return 0; // Invalid vehicleid
	color1 = vehicleData[vehicleid][gVeh_Color1];
	color2 = vehicleData[vehicleid][gVeh_Color2];
	return vehicleData[vehicleid][gVeh_Color1];
}
#endif

#define GetVehicleColors GetVehicleColor
#define GetVehicleColours GetVehicleColor
#define GetVehicleColour GetVehicleColor

// Number of seats for every vehicle.
// Comments indicate LAST vehicle on row.
new static stock const gVehicleSeatCounts[212] =
{
	4,2,2,2,4,4,1,2,2,4, // Stretch
	2,2,2,4,2,2,4,2,4,2, // Esperanto
	4,2,2,2,2,1,4,4,4,2, // Banshee
	1,9,1,2,2,1,2,9,4,2, // Stallion
	4,1,2,2,2,4,1,2,1,2, // Tram
	1,2,1,1,1,2,2,2,4,4, // Berkley's RC Van
	2,2,2,2,1,1,4,4,2,2, // Sparrow
	4,2,1,1,2,2,1,2,2,4, // Regina
	2,1,2,3,1,1,1,4,2,2, // Rancher
	4,2,4,1,2,2,2,4,4,2, // Benson
	2,1,2,2,2,2,2,4,2,1, // Bike
	1,2,1,1,2,2,4,2,2,1, // Shamal
	1,2,2,2,2,2,2,2,2,4, // Willard
	1,1,1,2,2,2,2,2,2,1, // Vortex
	4,2,2,2,2,2,4,4,2,2, // Tampa
	4,4,2,1,2,2,2,2,2,2, // Jester
	4,4,2,2,1,2,4,4,1,1, // Freight Trailer
	1,1,1,2,1,2,2,2,2,4, // Huntley
	4,2,4,1,1,4,2,2,2,2, // Club
	1,1,2,2,1,1,4,4,4,2, // Police Ranger
	2,2,2,2,4,2,1,1,1,4, // Boxville
	1,1					 // Utility Trailer
};

stock GetVehicleSeatCount(vehicleid)
{
	if(vehicleid < 1 || vehicleid > MAX_VEHICLES) return 0; // Invalid vehicle ID
	
	new model = GetVehicleModel(vehicleid);
	if(model == 0) return 0; // Vehicle does not exist
	
	return gVehicleSeatCounts[model-400];
}

stock GetVehicleModelSeatCount(modelid)
{
	if(modelid < 400 || modelid > 611) return 0; // Invalid model ID
	return gVehicleSeatCounts[modelid-400];
}

stock vfunc_ChangeVehicleColor(vehicleid, color1, color2, paintjob=0)
{
	if(vehicleid < 1 || vehicleid > MAX_VEHICLES) return 0; // Invalid vehicleid
	
	if((color1 == -1 || color2 == -1) && gVehicleColors[GetVehicleModel(vehicleid)-400][0] != -1) // Random colors, yay!
	{
		// Get the max index
		new index;
		for(new i=0; i<20; i++)
		{
		    if(gVehicleColors[GetVehicleModel(vehicleid)-400][i] == -1)
			{
				index = i;
				break;
			}
		}
		new RandCol = random(index);
		if(isodd(RandCol)) RandCol--;
		if(color1 == -1) vehicleData[vehicleid][gVeh_Color1] = gVehicleColors[GetVehicleModel(vehicleid)-400][RandCol];
		if(color2 == -1) vehicleData[vehicleid][gVeh_Color2] = gVehicleColors[GetVehicleModel(vehicleid)-400][RandCol+1];
		return ChangeVehicleColor(vehicleid, vehicleData[vehicleid][gVeh_Color1], vehicleData[vehicleid][gVeh_Color2]);
	}
	ChangeVehicleColor(vehicleid, color1, color2);
	
	if(paintjob) return 1;
	
	vehicleData[vehicleid][gVeh_Color1] = color1;
	vehicleData[vehicleid][gVeh_Color2] = color2;
	return 1;
}

#if defined _ALS_ChangeVehicleColor
	#undef ChangeVehicleColor
#else
	#define _ALS_ChangeVehicleColor
#endif
#define ChangeVehicleColor vfunc_ChangeVehicleColor

#define ChangeVehicleColors ChangeVehicleColor
#define ChangeVehicleColour ChangeVehicleColor
#define ChangeVehicleColours ChangeVehicleColor
#define SetVehicleColor ChangeVehicleColor
#define SetVehicleColour ChangeVehicleColor

stock vfunc_ChangeVehiclePaintjob(vehicleid, paintjobid)
{
	if(vehicleid < 1 || vehicleid > MAX_VEHICLES) return 0; // Invalid vehicleid
	
	ChangeVehiclePaintjob(vehicleid, paintjobid);
	ChangeVehicleColor(vehicleid, 1, 1, 1);
	
	vehicleData[vehicleid][gVeh_Paintjob] = paintjobid;
	
	if(paintjobid == 3) // Reset colors
	{
		new c1, c2;
		GetVehicleColor(vehicleid, c1, c2);
		SetVehicleColor(vehicleid, c1, c2);
	}
	return 1;
}

#if defined _ALS_ChangeVehiclePaintjob
	#undef ChangeVehiclePaintjob
#else
	#define _ALS_ChangeVehiclePaintjob
#endif
#define ChangeVehiclePaintjob vfunc_ChangeVehiclePaintjob

#if !defined GetVehiclePaintjob
stock GetVehiclePaintjob(vehicleid)
{
	if(vehicleid < 1 || vehicleid > MAX_VEHICLES) return 0; // Invalid vehicleid
	return vehicleData[vehicleid][gVeh_Paintjob];
}
#endif

hook OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	// Update paintjob
	vehicleData[vehicleid][gVeh_Paintjob] = paintjobid;
	return 1;
}

#define RemoveVehiclePaintjob(%0) ChangeVehiclePaintjob(%0, 3)

hook OnVehicleSpawn(vehicleid)
{
	// Reset colours
	vehicleData[vehicleid][gVeh_Paintjob] = 3;
	ChangeVehicleColours(vehicleid, vehicleData[vehicleid][gVeh_SpawnColor1], vehicleData[vehicleid][gVeh_SpawnColor2]);
	return 1;
}

hook OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	// Update colours
	vehicleData[vehicleid][gVeh_Color1] = color1;
	vehicleData[vehicleid][gVeh_Color2] = color2;
	
	return 1;
}