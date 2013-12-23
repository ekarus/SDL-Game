#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <SDL.h>
#include "Singleton.h"

struct LogOutput
{
	enum Enum
	{
		COUT = 0x001,
		CERR = 0x010,
		FILE = 0x100
	};
};

namespace Detail
{
	class LoggerImpl
	{
	public:

		void Write(const std::string& level, const std::string& function, size_t line, const std::string& message);
		void setOutput(unsigned int flag);

		LoggerImpl();
		~LoggerImpl();

	private:
		void WriteInternal(std::ostream& stream, const std::string& level, const std::string& function, size_t line, const std::string& message);
		void WriteShortInternal(std::ostream& stream, const std::string& level, const std::string& function, size_t line, const std::string& message);
		std::ofstream out_stream_;
		unsigned int output_scenario_;
	};
}

typedef Singleton<Detail::LoggerImpl> Logger;

#define WRITE_LOG(level, operators)\
	do{\
	std::stringstream string_stream;\
	string_stream<<operators;\
	Logger::Instance()->Write(level,__FUNCTION__,__LINE__, string_stream.str());\
	}while(0)

#define LOG_ERROR(operators) WRITE_LOG("ERROR",operators)
#define LOG_INFO(operators) WRITE_LOG("INFO",operators)

/*std::string sdl_error = SDL_GetError();\
if(!sdl_error.empty()) Logger::Instance()->Write(level,__FUNCTION__,__LINE__, sdl_error);\*/