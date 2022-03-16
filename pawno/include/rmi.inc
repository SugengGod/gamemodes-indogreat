/*

RevolutioN Mega Include v0.1

*/

#if defined _rmi_included
  #endinput
#endif

#define _rmi_included
#include <a_samp>
#include <a_sampmysql>
#include <revo/md5.own>
//#include <revo/objects.own>
#include <revo/cores.own>
#include <dini>
#include <dudb>

#define FUSE -3
#define COLOR_GRAD1 		  		0xB4B5B7AA
#define COLOR_VERDE_AQUA            0x20B2AAAA
#define COLOR_ROSA2                 0xDDA0DDAA
#define COLOR_ORANGE 				0xFF9900AA
#define COLOR_PURPLE 				0x800080AA
#define COLOR_AZULPLUS          	0x4169FFAA
#define COLOR_VERDECLARO       		0x7FFF00AA
#define COLOR_UNLOGGED         		0xAAAAAAAA
#define COLOR_PALHA            		0xF0E68CAA
#define COLOR_ROSA             		0xFF00FFAA
#define COLOR_EMERGENCIA       		0xD06050AA
#define COLOR_GREEN            		0x33AA33AA
#define COLOR_RED              		0xAA3333AA
#define COLOR_RED2             		0xFF0000AA
#define COLOR_YELLOW           		0xFFFF00AA
#define COLOR_WHITE            		0xFFFFFFAA
#define COLOR_GRAY             		0xAFAFAFAA
#define COLOR_DESEMPREGADO     		0x666666AA
#define COLOR_BARMAN           		0x8B4513AA
#define COLOR_ASSASSINO        		0xA52A2AAA
#define COLOR_VENDEDOR_DE_CARROS  	0x009900AA
#define COLOR_CORRETOR         		0x8FBC8FAA
#define COLOR_SEGURANCA        		0xADD8E6AA
#define COLOR_MOTORISTA  	   		0x33CCFFAA
#define COLOR_MOTORISTA_DE_ONIBUS 	0xF5F5DCAA
#define COLOR_CAMINHONEIRO    		0xE4E4E4AA
#define COLOR_CACADOR          		0xA0522DAA
#define COLOR_PESCADOR   	  		0xE9967AAA
#define COLOR_ENTREGADOR_PIZZA 		0xF0E68CAA
#define COLOR_TAXISTA          		0xFFFF00AA
#define COLOR_MOTOTAXI         		0xFFC000AA
#define COLOR_TAXI_AEREO       		0xFFA500AA
#define COLOR_INSTRUTOR	       		0xDC143CFF
#define COLOR_TRAFICANTE       		0x878009FF
#define COLOR_JORNALISTA      	 	0x800080AA
#define COLOR_PARAMEDICO       		0xF4EED7AA
#define COLOR_ADVOGADO         		0x18585EAA
#define COLOR_COP_MILITAR      		0x0000FFAA
#define COLOR_COP_RODOVIARIO   		0x1F9FBFAA
#define COLOR_COP_FLORESTAL    		0x45804FAA
#define COLOR_COP_SWAT         		0x00C7FFAA
#define COLOR_COP_NARCOTICOS   		0x057ABDAA
#define COLOR_JUIZ             		0x7FFF00AA
#define COLOR_SHERIFF          		0x81694CAA
#define COLOR_LIXEIRO          		0xAFAFAFFF
#define COLOR_TRANSPORTE_DE_VALORES 0x83BFBFAA
#define COLOR_CONTRABANDISTA   		0xFF6347AA
#define COLOR_RECEITA_FEDERAL  		0xB8860BAA
#define COLOR_AGRICULTOR      		0xFFE4C4AA
#define COLOR_LADRAO_DE_CARROS 		0xFF4500AA
#define COLOR_ASSALTANTE      		0x800000AA
#define COLOR_FRENTISTA          	0xFF7F50AA
#define COLOR_LOCADOR_DE_CARROS 	0xADFF2FAA
#define COLOR_PEDREIRA         		0xBC8F8FAA
#define COLOR_VENDEDOR_DE_ARMAS    	0x10F441AA
#define COLOR_MECANICO              0x677594FF
#define COLOR_PROSTITUTA            0xFF00FFAA

//Cores invisíveis

#define COLOR_DESEMPREGADO_INV 			0x66666600
#define COLOR_BARMAN_INV           		0x8B451300
#define COLOR_ASSASSINO_INV        		0xA52A2A00
#define COLOR_VENDEDOR_DE_CARROS_INV  	0x00990000
#define COLOR_CORRETOR_INV         		0x8FBC8F00
#define COLOR_SEGURANCA_INV        		0xADD8E600
#define COLOR_MOTORISTA_INV  	   		0x33CCFF00
#define COLOR_MOTORISTA_DE_ONIBUS_INV 	0xF5F5DC00
#define COLOR_CAMINHONEIRO_INV    		0xE4E4E400
#define COLOR_CACADOR_INV          		0xA0522D00
#define COLOR_PESCADOR_INV   	  		0xE9967A00
#define COLOR_ENTREGADOR_PIZZA_INV 		0xF0E68C00
#define COLOR_TAXISTA_INV          		0xFFFF0000
#define COLOR_MOTOTAXI_INV         		0xFFC00000
#define COLOR_TAXI_AEREO_INV       		0xFFA50000
#define COLOR_INSTRUTOR_INV	       		0xDC143C00
#define COLOR_TRAFICANTE_INV       		0x87800900
#define COLOR_JORNALISTA_INV      	 	0x80008000
#define COLOR_PARAMEDICO_INV       		0xF4EED700
#define COLOR_ADVOGADO_INV         		0x18585E00
#define COLOR_COP_MILITAR_INV      		0x0000FF00
#define COLOR_COP_RODOVIARIO_INV   		0x1F9FBF00
#define COLOR_COP_FLORESTAL_INV    		0x45804F00
#define COLOR_COP_SWAT_INV         		0x00C7FF00
#define COLOR_COP_NARCOTICOS_INV   		0x057ABD00
#define COLOR_JUIZ_INV             		0x7FFF0000
#define COLOR_SHERIFF_INV          		0x81694C00
#define COLOR_LIXEIRO_INV          		0xAFAFAF00
#define COLOR_TRANSPORTE_DE_VALORES_INV 0x83BFBF00
#define COLOR_CONTRABANDISTA_INV   		0xFF634700
#define COLOR_RECEITA_FEDERAL_INV  		0xB8860B00
#define COLOR_AGRICULTOR_INV      		0xFFE4C400
#define COLOR_LADRAO_DE_CARROS_INV 		0xFF450000
#define COLOR_ASSALTANTE_INV      		0x80000000
#define COLOR_FRENTISTA_INV          	0xFF7F5000
#define COLOR_LOCADOR_DE_CARROS_INV 	0xADFF2F00
#define COLOR_PEDREIRA_INV         		0xBC8F8F00
#define COLOR_VENDEDOR_DE_ARMAS_INV    	0x10F44100
#define COLOR_MECANICO_INV              0x67759400
#define COLOR_PROSTITUTA_INV            0xFF00FF00

//Profissões

#define DESEMPREGADO          1//feito
#define BARMAN                2//feito
#define ASSASSINO             3//feito
#define VENDEDOR_DE_CARROS    4//feito
#define CORRETOR              5//feito
#define SEGURANÇA             6//feito
#define MOTORISTA			  7//feito
#define MOTORISTA_DE_ONIBUS   8//feito
#define CAMINHONEIRO          9//feito
#define CACADOR               10//feito
#define PESCADOR              11//feito
#define ENTREGADOR_PIZZA      12//feito
#define TAXISTA               13//feito
#define MOTOTAXI              14//feito
#define TAXI_AEREO            15//feito
#define INSTRUTOR			  16//feito
#define TRAFICANTE            17//feito
#define JORNALISTA            18//feito
#define PARAMEDICO            19//feito
#define ADVOGADO              20//feito
#define COP_MILITAR           21//feito
#define COP_RODOVIARIO        22//feito
#define COP_FLORESTAL         23//feito
#define COP_SWAT              24//feito
#define COP_NARCOTICOS        25//feito
#define JUIZ                  26//feito
#define SHERIFF               27//feito
#define LIXEIRO               28//feito
#define TRANSPORTE_DE_VALORES 29//feito
#define CONTRABANDISTA        30//feito
#define RECEITA_FEDERAL       31//feito
#define AGRICULTOR            32//feito
#define LADRAO_DE_CARROS      33//feito
#define ASSALTANTE            34//feito
#define FRENTISTA             35//feito
#define LOCADOR_DE_CARROS     36//feito
#define PEDREIRA              37//feito
#define VENDEDOR_DE_ARMAS     38//feito
#define MECANICO              39//feito
#define PROSTITUTA            40//feito

//Bancos
#define NUM_BANCOS              9
//Carros
#define QTCARS                  145
//Desmanche
#define MAX_DESMANCHEVEICULO	19
//Zonas
#define MAX_PLAYERS_ 200
//Casino
#define MAX_CASINO      3
new Float:AreaProibida[MAX_CASINO][4] = {
	{1928.1771,987.5739, 1970.5675,1042.8369},
	{2171.3618,1584.2649, 2279.4915,1628.6199},
	{1117.5068,-11.2747, 1142.4843,12.5986}
};
//Loteria
#define PRECO_TICKET 100 // $100 dolares
//Pra nunca mais crashar o servidor em caso de caracteres especiais
#define fixchars(%1) for(new charfixloop=0;charfixloop<strlen(%1);charfixloop++)if(%1[charfixloop]<0)%1[charfixloop]+=256
//define's do velocimetro
#define SPEED   KMPH
#define SLOTS 4
#define CONTRABANDOINI 1
#define CONTRABANDONAVIO 2
#define CONTRABANDONAVIO2 3
#define CONTRABANDORAMPA 4
#define CONTRABANDOFINAL 5
#define NACAMA 1

#define MI_Maleta 1
#define MI_SanFierro 2

forward AssaltoFim(playerid);
forward RouboFim(playerid);
forward AplicarGasosa(playerid,vehicleid,amount);
forward GatesCoordChecker();
forward PortaoCoordChecker();
forward ApplyTuningForVehicle(vehicleid);
forward SetPlayerFree(playerid);
forward AvancoLigacao(plcaller,plcalled);
forward CheckFuel();
forward writelog(log[]);
forward TempoPrisao();
forward Taxi();
forward IsNumeric(const string[]);
forward ATaxi();
forward ColocarNoVeiculoMot(playerid,vehid);
forward MTaxi();
forward Speed();
forward Caca(playerid);
forward Pesca(playerid);
forward Fazenda(playerid);
forward LeiteA(playerid);
forward Prostituir(playerid);
forward Strip(playerid);
forward Strip3(playerid);
forward Strip4(playerid);
forward PlayerPlaySoundEx(playerid,soundid);
forward minrand(min, max);
forward LogarPlayer(playerid);
forward GetClosestHospital(playerid);
forward Tempo();
forward Bancos(playerid);
forward GetPlayerDistanceToPoint(playerid,Float:x,Float:y);
forward Roubo(playerid);
forward open(playerid);
forward Casino();
forward IsStringAName(string[]);
forward GetPlayerID(string[]);
forward CarrosParaAlugar(vehiclemodel_carrosalugar);
forward TempoAlugando(playerid);
forward Desmanche(playerid);
forward strtik(const string[], &index);
forward isPlayerInArea(playerID, Float:data[4]);
forward update_zones();
forward VoteKickTimer();
forward ClearVote(kickedid);
forward Radar();
forward sequestrar();
forward ContrabandoNavio(playerid);
forward Desmancheveiculo();
forward OpenGate(gateid);
forward CloseGate(gateid);
forward OpenPortao(objectid);
forward ClosePortao(objectid);
forward OnPlayerKeyStateChange2(playerid,newkeys,oldkeys);
forward SetarPosicaoDoVeiculo(vehid,Float:X,Float:Y,Float:Z,Float:ang);
forward AltClientMessage(playerid,color,const message[]);
public AltClientMessage(playerid,color,const message[]) SendClientMessage(playerid,color,message);
forward AcaoEspecial(playerid,actionid);
public AcaoEspecial(playerid,actionid) SetPlayerSpecialAction(playerid,actionid);
public SetarPosicaoDoVeiculo(vehid,Float:X,Float:Y,Float:Z,Float:ang){
	SetVehiclePos(vehid,X,Y,Z);
	SetVehicleZAngle(vehid,ang);
}
public ColocarNoVeiculoMot(playerid,vehid) PutPlayerInVehicle(playerid,vehid,0);
forward CriarVeiculo(m,Float:x,Float:y,Float:z,Float:r,c,d,e);

new TravaTextdraw[MAX_PLAYERS];
new PrelAnim[MAX_PLAYERS];
new Abastecendo[MAX_PLAYERS];
new PrevScore[MAX_PLAYERS];
//TEXTDRAWS
new Text:tdMissao1;
new Text:tdMissao2;
new Text:tdMissao3;
new Text:tdVeloCaixa;
new Text:tdVeloTitle;
new Text:tdVeloText[MAX_PLAYERS];
new Text:tdEscuro;
new Text:tdHora;
new Text:tdDesmanche;
new Text:Bemvindo;
new Text:Bemvindo2;
new Text:Bemvindo3;
new Text:Banco;
new Text:Hotel;
new Text:Posto;
new Text:Delegacia;
new Text:Hospital;
new Text:tdCaca;
new Text:tdPesca;
new Text:tdCoopPesca;
new Text:tdAreaCarga;
new Text:tdAreaDescarga;
new Text:tdPlant;
new Text:tdLeite;
new Text:tdColheita;
new Text:tdForte;
new Text:tdPdCarga;
new Text:tdConstrucao;
new Text:td247;
new Text:tdRecarga;
new Text:tdLixao;
new Text:tdStrip;
new Text:GasTD[MAX_PLAYERS];
//---
new OpcionalVelocimetro[MAX_PLAYERS];
new ExibindoVelocimetro[MAX_PLAYERS];
new PassoMissaoInicial[MAX_PLAYERS];
new MostrandoHora[MAX_PLAYERS]=0;
new HospitalInternado[MAX_PLAYERS]=0;
new CarroTrancado[MAX_VEHICLES];
new AluguelFornecedor[MAX_PLAYERS];
new Alarme[MAX_VEHICLES];
new Dono[MAX_VEHICLES][MAX_STRING];
new CellCredits[MAX_PLAYERS];
new AreaDesmanche[MAX_PLAYERS];
new AreaHotel[MAX_PLAYERS];
new AreaDeleg[MAX_PLAYERS];
new AreaHosp[MAX_PLAYERS];
new ftlog[256];
new Float:ppos[MAX_PLAYERS][3];
new PLAYERLIST_authed[MAX_PLAYERS];
new AreaBanco[MAX_PLAYERS];
new AreaCreditos[MAX_PLAYERS];
new MissaoLixeiro[MAX_PLAYERS] = 0;
new LixoColetado[MAX_PLAYERS] = 0;
new AreaLixao[MAX_PLAYERS] = 0;
new PrisaoTimer[MAX_PLAYERS][2];
//Pesca
new AreaPesca[MAX_PLAYERS] = 0;
new Piracema = 0;
new AreaCoopPesca[MAX_PLAYERS] = 0;
new PescaInProgress[MAX_PLAYERS] = 0;
new QtPescas[MAX_PLAYERS] = 0;
//Caça
new TemporadaCaca = 1;
new AreaCaca[MAX_PLAYERS] = 0;
new AreaCoopCaca[MAX_PLAYERS] = 0;
new CacaInProgress[MAX_PLAYERS] = 0;
new QtCacas[MAX_PLAYERS] = 0;
//Sequestro
new Sequestro[MAX_PLAYERS] = 0;
new Cativeiro[MAX_PLAYERS] = 0;
new TempoSequestro[MAX_PLAYERS];
//Caminhoneiros
new AreaCarga[MAX_PLAYERS] = 0;
new AreaDescarga[MAX_PLAYERS] = 0;
new Carregamento[MAX_PLAYERS] = 0;
//Aluguel de carros
new CarroAlugado[MAX_PLAYERS] = 0;
new TempoAlugar[MAX_PLAYERS] = 0;
new TmpAlugar[MAX_PLAYERS] = 0;
new JogadorNoCarro[MAX_PLAYERS] = 0;
new OferecerCarro[MAX_PLAYERS] = 0;
new alugado1;
new alugado2;
new alugado3;
new alugado4;
new alugado5;
new alugado6;
new alugado7;
new alugado8;
new alugado9;
new Pickup_EntradaPol;
new Pickup_SaidaPol;
new Pickup_Entrada247;
new Pickup_Saida247;
new Pickup_EntradaCPD;
new Pickup_SaidaCPD;
new ExPoints[MAX_PLAYERS];
//roubo
new Assalto[MAX_PLAYERS] = 0;
new RouboMao[MAX_PLAYERS] = 0;
//Desmanche
new TempoDesmanche[MAX_PLAYERS] = 0;
//gate
new PortaoFechando[3];
new PortaoAbrindo[3];
new PortaoTimer[3];
new ContagemPortao[3];
new PortaoAberto[3];
new DelegaFechando[3];
new DelegaAbrindo[3];
new DelegaAberto[3];
//Fazenda
new AreaFazenda[MAX_PLAYERS] = 0;
new AreaCoopFazenda[MAX_PLAYERS] = 0;
new FazendaInProgress[MAX_PLAYERS] = 0;
new QtMilho[MAX_PLAYERS] = 0;
new Leite[MAX_PLAYERS] = 0;
new LeiteInProgress[MAX_PLAYERS] = 0;
new QtLeite[MAX_PLAYERS] = 0;
//Transporte
new AreaForte[MAX_PLAYERS] = 0;
new Carga[MAX_PLAYERS] = 0;
//Contrabando
new Contrabando[MAX_PLAYERS];
new CheckpointStatus[MAX_PLAYERS];
new nCheckpointStatus[MAX_PLAYERS];
//Vededor de Armas
new Armas[MAX_PLAYERS];
new Armaoferecida[MAX_PLAYERS] = 0;
//Pedeira
new PedreiraCarga[MAX_PLAYERS] = 0;
new Construcao[MAX_PLAYERS] = 0;
new Pedras[MAX_PLAYERS] = 0;
//defines de coisas
new Menu:Bombshop;
new Menu:Bombshopveh;
new Menu:CPD_First;
new Menu:CPD_Second;
new Menu:CPD_Third;
new Menu:CPD_Fourth;
new Menu:CPD_Fifth;
new Menu:CPD_Sixth;
new AreaBombShop[MAX_PLAYERS];
new DebugKeys[MAX_PLAYERS] = 0;
new Escondido[MAX_PLAYERS] = 0;
new Veiculo[MAX_PLAYERS];
new Previsao;
new Petrol[MAX_PLAYERS];
new AreaPosto[MAX_PLAYERS];
new Presos[MAX_PLAYERS] = 0;
new TempoPreso[MAX_PLAYERS] = 0;
new Profissao[MAX_PLAYERS] = 0;
new Procurados[MAX_PLAYERS] = 0;
new Taximetro[MAX_PLAYERS][2];
new ATaximetro[MAX_PLAYERS][2];
new MTaximetro[MAX_PLAYERS][2];
new PrecoCorrida[MAX_PLAYERS];
new worldMinute;
new worldTime;
new Bebida[MAX_PLAYERS] = 0;
new Maconha[MAX_PLAYERS] = 0;
new Heroina[MAX_PLAYERS] = 0;
new Cocaina[MAX_PLAYERS] = 0;
new Velo[MAX_PLAYERS];
new Velocidade[MAX_PLAYERS];
new Perseguicao[MAX_PLAYERS] = 0;
new Chave[MAX_PLAYERS] = 0;
//Prostituta
new Transacama[MAX_PLAYERS] = 0;
new AreaStrip[MAX_PLAYERS];
new Prostitutacama[MAX_PLAYERS];
new Strip2[MAX_PLAYERS] = 0;
new Prostitutacama2[MAX_PLAYERS];
//Loterias

