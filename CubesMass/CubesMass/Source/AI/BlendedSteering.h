#ifndef BLENDEDSTEERING_H
#define BLENDEDSTEERING_H

//Steering algorithm class with all classes of algorithms for steering....?
#include "Steering.h"
#include <vector>
#include "SteeringAlgorithm.h"
#include <memory>
#include <stdio.h>
#include <bitset>
#include <array>
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
using AlgorithmArray = std::array <SteeringAlgorithm*, maxAlgorithms> ;



inline AlgorithmID getNewAlgorithmTypeID()
{
	//u means unsigned
	static AlgorithmID lastID = 0u;
	return lastID++;
}

template <typename T> inline AlgorithmID getAlgorithmTypeID() noexcept
{
	static_assert (std::is_base_of<SteeringAlgorithm, T>::value, "");
	static AlgorithmID typeID = getNewAlgorithmTypeID();
	return typeID;
}


class BlendedSteering : public Steering
{
public:
	struct BehaviourAndWeight
	{
		float weight;
		SteeringOutput val;
	};
	std::vector<std::unique_ptr<SteeringAlgorithm>> algorithms;
	
	float mSpeed;
	float mAngle;


	AlgorithmArray algorithmArray;
	AlgorithmBitSet algorithmBitSet;

	BlendedSteering();
	~BlendedSteering();

	//This might be created for every AIComponent... this is since it will hold all steering that is effecting the ai


	//This will go through all our stored algorithms
	SteeringOutput getSteering() override;
	



	//Ugly template things 
	template <typename T, typename... TArgs>
	T& addSteering(TArgs&&... mArgs)
	{
		//Still figuring this one out...
		//Creates our new Component
		T* comp(new T(std::forward<TArgs>(mArgs)...));

		//Sets components owner (Us)
		//comp->entity = this;


		//std::vector<SteeringAlgorithm*> uPtr{ comp };
		std::unique_ptr<SteeringAlgorithm> uPtr{ comp };



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
		comp->Init();

		
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
 