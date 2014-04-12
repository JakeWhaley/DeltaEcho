#ifndef DATABASEWRAPPERS_H
#define DATABASEWRAPPERS_H
#include <stdio.h>
#include <sqlite3.h>
#include "CharFunc.h"

//Datatypes:
enum sqlDatalTypes {sqlString,sqlDouble,sqlLong,sqlDecimal,sqlSuperLong,sqlBlob };



void	DBMemOpen(sqlite3**);			//Creates a new database in RAM
int		DBSMemOpen(sqlite3**);			//Does that, but also reports status

void	DBOpen(sqlite3**,char*);			//Open, or create, a database on disk
int		DBSOpen(sqlite3**,char*);		//

void	DBClose(sqlite3*);				//Close a database, whether in ram or on disk
int		DBSClose(sqlite3*);				//

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

//void	DBSelect(sqlite3*,char*, unsigned long,char**);		//Selects all records from a table
//int		DBSSelect(sqlite3*,char*, unsigned long,char**);		//DB, table name, count, columns

void	DBInsert(sqlite3*,char*, unsigned long,char**);		//Inserts records into a table, assuming every column is there
int		DBSInsert(sqlite3*,char*, unsigned long, char**);		//DB, table name,count, records

void	DBInsertS(sqlite3*,char*, unsigned long,unsigned long, char**, char**);	//INSERT records into a table with specifics
int		DBSInsertS(sqlite3*,char*, unsigned long,unsigned long, char**, char**);//DB,Table,Count Columns, count records, columns, data

void	DBDeleteW(sqlite3*,char*, unsigned long, char**, char**, int*);		//DELETE records from a table WHERE
int		DBSDeleteW(sqlite3*,char*, unsigned long, char**, char**, int*);	//DB,Table,Count Columns, Columns, Where filter, filter type

void	DBUpdateW(sqlite3*,char*, unsigned long, char**, char**,char**,int*);	//UPDATE records in a table WHERE
int		DBSUpdateW(sqlite3*,char*, unsigned long, char**, char**,char**,int*);	//DB,Table,Count Columns, Columns, Column Data, Where filter, filter type
									
//void	DBSelectW(sqlite3*,char* ,unsigned long,char**,char**,int*);	//SELECT records from a table WHERE 
//int		DBSSelectW(sqlite3*,char* ,unsigned long,char**,char**,int*);	//DB,Table,Count Columns, Columns, Where filter, filter type		

unsigned long DBGetRecordCount(sqlite3*,char*);							//SELECT count(*) in table
																		//DB, Table

unsigned long DBGetFieldCount(sqlite3*,char*);							//find count of possible fields in table
																		//DB, Table


#endif