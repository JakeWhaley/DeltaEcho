#ifndef CONDITION_H
#define CONDITION_H
#include "CharFunc.h"
template <typename CondTemp>

class Condition
{

private:
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
	void		ZeroOut();			//Function for preparing Condition Class
public:
	Condition();
	Condition(bool,short,short,CondTemp *,char*,char*);
	Condition(Condition*,bool,short,short,CondTemp *,char*,char*);
	~Condition();
	void		setCondition(Condition*);
	void		setCondition(Condition*,bool,short,short,CondTemp*,char*,char*);
	void		Adopt(Condition*);
	void		Disown(Condition*);
	void		Embrace(Condition*);
	void		Shun(Condition*);
	Condition*	GetParent();
	Condition*	GetFirstBorn();
	Condition*	GetElderSibling();
	Condition*	GetYoungerSibling();
	void		setNot(bool);
	bool		getNot();
	void		setBO(short);
	short		getBO();
	short		getCT();
	void		setData(CondTemp*,short);
	CondTemp*	getData();
	void		setName(char*);
	void		setComment(char*);
	char*		getName();
	char*		getComment();

	
};
#endif