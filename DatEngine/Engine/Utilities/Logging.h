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
	static void log(const LogLevel logLevel, const std::string& logTag, const std::string& logMessage) {
		if ((int)logLevel <= 3) { // TODO: Make Un-constant
			std::cout << "[" << getLogLevelAsString(logLevel) << "] [" << logTag << "] " << logMessage << std::endl;
		}
	}

	static void info(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGINFO, logTag, logMessage);
	}

	static void error(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGERROR, logTag, logMessage);
	}

	static void warn(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGWARNING, logTag, logMessage);
	}

	static void verbose(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGDEBUG, logTag, logMessage);
	}
};