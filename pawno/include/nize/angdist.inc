// Angle & Distance Management by SlashQ
// I didn't make these, but rather optimize the codes & shove them in an include.

#include <a_samp>

stock Float:GetDistanceBetweenPlayers(p1, p2) {

	new
		Float: x1,
		Float: y1,
		Float: z1,
		Float: x2,
		Float: y2,
		Float: z2;
		
	if(!IsPlayerConnected(p1) || !IsPlayerConnected(p2)) return -1.00;

	GetPlayerPos(p1, x1, y1, z1);
	GetPlayerPos(p2, x2, y2, z2);

	return floatsqroot(floatpower(floatabs(floatsub(x2, x1)), 2) + floatpower(floatabs(floatsub(y2, y1)), 2) + floatpower(floatabs(floatsub(z2, z1)), 2));
}

stock Float:DistanceCameraTargetToLocation(Float:camX, Float:camY, Float:camZ, Float:objX, Float:objY, Float:objZ, Float:frX, Float:frY, Float:frZ) {

	new
		Float: dist = floatsqroot((camX - objX) * (camX - objX) + (camY - objY) * (camY - objY) + (camZ - objZ) * (camZ - objZ)),
		Float: tmpX = (frX * dist) + camX,
		Float: tmpY = (frY * dist) + camY,
		Float: tmpZ = (frZ * dist) + camZ;
		
	return floatsqroot((tmpX - objX) * (tmpX - objX) + (tmpY - objY) * (tmpY - objY) + (tmpZ - objZ) * (tmpZ - objZ));
}

stock Float:GetPointAngleToPoint(Float:x2, Float:y2, Float:X, Float:Y) {

	new
	    Float:dx,
	    Float:dy,
	    Float:angle;
	    
    dx = floatabs(floatsub(x2, X));
    dy = floatabs(floatsub(y2, Y));

	if (dy == 0.0 || dx == 0.0)
	{
        if(dy == 0 && dx > 0) angle = 0.0;
        else if(dy == 0 && dx < 0) angle = 180.0;
        else if(dy > 0 && dx == 0) angle = 90.0;
        else if(dy < 0 && dx == 0) angle = 270.0;
        else if(dy == 0 && dx == 0) angle = 0.0;
    }
    else
	{
        angle = atan(dx / dy);
        if(X > x2 && Y <= y2) angle += 90.0;
        else if(X <= x2 && Y < y2) angle = floatsub(90.0, angle);
        else if(X < x2 && Y >= y2) angle -= 90.0;
        else if(X >= x2 && Y > y2) angle = floatsub(270.0, angle);
    }
    return floatadd(angle, 90.0);
}

stock GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, &Float:z, &Float:a) {

	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);
	
	if (GetPlayerVehicleID(playerid)) GetVehicleZAngle(GetPlayerVehicleID(playerid), a);

	x += (DISTANCE * floatsin(-a, degrees));
	y += (DISTANCE * floatcos(-a, degrees));
	return 1;
}

stock GetXYInFrontOfPoint(&Float:x, &Float:y, Float:angle, Float:distance) {

	x += (distance * floatsin(-angle, degrees));
	y += (distance * floatcos(-angle, degrees));
	return 1;
}

stock IsPlayerAimingAt(playerid, Float:x, Float:y, Float:z, Float:radius) {

	new
		Float: cam_x,
		Float: cam_y,
		Float: cam_z,
		Float: vector_x,
		Float: vector_y,
		Float: vector_z,
		Float: vertical,
		Float: horizontal,
		Float: angle,
		Float: resize_x,
		Float: resize_y,
		Float: resize_z;

	GetPlayerCameraPos(playerid, cam_x, cam_y, cam_z);
    GetPlayerCameraFrontVector(playerid, vector_x, vector_y, vector_z);

	if(GetPlayerWeapon(playerid) > 0)
	{
		if(GetPlayerWeapon(playerid) == 34 || GetPlayerWeapon(playerid) == 35 || GetPlayerWeapon(playerid) == 36)
		{
 			if (DistanceCameraTargetToLocation(cam_x, cam_y, cam_z, x, y, z, vector_x, vector_y, vector_z) < radius) return 1;
    		return 0;
		}
		else if(GetPlayerWeapon(playerid) == 30 || GetPlayerWeapon(playerid) == 31)
		{
			vertical = 4.0;
			horizontal = -1.6;
		}
		else if(GetPlayerWeapon(playerid) == 33)
		{
	    	vertical = 2.7;
			horizontal = -1.0;
		}
		else
		{
		    vertical = 6.0;
			horizontal = -2.2;
		}
	}

    angle = GetPointAngleToPoint(0, 0, floatsqroot(vector_x * vector_x + vector_y * vector_y), vector_z) - 270.0;
    resize_x = floatsin((angle + vertical), degrees);
    resize_y = floatsin((angle + vertical), degrees);
    resize_z = floatsin((angle + vertical), degrees);

    GetXYInFrontOfPoint(resize_x, resize_y, GetPointAngleToPoint(0, 0, vector_x, vector_y) + horizontal, floatcos(angle + vertical, degrees));
    if (DistanceCameraTargetToLocation(cam_x, cam_y, cam_z, x, y, z, resize_x, resize_y, resize_z) < radius) return 1;
    return 0;
}

stock IsPlayerAimingAtPlayer(playerid, targetid) {

    new
		Float:x,
		Float:y,
		Float:z;
		
    GetPlayerPos(targetid, x, y, z);

	if(IsPlayerAimingAt(playerid, x, y, z - 0.75, 0.25)) return 1;
    else if(IsPlayerAimingAt(playerid, x, y, z - 0.25, 0.25)) return 1;
    else if(IsPlayerAimingAt(playerid, x, y, z + 0.25, 0.25)) return 1;
    else if(IsPlayerAimingAt(playerid, x, y, z + 0.75, 0.25)) return 1;
    return 0;
}