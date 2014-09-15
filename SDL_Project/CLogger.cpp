#include "CLogger.h"
#include <iostream>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

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

	LoggerImpl::LoggerImpl() : output_scenario_(LogOutput::COUT)
	{
		out_stream_.open("LOG.txt", std::fstream::out | std::ofstream::app);
	}

	LoggerImpl::~LoggerImpl()
	{
		out_stream_.close();
	}

	void LoggerImpl::WriteInternal(std::ostream& stream, const std::string& level, const std::string& function, size_t line, const std::string& message )
	{
		stream << level << " : " << TimeString() << " [" << function << " line " << line << "] - " << message << std::endl;
	}

	void LoggerImpl::WriteShortInternal( std::ostream& stream, const std::string& level, const std::string& function, size_t line, const std::string& message )
	{
		stream << level << " : " << TimeString() << " - " << message << std::endl;
	}

	void LoggerImpl::setOutput( unsigned int flag )
	{
		output_scenario_ = flag;
	}

	std::string LoggerImpl::TimeString() const
	{
		boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
		std::string time_string = boost::posix_time::to_simple_string(now);
		return time_string;
	}
}