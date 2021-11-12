#ifndef STEERINGOUTPUT_H
#define STEERINGOUTPUT_H
#include "Vector.h"
#include <iostream>
#include <random>
class SteeringOutput
{
public:

	///!!! Currently speed is hard-coded in, this will change once the physics component is added 

	//This wont work...
	//This will be transitioned into a pure virtual class with a struct ofo 

	inline static Vector2 getSteeringOutput(Vector2 AIPosition_) 
	{


		float satisfactionRadius = 45.0f;
		const float timeTo = 1.15f;
		Vector2 result;
		result = Scene1::playerPosition - AIPosition_;
		
		float mag = sqrtf(result.x * result.x + result.y * result.y);


		if (mag < satisfactionRadius)
		{
			return Vector2(0.f);
		}

		result = result / timeTo;
		mag = sqrtf(result.x * result.x + result.y * result.y);
		
		if (mag > 100.0f)
		{
			result = Vector2(result.x / mag, result.y / mag);
			result *= 100.0f;
		}
		return result;
	}
	inline static Vector2 getSteeringOutput(Vector2 AIPosition_, Vector2 location)
	{


		float satisfactionRadius = 14.5f;
		const float timeTo = 1.15f;





		Vector2 result;
		result = location - AIPosition_;


		float mag = sqrtf(result.x * result.x + result.y * result.y);
		if (mag < satisfactionRadius)
		{
			return Vector2(0.f);
		}

		result = result / timeTo;
		mag = sqrtf(result.x * result.x + result.y * result.y);

		if (mag > 100.0f)
		{
			result = Vector2(result.x / mag, result.y / mag);
			result *= 100.0f;
		}
		return result;


	}
	inline static float getWanderOutput(Vector2 AIPosition_, float orientation)
	{
		float maxRotation = 1.0f;
		
		//Get a target location
		//Grab forward vector of that location
		//Randomize it a bit i think??
		
		
		Vector2 tmp = Vector2(cosf(orientation), sinf(orientation));
		//This gives our orientation as vector
		Vector2 result = tmp * 100.f;

		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);


		return r * maxRotation;

		std::cout << r << std::endl;


		



		


	}
	


};



#endif // !STEERINGOUTPUT_H
