#include <a_samp>
#if defined struct
	#endinput
#endif
#define struct
forward setDS(...);
forward getDS(tostring[],...);
forward isDS(...);

/*
	native setDS(...);
	native getDS(tostring[],...);
	native isDS(...);
*/

#define MAX_STRUCT 30

public setDS(...)
{
	new read[256];
	if(!fexist("data.txt"))
	{
		fclose(fopen("data.txt",io_write));
	}

    new string[256];
	for( new arg = 0;arg < numargs()-1;arg++)
	{
		new thisarg[MAX_STRUCT];
		for(new i = 0;i < MAX_STRUCT;i++) thisarg[i] = getarg(arg,i);
		strins(string,thisarg,strlen(string));
		strins(string,":",strlen(string));
	}

	if(!fexist("data.txt")) return 0;
	new File:h = fopen("temp",io_write);
	new File:h2 = fopen("data.txt",io_read);
	while(fread(h2,read))
	{
	 	if(strcmp(read,string,true,strlen(string)))
		 {
		 	fwrite(h,read);
		 }
	}
	fclose(h2);
	fclose(h);
	h = fopen("temp",io_read);
	h2 = fopen("data.txt",io_write);
	while(fread(h,read))
	{
	 	fwrite(h2,read);
	}
	fclose(h);
	fclose(h2);
	fremove("temp");
	format(string,256,"");
	for( new arg = 0;arg < numargs();arg++)
	{
		new thisarg[MAX_STRUCT];
		for(new i = 0;i < MAX_STRUCT;i++) thisarg[i] = getarg(arg,i);
		strins(string,thisarg,strlen(string));
		strins(string,":",strlen(string));
	}
	
	h = fopen("data.txt",io_append);
	strins(string,"\r\n",strlen(string));
	fwrite(h,string);
	fclose(h);
	return 1;
}

public getDS(tostring[],...)
{
	format(tostring,1,"\0");
	if(!fexist("data.txt")) return 0;
    new string[256];
	for( new arg = 1;arg < numargs();arg++)
	{
		new thisarg[MAX_STRUCT];
		for(new i = 0;i < MAX_STRUCT;i++) thisarg[i] = getarg(arg,i);
		strins(string,thisarg,strlen(string));
		strins(string,":",strlen(string));
	}
	new File:h = fopen("data.txt",io_read);
	while(fread(h,tostring,256))
	{
	    if(strcmp(tostring,string,false,strlen(string))==0)
		{
		    strdel(tostring,0,strlen(string));
		    strdel(tostring,strfind(tostring,":"),strlen(tostring));
	 		return 1;
		}
	}
	fclose(h);
	format(tostring,1,"\0");
	return 0;
}

public isDS(...)
{
	if(!fexist("data.txt")) return 0;
    new string[256];
	for( new arg = 0;arg < numargs();arg++)
	{
		new thisarg[MAX_STRUCT];
		for(new i = 0;i < MAX_STRUCT;i++) thisarg[i] = getarg(arg,i);
		strins(string,thisarg,strlen(string));
		strins(string,":",strlen(string));
	}
	new File:h = fopen("data.txt",io_read);
	new read[256];
	while(fread(h,read))
	{
	    if(strcmp(read,string,false,strlen(string))==0) return 1;
	}
	fclose(h);
	return 0;
}
									/*        by Kapil  */
