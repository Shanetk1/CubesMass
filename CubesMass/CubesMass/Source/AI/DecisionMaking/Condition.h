#ifndef CONDITION_H
#define CONDITION_H

class AIController;

class Condition
{
protected:
	AIController* owner;
public:
	virtual bool test() = 0;
	Condition(AIController* owner_);
	~Condition();



};


#endif // !CONDITION_H
