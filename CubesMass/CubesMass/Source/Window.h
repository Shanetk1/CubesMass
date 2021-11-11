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
	int height, width = 0.0f;

public:
	Window();
	~Window();
	bool OnCreate(std::string name_,int _width, int _height);
	void OnDestroy();
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();


	const int getHeight() { return height; }
	const int getWidth() { return width; }


};





#endif // !WINDOW_H

