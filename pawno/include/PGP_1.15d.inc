 /*
 *  Protioso - Gerenciamento de Pickups 1.0 rev. C, por [VGS]Protioso_OC
 *   PGP - P001
 *  (c) Copyright 2008/2009, [VGS]Protioso_OC
 *  Vengeance Shooters clan fórum: www.vgs.br30.com
 *  Críticas e sugestões: protioso@hotmail.com
 *  :*
 */

#if defined _PGP_included
	#endinput
#endif
#define _PGP_included
#pragma library PGP

#include <a_samp>
#include <dutils>
#pragma unused ret_memcpy
//
#define MAX_PGP 300 //Valor recomendado (Máximo 400)
enum spick
{
	Float:px,
	Float:py,
	Float:pz,
	Float:PRaio,
	SPRaio,
	SPRaioM,
	PModelo,
 	PTipo,
	PMSG[256],
	PMSGS,
	EstiloGT,
	SPickup,
	SPickupF,
};
new PPickup[MAX_PLAYERS][spick];
new PegouPickup[MAX_PLAYERS];
new JogadorPickup[MAX_PLAYERS] = -1;
new JogadorPickupPega[MAX_PLAYERS] = -1;
new JogadorEmRaio[MAX_PLAYERS] = -1;
new GTJogador[MAX_PLAYERS] = 0;
new gTimerP = 0;
new gPID = 0;
new gNumPGP = 0;
//
forward pgp_ZerarGT(playerid);
forward JogadorEmPickup(playerid, pgpid);
forward pgp_CriarPickup(pmodeloid, tipo, Float:x, Float:y, Float:z);
forward pgp_CriarPickupEx(pmodeloid, tipo, Float:x, Float:y, Float:z, mensagem[], estilogametext);
forward pgp_CriarPickupR(pmodeloid, tipo, Float:x, Float:y, Float:z, Float:raio);
forward pgp_CriarPickupREx(pmodeloid, tipo, Float:x, Float:y, Float:z, Float: raio, mensagem[], estilogametext);
forward pgp_ChecarJogadores();
forward pgp_JogadorEstaEmPickup(playerid);
forward pgp_DesativarPickup(pgpid);
forward pgp_DestruirPickup(pgpid);
forward pgp_DestruirPickupEx(pgpid);
forward pgp_PickupPGPOn(pgpid);
forward pgp_PickGameText(pgpid, playerid);
forward pgp_RecriarPickup(pgpid);
forward pgp_JogadorPegaPickup(playerid, pgpid);
forward pgp_MudarModelo(pgpid, novomodeloid);
forward pgp_MudarTipo(pgpid, novotipo);
forward pgp_MudarMensagem(pgpid, novamensagem[]);
forward pgp_AdicionarMensagem(pgpid, mensagem[]);
forward pgp_MudarRaio(pgpid, Float:novoraio);
forward pgp_AdicionarRaio(pgpid, Float:raio);
forward pgp_MudarEstiloGT(pgpid, novoestilo);
forward pgp_ZerarPickupPega(playerid);
//
/*
native JogadorEmPickup(playerid, pgpid);
native pgp_CriarPickup(pmodeloid, tipo, Float:x, Float:y, Float:z);
native pgp_CriarPickupEx(pmodeloid, tipo, Float:x, Float:y, Float:z, mensagem[], estilogametext);
native pgp_CriarPickupR(pmodeloid, tipo, Float:x, Float:y, Float:z, Float:raio);
native pgp_CriarPickupREx(pmodeloid, tipo, Float:x, Float:y, Float:z, Float: raio, mensagem[], estilogametext);
native pgp_JogadorNaPickup(playerid, pgpid);
native pgp_JogadorPickup(playerid);
native pgp_DesativarPickup(pgpid);
native pgp_DestruirPickup(pgpid);
native pgp_DestruirPickupEx(pgpid);
native pgp_PickupExiste(pickup);
native pgp_PickupPGPOn(pgpid);
native pgp_PickGameText(pgpid, playerid);
native pgp_JogadorEmPickupModelo(playerid, pmodeloid);
native pgp_RecriarPickup(pgpid);
native pgp_JogadorPegaPickup(playerid, pgpid);
native pgp_JogadorPickupPega(playerid);
native pgp_JogadorRaio(playerid);
native pgp_MensagemPickup(pgpid);
native pgp_MudarModelo(pgpid, novomodeloid);
native pgp_MudarTipo(pgpid, novotipo);
native pgp_MudarMensagem(pgpid, novamensagem[]);
native pgp_AdicionarMensagem(pgpid, mensagem[]);
native pgp_MudarRaio(pgpid, Float:novoraio);
native pgp_AdicionarRaio(pgpid, Float:raio);
native pgp_MudarEstiloGT(pgpid, novoestilo);
native pgp_JogadorEstaEmPickup(playerid);
native pgp_ModeloPickup(pgpid);
native pgp_ZerarPickupPega(playerid);
*/

