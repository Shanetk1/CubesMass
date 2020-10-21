#include <iostream>
#include "Scene1.h"
#include <SDL.h>
#include "EntityCS/Components.h"


SDL_Renderer* Scene1::renderer = nullptr;



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
	newPlayer.addComponent<SpriteComponent>("assets/Wooo.png");
	return true;
}

void Scene1::OnDestroy()
{
}

void Scene1::Update(const float deltaTime)
{

	manager.Refresh();
	manager.Update();



	newPlayer.getComponent<PositionComponent>().position.Add(Vector2(2.0f,0.f));

	if (newPlayer.getComponent<PositionComponent>().position.x > 100)
	{
		newPlayer.getComponent<SpriteComponent>().setTexture("assets/Panda.png");
	}

}

void Scene1::Render() const
{
	//Necessary at the beginning 
	SDL_RenderClear(renderer);

	manager.Render();
	
	
	

	//Necessary at end
	SDL_RenderPresent(renderer);
}

void Scene1::HandleEvents(const SDL_Event& sdlEvent)
{
	
}
