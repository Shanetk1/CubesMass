#ifndef WANDER_H
#define WANDER_h



#include "Steering.h"
#include <random>

class Wander : public Steering
{
public:
	Wander()
	{

	}


	//Set default values
//	Wander()
//	{
//	}




	SteeringOutput getSteering(const float deltaTime) override
	{
		return wander();
	}


private:



	//Algorithm Calculation
	SteeringOutput wander()
	{
		//Baseline

		SteeringOutput result;


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



#endif // !WANDER_H
