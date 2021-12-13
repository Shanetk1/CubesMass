#ifndef STATEMACHINE_H
#define STATEMACHINE_H


#include "State.h"

class StateMachine
{
	//Remember; the entire job of this class is to know about the initial state and current state...


public:
	StateMachine(AIController* owner_);
	
	//Return a enum....
	
	void getCurrentStateName();
	~StateMachine();
	bool Init();
	void update();
private:
	State* initialState;
	State* currentState;






};




#endif // !STATEMACHINE_H
