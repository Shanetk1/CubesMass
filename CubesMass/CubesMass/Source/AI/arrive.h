#ifndef ARRIVE_H

#define ARRIVE_H

#include "SteeringHeaders.h"

class Arrive : public SteeringAlgorithm
{
public:



	Arrive()
	{

	}
	//Target position, self(AI) location)
	Arrive(Vector2 targetPos_, Vector2 selfLocation_)
	{
		location_ = targetPos_;
		aiPosition_ = selfLocation_;
	}
 	
	SteeringOutput getSteering() override
	{
		
		return SteeringOutput(arrive(aiPosition_, location_));
	}
	void updateValues(Vector2 targetPos_, Vector2 selfLocation_)
	{
		location_ = targetPos_;
		aiPosition_ = selfLocation_;
	}


	void Init() override
	{

	}
private:
	Vector2 aiPosition_, location_ = Vector2(0.0f);




	inline SteeringOutput arrive(Vector2 AIPosition_, Vector2 location_)
	{
		//Baseline 
		SteeringOutput result;


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


};

#endif // !ARRIVE_H