//REVO-SENA
new ApostaSena[MAX_PLAYERS][100][6];
new ApostasSena[MAX_PLAYERS];
new Acertos[MAX_PLAYERS];
new bool:ApostandoSena[MAX_PLAYERS];
//REVO-QUINA
new ApostaQuina[MAX_PLAYERS][100][5];
new ApostasQuina[MAX_PLAYERS];
new bool:ApostandoQuina[MAX_PLAYERS];
//Casino
new AreaCasino[MAX_PLAYERS];
//Zonas
new zoneupdates[MAX_PLAYERS_];
new player_zone[MAX_PLAYERS_];
new zoneupdate;
//Celular
new CellTimer[MAX_PLAYERS];
new Chamando[MAX_PLAYERS];
new CobrancaCall[MAX_PLAYERS];
new EmLigacao[MAX_PLAYERS];
new CalledID[MAX_PLAYERS];
new LastPN;
new PedindoPizza[MAX_PLAYERS];
new celular[MAX_PLAYERS];
new Agenda[MAX_PLAYERS];
//Mortes lvl
new Kills[MAX_PLAYERS];
new Gates[4];
new Portao[4];
//VoteKick
new KickVote[MAX_PLAYERS];
new VoteKick[MAX_PLAYERS];
new LastVote[MAX_PLAYERS];
new numplayers = 0;

static seta = 1318;
const VEH_MONSTER = 	444; //1
const VEH_CARCOPCS = 	599; //2
const VEH_HYDRA = 		520; //3
const VEH_HPV1000 = 	523; //4
const VEH_SABRE = 		475; //5
const VEH_FCR900 = 	521; //6
const VEH_TAXI = 		420; //7
const VEH_ONIBUS = 	437; //8
const VEH_TURISMO = 	451; //9
const VEH_NRG500 = 	522; //10
const VEH_PHOENIX = 	603; //11
const VEH_SUPERGT = 	506; //12
const VEH_ANDROMADA = 	592; //13
const VEH_MANANA = 	410; //14
const VEH_URANUS =     558; //15
const VEH_GREENWOOD = 	492; //16
const VEH_SLAMVAN = 	535; //17
const VEH_LIXEIRO = 	408; //18
const VEH_CARROFORTE = 428; //19
const VEH_LIMUSINE = 	409; //20
const VEH_MAVERICK = 	487; //21
const VEH_SAVANNA = 	567; //22
const VEH_RCCAM = 		594; //23
const VEH_ADMIRAL = 	445; //24
const VEH_BANSHEE = 	429; //25
const VEH_BFINJECT = 	524; //26
const VEH_BLADE = 		536; //27
const VEH_BLISTAC = 	496; //28
const VEH_BOBCAT = 	422; //29
const VEH_BUFFALO = 	402; //30
const VEH_BULLET = 	541; //31
const VEH_FLASH = 		565; //32
const VEH_INFERNUS = 	411; //33
const VEH_JESTER = 	559; //34
const VEH_LANDSTAL = 	400; //35
const VEH_MESA = 		500; //36
const VEH_STRATUM = 	561; //37
const VEH_TRATOR =     531; //38
const VEH_SANCHEZ =    468; //39
const VEH_BF400 = 		581; //40
const VEH_FAGGIO = 	462; //41
const VEH_PCJ600 = 	461; //42
const VEH_AT400 = 		577; //43
const VEH_SHAMAL = 	519; //44
const VEH_RDTRAIN = 	515; //45
const VEH_HELIPOLICE = 497; //46
const VEH_ELEGY = 		562; //47
const VEH_JETMAX = 	493; //48
const VEH_MARQUIS = 	484; //49
const VEH_REEFER = 	453; //50
const VEH_FREEWAY = 	463; //51
const VEH_BIKE = 		509; //52
const VEH_MTBIKE =     510; //53
const VEH_BMX =        481; //54
const VEH_NEWSVAN =    582; //55
const VEH_WALTON =     478; //56
const VEH_SPARROW =    469; //57
const VEH_PETROLTRAI = 584; //58
const VEH_AMBULANCIA = 416; //59
const VEH_TRAM =       449; //60
const VEH_JOURNEY =    508; //61
const VEH_DUMPER =     406; //62
const VEH_PIZZABOY =   448; //63
const VEH_DODO =       593; //64
const VEH_ELEGANT =    507; //65
const VEH_RCBARON =    464; //66
const VEH_RCGOBLIN =   501; //67
const VEH_REBOQUE =    525; //68
const VEH_MAJESTIC =   517; //69
const VEH_ARTICTRAI =  435; //70

new VeiculosPermitidos[70] = {
VEH_MONSTER,
VEH_CARCOPCS,
VEH_HYDRA,
VEH_HPV1000,
VEH_SABRE,
VEH_FCR900,
VEH_TAXI,
VEH_ONIBUS,
VEH_TURISMO,
VEH_NRG500,
VEH_PHOENIX,
VEH_SUPERGT,
VEH_ANDROMADA,
VEH_MANANA,
VEH_URANUS,
VEH_GREENWOOD,
VEH_SLAMVAN,
VEH_LIXEIRO,
VEH_CARROFORTE,
VEH_LIMUSINE,
VEH_MAVERICK,
VEH_SAVANNA,
VEH_RCCAM,
VEH_ADMIRAL,
VEH_BANSHEE,
VEH_BFINJECT,
VEH_BLADE,
VEH_BLISTAC,
VEH_BOBCAT,
VEH_BUFFALO,
VEH_BULLET,
VEH_FLASH,
VEH_INFERNUS,
VEH_JESTER,
VEH_LANDSTAL,
VEH_MESA,
VEH_STRATUM,
VEH_TRATOR,
VEH_SANCHEZ,
VEH_BF400,
VEH_FAGGIO,
VEH_PCJ600,
VEH_AT400,
VEH_SHAMAL,
VEH_RDTRAIN,
VEH_HELIPOLICE,
VEH_ELEGY,
VEH_JETMAX,
VEH_MARQUIS,
VEH_REEFER,
VEH_FREEWAY,
VEH_BIKE,
VEH_MTBIKE,
VEH_BMX,
VEH_NEWSVAN,
VEH_WALTON,
VEH_SPARROW,
VEH_PETROLTRAI,
VEH_AMBULANCIA,
VEH_TRAM,
VEH_JOURNEY,
VEH_DUMPER,
VEH_PIZZABOY,
VEH_DODO,
VEH_ELEGANT,
VEH_RCBARON,
VEH_RCGOBLIN,
VEH_REBOQUE,
VEH_MAJESTIC,
VEH_ARTICTRAI,
};
stock IsValidModel(modelid)
{
	new allow;
	for(new m; m<sizeof VeiculosPermitidos; m++)
		if(modelid == VeiculosPermitidos[m]) allow=1;
	return allow;
}
new GPV[MAX_VEHICLES];
new CPD_cp1,CPD_cp2,CPD_cp3,CPD_cp4,CPD_cp5,CPD_cp6;
new bancoscp[NUM_BANCOS];
new Float:bancospos[NUM_BANCOS][3] = {
	{-2446.8564,522.0898,30.2816},
	{1721.8188,-1718.9016,13.5341},
	{398.1302,-1805.6890,7.8380},
	{1309.5111,-1370.3267,13.5731},
	{-1600.3402,872.6577,9.2298},
	{1022.5526,-1122.4902,23.8712},
	{2091.0146,2053.3230,10.8203},
	{2408.9451,1987.9479,10.8203},
	{-184.7314,1133.2028,19.7422}
};

