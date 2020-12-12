#ifndef TIMER_H
#define TIMER_H
class Timer
{
private:
	unsigned int prevTicks = 0;
	unsigned int currTicks = 0;

public:
	Timer();
	~Timer();
	void Start();
	void UpdateFrameTicks();//For properly setting prev ticks
	float GetDeltaTime() const;
	unsigned int GetSleepTime(const unsigned int fps);


};









#endif // !TIMER_H