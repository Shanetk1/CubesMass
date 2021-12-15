#include "ConditionFollowPath.h"
#include "../../AIInfoContainer.h"

bool ConditionFollowPath::test()
{
	//Only start following a path when.... seesplayer is false.... i think?

	

	//If sees player is true dont do this condition, if seesplayer is false go back to following path.. 
	return !info->getSeesPlayer();

}