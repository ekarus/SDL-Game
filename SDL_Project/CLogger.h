#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <SDL.h>
#include "Singleton.h"

class Logger : public Singleton<Logger>
{
public:
	enum Output
	{
		COUT,
		CERR,
		FILE
	};
	void Write(const std::string level, const std::string function, size_t line, const std::string message);
	void setOutput(Output output)
	{
		output_scenario_ = output;
	}
private:
	friend class Singleton<Logger>;
	std::ofstream out_stream_;
	Output output_scenario_;

protected:
	Logger();
	~Logger();
};



#define WRITE_LOG(level, operators)\
do{\
	std::stringstream string_stream;\
	string_stream<<operators;\
	Logger::Instance()->Write(level,__FUNCTION__,__LINE__, string_stream.str());\
}while(0)

#define LOG_ERROR(operators) WRITE_LOG("ERROR",operators)
#define LOG_INFO(operators) WRITE_LOG("INFO",operators)

void logError( std::ostream& os,std::string msg );
void logInfo( std::ostream& os,std::string msg );