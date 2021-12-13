#include "StateMachine.h"


//Add a reference to our owner...?
StateMachine::StateMachine(AIController* owner_)
{


}


bool StateMachine::Init()
{
	
/*
	//Create all our states...
	State* doNothing = new State(do_Nothing);
	State* followPath2 = new State(follow_a_path_v2);
	State* followPath2 = new State(follow_mouse);
	State* pursueTarget = new State(pursue_target);


	//This class inherits from transition class....
	ConditionFollowMouse* c1;
	c1 = new ConditionFollowMouse(owner);
	Transition* t1 = new Transition(followPath2, c1);
	doNothing->addTransition(t1);
	*/

	return true;
}

void StateMachine::update()
{
	Transition* triggered = nullptr;

	for (Transition* transition : currentState->getTransitions())
	{
		if (transition->isTriggered())
		{
			triggered = transition;
			break;
		}
	}
	if (triggered)
	{
		State* targetState = triggered->getTargetState();

		currentState = targetState;
	}
	else
	{

	}
	return;
}