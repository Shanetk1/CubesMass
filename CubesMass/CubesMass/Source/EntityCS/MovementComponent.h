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
			float angle = atan2(-(MouseEventListener::GetMousePosition().y - transformRef->getPosition().y), MouseEventListener::GetMousePosition().x - transformRef->getPosition().x);
			angle = angle * RADIANS_TO_DEGREES;
			std::cout << "Mouse Position x=" <<  MouseEventListener::GetMousePosition().x << std::endl;
			std::cout <<  "Player position x=" << transformRef->getPosition().x << std::endl;

			std::cout << "Mouse Position y=" << MouseEventListener::GetMousePosition().y << std::endl;
			std::cout << "Player position y=" << transformRef->getPosition().y << std::endl;

			
			transformRef->setOrientation(90 + angle);
		
		}
		else
		{



			if (MATH::VMath::mag(velocity) > 0.0f)
			{


				if (isPlayer)
				{


				}
				else
				{
					//tmp1 = atan2(-velocity.y, velocity.x);
				}



				//tmp1 *= RADIANS_TO_DEGREES;
				//transformRef->setOrientation(tmp1);


			}
			else
			{
				//tmp1 = tmp1;
			}
		}





	};
	void Render() override {};









};




#endif // !MOVEMENTCOMPONENT_H
