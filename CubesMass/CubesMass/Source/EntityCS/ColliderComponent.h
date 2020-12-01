#ifndef COLLIDERCOMPONENT_h
#define COLLIDERCOMPONENT_h

#include "Components.h"
#include <string>
#include <SDL.h>

class ColliderComponent : public Component
{

public:

	SDL_Rect collider;

	//Used to check what we hit an (identifier)
	std::string tag;

	TransformComponent* transform;
	SpriteComponent* spriteComp = nullptr;

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
	void Init() override
	{

		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		//Can be smart here and check and see if we have a sprite component
		//If so set our collider to the size of the sprite src box i think....

		if (entity->hasComponent<SpriteComponent>())
		{
			//Sets our collision rectangle to our width and height of our sprite
			//Doensn't really work will look into...


			spriteComp = &entity->getComponent<SpriteComponent>();
			collider.h = spriteComp->height;
			collider.w = spriteComp->width;
		}
	}
	void Update() override
	{

		collider.x = transform->position.x;
		collider.y = transform->position.y;

		///Collider component should have height, width individually and use transforms scale instead of using sprite components....
		/// 
		collider.w = width * transform->scale.x;
		collider.h = height * transform->scale.y;

		//printf("collider w = %i", collider.w);
	}


	void Render() override
	{

	}

	//*This will be a container class basically detailing the BoundingBox for our collision detection*\\
	//*CollisionDetection still needs to be made as a static function (accessed from anywhere) so    *\\
	//*That we can call it in the update function of scene and check if collision is happening from there




};



#endif // !COLLIDERCOMPONENT_h