#include <profileapi.h>
#include <Platform/Timing.h>
#include <Utilities/Logging.h>

void Timing::initialise() {
	QueryPerformanceFrequency((LARGE_INTEGER*) &frequency);
	QueryPerformanceCounter((LARGE_INTEGER*) &offset);
}

uint64_t Timing::getTimerValue() {
	uint64_t ticks;
	QueryPerformanceCounter((LARGE_INTEGER*) &ticks);
	return ticks;
}

void Timing::setOffset(double newOffset) {
	// Ensure positive value and that the value won't overflow
	// 18446744073.0 calculated with (double)(UINT64_MAX / 1e9), if value is above this then when converting to ticks it will overflow and result in a very small value
	if (newOffset < 0.0 || newOffset > 18446744073.0) {
		Log::e("Timing", "Tried to set timing offset to negative value or value that will overflow, ignoring");
		return;
	}
	offset = getTimerValue() * (uint64_t)(newOffset * frequency);
}