#ifndef TRANSFORMCOMPONENTS_H
#define TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Vector.h"


class TransformComponent : public Component
{
public:
	Vector2 position = (0.f,0.f);
	Vector2 scale = (1.f,1.f);
	float orientation = 0.0f;
	
	/// Set position, set scale
	TransformComponent(Vector2 pos_, Vector2 scale_)
	{
		position = pos_;
		scale = scale_;
	}

	/// Sets everything to default values
	TransformComponent() 
	{
		position.x = 0.f;
		position.y = 0.f;
	}

	// Set scale
	void setScale(Vector2 scale_)
	{
		scale = scale_;
	}

	// Set position
	void setPosition(Vector2 position_)
	{
		position = position_;
	}

	void setOrientation(float orientation_)
	{
		orientation = orientation_;
	}
	//Returns position
	Vector2 getPosition() { return position; }
	float getOrientation() {return orientation;}

	void Init() override 
	{};
	void Update(const float deltaTime) override
	{

	};
	void Render() override {};


};



#endif 
