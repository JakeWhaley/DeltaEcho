#ifndef TRIGGER_H
#define TRIGGER_H
#include "CharFunc.h"
class Trigger
{
private:
	Condition * condTree;
	Action *	actionTree;

public:
	Trigger();
	Trigger(Condition*,Action*);
	~Trigger();

}
#endif