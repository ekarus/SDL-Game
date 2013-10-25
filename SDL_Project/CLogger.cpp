#include "CLogger.h"
#include <iostream>

void logError( std::ostream& os,std::string msg )
{
	os<<"ERROR - "<<msg<<" : "<<SDL_GetError()<<std::endl;
}

void logInfo( std::ostream& os,std::string msg )
{
	os<<"INFO - "<<msg<<std::endl;
}

void Logger::Write( const std::string level, const std::string function, size_t line, const std::string message )
{
	if ( Output::COUT == output_scenario_)
	{
		std::cout<<level<<" : "<<"["<<function<<" line "<<line<<"] - "<<message<<std::endl;
	}
	else if ( Output::CERR == output_scenario_)
	{
		std::cerr<<level<<" : "<<"["<<function<<" line "<<line<<"] - "<<message<<std::endl;
	}
	else if ( Output::FILE == output_scenario_)
	{
		if(out_stream_.is_open())
		{
			out_stream_<<level<<" : "<<"["<<function<<" line "<<line<<"] - "<<message<<std::endl;
		}
		else
		{
			setOutput(COUT);
			LOG_ERROR("Cannot open log file to write");
		}
	}
	
}

Logger::Logger():output_scenario_(Output::COUT)
{
	out_stream_.open("LOG.txt", std::fstream::out| std::ofstream::app);
}

Logger::~Logger()
{
	out_stream_.close();
}