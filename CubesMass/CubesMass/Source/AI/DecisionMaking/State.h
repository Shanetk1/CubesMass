#ifndef STATE_H
#define STATE_H

#include <list>
#include "Transition.h"


class Transition;


class State
{
public:
	State();
	~State();
	void getActions();
	void getEntryActions();
	void getExitActions();

	//getName() { return name; }
	std::list<Transition*> getTransitions() { return transitions; }
	void addTransition(Transition* transition);




private:
	//List of our transitions from this state....
	//Transition transitions[];
	std::list<Transition*> transitions;
	//Name...
};


#endif // !STATE_H
