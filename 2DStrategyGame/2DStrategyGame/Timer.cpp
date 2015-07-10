#include "Timer.h"

Timer::Timer()
{

}

Timer::~Timer()
{

}

bool Timer::Initialise()
{
	LARGE_INTEGER i;
	if (!QueryPerformanceFrequency(&i))
	{
		return false;
	}
	frequencyPerSec = (float)(i.QuadPart);
	QueryPerformanceCounter(&i);
	start = i.QuadPart;
	totalGameTime = 0;
	elapsedTime = 0;

	return true;
}

void Timer::Update()
{
	LARGE_INTEGER i;
	QueryPerformanceCounter(&i);
	elapsedTime = (float)(i.QuadPart - start) / frequencyPerSec;
	start = i.QuadPart;
	totalGameTime += elapsedTime;
}