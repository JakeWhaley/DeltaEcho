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

	if(sqlite3_open("master.db", &db)){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}else{
		fprintf(stderr, "Opened database successfully\n");
	}
	sqlite3_close(db);
	SDL_Delay(5000);

	return 0;
};