new Float:HotelPos[4][8] = {
	{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
	{-1781.7557,-1728.1963,939.8461,963.0589,-1757.7770,960.1347,24.8828,180.0},
	{-1979.7885,-1908.2384,409.2338,574.5917,-1964.1333,531.8960,35.1719,90.2509},
	{-2438.9146,-2381.5166,308.4261,354.4076,-2413.9404,329.9223,34.9755,249.5154}
};

#include <cpstream02>
stock IsInBank(playerid)
{
	new is;
	for(new b; b<NUM_BANCOS; b++) if(CPS_IsPlayerInCheckpoint(playerid,bancoscp[b])) is=1;
	return is;
}

stock MissaoInicial(playerid)
{
	CPS_SetStreamActiveForPlayer(playerid,false);
	SetTimerEx("MensagemMI",2000,false,"dd",playerid,1);
	SetTimerEx("MensagemMI",7000,false,"dd",playerid,2);
	SetTimerEx("MensagemMI",12000,false,"dd",playerid,3);
	SetTimerEx("MensagemMI",13000,false,"dd",playerid,4);
	SetTimerEx("MensagemMI",20000,false,"dd",playerid,5);
	SetTimerEx("MensagemMI",25000,false,"dd",playerid,6);
	SetTimerEx("MensagemMI",28000,false,"dd",playerid,7);
	SetTimerEx("MensagemMI",34000,false,"dd",playerid,8);
	SetTimerEx("MensagemMI",38000,false,"dd",playerid,9);
	SetTimerEx("MensagemMI",40000,false,"dd",playerid,10);
}

forward MensagemMI(playerid,id);
public MensagemMI(playerid,id)
{
	switch(id)
	{
	    case 1: SendClientMessage(playerid,COLOR_WHITE,"Já estou cansado dessa vida... essa cidade está muito pequena para mim!");
	    case 2: SendClientMessage(playerid,COLOR_WHITE,"Olhe só, nada de decente, o puteiro fica a milhas de distância...");
	    case 3: SendClientMessage(playerid,COLOR_WHITE,"Embora eu tenha nascido aqui, eu tenho a ambição de sempre querer mais");
	    case 4: SendClientMessage(playerid,COLOR_WHITE,"ir além dos meus limites, enfim, ser o melhor.");
		case 5: SendClientMessage(playerid,COLOR_WHITE,"Nessa pobreza toda eu nunca vou conseguir alcançar meus sonhos.");
		case 6: SendClientMessage(playerid,COLOR_WHITE,"Preciso de um lugar melhor para viver.");
		case 7: SendClientMessage(playerid,COLOR_WHITE,"Já sei! San Fierro é o lugar! Isso! Como eu fui um otário durante esses anos todos...");
		case 8: SendClientMessage(playerid,COLOR_WHITE,"Sim, San Fierro, o lugar de onde meu falecido pai nunca deveria ter saído!");
		case 9: SendClientMessage(playerid,COLOR_WHITE,"Vou pegar minhas malas e começar uma vida longe daqui!");
		case 10: {
		    TextDrawShowForPlayer(playerid,tdMissao1);
			SetPlayerCheckpoint(playerid,-154.0990,1183.9434,19.7422,2.0);
			PassoMissaoInicial[playerid] = MI_Maleta;
		}
		case 11: {
		    PassoMissaoInicial[playerid] = 3;
		    TextDrawShowForPlayer(playerid,tdMissao2);
			CPS_SetStreamActiveForPlayer(playerid,true);
		}
		case 12: {
		    CPS_SetStreamActiveForPlayer(playerid,false);
		    TextDrawShowForPlayer(playerid,tdMissao3);
		    SetPlayerCheckpoint(playerid,-1612.2537,785.3365,7.1875,2.0);
		    PassoMissaoInicial[playerid] = MI_SanFierro;
		}
	}
}

stock CriarCheckpoints()
{
    CPD_cp1 = CPS_AddCheckpoint(362.7719,173.7793,1008.3828,2.0,40);
	CPD_cp2 = CPS_AddCheckpoint(361.8476,205.0786,1008.3828,2.0,40);
	CPD_cp3 = CPS_AddCheckpoint(355.6021,161.8357,1019.9844,2.0,40);
	CPD_cp4 = CPS_AddCheckpoint(362.6747,171.6730,1025.7891,2.0,40);
	CPD_cp5 = CPS_AddCheckpoint(362.8526,151.2095,1025.7964,2.0,40);
	CPD_cp6 = CPS_AddCheckpoint(354.8842,172.7762,1025.7964,2.0,40);
	for(new i; i<NUM_BANCOS; i++) bancoscp[i] = CPS_AddCheckpoint(bancospos[i][0],bancospos[i][1],bancospos[i][2],2.0,40);
}

//[Arrays necessárias]
new Float:Celas[][] = {
	{227.6684,110.1895,999.0156},
	{223.0134,110.3193,999.0156},
	{219.3730,110.2772,999.0156},
	{214.9654,109.4626,999.0156}
};


//Lixeiras
new Float:LixeirasCheckpoints[74][3] = {
	{-161.0533,1174.8231,19.7422},
	{-169.9686,1170.0933,19.7500},
	{-89.5499,1127.7946,19.7422},
	{-219.0813,1165.2712,19.7422},
	{-168.9296,1027.2073,19.7344},
	{-122.5816,1080.0015,19.7788},
	{-2488.3569,2539.0354,18.0562},
	{2255.8774,2527.1499,10.8203},
	{2262.2607,2564.5474,10.8202},
	{2544.5713,2318.8320,10.8133},
	{2515.2197,2316.5542,10.8203},
	{2551.1072,2244.9885,10.8203},
	{2597.4719,2077.3086,10.8203},
	{2597.2158,2071.3884,10.8130},
	{2597.1104,2044.9716,10.8203},
	{2675.5828,1705.6161,10.8203},
	{2675.1670,1666.3903,10.8203},
	{2675.4636,1826.3031,10.8203},
	{2657.7800,1940.8837,10.8203},
	{2179.8164,1419.4374,10.8203},
	{1678.4476,1166.3718,10.8203},
	{1687.4487,1251.3823,10.7490},
	{1519.2963,979.4398,10.8203},
	{1519.4396,972.1034,10.8203},
	{1558.8448,969.7551,10.8203},
	{1667.0028,912.7361,10.7148},
	{1637.2725,892.1777,10.7225},
	{1633.1637,665.1866,10.8203},
	{1665.8140,2056.2122,10.8203},
	{1660.8794,2085.2131,10.8203},
	{1664.2474,2108.1174,10.8203},
	{724.8134,-465.3358,16.3359},
	{780.9294,-595.2310,16.3359},
	{195.1865,-180.0826,1.5781},
	{160.5844,-175.5925,1.5781},
	{253.9077,-160.7479,1.5703},
	{253.8341,-153.9057,1.5703},
	{255.5944,-133.8832,1.5781},
	{260.1812,-133.7466,1.5781},
	{266.9190,-134.0600,1.5781},
	{245.0523,-43.5894,1.5853},
	{343.1069,-78.5039,1.4234},
	{345.3282,-102.9888,1.3436},
	{1416.9526,270.7458,19.5618},
	{1352.1171,203.1920,19.5547},
	{1369.9030,199.2469,19.5547},
	{1299.1567,220.7018,19.5547},
	{2273.0247,64.2270,26.4844},
	{654.6854,-440.0193,16.3359},
	{694.5139,-455.8463,16.3359},
	{653.7773,-497.6555,16.3359},
	{666.7076,-623.6600,16.3359},
	{777.5923,1866.4501,4.8751},
	{2491.7952,-1655.3499,13.3762},
	{2399.7366,-1722.5333,13.1659},
	{2177.8809,-1343.1554,23.9844},
	{805.7858,-1057.6353,24.7345},
	{1068.4235,-1132.6014,23.8281},
	{539.5020,-1261.1362,16.4641},
	{498.0841,-1294.5765,15.6489},
	{401.2081,-1339.0613,14.2121},
	{545.0730,-1518.8091,14.4370},
	{951.6190,-978.9124,38.8653},
	{1075.7140,-963.9644,42.3192},
	{1146.1953,-959.1254,42.5880},
	{1245.9070,-943.1398,42.4271},
	{1780.9406,-1180.0648,23.8281},
	{1723.9698,-1270.5125,13.5469},
	{1461.4204,-1488.4612,13.5469},
	{1698.8551,-1720.3446,13.1159},
	{1919.9664,-2123.1597,13.5849},
	{1919.7251,-2088.1360,13.5803},
	{1337.6675,-1773.3949,13.5469},
	{1337.6957,-1842.7949,13.5469}
};
//[Arrays necessárias]
new ProfLevel[] = {
	0,
	0,
	0,
	10,
	100,
	100,
	20,
	30,
	20,
	30,
	10,
	10,
	0,
	0,
	0,
	20,
	90,
	50,
	30,
	40,
	100,
	90,
	90,
	80,
	110,
	90,
	150,
	140,
	10,
	40,
	60,
	70,
	50,
	40,
	30,
	30,
	70,
    20,
    60,
    70,
    50
};
new ProfExtName[][] = {
	"Inválida",
	"Desempregado",
	"Barman",
	"Assassino",
	"Vendedor de carros",
	"Corretor",
	"Segurança",
	"Motorista Particular",
	"Motorista De Ônibus",
	"Caminhoneiro",
	"Caçador",
	"Pescador",
	"Entregador De Pizza",
	"Taxista",
	"Mototaxista",
	"Taxista Aéreo",
	"Instrutor De Direção",
	"Traficante",
	"Jornalista",
	"Paramédico",
	"Advogado",
	"Cop Militar",
	"Cop Rodoviário",
	"Cop Florestal",
	"Cop Elite/SWAT",
	"Cop Narcoticos",
	"Juiz",
	"Xerife",
	"Lixeiro",
	"Transporte De Valores",
	"Contrabandista",
	"Receita Federal",
 	"Agricultor",
 	"Ladrão De Carros",
 	"Assaltante",
 	"Frentista",
 	"Locador De Carros",
 	"Pedreira",
 	"Vendedor De Armas",
 	"Mecânico",
 	"Prostituta"
};
new ProfGT[][] = {
	"Inv˜lida",
	"Desempregado",
	"Barman",
	"Assassino",
	"Vendedor de carros",
	"Corretor",
	"Seguranœa",
	"Motorista Particular",
	"Motorista de §nibus",
	"Caminhoneiro",
	"Caœador",
	"Pescador",
	"Entregador de Pizza",
	"Taxista",
	"Mototaxista",
	"Taxista Ažreo",
	"Instrutor de Direœšo",
	"Traficante",
	"Jornalista",
	"Paramždico",
	"Advogado",
	"Pol¢cia Militar",
	"Pol¢cia Rodovi˜ria",
	"Pol¢cia Florestal",
	"Pol¢cia SWAT",
	"Pol¢cia Narc¦ticos",
	"Juiz",
	"Xerife",
	"Lixeiro",
	"Transporte De Valores",
	"Contrabandista",
	"Receita Federal",
 	"Agricultor",
 	"Ladršo de Carros",
 	"Assaltante",
 	"Frentista",
 	"Locador De Carros",
 	"Pedreira",
 	"Vendedor De Armas",
 	"Mecanico",
 	"Prostituta"
};
new IntSalario[] = {
	0,
	350,
	800,
	400,
	350,
	350,
	1000,
	2000,
	2000,
	1500,
	2000,
	1500,
	900,
	2000,
	1000,
	1500,
	850,
	1000,
	1500,
	1000,
	1000,
	1500,
	1400,
	1800,
	2000,
	2000,
	4000,
	4500,
	1000,
	1200,
	800,
	3000,
	1200,
	1000,
	600,
	1200,
	1000,
	1500,
	1400,
	1000,
	800
};
new StringsSalario[][] = {
	"invalido",
	"Seu seguro desemprego foi depositado, nao vai procurar emprego? $350",
	"O BAR para o qual você trabalha depositou seu salário: $800",
	"A Agência de crimes de San Andreas depositou seu salário $400",
	"A revendedora [MPA] veículos depositou seu salário: $350",
	"A imobiliaria San fierro imoveis depositou seu salário: $350",
	"A SegurityLife depositou seu salário: $1000",
	"A empresa LuxLimosine depositou seu salárioo: $2000",
	"A Companhia de Onibûs depositou seu salário: $2000",
	"A cooperativa de caminhoneiros depositou seu salário mensal: $1500",
	"Salário da cooperativa recebido: $2000",
	"A cooperativa ja depositou seu salário: $1500",
	"A pizzaria depositou seu salário: $900",
	"Seu salário governamental foi depositado: $2000",
	"Você recebeu seu salário depostiado pela companhia: $1000",
	"A companhia de taxi areo depositou seu salário: $1500",
	"A Auto-escola ja depostiou seu salário: $850",
	"Você ja recebeu a grana da boca de fumo que você comanda: $1000",
	"A editora do jornal FOLHA DE SAN ANDREAS depositou seu salário: $1500",
	"O hospital depositou seu salário: $1000",
	"Seu salário governamental foi depositado: $1000",
	"Seu salário governamental foi depositado: $1200",
	"Seu salário governamental foi depositado: $1400",
	"Seu salário governamental foi depositado: $1800",
	"Seu salário governamental foi depositado: $2000",
	"Seu salário governamental foi depositado: $2000",
	"Seu salário governamental foi depositado: $4000",
	"A prefeitura de Fort Carson depositou seu salário: $4500",
	"O lixão de San Andreas depositou seu salário: $1000",
	"A Central 24/7 depositou seu salário: $1200",
	"Contrabando lhe gerou: $800",
	"A prefeitura de Fort Carson depositou seu salário: 3000",
	"A fazenda depositou seu salário: $1200",
	"O seu desmanche rendeu: $1000",
	"A partilha dos roubos deu: $600",
	"A Motos S/A LTDA depositou seu salário: $1200",
	"A San Andreas Company CAR depositou seu salário: $1000",
	"A Pedreira de SA depositou seu salário: $1500",
	"A Ammu Nation depositou seu salário: $1400",
	"A Pay 'n' Spray depositou seu salário: $1000",
	"A Boate depositou seu salário: $800"
};
new ProfColors[] = {
	COLOR_UNLOGGED,
	COLOR_DESEMPREGADO,
	COLOR_BARMAN,
	COLOR_ASSASSINO,
	COLOR_VENDEDOR_DE_CARROS,
	COLOR_CORRETOR,
	COLOR_SEGURANCA,
	COLOR_MOTORISTA,
	COLOR_MOTORISTA_DE_ONIBUS,
	COLOR_CAMINHONEIRO,
	COLOR_CACADOR,
	COLOR_PESCADOR,
	COLOR_ENTREGADOR_PIZZA,
	COLOR_TAXISTA,
	COLOR_MOTOTAXI,
	COLOR_TAXI_AEREO,
	COLOR_INSTRUTOR,
	COLOR_TRAFICANTE,
	COLOR_JORNALISTA,
	COLOR_PARAMEDICO,
	COLOR_ADVOGADO,
	COLOR_COP_MILITAR,
	COLOR_COP_RODOVIARIO,
	COLOR_COP_FLORESTAL,
	COLOR_COP_SWAT,
	COLOR_COP_NARCOTICOS,
	COLOR_JUIZ,
	COLOR_SHERIFF,
    COLOR_LIXEIRO,
    COLOR_TRANSPORTE_DE_VALORES,
    COLOR_CONTRABANDISTA,
    COLOR_RECEITA_FEDERAL,
    COLOR_AGRICULTOR,
    COLOR_LADRAO_DE_CARROS,
    COLOR_ASSALTANTE,
    COLOR_FRENTISTA,
    COLOR_LOCADOR_DE_CARROS,
    COLOR_PEDREIRA,
    COLOR_VENDEDOR_DE_ARMAS,
    COLOR_MECANICO,
    COLOR_PROSTITUTA
};
new ProfInvColors[] = {
	COLOR_UNLOGGED,
	COLOR_DESEMPREGADO_INV,
	COLOR_BARMAN_INV,
	COLOR_ASSASSINO_INV,
	COLOR_VENDEDOR_DE_CARROS_INV,
	COLOR_CORRETOR_INV,
	COLOR_SEGURANCA_INV,
	COLOR_MOTORISTA_INV,
	COLOR_MOTORISTA_DE_ONIBUS_INV,
	COLOR_CAMINHONEIRO_INV,
	COLOR_CACADOR_INV,
	COLOR_PESCADOR_INV,
	COLOR_ENTREGADOR_PIZZA_INV,
	COLOR_TAXISTA_INV,
	COLOR_MOTOTAXI_INV,
	COLOR_TAXI_AEREO_INV,
	COLOR_INSTRUTOR_INV,
	COLOR_TRAFICANTE_INV,
	COLOR_JORNALISTA_INV,
	COLOR_PARAMEDICO_INV,
	COLOR_ADVOGADO_INV,
	COLOR_COP_MILITAR_INV,
	COLOR_COP_RODOVIARIO_INV,
	COLOR_COP_FLORESTAL_INV,
	COLOR_COP_SWAT_INV,
	COLOR_COP_NARCOTICOS_INV,
	COLOR_JUIZ_INV,
	COLOR_SHERIFF_INV,
    COLOR_LIXEIRO_INV,
    COLOR_TRANSPORTE_DE_VALORES_INV,
    COLOR_CONTRABANDISTA_INV,
    COLOR_RECEITA_FEDERAL_INV,
    COLOR_AGRICULTOR_INV,
    COLOR_LADRAO_DE_CARROS_INV,
    COLOR_ASSALTANTE_INV,
    COLOR_FRENTISTA_INV,
    COLOR_LOCADOR_DE_CARROS_INV,
    COLOR_PEDREIRA_INV,
    COLOR_VENDEDOR_DE_ARMAS_INV,
    COLOR_MECANICO_INV,
    COLOR_PROSTITUTA_INV
};
new Float:Hospitais[5][4] = {
	    {-2651.6501,634.1177,14.4531,180.0},//Hospital de SF
		{1173.5842,-1324.5615,15.1953,15.19},
		{2031.9415,-1404.3578,17.2614,17.2614},
		{1582.5615,1768.7921,10.8203,93.7454},
		{-320.7639,1065.8195,19.7422,136.0}
};
new Float:ProfPos[41][3] = {
	{223.0134,110.3193,999.0156},//Nothing
	{-1612.2537,785.3365,7.1875},//Desempregado
	{-2244.2957,-88.5787,35.3203},//Barman
	{-2179.8931,610.6476,35.1641},//Assassino
	{-1612.2537,785.3365,7.1875},//Vendedor
	{-1612.2537,785.3365,7.1875},//Corretor
	{-1612.2537,785.3365,7.1875},//Segurança
	{-1612.2537,785.3365,7.1875},//Motorista
	{-1984.6200,137.6697,27.6875},//MOnibus
	{634.2159,1682.4813,6.9922},//Caminhoneiro
	{-1612.2537,785.3365,7.1875},//Caçador
	{-1740.9624,1428.7847,7.1875},//Pescador
	{-1807.3835,944.6384,24.8906},//EPizza
	{-1984.6200,137.6697,27.6875},//Taxi
	{-1984.6200,137.6697,27.6875},//MTaxi
	{-1984.6200,137.6697,27.6875},//ATaxi
	{-2026.5381,-99.2734,35.1641},//Instrutor
	{-2179.8931,610.6476,35.1641},//Traficante
	{-2229.2561,251.0785,35.3203},//Jornalista
	{-2651.6501,634.1177,14.4531},//Paramédico
	{-2699.4666,375.9366,4.3767},//Advogado
	{-1605.7092,711.6038,13.8672},//Polícia Militar
	{-1605.7092,711.6038,13.8672},//Polícia Rodoviária
	{-1605.7092,711.6038,13.8672},//Polícia Florestal
	{-1605.7092,711.6038,13.8672},//Polícia Swat/Elite
	{-1605.7092,711.6038,13.8672},//Polícia Narcoticos
	{-2699.4666,375.9366,4.3767},//Juiz
	{-1605.7092,711.6038,13.8672},//Xerife
	{-1859.1014,-1650.5037,26.6171},//Lixeiro
	{2546.9211,1963.0864,10.8203},//Transporte de Valores
	{-2179.8931,610.6476,35.1641},//Contrabandista
	{1481.0403,-1768.0181,18.7958},//Receita Federal
	{-1060.5527,-1195.2561,129.5891},//Agricultor
	{-2179.8931,610.6476,35.1641},//Ladrão de carros
	{-2179.8931,610.6476,35.1641},//Assaltante
	{-301.3666,1164.5613,19.9462},//FRENTISTA
	{-1641.6865,1204.1100,7.2496},//Locador de Carros
	{817.2215,856.4513,12.7891},//Pedreira
	{-2626.3306,210.8499,4.6054},//Vendedor de Armas
	{-2025.1118,156.8193,28.8359},//Mecânico
	{-2624.7446,1409.4442,7.0938}//PROSTITUTA
};
new ProfSkin[] = {
	0,//Nothing
	0,//Desempregado
	171,//Barman
	127,//Assassino
	187,//Vendedor
	59,//Corretor
	165,//Segurança
	255,//Motorista Particular
	112,//Motorista De Onibus
	95,//Caminhoneiro
	58,//Caçador
	128,//Pescador
	155,//Entregador De Pizza
	234,//Taxista
	52,//Moto-Taxi
	61,//Aero-Taxi
	188,//Instrutor
	28,//Traficante
	37,//Jornalista
	276,//Paramedico
	147,//Advogado
	282,//COP Militar
	283,//COP Rodoviário
	288,//COP Florestal
 	285,//COP Swat
 	126,//COP Narcóticos
	57,//Juiz
	34,//Sheriff
	137,//Lixeiro
	71,//Transportador De Valores
	127,//Contrabandista
	165,//Receita Federal
	159,//Agricultor
	22,//Ladrão De Carros
	19,//Assaltante
	59,//FRENTISTA
	147,//Locador De Carros
	27,//Pedreira
	179,//Vendedor de Armas
	50,//Mecânico
	246//Prostituta
};
new WeatherName[][] = {
	"Super ensolarado, 40 graus",
	"Ensolarado, 30 graus",
	"Super ensolarado, com smog, 35 graus",
	"Ensolarado, com smog, 29 graus",
	"Nublado, 25 graus",
	"Ensolarado, 30 graus",
	"Super ensolarado, 40 graus",
	"Nublado, 25 graus",
	"Tempestade, ventos fortes e trovões, 20 graus",
	"Neblina, 15 graus",
	"Ensolarado, 35 graus",
	"Super ensolarado, 45 graus",
	"Nublado, 30 graus",
	"Super ensolarado, 38 graus",
	"Ensolarado, 28 graus",
	"Nublado, 24 graus",
	"Chuvoso, 22 graus",
	"Super ensolarado, 50 graus",
	"Ensolarado, 40 graus",
	"Tempestade de areia, 45 graus"
};
//Armas Nomes
new weaponname[][] = {
	"Mão livre",
	"Soco Inglês",
	"Taco de Golfe",
	"Cacetete",
	"Faca",
	"Taco de Baseball",
	"Shovel",
	"Taco de Sinuca",
	"Katana",
	"Motosserra",
	"Vibrador roxo de duas pontas",
	"Vibrador branco grande",
	"Vibrador branco médio",
	"Vibrador prata pequeno",
	"Flores",
	"Bengala",
	"Granada",
	"Teargas",
	"Coquetel Molotov",
	"Lança Foguetes",
	"Lança-Foguetes Tele-guiado",
	"Hydra Rocket",
	"Pistola",
	"Silenced Pistol",
	"Desert Eagle",
	"Escopeta Calibre 12",
	"Escopeta de Cano Serrado",
	"Escopeta de Combate",
	"Micro Uzi",
	"MP5",
	"AK47",
	"M4",
	"Tec9",
	"Country Rifle"
};
new valorarma[] = {
	0,
	500,
	600,
	650,
	750,
	350,
	400,
	300,
	800,
	1000,
	100,
	100,
	100,
	100,
	100,
	150,
	300,
	300,
	0,
	0,
	0,
	0,
	800,
	1000,
	3000,
	1800,
	6000,
	7500,
	8000,
	5500,
	7500,
	9000,
	8000,
	4000
};
new armamuni[] = {
	0,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	4,
	4,
	0,
	0,
	0,
	0,
	100,
	100,
	100,
	46,
	80,
 	80,
 	300,
 	300,
  	150,
  	150,
  	300,
  	80,
  	0
};

new ProfWeapons[][8] = {
	{0,0,0,0,0,0,0,0},//nothing
	{41,500,5,0,0,0,0,0},//desempregado
	{2,1,41,100,0,0,0,0},//barman
	{6,1,4,1,23,350,0,0},//assassino
	{2,1,14,5,0,0,0,0},//vendedor
	{15,1,41,500,14,1,0,0},//corretor
	{24,350,3,1,0,0,0,0},//segurança
	{5,1,41,500,0,0,0,0},//motorista particular
	{42,400,5,1,0,0,0,0},//motorista de onibus
	{41,500,5,1,0,0,0,0},//caminhoneiro
	{33,100,4,1,0,0,0,0},//caçador
	{4,1,42,500,0,0,0,0},//pescador
	{46,1,5,1,41,500,14,1},//entregador
	{42,500,5,0,0,0,0,0},//taxista
	{5,1,42,100,14,1,0,0},//mototaxi
   	{24,100,42,100,46,1,0,0},//taxi aereo
	{14,1,42,1,5,1,0,0},//instrutor
	{22,355,41,600,4,1,0,0},//traficante
	{2,1,46,1,5,1,0,0},//jornalista
	{41,500,5,1,0,0,0,0},//paramédico
	{14,1,15,1,24,60,0,0},//advogado
	{3,1,24,500,25,100,0,0},//cop militar
	{3,1,24,500,32,300,25,100},//rodoviario
	{3,1,24,500,32,300,25,100},//florestal
	{29,300,24,500,27,100,31,300},//swat
	{3,1,24,500,25,100,0,0},//cop narcoticos
	{15,1,22,300,0,0,0,0},//juíz
	{24,500,32,300,25,100,0,0},//xerife
	{32,400,24,60,7,1,0,0},//lixeiro
	{24,60,25,80,0,0,0,0},//transporte valores
	{28,400,4,1,23,80,0,0},//contrabandista
	{27,400,3,1,24,100,0,0},//receita
	{33,80,6,1,0,0,0,0},//agricultor
	{22,100,1,1,28,500,0,0},//ladrao carros
	{29,400,24,60,4,1,0,0},//assaltante
	{29,460,22,60,5,1,4,1},//frentista
	{29,400,5,1,24,80,0,0},//locador
	{42,400,5,1,22,100,0,0},//pedreira
	{29,460,24,60,0,0,0,0},//vendedor armas
	{29,460,22,60,5,1,4,1},//mecanico
	{29,460,22,60,5,1,4,1}
};

// ZONES
enum zoneinfo {
	zone_name[27],
    Float:zone_minx,
    Float:zone_miny,
    Float:zone_minz,
    Float:zone_maxx,
    Float:zone_maxy,
    Float:zone_maxz
}

new Float:zones[][zoneinfo] = {
{ "'The Big Ear'",                -410.00,  1403.30,    -3.00,  -137.90,  1681.20,   200.00},
{ "Aldea Malvada",               -1372.10,  2498.50,     0.00, -1277.50,  2615.30,   200.00},
{ "Angel Pine",                  -2324.90, -2584.20,    -6.10, -1964.20, -2212.10,   200.00},
{ "Arco del Oeste",               -901.10,  2221.80,     0.00,  -592.00,  2571.90,   200.00},
{ "Avispa Country Club",         -2646.40,  -355.40,     0.00, -2270.00,  -222.50,   200.00},
{ "Avispa Country Club",         -2831.80,  -430.20,    -6.10, -2646.40,  -222.50,   200.00},
{ "Avispa Country Club",         -2361.50,  -417.10,     0.00, -2270.00,  -355.40,   200.00},
{ "Avispa Country Club",         -2667.80,  -302.10,   -28.80, -2646.40,  -262.30,    71.10},
{ "Avispa Country Club",         -2470.00,  -355.40,     0.00, -2270.00,  -318.40,    46.10},
{ "Avispa Country Club",         -2550.00,  -355.40,     0.00, -2470.00,  -318.40,    39.70},
{ "Back o Beyond",               -1166.90, -2641.10,     0.00,  -321.70, -1856.00,   200.00},
{ "Battery Point",               -2741.00,  1268.40,    -4.50, -2533.00,  1490.40,   200.00},
{ "Bayside",                     -2741.00,  2175.10,     0.00, -2353.10,  2722.70,   200.00},
{ "Bayside Marina",              -2353.10,  2275.70,     0.00, -2153.10,  2475.70,   200.00},
{ "Beacon Hill",                  -399.60, -1075.50,    -1.40,  -319.00,  -977.50,   198.50},
{ "Blackfield",                    964.30,  1203.20,   -89.00,  1197.30,  1403.20,   110.90},
{ "Blackfield",                    964.30,  1403.20,   -89.00,  1197.30,  1726.20,   110.90},
{ "Blackfield Chapel",            1375.60,   596.30,   -89.00,  1558.00,   823.20,   110.90},
{ "Blackfield Chapel",            1325.60,   596.30,   -89.00,  1375.60,   795.00,   110.90},
{ "Blackfield Intersection",      1197.30,  1044.60,   -89.00,  1277.00,  1163.30,   110.90},
{ "Blackfield Intersection",      1166.50,   795.00,   -89.00,  1375.60,  1044.60,   110.90},
{ "Blackfield Intersection",      1277.00,  1044.60,   -89.00,  1315.30,  1087.60,   110.90},
{ "Blackfield Intersection",      1375.60,   823.20,   -89.00,  1457.30,   919.40,   110.90},
{ "Blueberry",                     104.50,  -220.10,     2.30,   349.60,   152.20,   200.00},
{ "Blueberry",                      19.60,  -404.10,     3.80,   349.60,  -220.10,   200.00},
{ "Blueberry Acres",              -319.60,  -220.10,     0.00,   104.50,   293.30,   200.00},
{ "Caligula's Palace",            2087.30,  1543.20,   -89.00,  2437.30,  1703.20,   110.90},
{ "Caligula's Palace",            2137.40,  1703.20,   -89.00,  2437.30,  1783.20,   110.90},
{ "Calton Heights",              -2274.10,   744.10,    -6.10, -1982.30,  1358.90,   200.00},
{ "Chinatown",                   -2274.10,   578.30,    -7.60, -2078.60,   744.10,   200.00},
{ "City Hall",                   -2867.80,   277.40,    -9.10, -2593.40,   458.40,   200.00},
{ "Come-A-Lot",                   2087.30,   943.20,   -89.00,  2623.10,  1203.20,   110.90},
{ "Commerce",                     1323.90, -1842.20,   -89.00,  1701.90, -1722.20,   110.90},
{ "Commerce",                     1323.90, -1722.20,   -89.00,  1440.90, -1577.50,   110.90},
{ "Commerce",                     1370.80, -1577.50,   -89.00,  1463.90, -1384.90,   110.90},
{ "Commerce",                     1463.90, -1577.50,   -89.00,  1667.90, -1430.80,   110.90},
{ "Commerce",                     1583.50, -1722.20,   -89.00,  1758.90, -1577.50,   110.90},
{ "Commerce",                     1667.90, -1577.50,   -89.00,  1812.60, -1430.80,   110.90},
{ "Conference Center",            1046.10, -1804.20,   -89.00,  1323.90, -1722.20,   110.90},
{ "Conference Center",            1073.20, -1842.20,   -89.00,  1323.90, -1804.20,   110.90},
{ "Cranberry Station",           -2007.80,    56.30,     0.00, -1922.00,   224.70,   100.00},
{ "Creek",                        2749.90,  1937.20,   -89.00,  2921.60,  2669.70,   110.90},
{ "Dillimore",                     580.70,  -674.80,    -9.50,   861.00,  -404.70,   200.00},
{ "Doherty",                     -2270.00,  -324.10,    -0.00, -1794.90,  -222.50,   200.00},
{ "Doherty",                     -2173.00,  -222.50,    -0.00, -1794.90,   265.20,   200.00},
{ "Downtown",                    -1982.30,   744.10,    -6.10, -1871.70,  1274.20,   200.00},
{ "Downtown",                    -1871.70,  1176.40,    -4.50, -1620.30,  1274.20,   200.00},
{ "Downtown",                    -1700.00,   744.20,    -6.10, -1580.00,  1176.50,   200.00},
{ "Downtown",                    -1580.00,   744.20,    -6.10, -1499.80,  1025.90,   200.00},
{ "Downtown",                    -2078.60,   578.30,    -7.60, -1499.80,   744.20,   200.00},
{ "Downtown",                    -1993.20,   265.20,    -9.10, -1794.90,   578.30,   200.00},
{ "Downtown Los Santos",          1463.90, -1430.80,   -89.00,  1724.70, -1290.80,   110.90},
{ "Downtown Los Santos",          1724.70, -1430.80,   -89.00,  1812.60, -1250.90,   110.90},
{ "Downtown Los Santos",          1463.90, -1290.80,   -89.00,  1724.70, -1150.80,   110.90},
{ "Downtown Los Santos",          1370.80, -1384.90,   -89.00,  1463.90, -1170.80,   110.90},
{ "Downtown Los Santos",          1724.70, -1250.90,   -89.00,  1812.60, -1150.80,   110.90},
{ "Downtown Los Santos",          1370.80, -1170.80,   -89.00,  1463.90, -1130.80,   110.90},
{ "Downtown Los Santos",          1378.30, -1130.80,   -89.00,  1463.90, -1026.30,   110.90},
{ "Downtown Los Santos",          1391.00, -1026.30,   -89.00,  1463.90,  -926.90,   110.90},
{ "Downtown Los Santos",          1507.50, -1385.20,   110.90,  1582.50, -1325.30,   335.90},
{ "East Beach",                   2632.80, -1852.80,   -89.00,  2959.30, -1668.10,   110.90},
{ "East Beach",                   2632.80, -1668.10,   -89.00,  2747.70, -1393.40,   110.90},
{ "East Beach",                   2747.70, -1668.10,   -89.00,  2959.30, -1498.60,   110.90},
{ "East Beach",                   2747.70, -1498.60,   -89.00,  2959.30, -1120.00,   110.90},
{ "East Los Santos",              2421.00, -1628.50,   -89.00,  2632.80, -1454.30,   110.90},
{ "East Los Santos",              2222.50, -1628.50,   -89.00,  2421.00, -1494.00,   110.90},
{ "East Los Santos",              2266.20, -1494.00,   -89.00,  2381.60, -1372.00,   110.90},
{ "East Los Santos",              2381.60, -1494.00,   -89.00,  2421.00, -1454.30,   110.90},
{ "East Los Santos",              2281.40, -1372.00,   -89.00,  2381.60, -1135.00,   110.90},
{ "East Los Santos",              2381.60, -1454.30,   -89.00,  2462.10, -1135.00,   110.90},
{ "East Los Santos",              2462.10, -1454.30,   -89.00,  2581.70, -1135.00,   110.90},
{ "Easter Basin",                -1794.90,   249.90,    -9.10, -1242.90,   578.30,   200.00},
{ "Easter Basin",                -1794.90,   -50.00,    -0.00, -1499.80,   249.90,   200.00},
{ "Easter Bay Airport",          -1499.80,   -50.00,    -0.00, -1242.90,   249.90,   200.00},
{ "Easter Bay Airport",          -1794.90,  -730.10,    -3.00, -1213.90,   -50.00,   200.00},
{ "Easter Bay Airport",          -1213.90,  -730.10,     0.00, -1132.80,   -50.00,   200.00},
{ "Easter Bay Airport",          -1242.90,   -50.00,     0.00, -1213.90,   578.30,   200.00},
{ "Easter Bay Airport",          -1213.90,   -50.00,    -4.50,  -947.90,   578.30,   200.00},
{ "Easter Bay Airport",          -1315.40,  -405.30,    15.40, -1264.40,  -209.50,    25.40},
{ "Easter Bay Airport",          -1354.30,  -287.30,    15.40, -1315.40,  -209.50,    25.40},
{ "Easter Bay Airport",          -1490.30,  -209.50,    15.40, -1264.40,  -148.30,    25.40},
{ "Easter Bay Chemicals",        -1132.80,  -768.00,     0.00,  -956.40,  -578.10,   200.00},
{ "Easter Bay Chemicals",        -1132.80,  -787.30,     0.00,  -956.40,  -768.00,   200.00},
{ "El Castillo del Diablo",       -464.50,  2217.60,     0.00,  -208.50,  2580.30,   200.00},
{ "El Castillo del Diablo",       -208.50,  2123.00,    -7.60,   114.00,  2337.10,   200.00},
{ "El Castillo del Diablo",       -208.50,  2337.10,     0.00,     8.40,  2487.10,   200.00},
{ "El Corona",                    1812.60, -2179.20,   -89.00,  1970.60, -1852.80,   110.90},
{ "El Corona",                    1692.60, -2179.20,   -89.00,  1812.60, -1842.20,   110.90},
{ "El Quebrados",                -1645.20,  2498.50,     0.00, -1372.10,  2777.80,   200.00},
{ "Esplanade East",              -1620.30,  1176.50,    -4.50, -1580.00,  1274.20,   200.00},
{ "Esplanade East",              -1580.00,  1025.90,    -6.10, -1499.80,  1274.20,   200.00},
{ "Esplanade East",              -1499.80,   578.30,   -79.60, -1339.80,  1274.20,    20.30},
{ "Esplanade North",             -2533.00,  1358.90,    -4.50, -1996.60,  1501.20,   200.00},
{ "Esplanade North",             -1996.60,  1358.90,    -4.50, -1524.20,  1592.50,   200.00},
{ "Esplanade North",             -1982.30,  1274.20,    -4.50, -1524.20,  1358.90,   200.00},
{ "Fallen Tree",                  -792.20,  -698.50,    -5.30,  -452.40,  -380.00,   200.00},
{ "Fallow Bridge",                 434.30,   366.50,     0.00,   603.00,   555.60,   200.00},
{ "Fern Ridge",                    508.10,  -139.20,     0.00,  1306.60,   119.50,   200.00},
{ "Financial",                   -1871.70,   744.10,    -6.10, -1701.30,  1176.40,   300.00},
{ "Fisher's Lagoon",              1916.90,  -233.30,  -100.00,  2131.70,    13.80,   200.00},
{ "Flint Intersection",           -187.70, -1596.70,   -89.00,    17.00, -1276.60,   110.90},
{ "Flint Range",                  -594.10, -1648.50,     0.00,  -187.70, -1276.60,   200.00},
{ "Fort Carson",                  -376.20,   826.30,    -3.00,   123.70,  1220.40,   200.00},
{ "Foster Valley",               -2270.00,  -430.20,    -0.00, -2178.60,  -324.10,   200.00},
{ "Foster Valley",               -2178.60,  -599.80,    -0.00, -1794.90,  -324.10,   200.00},
{ "Foster Valley",               -2178.60, -1115.50,     0.00, -1794.90,  -599.80,   200.00},
{ "Foster Valley",               -2178.60, -1250.90,     0.00, -1794.90, -1115.50,   200.00},
{ "Frederick Bridge",             2759.20,   296.50,     0.00,  2774.20,   594.70,   200.00},
{ "Gant Bridge",                 -2741.40,  1659.60,    -6.10, -2616.40,  2175.10,   200.00},
{ "Gant Bridge",                 -2741.00,  1490.40,    -6.10, -2616.40,  1659.60,   200.00},
{ "Ganton",                       2222.50, -1852.80,   -89.00,  2632.80, -1722.30,   110.90},
{ "Ganton",                       2222.50, -1722.30,   -89.00,  2632.80, -1628.50,   110.90},
{ "Garcia",                      -2411.20,  -222.50,    -0.00, -2173.00,   265.20,   200.00},
{ "Garcia",                      -2395.10,  -222.50,    -5.30, -2354.00,  -204.70,   200.00},
{ "Garver Bridge",               -1339.80,   828.10,   -89.00, -1213.90,  1057.00,   110.90},
{ "Garver Bridge",               -1213.90,   950.00,   -89.00, -1087.90,  1178.90,   110.90},
{ "Garver Bridge",               -1499.80,   696.40,  -179.60, -1339.80,   925.30,    20.30},
{ "Glen Park",                    1812.60, -1449.60,   -89.00,  1996.90, -1350.70,   110.90},
{ "Glen Park",                    1812.60, -1100.80,   -89.00,  1994.30,  -973.30,   110.90},
{ "Glen Park",                    1812.60, -1350.70,   -89.00,  2056.80, -1100.80,   110.90},
{ "Green Palms",                   176.50,  1305.40,    -3.00,   338.60,  1520.70,   200.00},
{ "Greenglass College",            964.30,  1044.60,   -89.00,  1197.30,  1203.20,   110.90},
{ "Greenglass College",            964.30,   930.80,   -89.00,  1166.50,  1044.60,   110.90},
{ "Hampton Barns",                 603.00,   264.30,     0.00,   761.90,   366.50,   200.00},
{ "Hankypanky Point",             2576.90,    62.10,     0.00,  2759.20,   385.50,   200.00},
{ "Harry Gold Parkway",           1777.30,   863.20,   -89.00,  1817.30,  2342.80,   110.90},
{ "Hashbury",                    -2593.40,  -222.50,    -0.00, -2411.20,    54.70,   200.00},
{ "Hilltop Farm",                  967.30,  -450.30,    -3.00,  1176.70,  -217.90,   200.00},
{ "Hunter Quarry",                 337.20,   710.80,  -115.20,   860.50,  1031.70,   203.70},
{ "Idlewood",                     1812.60, -1852.80,   -89.00,  1971.60, -1742.30,   110.90},
{ "Idlewood",                     1812.60, -1742.30,   -89.00,  1951.60, -1602.30,   110.90},
{ "Idlewood",                     1951.60, -1742.30,   -89.00,  2124.60, -1602.30,   110.90},
{ "Idlewood",                     1812.60, -1602.30,   -89.00,  2124.60, -1449.60,   110.90},
{ "Idlewood",                     2124.60, -1742.30,   -89.00,  2222.50, -1494.00,   110.90},
{ "Idlewood",                     1971.60, -1852.80,   -89.00,  2222.50, -1742.30,   110.90},
{ "Jefferson",                    1996.90, -1449.60,   -89.00,  2056.80, -1350.70,   110.90},
{ "Jefferson",                    2124.60, -1494.00,   -89.00,  2266.20, -1449.60,   110.90},
{ "Jefferson",                    2056.80, -1372.00,   -89.00,  2281.40, -1210.70,   110.90},
{ "Jefferson",                    2056.80, -1210.70,   -89.00,  2185.30, -1126.30,   110.90},
{ "Jefferson",                    2185.30, -1210.70,   -89.00,  2281.40, -1154.50,   110.90},
{ "Jefferson",                    2056.80, -1449.60,   -89.00,  2266.20, -1372.00,   110.90},
{ "Julius Thruway East",          2623.10,   943.20,   -89.00,  2749.90,  1055.90,   110.90},
{ "Julius Thruway East",          2685.10,  1055.90,   -89.00,  2749.90,  2626.50,   110.90},
{ "Julius Thruway East",          2536.40,  2442.50,   -89.00,  2685.10,  2542.50,   110.90},
{ "Julius Thruway East",          2625.10,  2202.70,   -89.00,  2685.10,  2442.50,   110.90},
{ "Julius Thruway North",         2498.20,  2542.50,   -89.00,  2685.10,  2626.50,   110.90},
{ "Julius Thruway North",         2237.40,  2542.50,   -89.00,  2498.20,  2663.10,   110.90},
{ "Julius Thruway North",         2121.40,  2508.20,   -89.00,  2237.40,  2663.10,   110.90},
{ "Julius Thruway North",         1938.80,  2508.20,   -89.00,  2121.40,  2624.20,   110.90},
{ "Julius Thruway North",         1534.50,  2433.20,   -89.00,  1848.40,  2583.20,   110.90},
{ "Julius Thruway North",         1848.40,  2478.40,   -89.00,  1938.80,  2553.40,   110.90},
{ "Julius Thruway North",         1704.50,  2342.80,   -89.00,  1848.40,  2433.20,   110.90},
{ "Julius Thruway North",         1377.30,  2433.20,   -89.00,  1534.50,  2507.20,   110.90},
{ "Julius Thruway South",         1457.30,   823.20,   -89.00,  2377.30,   863.20,   110.90},
{ "Julius Thruway South",         2377.30,   788.80,   -89.00,  2537.30,   897.90,   110.90},
{ "Julius Thruway West",          1197.30,  1163.30,   -89.00,  1236.60,  2243.20,   110.90},
{ "Julius Thruway West",          1236.60,  2142.80,   -89.00,  1297.40,  2243.20,   110.90},
{ "Juniper Hill",                -2533.00,   578.30,    -7.60, -2274.10,   968.30,   200.00},
{ "Juniper Hollow",              -2533.00,   968.30,    -6.10, -2274.10,  1358.90,   200.00},
{ "K.A.C.C. Military Fuels",      2498.20,  2626.50,   -89.00,  2749.90,  2861.50,   110.90},
{ "Kincaid Bridge",              -1339.80,   599.20,   -89.00, -1213.90,   828.10,   110.90},
{ "Kincaid Bridge",              -1213.90,   721.10,   -89.00, -1087.90,   950.00,   110.90},
{ "Kincaid Bridge",              -1087.90,   855.30,   -89.00,  -961.90,   986.20,   110.90},
{ "King's",                      -2329.30,   458.40,    -7.60, -1993.20,   578.30,   200.00},
{ "King's",                      -2411.20,   265.20,    -9.10, -1993.20,   373.50,   200.00},
{ "King's",                      -2253.50,   373.50,    -9.10, -1993.20,   458.40,   200.00},
{ "LVA Freight Depot",            1457.30,   863.20,   -89.00,  1777.40,  1143.20,   110.90},
{ "LVA Freight Depot",            1375.60,   919.40,   -89.00,  1457.30,  1203.20,   110.90},
{ "LVA Freight Depot",            1277.00,  1087.60,   -89.00,  1375.60,  1203.20,   110.90},
{ "LVA Freight Depot",            1315.30,  1044.60,   -89.00,  1375.60,  1087.60,   110.90},
{ "LVA Freight Depot",            1236.60,  1163.40,   -89.00,  1277.00,  1203.20,   110.90},
{ "Las Barrancas",                -926.10,  1398.70,    -3.00,  -719.20,  1634.60,   200.00},
{ "Las Brujas",                   -365.10,  2123.00,    -3.00,  -208.50,  2217.60,   200.00},
{ "Las Colinas",                  1994.30, -1100.80,   -89.00,  2056.80,  -920.80,   110.90},
{ "Las Colinas",                  2056.80, -1126.30,   -89.00,  2126.80,  -920.80,   110.90},
{ "Las Colinas",                  2185.30, -1154.50,   -89.00,  2281.40,  -934.40,   110.90},
{ "Las Colinas",                  2126.80, -1126.30,   -89.00,  2185.30,  -934.40,   110.90},
{ "Las Colinas",                  2747.70, -1120.00,   -89.00,  2959.30,  -945.00,   110.90},
{ "Las Colinas",                  2632.70, -1135.00,   -89.00,  2747.70,  -945.00,   110.90},
{ "Las Colinas",                  2281.40, -1135.00,   -89.00,  2632.70,  -945.00,   110.90},
{ "Las Payasadas",                -354.30,  2580.30,     2.00,  -133.60,  2816.80,   200.00},
{ "Las Venturas Airport",         1236.60,  1203.20,   -89.00,  1457.30,  1883.10,   110.90},
{ "Las Venturas Airport",         1457.30,  1203.20,   -89.00,  1777.30,  1883.10,   110.90},
{ "Las Venturas Airport",         1457.30,  1143.20,   -89.00,  1777.40,  1203.20,   110.90},
{ "Las Venturas Airport",         1515.80,  1586.40,   -12.50,  1729.90,  1714.50,    87.50},
{ "Last Dime Motel",              1823.00,   596.30,   -89.00,  1997.20,   823.20,   110.90},
{ "Leafy Hollow",                -1166.90, -1856.00,     0.00,  -815.60, -1602.00,   200.00},
{ "Lil' Probe Inn",                -90.20,  1286.80,    -3.00,   153.80,  1554.10,   200.00},
{ "Linden Side",                  2749.90,   943.20,   -89.00,  2923.30,  1198.90,   110.90},
{ "Linden Station",               2749.90,  1198.90,   -89.00,  2923.30,  1548.90,   110.90},
{ "Linden Station",               2811.20,  1229.50,   -39.50,  2861.20,  1407.50,    60.40},
{ "Little Mexico",                1701.90, -1842.20,   -89.00,  1812.60, -1722.20,   110.90},
{ "Little Mexico",                1758.90, -1722.20,   -89.00,  1812.60, -1577.50,   110.90},
{ "Los Flores",                   2581.70, -1454.30,   -89.00,  2632.80, -1393.40,   110.90},
{ "Los Flores",                   2581.70, -1393.40,   -89.00,  2747.70, -1135.00,   110.90},
{ "Los Santos International",     1249.60, -2394.30,   -89.00,  1852.00, -2179.20,   110.90},
{ "Los Santos International",     1852.00, -2394.30,   -89.00,  2089.00, -2179.20,   110.90},
{ "Los Santos International",     1382.70, -2730.80,   -89.00,  2201.80, -2394.30,   110.90},
{ "Los Santos International",     1974.60, -2394.30,   -39.00,  2089.00, -2256.50,    60.90},
{ "Los Santos International",     1400.90, -2669.20,   -39.00,  2189.80, -2597.20,    60.90},
{ "Los Santos International",     2051.60, -2597.20,   -39.00,  2152.40, -2394.30,    60.90},
{ "Marina",                        647.70, -1804.20,   -89.00,   851.40, -1577.50,   110.90},
{ "Marina",                        647.70, -1577.50,   -89.00,   807.90, -1416.20,   110.90},
{ "Marina",                        807.90, -1577.50,   -89.00,   926.90, -1416.20,   110.90},
{ "Market",                        787.40, -1416.20,   -89.00,  1072.60, -1310.20,   110.90},
{ "Market",                        952.60, -1310.20,   -89.00,  1072.60, -1130.80,   110.90},
{ "Market",                       1072.60, -1416.20,   -89.00,  1370.80, -1130.80,   110.90},
{ "Market",                        926.90, -1577.50,   -89.00,  1370.80, -1416.20,   110.90},
{ "Market Station",                787.40, -1410.90,   -34.10,   866.00, -1310.20,    65.80},
{ "Martin Bridge",                -222.10,   293.30,     0.00,  -122.10,   476.40,   200.00},
{ "Missionary Hill",             -2994.40,  -811.20,     0.00, -2178.60,  -430.20,   200.00},
{ "Montgomery",                   1119.50,   119.50,    -3.00,  1451.40,   493.30,   200.00},
{ "Montgomery",                   1451.40,   347.40,    -6.10,  1582.40,   420.80,   200.00},
{ "Montgomery Intersection",      1546.60,   208.10,     0.00,  1745.80,   347.40,   200.00},
{ "Montgomery Intersection",      1582.40,   347.40,     0.00,  1664.60,   401.70,   200.00},
{ "Mulholland",                   1414.00,  -768.00,   -89.00,  1667.60,  -452.40,   110.90},
{ "Mulholland",                   1281.10,  -452.40,   -89.00,  1641.10,  -290.90,   110.90},
{ "Mulholland",                   1269.10,  -768.00,   -89.00,  1414.00,  -452.40,   110.90},
{ "Mulholland",                   1357.00,  -926.90,   -89.00,  1463.90,  -768.00,   110.90},
{ "Mulholland",                   1318.10,  -910.10,   -89.00,  1357.00,  -768.00,   110.90},
{ "Mulholland",                   1169.10,  -910.10,   -89.00,  1318.10,  -768.00,   110.90},
{ "Mulholland",                    768.60,  -954.60,   -89.00,   952.60,  -860.60,   110.90},
{ "Mulholland",                    687.80,  -860.60,   -89.00,   911.80,  -768.00,   110.90},
{ "Mulholland",                    737.50,  -768.00,   -89.00,  1142.20,  -674.80,   110.90},
{ "Mulholland",                   1096.40,  -910.10,   -89.00,  1169.10,  -768.00,   110.90},
{ "Mulholland",                    952.60,  -937.10,   -89.00,  1096.40,  -860.60,   110.90},
{ "Mulholland",                    911.80,  -860.60,   -89.00,  1096.40,  -768.00,   110.90},
{ "Mulholland",                    861.00,  -674.80,   -89.00,  1156.50,  -600.80,   110.90},
{ "Mulholland Intersection",      1463.90, -1150.80,   -89.00,  1812.60,  -768.00,   110.90},
{ "North Rock",                   2285.30,  -768.00,     0.00,  2770.50,  -269.70,   200.00},
{ "Ocean Docks",                  2373.70, -2697.00,   -89.00,  2809.20, -2330.40,   110.90},
{ "Ocean Docks",                  2201.80, -2418.30,   -89.00,  2324.00, -2095.00,   110.90},
{ "Ocean Docks",                  2324.00, -2302.30,   -89.00,  2703.50, -2145.10,   110.90},
{ "Ocean Docks",                  2089.00, -2394.30,   -89.00,  2201.80, -2235.80,   110.90},
{ "Ocean Docks",                  2201.80, -2730.80,   -89.00,  2324.00, -2418.30,   110.90},
{ "Ocean Docks",                  2703.50, -2302.30,   -89.00,  2959.30, -2126.90,   110.90},
{ "Ocean Docks",                  2324.00, -2145.10,   -89.00,  2703.50, -2059.20,   110.90},
{ "Ocean Flats",                 -2994.40,   277.40,    -9.10, -2867.80,   458.40,   200.00},
{ "Ocean Flats",                 -2994.40,  -222.50,    -0.00, -2593.40,   277.40,   200.00},
{ "Ocean Flats",                 -2994.40,  -430.20,    -0.00, -2831.80,  -222.50,   200.00},
{ "Octane Springs",                338.60,  1228.50,     0.00,   664.30,  1655.00,   200.00},
{ "Old Venturas Strip",           2162.30,  2012.10,   -89.00,  2685.10,  2202.70,   110.90},
{ "Palisades",                   -2994.40,   458.40,    -6.10, -2741.00,  1339.60,   200.00},
{ "Palomino Creek",               2160.20,  -149.00,     0.00,  2576.90,   228.30,   200.00},
{ "Paradiso",                    -2741.00,   793.40,    -6.10, -2533.00,  1268.40,   200.00},
{ "Pershing Square",              1440.90, -1722.20,   -89.00,  1583.50, -1577.50,   110.90},
{ "Pilgrim",                      2437.30,  1383.20,   -89.00,  2624.40,  1783.20,   110.90},
{ "Pilgrim",                      2624.40,  1383.20,   -89.00,  2685.10,  1783.20,   110.90},
{ "Pilson Intersection",          1098.30,  2243.20,   -89.00,  1377.30,  2507.20,   110.90},
{ "Pirates in Men's Pants",       1817.30,  1469.20,   -89.00,  2027.40,  1703.20,   110.90},
{ "Playa del Seville",            2703.50, -2126.90,   -89.00,  2959.30, -1852.80,   110.90},
{ "Prickle Pine",                 1534.50,  2583.20,   -89.00,  1848.40,  2863.20,   110.90},
{ "Prickle Pine",                 1117.40,  2507.20,   -89.00,  1534.50,  2723.20,   110.90},
{ "Prickle Pine",                 1848.40,  2553.40,   -89.00,  1938.80,  2863.20,   110.90},
{ "Prickle Pine",                 1938.80,  2624.20,   -89.00,  2121.40,  2861.50,   110.90},
{ "Queens",                      -2533.00,   458.40,     0.00, -2329.30,   578.30,   200.00},
{ "Queens",                      -2593.40,    54.70,     0.00, -2411.20,   458.40,   200.00},
{ "Queens",                      -2411.20,   373.50,     0.00, -2253.50,   458.40,   200.00},
{ "Randolph Industrial Estate",   1558.00,   596.30,   -89.00,  1823.00,   823.20,   110.90},
{ "Redsands East",                1817.30,  2011.80,   -89.00,  2106.70,  2202.70,   110.90},
{ "Redsands East",                1817.30,  2202.70,   -89.00,  2011.90,  2342.80,   110.90},
{ "Redsands East",                1848.40,  2342.80,   -89.00,  2011.90,  2478.40,   110.90},
{ "Redsands West",                1236.60,  1883.10,   -89.00,  1777.30,  2142.80,   110.90},
{ "Redsands West",                1297.40,  2142.80,   -89.00,  1777.30,  2243.20,   110.90},
{ "Redsands West",                1377.30,  2243.20,   -89.00,  1704.50,  2433.20,   110.90},
{ "Redsands West",                1704.50,  2243.20,   -89.00,  1777.30,  2342.80,   110.90},
{ "Regular Tom",                  -405.70,  1712.80,    -3.00,  -276.70,  1892.70,   200.00},
{ "Richman",                       647.50, -1118.20,   -89.00,   787.40,  -954.60,   110.90},
{ "Richman",                       647.50,  -954.60,   -89.00,   768.60,  -860.60,   110.90},
{ "Richman",                       225.10, -1369.60,   -89.00,   334.50, -1292.00,   110.90},
{ "Richman",                       225.10, -1292.00,   -89.00,   466.20, -1235.00,   110.90},
{ "Richman",                        72.60, -1404.90,   -89.00,   225.10, -1235.00,   110.90},
{ "Richman",                        72.60, -1235.00,   -89.00,   321.30, -1008.10,   110.90},
{ "Richman",                       321.30, -1235.00,   -89.00,   647.50, -1044.00,   110.90},
{ "Richman",                       321.30, -1044.00,   -89.00,   647.50,  -860.60,   110.90},
{ "Richman",                       321.30,  -860.60,   -89.00,   687.80,  -768.00,   110.90},
{ "Richman",                       321.30,  -768.00,   -89.00,   700.70,  -674.80,   110.90},
{ "Robada Intersection",         -1119.00,  1178.90,   -89.00,  -862.00,  1351.40,   110.90},
{ "Roca Escalante",               2237.40,  2202.70,   -89.00,  2536.40,  2542.50,   110.90},
{ "Roca Escalante",               2536.40,  2202.70,   -89.00,  2625.10,  2442.50,   110.90},
{ "Rockshore East",               2537.30,   676.50,   -89.00,  2902.30,   943.20,   110.90},
{ "Rockshore West",               1997.20,   596.30,   -89.00,  2377.30,   823.20,   110.90},
{ "Rockshore West",               2377.30,   596.30,   -89.00,  2537.30,   788.80,   110.90},
{ "Rodeo",                          72.60, -1684.60,   -89.00,   225.10, -1544.10,   110.90},
{ "Rodeo",                          72.60, -1544.10,   -89.00,   225.10, -1404.90,   110.90},
{ "Rodeo",                         225.10, -1684.60,   -89.00,   312.80, -1501.90,   110.90},
{ "Rodeo",                         225.10, -1501.90,   -89.00,   334.50, -1369.60,   110.90},
{ "Rodeo",                         334.50, -1501.90,   -89.00,   422.60, -1406.00,   110.90},
{ "Rodeo",                         312.80, -1684.60,   -89.00,   422.60, -1501.90,   110.90},
{ "Rodeo",                         422.60, -1684.60,   -89.00,   558.00, -1570.20,   110.90},
{ "Rodeo",                         558.00, -1684.60,   -89.00,   647.50, -1384.90,   110.90},
{ "Rodeo",                         466.20, -1570.20,   -89.00,   558.00, -1385.00,   110.90},
{ "Rodeo",                         422.60, -1570.20,   -89.00,   466.20, -1406.00,   110.90},
{ "Rodeo",                         466.20, -1385.00,   -89.00,   647.50, -1235.00,   110.90},
{ "Rodeo",                         334.50, -1406.00,   -89.00,   466.20, -1292.00,   110.90},
{ "Royal Casino",                 2087.30,  1383.20,   -89.00,  2437.30,  1543.20,   110.90},
{ "San Andreas Sound",            2450.30,   385.50,  -100.00,  2759.20,   562.30,   200.00},
{ "Santa Flora",                 -2741.00,   458.40,    -7.60, -2533.00,   793.40,   200.00},
{ "Santa Maria Beach",             342.60, -2173.20,   -89.00,   647.70, -1684.60,   110.90},
{ "Santa Maria Beach",              72.60, -2173.20,   -89.00,   342.60, -1684.60,   110.90},
{ "Shady Cabin",                 -1632.80, -2263.40,    -3.00, -1601.30, -2231.70,   200.00},
{ "Shady Creeks",                -1820.60, -2643.60,    -8.00, -1226.70, -1771.60,   200.00},
{ "Shady Creeks",                -2030.10, -2174.80,    -6.10, -1820.60, -1771.60,   200.00},
{ "Sobell Rail Yards",            2749.90,  1548.90,   -89.00,  2923.30,  1937.20,   110.90},
{ "Spinybed",                     2121.40,  2663.10,   -89.00,  2498.20,  2861.50,   110.90},
{ "Starfish Casino",              2437.30,  1783.20,   -89.00,  2685.10,  2012.10,   110.90},
{ "Starfish Casino",              2437.30,  1858.10,   -39.00,  2495.00,  1970.80,    60.90},
{ "Starfish Casino",              2162.30,  1883.20,   -89.00,  2437.30,  2012.10,   110.90},
{ "Temple",                       1252.30, -1130.80,   -89.00,  1378.30, -1026.30,   110.90},
{ "Temple",                       1252.30, -1026.30,   -89.00,  1391.00,  -926.90,   110.90},
{ "Temple",                       1252.30,  -926.90,   -89.00,  1357.00,  -910.10,   110.90},
{ "Temple",                        952.60, -1130.80,   -89.00,  1096.40,  -937.10,   110.90},
{ "Temple",                       1096.40, -1130.80,   -89.00,  1252.30, -1026.30,   110.90},
{ "Temple",                       1096.40, -1026.30,   -89.00,  1252.30,  -910.10,   110.90},
{ "The Camel's Toe",              2087.30,  1203.20,   -89.00,  2640.40,  1383.20,   110.90},
{ "The Clown's Pocket",           2162.30,  1783.20,   -89.00,  2437.30,  1883.20,   110.90},
{ "The Emerald Isle",             2011.90,  2202.70,   -89.00,  2237.40,  2508.20,   110.90},
{ "The Farm",                    -1209.60, -1317.10,   114.90,  -908.10,  -787.30,   251.90},
{ "The Four Dragons Casino",      1817.30,   863.20,   -89.00,  2027.30,  1083.20,   110.90},
{ "The High Roller",              1817.30,  1283.20,   -89.00,  2027.30,  1469.20,   110.90},
{ "The Mako Span",                1664.60,   401.70,     0.00,  1785.10,   567.20,   200.00},
{ "The Panopticon",               -947.90,  -304.30,    -1.10,  -319.60,   327.00,   200.00},
{ "The Pink Swan",                1817.30,  1083.20,   -89.00,  2027.30,  1283.20,   110.90},
{ "The Sherman Dam",              -968.70,  1929.40,    -3.00,  -481.10,  2155.20,   200.00},
{ "The Strip",                    2027.40,   863.20,   -89.00,  2087.30,  1703.20,   110.90},
{ "The Strip",                    2106.70,  1863.20,   -89.00,  2162.30,  2202.70,   110.90},
{ "The Strip",                    2027.40,  1783.20,   -89.00,  2162.30,  1863.20,   110.90},
{ "The Strip",                    2027.40,  1703.20,   -89.00,  2137.40,  1783.20,   110.90},
{ "The Visage",                   1817.30,  1863.20,   -89.00,  2106.70,  2011.80,   110.90},
{ "The Visage",                   1817.30,  1703.20,   -89.00,  2027.40,  1863.20,   110.90},
{ "Unity Station",                1692.60, -1971.80,   -20.40,  1812.60, -1932.80,    79.50},
{ "Valle Ocultado",               -936.60,  2611.40,     2.00,  -715.90,  2847.90,   200.00},
{ "Verdant Bluffs",                930.20, -2488.40,   -89.00,  1249.60, -2006.70,   110.90},
{ "Verdant Bluffs",               1073.20, -2006.70,   -89.00,  1249.60, -1842.20,   110.90},
{ "Verdant Bluffs",               1249.60, -2179.20,   -89.00,  1692.60, -1842.20,   110.90},
{ "Verdant Meadows",                37.00,  2337.10,    -3.00,   435.90,  2677.90,   200.00},
{ "Verona Beach",                  647.70, -2173.20,   -89.00,   930.20, -1804.20,   110.90},
{ "Verona Beach",                  930.20, -2006.70,   -89.00,  1073.20, -1804.20,   110.90},
{ "Verona Beach",                  851.40, -1804.20,   -89.00,  1046.10, -1577.50,   110.90},
{ "Verona Beach",                 1161.50, -1722.20,   -89.00,  1323.90, -1577.50,   110.90},
{ "Verona Beach",                 1046.10, -1722.20,   -89.00,  1161.50, -1577.50,   110.90},
{ "Vinewood",                      787.40, -1310.20,   -89.00,   952.60, -1130.80,   110.90},
{ "Vinewood",                      787.40, -1130.80,   -89.00,   952.60,  -954.60,   110.90},
{ "Vinewood",                      647.50, -1227.20,   -89.00,   787.40, -1118.20,   110.90},
{ "Vinewood",                      647.70, -1416.20,   -89.00,   787.40, -1227.20,   110.90},
{ "Whitewood Estates",             883.30,  1726.20,   -89.00,  1098.30,  2507.20,   110.90},
{ "Whitewood Estates",            1098.30,  1726.20,   -89.00,  1197.30,  2243.20,   110.90},
{ "Willowfield",                  1970.60, -2179.20,   -89.00,  2089.00, -1852.80,   110.90},
{ "Willowfield",                  2089.00, -2235.80,   -89.00,  2201.80, -1989.90,   110.90},
{ "Willowfield",                  2089.00, -1989.90,   -89.00,  2324.00, -1852.80,   110.90},
{ "Willowfield",                  2201.80, -2095.00,   -89.00,  2324.00, -1989.90,   110.90},
{ "Willowfield",                  2541.70, -1941.40,   -89.00,  2703.50, -1852.80,   110.90},
{ "Willowfield",                  2324.00, -2059.20,   -89.00,  2541.70, -1852.80,   110.90},
{ "Willowfield",                  2541.70, -2059.20,   -89.00,  2703.50, -1941.40,   110.90},
{ "Yellow Bell Station",          1377.40,  2600.40,   -21.90,  1492.40,  2687.30,    78.00},
{ "Los Santos",                     44.60, -2892.90,  -242.90,  2997.00,  -768.00,   900.00},
{ "Las Venturas",                  869.40,   596.30,  -242.90,  2997.00,  2993.80,   900.00},
{ "Bone County",                  -480.50,   596.30,  -242.90,   869.40,  2993.80,   900.00},
{ "Tierra Robada",               -2997.40,  1659.60,  -242.90,  -480.50,  2993.80,   900.00},
{ "Tierra Robada",               -1213.90,   596.30,  -242.90,  -480.50,  1659.60,   900.00},
{ "San Fierro",                  -2997.40, -1115.50,  -242.90, -1213.90,  1659.60,   900.00},
{ "Red County",                  -1213.90,  -768.00,  -242.90,  2997.00,   596.30,   900.00},
{ "Flint County",                -1213.90, -2892.90,  -242.90,    44.60,  -768.00,   900.00},
{ "Whetstone",                   -2997.40, -2892.90,  -242.90, -1213.90, -1115.50,   900.00}};

//Arrays do sistema de Experience Level
new VeiculoConsertado[MAX_VEHICLES] = 0;
new VeiculoPintado[MAX_VEHICLES] = 0;
new CasaVendida[MAX_PLAYERS] = 0;
new CarroAbastecido[MAX_VEHICLES] = 0;
new JogadorMultado[MAX_PLAYERS] = 0;
forward ZerarVeiculoConsertado(vehicleid);
forward ZerarVeiculoPintado(vehicleid);
forward ZerarCarroAbastecido(vehicleid);
forward ZerarCasaVendida(playerid);
forward ZerarJogadorMultado(playerid);
public ZerarVeiculoConsertado(vehicleid) VeiculoConsertado[vehicleid]=0;
public ZerarVeiculoPintado(vehicleid) VeiculoPintado[vehicleid]=0;
public ZerarCasaVendida(playerid) CasaVendida[playerid]=0;
public ZerarCarroAbastecido(vehicleid) CarroAbastecido[vehicleid]=0;
public ZerarJogadorMultado(playerid) JogadorMultado[playerid]=0;

//[/Arrays necessárias]
new carrosalugar[] =
{
	560
};
//Desmanche
new Veiculoprocurado;
new Veiculosprocurados[MAX_DESMANCHEVEICULO] = {
	463,
	461,
	411,
	468,
	541,
	424,
	402,
	415,
	562,
	587,
	565,
	521,
	434,
	559,
 	400,
 	522,
 	535,
 	560,
 	451
};
new Veiculosprocuradosnome[MAX_DESMANCHEVEICULO][32] = {
	"Freeway",
	"PCJ-600",
	"Infernus",
	"Sanchez",
	"Bullet",
	"BjInject",
	"Buffalo",
	"Cheetah",
	"Elegy",
	"Euros",
	"Flash",
	"FCR-900",
	"HotKnife",
	"Jester",
	"Landstal",
	"Nrg-500",
	"Slamvam",
	"Sultan",
	"Turismo"
};


stock CriarPickups()
{
	AddStaticPickup(1210,1,-154.0990,1183.9434,19.7422);//maleta fort carson
    for(new i; i<NUM_BANCOS; i++) AddStaticPickup(1274,1,bancospos[i][0],bancospos[i][1],bancospos[i][2]);
    for(new h=1; h<4; h++) AddStaticPickup(1272,1,HotelPos[h][4], HotelPos[h][5], HotelPos[h][6]);
	AddStaticPickup(362,2,1420.2501,2881.3828,10.8203);//minigun
	AddStaticPickup(350,2,-1609.9634,674.0835,-5.2422); // shotgun
	AddStaticPickup(356,2,-1608.0623,674.1035,-5.2422); // m4
	AddStaticPickup(355,2,-1603.5215,674.7878,-5.2422); // ak47
	AddStaticPickup(348,2,-1609.7281,679.0164,-5.2422); // desert eagle
    AddStaticPickup(357,2,-1608.2559,678.6394,-5.2422); //minigun
    AddStaticPickup(372,2,-1606.7788,678.6942,-5.2422); // tec-9
    AddStaticPickup(353,2,-1603.8494,678.8831,-5.2422); // mp5
    AddStaticPickup(343,2,-1605.1569,678.0090,-5.2422); // gas
    AddStaticPickup(1272,1,-1600.4955,863.6196,7.6875); //
    AddStaticPickup(1240,2,-2655.5859,637.5977,14.4531); //
    AddStaticPickup(1253,1,-318.5863,1535.5477,75.5625); //jornal
    AddStaticPickup(367,2,-312.4564,1515.9036,75.3594); //jornal
//	AddStaticPickup(1244,1,1389.0552,1768.4464,10.8203);//Aero-Gas
    //AddStaticPickup(1244,1,-1248.6545,-96.2660,14.1484);//Aero-Gas
    //AddStaticPickup(1244,1,1422.8640,-2432.5745,13.0956);//Aero-Gas
    Pickup_EntradaPol = CreatePickup(seta,2,-1605.7075,710.2816,13.8672);
    Pickup_SaidaPol = CreatePickup(seta,2,245.9235,108.6110,1003.2188);
    Pickup_Entrada247 = CreatePickup(seta,2,-2443.4539,755.4039,35.1719);
    Pickup_Saida247 = CreatePickup(seta,2,5.8416,-30.5887,1003.5494);
    Pickup_EntradaCPD = CreatePickup(seta,2,-2057.6982,456.1456,35.1719);
    Pickup_SaidaCPD = CreatePickup(seta,2,389.7861,171.6789,1008.3828);
}

public writelog(log[])
{
	new dia,mes,ano;
	getdate(ano,mes,dia);
	new tmp[256],ny[256];
	format(ny,256,"%d",ano);
	strdel(ny,0,2);
	format(tmp,256,"logs/log-%s-%s-%s.txt",AddZeros(dia),AddZeros(mes),ny);
	if(!fexist(tmp))
	    dini_Create(tmp);
	else {
		new File:logstr;
		logstr = fopen(tmp, io_append);
		new newlog[256];
		format(newlog,256,"[%s] %s",GetFormattedTime(),log);
        fwrite(logstr, newlog);
        fwrite(logstr, "\r\n");
        fclose(logstr);
	}
}

stock AddPlayerHealth(playerid,Float:h)
{
	if(!IsPlayerConnected(playerid)) return 0;
	new Float:x;
	GetPlayerHealth(playerid,x);
	if(x+h < 100) SetPlayerHealth(playerid,x+h);
	if(x+h >= 100) SetPlayerHealth(playerid,100);
	return 0;
}

stock GetDistanceToCar(playerid,carid)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
	new Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	GetVehiclePos(carid,x2,y2,z2);
	tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
	return floatround(tmpdis);
}

