/*--------------------------------------\
|					|
|	     SimpleFiles.inc    	|
|     					|
|  -Creator: Rafelder			|
|  -Credits to me and the creators of	|
|	 	encode, decode and hash	|
|  -Version: 1.0			|
|  -Date: 1st March 2008		|
|  -Require: dini, dutils		|
|					|
|					|
|             (c) Copyright by Rafelder |
\--------------------------------------*/

#if defined _SimpleFiles_included
  #endinput
#endif

#define _SimpleFiles_included

#include <dini>
#include <dutils>

/*
native FileCreate(filename[], password[]);
native FileDelete(filename[]);
native FileExists(filename[])

native SaveFileString(filename[], key[], string[]);
native SaveFileInteger(filename[], key[], integer);
native SaveFileFloat(filename[], key[], Float:float);

native GetFileString(filename[], key[]);
native GetFileInteger(filename[], key[]);
native Float:GetFileFloat(filename[], key[]);

native IsRightPassword(filename[], password[])
native ChangePassword(filename[], newpassword[]);
native EditFileName(filename[], newname[]);
*/


stock FileCreate(filename[], password[])
{
	if(FileExists(filename)) return false;
	new File:afile, filen[MAX_STRING];
	format(filen, sizeof(filen), "%s.txt", NameEncode(filename));
	if (fexist(filen)) return false;
	afile=fopen(filen, io_write);
	fclose(afile);
	SaveFileInteger(filename, "password_hash", f_hash(password));
	return true;
}

stock FileDelete(filename[])
{
	if(!FileExists(filename)) return false;
	new filen[MAX_STRING];
	format(filen, sizeof(filen), "%s.txt", NameEncode(filename));
	if (!fexist(filen)) return false;
	fremove(filen);
	return true;
}

stock FileExists(filename[])
{
	new filen[MAX_STRING];
	format(filen, sizeof(filen), "%s.txt", NameEncode(filename));
	if (fexist(filen)) return true;
	return false;
}

stock SaveFileString(filename[], key[], string[])
{
	if(!FileExists(filename)) return false;
	new filen[MAX_STRING];
	format(filen, sizeof(filen), "%s.txt", NameEncode(filename));
	return dini_Set(filen, key, string);
}

stock SaveFileInteger(filename[], key[], integer)
{
	if(!FileExists(filename)) return false;
	new filen[MAX_STRING];
	format(filen, sizeof(filen), "%s.txt", NameEncode(filename));
	return dini_IntSet(filen, key, integer);
}

stock SaveFileFloat(filename[], key[], Float:float)
{
	if(!FileExists(filename)) return false;
	new filen[MAX_STRING];
	format(filen, sizeof(filen), "%s.txt", NameEncode(filename));
	return dini_FloatSet(filen, key, float);
}

stock GetFileString(filename[], key[])
{
	new fstring[MAX_STRING];
	fstring[0]=0;
	if(!FileExists(filename)) return fstring;
  	format(fstring, sizeof(fstring), "%s.txt", NameEncode(filename));
  	format(fstring, sizeof(fstring), dini_Get(fstring, key));
  	return fstring;
}

stock GetFileInteger(filename[], key[])
{
	if(!FileExists(filename)) return false;
	new fstring[MAX_STRING];
  	format(fstring, sizeof(fstring), "%s.txt", NameEncode(filename));
  	return dini_Int(fstring, key);
}

stock Float:GetFileFloat(filename[], key[])
{
	new Float:wfloat;
	wfloat=0.0;
	if(!FileExists(filename)) return wfloat;
	new fstring[MAX_STRING];
  	format(fstring, sizeof(fstring), "%s.txt", NameEncode(filename));
  	return dini_Float(fstring, key);
	
}

stock IsRightPassword(filename[], password[])
{
	if(!FileExists(filename)) return false;
	new pstring[MAX_STRING];
	format(pstring, sizeof(pstring),"%s.txt", NameEncode(filename));
  	if (GetFileInteger(filename, "password_hash") == f_hash(password)) return true;
  	return false;
}

stock ChangePassword(filename[], newpassword[])
{
	if(!FileExists(filename)) return false;
	SaveFileInteger(filename, "password_hash", f_hash(newpassword));
	return 1;
}


stock EditFileName(filename[], newname[])
{
	if(!FileExists(filename)) return false;
  	new oldfname[MAX_STRING], newfname[MAX_STRING];
  	format(oldfname, sizeof(oldfname), "%s.txt", NameEncode(filename));
  	format(newfname, sizeof(newfname), "%s.txt", NameEncode(newname));
  	return frenametextfile(oldfname, newfname);
}

stock f_hash(buf[])//Wikipage
{
	new length=strlen(buf);
	new s1 = 1;
	new s2 = 0;
	new n;	
	for (n=0; n<length; n++)
	{
		s1 = (s1 + buf[n]) % 65521;
		s2 = (s2 + s1)     % 65521;
	}
	return (s2 << 16) + s1;
}

stock NameEncode(filename[])//From dudb file
{
  	new tmp[MAX_STRING];
  	set(tmp, filename);
  	tmp=strreplace("_","_00",tmp);
  	tmp=strreplace(";","_01",tmp);
  	tmp=strreplace("!","_02",tmp);
  	tmp=strreplace("/","_03",tmp);
  	tmp=strreplace("\\","_04",tmp);
  	tmp=strreplace("[","_05",tmp);
  	tmp=strreplace("]","_06",tmp);
  	tmp=strreplace("?","_07",tmp);
  	tmp=strreplace(".","_08",tmp);
  	tmp=strreplace("*","_09",tmp);
  	tmp=strreplace("<","_10",tmp);
  	tmp=strreplace(">","_11",tmp);
  	tmp=strreplace("{","_12",tmp);
  	tmp=strreplace("}","_13",tmp);
  	tmp=strreplace(" ","_14",tmp);
  	tmp=strreplace("\"","_15",tmp);
  	tmp=strreplace(":","_16",tmp);
  	tmp=strreplace("|","_17",tmp);
  	tmp=strreplace("=","_18",tmp);
  	return tmp;
}

stock NameDecode(filename[])//From dudb file
{
  	new tmp[MAX_STRING];
  	set(tmp, filename);
  	tmp=strreplace("_01",";",tmp);
  	tmp=strreplace("_02","!",tmp);
  	tmp=strreplace("_03","/",tmp);
  	tmp=strreplace("_04","\\",tmp);
  	tmp=strreplace("_05","[",tmp);
  	tmp=strreplace("_06","]",tmp);
  	tmp=strreplace("_07","?",tmp);
  	tmp=strreplace("_08",".",tmp);
  	tmp=strreplace("_09","*",tmp);
  	tmp=strreplace("_10","<",tmp);
  	tmp=strreplace("_11",">",tmp);
  	tmp=strreplace("_12","{",tmp);
  	tmp=strreplace("_13","}",tmp);
  	tmp=strreplace("_14"," ",tmp);
  	tmp=strreplace("_15","\"",tmp);
  	tmp=strreplace("_16",":",tmp);
  	tmp=strreplace("_17","|",tmp);
  	tmp=strreplace("_18","=",tmp);
  	tmp=strreplace("_00","_",tmp);
  	return tmp;
}