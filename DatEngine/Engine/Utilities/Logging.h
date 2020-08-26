#pragma once
#include <iostream>
#include <fstream>
#include <Utilities/Console.h>

enum class LogLevel {
	ERROR = 0,
	WARNING = 1,
	INFO = 2,
	DEBUG = 3
};

class Log {
private:
	static std::string getLogLevelAsString(LogLevel level) {
		switch (level) {
		case LogLevel::INFO:
			return "Info";
		case LogLevel::WARNING:
			return "Warning";
		case LogLevel::ERROR:
			return "Error";
		case LogLevel::DEBUG:
			return "Debug";
		default:
			return "";
		}
	}
public:
	static void log(const ConsoleColour logColour, const LogLevel logLevel, const std::string logTag, const std::string logMessage) {
		if ((int)logLevel <= 3) { // TODO: Make Unconstant
			std::cout << ColourMod(logColour) << "[" << getLogLevelAsString(logLevel) << "] [" << logTag << "] " << logMessage << ColourMod(ConsoleColour::RESET) << std::endl;
		}
	}

	static void log(const LogLevel logLevel, const std::string logTag, const std::string logMessage) {
		ConsoleColour colour = ConsoleColour::DEFAULT;
		switch (logLevel) {
		case LogLevel::WARNING:
			colour = ConsoleColour::YELLOW;
			break;
		case LogLevel::ERROR:
			colour = ConsoleColour::RED;
			break;
		case LogLevel::DEBUG:
			colour = ConsoleColour::GREEN;
			break;
		}

		log(colour, logLevel, logTag, logMessage);
	}

	static void i(const std::string logTag, const std::string logMessage) {
		log(LogLevel::INFO, logTag, logMessage);
	}

	static void e(const std::string logTag, const std::string logMessage) {
		log(LogLevel::ERROR, logTag, logMessage);
	}

	static void w(const std::string logTag, const std::string logMessage) {
		log(LogLevel::WARNING, logTag, logMessage);
	}

	static void v(const std::string logTag, const std::string logMessage) {
		log(LogLevel::DEBUG, logTag, logMessage);
	}
};