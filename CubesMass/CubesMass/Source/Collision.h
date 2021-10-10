#ifndef COLLISION_H
#define COLLISION_H
#include <SDL.h>
#include "Vector.h"
class Collision
{

public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);


	//Scuffed neeeds update, I should make a struct for this circle to contain it better but for now its ok
	static bool CircleColl(const float circ1rad_, const Vector2& circ1_, const float circ2rad_, const Vector2& circ2_);
	static bool CircleRectIntersect(const float circ1rad_, const Vector2& circ1_, const SDL_Rect& recA);
	static bool CircleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh);
};
#endif // !COLLISION_H
