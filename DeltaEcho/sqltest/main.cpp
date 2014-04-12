#include <iostream>
#include <sqlite3.h>
#include "../DeltaEcho/CharFunc.h"
#include "../DeltaEcho/DatabaseWrappers.h"
#include "../DeltaEcho/SQLTable.h"
#include "../DeltaEcho/SQLItem.h"
using namespace std;
void main()
{
	
	SQLTable taby("dooleydoo.sqlite3","tablename");
	int i = 5;
	SQLItem blah;
	blah.set(taby.Get(0,1));
	char * bluh = blah.getCData();
	cout << bluh ;//<<(taby.Get(0,1)).getIData()<<(taby.Get(1,0)).getIData()<<(taby.Get(1,0)).getIData();
	i=0;
};