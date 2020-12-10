#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include "Components.h"
class KeyBoardController : public Component
{
	//Basically a movement component via keyboard input//

	//RENDER FLIPPING DOESN'T WORK BECAUE OF DEPENDANT ON SPRITE COMPONENT EXISTING BEFORE INIT

private:
	TransformComponent* transform;
	float speed;
	Vector2 velocity;

	SpriteComponent* sprite;
public:
	void Init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
		velocity = Vector2(0.f);
		speed = 3.0f;
	}
	void Update() override
	{
		transform->position.x += velocity.x * speed;
		transform->position.y += velocity.y * speed;
	}
	void HandleEvents(const SDL_Event &sdlEvent) override
	{
		//Look for better ways for handling input***

		//Eventually we need to use POLL EVENTS AND RE-DO 
		//Our handle events system completely will be annoying as hell




		//We could make our sdl_event from our scene 
		//A static event allowing us to access it hear instead of passing down
		//The event address..... but idk
		if (sdlEvent.type == SDL_KEYDOWN)
		{
			switch (sdlEvent.key.keysym.sym)
			{
			case SDLK_w:
				velocity.y = -1;
				break;
			case SDLK_s:
				velocity.y = 1;
				break;
			case SDLK_a:
				velocity.x = -1;
				sprite->flip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_d:
				velocity.x = 1;
				break;
				default:
					break;
			}
		}

		if (sdlEvent.type == SDL_KEYUP)
		{
		
			switch (sdlEvent.key.keysym.sym)
			{
			case SDLK_w:
				velocity.y = 0;
				break;
			case SDLK_s:
				velocity.y = 0;
				break;
			case SDLK_a:
				velocity.x = 0;
				sprite->flip = SDL_FLIP_NONE;
				break;
			case SDLK_d:
				velocity.x = 0;
				break;
			default:
				break;

			}
		}

	}
};
#endif // !KEYBOARDCONTROLLER_H
