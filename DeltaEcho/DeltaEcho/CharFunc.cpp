#include "CharFunc.h"

void concatenate(char ** storage,char * addon)
{
	//addon = const_cast <char*> (addon);
	if (*storage == 0)
	{
		*storage = new char;
		**storage = '\0';
	}
								//Assemble ingredients
	char * workingChar;					//The cooking bowl
	unsigned long storageLength, addonLength,fullLength;

								//Prepare
	storageLength = (findLength(*storage)-1);	//Compensate for loss of terminator
	addonLength = findLength(addon);
	fullLength = (storageLength+addonLength);
	workingChar = new char[fullLength];	//Working memory
	if((storageLength+addonLength)==24)
		workingChar;

								//Mix it all in the mixing bowl
	for (unsigned long i = 0;i<storageLength;i++)		//Give me the original text
	{
		workingChar[i] = (*storage)[i];			
	}

	//if(storageLength
	//storageLength++;							//Compensate for Loop

	for (unsigned long i = 0;i<addonLength;i++)			//Now give me what you want to add
	{
		workingChar[storageLength+i] = addon[i];
	}

								//Clean Up and Serve
	delete[] *storage;							//Free up that memory
	*storage = workingChar;						//And take this memory
};

void conc(char ** storage,char * addon)
{
	concatenate(storage,addon);	//See above
};

void concatenate(char ** storage,char addon)
{
	if (*storage == 0)
	{
		*storage = new char;
		**storage = '\0';
	}
								//Assemble ingredients
	char * workingChar;					//The cooking bowl
	unsigned long storageLength;

								//Prepare
	storageLength = findLength(*storage) -1;	
	workingChar = new char[(storageLength+2)];	//Working memory

								//Mix it all in the mixing bowl
	for (unsigned long i = 0;i<storageLength;i++)		//Give me the original text
	{
		workingChar[i] = (*storage)[i];			
	}

		workingChar[storageLength] = addon;
		workingChar[storageLength+1] = '\0';

								//Clean Up and Serve
	delete[] *storage;							//Free up that memory
	*storage = workingChar;						//And take this memory
};

void conc(char ** storage,char addon)
{
	concatenate(storage,addon);	//See above
};

void concatenate(char ** storage, const char addon[])
{
	if (*storage == 0)
	{
		*storage = new char;
		**storage = '\0';
	}


								//Assemble ingredients
	char * workingChar;					//The cooking bowl
	unsigned long storageLength, addonLength;

								//Prepare
	storageLength = (findLength(*storage)-1);	//Compensate for loss of terminator
	addonLength = findLength(addon);
	workingChar = new char[(storageLength+addonLength)];	//Working memory

								//Mix it all in the mixing bowl
	for (unsigned long i = 0;i<storageLength;i++)		//Give me the original text
	{
		workingChar[i] = (*storage)[i];			
	}

	//storageLength++;							//Compensate for Loop

	for (unsigned long i = 0;i<addonLength;i++)			//Now give me what you want to add
	{
		workingChar[storageLength+i] = (addon)[i];
	}

								//Clean Up and Serve
	delete[] *storage;							//Free up that memory
	*storage = workingChar;						//And take this memory
};

void conc(char ** storage, const char addon[])
{
	concatenate(storage,addon);
};

void setEqual(char ** storage,char * replacement)
{
	if (*storage == 0)
	{
		unsigned long replacementLength = findLength(replacement);
		*storage = new char[replacementLength];
		for (unsigned long i = 0; i < replacementLength;i++)
			(*storage)[i] = replacement[i];
	} else
	{
									//Assemble Ingredients
		unsigned long storageLength = findLength(storage);
		unsigned long replacementLength = findLength(replacement);
									//Mix it up
		if (storageLength == replacementLength)
		{
			for (unsigned long i = 0; i < storageLength;i++)
				(*storage)[i] = replacement[i];
		} else
		{
			delete [] *storage;
			*storage = new char[replacementLength];
			for (unsigned long i = 0; i < replacementLength;i++)
				(*storage)[i] = replacement[i];
		} 
	}
};

void setEqual(char ** storage,char replacement)
{
								//Mix it up
	if (findLength(*storage) == 2)
	{
		*storage[0] = replacement;
	} else
	{
		delete [] *storage;
		*storage = new char[2];
		(*storage)[0] = replacement;
		(*storage)[1] = '\0';
	} 
};

