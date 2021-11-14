#ifndef STEERINGALGORITHM_H
#define STEERINGALGORITHM_H


class SteeringAlgorithm : Steering
{
public:




	//All will have a init and destructor

	
	

	virtual SteeringOutput getSteering()  = 0;
	virtual void Update() {};
	virtual void Init() {};
	virtual ~SteeringAlgorithm() {};


};



#endif // !STEERINGALGORITHM_H
