#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include <SDL.h>
#include "../Scene1.h"
#include "../Animation.h"
#include <map>


class SpriteComponent : public Component
{
private:
	TransformComponent* transform = nullptr;
	SDL_Texture* texture;
	SDL_Rect sRect, dRect;


	bool animated = false;
	int frames = 0;
	int speed = 100;


public:
	int height = 0;
	int width = 0;
	int animIndex = 0;

	std::map<const char*, Animation> animations;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SpriteComponent() = default;
	SpriteComponent(const char* fileName) 
	{
		//Default h,w to 32 pixels to actually render something
		height = 32;
		width = 32;
		setTexture(fileName);
		
	}

	SpriteComponent(const char* fileName, int index_, int speed_, int frames_) //This MUST ALWAYS be the idle animation
	{
		//I dont like this rather, I want to send it parameters necessary for animation...

		//COMPLETELY BROKEN DONT USE


		animated = true;

		Animation idle = Animation(index_, speed_, frames_);




		//Animation idle = Animation(2, 200, 7);
		//Animation walkRight = Animation(11, 100, 9);
		//Animation walkUp = Animation(8, 100, 9);
		//Animation walkDown = Animation(10, 100, 9);
		//Animation walkAngled = Animation(11, 100, 9);

		animations.emplace("Idle",idle);

		//animations.emplace("WalkRight", walkRight);
		//animations.emplace("WalkUp", walkUp);
		//animations.emplace("WalkDown", walkDown);
		//animations.emplace("WalkAngled", walkAngled);
		height = 64;
		width = 64;
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
		sRect.w = width;
		sRect.h = height;
	}
	void Init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sRect.x = sRect.y = 0;
		sRect.w = width;
		sRect.h = height;



	}
	void Update(const float deltaTime) override
	{
		if (animated)
		{
			sRect.x = dRect.w * ((SDL_GetTicks() / speed) % frames);
			sRect.y = animIndex * sRect.h;
		}
		//Because sdl rect val's are integer
		dRect.x = (int)transform->position.x - Scene1::camera.x;
		dRect.y = (int)transform->position.y - Scene1::camera.y;
		dRect.w = sRect.w * transform->scale.x;
		dRect.h = sRect.h * transform->scale.y;
		

		/*
		if (transform->velocity.x == 0 && transform->velocity.y == 0)
		{
			Play("Idle");
		}

		if (transform->velocity.x > 0)
		{
			flip = SDL_FLIP_NONE;
			Play("WalkRight");
		}
		else if (transform->velocity.x < 0)
		{
			flip = SDL_FLIP_HORIZONTAL;
			Play("WalkRight");

		}

		if (transform->velocity.y > 0)
		{
			Play("WalkDown");
			flip = SDL_FLIP_NONE;

		}
		else if (transform->velocity.y < 0)
		{
			Play("WalkUp");
			flip = SDL_FLIP_NONE;
		}


		*/
	}
	void Render() override
	{
		TextureLoader::Draw(texture, sRect, dRect, transform->orientation, flip);
	}
	void Play(const char* animName)
	{
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}
};






#endif // !SPRITECOMPONENT_H
