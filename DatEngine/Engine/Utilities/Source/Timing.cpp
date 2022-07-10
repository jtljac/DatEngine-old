#include "../Timing.h"
#include <Utilities/Logging.h>

uint64_t Timing::frequency = 0;
uint64_t Timing::offset = 0;

void Timing::setOffset(double newOffset) {
#if _DEBUG
    // Ensure positive value and that the value won't overflow
    // 18446744073.0 calculated with (double)(UINT64_MAX / 1e9), if value is above this then when converting to ticks it will overflow and result in a very small value
    if (newOffset < 0.0 || newOffset > 18446744073.0) {
        Log::warn("Timing", "Tried to set timing offset to negative value or value that will overflow, ignoring");
        return;
    }
#endif
    offset = getTimerValue() * (uint64_t)(newOffset * frequency);
}

double Timing::getTime() {
    return static_cast<double>(getTimerValue() - offset) / frequency;
}

double Timing::getMilliseconds() {
    return static_cast<double>(getTimerValue() - offset) * 1e3 / frequency;
}

double Timing::getNanoseconds() {
    return static_cast<double>(getTimerValue() - offset) * 1e9 / frequency;
}
