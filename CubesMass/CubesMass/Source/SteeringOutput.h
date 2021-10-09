#ifndef STEERINGOUTPUT_H
#define STEERINGOUTPUT_H
#include "Vector.h"
#include <iostream>
class SteeringOutput
{
public:

	inline static Vector2 getSteeringOutput(Vector2 AIPosition_) //This is our arrive algorithm
	{


		//To calculate this we need player pos, self-pos, max-speed

		//It is this classes job to do the algorithms stuff meaning i need to gather the world information as well....

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
	inline static Vector2 getWanderOutput(Vector2 AIPosition_)
	{
		float maxRotation = 1.0f;
		 

		//Vector2 result = 100.f * 


		//return Vector2(0.f);
	}



};



#endif // !STEERINGOUTPUT_H
