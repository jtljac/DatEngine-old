#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Utilities/Timing.h>

void Timing::initialise() {
	QueryPerformanceFrequency((LARGE_INTEGER*) &frequency);
	QueryPerformanceCounter((LARGE_INTEGER*) &offset);
}

uint64_t Timing::getTimerValue() {
	uint64_t ticks;
	QueryPerformanceCounter((LARGE_INTEGER*) &ticks);
	return ticks;
}