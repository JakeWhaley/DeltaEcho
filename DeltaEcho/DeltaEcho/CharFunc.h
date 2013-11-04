#ifndef CHARFUNC_H
#define CHARFUNC_H
#include <limits.h>
#include <sstream>
//#include <string.h>

using namespace std;
//This is Function for string manipulation.
//Someone is going to complain about me reinventing the wheel.
//I prefer making sure my wheel isn't actually a box.
//This holds some well known functions as well as personal
//short hand functions
//Feel free to add, but do not remove from the core.

		//First String, Second String
		void concatenate(char**,char*);		
		void conc(char**,char*);			//shorthand
		void concatenate(char**,char);		//adds single character, Also adds a string terminator
		void conc(char**,char);				//shorthand
		void concatenate(char**,const char []);	//TODO:Implement
		void conc(char**,const char[]);			//TODO:Implement

		//Output string, input string
		void setEqual(char**,char*);
		void setEqual(char**,char);			//setEqual a single character, Also adds a string terminator
		void setEqual(char**,const char[]);	

		//String, special char, placement	//Special Formatting
		void addFormat(char**,char);		
		void addFormat(char**,char,unsigned long);	//For a specific place
		void addFormat(char**,char[],unsigned long);

		//String, Color
		void addColor(char**,int);		//Uses quicktable
		void addHexColor(char**,int);	//Specified Color

		//String, Color, placement
		void addColor(char**,int,unsigned long);		//Uses quicktable
		void addHexColor(char**,int,unsigned long);	//Specified Color

		//Looks for string terminators, and returns their position.
		unsigned long findLength(char*);
		unsigned long findLength(char**);
		unsigned long findLength(const char[]);

		//TODO: All of these
		bool isEqual(const char[],const char[]);	//Currently all of the other isEquals funnels to char* , char*
		bool isEqual(char**,char**);				//Obviously this is not optimal in the long run
		bool isEqual(char*,char*);					//If you read this and find that they all still do this
		bool isEqual(const char[],char*);			//Feel free to be an ass to me about my temporary fix
		bool isEqual(char*,const char[]);			//No seriously. This is shameful.
		bool isEqual(char**,char*);					//If you're picking apart my code as a hobby
		bool isEqual(char*,char**);					//Feel free to make my mistake here again
		bool isEqual(const char[],char**);			//Just remember you're so susceptible to memory leaks
		bool isEqual(char**,const char[]);			//Changing your algorithm from O(n) to O(scary)

		char* ftoa(float);


#endif
