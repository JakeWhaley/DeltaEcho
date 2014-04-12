#ifndef SQLTABLE_H
#define SQLTABLE_H
#include "SQLItem.h"
#include <sqlite3.h>
#include "DatabaseWrappers.h"
#include "CharFunc.h"
class SQLTable
{


private: 
	SQLItem ** data;			//Where we store things for quick access
	char ** fieldNames;			//name of each field available
	unsigned long fieldCount;	//number of fields, and the width of the table
	unsigned long recordCount;	//number of records, and the length of the table
	sqlite3 * workDB;			//a quick memory database for sorting 
	char*	workDBC;			//Path to db in case we need to close and open
	char*	workTable;			//Table we work with in db operations
	bool workDBOn;				//switch saying whether or not we work in db 
								//(affects input time and sort processing time)
								//off->on	n->2n			3n->n   for O(n)=processing
								//(Has no effect on retrieval time for data)

	void EmptyData();			//Delete data
	void LoadData();			//Load from current DB

public:
	SQLTable();					//Create empty table
	SQLTable(char *, char *);	//Create table using DB path and Table inputs
	SQLTable(SQLTable*);		//Create a table from an existing copy
	~SQLTable();				//Clean up the table
	void SetDB(char*,char*);	//Database Path, Table
	char* GetDB();				//Retrieves DB path
	char* GetTable();			//Retrieves table name
	void DBOn();				//Turns worktable processing on
	void DBOff();				//turns it off
	void WorkDBClose();				//closes DB and hits DBOff
	void WorkDBOpen();				//Opens DB
	SQLItem Get(int,int);		//Retrieves item at width,length
	void Set(int,int,SQLItem);	//Sets item at width,length, with data
	int SetS(int,int,SQLItem);	//Sets item & returns success
	void Sort(int,int);			//Request a particular sort based on a field
	int SortS(int,int);			//return sort success
	unsigned long GetRecordCount();	//Return count of records
	unsigned long GetFieldCount();	//Return count of fields
};

#endif