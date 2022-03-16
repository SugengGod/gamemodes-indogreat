// This file holds all functions for the toll-system

#define MAX_TOLLGATES (10)
#define TXT_PlayerPaysToll "~r~You paid $%i for the toll"
#define TXT_GovtPaysToll "~g~The government has paid\nfor your toll fee"

enum TTollGate
{
	GateID, // Holds the object-id of the gate
	TollPrice, // Holds the price for passing the gate
	GateStatus, // Holds the status of the gate (open = 1, closed = 0)
	Float:OpenX, // Holds the coordinates when the gate is opened
	Float:OpenY, // Holds the coordinates when the gate is opened
	Float:OpenZ, // Holds the coordinates when the gate is opened
	Float:CloseX, // Holds the coordinates when the gate is closed
	Float:CloseY, // Holds the coordinates when the gate is closed
	Float:CloseZ // Holds the coordinates when the gate is closed
}
new ATollGates[MAX_TOLLGATES][TTollGate];

AddTollGate(GateModel, Float:OX, Float:OY, Float:OZ, Float:CX, Float:CY, Float:CZ, Float:RX, Float:RY, Float:RZ, TollMoney)
{
	// Loop through all tollgates
	for (new TollGate; TollGate < MAX_TOLLGATES; TollGate++)
	{
		// Check if this is an empty entry
		if (ATollGates[TollGate][GateID] == 0)
		{
			// Create a new object for the toll-gate in it's closed status
			ATollGates[TollGate][GateID] = CreateObject(GateModel, CX, CY, CZ, RX, RY, RZ);
			// Set data
			ATollGates[TollGate][TollPrice] = TollMoney; // Set the price to pay for passing the toll-gate
			ATollGates[TollGate][GateStatus] = 0; // Set the status to CLOSED
			ATollGates[TollGate][OpenX] = OX; // Save the OpenX coordinates
			ATollGates[TollGate][OpenY] = OY; // Save the OpenY coordinates
			ATollGates[TollGate][OpenZ] = OZ; // Save the OpenZ coordinates
			ATollGates[TollGate][CloseX] = CX; // Save the CloseX coordinates
			ATollGates[TollGate][CloseY] = CY; // Save the CloseY coordinates
			ATollGates[TollGate][CloseZ] = CZ; // Save the CloseZ coordinates
			break; // Stop the for-loop
		}
	}
}

forward Toll();
public Toll()
{
	// Loop through all players
    for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		// Check if the player is the driver of a vehicle
		if (GetPlayerVehicleSeat(playerid) == 0)
		{
			// Loop through all toll-gates
			for (new TollGate; TollGate < MAX_TOLLGATES; TollGate++)
			{
				// Check if this toll-gate exists
				if (ATollGates[TollGate][GateID] != 0)
				{
				    // Check if the player is in range of the tollgate
			        if(IsPlayerInRangeOfPoint(playerid, 7.5, ATollGates[TollGate][CloseX], ATollGates[TollGate][CloseY], ATollGates[TollGate][CloseZ]) && !IsAGovernmentFaction(playerid))
			        {
						// Check if the toll-gate is closed
			            if(ATollGates[TollGate][GateStatus] == 0)
						{
						    // Open the gate
			                MoveObject(ATollGates[TollGate][GateID], ATollGates[TollGate][OpenX], ATollGates[TollGate][OpenY], ATollGates[TollGate][OpenZ], 3.0);
							// Set status to OPEN
			                ATollGates[TollGate][GateStatus] = 1;
			                // Let the player pay the toll
			                GivePlayerCash(playerid, -ATollGates[TollGate][TollPrice]);
			                new string[50];
			                format(string, sizeof(string), TXT_PlayerPaysToll, ATollGates[TollGate][TollPrice]);
			                GameTextForPlayer(playerid, string, 3000, 4);
			                // Start a timer that closes the gate after 5 seconds
			                SetTimerEx("CloseGate", 5000, false, "i", TollGate);
						}
			        }
					else
					if(IsPlayerInRangeOfPoint(playerid, 7.5, ATollGates[TollGate][CloseX], ATollGates[TollGate][CloseY], ATollGates[TollGate][CloseZ]) && IsAGovernmentFaction(playerid))
			        {
						// Check if the toll-gate is closed
			            if(ATollGates[TollGate][GateStatus] == 0)
						{
						    // Open the gate
			                MoveObject(ATollGates[TollGate][GateID], ATollGates[TollGate][OpenX], ATollGates[TollGate][OpenY], ATollGates[TollGate][OpenZ], 3.0);
							// Set status to OPEN
			                ATollGates[TollGate][GateStatus] = 1;
			                new string[50];
			                format(string, sizeof(string), TXT_GovtPaysToll, ATollGates[TollGate][TollPrice]);
			                GameTextForPlayer(playerid, string, 3000, 4);
			                // Start a timer that closes the gate after 5 seconds
			                SetTimerEx("CloseGate", 5000, false, "i", TollGate);
						}
					}
				}
			}
		}
    }
}

forward CloseGate(TollGate);
public CloseGate(TollGate)
{
    // Close the gate
	MoveObject(ATollGates[TollGate][GateID], ATollGates[TollGate][CloseX], ATollGates[TollGate][CloseY], ATollGates[TollGate][CloseZ], 3.0);
	// Set status to CLOSED
	ATollGates[TollGate][GateStatus] = 0;
}

