#include "main.h"

int everythingThread(void *data)
{
	bool quit = false;
	while(!quit)
	{

		switch(op)
		{
			case 

		}


	}

	return 0;
};
int loggingThread(void *data)
{
	
	return 0;
};
int controlsThread(void *data)
{
	
	return 0;
};
int netThread(void *data)
{
	
	return 0;
};
int audioThread(void *data)
{
	
	return 0;
};
int logicThread(void *data)
{
	
	return 0;
};
int cleanupThread(void *data)
{
	
	return 0;
};
int normalizeThread(void *data)
{
	
	return 0;
};
int renderThread(void *data)
{
	
	return 0;
};
int storageThread(void *data)
{
	
	return 0;
};
int main( int argc, char* args[] )
{
	
	sqlite3 *db;
	char *zErrMsg = 0;

	
	DBMemOpen(&db);
	DBClose(db);
	//DBOpen(&db,"master.db");
	//DBClose(db);

	//int execsuccess = sqlite3_exec(db,"SELECT name FROM (SELECT * FROM sqlite_master UNION ALLSELECT * FROM sqlite_temp_master)WHERE type='table'ORDER BY name",NULL,NULL,NULL);
	SQLTable master("master.db","master");
	if((master.GetRecordCount()>3) && (master.GetFieldCount() == 2))
	{
		if(master.Get(0,0).getType()==2)
		{
			if(master.Get(0,1).getType()==1)
			{
				char * magic = master.Get(0,1).getCData();
				if(isEqual(magic,"682"))
				{
					char * engineVer = master.Get(1,1).getCData();
					char * configVer = master.Get(2,1).getCData();

					if(isEqual(engineVer, "00.00.01")
					{
						if(isEqual(isEqual(configVer, "00.00.01")
						{



						}
					}
					delete [] engineVer;
					delete [] configVer;
				}
				delete [] magic;
			}
		}
	}

	char * str = master.GetAllChar();
	std::printf(str);
	/**/
	SDL_Delay(5000);
	//DBClose(db);
	delete [] str;
	return 0;
};