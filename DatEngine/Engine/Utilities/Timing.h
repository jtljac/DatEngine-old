#pragma once

#include <cstdint>

class Timing {
	static uint64_t frequency;
    static uint64_t offset;
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
    static void setOffset(double newOffset);

	/**
	 * Gets the seconds elapsed since the timing was initialised, unless time has been set with @ref SetOffset in which it will get the time since the set offset
	 * @returns The time since initialisation in seconds
	 */
	static double getTime();

	/**
	 * Gets the milliseconds elapsed since the the timing was initialised, unless time has been set with @ref SetOffset in which it will get the time since the set offset
	 * @returns The time since initialisation in milliseconds
	 */
	static double getMilliseconds();

	/**
	 * Gets the nanoseconds elapsed since the timing was initialised, unless time has been set with SetOffset in which it will get the time since the set offset
	 * @returns The time since initialisation in nanoseconds
	 */
	static double getNanoseconds();
};