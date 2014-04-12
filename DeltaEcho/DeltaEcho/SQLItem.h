#ifndef SQLITEM_H
#define SQLITEM_H
//#include "sqlItemU.h"
#include "CharFunc.h"
class SQLItem
{
	//Type 1 is char
	//Type 2 is long
	//Type 3 is double


private: //sqlItemU * data;
	int type;
	long * integer;
	double * real;
	char *	text;
	void zeroOut();
public:
	SQLItem();
	SQLItem(long);
	SQLItem(double);
	SQLItem(long*,int);
	SQLItem(double*,int);
	SQLItem(char*,int);
	SQLItem(long*);
	SQLItem(double*);
	SQLItem(char*);
	//SQLItem(sqlItemU);
	SQLItem(SQLItem*);
	SQLItem(SQLItem&);
	~SQLItem();
	//void set(sqlItemU,int);
	void set(char*, int);
	void set(long*, int);
	void set(double*, int);
	void set(char*);
	void set(double);
	void set(long);
	void set(long*);
	void set(double*);
	void empty();
	void set(SQLItem*);
	void set(SQLItem);
	double* getDData();
	long*	getIData();
	char*	getCData();
	int		getType();
};

#endif