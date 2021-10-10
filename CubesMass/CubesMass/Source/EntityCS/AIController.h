#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Components.h"
#include "../Vector.h"
#include "../SteeringOutput.h"
class AIController : public Component
{
private:

	TransformComponent* transform = nullptr;

	//Patrolling handling I think this can be done better but for now it works
	std::vector<Vector2*> patrolPoints = std::vector<Vector2*>();
	Vector2 patrolLocation;
	int patrolNode = 0;
	



	enum States
	{
		PATROL = 0,
		WANDER = 1,
		CHASE = 2
	};
	States State = PATROL;


	inline void beginPatrol()
	{

		//Basically, always move to the first item in the vector list
		if (patrolPoints.size() > 0)
		{

			if (MATH::VMath::distance(transform->position, *patrolPoints.at(0)) < 10.f)
			{
				//Use a different point
				patrolLocation = *patrolPoints.at(1);
				patrolNode = 1;
			}
			else
			{
				patrolLocation = *patrolPoints.at(0);
				patrolNode = 0;
			}
		}
	}


public:
	//We ned to handle enum switching based off other stuff dont know yet other than manually...

	bool seesPlayer = false;




	//The components job is to have functionality that will effect the A.I's transform...
	//Meaning implement algorithms based on the ai's state

	AIController()
	{
		//Setting Default
		State = PATROL;
		patrolPoints = std::vector<Vector2*>();
	}
	AIController(std::vector<Vector2*> patrolPoints_)
	{
		patrolPoints = patrolPoints_;
		State = PATROL;
	}


	virtual void Init()
	{
		//This is dangerous since if this doesnt exist will will get an error, could add error check but lazy
		transform = &entity->getComponent<TransformComponent>();
		State = PATROL;
		beginPatrol();
	};
	virtual void Update(const float deltaTime)
	{

		if (seesPlayer)
		{
			State = CHASE;
		}



		switch (State)
		{
		case AIController::PATROL:
			//Patrol should just update velocity...
			//We need to call something and send it our information thats it and it should return a result
			//However this component shouldnt need to hold the player position for every ai we have...

			transform->velocity = SteeringOutput::getSteeringOutput(transform->position, patrolLocation);

			std::cout << transform->orientation << std::endl;


			if (patrolPoints.size() > 1)
			{
				if (patrolNode == 0 && MATH::VMath::distance(patrolLocation, transform->position) < 15.0f)
				{
					//Enemy AI is close to goal location, change target to next patrol destination
					patrolNode = 1;
					patrolLocation = *patrolPoints.at(patrolNode);
				}
				else if (patrolNode == 1 && MATH::VMath::distance(patrolLocation, transform->position) < 15.0f)
				{
					patrolNode = 0;
					patrolLocation = *patrolPoints.at(patrolNode);
				}


			}

			break;
		case AIController::WANDER:
			//transform->velocity = SteeringOutput::getWanderOutput(transform->position);
			break;
		case AIController::CHASE:
			transform->velocity = SteeringOutput::getSteeringOutput(transform->position);

			break;
		default:
			break;
		}




	};
	virtual void Render()
	{

	};


};



#endif 