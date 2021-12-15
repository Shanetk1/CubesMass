#include <iostream>
#include "Scene1.h"
#include <SDL.h>
#include "EntityCS/Components.h"
#include "Collision.h"
#include "AI/Pathfinding/Graph/TileDemo.h"

const char* mapFile = "assets/32x32noBG.png";
SDL_Texture* tex_;


SDL_Renderer* Scene1::renderer = nullptr;

Vector2 Scene1::playerPosition = Vector2(0.f);

SDL_Rect Scene1::camera = { 0,0,800, 640 };//Used as our culling as well

Manager manager;



Entity& newPlayer(manager.addEntity());
Entity& AITest(manager.addEntity());

auto& tiles(manager.getGroup(Scene1::groupMap));
auto& players(manager.getGroup(Scene1::groupPlayer));
auto& colliders(manager.getGroup(Scene1::groupColliders));
auto& projectiles(manager.getGroup(Scene1::groupProjectiles));

Scene1::Scene1(SDL_Renderer* renderer_): map(nullptr), graphLevel(nullptr)
{
	renderer = renderer_;
	
}


bool Scene1::OnCreate()
{
	tex_ = TextureLoader::LoadTexture(mapFile);

	//Our map will load our tilemap and crete our tilemap to use with our pathfinding algorithms.... //POINTER ON THIS MAY OR MAY NOT BE CAUSING A DATA LEAK//
	map = new Map();

	//Dummy initialization
	std::vector<TileDemo*> tiles;
	tiles = map->loadMap("assets/map.txt", 25, 20);

	//Maybe make a constant of max map size....
	//If I just loop through 



	//Set up our graph here
	graphLevel = new Graph(25 * 20);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int currNode = (j) + (i * 25);
			//std::cout << currNode << std::endl;

			//Checks to see if our tiles are traversable this value is set via the map.txt file and loaded up on Map::loadMap();
			if (tiles[currNode]->getCanTraverse())
			{

				//Left connections
				if (i > 0)
				{

					graphLevel->addWeightedConnection(tiles[currNode]->getNode(), tiles[currNode - 1]->getNode(), 64.0f);
				}

				//Right connections
				if (i < 20 - 1)
				{
					graphLevel->addWeightedConnection(tiles[currNode]->getNode(), tiles[currNode + 1]->getNode(), 64.0f);
				}

				//Up connections
				if (j > 0)
				{
					graphLevel->addWeightedConnection(tiles[currNode]->getNode(), tiles[currNode - (25)]->getNode(), 64.0f);
				}

				//Down connections
				if (j < 25 - 1)
				{
					graphLevel->addWeightedConnection(tiles[currNode]->getNode(), tiles[currNode + (25)]->getNode(), 64.0f);
				}

			}
		}
	}
	//Adds our game world to our graph... our graph now will hold a reference to the game world so make it just overall easier to operate..
	//There is something wierd here with how this is being passed LOOK HERE FOR ANY MAP BUGSSS!!!

	//std::vector<TileDemo*>* tiles2 = new std::vector<TileDemo*>();
	//tiles2 = &tiles;


	graphLevel->addGameWorld(tiles);







	newPlayer.addComponent<TransformComponent>(Vector2(400.f, 320.f), Vector2(1.f,1.f));
	newPlayer.addComponent<MovementComponent>(true);
	newPlayer.addComponent<SpriteComponent>("assets/player/player_9mmhandgun.png");
	newPlayer.getComponent<SpriteComponent>().setSize(60, 66);
	newPlayer.addComponent<KeyBoardController>();
	newPlayer.addComponent<BoxColliderComponent>("player");
	newPlayer.getComponent<BoxColliderComponent>().setColliderSize(64.f, 64.f);
	newPlayer.addGroup(groupPlayer);


	//AI Populate
	AITest.addComponent<TransformComponent>(Vector2(64.f, 64.f), Vector2(1.f, 1.f));
	AITest.addComponent<MovementComponent>();
	AITest.addComponent<SpriteComponent>("assets/player/player_9mmhandgun.png");
	AITest.getComponent<SpriteComponent>().setSize(60, 66);

	AITest.addComponent<CircleColliderComponent>("AIPerception");
	AITest.getComponent<CircleColliderComponent>().SetRadiusSize(100.0f);




	//Gives ai information about map and nodes... Bad overall but it gets the pathfinding working...
	AITest.addComponent<AIController>(graphLevel);
	AITest.addGroup(groupPlayer);

	return true;
}
void Scene1::OnDestroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	delete renderer;
}


//NOTE MAP SIZE IS ; WIDTH = 1600,
void Scene1::Update(const float deltaTime)
{
	//Beginning of every frame update world information...
	//I dont think this is necessary creating something where this will update once every 30 frames is more ideal....
	

	Vector2 playerPos = newPlayer.getComponent<TransformComponent>().position;
	Scene1::playerPosition = playerPos;

	manager.Refresh();
	manager.Update(deltaTime);


	camera.x = newPlayer.getComponent<TransformComponent>().position.x - 400;
	camera.y = newPlayer.getComponent<TransformComponent>().position.y - 320;
	
	//Map bounds....
	//startpos; 0, 0
	//height =
	
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
		if (Collision::AABB(newPlayer.getComponent<BoxColliderComponent>().collider, c->getComponent<BoxColliderComponent>().collider))
		{
			newPlayer.getComponent<TransformComponent>().position = playerPos;
		}

		

	}

	//std::cout << "Player orientation; " << newPlayer.getComponent<TransformComponent>().orientation << std::endl;





	SDL_Rect tmp = newPlayer.getComponent<BoxColliderComponent>().collider;
	Vector2 tmpC = AITest.getComponent<CircleColliderComponent>().position;
	float rad = AITest.getComponent<CircleColliderComponent>().radius;
	if (Collision::CircleRect(tmpC.x, tmpC.y, rad, tmp.x, tmp.y, tmp.w, tmp.h))
	{
		//Super scuffed if value but whatever
		//Need to continually check since this is between player and AI eventually make this only scroll through the list of AI grouped entities!
		AITest.getComponent<AIController>().myInfo->setSeesPlayer(true);


	}
	else
	{

		AITest.getComponent<AIController>().myInfo->setSeesPlayer(false);

	}
}

void Scene1::Render() const
{
	SDL_RenderClear(renderer);

	//If this obj.x < camera.x && obj.x > camera.x 
	//&& obj.y < camera.y && obj.y > camera.y


	//Need to cycle through all objs but for now just tiles
	


	//tiles->Render(renderer);





	for (auto& t : tiles)
	{
		//This is some really basic culling idk if its good but it works, to test put the 74 numbers to 0
		float x = t->getComponent<TileComponent>().position.x;
		float y = t->getComponent<TileComponent>().position.y;
		if ((x <= camera.x + camera.w && x + 0 >= camera.x && y <= camera.y + camera.h && y + 0 >= camera.y))
		{
			//t->Render();
		}
		//t->Render();

	}
	for (int i = 0; i < tiles.size(); i++)
	{

		tiles[i]->Render();

	/*	for (int j = 0; j < tiles_[i].size(); j++)
		{
			tiles_[i][j]->Render(renderer, 64, 64);
		}*/

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
		tile.addComponent<BoxColliderComponent>("Collider help");
		tile.getComponent<BoxColliderComponent>().setColliderSize(64.f, 64.f);
		tile.addGroup(groupColliders);
	}

	tile.addGroup(groupMap);
}