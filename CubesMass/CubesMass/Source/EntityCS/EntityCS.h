#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>



//Forward declarations
class Component;
class Entity;




//Comppnent id is a unsigned int
using ComponentID = std::size_t;
//Used to give component id 

//Component ID getter
inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;

}

//This is only used internally
template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static_assert (std::is_base_of<Component, T>::value, "");
	static ComponentID typeID = getComponentTypeID();
	return typeID;


}
constexpr std::size_t maxComponents = 32;



//Look up c++ bitset to help understand this...
//Basically it stores bits with only 2 values true or false
//This is cause a bit is either a 1 or a 0 (On or off)
//This is an array of bits
using ComponentBitSet = std::bitset<maxComponents>;



using ComponentArray = std::array<Component*, maxComponents>;


class Component
{
public:
	Entity* entity;
	//Components will have a reference to what owns them


	virtual void Init() {}
	virtual void Update() {}
	virtual void Render() {}
	virtual void HandleEvents(const SDL_Event &sdlEvent){}
	virtual ~Component() {}
	
};
class Entity
{
private:
	bool Active = true;

	//a list of components that are attached to me!
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;


public:
	void Update()
	{
		//Go through list of components attached and call Update at every sequence
		for (auto& c : components) c->Update(); 
		

	}
	void Render() 
	{
		//Go through list of components attached and call Render at every sequence
		for (auto& c : components) c->Render();
	}
	void HandleEvents(const SDL_Event& sdlEvent) 
	{

		//Go through list of components attached and call HandleEvents at every sequence
		for (auto& c : components) c->HandleEvents(sdlEvent);
	}



	bool isActive() const { return Active; }
	void OnDestroy() { Active = false; }

	//Calls our getComponentTypeID and returns 
	template <typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>()];
		//Access a certain bit at[index] and will return if it is on 1 (true) or off 0 (false)
		//This is set via adding components checking this with no components will always be false


	}
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		//Still figuring this one out...
		//Creates our new Component
		T* comp(new T(std::forward<TArgs>(mArgs)...));

		//Sets components owner (Us)
		comp->entity = this;


		std::unique_ptr<Component> uPtr{ comp };



		//Places our component into the components vector list passes it uPtr since std::move argument is Args&&... args from T* comp
		//Look up std::vector::emplace_back() for docs
		components.emplace_back(std::move(uPtr));

		//Set component array at this typeID index to this component
		componentArray[getComponentTypeID<T>()] = comp;
		
		//Set the bitset to true at this TypeID index
		//Pretty sure this is so that all the same components will like transform will be at the same typeID
		componentBitSet[getComponentTypeID<T>()] = true;

		//Initialize component by calling its initialize function!
		comp->Init();
		

		//Return pointer to component
		return *comp;
	}
	
	template <typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
		//basically gets our component based off templace class given

	}


};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;
	//Holds a list of entities
public:
	void Update()
	{
		for (auto& e : entities)e->Update();
	}
	void Render()
	{
		for (auto& e : entities)e->Render();
	}
	void HandleEvenets(const SDL_Event& sdlEvent)
	{
		for (auto& e : entities)e->HandleEvents(sdlEvent);
	}

	void Refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &mEntity)
		{
			return !mEntity->isActive();
		}),
			std::end(entities));
	}
	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;

	}
};