stock GetDistanceBetweenPlayers(playerid,playerid2)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
	new Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	GetPlayerPos(playerid2,x2,y2,z2);
	tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
	return floatround(tmpdis);
}

stock GetPlayerDistanceToPointEx(playerid,Float:x2,Float:y2,Float:z2)
{
	new Float:x1,Float:y1,Float:z1;
	new Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
	return floatround(tmpdis);
}

stock GetDistanceToObject(playerid,objectid)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
	new Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	GetObjectPos(objectid,x2,y2,z2);
	tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
	return floatround(tmpdis);
}

stock GetFormattedTime(){
	new time[256];
	new Hora,Minuto,Segundo;
	gettime(Hora,Minuto,Segundo);
	Hora += FUSE; //descomente isso para ativar o fuso horario
	if(Hora < 0) Hora += 24;
    format(time,sizeof(time),"%s:%s:%s",AddZeros(Hora),AddZeros(Minuto),AddZeros(Segundo));
	return time;
}

stock AddZeros(num)
{
	new tmp[256];
	if(num < 10) format(tmp,256,"0%d",num);
	else format(tmp,256,"%d",num);
	return tmp;
}

stock IntToStr(i)
{
	new tmp[256];
	format(tmp,sizeof tmp,"%d",i);
	return tmp;
}

