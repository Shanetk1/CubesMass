#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H




#include "Components.h"
#include <SDL.h>
#include "../TextureLoader.h"


class SpriteComponent : public Component
{


private:
	PositionComponent* positionComp;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* fileName) 
	{

		setTexture(fileName);
	};
	//Function looks bad but used to change texture on the fly, and used by constructor
	void setTexture(const char* fileName)
	{
		
		texture = TextureLoader::LoadTexture(fileName);
	}
	void Init() override
	{
		positionComp = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;

	}
	void Update() override
	{

		//Because sdl rect val's are integer
		destRect.y = (int)positionComp->position.x;
		destRect.x = (int)positionComp->position.y;

	}
	void Render() override
	{
		TextureLoader::Draw(texture, srcRect, destRect);
	}



public:

};






#endif // !SPRITECOMPONENT_H
