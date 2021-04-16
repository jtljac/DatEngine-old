#include <ctime>
#include <Platform/Timing.h>

void Timing::initialise() {
	frequency = 1e9;
	offset = getTimerValue();
}

uint64_t Timing::getTimerValue() {
	timespec ticks;
    clock_gettime(CLOCK_MONOTONIC, &ticks);
	return ticks.tv_nsec;
}