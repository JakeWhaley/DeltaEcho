#include "main.h"

int everythingThread(void *data)
{
	
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
	DBOpen(&db,"master.db");
	//DBClose(db);

	//int execsuccess = sqlite3_exec(db,"SELECT name FROM (SELECT * FROM sqlite_master UNION ALLSELECT * FROM sqlite_temp_master)WHERE type='table'ORDER BY name",NULL,NULL,NULL);
	


	/**/
	SDL_Delay(5000);
	DBClose(db);
	return 0;
};