#include <a_samp>
#include <YSI\y_bit>

static stock
    Float:AC_Position[3],
    pLastPosTick[MAX_PLAYERS],
    BitArray:AC_SafeTP<MAX_PLAYERS>
;


static
    _pLastFlyTick[ MAX_PLAYERS ]
;

forward OnPlayerTeleport(playerid, Float:distance);
forward OnPlayerFly( playerid );

public OnPlayerSpawn(playerid)
{
    GetPlayerPos(playerid, AC_Position[0], AC_Position[1], AC_Position[2]);
    #if defined pds_OnPlayerSpawn
        pds_OnPlayerSpawn(playerid);
    #endif
    return true;
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn  
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn pds_OnPlayerSpawn
    
#if defined pds_OnPlayerSpawn
    forward pds_OnPlayerSpawn(playerid);
#endif

public OnPlayerUpdate(playerid)
{   
    static  
        Float:Fly_Positions[ 3 ], Float:Velocity[ 3 ], PlayerKeys[ 3 ]; 

    GetPlayerPos( playerid, Fly_Positions[ 0 ], Fly_Positions[ 1 ], Fly_Positions[ 2 ] ), GetPlayerVelocity(playerid, Velocity[ 0 ], Velocity[ 1 ], Velocity[ 2 ] ),
    GetPlayerKeys( playerid, PlayerKeys[ 0 ], PlayerKeys[ 1 ], PlayerKeys[ 2 ] );

    if( gettime( ) - _pLastFlyTick[ playerid ] > 1 )
    {
        if( IsPlayerUsingFlyAnim ( playerid )  && !IsPlayerInWater( playerid ) && PlayerKeys[ 1 ] == KEY_UP && (Fly_Positions[ 2 ] >= 15.0) && 
        (Velocity[ 0 ] >= -0.9  || Velocity[ 1 ] >= -0.9 || Velocity[ 0 ] >= 0.9  || Velocity[ 1 ] >= 0.9) )
        {
            CallLocalFunction( "OnPlayerFly", "i", playerid );
        }
        _pLastFlyTick[playerid] = gettime( );
    }  
    
    if(gettime( ) - pLastPosTick[ playerid ] > 1) //updates the player location every 2 seconds.
    {
        //on-foot
        if( !IsPlayerInRangeOfPoint(playerid, 50.0, AC_Position[0], AC_Position[1], AC_Position[2]) && !Bit_Get(AC_SafeTP, playerid) && !IsPlayerNPC(playerid) 
        && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            CallLocalFunction("OnPlayerTeleport", "if", playerid, GetPlayerDistanceFromPoint(playerid, AC_Position[ 0 ], AC_Position[ 1 ], AC_Position[ 2 ])); 
        }
        //on-vehicle
        else if( !IsPlayerInRangeOfPoint(playerid, 300.0, AC_Position[0], AC_Position[1], AC_Position[2]) && !Bit_Get(AC_SafeTP, playerid) && !IsPlayerNPC(playerid) 
        && GetVehicleSpeed( GetPlayerVehicleID(playerid) ) <= 50 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
        {
            CallLocalFunction("OnPlayerTeleport", "if", playerid, GetPlayerDistanceFromPoint(playerid, AC_Position[0], AC_Position[1], AC_Position[2]));
        }
        GetPlayerPos(playerid, AC_Position[ 0 ], AC_Position[ 1 ], AC_Position[ 2 ]);
        Bit_Set(AC_SafeTP, playerid, false);
        pLastPosTick[ playerid ] = gettime( ) + 2;
    }
    #if defined pds_OnPlayerUpdate
        pds_OnPlayerUpdate(playerid);
    #endif
    return true;
}

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate pds_OnPlayerUpdate
    
#if defined pds_OnPlayerUpdate
    forward pds_OnPlayerUpdate(playerid);
#endif

stock pds_SetPlayerPos(playerid, Float:PosX, Float:PosY, Float:PosZ)
{
    GetPlayerPos(playerid, AC_Position[0], AC_Position[1], AC_Position[2]);
    Bit_Set(AC_SafeTP, playerid, true);
    return SetPlayerPos(playerid, PosX, PosY, PosZ);
}

#if defined _ALS_SetPlayerPos
    #undef SetPlayerPos
#else
    #define _ALS_SetPlayerPos
#endif

#define SetPlayerPos pds_SetPlayerPos

stock pds_SetPlayerPosFindZ(playerid, Float:PosX, Float:PosY, Float:PosZ) 
{ 
    GetPlayerPos(playerid, AC_Position[0], AC_Position[1], AC_Position[2]);
    Bit_Set(AC_SafeTP, playerid, true);
    return SetPlayerPosFindZ(playerid, PosX, PosY, PosZ);
}

#if defined _ALS_SetPlayerPosFindZ
    #undef SetPlayerPosFindZ  
#else
    #define _ALS_SetPlayerPosFindZ
#endif

#define SetPlayerPosFindZ pds_SetPlayerPosFindZ


stock pds_PutPlayerInVehicle(playerid, vehicleid, seatid) 
{ 
    GetPlayerPos(playerid, AC_Position[0], AC_Position[1], AC_Position[2]);
    Bit_Set(AC_SafeTP, playerid, true);
    return PutPlayerInVehicle(playerid, vehicleid, seatid);
}

#if defined _ALS_PutPlayerInVehicle
    #undef PutPlayerInVehicle  
#else
    #define _ALS_PutPlayerInVehicle
#endif

#define PutPlayerInVehicle pds_PutPlayerInVehicle

stock pds_SetPlayerInterior(playerid, interiorid) 
{ 
    GetPlayerPos(playerid, AC_Position[0], AC_Position[1], AC_Position[2]);
    Bit_Set(AC_SafeTP, playerid, true);
    return SetPlayerInterior(playerid, interiorid);
}


#if defined _ALS_SetPlayerInterior
    #undef SetPlayerInterior  
#else
    #define _ALS_SetPlayerInterior
#endif

#define SetPlayerInterior pds_SetPlayerInterior

static stock GetVehicleSpeed( vehicleid ) //records in KMH.
{
    new
        Float:VehiclePos[3],
        VehicleVelocity;
        
    GetVehicleVelocity( vehicleid, VehiclePos[0], VehiclePos[1], VehiclePos[2] );
    VehicleVelocity = floatround( floatsqroot( VehiclePos[0]*VehiclePos[0] + VehiclePos[1]*VehiclePos[1] + VehiclePos[2]*VehiclePos[2] ) * 180 );
    return VehicleVelocity;
}


//==================================[Stocks]==================================//

static stock IsPlayerUsingFlyAnim( playerid ) 
{
    switch( GetPlayerAnimationIndex( playerid ) )
    {
        case 1538, 1542, 1544, 1250, 1062, 1539, 958, 962: return true;
    }
    return false;
}

/*
    All functions below are created by Southclaw, thanks to him for sharing this useful function & array of SA water-area.
    This function were taken from his (Scavenge and Survive) script, its free to use and its available on Github!
*/

static stock Float:Distance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2) return floatsqroot((((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))+((z1-z2)*(z1-z2))));
static stock Float:Distance2D(Float:x1, Float:y1, Float:x2, Float:y2) return floatsqroot( ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)) );

