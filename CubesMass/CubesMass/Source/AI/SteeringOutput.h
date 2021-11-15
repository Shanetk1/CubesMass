#ifndef STEERINGOUTPUT_H
#define STEERINGOUTPUT_H

#include "../Vector.h"



struct SteeringOutput
{
	//Velocity, and orientation
	Vector2 vel = Vector2(0.0f);
	float orientation = 0.0f;



	//A quick += operator overload....


	inline SteeringOutput& operator += (const SteeringOutput& s_)
	{
		this->vel += s_.vel;
		this->orientation += s_.orientation;

		return *this;



	}



};
#endif // !STEERINGOUTPUT_H
