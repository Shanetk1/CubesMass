#include <iostream>
#include "Scene1.h"
#include <SDL.h>
#include "EntityCS/Components.h"
#include "Map.h"
#include "Collision.h"

Map* mapTest;
const char* mapFile = "assets/32x32noBG.png";
SDL_Texture* tex_;


SDL_Renderer* Scene1::renderer = nullptr;


SDL_Rect Scene1::camera = { 0,0,800, 640 };//Used as our culling as well

Manager manager;


Entity& newPlayer(manager.addEntity());
Entity& wall(manager.addEntity());

auto& tiles(manager.getGroup(Scene1::groupMap));
auto& players(manager.getGroup(Scene1::groupPlayer));
auto& colliders(manager.getGroup(Scene1::groupColliders));
auto& projectiles(manager.getGroup(Scene1::groupProjectiles));

Scene1::Scene1(SDL_Renderer* renderer_)
{
	renderer = renderer_;
}


bool Scene1::OnCreate()
{
	//Load our tileset here to when we parse our map file we send it the loaded texture address to create
	//Every single tile component
	tex_ = TextureLoader::LoadTexture(mapFile);

	mapTest = new Map();
	mapTest->loadMap("assets/map.txt", 25.f, 20.f);

	newPlayer.addComponent<TransformComponent>(Vector2(400.f, 320.f), Vector2(1.f,1.f));
	newPlayer.addComponent<SpriteComponent>("assets/download.png", true);

	newPlayer.addComponent<KeyBoardController>();
	newPlayer.addComponent<ColliderComponent>("player");
	newPlayer.getComponent<ColliderComponent>().setColliderSize(64.f, 64.f);
	newPlayer.addGroup(groupPlayer);

	wall.addComponent<TransformComponent>(Vector2(300.f,300.f), Vector2(1.f,1.f));
	wall.addComponent<SpriteComponent>("assets/dirt.png");
	wall.getComponent<SpriteComponent>().setSize(300.f, 20.f);
	wall.addComponent<ColliderComponent>("wall");
	wall.getComponent<ColliderComponent>().setColliderSize(300.f, 20.f);
	wall.addGroup(groupPlayer);



	

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
	Vector2 playerPos = newPlayer.getComponent<TransformComponent>().position;
	manager.Refresh();
	manager.Update();



	camera.x = newPlayer.getComponent<TransformComponent>().position.x - 400;
	camera.y = newPlayer.getComponent<TransformComponent>().position.y - 320;
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > camera.w)
	{
		camera.x = camera.w;
	}
	if (camera.y > camera.h)
	{
		camera.y = camera.h;
	}

	for (auto& c : colliders)
	{
		if (Collision::AABB(newPlayer.getComponent<ColliderComponent>().collider, c->getComponent<ColliderComponent>().collider))
		{
			newPlayer.getComponent<TransformComponent>().position = playerPos;
		}
	}




	
}

void Scene1::Render() const
{
	SDL_RenderClear(renderer);

	//If this obj.x < camera.x && obj.x > camera.x 
	//&& obj.y < camera.y && obj.y > camera.y


	//Need to cycle through all objs but for now just tiles
	
	
	for (auto& t : tiles)
	{
		//This is some really basic culling idk if its good but it works, to test put the 74 numbers to 0
		float x = t->getComponent<TileComponent>().position.x;
		float y = t->getComponent<TileComponent>().position.y;
		if ((x <= camera.x + camera.w && x + 0 >= camera.x && y <= camera.y + camera.h && y + 0 >= camera.y))
		{
			t->Render();
		}

	}
	for (auto& p : players)
	{
		p->Render();
	}
	for (auto& p : projectiles)
	{
		p->Render();
	}

	//Necessary at end
	SDL_RenderPresent(renderer);
}

void Scene1::HandleEvents(const SDL_Event& sdlEvent)
{
	manager.HandleEvenets(sdlEvent);
}


void Scene1::addTile(int srcX, int srcY, int xPos, int yPos, int coll)
{

	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xPos, yPos, tex_);
	if (coll > 0)
	{
		//Adding colliders to this is awkward because we need them to have a transform position
		tile.addComponent<TransformComponent>(Vector2(xPos, yPos), Vector2(1.f,1.f));
		tile.addComponent<ColliderComponent>("Collider help");
		tile.getComponent<ColliderComponent>().setColliderSize(64.f, 64.f);
		tile.addGroup(groupColliders);
	}

	tile.addGroup(groupMap);
}