/*
*
*	SA:MP Include
*
*	aSQL.inc : Part of Innova Include Collection (IIC) By Rogér "aFei" Paland
*
*  	Copyright (c) 2011, Innova Gaming (IG)
*
*/










#if !defined mysql_included
	#error "a_mysql needs to be included to make aSQL work"
	#endinput
#endif
#if !defined _samp_included
	#endinput
#endif

#include "SQL/YSI_MD5.own"
#include "SQL/config.ini"










/*
native SQL_ConnectDatabase();
native SQL_DisconnectDatabase();
native -------------------------;
native SQL_GetFloat(dbRowID, const TABLE[], const COLUMN[], &Float:result);
native SQL_GetInt(dbRowID, const TABLE[], const COLUMN[], &myint);
native SQL_GetString(dbRowID, const TABLE[], const COLUMN[]);
native SQL_SetFloat(dbRowID, const TABLE[], const COLUMN[], Float:myfloat, &Float:result);
native SQL_SetInt(dbRowID, const TABLE[], const COLUMN[], INTEGER, &result);
native SQL_SetString(dbRowID, const TABLE[], const COLUMN[], const STRING[]);
native SQL_Write(const TABLE[]);
*/










//#define SQL_FORMATTED_QUERY_DEBUG

#define RANDOM_NUMBER 															-9761264623162

#define RANDOM_FLOAT 															-9761264623162.0000







#if defined mysql_query_format
	#undef mysql_query_format
#endif

new
	bool:FALSE = false;

#define mysql_query_format(%1,%2) do{new fstring[1024];format(fstring,1024,(%1),%2);amysql_query(fstring);}while(FALSE)


stock amysql_query(query[])
{
	new 
		result = mysql_query(query);
	#if defined SQL_FORMATTED_QUERY_DEBUG
    printf(">> aSQL: [Input[]: %s]", query);
	#else
		#pragma unused query
	#endif
	return result;
}



