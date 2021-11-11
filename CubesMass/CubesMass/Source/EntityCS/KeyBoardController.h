#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H
#include "Components.h"
class KeyBoardController : public Component
{
	//Basically a movement component via keyboard input//
	//RENDER FLIPPING DOESN'T WORK BECAUE OF DEPENDANT ON SPRITE COMPONENT EXISTING BEFORE INIT
private:
	MovementComponent* transform = nullptr;
	float speed = 0;
	Vector2 velocity = (0.f,0.f);
public:
	void Init() override
	{
		transform = &entity->getComponent<MovementComponent>();
	}
	void Update(const float deltaTime) override
	{
	}
	void HandleEvents(const SDL_Event &sdlEvent) override
	{
		//Look for better ways for handling input***

		//Eventually we need to use POLL EVENTS AND RE-DO 
		//Our handle events system completely will be annoying as hell




		//We could make our sdl_event from our scene 
		//A static event allowing us to access it hear instead of passing down
		//The event address..... but idk

		Vector2 tmp = transform->getVelocity();


		if (sdlEvent.type == SDL_KEYDOWN)
		{
			switch (sdlEvent.key.keysym.sym)
			{
			case SDLK_w:
				transform->setVelocity(Vector2(tmp.x,-150.f));
				break;
			case SDLK_s:
				transform->setVelocity(Vector2(tmp.x, 150.f));
				break;
			case SDLK_a:
				transform->setVelocity(Vector2(-150.0f, tmp.y));
				break;
			case SDLK_d:
				transform->setVelocity(Vector2(150.0f, tmp.y));
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
				transform->setVelocity(Vector2(tmp.x, 0.0f));
				break;
			case SDLK_s:
				transform->setVelocity(Vector2(tmp.x, 0.0f));
				break;
			case SDLK_a:
				transform->setVelocity(Vector2(0.0f, tmp.y));
				break;
			case SDLK_d:
				transform->setVelocity(Vector2(0.0f, tmp.y));
				break;
			case SDLK_ESCAPE:
				SDL_Quit();
			default:
				break;

			}
		}

	}
};
#endif // !KEYBOARDCONTROLLER_H
