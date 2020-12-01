#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "Components.h"
#include <SDL.h>
class TileComponent : public Component
{
public: 
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	char* path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id)
	{
		tileRect.x = x;

		tileRect.y = y;

		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID)
		{
		case 0: 
			path = ("assets/water.png");
			break;
		case 1:
			path = ("assets/grass.png");
			break;
		case 2:
			path = ("assets/dirt.png");
			break;
		default:
			break;
		}

	}


	void Init() override
	{
		entity->addComponent<TransformComponent>(Vector2(tileRect.x, tileRect.y), Vector2(1.f, 1.f));
		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);
		sprite = &entity->getComponent<SpriteComponent>();
	}
};


#endif // !TILECOMPONENT_H
