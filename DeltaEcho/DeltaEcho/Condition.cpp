#include "Condition.h"

template <typename CondTemp>
void Condition<CondTemp>::ZeroOut()
{
	parent = 0;
	child = 0;
	previous = 0;
	next = 0;
	not = false;
	booleanOperator = 0;
	conditionType = 0;
	data = 0;
	name = 0;
	comment = 0;
};

template <typename CondTemp>
Condition<CondTemp>::Condition()
{
	ZeroOut();
};

template <typename CondTemp>
Condition<CondTemp>::Condition(bool inNot,short inBool,short inType,CondTemp* inData,char* inName,char* inComment)
{
	ZeroOut();
	not = inNot;
	booleanOperator = inBool;
	setData(inData,inType);
	SetEqual(&name,inName);
	SetEqual(&comment,inComment);
};

template <typename CondTemp>
Condition<CondTemp>::Condition(Condition* inParent,bool inNot,short inBool,short inType,CondTemp* inData,char* inName,char* inComment)
{
	ZeroOut();
	not = inNot;
	booleanOperator = inBool;
	setData(inData,inType);
	SetEqual(&name,inName);
	SetEqual(&comment,inComment);
	parent=inParent;
	parent->Adopt(this);
};


template <typename CondTemp>
Condition<CondTemp>::~Condition()
{
	if(data)
		delete [] data;
	if(name)
		delete [] name;
	if(comment)
		delete [] comment;
	if(child)
		delete child;
	if(youngerSibling)
		delete youngerSibling;
};


template <typename CondTemp>
void	Condition<CondTemp>::setCondition(Condition* input)
{
	not = input->getNot();
	booleanOperator = input->getBO();
	CondTemp * temp = input->getData();
	setData(temp,input->getCT());
	delete [] temp;
	if(name)
		delete [] name;
	if(comment)
		delete [] comment;
	name = input->getName();
	comment = input->getComment();
};

template <typename CondTemp>
void	Condition<CondTemp>::setCondition(Condition* inParent,bool inNot,short inBool,short inType,CondTemp* inData,char* inName,char* inComment)
{

	not = inNot;
	booleanOperator = inBool;
	setData(inData,inType);
	if(name)
		delete [] name;
	if(comment)
		delete [] comment;
	setEqual(&name,inName);
	setEqual(&comment,inComment);
	parent->Disown(this);
	parent = inParent;
	parent->Adopt(this);
};

template <typename CondTemp>
void		Condition<CondTemp>::Adopt(Condition* adoptee)
{
	if(child)
		child->Embrace(adoptee);
	else child = adoptee;
};

template <typename CondTemp>
void		Condition<CondTemp>::Disown(Condition* kid)
{
	if(child == kid)
		child = child->GetYoungerSibling();
	else if(child)
		child->Shun(kid);
	else return;		//Wonder how we got here?
};

template <typename CondTemp>
void		Condition<CondTemp>::Embrace(Condition* adoptee)
{
	if(youngerSibling)
		youngerSibling->Embrace(adoptee);
	else youngerSibling = adoptee;
};

template <typename CondTemp>
void		Condition<CondTemp>::Shun(Condition* kid)
{
	if(youngerSibling==kid)
		youngerSibling=kid->GetYoungerSibling();
	else if(youngerSibling)
		youngerSibling->Shun(kid);
	else return;		//Wonder how we got here?
};

template <typename CondTemp>
Condition<CondTemp>*	Condition<CondTemp>::GetParent()
{
	return parent;
};

template <typename CondTemp>
Condition<CondTemp>*	Condition<CondTemp>::GetFirstBorn()
{
	return child;
};

template <typename CondTemp>
Condition<CondTemp>*	Condition<CondTemp>::GetElderSibling()
{
	return elderSibling;
};

template <typename CondTemp>
Condition<CondTemp>*	Condition<CondTemp>::GetYoungerSibling()
{
	return youngerSibling;
};

template <typename CondTemp>
void		Condition<CondTemp>::setNot(bool input)
{
	not = input;
};

template <typename CondTemp>
bool		Condition<CondTemp>::getNot()
{
	return not;
};

template <typename CondTemp>
void		Condition<CondTemp>::setBO(short inBO)
{
	booleanOperator = inBO;
};

template <typename CondTemp>
short		Condition<CondTemp>::getBO()
{
	return booleanOperator;
};

template <typename CondTemp>
short		Condition<CondTemp>::getCT()
{
	return conditionType;
};

template <typename CondTemp>
void		Condition<CondTemp>::setData(CondTemp* inData, short inType)
{
	if(data)
		delete[] data;
	data = new CondTemp[inData[0]];
	for(int i = 0; i < inData[0];i++)
	{
		data[i]=inData[i];
	}
	conditionType = inType;
};

template <typename CondTemp>
CondTemp*	Condition<CondTemp>::getData()
{
	CondTemp* temp = new CondTemp[data[0]];
	for (int i = 0; i < data[0];i++)
	{
		temp[i]=data[i]
	}
	return temp;
};

template <typename CondTemp>
void		Condition<CondTemp>::setName(char* input)
{
	SetEqual(&name,input);
};

template <typename CondTemp>
void		Condition<CondTemp>::setComment(char* input)
{
	SetEqual(&comment,input);
};

template <typename CondTemp>
char*		Condition<CondTemp>::getName()
{
	char * temp;
	SetEqual(&temp,name);
	return temp;
};

template <typename CondTemp>
char*		Condition<CondTemp>::getComment()
{
	char * temp;
	SetEqual(&temp,comment);
	return temp;
};