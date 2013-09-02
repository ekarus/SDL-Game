#pragma once
#include <ctime>


class Time
{
	unsigned int ticks;
public:
	Time()
	{
		Update();
	}
	unsigned int Update()//обновляем количество тиков
	{
		ticks=clock();
		return ticks;
	}
	unsigned int ElapsedTicks()//возвращает пройденое время
	{
		return clock()-ticks;
	}
	unsigned int GetTicks()
	{
		return Update();
	}
	float GetSec()
	{
		return (float)(Update()/CLOCKS_PER_SEC);
	}
	float ElapsedSec()//возвращает пройденое время в секундах
	{
		return (float)(ElapsedTicks())/CLOCKS_PER_SEC;
	}
	unsigned int Delta(Time& t)
	{
		return (t.ticks-ticks);
	}
	static float getCurrTimeSec()
	{
		return float(clock()/CLOCKS_PER_SEC);
	}
};

class Timer
{
private:
	bool activate;
	Time time;
	float start_time;
	float event_time;

public:
	Timer();
	float Start();
	void setEventTime(float event_time_sec);
	float getEventTime();
	bool isEvent();
	bool isActive();
};
