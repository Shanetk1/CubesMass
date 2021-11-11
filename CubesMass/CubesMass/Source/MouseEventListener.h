#ifndef MOUSEEVENTLISTENER_H
#define MOUSEEVENTLISTENER_H

#include <SDL.h>
#include "Vector.h"
#include "Window.h"



class MouseEventListener
{
public:


	MouseEventListener(const MouseEventListener&) = delete;
	MouseEventListener(MouseEventListener&&) = delete;
	MouseEventListener& operator=(const MouseEventListener&) = delete;
	MouseEventListener& operator=(MouseEventListener&&) = delete;
	MouseEventListener() = delete;

	~MouseEventListener();


	static void Update(SDL_Event e_);


	static void RegisterWindow(Window* window_);
	static void NotifyOfMousePressed(int buttonType_);
	static void NotifyOfMouseReleased(int buttonType_);
	static void NotifyOfMouseMove();
	static void NotifyOfMouseScroll(int y_);


	static Vector2 GetPreviousMousePosition();
	static Vector2 GetMousePosition();
	static Vector2 GetMouseOffset();

private:

	static Vector2 mouse, prevMouse;
	static bool firstUpdate;
	static void UpdateMousePosition();

	static Window* window;

};






#endif // !MOUSEEVENTLISTENER_H