stock SQL_ConnectDatabase()
{
    if(!mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASS))
    {
        print(">> aSQL: Couldn't connect at HOST " #SQL_HOST " [Database: " #SQL_DB "] with USER " #SQL_USER " [Password: " #SQL_PASS "]");

        print(">> aSQL: Retrying..");

        if(!mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASS))
        {

            print(">> aSQL: Couldn't connect at HOST "#SQL_HOST" [Database: "#SQL_DB"] with USER "#SQL_USER" [Password: "#SQL_PASS"]");

            print(">> aSQL: Retrying..");

            if(!mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASS))
            {

                print(">> aSQL: Couldn't connect at HOST "#SQL_HOST" [Database: "#SQL_DB"] with USER "#SQL_USER" [Password: "#SQL_PASS"]");

            	print(">> aSQL: Server start has been stopped!");

                return 0;
            }
        }
    }

    print(">> aSQL: Successfully connected at HOST "#SQL_HOST" [Database: "#SQL_DB"]!");

    return 1;
}

stock SQL_DisconnectDatabase()
{
    if(mysql_ping() == 1) mysql_close();

    print(">> aSQL: Connection to SQL database has been stopped!");

    return 1;
}

stock SQL_Checkdb(const TABLE[], const COLUMN[], const DEFINE[])
{
    mysql_query_format("CREATE TABLE IF NOT EXISTS `" #SQL_PREFIX "%s` (`row_id` int(11) NOT NULL auto_increment, PRIMARY KEY  (`row_id`));", TABLE);

	mysql_query_format("SHOW COLUMNS FROM `"#SQL_PREFIX"%s` LIKE '%s'", TABLE, COLUMN);

	mysql_store_result();

	if (mysql_num_rows())
	{
	    mysql_free_result();
		
		return 1;
	}

    mysql_free_result();

    mysql_query_format("ALTER TABLE `"#SQL_PREFIX"%s` ADD `%s` %s;", TABLE, COLUMN, DEFINE);
		
	return 1;
}

stock SQL_Write(const TABLE[])
{
	mysql_query_format("CREATE TABLE IF NOT EXISTS `" #SQL_PREFIX "%s` (`row_id` int(11) NOT NULL auto_increment, PRIMARY KEY  (`row_id`));", TABLE);
	
	mysql_query_format("ALTER TABLE `"#SQL_PREFIX"%s` ADD `d_o_c` varchar(50) NOT NULL AFTER `row_id` ;", TABLE);
	
	new
		day, month, year, minute, second, hour;
		
	getdate(year, month, day);
	gettime(hour, minute, second);
	
	mysql_query_format("INSERT INTO `"#SQL_PREFIX"%s` (`d_o_c`) VALUES ('%02d:%02d:%02d - %02d/%02d/%02d');", TABLE, hour, minute, second, day, month, year);
		
	new
		lastid = 0;
		
	lastid = mysql_insert_id();

	return lastid;
}

stock SQL_SetInt(dbRowID, const TABLE[], const COLUMN[], INTEGER, &upd_val = RANDOM_NUMBER)
{
    SQL_Checkdb(TABLE, COLUMN, "int(20) NOT NULL default '0'");

	mysql_query_format("UPDATE `"#SQL_PREFIX"%s` SET `%s` = '%i' WHERE `row_id` = '%i' LIMIT 1;", TABLE, COLUMN, INTEGER, dbRowID);

	if(upd_val != RANDOM_NUMBER)	upd_val = RANDOM_NUMBER;

	return 1;
}

stock SQL_SetFloat(dbRowID, const TABLE[], const COLUMN[], Float:FLOAT, &Float:upd_val = RANDOM_FLOAT)
{
    SQL_Checkdb(TABLE, COLUMN, "varchar(50) NOT NULL default '0.0'");

	mysql_query_format("UPDATE `"#SQL_PREFIX"%s` SET `%s` = '%f' WHERE `row_id` = '%i' LIMIT 1;", TABLE, COLUMN, FLOAT, dbRowID);

	if(upd_val != RANDOM_NUMBER)	upd_val = RANDOM_NUMBER;

	return 1;
}

stock SQL_SetString(dbRowID, const TABLE[], const COLUMN[], const STRING[])
{
    SQL_Checkdb(TABLE, COLUMN, "varchar(500) NOT NULL default '-'");
	
	mysql_query_format("UPDATE `"#SQL_PREFIX"%s` SET `%s` = '%s' WHERE `row_id` = '%i' LIMIT 1;", TABLE, COLUMN, STRING, dbRowID);
	
	return 1;
}

stock SQL_GetInt(dbRowID, const TABLE[], const COLUMN[], &myint = RANDOM_NUMBER)
{
	SQL_Checkdb(TABLE, COLUMN, "int(11) NOT NULL default '0'");
	
	new
	    myid = -1,
	    QUERY[1024];

    format(QUERY, 1024, "SELECT `%s` FROM `"#SQL_PREFIX"%s` WHERE `row_id` = '%i' LIMIT 1;", COLUMN, TABLE, dbRowID);

	new
		RESULT = amysql_query(QUERY);

	if(!RESULT)	return mysql_errno();

	mysql_store_result();

	if(mysql_num_rows() >= 1)	myid = mysql_fetch_int();

    mysql_free_result();
    
    myint = myid;

	return myid;
}

stock SQL_GetString(dbRowID, const TABLE[], const COLUMN[])
{
    SQL_Checkdb(TABLE, COLUMN, "varchar(500) NOT NULL default '-'");
    
	new
	    string[1000],
		QUERY[1024];

	format(QUERY, 1024, "SELECT `%s` FROM `"#SQL_PREFIX"%s` WHERE `row_id` = '%i' LIMIT 1;", COLUMN, TABLE, dbRowID);

	new
		RESULT = amysql_query(QUERY);

	if(!RESULT)	{
	
		mysql_errno();
		
		return string;
		
	}
	
	mysql_store_result();

	if(mysql_num_rows() >= 1)
	{
		if(mysql_retrieve_row())
		{
			mysql_fetch_field_row(string, COLUMN);
		}
	}

	mysql_free_result();

	return string;
}

stock Float:SQL_GetFloat(dbRowID, const TABLE[], const COLUMN[], &Float:result = RANDOM_FLOAT)
{
    SQL_Checkdb(TABLE, COLUMN, "varchar(50) NOT NULL default '0.0'");
    
	new
		Float:myfloat = 0.0,
		string[100],
		QUERY[1024];

	format(QUERY, 1024, "SELECT `%s` FROM `"#SQL_PREFIX"%s` WHERE `row_id` = '%i' LIMIT 1;", COLUMN, TABLE, dbRowID);

	new
		RESULT = amysql_query(QUERY);

	if(!RESULT)	{
	
		mysql_errno();
		
		return myfloat;
		
	}

	mysql_store_result();

	if(mysql_num_rows() >= 1)
	{
		if(mysql_retrieve_row())
		{
			mysql_fetch_field_row(string, COLUMN);
			myfloat = floatstr(string);
		}
	}

	mysql_free_result();

	result = myfloat;

	return myfloat;
}

stock streql(const string0[], const string1[])
{
    if(strlen(string0) == strlen(string1) && strcmp(string0, string1, true, strlen(string0)) == 0) return 1;
    return 0;
}

stock md5(forstring[])
{
	new
	    Sendmsg[200];
	format(Sendmsg, sizeof(Sendmsg), "%s", MD5_Hash(forstring));
    for(new i = 0; i < strlen(Sendmsg); i++)
   		Sendmsg[i] = tolower(Sendmsg[i]);
 	return Sendmsg;
}