stock FloatToStr(Float:flt)
{
	new tmp[256];
	format(tmp,sizeof tmp,"%f",flt);
	return tmp;
}

stock PRIV_FWN(nick[])
{
	new tmp[256];
	format(tmp,sizeof tmp,"nickname = '%s'",nick);
	return tmp;
}

stock PRIV_FWI(carid)
{
	new tmp[256];
	format(tmp,sizeof tmp,"id = %d",carid);
	return tmp;
}

stock CriarMenus()
{
	Bombshop = CreateMenu("Loja de bombas",2,2,150,100,20);
	if(IsValidMenu(Bombshop)){
	    SetMenuColumnHeader(Bombshop,0,"Produto");
	    SetMenuColumnHeader(Bombshop,1,"Preœo");
		AddMenuItem(Bombshop,0,"Napalm");
		AddMenuItem(Bombshop,1,"$500");
		AddMenuItem(Bombshop,0,"Dinamite");
		AddMenuItem(Bombshop,1,"$450");
		AddMenuItem(Bombshop,0,"Sair");
	}
	//----
	Bombshopveh = CreateMenu("Loja de bombas",2,2,150,100,20);
	if(IsValidMenu(Bombshopveh)){
	    SetMenuColumnHeader(Bombshop,0,"Produto");
	    SetMenuColumnHeader(Bombshop,1,"Preœo");
		AddMenuItem(Bombshopveh,0,"Instalar bomba");
		AddMenuItem(Bombshopveh,1,"$500");
		AddMenuItem(Bombshopveh,0,"Napalm");
		AddMenuItem(Bombshopveh,1,"$500");
		AddMenuItem(Bombshopveh,0,"Dinamite");
		AddMenuItem(Bombshopveh,1,"$450");
		AddMenuItem(Bombshopveh,0,"Sair");
	}

	CPD_First = CreateMenu("Profissšo",2,2,150,100,20);
	if(IsValidMenu(CPD_First)){
	    SetMenuColumnHeader(CPD_First,0,"Nome");
	    SetMenuColumnHeader(CPD_First,1,"Sal˜rio");
	    AddMenuItem(CPD_First,0,"Desempregado");
		AddMenuItem(CPD_First,1,"$350");
		AddMenuItem(CPD_First,0,"Barman");
		AddMenuItem(CPD_First,1,"$800");
		AddMenuItem(CPD_First,0,"Entregador de Pizza");
		AddMenuItem(CPD_First,1,"$1400");
		AddMenuItem(CPD_First,0,"Mototaxista");
		AddMenuItem(CPD_First,1,"$1400");
		AddMenuItem(CPD_First,0,"Taxista");
		AddMenuItem(CPD_First,1,"$1400");
		AddMenuItem(CPD_First,0,"Assassino");
		AddMenuItem(CPD_First,1,"$400");
		AddMenuItem(CPD_First,0,"Caœador");
		AddMenuItem(CPD_First,1,"$2000");
		AddMenuItem(CPD_First,0,"Pescador");
		AddMenuItem(CPD_First,1,"$1400");
	}
	CPD_Second = CreateMenu("Profissšo",2,2,150,100,20);
	if(IsValidMenu(CPD_Second)){
		SetMenuColumnHeader(CPD_Second,0,"Nome");
	    SetMenuColumnHeader(CPD_Second,1,"Sal˜rio");
	    AddMenuItem(CPD_Second,0,"Taxi Ažreo");
	    AddMenuItem(CPD_Second,1,"$1500");
	    AddMenuItem(CPD_Second,0,"Seguranœa");
	    AddMenuItem(CPD_Second,1,"$1000");
	    AddMenuItem(CPD_Second,0,"Motorista de §nibus");
	    AddMenuItem(CPD_Second,1,"$2000");
	    AddMenuItem(CPD_Second,0,"Pedreira");
	    AddMenuItem(CPD_Second,1,"$1500");
	    AddMenuItem(CPD_Second,0,"Motorista");
	    AddMenuItem(CPD_Second,1,"$2000");
		AddMenuItem(CPD_Second,0,"Jornalista");
	    AddMenuItem(CPD_Second,1,"$1500");
	    AddMenuItem(CPD_Second,0,"Caminhoneiro");
	    AddMenuItem(CPD_Second,1,"$1500");
	    AddMenuItem(CPD_Second,0,"Assaltante");
	    AddMenuItem(CPD_Second,1,"$600");
	    AddMenuItem(CPD_Second,0,"Frentista");
	    AddMenuItem(CPD_Second,1,"$1200");
	    AddMenuItem(CPD_Second,0,"Paramždico");
	    AddMenuItem(CPD_Second,1,"$1000");
	    AddMenuItem(CPD_Second,0,"Transporte de Valores");
	    AddMenuItem(CPD_Second,1,"$1200");
	    AddMenuItem(CPD_Second,0,"Ladršao de Carros");
  	    AddMenuItem(CPD_Second,1,"$1000");
	}
	CPD_Third = CreateMenu("Profissšo",2,2,150,100,20);
	if(IsValidMenu(CPD_Third)){
		SetMenuColumnHeader(CPD_Third,0,"Nome");
	    SetMenuColumnHeader(CPD_Third,1,"Sal˜rio");
	    AddMenuItem(CPD_Third,0,"Prostituta");
	    AddMenuItem(CPD_Third,1,"$800");
	    AddMenuItem(CPD_Third,0,"Agricultor");
	    AddMenuItem(CPD_Third,1,"$1200");
	    AddMenuItem(CPD_Third,0,"Traficante");
	    AddMenuItem(CPD_Third,1,"$1000");
	    AddMenuItem(CPD_Third,0,"Vendedor de Armas");
	    AddMenuItem(CPD_Third,1,"$1400");
	    AddMenuItem(CPD_Third,0,"Receita Federal");
	    AddMenuItem(CPD_Third,1,"$2000");
	    AddMenuItem(CPD_Third,0,"Contrabandista");
	    AddMenuItem(CPD_Third,1,"$800");
	    AddMenuItem(CPD_Third,0,"Locador de Carros");
	    AddMenuItem(CPD_Third,1,"$1000");
	    AddMenuItem(CPD_Third,0,"Mecanico");
	    AddMenuItem(CPD_Third,1,"$1000");
	}
	CPD_Fourth = CreateMenu("Profissšo",2,2,150,100,20);
	if(IsValidMenu(CPD_Fourth)){
		SetMenuColumnHeader(CPD_Fourth,0,"Nome");
	    SetMenuColumnHeader(CPD_Fourth,1,"Sal˜rio");
	    AddMenuItem(CPD_Fourth,0,"Cop Florestal");
	    AddMenuItem(CPD_Fourth,1,"$2000");
	    AddMenuItem(CPD_Fourth,0,"Instrutor de Carros");
	    AddMenuItem(CPD_Fourth,1,"$850");
	    AddMenuItem(CPD_Fourth,0,"Cop Militar");
	    AddMenuItem(CPD_Fourth,1,"$1200");
	    AddMenuItem(CPD_Fourth,0,"Cop Rodoviario");
	    AddMenuItem(CPD_Fourth,1,"$1400");
	    AddMenuItem(CPD_Fourth,0,"Cop Narcoticos");
	    AddMenuItem(CPD_Fourth,1,"$1800");
	    AddMenuItem(CPD_Fourth,0,"Advogado");
	    AddMenuItem(CPD_Fourth,1,"$1000");
	}

	CPD_Fifth = CreateMenu("Profissšo",2,2,150,100,20);
	if(IsValidMenu(CPD_Fifth)){
		SetMenuColumnHeader(CPD_Fifth,0,"Nome");
	    SetMenuColumnHeader(CPD_Fifth,1,"Sal˜rio");
	    AddMenuItem(CPD_Fifth,0,"Cop Swat");
	    AddMenuItem(CPD_Fifth,1,"$2000");
	}

	CPD_Sixth = CreateMenu("Profissšo",2,2,150,100,20);
	if(IsValidMenu(CPD_Sixth)){
		SetMenuColumnHeader(CPD_Sixth,0,"Nome");
	    SetMenuColumnHeader(CPD_Sixth,1,"Sal˜rio");
	    AddMenuItem(CPD_Sixth,0,"Sheriff");
	    AddMenuItem(CPD_Sixth,1,"$4500");
	    AddMenuItem(CPD_Sixth,0,"Juiz");
	    AddMenuItem(CPD_Sixth,1,"$3000");
	}
}

