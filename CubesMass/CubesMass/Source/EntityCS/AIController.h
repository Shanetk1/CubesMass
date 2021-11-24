#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Components.h"
#include "../Vector.h"
#include "../AI/SteeringOutput.h"



#include "../AI/BlendedSteering.h"
#include "../AI/SteeringHeaders.h"
#include "../AI/FollowPath.h"



class AIController : public Component
{
private:

	TransformComponent* transform = nullptr;
	MovementComponent* movement = nullptr;

	//Our steering...
	BlendedSteering* SteeringHandler = nullptr;

	//Our necessary data for pathfinding
	Graph* graph = nullptr;
	std::vector<std::vector<TileDemo*>>* tiles = nullptr;


	//OLD
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


	AIController(Graph* graph_, std::vector<std::vector<TileDemo*>>* tiles_)
	{
		//patrolPoints = patrolPoints_;
		graph = graph_;
		tiles = tiles_;
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
		

		//Add steering here for pathfinding
		SteeringHandler->addSteering<FollowPath>(30.0f, 0.0f, tiles, graph->findPathUsingAStar(28, 179));
		SteeringHandler->setMaxSpeed(150.0f);

	};
	virtual void Update(const float deltaTime)
	{
		static float delay = 0.0f;


		//This value will change based on state
		Vector2 target = Scene1::playerPosition;





		if (seesPlayer)
		{
			State = CHASE;
		}



		switch (State)
		{
		case AIController::PATROL:

			break;
		case AIController::WANDER: {


			//I rlly dont like this..
			if (delay <= 0.0f)
			{
				delay = 2.0f;
			}
		}
			break;
		case AIController::CHASE:

			break;
		default:
			break;
		}








		//First update the necessary updatables after all logic has been done
		SteeringHandler->updateUpdatables(target, this->transform->position);


		//Then we need to get our result of the algorithms.....
		SteeringOutput val = SteeringHandler->updateAlgorithms(deltaTime);

		//Set these gathered values to our aI's velocity, and position...
		movement->setVelocity(val.vel);
		transform->setOrientation(val.orientation);

	};
	virtual void Render()
	{};


};



#endif 