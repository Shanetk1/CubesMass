#ifndef TRANSFORMCOMPONENTS_H
#define TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Vector.h"
class TransformComponent : public Component
{
private:


public:
	Vector2 position = (0.f,0.f);
	Vector2 rotation;
	Vector2 scale = (1.f,1.f);

	Vector2 velocity;//This isnt good cause transform should just have the values of pos, rotation and scale!
	
	/// Set position, set scale
	TransformComponent(Vector2 pos, Vector2 scale_)
	{
		position = pos;
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

	void Init() override 
	{
	
	};
	void Update() override 
	{
	
	};
	void Render() override {};


};



#endif 
