#pragma once

#include <stdint.h>
#include <Utilities/Logging.h>

class Timing {
	inline static uint64_t frequency = 0.;
	inline static uint64_t offset = 0.;
	static uint64_t getTimerValue();
public:
	/**
	 * Sets up timing for use
	 */
	static void initialise();

	/**
	 * Sets the offset of the getTime function from the cpu time to the given value
	 * @param newOffset The new offset in seconds
	 */
    void setOffset(double newOffset) {
        // Ensure positive value and that the value won't overflow
        // 18446744073.0 calculated with (double)(UINT64_MAX / 1e9), if value is above this then when converting to ticks it will overflow and result in a very small value
        if (newOffset < 0.0 || newOffset > 18446744073.0) {
            Log::warn("Timing", "Tried to set timing offset to negative value or value that will overflow, ignoring");
            return;
        }
        offset = getTimerValue() * (uint64_t)(newOffset * frequency);
    }

	/**
	 * Gets the seconds elapsed since the timing was initialised, unless time has been set with @ref SetOffset in which it will get the time since the set offset
	 * @returns The time since initialisation in seconds
	 */
	static double getTime() {
        return static_cast<double>(getTimerValue() - offset) / frequency;
	}

	/**
	 * Gets the milliseconds elapsed since the the timing was initialised, unless time has been set with @ref SetOffset in which it will get the time since the set offset
	 * @returns The time since initialisation in milliseconds
	 */
	static double getMilliseconds() {
		return static_cast<double>(getTimerValue() - offset) * 1e3 / frequency;
	}

	/**
	 * Gets the nanoseconds elapsed since the the timing was initialised, unless time has been set with @ref SetOffset in which it will get the time since the set offset
	 * @returns The time since initialisation in nanoseconds
	 */
	static double getNanoseconds() {
		return static_cast<double>(getTimerValue() - offset) * 1e9 / frequency;
	}
};