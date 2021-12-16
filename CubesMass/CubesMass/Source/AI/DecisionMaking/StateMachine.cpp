#include "StateMachine.h"

#include "State.h"


//Conditions!
#include "Conditions/ConditionPursue.h"
#include "Conditions/ConditionFollowPath.h"
//Add a reference to our owner...?
StateMachine::StateMachine(AIInfoContainer* info_) : info(info_), currentState(nullptr), initialState(nullptr)
{}

StateMachine::~StateMachine() {}


bool StateMachine::Init()
{
	//Create all our states...
	State* doNothing = new State(S_DoNothing);
	State* followPath = new State(S_FollowPath);
	State* pursueTarget = new State(S_Chase);



	//This class inherits from transition class....

	//Adds a transition from doNothing state to the pursue state... //Sets the condition of these state to only change when ConditionPursue becomes true!


	//
	ConditionPursue* c1;
	c1 = new ConditionPursue(info);
	Transition* t1 = new Transition(pursueTarget, c1);
	doNothing->addTransition(t1);
	
	//Add a transition state from doNothing state to the followPath state!
	ConditionFollowPath* c2;
	c2 = new ConditionFollowPath(info);
	Transition* t2 = new Transition(followPath, c2);
	doNothing->addTransition(t2);




	//Re-use conditions for return back basically....
	//Since Condition follow path 
	//follow path and pursue need to be connected as well

	
	followPath->addTransition(t1);

	

	pursueTarget->addTransition(t2);
	

	



	//Set up our member variables!
	initialState = doNothing;
	currentState = initialState;

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

States StateMachine::getCurrentStateName()
{
	return static_cast<States>(currentState->getName());



}