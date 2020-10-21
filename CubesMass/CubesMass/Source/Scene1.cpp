#include <iostream>
#include "Scene1.h"
#include <SDL.h>
#include "EntityCS/Components.h"


Manager manager;
auto& newPlayer(manager.addEntity());

Scene1::Scene1(SDL_Renderer* renderer_)
{
	renderer = renderer_;
	
	//Grabbing renderer from the window class...
	//Will be inputted into the camera class
}


bool Scene1::OnCreate()
{

	newPlayer.addComponent<PositionComponent>();
	return true;
}

void Scene1::OnDestroy()
{
}

void Scene1::Update(const float deltaTime)
{

	manager.Update();
	std::cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;
}

void Scene1::Render() const
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	
}

void Scene1::HandleEvents(const SDL_Event& sdlEvent)
{
}
