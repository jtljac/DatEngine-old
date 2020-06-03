#pragma once
#include <ostream>


enum class ConsoleColour {
	RESET = 0,
	DEFAULT = 39,
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35,
	CYAN = 36,
	LIGHTGRAY = 37,
	DARKGRAY = 90,
	LIGHTRED = 91,
	LIGHTGREEN = 92,
	LIGHTYELLOW = 93,
	LIGHTBLUE = 94,
	LIGHTMAGENTA = 95,
	LIGHTCYAN = 96,
	WHITE = 97
};

class ColourMod {
	ConsoleColour colour;
public:
	ColourMod(ConsoleColour theColour) : colour(theColour) {}
	friend std::ostream& operator<< (std::ostream& stream, const ColourMod mod) {
		return stream << "\033[" << (int) mod.colour << "m";
	}
};