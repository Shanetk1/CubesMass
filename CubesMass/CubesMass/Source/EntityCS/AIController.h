#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Components.h"
#include "../Vector.h"
#include "../AI/SteeringOutput.h"



#include "../AI/BlendedSteering.h"
#include "../AI/SteeringHeaders.h"


class AIController : public Component
{
private:

	TransformComponent* transform = nullptr;
	MovementComponent* movement = nullptr;
	BlendedSteering* SteeringHandler = nullptr;

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

			//Eventually add randomization to picking patrol point...
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


	bool seesPlayer = false;

	//Setting Default State, Init vector list
	AIController()
	{
		State = WANDER;
		patrolPoints = std::vector<Vector2*>();
	}


	AIController(std::vector<Vector2*> patrolPoints_)
	{
		patrolPoints = patrolPoints_;
		State = WANDER;
	}


	virtual void Init()
	{
		//This is dangerous since if this doesnt exist will will get an error, could add error check but lazy
		transform = &entity->getComponent<TransformComponent>();
		movement = &entity->getComponent<MovementComponent>();
		SteeringHandler = new BlendedSteering();
		State = WANDER;
		beginPatrol();



		SteeringHandler->addSteering<Arrive>();



	};
	virtual void Update(const float deltaTime)
	{
		static float delay = 0.0f;

		//Why we need to do this...
		SteeringHandler->getAlgorithm<Arrive>().updateValues(Scene1::playerPosition, transform->getPosition());



		//SteeringOutput::AIOutput val;

		//Preset values to old values needed
	//	val.vel = movement->getVelocity();
	//	val.orientation = transform->getOrientation();

		//std::cout << delay << std::endl;


		if (seesPlayer)
		{
			State = CHASE;
		}



		switch (State)
		{
		case AIController::PATROL:
			//Patrol should just update velocity...
			//We need to call something and send it our information thats it and it should return a result


			//val = SteeringOutput::arrive(transform->position, patrolLocation);


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
		case AIController::WANDER: {


			//I rlly dont like this..
			if (delay <= 0.0f)
			{
				//val = SteeringOutput::wander(transform->getPosition(), transform->getOrientation());
				delay = 2.0f;
			}
		}
			break;
		case AIController::CHASE:
			//val = SteeringOutput::arrive(transform->position, Scene1::playerPosition);

			break;
		default:
			break;
		}





		movement->setVelocity(SteeringHandler->getSteering().vel);

		if (MATH::VMath::mag(movement->getVelocity()) > 0.0f)
		{
		//	transform->setOrientation(val.orientation);
		}

		delay -= deltaTime;
	};
	virtual void Render()
	{};


};



#endif 