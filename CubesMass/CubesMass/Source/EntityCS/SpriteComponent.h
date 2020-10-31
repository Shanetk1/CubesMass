#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include <SDL.h>
#include "../TextureLoader.h"
#include "../Scene1.h"


class SpriteComponent : public Component
{
public:
	int height = 0;
	int width = 0;


private:
	TransformComponent* TransformComp;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;


public:
	SpriteComponent() = default;
	SpriteComponent(const char* fileName) 
	{
		//Default h,w to 32 pixels to actually render something
		height = 64;
		width = 64;
		setTexture(fileName);
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	//Change texture should be used to update to a NEW texture
	void setTexture(const char* fileName)
	{
		
		texture = TextureLoader::LoadTexture(fileName);
	}

	void setSize(int height_, int width_)
	{
		height = height_;
		width = width_;

		//Update our square only need to do here cause doing in update would be unnecessary
		srcRect.w = width;
		srcRect.h = height;


	}
	void Init() override
	{
		TransformComp = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = width;
		srcRect.h = height;
	

	}
	void Update() override
	{
		
		//Because sdl rect val's are integer
		destRect.x = (int)TransformComp->position.x;
		destRect.y = (int)TransformComp->position.y;
		destRect.w = srcRect.w * TransformComp->scale.x;
		destRect.h = srcRect.h * TransformComp->scale.y;


	}
	void Render() override
	{
		TextureLoader::Draw(texture, srcRect, destRect);
	}



public:

};






#endif // !SPRITECOMPONENT_H
