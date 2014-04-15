#ifndef CONDITION_H
#define CONDITION_H
#include "CharFunc.h"
template <class CondTemp>

class Condition
{

public:
	Condition * parent;
	Condition * child;
	Condition * previous;
	Condition * next;
	bool		not;
	short		booleanOperator;
	short		conditionType;
	CondTemp *	data;
	char *		name;
	char *		comment;

	Condition();
	Condition(bool,short,short,CondTemp*,char*,char*);
	Condition(Condition*,bool,short,short,CondTemp*,char*,char*);
	~Condition();
	void		setCondition(Condition*);
	void		setCondition(Condition*,bool,short,short,CondTemp*,char*,char*);
	void		Adopt(Condition*);
	void		Disown(Condition*);
	void		SetElderSibling(Condition*);
	void		SetYoungerSibling(Condition*);
	Condition*	GetParent();
	Condition*	GetFirstBorn();
	Condition*	GetElderSibling();
	Condition*	GetYoungerSibling();
	void		setNot(bool);
	bool		getNot();
	void		setBO(short);
	short		getBO();
	void		setCT(short);
	short		getCT();
	void		setData(CondTemp);
	CondTemp*	getData();
	void		setName(char*);
	void		setComment(char*);
	char*		getName();
	char*		getComment();

	
}
#endif