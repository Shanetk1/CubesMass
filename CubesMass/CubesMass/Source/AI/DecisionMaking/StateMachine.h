#ifndef STATEMACHINE_H
#define STATEMACHINE_H


#include "State.h"

class StateMachine
{
public:
	StateMachine(AIController* owner_);
	
	//Return a enum....
	getCurrentStateName();
	~StateMachine();
	bool Init();
	void update();
private:
	State* initialState;
	State* currentState;






};




#endif // !STATEMACHINE_H
