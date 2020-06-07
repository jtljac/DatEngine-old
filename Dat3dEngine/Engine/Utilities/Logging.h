#pragma once
#include <iostream>
#include <fstream>
#include <Engine/Utilities/Console.h>

enum class LogLevel {
	ERROR = 0,
	WARNING = 1,
	INFO = 2,
	VERBOSE = 3
};

class Log {
private:
	static std::string getLogLevel(LogLevel level) {
		switch (level) {
		case LogLevel::INFO:
			return "Info";
		case LogLevel::WARNING:
			return "Warning";
		case LogLevel::ERROR:
			return "Error";
		case LogLevel::VERBOSE:
			return "Verbose";
		default:
			return "";
		}
	}
public:
	static void log(const ConsoleColour logColour, const LogLevel loglevel, const std::string logTag, const std::string logMessage) {
		if ((int)loglevel <= 2) { // TODO: Make Unconstant
			std::cout << ColourMod(logColour) << "[" << getLogLevel(loglevel) << "] [" << logTag << "] " << logMessage << ColourMod(ConsoleColour::RESET) << std::endl;
		}
	}

	static void i(const std::string logTag, const std::string logMessage) {
		log(ConsoleColour::DEFAULT, LogLevel::INFO, logTag, logMessage);
	}

	static void e(const std::string logTag, const std::string logMessage) {
		log(ConsoleColour::RED, LogLevel::ERROR, logTag, logMessage);
	}

	static void w(const std::string logTag, const std::string logMessage) {
		log(ConsoleColour::YELLOW, LogLevel::WARNING, logTag, logMessage);
	}

	static void v(const std::string logTag, const std::string logMessage) {
		log(ConsoleColour::GREEN, LogLevel::VERBOSE, logTag, logMessage);
	}
};