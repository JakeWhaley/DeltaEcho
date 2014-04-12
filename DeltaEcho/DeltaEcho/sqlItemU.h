#ifndef SQLITEMU_H
#define SQLITEMU_H
union sqlItemU
{
	char * str;
	int * integer;
	double * real;
	sqlItemU()
	{
		str=0;
	};
	~sqlItemU()
	{
		if (str)
			delete [] str;
	};
	sqlItemU(int* input)
	{
		integer = 0;
		if(input)
		{
			integer = new int[input[0]];
			//integer[0]=input[0];
			for (int i = 0; i<input[0];i++)
			{
				integer[i]=input[i];
			}
			integer[0];
			integer[1];
		}
		int e = 0;
	};
	sqlItemU(double* input)
	{
		real = 0;
		if(input)
		{
			real = new double[int(input[0])];
			//integer[0]=input[0];
			for (int i = 0; i<input[0];i++)
			{
				real[i]=input[i];
			}
		}
	};
	sqlItemU(char* input)
	{
		str = 0;
		if(input)
		{
			str = new char[input[0]];
			//integer[0]=input[0];
			for (int i = 0; i<input[0];i++)
			{
				str[i]=input[i];
			}
		}
	};
};

#endif