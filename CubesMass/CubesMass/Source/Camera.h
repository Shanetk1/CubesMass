#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

class Camera
{
public:
	SDL_Rect renderBox;


public:
	Camera();

	Camera(int x, int y, int w, int h)
	{
		renderBox.x = x;
		renderBox.y = y;
		renderBox.w = w;
		renderBox.h = h;
	}


};

#endif // !CAMERA_H


