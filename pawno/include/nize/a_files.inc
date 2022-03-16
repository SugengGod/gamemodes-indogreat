/*
	Cali-Files: Simple file system.
	Create, delete, write and read.
	Steal this and I'll kill you. =D
*/

#if defined _a_files_included
	#endinput
#endif

#define _a_files_included
#pragma library a_files

#include <file>
#include <string>

stock CreateFile(filename[])
{
	if (!fexist(filename)) {
		new File: file = fopen(filename, io_write);
		if (file) {
			fclose(file);
			return 1;
		}
	}
	return 1;
}

stock DeleteFile(filename[])
{
	if (fexist(filename)) {
		fremove(filename);
		return 1;
	}
	return 1;
}

stock Write(filename[], key[])
{
	new File: file = fopen(filename, io_append);
	if (file) {
 	    fwrite(file, key);
        fclose(file);
        return 1;
	}
	return 1;
}

stock NewLine(filename[])
{
	new File: file = fopen(filename, io_append);
	if (file) {
    	fwrite(file, "\r\n");
    	fclose(file);
    	return 1;
	}
	return 1;
}

stock Read(filename[], key[])
{
	new tmp[255], key_length = strlen(key);
	new File: file = fopen(filename, io_read);
	if (file) {
	    while (fread(file, key, sizeof(key))) {
	        if (tmp[key_length] == '=' && !strcmp(tmp, key, true, key_length)) {
	    	    strmid(tmp, tmp, key_length+1, strlen(tmp), 255);
				fclose(file);
   			}
		}
	}
	return tmp;
}