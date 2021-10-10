#include "Collision.h"
#include <cmath>
bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
    if 
    (
    recA.x + recA.w >= recB.x &&
    recB.x + recB.w >= recA.x &&
    recA.y + recA.h >= recB.y &&
    recB.y + recB.h >= recA.y)
    {
        return true;
    }
    return false;
}
bool Collision::CircleColl(const float circ1rad_, const Vector2& circ1_, const float circ2rad_, const Vector2& circ2_)
{


    float dx = (circ1_.x + circ1rad_) - (circ2_.x + circ2rad_);
    float dy = (circ1_.y + circ1rad_) - (circ2_.y + circ2rad_);
    float distance = sqrtf(dx * dx + dy * dy);


    if (distance < circ1rad_ + circ2rad_) {

        //Collision == TRUE

        return true;

    }
    else {

        //COLLISION == FALSE
        return false;
    }

}

bool Collision::CircleRectIntersect(const float circ1rad_, const Vector2& circ1_, const SDL_Rect& recA)
{   


   float circleDistanceX = std::abs(circ1_.x - recA.x);
   float circleDistanceY = std::abs(circ1_.y - recA.y);

    

    if (circleDistanceX > (recA.w / 2 + circ1rad_)) { return false; }
    if (circleDistanceY > (recA.h / 2 + circ1rad_)) { return false; }

    if (circleDistanceX <= (recA.w / 2)) { return true; }
    if (circleDistanceY <= (recA.h / 2)) { return true; }

   float cornerDistance_sq = (circleDistanceX - recA.w / 2) * (circleDistanceX - recA.w / 2) +
                             (circleDistanceY - recA.h / 2) * (circleDistanceY - recA.h / 2);

    return (cornerDistance_sq <= (circ1rad_ * circ1rad_));
}


bool Collision::CircleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh) 
{

    // temporary variables to set edges for testing
    float testX = cx;
    float testY = cy;

    // which edge is closest?
    if (cx < rx)         testX = rx;      // test left edge
    else if (cx > rx + rw) testX = rx + rw;   // right edge
    if (cy < ry)         testY = ry;      // top edge
    else if (cy > ry + rh) testY = ry + rh;   // bottom edge

    // get distance from closest edges
    float distX = cx - testX;
    float distY = cy - testY;
    float distance = sqrt((distX * distX) + (distY * distY));

    // if the distance is less than the radius, collision!
    if (distance <= radius) {
        return true;
    }
    return false;
}
