#ifndef CONDITIONFOLLOWPATH_H
#define CONDITIONFOLLOWPATH_H


#include "../Condition.h"

class ConditionFollowPath : public Condition
{
public:
	ConditionFollowPath(AIInfoContainer* info) : Condition(info) {}
	~ConditionFollowPath();

private:
	bool test() override;
};


#endif // !CONDITIONFOLLOWPATH_H
