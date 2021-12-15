#include "Transition.h"
#include <stdio.h>
#include <iostream>

Transition::Transition(State* targetState_, Condition* condition_) : targetState(targetState_), condition(condition_)
{}

Transition::~Transition()
{

}

bool Transition::isTriggered()
{
	//Check if our condition is triggered basically telling us that yes we need to transition or not

	return condition->test();
}
State* Transition::getTargetState()
{
	return targetState;
}