stock AtivarTimers()
{
	SetTimer("PickupsCoordChecker",1000,1);
	SetTimer("KeyT",100,1);
	SetTimer("GatesCoordChecker",1000,1);
	SetTimer("PortaoCoordChecker",1000,1);
	SetTimer("Bancos", 1000, 1);
	SetTimer("GasSaving",120000,1);
	SetTimer("CheckFuel", 50000, 1);
	SetTimer("MoneyGrubScoreUpdate", 200, 1);
	SetTimer("TempoPrisao", 1000, 1);
	SetTimer("Taxi", 5000, 1);
	SetTimer("Tempo", 900, 1);
	SetTimer("Speed",1000,1);
	SetTimer("Radar",1000,1);
	SetTimer("Casino", 5013, 1);
	SetTimer("VoteKickTimer", 1000, 1);
	SetTimer("sequestrar", 60000, 1);
	SetTimer("Desmancheveiculo",300000, 1);
}

stock CriarTextdraws()
{
	Bemvindo = TextDrawCreate(320,130,"~r~Bem-vindo ao ~b~~n~FreeStyle RPG");
	TextDrawColor(Bemvindo,0xFFF000FF);
	TextDrawAlignment(Bemvindo,2);
	TextDrawFont(Bemvindo,0);
	TextDrawLetterSize(Bemvindo,2.2,4.8);
	//txtdr2
	Bemvindo2 = TextDrawCreate(320,240,"~w~Comandos principais: ~n~ /ajuda - Ajuda sobre o RPG ~n~ /aprender - Aprenda mais sobre o RPG ~n~ /profs - Lista de profiss¨es ~n~ Para mais comandos, digite /comandos ~n~ ~n~ ~n~ ~y~Infernus Development Group ~n~ ~r~Sua diversšo, Nosso objetivo ~n~ ~n~ ~b~Visite o nosso site: WWW.GTABRASIL.NET");
	TextDrawColor(Bemvindo2,COLOR_GREEN);
	TextDrawAlignment(Bemvindo2,2);
	TextDrawFont(Bemvindo2,1);
	TextDrawSetOutline(Bemvindo2,1);
//	TextDrawLetterSize(Bemvindo2,1,1);
	TextDrawSetShadow(Bemvindo2,0);
	//site-announce
	Bemvindo3 = TextDrawCreate(320,400,"Visite nosso site: WWW.GTABRASIL.NET ~n~WWW.MPACLAN.COM");
	TextDrawColor(Bemvindo3,COLOR_COP_NARCOTICOS);
	TextDrawSetOutline(Bemvindo3,1);
	TextDrawSetShadow(Bemvindo3,1);
	TextDrawAlignment(Bemvindo3,2);
	//missao 1
	tdMissao1 = TextDrawCreate(320,340,"Pegue a maleta");
	TextDrawSetShadow(tdMissao1,1);
	TextDrawAlignment(tdMissao1,2);
	//missao 2
	tdMissao2 = TextDrawCreate(320,340,"Va ate o banco e saque, pelo menos, $1000");
	TextDrawSetShadow(tdMissao2,1);
	TextDrawAlignment(tdMissao2,2);
	//missao 3
	tdMissao3 = TextDrawCreate(320,340,"Va ate a marca ~r~vermelha ~s~mostrada no radar.");
	TextDrawSetShadow(tdMissao3,1);
	TextDrawAlignment(tdMissao3,2);
	//separador
	new Text:null = TextDrawCreate(320,340,"_");
	TextDrawSetShadow(null,1);
	TextDrawAlignment(null,2);
	//posto-td
	Posto = TextDrawCreate(5,300,"~b~Posto");
	TextDrawColor(Posto,COLOR_WHITE);
	TextDrawAlignment(Posto,0);
	TextDrawFont(Posto,0);
	TextDrawLetterSize(Posto,2,2);
	//banco-td
	Banco = TextDrawCreate(5,300,"Banco");
	TextDrawColor(Banco,COLOR_GREEN);
	TextDrawAlignment(Banco,0);
	TextDrawFont(Banco,0);
	TextDrawLetterSize(Banco,2,2);
	//hotel-td
	Hotel = TextDrawCreate(320,180,"~b~Hotel");
	TextDrawColor(Hotel,COLOR_WHITE);
	TextDrawAlignment(Hotel,2);
	TextDrawFont(Hotel,0);
	TextDrawLetterSize(Hotel,3,3);
	//hospital-td
	Hospital = TextDrawCreate(5,300,"Hospital");
	TextDrawColor(Hospital,COLOR_WHITE);
	TextDrawAlignment(Hospital,0);
	TextDrawFont(Hospital,0);
	TextDrawLetterSize(Hospital,2,2);
	//24/7-td
	td247 = TextDrawCreate(5,300,"Loja de Utilidades ~n~$1,99");
	TextDrawColor(td247,COLOR_PALHA);
	TextDrawFont(td247,3);
	TextDrawLetterSize(td247,2,2);
	//lixao-td
	tdLixao = TextDrawCreate(5,300,"Lixšo ou ~n~ Ferro-Velho");
	TextDrawColor(tdLixao,COLOR_TRAFICANTE);
	TextDrawFont(tdLixao,0);
	TextDrawLetterSize(tdLixao,2,2);
	//delegacia-td
	Delegacia = TextDrawCreate(5,300,"Delegacia");
	TextDrawColor(Delegacia,COLOR_YELLOW);
	TextDrawAlignment(Delegacia,0);
	TextDrawFont(Delegacia,0);
	TextDrawLetterSize(Delegacia,2,2);
	//area caça-td
	tdCaca = TextDrawCreate(5,300,"rea de Caœa");
	TextDrawColor(tdCaca,COLOR_RED);
	TextDrawAlignment(tdCaca,0);
	TextDrawFont(tdCaca,0);
	TextDrawLetterSize(tdCaca,2,2);
	//desmanche
	tdDesmanche = TextDrawCreate(5,300,"Beco do desmanche");
	TextDrawColor(tdDesmanche,COLOR_RED);
	TextDrawAlignment(tdDesmanche,0);
	TextDrawFont(tdDesmanche,0);
	TextDrawLetterSize(tdDesmanche,2,2);
	//pesca-td
	tdPesca = TextDrawCreate(5,300,"rea de Pesca");
	TextDrawColor(tdPesca,COLOR_GREEN);
	TextDrawAlignment(tdPesca,0);
	TextDrawFont(tdPesca,0);
	TextDrawLetterSize(tdPesca,2,2);
	//cooppesca-td
	tdCoopPesca = TextDrawCreate(5,300,"Cooperativa de Caœa ~n~e Pesca");
	TextDrawColor(tdCoopPesca,COLOR_GREEN);
	TextDrawAlignment(tdCoopPesca,0);
	TextDrawFont(tdCoopPesca,0);
	TextDrawLetterSize(tdCoopPesca,2,2);
	//areacarga-td
	tdAreaCarga = TextDrawCreate(5,300,"rea de Carga");
	TextDrawColor(tdAreaCarga,COLOR_GREEN);
	TextDrawAlignment(tdAreaCarga,0);
	TextDrawFont(tdAreaCarga,0);
	TextDrawLetterSize(tdAreaCarga,2,2);
	//areadescarga-td
	tdAreaDescarga = TextDrawCreate(5,300,"rea de Descarga");
	TextDrawColor(tdAreaDescarga,COLOR_GREEN);
	TextDrawAlignment(tdAreaDescarga,0);
	TextDrawFont(tdAreaDescarga,0);
	TextDrawLetterSize(tdAreaDescarga,2,2);
	//plant
	tdPlant = TextDrawCreate(5,300,"rea de Plantio");
	TextDrawColor(tdPlant,COLOR_GREEN);
	TextDrawAlignment(tdPlant,0);
	TextDrawFont(tdPlant,0);
	TextDrawLetterSize(tdPlant,2,2);
	//leite
	tdLeite = TextDrawCreate(5,300,"Curral das Vaca");
	TextDrawColor(tdLeite,COLOR_RED);
	TextDrawAlignment(tdLeite,0);
	TextDrawFont(tdLeite,0);
	TextDrawLetterSize(tdLeite,2,2);
	//venda-milho
	tdColheita = TextDrawCreate(5,300,"Venda do milho/Leite");
	TextDrawColor(tdColheita,COLOR_GREEN);
	TextDrawAlignment(tdColheita,0);
	TextDrawFont(tdColheita,0);
	TextDrawLetterSize(tdColheita,2,2);
	//forte-td
	tdForte = TextDrawCreate(5,300,"rea Forte");
	TextDrawColor(tdForte,COLOR_RED);
	TextDrawAlignment(tdForte,0);
	TextDrawFont(tdForte,0);
	TextDrawLetterSize(tdForte,2,2);
	//pedreira-td
	tdPdCarga = TextDrawCreate(5,300,"Pedreira");
	TextDrawColor(tdPdCarga,COLOR_GREEN);
	TextDrawAlignment(tdPdCarga,0);
	TextDrawFont(tdPdCarga,0);
	TextDrawLetterSize(tdPdCarga,2,2);
	//construção
	tdConstrucao = TextDrawCreate(5,300,"Construœšo");
	TextDrawColor(tdConstrucao,COLOR_GREEN);
	TextDrawAlignment(tdConstrucao,0);
	TextDrawFont(tdConstrucao,0);
	TextDrawLetterSize(tdConstrucao,2,2);
	//area-recarga
	tdRecarga = TextDrawCreate(5,300,"rea de Recarga");
	TextDrawColor(tdRecarga,COLOR_PALHA);
	TextDrawAlignment(tdRecarga,0);
	TextDrawFont(tdRecarga,0);
	TextDrawLetterSize(tdRecarga,2,2);
	//Boate
	tdStrip = TextDrawCreate(5,300,"Boate de Strip");
	TextDrawColor(tdStrip,COLOR_ROSA);
	TextDrawAlignment(tdStrip,0);
	TextDrawFont(tdStrip,0);
	TextDrawLetterSize(tdStrip,2,2);
	//Hora
	tdHora = TextDrawCreate(630,435,GetFormattedTime());
	TextDrawFont(tdHora,3);
	TextDrawAlignment(tdHora,3);
	TextDrawSetShadow(tdHora,1);
	TextDrawSetOutline(tdHora,1);
	//Escuro
	tdEscuro = TextDrawCreate(0.0,0.0,"_");
	TextDrawFont(tdEscuro,1);
	TextDrawLetterSize(tdEscuro, 0.0, 50.0);
	TextDrawUseBox(tdEscuro, true);
	TextDrawColor(tdEscuro,0);
	TextDrawBoxColor(tdEscuro, 0x000000FF);
	//Caixa Velocimetro
	tdVeloCaixa = TextDrawCreate(470,340,"_");
	TextDrawFont(tdVeloCaixa,1);
	TextDrawLetterSize(tdVeloCaixa,0.0,5.0);
	TextDrawTextSize(tdVeloCaixa,640,20);
	TextDrawUseBox(tdVeloCaixa, true);
	TextDrawColor(tdVeloCaixa,0);
	TextDrawBoxColor(tdVeloCaixa, 0x000000AA);
	//Velicmetro Titulo
	tdVeloTitle = TextDrawCreate(475,330,"Ve¢culo");
	TextDrawFont(tdVeloTitle,0);
	TextDrawLetterSize(tdVeloTitle,1,1.5);
	TextDrawSetOutline(tdVeloTitle,2);
}

