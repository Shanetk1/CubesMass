#include "Scene1.h"
#include <SDL.h>
#include "GameObject.h"

Scene1::Scene1(SDL_Renderer* renderer_)
{
	renderer = renderer_;
	
	//Grabbing renderer from the window class...
	//Will be inputted into the camera class
}


bool Scene1::OnCreate()
{
	player = new GameObject("jetski.bmp", renderer, 0.f, 0.f);


	return true;
}

void Scene1::OnDestroy()
{
	if (player) delete player;
	player = nullptr;
}

void Scene1::Update(const float deltaTime)
{
	player->Update();


}

void Scene1::Render() const
{
	SDL_RenderClear(renderer);
	player->Render();
	SDL_RenderPresent(renderer);

	
}

void Scene1::HandleEvents(const SDL_Event& sdlEvent)
{
}
