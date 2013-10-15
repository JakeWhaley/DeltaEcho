#include "DatabaseWrappers.h"

void	DBMemOpen(sqlite3** db)				//Creates a new database in RAM
{
	if(DBSMemOpen(db))	//If there was an error opening
	{
		fprintf(stderr, "Can't open database in memory: %s\n", sqlite3_errmsg(*db));
	}
};
int		DBSMemOpen(sqlite3** db)			//Does that, but also reports status
{
	if(sqlite3_open(":memory:", db))
	{
		return 1;
	}
	else
	{
		return 0;
	}
};

void	DBOpen(sqlite3** db,char* filepath)			//Open, or create, a database on disk
{
	if(DBSOpen(db,filepath))	//If there was an error opening
	{
		fprintf(stderr, "Can't open database on disk: %s\n", sqlite3_errmsg(*db));
	}
};
int		DBSOpen(sqlite3** db,char* filepath)		//
{
	if(sqlite3_open(filepath, db))
	{
		return 1;
	}
	else
	{
		return 0;
	}
};

void	DBClose(sqlite3* db)				//Close a database, whether in ram or on disk
{
	if(DBSClose(db))	//If there was an error opening
	{
		fprintf(stderr, "Can't close database: %s\n", sqlite3_errmsg(db));
	}
};
int		DBSClose(sqlite3* db)				//
{
	if(sqlite3_close(db))
	{
		return 1;
	}
	else
	{
		return 0;
	}
};

void	DBCreateTable(sqlite3*,char*);	//Creates a table in said database
int		DBSCreateTable(sqlite3*,char*);	//

void	DBCreateTable(sqlite3*,char*, unsigned long, char**,int*);//Does the above, but also specifies columns to add
int		DBSCreateTable(sqlite3*,char*,unsigned long, char**,int*);//DB, tablename, column count, columns, datatypes

void	DBAlterAdd(sqlite3*,char*,unsigned long, char**,int*);	//Adds columns to a table
int		DBSAlterAdd(sqlite3*,char*,unsigned long, char**,int*);	//DB, tablename, column count, columns, datatypes

void	DBAlterDrop(sqlite3*,char*,unsigned long, char**);	//Drops columns from a table
int		DBSAlterDrop(sqlite3*,char*,unsigned long, char**);	//DB, tablename, column count, columns

void	DBAlterMod(sqlite3*,char*,unsigned long, char**,int);	//Modifies column data type in a table
int		DBSAlterMod(sqlite3*,char*,unsigned long, char**,int);	//DB,table name,column count, column names, datatypes

void	DBSelect(sqlite3*,char**, unsigned long,char**);		//Selects all records from a table
int		DBSSelect(sqlite3*,char**, unsigned long,char**);		//DB, table name, count, columns

void	DBInsert(sqlite3*,char**, unsigned long,char**);		//Inserts records into a table, assuming every column is there
int		DBSInsert(sqlite3*,char**, unsigned long, char**);		//DB, table name,count, records

void	DBInsertS(sqlite3*,char*, unsigned long,unsigned long, char**, char**);	//INSERT records into a table with specifics
int		DBSInsertS(sqlite3*,char*, unsigned long,unsigned long, char**, char**);//DB,Table,Count Columns, count records, columns, data

void	DBDeleteW(sqlite3*,char*, unsigned long, char**, char**, int);	//DELETE records from a table WHERE
int		DBSDeleteW(sqlite3*,char*, unsigned long, char**, char**, int);	//DB,Table,Count Columns, Columns, Where filter, filter type

void	DBUpdateW(sqlite3*,char*, unsigned long, char**, char**,char**,int);	//UPDATE records in a table WHERE
int		DBSUpdateW(sqlite3*,char*, unsigned long, char**, char**,char**,int);	//DB,Table,Count Columns, Columns, Column Data, Where filter, filter type
									
void	DBSelectW(sqlite3*,char* ,unsigned long,char**,char**,int);		//SELECT records from a table WHERE 
int		DBSSelectW(sqlite3*,char* ,unsigned long,char**,char**,int);	//DB,Table,Count Columns, Columns, Where filter, filter type		
