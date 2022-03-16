/* --------------------------------------------------------------------------------------------
 *
 *					iniManagement by Emmet_
 *  	       	   Easy ini file management!
 *
 *    	  iniManagement is a new, easy-to-use and quick file management script
 *     	  which allows you to open files, close files, and write inside / read
 *    	  from them.
 *
 *    	  Functions:
 *    	  • INI_Open(filename[]) - Opens a file.
 *    	  • INI_Close(filename[]) - Closes a file.
 *    	  • INI_IntSet(filename[], tagname[], val) - Writes an integer to a file.
 *    	  • INI_FltSet(filename[], tagname[], Float:flt) - Writes a float to a file.
 *    	  • INI_StrSet(filename[], tagname[], str[]) - Writes a string to a file.
 *    	  • INI_GetInt(filename[], tagname[]) - Reads an integer from a file and returns it.
 *    	  • INI_GetFlt(filename[], tagname[]) - Reads a float from a file and returns it.
 *    	  • INI_GetStr(filename[], tagname[], str[]) - Reads a string from a file and returns it.
 *
 *    	  Error codes:
 *    	  • Error code 1 - The file you are trying to access doesn't exist.
 *    	  • Error code 2 - The file you are trying to access is already opened.
 *    	  • Error code 3 - There are already the maximum opened files possible.
 *    	  • Error code 4 - The file you are trying to access is not opened.
 *
 * --------------------------------------------------------------------------------------------
*/

