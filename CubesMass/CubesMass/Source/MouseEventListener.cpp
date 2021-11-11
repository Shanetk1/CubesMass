#include "MouseEventListener.h"



Vector2 MouseEventListener::mouse = Vector2();
Vector2 MouseEventListener::prevMouse = Vector2();
bool MouseEventListener::firstUpdate = true;
Window* MouseEventListener::window = nullptr;


MouseEventListener::~MouseEventListener()
{

}


void MouseEventListener::Update(SDL_Event e_)
{


	if (e_.type == SDL_MOUSEBUTTONDOWN)
	{
		UpdateMousePosition();
		NotifyOfMousePressed(e_.button.button);
	}
	else if (e_.type == SDL_MOUSEBUTTONUP)
	{
		UpdateMousePosition();
		NotifyOfMouseReleased(e_.button.button);
	}
	else if (e_.type == SDL_MOUSEMOTION)
	{
		UpdateMousePosition();
		NotifyOfMouseMove();
	}
	else if (e_.type == SDL_MOUSEWHEEL)
	{
		UpdateMousePosition();
		NotifyOfMouseScroll(e_.wheel.y);
	}

}

Vector2 MouseEventListener::GetPreviousMousePosition()
{
	return prevMouse;
}

Vector2 MouseEventListener::GetMousePosition()
{
	return mouse;
}

Vector2 MouseEventListener::GetMouseOffset()
{
	return Vector2(mouse.x - prevMouse.x, prevMouse.y - mouse.y);
}


void MouseEventListener::UpdateMousePosition()
{
	int tmpX, tmpY;

	SDL_GetMouseState(&tmpX, &tmpY);



	//Need to get window position here... maybe have a reference to the window....

	tmpY = static_cast<int>(window->getHeight()) - tmpY;



	if (firstUpdate)
	{
		prevMouse.x = mouse.x = tmpX;
		prevMouse.y = mouse.y = tmpY;
		firstUpdate = false;
	}
	else
	{
		prevMouse.x = mouse.x;
		prevMouse.y = mouse.y;
		mouse.x = tmpX;
		mouse.y = tmpY;
	}

}


void MouseEventListener::RegisterWindow(Window* window_)
{
	window = window_;
}

void MouseEventListener::NotifyOfMousePressed(int buttonType_)
{
}

void MouseEventListener::NotifyOfMouseReleased(int buttonType_)
{
}

void MouseEventListener::NotifyOfMouseMove()
{
}

void MouseEventListener::NotifyOfMouseScroll(int y_)
{
}
