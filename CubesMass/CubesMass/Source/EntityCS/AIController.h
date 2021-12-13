#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "Components.h"
#include "../Vector.h"
#include "../AI/SteeringOutput.h"


#include "../AI/BlendedSteering.h"
#include "../AI/SteeringHeaders.h"
#include "../AI/FollowPath.h"
#include "../AI/DecisionMaking/StateMachine.h"


class AIController : public Component
{
private:

	//Necessary classes for moving the AI
	TransformComponent* transform = nullptr;
	MovementComponent* movement = nullptr;

	//Necessary class for gathering steering outputs and adding steering functionality
	BlendedSteering* SteeringHandler = nullptr;

	//Our necessary data for pathfinding
	Graph* graph = nullptr;

	//State Machine pointer
	StateMachine* state = nullptr;

	enum States
	{
		PATROL = 0,
		WANDER = 1,
		CHASE = 2
	};
	States State = PATROL;


public:
	bool seesPlayer = false;

	//Setting Default State, Init vector list
	AIController()
	{
		State = WANDER;
	}


	AIController(Graph* graph_)
	{
		graph = graph_;
		State = WANDER;

	}


	virtual void Init()
	{
		
		transform = &entity->getComponent<TransformComponent>();
		movement = &entity->getComponent<MovementComponent>();

		SteeringHandler = new BlendedSteering();
		
		State = WANDER;
		
		state = new StateMachine(this);
		state->Init();
		
		
		//Add steering here for pathfinding
		//This is fine...., eventually these node values need to change and change beased on lets say player position so we would need to deduce a x and y position and then correlate that into a node...
		//I also think sending it a path is fine.... I could rather send it a path via the game world node list.... but not sure....
		//For this followpath..... we will have a function that will find a new path every frame perhaps howeber will have a delay....
		SteeringHandler->addSteering<FollowPath>(10.0f, 0.0f, graph->findPathUsingAStar(28, 179));
		SteeringHandler->setMaxSpeed(150.0f);

	};
	virtual void Update(const float deltaTime)
	{
		static float delay = 0.0f;

		state->update();

		/*
		switch (state->)
		{
		default:
			break;
		}*/
		//This value will change based on state
		//Is our player position... which is updated every frame....
		//This is plugged into our Blended steering
		Vector2 target = Scene1::playerPosition;


		


		if (seesPlayer)
		{
			State = CHASE;
		}
		

		/*
		switch (switch_on)
		{
		default:
			break;
		}

		*/






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