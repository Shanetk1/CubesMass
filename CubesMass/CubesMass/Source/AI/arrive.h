#ifndef ARRIVE_H

#define ARRIVE_H

#include "../Vector.h"
#include "Steering.h"

class Arrive : public Steering
{
public:
	//Defaulted... will use all set default values
	Arrive()
	{
	
	
	}
	
	//Sets default variables... This can be updated again using a different method
	Arrive(float satRadius_, float timeTo_)
	{
		satRadius = satRadius_;
		timeTo = timeTo_;
	}


	SteeringOutput* getSteering(const float deltaTime) override
	{
		//Why we do this is because we need to run the algorithm then let the algorithm to be delayed
		static float timePassed = delay;
		//Entire logic of allowing algorithms to be delayed... we can set the delay to 0.5 default as it wouldnt really change anything...
		if (delay <= timePassed)
		{
			timePassed = 0.0f;
			return new SteeringOutput(arrive(SteeringHandler->getAIPos(), SteeringHandler->getTargetLoc()));
			
		}
		else
		{
			

			timePassed += deltaTime;
			//std::cout << arrive(oldPos, oldLoc).vel.x << std::endl;


			//Why this doesnt work.... because oldPos old Loc are old and senDING it old values will produce old results...
			//This mean that the AI position would need to be updated sadly which kind of makes this redundant but idk yet... 
			//For now having a delay on arrive is slightly pointless
			//but we will keep it in because its overall useful and can still be used just on a very low amount of delay probably around 0.5 

			return new SteeringOutput(arrive(oldPos, oldLoc));


			

		}



	}
	

	//Setters
	void setTimeTo(float timeTo_) { timeTo = timeTo_; }
	void setSatRadius(float satRadius_) { satRadius = satRadius_; }


private:
	Vector2 oldLoc, oldPos = Vector2();


	SteeringOutput oldValue = SteeringOutput();
	//Store an old value, meaning store the last returned value

	//const variables... hwoever we are not going to be keeping these const... this is because there could be an instance where we might want to change the timeto, or the satisfaction radius...
	float satRadius;
	float timeTo;
	//These are defaulted to these values if not set..







	//Algorithm Calculation
	inline SteeringOutput arrive(Vector2 AIPosition_, Vector2 location_)
	{
		oldLoc = location_;
		oldPos = AIPosition_;



		//Baseline 
		SteeringOutput result;
		float mSpeed = SteeringHandler->getMaxSpeed();


		

		result.vel = location_ - AIPosition_;


		float mag = sqrtf(result.vel.x * result.vel.x + result.vel.y * result.vel.y);
		if (mag < satRadius)
		{

			//Here we run into an issue of it breaking...

			//This is an issue because of the orientation resetting...
			result.vel = Vector2(0.0f);
			result.orientation = oldValue.orientation;

			return result;

		}




		if (!timeTo == 0.0f)
		{
			result.vel = result.vel / timeTo;
		}
		else
		{
			result.vel = result.vel * mSpeed;
		}

		
		mag = sqrtf(result.vel.x * result.vel.x + result.vel.y * result.vel.y);
		if (mag > mSpeed)
		{
			result.vel = Vector2(result.vel.x / mag, result.vel.y / mag);
			result.vel *= mSpeed;
		}

		result.orientation = atan2(result.vel.y, result.vel.x);
		//angle *= RADIANS_TO_DEGREES;
		//transformRef->setOrientation(angle);
	

		//For special case fix
		oldValue = result;

		return result;
	}
};

#endif // !ARRIVE_H
