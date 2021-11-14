#ifndef STEERING_H
#define STEERING_H

#include "../Vector.h"
#include "SteeringOutput.h"

class Steering
{
	//A base class for every steering basically only just 1 function...
	//All steering algorithms need 
public:

		
	virtual SteeringOutput getSteering() = 0;

};



#endif // !STEERING_H
