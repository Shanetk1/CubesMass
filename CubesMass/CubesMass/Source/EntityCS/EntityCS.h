#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

//This I got from a tutorial but holy fuck its confusing,
//I'm gonna go through it later and try to comment everything to explain it



class Component;
class Entity;

//Comppnent id is a unsigned int
using ComponentID = std::size_t;

//Component ID getter
inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;

}
template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static_assert (std::is_base_of<Component, T>::value, "");
	static ComponentID typeID = getComponentTypeID();
	return typeID;


}
constexpr std::size_t maxComponents = 32;


using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;


class Component
{
public:
	Entity* entity;

	virtual void Init() {}
	virtual void Update() {}
	virtual void Render() {}
	virtual ~Component() {}
};
class Entity
{
private:
	bool Active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;


public:
	void Update()
	{
		for (auto& c : components) c->Update(); 
		

	}
	void Render() 
	{
		for (auto& c : components) c->Render();
	}
	bool isActive() const { return Active; }
	void OnDestroy() { Active = false; }

	template <typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>()];
	}
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* comp(new T(std::forward<TArgs>(mArgs)...));
		comp->entity = this;
		std::unique_ptr<Component> uPtr{ comp };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = comp;
		componentBitSet[getComponentTypeID<T>()] = true;

		comp->Init();
		return *comp;
	}
	
	template <typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);

	}


};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void Update()
	{
		for (auto& e : entities)e->Update();
	}
	void Render()
	{
		for (auto& e : entities)e->Render();
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


