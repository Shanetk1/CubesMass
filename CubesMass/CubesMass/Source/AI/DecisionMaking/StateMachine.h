#ifndef STATEMACHINE_H
#define STATEMACHINE_H


enum States
{
	S_DoNothing = 0,
	S_Chase = 1,
	S_FollowPath = 2
};
//Forward declarations... We are including these in cpp
class State;
class AIInfoContainer;


class StateMachine
{
	//Remember; the entire job of this class is to know about the initial state and current state...


public:
	StateMachine(AIInfoContainer* info_);

	//Return a enum....
	
	States getCurrentStateName();
	~StateMachine();
	bool Init();
	void update();


	//States here




private:
	State* initialState;
	State* currentState;
	AIInfoContainer* info;






};




#endif // !STATEMACHINE_H
