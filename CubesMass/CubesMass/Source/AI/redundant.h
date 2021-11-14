#ifndef STEERINGOUTPUT_H
#define STEERINGOUTPUT_H
#include "../Vector.h"
#include <iostream>
#include <random>
class SteeringOutput
{
public:
	struct AIOutput
	{
		//Velocity, and orientation
		Vector2 vel = Vector2(0.0f);
		float orientation = 0.0f;
	};


/*	inline static AIOutput arrive(Vector2 AIPosition_)
	{
		//
		AIOutput result;

		float satisfactionRadius = 45.0f;
		const float timeTo = 1.15f;
		
		
		float mag = sqrtf(result.linear.x * result.linear.x + result.linear.y * result.linear.y);


		if (mag < satisfactionRadius)
		{
			result.linear = Vector2(0.0f);
			return result;
		}

		result.linear = result.linear / timeTo;
		mag = sqrtf(result.linear.x * result.linear.x + result.linear.y * result.linear.y);
		
		if (mag > 100.0f)
		{
			result.linear = Vector2(result.linear.x / mag, result.linear.y / mag);
			result.linear *= 100.0f;
		}
		return result;
	}*/

	//ARRIVE ALGORITHM, SPECIFY ONLY AI LOCATION (SELF) AND LOCATION TO TRAVEL TO.... Note, this arrive algorithm uses a lot of default values, if looking for specific results use a different version of arrive which allows for more customization
	inline static AIOutput arrive(Vector2 AIPosition_, Vector2 location_)
	{
		//Baseline 
		AIOutput result;


		float satisfactionRadius = 14.5f;
		const float timeTo = 1.15f;




		result.vel = location_ - AIPosition_;


		float mag = sqrtf(result.vel.x * result.vel.x + result.vel.y * result.vel.y);
		if (mag < satisfactionRadius)
		{

			//Here we run into an issue of it breaking...
			result.vel = Vector2(0.0f);


		}

		result.vel = result.vel / timeTo;
		mag = sqrtf(result.vel.x * result.vel.x + result.vel.y * result.vel.y);

		if (mag > 100.0f)
		{
			result.vel = Vector2(result.vel.x / mag, result.vel.y / mag);
			result.vel *= 100.0f;
		}

		result.orientation = atan2(result.vel.y, result.vel.x);
		//angle *= RADIANS_TO_DEGREES;
		//transformRef->setOrientation(angle);


		return result;
	}

	inline static AIOutput arrive(Vector2 AIPosition_, Vector2 location_, float mSpeed_, float satisfyRadius_, float timeTo_)
	{
		//Baseline 
		AIOutput result;


		float satisfactionRadius = satisfyRadius_; // 14.5f;
		const float timeTo =	   timeTo_; // 1.15f;




		result.vel = location_ - AIPosition_;

		//This mag = the length of result.linear
		float mag = sqrtf(result.vel.x * result.vel.x + result.vel.y * result.vel.y);
		

		//If distance < target radius don't allow AI to move basically
		if (mag < satisfactionRadius)
		{
			result.vel = Vector2(0.0f);
			return result;
		}



		result.vel = result.vel / timeTo;
		mag = sqrtf(result.vel.x * result.vel.x + result.vel.y * result.vel.y);


		//If the result.vel length isnt more than maxspeed
		if (mag > mSpeed_)
		{
			result.vel = Vector2(result.vel.x / mag, result.vel.y / mag);
			result.vel *= mSpeed_;
		}
		return result;
	}






	//Need more of same function with more customization for maxrotation, and mSpeed orientation given here is also redundant remove it
	inline static AIOutput wander(Vector2 AIPosition_, float orientation_)
	{
		//Baseline 
		AIOutput result;

		
		float maxRotation = 1.0f;
		



		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_real_distribution<> distr(0.25f, 1.0f);

		float r = distr(eng);




		result.orientation = r * maxRotation;

		Vector2 tmp = Vector2(cosf(result.orientation), sinf(result.orientation));


		result.vel = tmp * 100.f;

		return result;
		



		


	}
	


};





#endif // !STEERINGOUTPUT_H