//----------------------------------------------------------------------------------------------------------------------||

public pgp_CriarPickup(pmodeloid, tipo, Float:x, Float:y, Float:z)
{
	if(gPID + 1 >= MAX_PGP)
	{
   		 printf("[PGP]: Impossivel criar pickup id %d! Limite maximo exedido (%d).", gPID, MAX_PGP);
		 return 0;
	}
	new ida;
	ida = CreatePickup(pmodeloid, tipo, x, y, z);
	gPID = ida;
	PPickup[gPID][px] = x;
	PPickup[gPID][py] = y;
	PPickup[gPID][pz] = z;
	PPickup[gPID][PModelo] = pmodeloid;
	PPickup[gPID][PTipo] = tipo;
	PPickup[gPID][PMSGS] = 0;
	PPickup[gPID][SPRaio] = 0;
	PPickup[gPID][SPickup] = 1;
	PPickup[gPID][SPickupF] = 1;
    gNumPGP++;
	if(gTimerP == 0)
	{
        gTimerP = 1;
		SetTimer("pgp_ChecarJogadores", 1500, 1);
   		print("[PGP]: Sistema iniciado, criando pickup(s).");
	}
	return gPID;
}

public pgp_CriarPickupEx(pmodeloid, tipo, Float:x, Float:y, Float:z, mensagem[], estilogametext)
{
	if(gPID + 1 >= MAX_PGP)
	{
   		 printf("[PGP]: Impossivel criar pickup id %d! Limite maximo exedido (%d).", gPID, MAX_PGP);
		 return 0;
	}
	if(estilogametext < 0 || estilogametext > 6)
	{
   		 printf("[PGP]: Impossivel criar pickup id %d! Estilo de GameText invalido (%d). Use de 0 a 6.", gPID, estilogametext);
		 return 0;
	}
	new ida, str[256];
	ida = CreatePickup(pmodeloid, tipo, x, y, z);
	gPID = ida;
	PPickup[gPID][px] = x;
	PPickup[gPID][py] = y;
	PPickup[gPID][pz] = z;
	PPickup[gPID][PModelo] = pmodeloid;
	PPickup[gPID][PTipo] = tipo;
	PPickup[gPID][PMSGS] = 1;
	PPickup[gPID][SPRaio] = 0;
	PPickup[gPID][SPickup] = 1;
	PPickup[gPID][SPickupF] = 1;
	PPickup[gPID][EstiloGT] = estilogametext;
    set(str,mensagem);
	set(PPickup[gPID][PMSG],str);
    gNumPGP++;
	if(gTimerP == 0)
	{
        gTimerP = 1;
		SetTimer("pgp_ChecarJogadores", 1500, 1);
   		print("[PGP]: Sistema iniciado, criando pickup(s).");
	}
	return gPID;
}

