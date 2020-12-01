#include <iostream>
#include "Scene1.h"
#include <SDL.h>
#include "EntityCS/Components.h"
#include "Camera.h"
#include "Map.h"
#include "Collision.h"
Map* mapTest;

SDL_Renderer* Scene1::renderer = nullptr;

//Camera is just a rectangle basically 
SDL_Rect Scene1::camera = { 0,0,800, 640 };


//Our entity manager (For components+entities)
//This updates, renders our components
Manager manager;


//auto& newPlayer(manager.addEntity());

//Entities hold are our baseline for creating gameObjects
//Every Entity is rendered, updated and you can add      
//Components to entities to create functionality
Entity& newPlayer(manager.addEntity());
Entity& wall(manager.addEntity());

enum groupList
{
	groupPlayer
};


Scene1::Scene1(SDL_Renderer* renderer_)
{
	//
	renderer = renderer_;

	

}


bool Scene1::OnCreate()
{
	//This is our initialization where everything will load in, and be set up







	//Adding components to objects can be done onCreate ideally but also in Update if necessary
	newPlayer.addComponent<TransformComponent>();
	newPlayer.addComponent<SpriteComponent>("assets/Wooo.png");
	newPlayer.addComponent<KeyBoardController>();
	newPlayer.addComponent<ColliderComponent>("player");
	newPlayer.getComponent<ColliderComponent>().setColliderSize(32.f, 32.f);
	//newPlayer.addGroup(groupPlayer);
	//newPlayer.addComponent<TransformComponent, SpriteComponent, KeyBoardController, ColliderComponent>();
	//***Note on the order of which they are added is important!!!!!!***\\

	newPlayer.getComponent<ColliderComponent>();


	wall.addComponent<TransformComponent>(Vector2(300.f,300.f), Vector2(1.f,1.f));
	wall.addComponent<SpriteComponent>("assets/dirt.png");
	wall.getComponent<SpriteComponent>().setSize(300.f, 20.f);
	wall.addComponent<ColliderComponent>("wall");
	wall.getComponent<ColliderComponent>().setColliderSize(300.f, 20.f);


	//wall.getComponent<TransformComponent>().setScale(Vector2(2.f, 2.f));
	//This value shouldnt just return true but I'm lazy sooo I'll change this later

	//Add asset of map and size of map 16x16, 64x 64, etc
	//mapTest = new Map();
	//Map::loadMap();
	return true;
}

void Scene1::OnDestroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	delete renderer;
}

void Scene1::Update(const float deltaTime)
{
	//Updates all our entities and all their attached components
	manager.Refresh();
	manager.Update();
	


	//Below you add logic to the game example below will change sprite once player reaches a certain position


	//instead of getting component every time you can store this value below are 2 ways of doing this
	//auto& myComp= newPlayer.getComponent<TransformComponent>();
	//TransformComponent& transform = newPlayer.getComponent<TransformComponent>();
	//Use this way though it is much more clear compared to the auto& version
	
	if (newPlayer.hasComponent<TransformComponent>())
	{
		//printf("true");
	}



	if (Collision::AABB(newPlayer.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider))
	{
		printf("wall hit!!!!!");
	}





}

auto& player(manager.getGroup(groupPlayer));
void Scene1::Render() const
{
	//Necessary at the beginning 
	SDL_RenderClear(renderer);

	//Renders all our entities attached components
	manager.Render();
	
	for (auto& p : player)
	{
		p->Render();
	}


	//Necessary at end
	SDL_RenderPresent(renderer);
}

void Scene1::HandleEvents(const SDL_Event& sdlEvent)
{

	//This might change cause I don't like current input handling
	manager.HandleEvenets(sdlEvent);
	//But for now it will do



	//Basically all our components with handle events will react to this





}


void Scene1::addTile(int id, int x, int y)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x,y, 32, 32, id);
}