stock ProcessaMorte(playerid)
{
	TextDrawShowForPlayer(playerid,tdEscuro);
	SetTimerEx("EsconderTextdraw",5000,false,"dd",playerid,_:tdEscuro);
	SetPlayerPos(playerid,3335.0933,-164.4139,8.5);
	SetPlayerFacingAngle(playerid,273.2);
	SetTimerEx("AnimacaoMorte",1000,false,"d",playerid);
	TogglePlayerControllable(playerid,0);
	SendClientMessage(playerid,COLOR_RED,"Você foi encontrado e resgatado por uma equipe de médicos,");
	SendClientMessage(playerid,COLOR_RED,"e agora está sob observação médica. Você sairá daqui dentro de 2 horas.");
	new h = HospitalInternado[playerid]-1;
	SetSpawnInfo(playerid,0,GetPlayerSkin(playerid),Hospitais[h][0],Hospitais[h][1],Hospitais[h][2],Hospitais[h][3],0,0,0,0,0,0);
	SetTimerEx("AcabaMorte",120000,false,"d",playerid);
}

forward AnimacaoMorte(playerid);
public AnimacaoMorte(playerid)
{
	ApplyAnimation(playerid,"FINALE","FIN_Land_Die",4.1,0,1,1,1,1);
	ApplyAnimation(playerid,"FINALE","FIN_Land_Die",4.1,0,1,1,1,1);
	SetPlayerCameraPos(playerid,3334.5413,-168.5578,8.6388);
	SetPlayerCameraLookAt(playerid,3335.0933,-164.4139,8.3485);
}

forward AcabaMorte(playerid);
public AcabaMorte(playerid)
{
	HospitalInternado[playerid]=0;
	SpawnPlayer(playerid);
	TogglePlayerControllable(playerid,1);
	TrocarBankmoney(PlayerName(playerid), PegarBankmoney(PlayerName(playerid)) - 120);
	ResetPlayerWeapons(playerid);
	SetPlayerVirtualWorld(playerid,0);
	SendClientMessage(playerid,COLOR_RED,"A equipe médica lhe deu alta, agora você pode prosseguir.");
	SendClientMessage(playerid,COLOR_RED,"Como forma de pagamento, a equipe médica lhe descontou do banco");
	SendClientMessage(playerid,COLOR_RED,"120 dólares e confiscou todas suas armas.");
}

forward EsconderTextdraw(playerid,Text:tdid);
public EsconderTextdraw(playerid,Text:tdid) TextDrawHideForPlayer(playerid,tdid);

stock LoteriaComeco()
{
	ProcessaRevoSena();
	ProcessaRevoQuina();
}