// Includes
#include <a_samp>
//--------------------------------------------------------------------------------------------//
// Limitations & Definitions
#define 	MAX_OPENED_FILES 	 64
#define 	MAX_STRING_SIZE      512
#define     MAX_FILENAME_LENGTH  255
//--------------------------------------------------------------------------------------------//
new File:fHandle[MAX_OPENED_FILES];
new fName[MAX_OPENED_FILES][MAX_FILENAME_LENGTH];
new bool:isOpened[MAX_OPENED_FILES];
new openedFiles;
//--------------------------------------------------------------------------------------------//
stock INI_Open(filename[])
{
	if (INI_IsOpened(filename) == 1)
	{
		print("Error code 2.");
		return 0;
	}

	if (openedFiles == MAX_OPENED_FILES)
	{
		print("Error code 3.");
	    return 0;
	}
	    
	new File: file = fopen(filename, io_readwrite);
	if (file)
	{
	    openedFiles ++;
	    isOpened[openedFiles] = true;
	    fHandle[openedFiles] = file;
	    format(fName[openedFiles], MAX_FILENAME_LENGTH, filename);
	    return 1;
	}
	return 0;
}
//--------------------------------------------------------------------------------------------//
stock INI_Close(filename[])
{
	if (fexist(filename) == 0)
	{
	    print("Error code 1.");
	    return 0;
	}

	if (INI_IsOpened(filename) == 1)
	{
 		openedFiles --;
 		fHandle[openedFiles] = File:0;
  		isOpened[INI_RetrieveID(filename)] = false;
		strdel(fName[INI_RetrieveID(filename)], 0, MAX_FILENAME_LENGTH);
		return 1;
	}
	else printf("Error code 4.");
	return 0;
}
//--------------------------------------------------------------------------------------------//
stock INI_IntSet(filename[], tagname[], val)
{
    if (fexist(filename) == 0)
	{
	    print("Error code 1.");
	    return 0;
	}

	if (INI_IsOpened(filename) == 0)
	{
	    print("Error code 4.");
	    return 0;
	}

	new string[MAX_STRING_SIZE];

	format(string, sizeof(string), "%s = %d\r\n", tagname, val);
	fwrite(fHandle[INI_RetrieveID(filename)], string);
	return 1;
}
//--------------------------------------------------------------------------------------------//
stock INI_FltSet(filename[], tagname[], Float:flt)
{
    if (fexist(filename) == 0)
	{
	    print("Error code 1.");
	    return 0;
	}

	if (INI_IsOpened(filename) == 0)
	{
	    print("Error code 4.");
	    return 0;
	}

	new string[MAX_STRING_SIZE];

	format(string, sizeof(string), "%s = %f\r\n", tagname, flt);
	fwrite(fHandle[INI_RetrieveID(filename)], string);
	return 1;
}
//--------------------------------------------------------------------------------------------//
stock INI_StrSet(filename[], tagname[], str[])
{
    if (fexist(filename) == 0)
	{
	    print("Error code 1.");
	    return 0;
	}

	if (INI_IsOpened(filename) == 0)
	{
	    print("Error code 4.");
	    return 0;
	}

	new string[MAX_STRING_SIZE];

	format(string, sizeof(string), "%s = %s\r\n", tagname, str);
	fwrite(fHandle[INI_RetrieveID(filename)], string);
	return 1;
}
//--------------------------------------------------------------------------------------------//
stock INI_GetInt(filename[], tagname[])
{
    if (fexist(filename) == 0)
	{
	    print("Error code 1.");
	    return 0;
	}

	if (INI_IsOpened(filename) == 0)
	{
	    print("Error code 4.");
	    return 0;
	}
	
	new string[MAX_STRING_SIZE];
	new tag[MAX_STRING_SIZE];
	new val[MAX_STRING_SIZE];

	while (fread(fHandle[INI_RetrieveID(filename)], string, MAX_STRING_SIZE))
	{
	    if (strfind(string, "=") != -1)
		    strmid(tag, string, 0, strfind(string, "="), sizeof(tag));
		    
        if (strcmp(tag, tagname, false) == 0)
		{
			if (strfind(string, "=") != -1)
			{
				strmid(val, string, (strfind(string, "=") + 1), strlen(string), sizeof(string));
				return strval(val);
			}
		}
	}
	return 0;
}
//--------------------------------------------------------------------------------------------//
stock Float:INI_GetFlt(filename[], tagname[])
{
    if (fexist(filename) == 0)
	{
	    print("Error code 1.");
	    return 0.0;
	}

	if (INI_IsOpened(filename) == 0)
	{
	    print("Error code 4.");
	    return 0.0;
	}

	new string[MAX_STRING_SIZE];
	new tag[MAX_STRING_SIZE];
	new val[MAX_STRING_SIZE];

	while (fread(fHandle[INI_RetrieveID(filename)], string, MAX_STRING_SIZE))
	{
	    if (strfind(string, "=") != -1)
		    strmid(tag, string, 0, strfind(string, "="), sizeof(tag));

        if (strcmp(tag, tagname, false) == 0)
		{
			if (strfind(string, "=") != -1)
			{
				strmid(val, string, (strfind(string, "=") + 1), strlen(string), sizeof(string));
				return floatstr(val);
			}
		}
	}
	return 0.0;
}
//--------------------------------------------------------------------------------------------//
stock INI_GetStr(filename[], tagname[], str[])
{
    if (fexist(filename) == 0)
	{
	    print("Error code 1.");
	    return 0;
	}

	if (INI_IsOpened(filename) == 0)
	{
	    print("Error code 4.");
	    return 0;
	}

	new string[MAX_STRING_SIZE];
	new tag[MAX_STRING_SIZE];
	new val[MAX_STRING_SIZE];

	while (fread(fHandle[INI_RetrieveID(filename)], string, MAX_STRING_SIZE))
	{
	    if (strfind(string, "=") != -1)
		    strmid(tag, string, 0, strfind(string, "="), sizeof(tag));

        if (strcmp(tag, tagname, false) == 0)
		{
			if (strfind(string, "=") != -1)
			{
				strmid(val, string, (strfind(string, "=") + 1), strlen(string), sizeof(string));
				format(str, 256, val);
				return 1;
			}
		}
	}
	return 0;
}
//--------------------------------------------------------------------------------------------//
stock INI_RetrieveID(filename[])
{
	for (new i = 1; i <= openedFiles; i ++)
	{
	    if (isOpened[i] == true)
	    {
	    	if ((strcmp(fName[i], filename, false) == 0) && (strlen(fName[i]) == strlen(filename)))
	        	return i;
		}
	}
	return 0;
}
//--------------------------------------------------------------------------------------------//
stock INI_IsOpened(filename[])
{
	for (new i = 1; i <= openedFiles; i ++)
	{
	    if (isOpened[i] == true)
	    {
	    	if ((strcmp(fName[i], filename, false) == 0) && (strlen(fName[i]) == strlen(filename)))
	        	return 1;
		}
	}
	return 0;
}
