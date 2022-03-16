#define D_ARTS_MAX 128
#define D_ARTS_LINE_SIZE 2048
#define D_ARTS_MAX_OBJECTS 2000
#tryinclude <streamer>
new Float:D_ArtsInfo[D_ARTS_MAX][11];
// 0 = reserved
// 1 = create_type ( 0 = not inited 1 = standart 2 = dynamic )
// 2 = object_type
// 3 = Xpos
// 4 = Ypos
// 5 = Zpos
// 6 = Xrot
// 7 = Yrot
// 8 = Zrot
// 9 = width
// 10 = height

new D_ArtsObjects[D_ARTS_MAX][D_ARTS_MAX_OBJECTS]; 

//converted picture representation example
//new ArtObject[buffers used][];
//0th buffer is used to store the misc info
// 0 = width
// 1 = height
// i + 2 = num of sbuffers for the block i

stock CreateArt3(ArtObject[][], type, Float:PosX, Float:PosY, Float:PosZ, Float:RotX, Float:RotY, Float:RotZ, Float:DrawDistance = 300.0)
{
	return CreateArtInternal3(ArtObject, type, 0, PosX, PosY, PosZ, RotX, RotY, RotZ, -1, -1, -1, 0, DrawDistance);
}

#if defined CreateDynamicObject
stock CreateDynamicArt3(ArtObject[][], type, Float:PosX, Float:PosY, Float:PosZ, Float:RotX, Float:RotY, Float:RotZ, worldid = -1, interiorid = -1, playerid = -1, Float:StreamDistance = 200.0, Float:DrawDistance = 300.0 )
{
	return CreateArtInternal3(ArtObject, type, 1, PosX, PosY, PosZ, RotX, RotY, RotZ, worldid, interiorid, playerid, StreamDistance, DrawDistance);
}
#endif

