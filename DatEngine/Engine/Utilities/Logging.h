#pragma once
#include <iostream>
#include <fstream>
#include <Utilities/Console.h>

enum class LogLevel {
	LOGERROR = 0,
	LOGWARNING = 1,
	LOGINFO = 2,
	LOGDEBUG = 3
};

class Log {
private:
	static std::string getLogLevelAsString(LogLevel level) {
		switch (level) {
		case LogLevel::LOGINFO:
			return "Info";
		case LogLevel::LOGWARNING:
			return "Warning";
		case LogLevel::LOGERROR:
			return "Error";
		case LogLevel::LOGDEBUG:
			return "Debug";
		default:
			return "";
		}
	}
public:
	static void log(const ConsoleColour logColour, const LogLevel logLevel, const std::string& logTag, const std::string& logMessage) {
		if ((int)logLevel <= 3) { // TODO: Make Unconstant
			std::cout << ColourMod(logColour) << "[" << getLogLevelAsString(logLevel) << "] [" << logTag << "] " << logMessage << ColourMod(ConsoleColour::RESET) << std::endl;
		}
	}

	static void log(const LogLevel logLevel, const std::string& logTag, const std::string& logMessage) {
		ConsoleColour colour = ConsoleColour::DEFAULT;
		switch (logLevel) {
		case LogLevel::LOGWARNING:
			colour = ConsoleColour::YELLOW;
			break;
		case LogLevel::LOGERROR:
			colour = ConsoleColour::RED;
			break;
		case LogLevel::LOGDEBUG:
			colour = ConsoleColour::GREEN;
			break;
		}

		log(colour, logLevel, logTag, logMessage);
	}

	static void i(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGINFO, logTag, logMessage);
	}

	static void e(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGERROR, logTag, logMessage);
	}

	static void w(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGWARNING, logTag, logMessage);
	}

	static void v(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGDEBUG, logTag, logMessage);
	}
};