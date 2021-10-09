
#include "Window.h"

Window::Window()
{
	window = nullptr;
	renderer = nullptr;
}
Window::~Window()
{

}
SDL_Window* Window::getWindow()
{
	return window;
}
SDL_Renderer* Window::getRenderer()
{
	return renderer;
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
	
	//Might not be necessary, might be put into camera class
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		//printf("Renderer created for our window");
	}

	return true;
}
void Window::OnDestroy()
{
//	if (screenSurface)
//	{
//		SDL_FreeSurface(screenSurface);
//	}
	if (renderer) { SDL_DestroyRenderer(renderer); }
	if (window)   {SDL_DestroyWindow(window);}


	SDL_Quit();
}