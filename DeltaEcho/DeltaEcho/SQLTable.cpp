#include "SQLTable.h"


void SQLTable::EmptyData()		//Delete data
{

	for(int i = 0; i < recordCount; i++)
	{
		delete[] (data[i]);
	}
	if(data)
		delete[] data;
	fieldCount = 0;
	recordCount = 0;
};
void SQLTable::LoadData()		//Load from current DB
{
	EmptyData();
	if(!workDB)
		WorkDBOpen();
	char* err=0;
	char* msg=0;
	static sqlite3_stmt *statement;

	recordCount= DBGetRecordCount(workDB,workTable);
	fieldCount= DBGetFieldCount(workDB,workTable);
	data = new SQLItem*[recordCount];
	setEqual(&msg,"SELECT * FROM ");
	conc(&msg,workTable);
	conc(&msg, ';');


	if(sqlite3_prepare_v2(workDB,msg,-1,&statement,NULL)==SQLITE_OK)
	{	
		unsigned long recNumber = 0;
		while(sqlite3_step(statement) == SQLITE_ROW)
		{
			data[recNumber] = new SQLItem[fieldCount];
			for(unsigned long i = 0; i<fieldCount; i++)
			{
				long tempI[] = {0,0};
				double tempD[] = {0,0};
				char * tempC =0;
				switch(sqlite3_column_type(statement,i))
				{
				case SQLITE_INTEGER:
					tempI[0]=2;
					tempI[1]=sqlite3_column_int(statement,i);
					data[recNumber][i].set(tempI,2);
					break;
				case SQLITE_FLOAT:
					tempD[0]=2;
					tempD[1]=sqlite3_column_double(statement,i);
					data[recNumber][i].set(tempD,3);
					break;
				case SQLITE_TEXT:
					setEqual(&tempC,(const char*)(sqlite3_column_text(statement,i)));
					data[recNumber][i].set(tempC,1);
					break;
				case SQLITE_BLOB:
					setEqual(&tempC,(signed)sqlite3_column_text(statement,i));
					data[recNumber][i].set(tempC,1);
					break;
				default:
					setEqual(&tempC,(signed) sqlite3_column_text(statement,i));
					data[recNumber][i].set(tempC,1);
					break;
				if (tempC)
					delete[] tempC;
				};
			//recNumber++;
			}
			recNumber++;
		}
	}


};

SQLTable::SQLTable()					//Create empty table
{
	data = 0;
	fieldCount = 0;
	recordCount = 0;
	fieldNames = 0;
	workDBC = 0;
	workTable=0;
	workDB=0;
	EmptyData();
};

SQLTable::SQLTable(char * inDB, char * inTab)		//Create table using an existing db
{
	data = 0;
	fieldCount = 0;
	recordCount = 0;
	fieldNames = 0;
	workDBC = 0;
	workTable=0;
	workDB=0;
	SetDB(inDB,inTab);
};

SQLTable::SQLTable(SQLTable* input)		//Create a table from an existing copy
{
	data = 0;
	fieldCount = 0;
	recordCount = 0;
	fieldNames = 0;
	workDBC = 0;
	workTable=0;
	workDB=0;
	workDBC=input->GetDB();
	workTable=input->GetTable();
	LoadData();
};

SQLTable::~SQLTable()				//Clean up the table
{
	EmptyData();
};

void SQLTable::SetDB(char* inDB,char* inTab)	//DB path, table
{
	EmptyData();
	setEqual(&workDBC,inDB);
	setEqual(&workTable,inTab);
	LoadData();
};

char* SQLTable::GetDB()			//Retrieves the database
{
	char * out;
	setEqual(&out,workDBC);
	return out;
};

char* SQLTable::GetTable()			//Retrieves table name
{
	char * out;
	setEqual(&out,workTable);
	return out;
};

void SQLTable::DBOn()				//Turns worktable processing on
{
	if(!workDB)
		WorkDBOpen();
	workDBOn = true;
};

void SQLTable::DBOff()				//turns it off
{
	workDBOn = false;
};

void SQLTable::WorkDBClose()				//closes DB and hits DBOff
{
	DBOff();
	if(workDB)
		DBClose(workDB);
};

void SQLTable::WorkDBOpen()				//Opens DB
{
	if(!workDB)
		DBOpen(&workDB,workDBC);
};

SQLItem SQLTable::Get(int inRec,int inField)		//Retrieves item at width,length
{
	if(recordCount>inRec && inRec > -1 && fieldCount > inField && inField > -1)
	{
		SQLItem out;
		out.set(&(data[inRec][inField]));
		return out;
	}
	else
	{
		throw "SQLTABLEGETOUTOFBOUNDS";
		return (SQLItem)(long)0;
	}
};

void SQLTable::Set(int inRec,int inField,SQLItem inItem)	//Sets item at width,length, with data
{
	if(workDBOn)
	{
		//DBUpdateW(workDB,workTable,fieldCount,,data[inRec][inField],data[inRec],{0}
	}
	else
		data[inRec][inField].set(&inItem);
};

int SQLTable::SetS(int inRec,int inField,SQLItem inItem)	//Sets item & returns success
{
	try
	{
		Set(inRec,inField,inItem);
	}
	catch(const char * e)
	{
		//fprintf(stderr, "Can't open database in memory: %s\n", sqlite3_errmsg(*db));
		fprintf(stderr, e);
		fprintf(stderr, "(%i,%i,%i,%i)",inRec,inField,recordCount,fieldCount);
		return 1;
	}
	return 0;
};

void SQLTable::Sort(int,int)			//Request a particular sort based on a field
{

};

int SQLTable::SortS(int,int)			//return sort success
{
	return 0;
};

char * SQLTable::GetAllChar()
{
	char * str =0;
	setEqual(&str,'\0');
	for (int i = 0; i < recordCount; i++)
	{
		for(int ii = 0; ii < fieldCount; ii++)
		{
			int intbetween;
			char * blah = 0;
			long * bluh = 0;
			double * blag=0;
			switch(data[i][ii].getType())
			{
			case 0:
				
				break;
			case 1:
				blah = data[i][ii].getCData();
				conc(&str,blah);
				
				break;
			case 2:
				bluh = data[i][ii].getIData();
				intbetween = bluh[1];
				blah = new char[10];
				itoa(intbetween,blah,10);
				conc(&str,blah);
				
				
				break;
			case 3:
				blag = data[i][ii].getDData();
				blah =ftoa(blag[1]);
				conc(&str,blah);
				break;
			};
			if(blah)
				delete [] blah;
			if(bluh)
				delete [] bluh;
			if(blag)
				delete [] blag;
			conc(&str,'\t');
		}
		conc(&str,'\n');
	}
	return str;
};
unsigned long SQLTable::GetRecordCount()	//Return count of records
{
	return recordCount;
};
unsigned long SQLTable::GetFieldCount()	//Return count of fields
{
	return fieldCount;
};