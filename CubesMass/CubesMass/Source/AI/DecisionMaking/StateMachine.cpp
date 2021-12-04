#include "StateMachine.h"


//Add a reference to our owner...?
StateMachine::StateMachine(AIController* owner_)
{


}


bool StateMachine::Init()
{
	State* doNothing = new State(do_Nothing);



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