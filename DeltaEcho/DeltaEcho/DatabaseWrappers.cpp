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

void	DBCreateTable(sqlite3* db,char* table, unsigned long columncount, char** columns, int* datatypes)//Does the above, but also specifies columns to add
{
	int returnVal = DBSCreateTable(db,table,columncount,columns, datatypes);
	switch (returnVal)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	};
};
int		DBSCreateTable(sqlite3* db,char* table, unsigned long columncount, char** columns, int* datatypes)//DB, tablename, column count, columns, datatypes
{
	char* err;
	char* msg;
	
	setEqual(&msg,"CREATE TABLE ");
	conc(&msg,table);
	conc(&msg," ( ");
	for (int i = 0; i < columncount; i++)
	{
		conc(&msg,columns[i]);
		
		switch(datatypes[i])
		{
		case sqlString:		//String
			conc(&msg," TEXT "); 
			break;
		case sqlDouble:		//Double
			conc(&msg," REAL "); 
			break;
		case sqlLong:		//Long
			conc(&msg," INTEGER "); 
			break;
		case sqlDecimal:		//Super Floating Point
			conc(&msg," NUMERIC "); 
			break;
		case sqlBlob:
			conc(&msg," NONE "); 
			break;

		};

		if(i!=(columncount-1))
			conc(&msg,',');
	}

	conc(&msg, " );");

	int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	switch(execsuccess)
	{
	case 0:		//No Error
		return 0;
	default:	//We got an error
		sqlite3_free(err);
		return execsuccess;	
	}



};

void	DBAlterAdd(sqlite3*,char*,unsigned long, char**,int*);	//Adds columns to a table
int		DBSAlterAdd(sqlite3*,char*,unsigned long, char**,int*);	//DB, tablename, column count, columns, datatypes

void	DBAlterDrop(sqlite3*,char*,unsigned long, char**);	//Drops columns from a table
int		DBSAlterDrop(sqlite3*,char*,unsigned long, char**);	//DB, tablename, column count, columns

void	DBAlterMod(sqlite3*,char*,unsigned long, char**,int);	//Modifies column data type in a table
int		DBSAlterMod(sqlite3*,char*,unsigned long, char**,int);	//DB,table name,column count, column names, datatypes

/*
void	DBSelect(sqlite3* db,char* table, unsigned long columncount,char**columns)		//Selects all records from a table
{
	int returnVal = DBSSelect(db,table,columncount,columns);
	switch (returnVal)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	};
};
int		DBSSelect(sqlite3* db,char* table, unsigned long columncount,char** columns)		//DB, table name, count, columns
{
	char* err;
	char* msg;
	
	setEqual(&msg,"SELECT ");
	for (int i = 0; i < columncount; i++)
	{
		conc(&msg,columns[i]);
		if(i!=(columncount-1))
			conc(&msg,',');
	}

	conc(&msg, " FROM ");
	conc(&msg, table);

	conc(&msg, ';');
	//int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	//switch(execsuccess)
	{
	//case 0:		//No Error
		return 0;
	//default:	//We got an error
		//sqlite3_free(err);
		//return execsuccess;	
	}



};
*/
void	DBInsert(sqlite3* db,char* table, unsigned long recordcount, char** data)		//Inserts records into a table, assuming every column is there
{
	int returnVal = DBSInsert(db,table,recordcount,data);
	switch (returnVal)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	};
};
int		DBSInsert(sqlite3* db,char* table, unsigned long recordcount, char** data)		//DB, table name,count, records
{
	char* err;
	char* msg;


	unsigned long columncount = DBGetRecordCount(db,table);

	
	setEqual(&msg,"INSERT INTO ");
	conc(&msg, table);
	conc(&msg, " VALUES (");

for(int i = 0; i < (recordcount); i++)
	{

		for(int ii = 0; ii < columncount; ii++)
		{
			conc(&msg,data[((i*columncount)+(ii))]);
			if(ii<(columncount-1))
				conc(&msg,',');
		}
		
		if(i<(recordcount-1))
			conc(&msg,"),(");
		else conc(&msg,");");
	}

	int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	switch(execsuccess)
	{
	case 0:		//No Error
		return 0;
	default:	//We got an error
		sqlite3_free(err);
		return execsuccess;	
	}
};



