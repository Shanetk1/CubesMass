#ifndef STEERING_H
#define STEERING_H

#include "../Vector.h"
#include "SteeringOutput.h"

class BlendedSteering;



//Purely virtual class...Even though it is one function will be used by all defined steering algorithms...
//Eventually we might update this to updating
class Steering
{
protected:
	float delay = 0.0f;

public:	
	BlendedSteering* SteeringHandler = nullptr;

	//We need to use deltaTime to showcase this is running every tick, also will be used to allow algorithms to be delayed... (not update every tick)
	virtual SteeringOutput getSteering(const float deltaTime) = 0;
	
	void setDelay(float delay_) { delay = delay_; }
	//setDefaultValues... //But this wont work 


};



#endif // !STEERING_H
