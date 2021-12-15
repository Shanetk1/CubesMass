#include "ConditionPursue.h"
#include "../../AIInfoContainer.h"

bool ConditionPursue::test()
{
	//We need to create getters for our info class......


	if (info->getSeesPlayer())
	{

		return true;
	}
	else
	{
		return false;
	}
}
