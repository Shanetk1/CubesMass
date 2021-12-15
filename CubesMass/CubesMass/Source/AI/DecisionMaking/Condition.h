#ifndef CONDITION_H
#define CONDITION_H


class AIInfoContainer;




//Virtual class will be inherited by all our conditions....
class Condition
{
protected:
	AIInfoContainer* info;
public:
	virtual bool test() = 0;
	Condition(AIInfoContainer* info_) { info = info_; }
	~Condition();



};


#endif // !CONDITION_H
