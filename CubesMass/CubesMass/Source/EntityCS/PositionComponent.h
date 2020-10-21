#ifndef POSITIONCOMPONENTS_H
#define POSITIONCOMPONENT_H

#include "Components.h"
#include "../Vector.h"

class PositionComponent : public Component
{
private:


public:
	Vector2 position;

	PositionComponent(float x, float y)
	{
		position.x = x;
		position.x = y;

	}
	PositionComponent() 
	{
		position.x = 0.f;
		position.y = 0.f;
	}
	void Init() override {};
	void Update() override {};
	void Render() override {};


};



#endif 
