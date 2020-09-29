#include "Window.h"

Window::Window()
{
	width = 0;
	height = 0;
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
bool Window::OnCreate(std::string name_, int width_, int height_)
{
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow(name_.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_SHOWN);
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