stock ProcessaRevoSena()
{
	new n1,n2,n3,n4,n5,n6,msg[256],acertadoresquadra,acertadoresquina,acertadoressena;
/*	n1 = minrand(1,60);
	n2 = minrand(1,60);
	while(n2 == n1) n2 = minrand(1,60);
	n3 = minrand(1,60);
	while(n3 == n2 || n3 == n1) n3 = minrand(1,60);
	n4 = minrand(1,60);
	while(n4 == n1 || n4 == n2 || n3 == n4) n4 = minrand(1,60);
	n5 = minrand(1,60);
	while(n5 == n1 || n5 == n2 || n5 == n3 || n5 == n4) n5 = minrand(1,60);
	n6 = minrand(1,60);
	while(n6 == n1 || n6 == n2 || n6 == n4 || n6 == n4 || n6 == n5) n6 = minrand(1,60); */
	n1 = 1; n2 = 2; n3 = 3; n4 = 4, n5 = 5, n6 = 6;
	new premio = strval(PRIV_sqlget("loterias","premiosena",PRIV_FWI(1)));
	new premiosena = premio;
	new premioquina = premio/100;
	new premioquadra = premioquina/100;
	new concurso = strval(PRIV_sqlget("loterias","concursosena",PRIV_FWI(1)));
	format(msg,256,"REVO-SENA: Resultado para o concurso %03d:",concurso);
	SendClientMessageToAll(COLOR_AZULPLUS,msg);
	format(msg,256,"Números sorteados: %d, %d, %d, %d, %d, %d",n1,n2,n3,n4,n5,n6);
	SendClientMessageToAll(COLOR_COP_SWAT,msg);
	print("primeiro loop");
	for(new i; i<MAX_PLAYERS; i++){
	    if(IsPlayerConnected(i) && ApostandoSena[i]) {
	        new acertosanteriores;
	        for(new j; j<100; j++) {
	            acertosanteriores = Acertos[i];
				for(new k; k<6; k++) if(ApostaSena[i][j][k] == n1 || ApostaSena[i][j][k] == n2 || ApostaSena[i][j][k] == n3 || ApostaSena[i][j][k] == n4 || ApostaSena[i][j][k] == n5 || ApostaSena[i][j][k] == n6) Acertos[i]++;
  				if(Acertos[i] < acertosanteriores) Acertos[i]=acertosanteriores;
			}
			if(Acertos[i] < 4) SendClientMessage(i,COLOR_RED,"Infelizmente você não ganhou na REVO-SENA. Quem sabe na próxima tentativa!");
			switch(Acertos[i]) {
			    case 4: {
					SendClientMessage(i,COLOR_WHITE,"Você acertou 4 números na REVO-SENA");
					acertadoresquadra++;
				}
				case 5: {
					SendClientMessage(i,COLOR_PALHA,"Você acertou 5 números na REVO-SENA");
					acertadoresquina++;
				}
				case 6: {
				    SendClientMessage(i,COLOR_RED2,"Parabéns!!! Você é agora o mais novo milionário de San Andreas!");
				    acertadoressena++;
				}
			}
		}
	}
	premioquadra = divloto(premioquadra,acertadoresquadra);
	premioquina = divloto(premioquina,acertadoresquina);
	premiosena = divloto(premiosena,acertadoressena);
	for(new i; i<MAX_PLAYERS; i++) {
		if(!ApostandoSena[i]) continue;
	    new seupremio;
	    switch(Acertos[i]){
	        case 4: seupremio = premioquadra;
	        case 5: seupremio = premioquina;
	        case 6: seupremio = premiosena;
		}
		format(msg,256,"Seu prêmio: US$%d",seupremio);
		Acertos[i]=0;
		ApostandoSena[i] = false;
		SendClientMessage(i,COLOR_PALHA,msg);
		if(seupremio > 0) TrocarBankmoney(PlayerName(i),PegarBankmoney(PlayerName(i))+seupremio);
        for(new j; j<100; j++) for(new k; k<6; k++) ApostaSena[i][j][k] = 0;
	}
	if(acertadoressena == 0) SendClientMessageToAll(COLOR_AZULPLUS,"Não houve acertadores de 6 pontos na REVO-SENA");
	else if(acertadoressena == 1) SendClientMessageToAll(COLOR_AZULPLUS,"Houve 1 sortudo que acertou os 6 pontos na REVO-SENA");
	else {
		format(msg,256,"Houve %d sortudos que acertaram os 6 pontos na REVO-SENA. O prêmio foi dividido em partes iguais.",acertadoressena);
		SendClientMessageToAll(COLOR_AZULPLUS,msg);
	}
	concurso++;
	concurso %= 1000;
	new acumulo;
	if(!acertadoressena) acumulo += premio;
	new constr[256];
	format(constr,256,"%03d",concurso);
	if(constr[2] == '0'){
		acumulo += 10000000;
		format(msg,256,"Prêmio acumulado para o próximo concurso de final 0: %d",acumulo);
	} else if(constr[2] == '5'){
		acumulo += 5000000;
		format(msg,256,"Prêmio acumulado para o próximo concurso de final 5: %d",acumulo);
	} else {
	    acumulo += 1000000;
		format(msg,256,"Prêmio acumulado para o próximo concurso: %d",acumulo);
	}
	SendClientMessageToAll(COLOR_COP_SWAT,msg);
	PRIV_sqlset("loterias","premiosena",IntToStr(acumulo),PRIV_FWI(1));
	PRIV_sqlset("loterias","concursosena",IntToStr(concurso),PRIV_FWI(1));
	return 1;
}

stock divloto(param1,param2)
{
	if(param2 == 0) return 0;
	return param1/param2;
}

stock ProcessaRevoQuina()
{
	new n1,n2,n3,n4,n5,msg[256],acertadoresterno,acertadoresquadra,acertadoresquina;
	n1 = minrand(1,60);
	n2 = minrand(1,60);
	while(n2 == n1) n2 = minrand(1,60);
	n3 = minrand(1,60);
	while(n3 == n2 || n3 == n1) n3 = minrand(1,60);
	n4 = minrand(1,60);
	while(n4 == n1 || n4 == n2 || n3 == n4) n4 = minrand(1,60);
	n5 = minrand(1,60);
	while(n5 == n1 || n5 == n2 || n5 == n3 || n5 == n4) n5 = minrand(1,60);
	new premio = strval(PRIV_sqlget("loterias","premioquina",PRIV_FWI(1)));
	new premioquina = premio;
	new premioquadra = premio/100;
	new premioterno = premioquadra/100;
	new concurso = strval(PRIV_sqlget("loterias","concursoquina",PRIV_FWI(1)));
	format(msg,256,"REVO-QUINA: Resultado para o concurso %03d:",concurso);
	SendClientMessageToAll(COLOR_AZULPLUS,msg);
	format(msg,256,"Números sorteados: %d, %d, %d, %d, %d",n1,n2,n3,n4,n5);
	SendClientMessageToAll(COLOR_COP_SWAT,msg);
	for(new i; i<MAX_PLAYERS; i++){
	    if(IsPlayerConnected(i) && ApostandoQuina[i]) {
	        new acertosanteriores;
	        for(new j; j<100; j++) {
				acertosanteriores = Acertos[i];
				for(new k; k<5; k++) if(ApostaQuina[i][j][k] == n1 || ApostaQuina[i][j][k] == n2 || ApostaQuina[i][j][k] == n3 || ApostaQuina[i][j][k] == n4 || ApostaQuina[i][j][k] == n5) Acertos[i]++;
 				if(Acertos[i] < acertosanteriores) Acertos[i]=acertosanteriores;
			}
			if(Acertos[i] < 3) SendClientMessage(i,COLOR_RED,"Infelizmente você não ganhou na REVO-QUINA. Quem sabe na próxima tentativa!");
   			switch(Acertos[i]) {
			    case 3: {
					SendClientMessage(i,COLOR_WHITE,"Você acertou 3 números na REVO-QUINA");
					acertadoresterno++;
				}
				case 4: {
					SendClientMessage(i,COLOR_PALHA,"Você acertou 4 números na REVO-QUINA");
					acertadoresquadra++;
				}
				case 5: {
				    SendClientMessage(i,COLOR_RED2,"Parabéns!!! Você é agora o mais novo rico de San Andreas!");
				    acertadoresquina++;
				}
			}
		}
	}
	premioterno = divloto(premioterno,acertadoresterno);
	premioquadra = divloto(premioquadra,acertadoresquadra);
	premioquina = divloto(premioquina,acertadoresquina);
	for(new i; i<MAX_PLAYERS; i++) {
	    if(!ApostandoQuina[i]) continue;
        new seupremio;
	    switch(Acertos[i]){
	        case 3: seupremio = premioterno;
	        case 4: seupremio = premioquadra;
	        case 5: seupremio = premioquina;
		}
		format(msg,256,"Seu prêmio: US$%d",seupremio);
		Acertos[i]=0;
		ApostandoQuina[i] = false;
		if(seupremio > 0) TrocarBankmoney(PlayerName(i),PegarBankmoney(PlayerName(i))+seupremio);
		for(new j; j<100; j++) for(new k; k<5; k++) ApostaQuina[i][j][k] = 0;
		SendClientMessage(i,COLOR_PALHA,msg);
	}
	if(acertadoresquina == 0) SendClientMessageToAll(COLOR_AZULPLUS,"Não houve acertadores de 5 pontos na REVO-QUINA");
	else if(acertadoresquina == 1) SendClientMessageToAll(COLOR_AZULPLUS,"Houve 1 sortudo que acertou os 5 pontos na REVO-QUINA");
	else {
		format(msg,256,"Houve %d sortudos que acertaram os 5 pontos na REVO-QUINA. O prêmio foi dividido em partes iguais.",acertadoresquina);
		SendClientMessageToAll(COLOR_AZULPLUS,msg);
	}
	concurso++;
	concurso %= 1000;
	new acumulo;
	if(!acertadoresquina) acumulo += premio;
	new constr[256];
	format(constr,256,"%03d",concurso);
	if(constr[2] == '0'){
		acumulo += 1000000;
		format(msg,256,"Prêmio acumulado para o próximo concurso de final 0: %d",acumulo);
	} else if(constr[2] == '5'){
		acumulo += 500000;
		format(msg,256,"Prêmio acumulado para o próximo concurso de final 5: %d",acumulo);
	} else {
	    acumulo += 100000;
		format(msg,256,"Prêmio acumulado para o próximo concurso: %d",acumulo);
	}
	SendClientMessageToAll(COLOR_COP_SWAT,msg);
	PRIV_sqlset("loterias","premioquina",IntToStr(acumulo),PRIV_FWI(1));
	PRIV_sqlset("loterias","concursoquina",IntToStr(concurso),PRIV_FWI(1));
	return 1;
}

public strtik(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ',')) index++;
	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ',') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return 1;
}

public Desmancheveiculo()
{
	new string[256];
	new n = random(MAX_DESMANCHEVEICULO);
	format(string, sizeof(string),"Aew! Maluco tá afim de discolar um carro pra nós ? Que tal um(a) %s?", Veiculosprocuradosnome[n]);
	Veiculoprocurado = Veiculosprocurados[n];
	for(new i;i<MAX_PLAYERS;i++) if(Profissao[i] == LADRAO_DE_CARROS) SendClientMessage(i,COLOR_AZULPLUS, string);
	return 1;
}

public Pesca(playerid)
{
	QtPescas[playerid]++;
	PescaInProgress[playerid] = 0;
	SendClientMessage(playerid,COLOR_GREEN,"Sua rede voltou. Se quiser continuar pescando, fique a vontade.");
	SendClientMessage(playerid,COLOR_GREEN,"Se não, vá a cooperativa de pescas e venda seu pescado.");
}

public Caca(playerid)
{
	QtCacas[playerid]++;
	CacaInProgress[playerid] = 0;
	SendClientMessage(playerid,COLOR_GREEN,"Sua caça está pronta para ser vendida!");
	SendClientMessage(playerid,COLOR_GREEN,"Se quiser continuar caçando, fique a vontade.");
	SendClientMessage(playerid,COLOR_GREEN,"Se não, vá a cooperativa de caça e venda sua caça.");
}
public Fazenda(playerid)
{
	QtMilho[playerid]++;
	FazendaInProgress[playerid] = 0;
	SendClientMessage(playerid,COLOR_AGRICULTOR,"A colheita e o ensacamento estão completos. Se quiser continuar plantando, fique a vontade.");
	SendClientMessage(playerid,COLOR_GREEN,"Caso contrário, vá até a área de venda do milho e o venda.");
}
public LeiteA(playerid)
{
	QtLeite[playerid]++;
	LeiteInProgress[playerid] = 0;
	ClearAnimations(playerid);
	SendClientMessage(playerid,COLOR_AGRICULTOR,"Cê tirô todo o leite da vaca. Vá vender lá na fazenda cumpade.Se quiser continuar pegando nas teta.");
	SendClientMessage(playerid,COLOR_AGRICULTOR,"Caso adverso, vá até a área de venda do milho/leite e o venda.");
}
public Prostituir(playerid)
{
	ApplyAnimation(playerid,"benchpress","gym_bp_up_B",4.1,0,1,1,1,1);
	SendClientMessage(playerid, COLOR_ROSA, "Para mudar de posição digite /mudarposicao");
}
public Strip(playerid)
{
	ApplyAnimation(playerid,"STRIP","strip_A",4.1,0,1,1,1,10);
	SetTimerEx("Strip3",5000,0,"d",playerid);
}
public Strip3(playerid)
{
	ApplyAnimation(playerid,"STRIP","STR_A2B",4.1,0,1,1,1,10);
	SetTimerEx("Strip4",5000,0,"d",playerid);
}
public Strip4(playerid)
{
	ApplyAnimation(playerid,"STRIP","STR_Loop_C",4.1,0,1,1,1,10);
	ClearAnimations(playerid);
	SetPlayerPos(playerid,-2666.8901,1410.1359,906.2734);
	SendClientMessage(playerid, COLOR_ROSA2, "Acabou o strip-tease.");
}
public GetPlayerID(string[]) {
	for(new i = 0; i <= MAX_PLAYERS; i++) if(IsPlayerConnected(i) == 1) if(compare(PlayerName(i), string)) return i;
	return INVALID_PLAYER_ID;
}
public minrand(min, max) return random(max - min) + min;

stock SendClientMessagePolicia(text_color, string_text[]) for(new i=0;i<MAX_PLAYERS;i++) if(IsPlayerConnected(i)) if(Profissao[i] == COP_SWAT || Profissao[i] == COP_RODOVIARIO || Profissao[i] == COP_MILITAR || Profissao[i] == COP_NARCOTICOS || Profissao[i] == SHERIFF) SendClientMessage(i, text_color, string_text);

stock SendClientMessageJuiz(text_color, string_text[]) for(new i=0;i<MAX_PLAYERS;i++) if(IsPlayerConnected(i)) if(Profissao[i] == JUIZ || IsPlayerAdmin(i)) SendClientMessage(i, text_color, string_text);

stock SendClientMessageVendedor(text_color, string_text[]) for(new i=0;i<MAX_PLAYERS;i++) if(IsPlayerConnected(i)) if(Profissao[i] == VENDEDOR_DE_ARMAS) SendClientMessage(i, text_color, string_text);

stock SendClientMessageCarros(text_color, string_text[]) for(new i=0;i<MAX_PLAYERS;i++) if(IsPlayerConnected(i)) if(Profissao[i] == LOCADOR_DE_CARROS) SendClientMessage(i, text_color, string_text);

stock SendClientMessageAdmin(text_color, string_text[]) for(new i=0;i<MAX_PLAYERS;i++) if(IsPlayerConnected(i)) if(IsPlayerAdmin(i)) SendClientMessage(i, text_color, string_text);

stock SendClientMessageLadrao(text_color, string_text[]) for(new i=0;i<MAX_PLAYERS;i++)  if(IsPlayerConnected(i))  if(Profissao[i] == LADRAO_DE_CARROS || RECEITA_FEDERAL) SendClientMessage(i, text_color, string_text);

public GetClosestHospital(playerid)
{
	if(!IsPlayerConnected(playerid)){
	    return -1;
	}
	new Float:prevdist = 100000.000;
	new prevhosp;
	for(new hospid; hospid < 5; hospid++){
	    new Float:dist;
	    dist = GetPlayerDistanceToPoint(playerid,Hospitais[hospid][0],Hospitais[hospid][1]);
		if((dist < prevdist)){
		    prevdist = dist;
		    prevhosp = hospid;
		}
	}
	return prevhosp;
}

stock PlayerName(playerid)
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, MAX_PLAYER_NAME);
	return name;

}

public LogarPlayer(playerid)
{
    new Float:X, Float:Y, Float:Z, Float:ang;
	PegarPos(PlayerName(playerid),X,Y,Z,ang);
	new grana = PegarAccState(PlayerName(playerid))-GetPlayerMoney(playerid);
	GivePlayerMoney(playerid, grana);
	new skin = PegarSkin(PlayerName(playerid));
	Profissao[playerid] = PegarProf(PlayerName(playerid));
	new prof = Profissao[playerid];
	if(X == ProfPos[1][0] && Y == ProfPos[1][1] && Z == ProfPos[1][2]) {
	    X = ProfPos[prof][0];
	    Y = ProfPos[prof][1];
	    Z = ProfPos[prof][2];
	}
	SetSpawnInfo(playerid, 1, skin, X, Y, Z, ang, 0, 0, 0, 0, 0, 0);
	Petrol[playerid] = PegarGas(PlayerName(playerid));
	SetPlayerWantedLevel(playerid,PegarWantedLevel(PlayerName(playerid)));
	new prisao = PegarPrisao(PlayerName(playerid));
	if(prisao == 1 || Procurados[playerid] == 1){
		Procurados[playerid] = 0;
		new cela;
		Presos[playerid] = 1;
		cela = random(3);
		SetPlayerFacingAngle(playerid,0);
		SetPlayerInterior(playerid,10);
		PrisaoTimer[playerid][1]=1;
		PrisaoTimer[playerid][0]=SetTimerEx("SetPlayerFree",5*60*1000,false,"d",playerid);
		SetPlayerPos(playerid,Celas[cela][0],Celas[cela][1],Celas[cela][2]);
		SendClientMessage(playerid,COLOR_RED,"Você deve ter cometido algum crime, por isso foi preso.");
		SendClientMessage(playerid,COLOR_RED,"Para sair mais cedo da prisão, você pode pagar a fiança de $1500,");
		SendClientMessage(playerid,COLOR_RED,"escrevendo /fianca.");
	}
	else SpawnPlayer(playerid);
}
public IsNumeric(const string[]) //By Mike
{
	for (new i = 0, j = strlen(string); i < j; i++) if (string[i] > '9' || string[i] < '0') return 0;
	return 1;
}
public SetPlayerFree(playerid){
    TrocarPrisao(PlayerName(playerid), 0);
    Presos[playerid] = 0;
    SetSpawnInfo(playerid,0,PegarSkin(PlayerName(playerid)),-1605.5067,710.3071,13.8672,0,0,0,0,0,0,0);
    SpawnPlayer(playerid);
    SendClientMessage(playerid,COLOR_GREEN,"Você foi solto, mas se cometer mais crimes, pagará novamente.");
    Contrabando[playerid] = 0;
	PrisaoTimer[playerid][1] = 0;
	KillTimer(PrisaoTimer[playerid][0]);
	SetPlayerWantedLevel(playerid, 0);
	TrocarWantedLevel(PlayerName(playerid), 0);
}

#include <revo/vehicle.own>
#include <revo/user.own>
#include <revo/mysql.own>
