#ifndef TRANSITION_H
#define TRANSITION_H

#include "Condition.h"

class Transition
{
private:
	class State* targetState;
	class Condition* condition;
public:
	Transition(State* targetState_, Condition* condition_);
	~Transition();
	bool isTriggered();
	State* getTargetState();
};



#endif // !TRANSITION_H
