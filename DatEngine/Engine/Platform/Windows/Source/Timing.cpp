#include <Windows.h>

#include <Platform/Timing.h>

unsigned long long Timing::getMilliseconds() {
	if (frequency == 0) {
		LARGE_INTEGER theFrequency;
		QueryPerformanceFrequency(&theFrequency);
		frequency = theFrequency.QuadPart;
	}

	LARGE_INTEGER seconds;
	QueryPerformanceCounter(&seconds);

	seconds.QuadPart *= 1e9;
	return (seconds.QuadPart / frequency) * 1e-6;
}