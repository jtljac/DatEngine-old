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
    /**
     * Log data to the console
     * @param logLevel The severity of the log
     * @param logTag The tag to give the log, usually the class context
     * @param logMessage The message to log
     */
	static void log(const LogLevel logLevel, const std::string& logTag, const std::string& logMessage) {
		if ((int)logLevel <= 3) { // TODO: Make Un-constant
			std::cout << "[" << getLogLevelAsString(logLevel) << "] [" << logTag << "] " << logMessage << std::endl;
		}
	}

    /**
     * Log an information message
     * For when you want to let the console know something
     * @param logTag The tag to give the log, usually the class context
     * @param logMessage The message to log
     */
	static void info(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGINFO, logTag, logMessage);
	}

    /**
     * Log an error message
     * For when something has gone wrong
     * @param logTag The tag to give the log, usually the class context
     * @param logMessage The message to log
     */
	static void error(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGERROR, logTag, logMessage);
	}

    /**
     * Log a warning message
     * For when something hasn't exactly gone right, but it's not that bad
     * @param logTag The tag to give the log, usually the class context
     * @param logMessage The message to log
     */
	static void warn(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGWARNING, logTag, logMessage);
	}

    /**
     * Log a verbose message
     * For when there's a bit of information which 90% of the time doesn't need to be logged, but may still be useful
     * @param logTag The tag to give the log, usually the class context
     * @param logMessage The message to log
     */
	static void verbose(const std::string& logTag, const std::string& logMessage) {
		log(LogLevel::LOGDEBUG, logTag, logMessage);
	}
};