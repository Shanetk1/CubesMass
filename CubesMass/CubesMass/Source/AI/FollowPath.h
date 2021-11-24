#ifndef FOLLOWPATH_H
#define FOLLOWPATH_H

#include "arrive.h"
#include "../VMath.h"
#include "BlendedSteering.h"
#include "Pathfinding/Graph/Path.h"

using namespace MATH;



class Graph;

class FollowPath : public Arrive
{
public:
	//Don't use this ever it will break the entire class
	FollowPath()
	{

	}

	//Pass in our graph address also our path.... or we could actually specify a location rather a node instead..... and then use the graph to calculate closest nodes to location then create a path from that....
	FollowPath(float satRadius_, float timeTo_, std::vector<std::vector<TileDemo*>>* graph_, std::vector<int> path_)
	{
		//I set time to so it sets the inherited arrives time to....

		//Set up our member variables for our inherited arrive algorithm....
		Arrive::Arrive(satRadius_, timeTo_);
		Arrive::SteeringHandler = SteeringHandler;


		//Set up our necessary member variables		WIP CHANGE PATH AND GRAPH!
		radius = satRadius_;
		path = new Path(path_);
		graph = graph_;
		
	}



	 SteeringOutput* getSteering(const float deltaTime) override
	 {
		 Vector2 target_position;

		 if (path->vectorList.empty()) return nullptr;

		 

		 target_position = path->getCurrentNodePosition(*graph);
		 SteeringHandler->setTargetLoc(target_position);

		 if (VMath::distance(SteeringHandler->getAIPos(), SteeringHandler->getTargetLoc()) <= radius)
		 {

			 // incremented for next steering request
			 

			 //Basically check if we can increment 1 more time before doing so this is weird since we are doing it backwords basically
			 if (0 < path->currentIndex - 1)
			 {
				 path->incrementCurrentNode(1);
			 }
			 else
			 {
				 std::cout << "This path has been found" << std::endl;
			 }

			 

		 }





		 SteeringHandler->setTargetLoc(target_position);


		 //getSteering(deltaTime);
		 //Send rest of stuff to arrive
		 return Arrive::getSteering(deltaTime);
	 }


	 

private:
	//Sat radius default same as arrive
	float radius = 10.0f;
	std::vector<std::vector<TileDemo*>>* graph;
	Path* path = nullptr;
};



#endif // !FOLLOWPATH_H
