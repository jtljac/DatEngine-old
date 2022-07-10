#pragma once

#include <stdint.h>
#include <iostream>
#include <vector>

#include <Utilities/Logging.h>
#include <Utilities/Timing.h>

#ifdef _DEBUG

#endif 

class Profile {
};

class Profiler {
	std::vector<Profiler> subProfilers;

	bool finished = false;
	uint64_t start, end;

	std::string name;
	std::string fileName;
	std::string functionName;
	int line;

public:
	Profiler() : start(Timing::getTime()) {}

	~Profiler() {
		finish();
	}

	void finish() {
		if (finished) {
			Log::warn("Profiler", "Tried to finish profiler more than once, ignoring");
			return;
		}

		// TODO: Platform specific timing
		end = Timing::getTime();
		finished = true;
	}

	unsigned long long getTimeElapsed() {
		if (finished) return end - start;
		else return 0;
	}
};