#ifndef COLLIDERCOMPONENT_h
#define COLLIDERCOMPONENT_h

#include "Components.h"
#include <string>
#include <SDL.h>
#include "../Scene1.h"
#include "TileComponent.h"
class ColliderComponent : public Component
{

public:

	SDL_Rect collider;
	//Used to check what we hit an (identifier)
	std::string tag = "";
	TransformComponent* transform = nullptr;
	SpriteComponent* sprite = nullptr;
	bool debug = true;
	int height, width = 0;

	ColliderComponent() = default;
	ColliderComponent(std::string tag_)
	{
		tag = tag_;
	}
	void setColliderSize(int height_, int width_)
	{
		height = height_;
		width = width_;
	}
	void changeDebug(bool cng)
	{
		debug = cng;
	}
	void Init() override
	{

		if (!entity->hasComponent<TransformComponent>() && entity->hasComponent<TileComponent>())
		{
			//entity->addComponent<TransformComponent>();
			printf("No transform meaing this is a tilemap!");
			collider = entity->getComponent<TileComponent>().sRect;
		}
		else
		{
			transform = &entity->getComponent<TransformComponent>();
		}
		

		//Can be smart here and check and see if we have a sprite component
		//If so set our collider to the size of the sprite src box i think....

		if (entity->hasComponent<SpriteComponent>())
		{
			//Sets our collision rectangle to our width and height of our sprite
			//Doensn't really work will look into...


			sprite = &entity->getComponent<SpriteComponent>();
			collider.h = sprite->height;
			collider.w = sprite->width;
		}
	}
	void Update() override
	{

		collider.x = (int)transform->position.x - Scene1::camera.x;
		collider.y = (int)transform->position.y - Scene1::camera.y;

		///Collider component should have height, width individually and use transforms scale instead of using sprite components....
		/// 
		collider.w = width * transform->scale.x;
		collider.h = height * transform->scale.y;


	}


	void Render() override
	{
		if (debug)
		{
			const SDL_Rect* help;
			help = &collider;
			


			SDL_SetRenderDrawColor(Scene1::renderer,255, 0, 0, 255);
			SDL_RenderDrawRect(Scene1::renderer, help);
			SDL_SetRenderDrawColor(Scene1::renderer, 255,255,255,255);
		}
	}

	//*This will be a container class basically detailing the BoundingBox for our collision detection*\\
	//*CollisionDetection still needs to be made as a static function (accessed from anywhere) so    *\\
	//*That we can call it in the update function of scene and check if collision is happening from there




};



#endif // !COLLIDERCOMPONENT_h