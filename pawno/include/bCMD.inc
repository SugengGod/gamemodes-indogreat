/*
	bCMD - New Command Processor
		Creator: BlueX
		Version: 1.8
		Last Update: 17/12/2012
*/
#if defined _bcmd_include
    #endinput
#endif
#define _bcmd_include
#include <a_samp>

#define bCMD[%0]>(%1:%2:%3)\
    forward bcmd_%0(%1,%2,%3);\
	public bcmd_%0(%1,%2,%3)

#define CMD::%0(%1,%2,%3)\
    bCMD[%0]>(%1:%2:%3)

#define cmd(%0:%1,%2,%3)\
    bCMD[%0]>(%1:%2:%3)

#if !defined isnull
	#define isnull(%1) \
				((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

forward OnPlayerCallCommand(playerid,cmdtext[],sucess);
const
    C_COMMAND_LEN = 32,
    C_KEY_LEN = 2,
	C_PARAMS_LEN = 255;

public OnPlayerCommandText(playerid,cmdtext[]){
	new key1[C_KEY_LEN],params1[C_PARAMS_LEN] = "\1",callback1[32] = "bcmd_";
	strmid(key1,cmdtext,0,1),strdel(cmdtext,0,1);
	if(strfind(cmdtext," ") != -1) strmid(params1,cmdtext,strfind(cmdtext," ")+1,255),strdel(cmdtext,strfind(cmdtext," "),255);
	strins(callback1,cmdtext,5);
	if(funcidx(callback1) == -1)
	    strins(cmdtext,key1,0,32),CallLocalFunction("OnPlayerCallCommand","dsd",playerid,cmdtext,0);
	else {
		CallLocalFunction(callback1,"dsd",playerid,isnull(params1) ? ("\1") : (params1),!strcmp(params1,"help",false) || !strcmp(params1,"ajuda",false));
        strins(cmdtext,key1,0,32),CallLocalFunction("OnPlayerCallCommand","dsd",playerid,cmdtext,1);
	}
	return 1;
}

#if defined _ALS_OnPlayerCommandText
    #undef OnPlayerCommandText
#else
    #define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText bcmd_OnPlayerCommandText
forward bcmd_OnPlayerCommandText(playerid, cmdtext[]);
