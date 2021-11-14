#include "BlendedSteering.h"




BlendedSteering::BlendedSteering() : Steering()
{
	//Loop thru our



}




SteeringOutput BlendedSteering::getSteering()
{
	//This is ok but yeah idk about the struct still
	SteeringOutput result;



	for (auto& a : algorithms)
	{
		//Update all algorithms data values...
		//This will give us our steering... it looks wierd since its not called getSteering
		result = a->getSteering();
		//Functions get populated with the necessary data 
	




	}










	return result;
}