public pgp_CriarPickupR(pmodeloid, tipo, Float:x, Float:y, Float:z, Float:raio)
{
	if(gPID + 1 >= MAX_PGP)
	{
   		 printf("[PGP]: Impossivel criar pickup id %d! Limite maximo exedido (%d).", gPID, MAX_PGP);
		 return 0;
	}
	new ida;
	ida = CreatePickup(pmodeloid, tipo, x, y, z);
	gPID = ida;
	PPickup[gPID][px] = x;
	PPickup[gPID][py] = y;
	PPickup[gPID][pz] = z;
	PPickup[gPID][PRaio] = raio;
	PPickup[gPID][SPRaioM] = 0;
	PPickup[gPID][PModelo] = pmodeloid;
	PPickup[gPID][PTipo] = tipo;
	PPickup[gPID][PMSGS] = 0;
	PPickup[gPID][SPRaio] = 1;
	PPickup[gPID][SPickup] = 1;
	PPickup[gPID][SPickupF] = 1;
    gNumPGP++;
	if(gTimerP == 0)
	{
        gTimerP = 1;
		SetTimer("pgp_ChecarJogadores", 1500, 1);
   		print("[PGP]: Sistema iniciado, criando pickup(s).");
	}
	return gPID;
}

public pgp_CriarPickupREx(pmodeloid, tipo, Float:x, Float:y, Float:z, Float: raio, mensagem[], estilogametext)
{
	if(gPID + 1 >= MAX_PGP)
	{
   		 printf("[PGP]: Impossivel criar pickup id %d! Limite maximo exedido (%d).", gPID, MAX_PGP);
		 return 0;
	}
	if(estilogametext < 0 || estilogametext > 6)
	{
   		 printf("[PGP]: Impossivel criar pickup id %d! Estilo de GameText invalido (%d). Use de 0 a 6.", gPID, estilogametext);
		 return 0;
	}
	new ida, str[256];
	ida = CreatePickup(pmodeloid, tipo, x, y, z);
	gPID = ida;
	PPickup[gPID][px] = x;
	PPickup[gPID][py] = y;
	PPickup[gPID][pz] = z;
	PPickup[gPID][PRaio] = raio;
	PPickup[gPID][SPRaioM] = 1;
	PPickup[gPID][PModelo] = pmodeloid;
	PPickup[gPID][PTipo] = tipo;
	PPickup[gPID][PMSGS] = 0;
	PPickup[gPID][SPRaio] = 1;
	PPickup[gPID][SPickup] = 1;
	PPickup[gPID][SPickupF] = 1;
	PPickup[gPID][EstiloGT] = estilogametext;
    set(str,mensagem);
	set(PPickup[gPID][PMSG],str);
    gNumPGP++;
	if(gTimerP == 0)
	{
        gTimerP = 1;
		SetTimer("pgp_ChecarJogadores", 1500, 1);
   		print("[PGP]: Sistema iniciado, criando pickup(s).");
	}
	return gPID;
}

public pgp_ChecarJogadores() for(new i=0; i<MAX_PLAYERS; i++) if(IsPlayerConnected(i)) pgp_ChecarPickups(i);

stock pgp_ChecarPickups(playerid)
{
	for(new p=0; p<MAX_PGP; p++)
	{
//		if(pgp_PickupPGPOn(p) == 1)
//		{
			if(PPickup[p][SPRaio] == 1 && PTP(PPickup[p][PRaio], playerid, PPickup[p][px], PPickup[p][py], PPickup[p][pz]) == 1 && JogadorEmRaio[playerid] < 0)
   			{
				printf("1ª condicao - playerid %d", playerid);
				JogadorEmRaio[playerid] = p;
				if(PPickup[p][SPRaioM] == 1) pgp_PickGameText(p, playerid);
			}
			else if(JogadorEmRaio[playerid] > -1)
			{
			    printf("2ª condicao - playerid %d", playerid);
				JogadorEmRaio[playerid] = -1;
			}
		    else if(PTP(1.0, playerid, PPickup[p][px], PPickup[p][py], PPickup[p][pz]) == 1 && JogadorPickup[playerid] < 0)
		    {
		        printf("3ª condicao - playerid %d", playerid);
		        JogadorPickup[playerid] = p;
				if(PegouPickup[playerid] == 0) pgp_PegouPickup(playerid, p);
				if(PPickup[p][PMSGS] == 1 && GTJogador[playerid] == 0) pgp_PickGameText(p, playerid);
			}
			else if(JogadorPickup[playerid] > -1)
			{
			    printf("4ª condicao - playerid %d", playerid);
			 	JogadorPickup[playerid] = -1;
                JogadorPickupPega[playerid] = -1;
			}
			else
			{
			    print("Bug");
			}
		}
//	}
}

