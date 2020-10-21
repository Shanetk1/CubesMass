#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H




#include "Components.h"
#include <SDL.h>

class SpriteComponent : public Component
{


private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent();
	SpriteComponent(const char* fileName);

	void Init() override
	{
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;

	}
	void Update() override
	{

		destRect.y = position->y();
		destRect.x = position->x();

	}
	void Render() override
	{
		//TextureLoader::LoadTexture();
	}



public:

};






#endif // !SPRITECOMPONENT_H
