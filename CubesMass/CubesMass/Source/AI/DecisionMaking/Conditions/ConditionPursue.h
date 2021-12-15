#ifndef CONDITIONPURSUE_H
#define CONDITIONPURSUE_H

#include "../Condition.h"


class ConditionPursue : public Condition
{
public:
	ConditionPursue(AIInfoContainer* info_) : Condition(info_) {};
	~ConditionPursue();





private:
	bool test() override;
};

#endif // !CONDITIONPURSUE_H
