/*
	By Gamer_Z
	LICENSE: http://gpb.googlecode.com/svn/BSD-GZ-SA-MP
	
	LICENSE:

	Copyright (c)  2013, Rafal "Gamer_Z" Grasman

	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

		-Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
		-Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
		-Neither the name of the organization nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

		Special Clause for SA-MP Servers:
		-The authors and or contributors must be credited in a visible and accessible area for the player, including but not limited to: about boxes, welcome messages on the server, commands displaying messages and/or message boxes

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  CONSEQUENTIAL
	DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	
	Thanks to NaS for "pushing" me into making this plugin :)
	Seriously, damn you, again more days spent on programming (but like always, fun stuff) :D
*/

#if defined QUATERNION_STUFF_INCUDED
	#endinput
#endif

#define QUATERNION_STUFF_INCUDED

/*
NOTE: TRIANGLES ARE ASSUMED IN THIS FORMAT:
NOTE2: 	The triangle can be in ANY SHAPE, but this is the recommended, and the ROTATIONS will be according to point X (so not "current" car position)
		If you wish to do that calculate the yaw yourself with atan2(deltaY,deltaX) and use QuatToEuler and EulerToQuat accordingly setting the YAW ONLY (but this can fuck up other rotations if TOO much difference)
		
				TOP:(x_3,y_3,z_3)
	                     *
	                    /|\
	                   / | \
	                  /  |  \
	                 /   |   \
	                /    |    \
	               /     |     \
	              /      |      \
	             /       |       \
	            /        |        \
	           /         |         \
	          /          |          \
	         /           |           \
	        /            |            \
	       /             |             \
	      ***************X***************
  LEFT:(x_1,y_1,z_1)          RIGHT:(x_2,y_2,z_2)
  
  LEFT & RIGHT are used to determine the >>ROLL<<
  X (auto calculated) and TOP are used to determine the PITCH and YAW
*/


//at least it's Pitch,Roll,Yaw for vehicles, I don't know if that is true for other GTA stuff becauce GLM dedault format accepts only Pitch,Yaw,Roll [but still somehow works, see GetQuatRotForVehBetweenCoords2D source)
//quaternion conversion
native QuatToEuler(&Float:pitch, &Float:roll, &Float:yaw, Float:qw, Float:qx, Float:qy, Float:qz);
native EulerToQuat(Float:pitch, Float:roll, Float:yaw, &Float:qw, &Float:qx, &Float:qy, &Float:qz);

//pitch,yaw,roll between positions
native GetPitchYawBetweenPositions(Float:x_1, Float:y_1, Float:z_1, Float:x_2, Float:y_2, Float:z_2, &Float:pitch, &Float:yaw);//line
native GetPitchYawRollBetweenPositions(Float:x_1, Float:y_1, Float:z_1, Float:x_2, Float:y_2, Float:z_2,  Float:x_3, Float:y_3, Float:z_3, &Float:pitch, &Float:yaw, &Float:roll);

//quaternions between positions
native GetQuatRotBetweenPositions2D(Float:x_1, Float:y_1, Float:z_1, Float:x_2, Float:y_2, Float:z_2, &Float:qw, &Float:qx, &Float:qy, &Float:qz);//line
native GetQuatRotBetweenPositions3D(Float:x_1, Float:y_1, Float:z_1, Float:x_2, Float:y_2, Float:z_2,  Float:x_3, Float:y_3, Float:z_3, &Float:qw, &Float:qx, &Float:qy, &Float:qz);

//quaternions between positions for VEHICLES
native GetQuatRotForVehBetweenCoords2D(Float:x_1, Float:y_1, Float:z_1, Float:x_2, Float:y_2, Float:z_2, &Float:qw, &Float:qx, &Float:qy, &Float:qz);
native GetQuatRotForVehBetweenCoords3D(Float:x_1, Float:y_1, Float:z_1, Float:x_2, Float:y_2, Float:z_2,  Float:x_3, Float:y_3, Float:z_3, &Float:qw, &Float:qx, &Float:qy, &Float:qz);

//DAT FEELING WHEN YOU UNDERSTAND QUATERNIONS AND GET THEM TO WORK ! <*** LISTEN TO (http://goo.gl/dO5bju) IF YOU WANT TO KNOW WHAT I WOULD'VE WRITTEN HERE XD>