void setEqual(char** storage, const char replacement[])
{
	if (*storage == 0)
	{
		unsigned long replacementLength = (unsigned long) findLength(replacement);
		*storage = new char[ replacementLength ];
		for (unsigned long i = 0; i < replacementLength ;i++)
			*(*storage + i) = replacement[i];

	} else
	{
									//Assemble Ingredients
		unsigned long storageLength = findLength(storage);
		unsigned long replacementLength = findLength(replacement);
									//Mix it up
		if (storageLength == replacementLength)
		{
			for (unsigned long i = 0; i < storageLength;i++)
				(*storage)[i] = replacement[i];
		} else
		{
			delete [] *storage;
			*storage = new char[replacementLength];
			for (unsigned long i = 0; i < replacementLength;i++)
				(*storage)[i] = replacement[i];
		} 
	}
}
unsigned long findLength(char * subject)
{
	if (subject == 0)
		return 0;
	unsigned long count = 0;
	char curChar = '0';
	while ((curChar !='\0')&&(count < ULONG_MAX))
	{
		curChar = subject[count];
		count++;
	}
	return count;
};

unsigned long findLength(char ** subject)
{
	//I have a feeling that some modders aren't going to be careful about this function
	//I'm going to save a couple of headaches at the cost of efficiency
	//Convention be damned
	return findLength(*subject);		
}

unsigned long findLength(const char subject[])
{
	unsigned long count = 0;
	char curChar = '0';
	while ((curChar !='\0')&&(count < ULONG_MAX))
	{
		curChar = subject[count];
		count++;
	}
	return count;
}

bool isEqual(const char left[],const char right[])		
{
	char ** leftConv	= new char*;
	char ** rightConv	= new char*;
	*leftConv	= 0;
	*rightConv	= 0;
	bool equality;
	setEqual(leftConv,	left);
	setEqual(rightConv,	right);
	equality= isEqual(*leftConv,*rightConv);
	delete[] *leftConv;
	delete[] *rightConv;
	delete leftConv;
	delete rightConv;
	return equality;
}
bool isEqual(char** left,char** right)
{
	return isEqual(*left,*right);		//Go deeper. Get closer to a stack overflow.
}
bool isEqual(char* left,char* right)
{
	int leftLength = findLength(left);		//Lets find how long these strings are
	int rightLength = findLength(right);

	if(findLength(left) != findLength(right))
	{
		//If they don't have the same length, then obviously they won't have the same data.
		return false;
	}

	for (int i = 0; i < leftLength; i++)
	{
		if(left[i]!=right[i])			//O(n) algorithm for finding lack of equalness between strings
			return false;
	}

	return true;						//Hey, we made it through. They're obviously the same
}
bool isEqual(const char left[],char* right)
{
	char ** leftConv = new char*;
	*leftConv= 0;
	bool equality;
	setEqual(leftConv,left);
	equality= isEqual(*leftConv,right);
	delete[] *leftConv;
	delete leftConv;
	return equality;
}
bool isEqual(char* left,const char right[])
{
	char ** rightConv = new char*;
	*rightConv= 0;
	bool equality;
	setEqual(rightConv,right);
	equality= isEqual( left, *rightConv);
	delete[] *rightConv;
	delete rightConv;
	return equality;
}
bool isEqual(char** left,char* right)
{
	return isEqual(*left,right);
}
bool isEqual(char* left,char** right)
{
	return isEqual(left,*right);
}
bool isEqual(const char left[],char** right)
{
	char ** leftConv = new char*;
	*leftConv= 0;
	bool equality;
	setEqual(leftConv,left);
	equality= isEqual( *right, *leftConv);
	delete[] *leftConv;
	delete leftConv;
	return equality;
}
bool isEqual(char** left,const char right[])
{
	char ** rightConv = new char*;
	*rightConv= 0;
	bool equality;
	setEqual(rightConv,right);
	equality= isEqual( *left, *rightConv);
	delete[] *rightConv;
	delete rightConv;
	return equality;
}

char * ftoa(float input)
{
	char * output = 0;
	stringstream str;
	str << input;
	setEqual(&output,str.str().c_str());
	return output;

}