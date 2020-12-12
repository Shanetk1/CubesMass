#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
class Window
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

public:
	Window();
	~Window();
	bool OnCreate(std::string name_,int _width, int _height);
	void OnDestroy();
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
};





#endif // !WINDOW_H

