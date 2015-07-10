#ifndef _TIMER_H_
#define _TIMER_H_
#include <Windows.h>

class Timer
{
public:
	Timer();
	~Timer();
	float elapsedTime;
	float totalGameTime;
	bool Initialise();
	void Update();
private:
	LONGLONG start;
	float frequencyPerSec;
};

#endif //!_TIMER_H_#pragma once