public pgp_MudarModelo(pgpid, novomodeloid)
{
	if(PPickup[pgpid][SPickup] == 0) return 0;
	pgp_DestruirPickupEx(pgpid);
	PPickup[pgpid][PModelo] = novomodeloid;
	SetTimerEx("pgp_RecriarPickup",3500,0,"d",pgpid);
	return 1;
}

public pgp_MudarTipo(pgpid, novotipo)
{
	if(PPickup[pgpid][SPickup] == 0) return 0;
	pgp_DestruirPickupEx(pgpid);
	PPickup[pgpid][PTipo] = novotipo;
	SetTimerEx("pgp_RecriarPickup",3500,0,"d",pgpid);
	return 1;
}

public pgp_MudarEstiloGT(pgpid, novoestilo)
{
	if(PPickup[pgpid][SPickup] == 0 || PPickup[pgpid][PMSGS] == 0) return 0;
	if(novoestilo < 0 || novoestilo > 6)
	{
   		 printf("[PGP]: Impossivel mudar GameText da pickup id %d!", pgpid, novoestilo);
		 return 0;
	}
	PPickup[pgpid][EstiloGT] = novoestilo;
	return 1;
}

public pgp_MudarMensagem(pgpid, novamensagem[])
{
	if(PPickup[pgpid][SPickup] == 0 || PPickup[pgpid][PMSGS] == 0) return 0;
	new str[256];
	set(str,novamensagem);
	set(PPickup[pgpid][PMSG],str);
	return 1;
}

public pgp_AdicionarMensagem(pgpid, mensagem[])
{
	if(PPickup[pgpid][SPickup] == 0 || PPickup[pgpid][PMSGS] == 1) return 0;
	new str[256];
	set(str,mensagem);
	set(PPickup[pgpid][PMSG],str);
	return 1;
}

public pgp_MudarRaio(pgpid, Float:novoraio)
{
	if(PPickup[pgpid][SPickup] == 0 || PPickup[pgpid][SPRaio] == 0) return 0;
	PPickup[pgpid][PRaio] = novoraio;
	return 1;
}

public pgp_AdicionarRaio(pgpid, Float:raio)
{
	if(PPickup[pgpid][SPickup] == 0 || PPickup[pgpid][SPRaio] == 1) return 0;
	PPickup[pgpid][PRaio] = raio;
	return 1;
}

public pgp_PickGameText(pgpid, playerid)
{
	new str[256];
    format(str,sizeof(str),"%s",PPickup[pgpid][PMSG]);
	GameTextForPlayer(playerid,str, 3000,PPickup[pgpid][EstiloGT]);
	GTJogador[playerid] = 1;
	SetTimerEx("pgp_ZerarGT",3000,0,"d",playerid);
}

public pgp_JogadorPegaPickup(playerid, pgpid)
{
	pgp_DestruirPickupEx(pgpid);
	JogadorPickupPega[playerid] = pgpid;
	SetTimerEx("pgp_RecriarPickup",6000,0,"d",pgpid);
	return 1;
}

public pgp_RecriarPickup(pgpid)
{
	if(PPickup[pgpid][SPickup] == 0 && PPickup[pgpid][SPickupF] == 0 || PPickup[pgpid][SPickup] == 0 && PPickup[pgpid][SPickupF] == 1) return 0;
	CreatePickup(PPickup[pgpid][PModelo], PPickup[pgpid][PTipo], PPickup[pgpid][px], PPickup[pgpid][py], PPickup[pgpid][pz]);
	return 1;
}

stock pgp_JogadorNaPickup(playerid, pgpid)
{
	if(PPickup[pgpid][SPickup] == 0) return 0;
    if(PTP(1.0, playerid, PPickup[pgpid][px], PPickup[pgpid][py], PPickup[pgpid][pz]) == 1 && PPickup[pgpid][SPickup] == 1) return 1;
    return 0;
}

