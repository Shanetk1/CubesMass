#include "Window.h"

Window::Window(int _width, int _height)
{
	width = _width;
	height = _height;
	window = nullptr;
	screenSurface = nullptr;
}
Window::~Window()
{

}
SDL_Window* Window::getWindow()
{
	return window;
}
bool Window::OnCreate()
{
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	screenSurface = SDL_GetWindowSurface(window);
	if (screenSurface == nullptr)
	{
		printf("Surface could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}
void Window::OnDestroy()
{
	if (screenSurface)
	{
		SDL_FreeSurface(screenSurface);
	}
	if (window)
	{
		SDL_DestroyWindow(window);
	}
	SDL_Quit();
}