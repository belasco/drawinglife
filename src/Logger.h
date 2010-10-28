/*=======================================================
 Copyright (c) avp::ptr, 2010
=======================================================*/

#ifndef _LOGGER_H_
#define _LOGGER_H_

#ifndef __GNUC__
# define __PRETTY_FUNCTION__ __FUNCTION__
#endif

/**
 * \brief Wrapper class for ofLog.
 *
 * Makes easy to debug values of various types.
 */
class Logger {
private:
	Logger();
	~Logger();
public:
	static void logValue(const char* function, const char* name, const string& value)
	{
		ofLog(OF_LOG_VERBOSE, "--> %s \n%s : %s\n<--", function, name, value.c_str());
	}
	static void logValue(const char* function, const char* name, int value)
	{
		ofLog(OF_LOG_VERBOSE, "--> %s \n%s : %d\n<--", function, name, value);
	}
	static void logValue(const char* function, const char* name, unsigned int value)
	{
		ofLog(OF_LOG_VERBOSE, "--> %s \n%s : %u\n<--", function, name, value);
	}
	static void logValue(const char* function, const char* name, double value)
	{
		ofLog(OF_LOG_VERBOSE, "--> %s \n%s : %f\n<--", function, name, value);
	}
	static void logValue(const char* function, const char* name, float value)
	{
		ofLog(OF_LOG_VERBOSE, "--> %s \n%s : %f\n<--", function, name, value);
	}
	static void logValue(const char* function, const char* name, bool value)
	{
		ofLog(OF_LOG_VERBOSE, "--> %s \n%s : %s\n<--", function, name, (value ? "true" : "false"));
	}
};


#define DBG_VAL(value)					Logger::logValue(__PRETTY_FUNCTION__, #value, value)

#endif // _LOGGER_H_
