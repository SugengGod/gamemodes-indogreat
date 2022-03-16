#if defined _JBDB_included
	#endinput
#endif
#define _JBDB_included

#include <a_samp>
#include <a_sampdb>
#include <dutils>

#define JBDB:: \
	JBDB_

static DB: JBDB::Database;

JBDB::Init (db [] = "JunkBuster/JunkBuster.db")
{
	if (!fexist (db))
	{
	    new File: f = fopen (db, io_append);
		fclose (f);
		
	    if (!(JBDB::Database = db_open (db)))
	        return 0;
	        
		db_query (JBDB::Database, "CREATE TABLE JBUsers (User TEXT PRIMARY KEY, IP TEXT, Banned BOOLEAN, UnbanTime INTEGER, Whitelisted BOOLEAN)");
		return 1;
	}
	return ((JBDB::Database = db_open (db)) != DB: 0);
}

JBDB::Exit ()
{
	return (JBDB::Database != DB: 0 && db_close (JBDB::Database));
}

stock bool: JBDB::GetUser (user [])
{
    if (user [0] && JBDB::Database)
	{
	    new
			query [64] = "SELECT * FROM `JBUsers` WHERE `User` = '",
			DBResult: dbresult;

	    strcat (query, user);
	    strcat (query, "'");
	    dbresult = db_query (JBDB::Database, query);
		if (db_num_rows (dbresult) > 0)
		{
		    db_free_result (dbresult);
		    return true;
		}
		db_free_result (dbresult);
	}
	return false;
}

//==============================================================================

stock JBDB::GetUserData (user [], &bool: banned, &unbantime, &bool: whitelisted, ip [], ipsize = sizeof (ip))
{
    if (user [0] && JBDB::Database)
    {
		new
		    query [128] = "SELECT `IP`, `Banned`, `UnbanTime`, `Whitelisted` FROM `JBUsers` WHERE `User` = '",
		    DBResult: dbresult,
		    result [64];
		    
		strcat (query, user);
		strcat (query, "'");
		dbresult = db_query (JBDB::Database, query);
		if (db_num_rows (dbresult) > 0)
		{
		    db_get_field (dbresult, 0, ip, ipsize);
			db_get_field (dbresult, 1, result, sizeof (result));
			banned = (strval (result) != 0);
			db_get_field (dbresult, 2, result, sizeof (result));
			unbantime = strval (result);
			db_get_field (dbresult, 3, result, sizeof (result));
			whitelisted = (strval (result) != 0);
		    db_free_result (dbresult);
		    return 1;
		}
		db_free_result (dbresult);
	}
	return 0;
}

stock JBDB::UpdateUserData (user [], ip [], bool: banned, unbantime, bool: whitelisted)
{
    if (user [0] && JBDB::Database)
    {
		new query [128];

		if (!JBDB::GetUser (user))
			format (query, sizeof (query), "INSERT INTO JBUsers (`User`, `IP`, `Banned`, `UnbanTime`, `Whitelisted`) VALUES ('%s', '%s', %d, %d, %d)", user, ip, _: banned, unbantime, _: whitelisted);
		else
		    format (query, sizeof (query), "UPDATE `JBUsers` SET `IP` = '%s', `Banned` = %d, `UnbanTime` = %d, `Whitelisted` = %d WHERE `User` = '%s'", ip, _: banned, unbantime, _: whitelisted, user);
		db_free_result (db_query (JBDB::Database, query));
		return 1;
    }
    return 0;
}

stock bool: JBDB::IsBanned (user [], ip []) // Check for IP and name.
{
	new
	    query [128],
	    DBResult: dbresult,
	    result [8];
	    
	format (query, sizeof (query), "SELECT `Banned` FROM `JBUsers` WHERE `IP` = '%s' OR `User` = '%s'", ip, user);
	dbresult = db_query (JBDB::Database, query);
	for (new i = 0, numrows = db_num_rows (dbresult); i < numrows; ++i, db_next_row (dbresult))
	{
		db_get_field (dbresult, 0, result, sizeof (result));
		if (strval (result))
		{
		    db_free_result (dbresult);
		    return true;
		}
	}
	db_free_result (dbresult);
	return false;
}

stock JBDB::UnbanIp (ip [])
{
	if (ip [0] && JBDB::Database)
	{
	    new
			query [128] = "UPDATE `JBUsers` SET `Banned` = 0, `UnbanTime`= 0 WHERE `IP` = '";
	    
	    strcat (query, ip);
	    strcat (query, "'");
	    return db_free_result (db_query (JBDB::Database, query));
	}
	return 0;
}

stock JBDB::SetWhitelisted (user [], ip [], bool: whitelisted)
{
    if (user [0] && JBDB::Database)
    {
		new query [128];

		if (!JBDB::GetUser (user))
			format (query, sizeof (query), "INSERT INTO JBUsers (`User`, `IP`, `Banned`, `UnbanTime`, `Whitelisted`) VALUES ('%s', '%s', 0, 0, %d)", user, ip, _: whitelisted);
		else
		    format (query, sizeof (query), "UPDATE `JBUsers` SET `IP` = '%s', `Whitelisted` = %d WHERE `User` = '%s'", ip, _: whitelisted, user);
		return db_free_result (db_query (JBDB::Database, query));
    }
    return 0;
}

stock bool: JBDB::IsWhitelisted (user [])
{
	if (user [0] && JBDB::Database)
	{
	    new
			query [64] = "SELECT `Whitelisted` FROM `JBUsers` WHERE `User` = '",
			DBResult: dbresult,
			result [16];

	    strcat (query, user);
	    strcat (query, "'");
	    dbresult = db_query (JBDB::Database, query);
		if (db_num_rows (dbresult) > 0)
		{
		    db_get_field (dbresult, 0, result, sizeof (result));
		    db_free_result (dbresult);
		    return (strval (result) != 0);
		}
		db_free_result (dbresult);
	}
	return false;
}
