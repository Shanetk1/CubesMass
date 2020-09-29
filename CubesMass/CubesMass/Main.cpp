#include <string>
#include "Window.h"

int main(int argc, char * args[])
{
	Window* newWindow = new Window(780, 640);
	newWindow->OnCreate();
	newWindow->OnDestroy();

	return 0;
}