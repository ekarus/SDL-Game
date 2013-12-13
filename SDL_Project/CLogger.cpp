#include "CLogger.h"
#include <iostream>

namespace Detail
{
	void LoggerImpl::Write( const std::string& level, const std::string& function, size_t line, const std::string& message )
	{
		if ( LogOutput::COUT == (LogOutput::COUT & output_scenario_))
		{
			WriteShortInternal(std::cout, level, function, line, message);
		}

		if ( LogOutput::CERR == (LogOutput::CERR & output_scenario_))
		{
			WriteShortInternal(std::cerr, level, function, line, message);
		}

		if ( LogOutput::FILE == (LogOutput::FILE & output_scenario_))
		{
			if(out_stream_.is_open())
			{
				WriteInternal(out_stream_, level, function, line, message);
			}
		}
	}

	LoggerImpl::LoggerImpl():output_scenario_(LogOutput::COUT)
	{
		out_stream_.open("LOG.txt", std::fstream::out | std::ofstream::app);
	}

	LoggerImpl::~LoggerImpl()
	{
		out_stream_.close();
	}

	void LoggerImpl::WriteInternal(std::ostream& stream, const std::string& level, const std::string& function, size_t line, const std::string& message )
	{
		stream << level << " : " << "[" << function << " line " << line << "] - " << message << std::endl;
	}

	void LoggerImpl::WriteShortInternal( std::ostream& stream, const std::string& level, const std::string& function, size_t line, const std::string& message )
	{
		stream << level << " : " << message << std::endl;
	}

	void LoggerImpl::setOutput( unsigned int flag )
	{
		output_scenario_ = flag;
	}

}