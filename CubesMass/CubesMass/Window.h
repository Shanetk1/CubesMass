#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <string>
class Window
{
private:
	int width, height;
	SDL_Window* window;
	SDL_Surface* screenSurface;

public:
	Window(int _width, int _height);
	~Window();
	bool OnCreate();
	void OnDestroy();
	SDL_Window* getWindow();


};





#endif // !WINDOW_H