stock pgp_JogadorEmPickupModelo(playerid, pmodeloid)
{
	if(pgp_JogadorPickup(playerid) > -1 && PPickup[pgp_JogadorPickup(playerid)][PModelo] == pmodeloid) return 1;
	return 0;
}

stock pgp_ModeloPickup(pgpid)
{
	if(PPickup[pgpid][PModelo] > 0) return PPickup[pgpid][PModelo];
	return -1;
}

public pgp_DesativarPickup(pgpid)
{
	if(PPickup[pgpid][SPickup] == 0) return 0;
	PPickup[pgpid][px] = 0.0;
	PPickup[pgpid][py] = 0.0;
	PPickup[pgpid][pz] = 0.0;
	PPickup[pgpid][PRaio] = 0.0;
	PPickup[pgpid][SPRaio] = 0;
	PPickup[pgpid][PMSGS] = 0;
	PPickup[pgpid][SPickup] = 0;
	PPickup[pgpid][SPickupF] = 0;
    PPickup[pgpid][EstiloGT] = -1;
	PPickup[pgpid][SPRaioM] = 0;
	PPickup[pgpid][PModelo] = 0;
	PPickup[pgpid][PTipo] = 0;
	PPickup[pgpid][SPRaio] = 0;
    set(PPickup[pgpid][PMSG],"Pickup desativada.");
    gNumPGP--;
    if(gNumPGP == 0) gTimerP = 0;
	return 1;
}

public pgp_DestruirPickupEx(pgpid)
{
	if(PPickup[pgpid][SPickup] == 0) return 0;
	DestroyPickup(pgpid);
	PPickup[pgpid][SPickupF] = 2;
	return 1;
}

public pgp_PickupPGPOn(pgpid)
{
	if(PPickup[pgpid][SPickupF] == 2 || PPickup[pgpid][SPickupF] == 0) return 0;
	return 1;
}

stock pgp_JogadorEstaEmPickup(playerid)
{
	if(pgp_JogadorPickup(playerid) == -1) return 0;
	return 1;
}

public pgp_DestruirPickup(pgpid)
{
	if(pgp_DesativarPickup(pgpid) == 1)
	{
		DestroyPickup(pgpid);
		for(new i; i<MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i))
			{
				if(JogadorPickup[i] == pgpid) JogadorPickup[i] = -1;
				if(JogadorPickupPega[i] == pgpid) JogadorPickupPega[i] = -1;
				if(JogadorEmRaio[i] == pgpid) JogadorEmRaio[i] = -1;
			}
		}
		return 1;
	}
	return 0;
}

stock pgp_PegouPickup(playerid, pgpid)
{
	PegouPickup[playerid] = 1;
	JogadorEmPickup(playerid, pgpid);
	SetTimerEx("pgp_ZerarPickupPega",3000,0,"d",playerid);
}

public pgp_ZerarPickupPega(playerid) if(PegouPickup[playerid] == 1) PegouPickup[playerid] = 0;

public pgp_ZerarGT(playerid) GTJogador[playerid] = 0;

stock pgp_JogadorPickup(playerid) return JogadorPickup[playerid];

stock pgp_JogadorRaio(playerid) return JogadorEmRaio[playerid];

stock pgp_PickupExiste(pickup) return PPickup[pickup][SPickup];

stock pgp_JogadorPickupPega(playerid) return JogadorPickupPega[playerid];

stock pgp_MensagemPickup(pgpid)
{
	new str[256];
	format(str,sizeof(str),"%s",PPickup[pgpid][PMSG]);
	return str;
}

stock PTP(Float:radi, playerid, Float:x, Float:y, Float:z)//PlayerToPoint
{
	new Float:oldposx, Float:oldposy, Float:oldposz;
	new Float:tempposx, Float:tempposy, Float:tempposz;
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);
	tempposx = (oldposx -x);
	tempposy = (oldposy -y);
	tempposz = (oldposz -z);
	if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
	{
		return 1;
	}
	return 0;
}