static Float:water_places[20][4] =
{
    {30.0,                        2313.0,                -1417.0,        23.0},
    {15.0,                        1280.0,                -773.0,                1083.0},
    {25.0,                        2583.0,                2385.0,                15.0},
    {20.0,                        225.0,                -1187.0,        74.0},
    {50.0,                        1973.0,                -1198.0,        17.0},
    {180.0,                        1937.0,         1589.0,                9.0},
    {55.0,                        2142.0,                1285.0,         8.0},
    {45.0,                        2150.0,                1132.0,                8.0},
    {55.0,                        2089.0,                1915.0,                10.0},
    {32.0,                        2531.0,                1567.0,                9.0},
    {21.0,                        2582.0,                2385.0,                17.0},
    {33.0,                        1768.0,                2853.0,                10.0},
    {47.0,                        -2721.0,        -466.0,                3.0},
    {210.0,                        -671.0,                -1898.0,        6.0},
    {45.0,                        1240.0,                -2381.0,        9.0},
    {50.0,                        1969.0,                -1200.0,        18.0},
    {10.0,                        513.0,                -1105.0,        79.0},
    {20.0,                        193.0,                -1230.0,        77.0},
    {30.0,                        1094.0,                -672.0,                113.0},
    {20.0,                        1278.0,                -805.0,                87.0}
};

static stock IsPlayerInWater(playerid)
{
    static Float:PosX, Float:PosY, Float:PosZ, i = -1;
    GetPlayerPos(playerid, PosX, PosY, PosZ);

    if(PosZ < 44.0)
    {
        if(Distance(PosX, PosY, PosZ, -965.0, 2438.0, 42.0) <= 700.0) return true;
    }

    while(++i < sizeof(water_places))
    {
        if(Distance2D(PosX, PosY, water_places[i][1], water_places[i][2]) <= water_places[i][0])
        {
            if(PosZ < water_places[i][3]) return true;
        }
        if(PosZ < 1.9)
        {
            if(Distance(PosX, PosY, PosZ, 618.4129, 863.3164, 1.0839) < 200.0) 
            return false; 
                else 
            return true;
        }
    }
    return false;
}