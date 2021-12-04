#ifndef FOLLOWPATH_H
#define FOLLOWPATH_H

#include "arrive.h"
#include "../VMath.h"
#include "BlendedSteering.h"
#include "Pathfinding/Graph/Path.h"

using namespace MATH;

//I like following being sent a path but idk....
//Maybe allow graph to create a pa

class Graph;

class FollowPath : public Arrive
{
public:
	//Don't use this ever it will break the entire class
	FollowPath()
	{

	}
	//Pass in our graph address also our path.... or we could actually specify a location rather a node instead..... and then use the graph to calculate closest nodes to location then create a path from that....
	FollowPath(float satRadius_, float timeTo_, std::vector<TileDemo*> path_) : Arrive(satRadius_, timeTo_)
	{
		//Personally I think a path of tiledemos works better here.....
		//The path instead could be the tilemap nodes....
		//I set time to so it sets the inherited arrives time to....

		//Arrive 
		//Arrive::setSatRadius(satRadius_);
		//Arrive::setTimeTo(timeTo_);
		Arrive::SteeringHandler = SteeringHandler;




		//Set up our necessary member variables		WIP CHANGE PATH AND GRAPH!
		radius = satRadius_;
		path = new Path(path_);
		//graph = &graph_;
		
	}



	 SteeringOutput* getSteering(const float deltaTime) override
	 {
		 Vector2 target_position;

		 if (path->vectorList.empty()) return nullptr;

		 

		 target_position = path->getCurrentNodePosition();
		 SteeringHandler->setTargetLoc(target_position);

		 if (VMath::distance(SteeringHandler->getAIPos(), SteeringHandler->getTargetLoc()) <= radius)
		 {
			 if (0 < path->currentIndex - 1)
			 {
				 path->decrementCurrentNode(1);
			 }
			 else
			 {
				 //std::cout << "This path has been found" << std::endl;
				 
				 std::vector<TileDemo*> newPath;
				 for (int i = path->vectorList.size() - 1; i >= 0; i--)
				 {
					 newPath.push_back(path->vectorList[i]);
					 //std::cout << path->vectorList[i]->getNode() << std::endl;
				 }
				 path->vectorList = newPath;
				 path->currentIndex = path->vectorList.size() - 1;



				 //Now reverse the path so increment other way until the end...
				 //Nothing happens after path is found... maybe we set this steering to inactive? or loop.....
			 }

			 

		 }





		 SteeringHandler->setTargetLoc(target_position);
		 return Arrive::getSteering(deltaTime);
	 }


	 

private:
	//Sat radius default same as arrive
	float radius = 10.0f;
	Path* path = nullptr;
};



#endif // !FOLLOWPATH_H