void	DBInsertS(sqlite3* db,char* table, unsigned long columncount,unsigned long recordcount, char** columns, char** data)	//INSERT records into a table with specifics
{
	int returnVal = DBSInsertS(db,table, columncount, recordcount, columns, data);
	switch (returnVal)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	};
};
int		DBSInsertS(sqlite3* db,char* table, unsigned long columncount,unsigned long recordcount, char** columns, char** data)//DB,Table,Count Columns, count records, columns, data
{
	char* err;
	char* msg;
	
	setEqual(&msg,"INSERT INTO ");
	conc(&msg, table);
	conc(&msg, " (");
	
	for(int i = 0; i < columncount;i++)
	{
		conc(&msg, columns[i]);
		if(i < (columncount-1))
			conc(&msg, ',');
	}

	conc(&msg, ") VALUES (");

	for(int i = 0; i < (recordcount); i++)
	{

		for(int ii = 0; ii < columncount; ii++)
		{
			conc(&msg,data[((i*columncount)+(ii))]);
			if(ii<(columncount-1))
				conc(&msg,',');
		}
		
		if(i<(recordcount-1))
			conc(&msg,"),(");
		else conc(&msg,");");
	}

	int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	switch(execsuccess)
	{
	case 0:		//No Error
		return 0;
	default:	//We got an error
		sqlite3_free(err);
		return execsuccess;	
	}

};


void	DBDeleteW(sqlite3* db,char* table, unsigned long columncount, char** columns, char** wheredata, int* filtertype)	//DELETE records from a table WHERE
{
	int returnVal = DBSDeleteW(db,table, columncount,columns,wheredata,filtertype);
	switch (returnVal)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	};
};
int		DBSDeleteW(sqlite3* db,char* table, unsigned long columncount, char** columns, char** wheredata, int* filtertype)	//DB,Table,Count Columns, Columns, Where filter, filter type
{
	char* err;
	char* msg;
	
	setEqual(&msg,"DELETE FROM");
	conc(&msg, table);
	conc(&msg, " WHERE ");

	bool startAnd = false;
	for(int i = 0; i < columncount; i++)
	{
		switch (filtertype[i])
		{
			case 0:		//No Filtering
				break;
			case 1:		//Exact Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " = ");
				conc(&msg, wheredata[i]);
				startAnd = true;
				break;
			case 2:		//Minimum Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " < ");
				conc(&msg, wheredata[i]);
				startAnd = true;
				break;
			case 3:		//Maximum Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " > ");
				conc(&msg, wheredata[i]);
				startAnd = true;
				break;
			case 4:		//Not Equal
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " != ");
				conc(&msg, wheredata[i]);
				startAnd = true;
				break;
		}
	}
	conc(&msg, ';');
	int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	switch(execsuccess)
	{
	case 0:		//No Error
		return 0;
	default:	//We got an error
		sqlite3_free(err);
		return execsuccess;	
	}



}

void	DBUpdateW(sqlite3* db,char* table, unsigned long columncount, char** columns, char** updatedata,char** wheredata,int* filtertype )	//UPDATE records in a table WHERE
{
	int returnVal = DBSUpdateW(db,table,columncount,columns,updatedata,wheredata,filtertype);
	switch (returnVal)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	};
};
int		DBSUpdateW(sqlite3* db,char* table, unsigned long columncount, char** columns, char** updatedata,char** wheredata,int* filtertype )	//DB,Table,Count Columns, Columns, Column Data, Where filter, filter type
{
	char* err;
	char* msg;
	
	setEqual(&msg,"UPDATE ");
	conc(&msg, table);
	conc(&msg, " SET ");
	for (int i = 0; i < columncount; i++)
	{
		conc(&msg,columns[i]);
		conc(&msg,'=');
		conc(&msg,updatedata[i]);
		if(i!=(columncount-1))
			conc(&msg,',');
	}
	conc(&msg, " WHERE ");

	bool startAnd = false;
	for(int i = 0; i < columncount; i++)
	{
		switch (filtertype[i])
		{
			case 0:		//No Filtering
				break;
			case 1:		//Exact Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " = ");
				conc(&msg, wheredata[i]);
				startAnd = true;
				break;
			case 2:		//Minimum Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " < ");
				conc(&msg, wheredata[i]);
				startAnd = true;
				break;
			case 3:		//Maximum Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " > ");
				conc(&msg, wheredata[i]);
				startAnd = true;
				break;
			case 4:		//Not Equal
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " != ");
				conc(&msg, wheredata[i]);
				startAnd = true;
				break;
		}
	}
	conc(&msg, ';');
	int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	switch(execsuccess)
	{
	case 0:		//No Error
		return 0;
	default:	//We got an error
		sqlite3_free(err);
		return execsuccess;	
	}



};