stock CreateArtInternal3(ArtObject[][], type, dynamic, Float:PosX, Float:PosY, Float:PosZ, Float:RotX, Float:RotY, Float:RotZ, worldid = -1, interiorid = -1, playerid = -1, Float:StreamDistance = 200.0, Float:DrawDistance = 300.0 )
{
	new art_id = -1;
	for (new i = 0; i < D_ARTS_MAX; i++)
	{
		if (D_ArtsInfo[i][1] == 0)
		{
			art_id = i;
			break;
		}
	}
	if (art_id < 0 || art_id >= D_ARTS_MAX)
		return -1; //no more objects can be created
	new width = ArtObject[0][0];
	new height = ArtObject[0][1];
	
	new Float:ang[3];
	ang[0] = RotX;
	ang[1] = RotY;
	ang[2] = RotZ;
	new Float:pos[3];
	pos[0] = PosX;
	pos[1] = PosY;
	pos[2] = PosZ;
	
	new internal_type = type;
	
	new arrow = 0; new matid;
	
	new Float:ws, Float:hs, oid, Float:arx = 0, Float:ary = 0, Float:arz = 0;
	
	
	
	if (internal_type == 0)
	{
		ws = 1.48;
		hs = 1.48;
		oid = 19168;
		matid = 0;
		arrow = 0;
	} else if (internal_type == 1)
	{
		ws = 1.48;
		hs = 1.48;
		oid = 19168;
		matid = 1;
		arrow = 0;
	}
	else if (internal_type == 2)
	{
		ws = 0.42;
		hs = 0.42;
		oid = 19167;
		matid = 1;
		arrow = 0;
	}
	else if (internal_type == 3)
	{
		ws = 0.42;
		hs = 0.42;
		oid = 19167;
		matid = 0;
		arrow = 0;
	}
	else if (internal_type == 4)
	{
		ws = 1.98;
		hs = 1.98;
		oid = 18660;
		matid = 0;
		arrow = 1;
	}
	else if (internal_type == 5)
	{
		ws = 0.995;
		hs = 0.995;
		oid = 19789;
		matid = 0;
		arrow = 0;
	}
	else if (internal_type == 6)
	{
		ws = 5.875;
		hs = 5.075;
		oid = 19464;
		matid = 0;
		arrow = 1;
	}
	else if (internal_type == 7)
	{
		ws = 0.51;
		hs = 0.51;
		oid = 2814;
		matid = 0;
		arrow = 1;
		ary = -94.65;
	}
	else if (internal_type == 8)
	{
		ws = 3.18;
		hs = 3.48;
		oid = 19372;
		matid = 0;
		arrow = 1;
	}
	else if (internal_type == 9)
	{
		ws = 1.48;
		hs = 1.48;
		oid = 18887;
		matid = 0;
		arrow = 0;
	}
	
	//my old magic with transformations
	new Float:up[3];
	up[0] = floatsin(ang[1], degrees)*floatcos(ang[2], degrees) + floatsin(ang[0], degrees)*floatsin(ang[2], degrees)*floatcos(ang[1], degrees);
	up[1] = floatsin(ang[2], degrees)*floatsin(ang[1], degrees) - floatsin(ang[0], degrees)*floatcos(ang[1], degrees)*floatcos(ang[2], degrees);
	up[2] = -floatcos(ang[0], degrees)*floatcos(ang[1], degrees);
	new Float:right[3];
	right[0] = -floatsin(ang[2], degrees)*floatcos(ang[0], degrees);
	right[1] = floatcos(ang[0], degrees)*floatcos(ang[2], degrees);
	right[2] = -floatsin(ang[0], degrees);
	new Float:frwd[3];
	frwd[0] = floatcos(ang[1], degrees)*floatcos(ang[2], degrees) - floatsin(ang[0], degrees)*floatsin(ang[2], degrees)*floatsin(ang[1], degrees); 
	frwd[1] = floatsin(ang[2], degrees)*floatcos(ang[1], degrees) + floatsin(ang[0], degrees)*floatsin(ang[1], degrees)*floatcos(ang[2], degrees);
	frwd[2] = floatcos(ang[0], degrees)*floatsin(ang[1], degrees);
	new Float:secnd[3];
	

	if (arrow == 0)
	{
		secnd = frwd;
	}
	else
	{
		secnd = up;
	}

	for(new i = 0; i < width; i++)
		for(new j = 0; j < height; j++)
		{
			new an_i = i, an_j = j, an_height = height, an_width = width;
			if (internal_type == 0 || internal_type == 1 || internal_type == 2 || internal_type == 5 || internal_type == 9)
			{
				an_i = j;
				an_j = width - i;
				an_height = width;
				an_width = height;
			}
			else if (internal_type == 3)
			{
				an_i = height - j;
				an_j = width - i;
				an_height = width;
				an_width = height;
			}
			new Float:start[3];
			start[0] = (float(an_i) - float(an_width)/2.0)*ws*right[0] + (float(an_j) - float(an_height)/2.0)*(hs)*secnd[0] + pos[0];
			start[1] = (float(an_i) - float(an_width)/2.0)*ws*right[1] + (float(an_j) - float(an_height)/2.0)*(hs)*secnd[1] + pos[1];
			start[2] = (float(an_i) - float(an_width)/2.0)*ws*right[2] + (float(an_j) - float(an_height)/2.0)*(hs)*secnd[2] + pos[2];
			new creo = -1;
			if (dynamic == 0)
			{
				creo = CreateObject( oid, start[0], start[1], start[2], ang[0] + arx, ang[1] + ary, ang[2] + 180 + arz, DrawDistance);
			}
			else
			{
			#if defined CreateDynamicObject
				creo = CreateDynamicObject( oid, start[0], start[1], start[2], ang[0] + arx, ang[1] + ary, ang[2] + 180 + arz, worldid, interiorid, playerid, StreamDistance, DrawDistance);
			#else
				#pragma unused worldid, interiorid, playerid, StreamDistance
			#endif
			}
			D_ArtsObjects[art_id][i + width*j] = creo;
			new d_temp_buf_string[2048] = "";
			new count = ArtObject[0][ (i + width*j) * 2 + 2];
			new index = ArtObject[0][ (i + width*j) * 2 + 3];
			for (new k = 0; k < count; k++)
				strcat(d_temp_buf_string, ArtObject[index + k], 2048);
			if (dynamic == 0)
			{
				SetObjectMaterialText(creo, d_temp_buf_string, matid, 140, "Webdings", 35, 0, 0, 0, 0);
			}
			else
			{
				#if defined SetDynamicObjectMaterialText
					SetDynamicObjectMaterialText(creo, matid, d_temp_buf_string, 140, "Webdings", 35, 0, 0, 0, 0);
				#endif
			}
		}
	D_ArtsInfo[art_id][1] = float(dynamic) + 1;
	D_ArtsInfo[art_id][2] = float(internal_type);
	D_ArtsInfo[art_id][3] = PosX;
	D_ArtsInfo[art_id][4] = PosY;
	D_ArtsInfo[art_id][5] = PosZ;
	D_ArtsInfo[art_id][6] = RotX;
	D_ArtsInfo[art_id][7] = RotY;
	D_ArtsInfo[art_id][8] = RotZ;
	D_ArtsInfo[art_id][9] = float(width);
	D_ArtsInfo[art_id][10] = float(height);
	return art_id;
}

stock DestroyArt3Internal(ArtID)
{
	if (D_ArtsInfo[ArtID][1] < 0.5 || D_ArtsInfo[ArtID][1] > 1.5)
		return -1;
	new dynamic = D_ArtsInfo[ArtID][1];
	if (dynamic == 0)
		return -1;
	new width = floatround(D_ArtsInfo[ArtID][9] + 0.5);
	new height = floatround(D_ArtsInfo[ArtID][10] + 0.5);
	for (new i = 0; i < width*height; i++)
	{
		if (dynamic == 1)
		{
			DestroyObject(D_ArtsObjects[ArtID][i]);
		}
		else
		{
			#if defined DestroyDynamicObject
				DestroyDynamicObject(D_ArtsObjects[ArtID][i]);
			#endif
		}
	}
	D_ArtsInfo[ArtID][1] = 0;
	return 0;
}

stock DestroyArt3(ArtID)
{
	return DestroyArt3Internal(ArtID);
}

stock DestroyDynamicArt3(ArtID)
{
	return DestroyArt3Internal(ArtID);
}