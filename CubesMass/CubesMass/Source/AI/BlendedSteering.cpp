#include "BlendedSteering.h"




BlendedSteering::BlendedSteering() : mSpeed(50.0f), aiPos(Vector2(0.0f)), targetLocation(Vector2(0.0f))
{
	//Blended steering gets created...
	//This is fine, eventually we will need to update our base class
	//
}

BlendedSteering::BlendedSteering(Vector2 targetLoc_, Vector2 aiPos_, float mSpeed_)
{
	targetLocation = targetLoc_;
	aiPos = aiPos_;
	mSpeed = mSpeed_;
}

SteeringOutput BlendedSteering::updateAlgorithms(const float deltaTime)
{
	SteeringOutput result;

	for (auto &i : algorithms)
	{

		//Adds up all stored algorithms
		//Eventually there will be a weight to it but we shall see





		if (i != nullptr)
		{
			result += *i->getSteering(deltaTime);
		}

	}


	return result;
}
