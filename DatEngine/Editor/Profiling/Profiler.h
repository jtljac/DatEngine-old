#pragma once

#include <Utilities/Logging.h>
#include <iostream>
#include <vector>
#include <chrono>

#ifdef _DEBUG

#endif 

class Profile {
};

class Profiler {
	std::vector<Profiler> subProfilers;

	bool finished = false;
	unsigned long long start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	unsigned long long end;

	std::string name;
	std::string fileName;
	std::string functionName;
	int line;

public:
	Profiler() {}

	~Profiler() {
		finish();
	}

	void finish() {
		if (finished) {
			Log::w("Profiler", "Tried to finish profiler more than once, ignoring");
			return;
		}

		// TODO: Platform specific timing
		end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		finished = true;
	}

	unsigned long long getTimeElapsed() {
		if (finished) return end - start;
		else return 0;
	}
};