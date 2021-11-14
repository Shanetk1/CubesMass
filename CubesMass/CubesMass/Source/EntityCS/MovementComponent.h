#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include "Components.h"



class MovementComponent : public Component
{
private:
	TransformComponent* transformRef = nullptr;
	Vector2 velocity;
	




	//I dont like this hear but its so that we dont need a pointless extra component for this as that defeats the purpose of the ocmponent system

	bool isPlayer = false;


public:
	MovementComponent()
	{
		//Default... 
	



	}
	//Isplayer is always defualted to false so only use this constructor if this component is being used by a player and oyu want to set it to true...
	MovementComponent(bool isPlayer_)
	{
		isPlayer = isPlayer_;

	}

	void setVelocity(Vector2 v_)
	{
		velocity = v_;
	}
	Vector2 getVelocity()
	{
		return velocity;
	}


	void Init() override
	{
		transformRef = &entity->getComponent<TransformComponent>();
		//We need this to update the transform...



	
	};
	void Update(const float deltaTime) override
	{
		Vector2 tmp = transformRef->getPosition();
		//float tmp1 = transformRef->getOrientation();
		//tmp += velocity * deltaTime;

		transformRef->setPosition(tmp + velocity * deltaTime);






		if (isPlayer)
		{
			//Mouse Coordinates are in screen co-ordinates not proper 

			Vector2 worldCoord = Vector2(Scene1::camera.x + MouseEventListener::GetMousePosition().x, Scene1::camera.y + MouseEventListener::GetMousePosition().y);
			//I think theres a special case when the camera is hitting the map edges

			//std::cout << MouseEventListener::GetMousePosition().y << std::endl;
			//std::cout << worldCoord.x << std::endl;

			float angle = atan2((worldCoord.y - transformRef->getPosition().y), worldCoord.x - transformRef->getPosition().x);
			//angle = angle * RADIANS_TO_DEGREES;
			//std::cout << "Mouse Position x=" <<  MouseEventListener::GetMousePosition().x << std::endl;
			//std::cout <<  "Player position x=" << transformRef->getPosition().x << std::endl;

			//std::cout << "Mouse Position y=" << MouseEventListener::GetMousePosition().y << std::endl;
			//std::cout << "Player position y=" << transformRef->getPosition().y << std::endl;

			
			transformRef->setOrientation(angle);
		
		}
		else
		{
			if (MATH::VMath::mag(velocity) > 0.0f)
			{
				//float angle = atan2(velocity.y, velocity.x);
				//angle *= RADIANS_TO_DEGREES;
				//transformRef->setOrientation(angle);
				//std::cout << 


			}
		}





	};
	void Render() override {};









};




#endif // !MOVEMENTCOMPONENT_H
