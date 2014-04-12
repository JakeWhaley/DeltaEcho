#include "SQLItem.h"

void SQLItem::zeroOut()
{
	integer = 0;
	real = 0;
	text = 0;
	type = 0;
};
SQLItem::SQLItem()
{
	zeroOut();
};
SQLItem::SQLItem(long init)
{
	zeroOut();
	set(init);
};
SQLItem::SQLItem(double init)
{
	zeroOut();
	set(init);
};
SQLItem::SQLItem(char* init)
{
	zeroOut();
	set(init);
};
SQLItem::SQLItem(long* input,int inType)
{
	zeroOut();
	set(input,inType);
};
SQLItem::SQLItem(double* input,int inType)
{
	zeroOut();
	set(input,inType);
};
SQLItem::SQLItem(char* input,int inType)
{
	zeroOut();
	set(input,inType);
};
SQLItem::SQLItem(long* input)
{
	zeroOut();
	set(input);
};
SQLItem::SQLItem(double* input)
{
	zeroOut();
	set(input);
};	
SQLItem::SQLItem(SQLItem * other)
{
	zeroOut();
	set(other);
};
SQLItem::SQLItem(SQLItem & other)
{
	zeroOut();
	set(&other);
};
/*
void SQLItem::set(sqlItemU input)
{
	if(type)
	{
		if(type==1)
			delete[] text;
		else if(type==2)
			delete[] integer;
		else if(type==3)
			delete[] real;

	}
		//delete data(type);
	type = 1;
	if(type==1)
	{
		text = 0;
		if(input)
		{
			str = new char[input[0]];
			//integer[0]=input[0];
			for (int i = 0; i<input[0];i++)
			{
				str[i]=input[i];
			}
	}
	else if(type==2)
		data = new sqlItemU(input.integer);
	else if(type==3)
		data = new sqlItemU(input.real);
};
*/
void SQLItem::set(SQLItem* input)
{
	empty();
	type = input->getType();
	switch (type)
	{
	case 0:	
		break;
	case 1:	
		text = input->getCData();
		break;
	case 2:
		integer = input->getIData();
		break;
	case 3:
		real = input->getDData();
		break;
	};
};	
void SQLItem::set(SQLItem input)
{
	empty();
	type = input.getType();
	switch (type)
	{
	case 0:	
		break;
	case 1:	
		text = input.getCData();
		break;
	case 2:
		integer = input.getIData();
		break;
	case 3:
		real = input.getDData();
		break;
	};
};	
void SQLItem::set(char* inCha, int inType)
{
	empty();
	setEqual(&text,inCha);
	type = inType;
};
void SQLItem::set(long* inInt, int inType)
{
	empty();
	if(inInt)
	{
		if(inInt[0]>=2)
		{
			type = inType;
			integer = new long[inInt[0]];
			for(int i = 0; i < inInt[0];i++)
			{
				integer[i]=inInt[i];
			}
		}
	}
};
void SQLItem::set(double* inReal, int inType)
{
	empty();
	if(inReal)
	{
		if(inReal[0]>=2)
		{
			type = inType;
			real = new double[inReal[0]];
			for(int i = 0; i < inReal[0];i++)
			{
				real[i]=inReal[i];
			}
		}
	}
};
void SQLItem::set(char* inCha)
{
	set(inCha,1);
};
void SQLItem::set(double inDouble)
{
	double dubs[2];
	dubs[0]=2;
	dubs[1]=inDouble;
	set(dubs,3);
};
void SQLItem::set(long inLong)
{
	long longs[2];
	longs[0]=2;
	longs[1]= inLong;
	set(longs,2);
};
void SQLItem::set(long* inLong)
{
	set(inLong,2);
};
void SQLItem::set(double* inDoub)
{
	set(inDoub,3);
};
void SQLItem::empty()
{
	if(text)
	{
		delete [] text;
	}
	if(real)
	{
		delete [] real;
	}
	if(integer)
	{
		delete [] integer;
	}
	type = 0;
};
double* SQLItem::getDData()
{
	double * outReal =0;
	if(real)
	{
		outReal = new double[(int)real[0]];
		for (int i = 0; i<(int)real[0];i++)
		{
			outReal[i]=real[i];
		}
	}
	return outReal;
};	
long*	SQLItem::getIData()
{
	long * outInt =0;
	if(integer)
	{
		outInt = new long[integer[0]];
		for (int i = 0; i<integer[0];i++)
		{
			outInt[i]=integer[i];
		}
		}
	return outInt;
};	
char*	SQLItem::getCData()
{
	char * str =0;
	if(text)
		setEqual(&str, text);
	return str;
};	
int		SQLItem::getType()
{
	return type;
};
SQLItem::~SQLItem()
{
	empty();
};