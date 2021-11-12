#ifndef AIOUTPUT_H
#define AIOUTPUT_H

#include "Vector.h"


//This is a purely virtual class
class AIOutput
{
	//IDK IF ITS GOOD BUT I want to use it so we'll see



	struct SteeringOutput
	{
		//Angular vel, and linear vel... the angular vel will just be the new orientation and the linear vel will be the new velocity
		Vector2 linear;
		float angular;
	};


	virtual SteeringOutput getSteering();
};


#endif