#ifndef CIRCLECOLLIDERCOMPONENT_H
#define CIRCLECOLLIDERCOMPONENT_H

#include "Components.h"
#include <string>

class CircleColliderComponent : public Component
{
public:


	Vector2 position;

	TransformComponent* transform = nullptr;
	float radius = 0; 
	const char* tag ="";
	//This is a very empty component since all it needs is a radius 
	//Mainly becuase there will not be a implemented offset and just use the transform position as the cirlces position



	CircleColliderComponent()
	{
		//Do nothing since nothing provided... most of our stuff will be in init anyway
	}
	CircleColliderComponent(const char* tag_)
	{
		tag = tag_;

	}
	void SetRadiusSize(float value_)
	{
		radius = value_;
	}

	void Init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}
	void Update(const float deltaTime) override
	{
		//Update nothing needs to happen here
		position.x = 32 + transform->position.x - Scene1::camera.x;
		position.y = 32 + transform->position.y - Scene1::camera.y;

	}
	void Render() override
	{
		DrawCircle(Scene1::renderer, position.x, position.y, radius);

	}


	//Courtesy of Microsoft :)
	void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
	{


		const int32_t diameter = (radius * 2);

		int32_t x = (radius - 1);
		int32_t y = 0;
		int32_t tx = 1;
		int32_t ty = 1;
		int32_t error = (tx - diameter);

		while (x >= y)
		{
			//  Each of the following renders an octant of the circle
			SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
			SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
			SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
			SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
			SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
			SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
			SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
			SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

			if (error <= 0)
			{
				++y;
				error += ty;
				ty += 2;
			}

			if (error > 0)
			{
				--x;
				tx += 2;
				error += (tx - diameter);
			}
		}
	}



};

#endif // !CIRCLECOLLIDERCOMPONENT_H
