#include "Timer.h"
#include <SDL.h>
Timer::Timer()
{
	prevTicks = 0;
	currTicks = 0;
}
Timer::~Timer(){}

void Timer::Start()
{
	prevTicks = SDL_GetTicks();
	currTicks = SDL_GetTicks();
}
void Timer::UpdateFrameTicks()
{
	prevTicks = currTicks;
	currTicks = SDL_GetTicks();
}
float Timer::GetDeltaTime() const
{
	return (float(currTicks - prevTicks) / 1000);
}
unsigned int Timer::GetSleepTime(const unsigned int fps)
{
	unsigned int millisecondsPerFrame = 1000 / fps; //1000 milleseconds in a second basically yup

	if (millisecondsPerFrame == 0)
	{
		return 0;
		//No sleeping
	}
	unsigned int sleepTime = millisecondsPerFrame - (SDL_GetTicks());

	if (sleepTime > millisecondsPerFrame)
	{
		return millisecondsPerFrame;
	}
	return sleepTime;
}