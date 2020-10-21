#ifndef POSITIONCOMPONENTS_H
#define POSITIONCOMPONENT_H

#include "Components.h"

class PositionComponent : public Component
{
private:
	float xPos, yPos = 0.f;


public:
	float x() { return xPos; }
	float y() { return yPos; }


	void Init() override { xPos = 0; yPos = 0; };
	void Update() override { xPos++; yPos++; }


	void setPosition(float x, float y) { xPos = x; yPos = y; }

};



#endif 
