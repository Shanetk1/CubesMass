#include "State.h"

State::State(States state_)
{
	name = state_;
}

State::State()
{

}
State::~State()
{

}
void State::addTransition(Transition* transition)
{
	//Add transition to our list of transitions...
	transitions.push_back(transition);

}
void State::getActions()
{

}
void State::getEntryActions()
{

}
void State::getExitActions()
{

}
std::list<Transition*>& State::getTransitions()
{
	return transitions;
}
