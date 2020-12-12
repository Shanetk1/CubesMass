#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include <SDL.h>
#include "../TextureLoader.h"
#include "../Scene1.h"
#include "../Animation.h"
#include <map>


class SpriteComponent : public Component
{
public:
	int height = 0;
	int width = 0;
	int animIndex = 0;

	std::map<const char*, Animation> animations;
	SDL_RendererFlip flip = SDL_FLIP_NONE;


private:
	TransformComponent* TransformComp;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	

	bool animated = false;
	int frames = 0;
	int speed = 100;



public:
	SpriteComponent() = default;
	SpriteComponent(const char* fileName) 
	{
		//Default h,w to 32 pixels to actually render something
		height = 32;
		width = 32;
		setTexture(fileName);
	}
	SpriteComponent(const char* fileName, bool animated_)
	{
		//Default h,w to 32 pixels to actually render something
		animated = animated_;

		Animation idle = Animation(0, 100, 3);


		animations.emplace("Idle",idle);

		height = 32;
		width = 32;

		Play("Idle");

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
		
		if (animated)
		{
			srcRect.x = destRect.w * ((SDL_GetTicks() / speed) % frames);
			srcRect.y = animIndex * srcRect.h;
		}

		

		//Because sdl rect val's are integer
		destRect.x = (int)TransformComp->position.x - Scene1::camera.x;
		destRect.y = (int)TransformComp->position.y - Scene1::camera.y;
		destRect.w = srcRect.w * TransformComp->scale.x;
		destRect.h = srcRect.h * TransformComp->scale.y;

	}
	void Render() override
	{
		TextureLoader::Draw(texture, srcRect, destRect, flip);
	}
	void Play(const char* animName)
	{
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}



public:

};






#endif // !SPRITECOMPONENT_H
