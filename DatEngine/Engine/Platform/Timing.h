#pragma once


class Timing {
#ifdef WIN32
	inline static unsigned long long frequency = 0;
#endif

public:
	static unsigned long long getMilliseconds();

	// static double getSeconds();
};