/*
void	DBSelectW(sqlite3* db,char* table,unsigned long columncount,char** columns,char** values,int* filtertype)		//SELECT records from a table WHERE 
{
	int returnVal = DBSSelectW(db,table,columncount,columns,values,filtertype);
	switch (returnVal)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	};
};
int		DBSSelectW(sqlite3* db,char* table,unsigned long columncount,char** columns,char** values,int* filtertype)	//DB,Table,Count Columns, Columns, Where filter, filter type		
{
	char* err;
	char* msg;
	
	setEqual(&msg,"SELECT ");
	for (int i = 0; i < columncount; i++)
	{
		conc(&msg,columns[i]);
		if(i!=(columncount-1))
			conc(&msg,',');
	}

	conc(&msg, " FROM ");
	conc(&msg, table);
	conc(&msg, " WHERE ");

	bool startAnd = false;
	for(int i = 0; i < columncount; i++)
	{
		switch (filtertype[i])
		{
			case 0:		//No Filtering
				break;
			case 1:		//Exact Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " = ");
				conc(&msg, values[i]);
				startAnd = true;
				break;
			case 2:		//Minimum Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " < ");
				conc(&msg, values[i]);
				startAnd = true;
				break;
			case 3:		//Maximum Filtering
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " > ");
				conc(&msg, values[i]);
				startAnd = true;
				break;
			case 4:		//Not Equal
				if(startAnd)
					conc(&msg, " AND ");
				conc(&msg, columns[i]);
				conc(&msg, " != ");
				conc(&msg, values[i]);
				startAnd = true;
				break;
		}
	}
	conc(&msg, ';');
	//int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	//switch(execsuccess)
	{
	//case 0:		//No Error
		return 0;
	//default:	//We got an error
		//sqlite3_free(err);
		//return execsuccess;	
	}



};
*/
unsigned long DBGetRecordCount(sqlite3* db,char* table)
{
	char* err =0;
	char* msg =0;
	sqlite3_stmt *statement;

	setEqual(&msg,"SELECT * FROM ");
	conc(&msg,table);
	conc(&msg," ; ");

	//int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	if(sqlite3_prepare_v2(db,msg,-1,&statement,NULL)==SQLITE_OK)
	{
		sqlite3_step(statement);
		int result = sqlite3_data_count(statement);
		if(sqlite3_finalize(statement)==SQLITE_OK)
			if(result>-1)
				return result;
	}
	return 0;


};

unsigned long DBGetFieldCount(sqlite3* db,char* table)
{
	char* err =0;
	char* msg =0;
	static sqlite3_stmt *statement;

	setEqual(&msg,"SELECT * FROM ");
	conc(&msg,table);
	conc(&msg," ; ");

	//int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	if(sqlite3_prepare_v2(db,msg,-1,&statement,NULL)==SQLITE_OK)
	{
		sqlite3_step(statement);
		int result = sqlite3_column_count(statement);
		if(sqlite3_finalize(statement)==SQLITE_OK)
			if(result>-1)
				return result;
	}
	return 0;

};

int DBGetDataTypes(sqlite3* db, char* table)
{
	char* err =0;
	char* msg =0;

	setEqual(&msg," SELECT * FROM ");
	conc(&msg,table);
	conc(&msg," ; ");


	int execsuccess = sqlite3_exec(db,msg,NULL,NULL,&err);
	switch(execsuccess)
	{
	case 0:		//No Error
		return 0;
	default:	//We got an error
		sqlite3_free(err);
		return execsuccess;	
	}
}