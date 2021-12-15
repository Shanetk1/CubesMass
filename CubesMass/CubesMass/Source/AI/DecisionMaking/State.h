#ifndef STATE_H
#define STATE_H

#include <list>
#include "Transition.h"


class Transition;
enum States;

class State
{
public:
	State();
	State(States state);
	~State();
	void getActions();
	void getEntryActions();
	void getExitActions();

	int getName() { return name; }
	std::list<Transition*>& getTransitions();
	void addTransition(Transition* transition);




private:
	//List of our transitions from this state....
	//Transition transitions[];
	std::list<Transition*> transitions;

	//Basically turn our states into an int...
	States name;
	//Name...
};


#endif // !STATE_H
