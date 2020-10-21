#ifndef TIMER_H
#define TIMER_H


class Timer
{
public:
	Timer();
	~Timer();
	void Start();
	void UpdateFrameTicks();//For properly setting prev ticks
	float GetDeltaTime() const;
	unsigned int GetSleepTime(const unsigned int fps);

private:
	unsigned int prevTicks;
	unsigned int currTicks;
};









#endif // !TIMER_H