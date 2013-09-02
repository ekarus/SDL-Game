#include "timer.h"

Timer::Timer()
{
	activate=false;
	start_time=0;
	event_time=0;
}

bool Timer::isActive()
{
	return activate;
}

bool Timer::isEvent()
{
	if(activate)
	{
		if(time.GetSec()>=event_time)
		{
			event_time=0;
			activate=false;
			return true;
		}	
		else
			return false;
	}
	return false;
}

float Timer::getEventTime()
{
	return event_time;
}

void Timer::setEventTime( float event_time_sec )
{
	event_time=event_time_sec;
}

float Timer::Start()
{
	activate=true;
	start_time=time.GetSec();
	return start_time;
}

