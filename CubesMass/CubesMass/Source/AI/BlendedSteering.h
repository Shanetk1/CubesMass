#ifndef BLENDEDSTEERING_H
#define BLENDEDSTEERING_H

//Steering algorithm class with all classes of algorithms for steering....?
#include <vector>
#include <memory>
#include <stdio.h>
#include <bitset>
#include <array>



#include "../Vector.h"
#include "Steering.h"
#include "Pathfinding/Graph/TileDemo.h"

class Steering;
class TileDemo;

//This class will not be inherited by steering, since well wait.... maybe it should cause it does have a getsteering pog that fixes it
//I kinda want to use this as a container class...
//Want to add steering to the vector and this class handles all the steering...
//AICONTROLLER will be the one adding the algorithms this will do the rest 


//I want blended steering to kind of work like a container class, which will be added to the aicontroller..
//The ai controllers job is then to add algorithms, steering outputs to the algorithm list and pop them accordingly...
constexpr std::size_t maxAlgorithms = 10;

//This is only used internally
using AlgorithmID = std::size_t;
using AlgorithmBitSet = std::bitset<maxAlgorithms>;
using AlgorithmArray = std::array <Steering*, maxAlgorithms> ;



inline AlgorithmID getNewAlgorithmTypeID()
{
	//u means unsigned
	static AlgorithmID lastID = 0u;
	return lastID++;
}

template <typename T> inline AlgorithmID getAlgorithmTypeID() noexcept
{
	static_assert (std::is_base_of<Steering, T>::value, "");
	static AlgorithmID typeID = getNewAlgorithmTypeID();
	return typeID;
}


class BlendedSteering
{
private:

	//Global accessed variable, These variables are necessary for most if not all AI algorithms for steering therefore will be stored here so that we can easily access them
	Vector2 targetLocation, aiPos = Vector2(0.0f);
	float mSpeed = 50.0f;





















public:
	struct BehaviourAndWeight
	{
		float weight;
		SteeringOutput val;
	};
	std::vector<std::unique_ptr<Steering>> algorithms;
	



	AlgorithmArray algorithmArray;
	AlgorithmBitSet algorithmBitSet;

	BlendedSteering();
	BlendedSteering(Vector2 targetLoc_, Vector2 aiPos_, float mSpeed_);


	~BlendedSteering();

	//Updates our algorithms, adding them all together and returning the result
	SteeringOutput updateAlgorithms(const float deltaTime);




	//Setters
	void setTargetLoc(Vector2 targetLoc_) {targetLocation = targetLoc_;}
	void setAIPos(Vector2 aiPos_) { aiPos = aiPos_; }


	//Setters and getters
	void setMaxSpeed(float mSpeed_) { mSpeed = mSpeed_; }
	void updateUpdatables(Vector2 targetLoc_, Vector2 aiPos_) { targetLocation = targetLoc_; aiPos = aiPos_; }

	Vector2 getTargetLoc() { return targetLocation; }
	Vector2 getAIPos() { return aiPos; }
	float getMaxSpeed() { return mSpeed; }
	

	//Ugly template things 
	template <typename T, typename... TArgs>
	T& addSteering(TArgs&&... mArgs)
	{
		//Still figuring this one out...
		//Creates our new Component
		T* comp(new T(std::forward<TArgs>(mArgs)...));

		//Sets components owner (Us)
		comp->SteeringHandler = this;


		//std::vector<SteeringAlgorithm*> uPtr{ comp };
		std::unique_ptr<Steering> uPtr{ comp };



		//Places our component into the components vector list passes it uPtr since std::move argument is Args&&... args from T* comp
		//Look up std::vector::emplace_back() for docs
		//algorithms.emplace_back(comp);

		algorithms.emplace_back(std::move(uPtr));

		//Set component array at this typeID index to this component
		algorithmArray[getAlgorithmTypeID<T>()] = comp;

		//Set the bitset to true at this TypeID index
		//Pretty sure this is so that all the same components will like transform will be at the same typeID
		algorithmBitSet[getAlgorithmTypeID<T>()] = true;

		//Initialize component by calling its initialize function!
		//comp->Init();
		//This is due to change...
		
		//Return pointer to component
		//std::cout << *comp <<  std::endl;
		return *comp;
	}
	template <typename T> T& getAlgorithm() const
	{
		auto ptr(algorithmArray[getAlgorithmTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

};



#endif // BLENDEDSTEERING_H
 