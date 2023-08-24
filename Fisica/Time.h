#pragma once
#include"Header.h"
class Time
{
private:
	float Old_Time = 0;
	float New_Time = 0;
	float Delta_Time = 0;
public:
	Time();
	~Time();

	static void Time_Update()
	{
		getInstance().New_Time = SDL_GetTicks();

		getInstance().Delta_Time = (getInstance().New_Time - getInstance().Old_Time) / 1000;

		getInstance().Old_Time = getInstance().New_Time;
	}

	static Time & getInstance()
	{
		static Time m_time;

		return m_time;
	}

	static float GetDeltaTime()
	{
		return getInstance().Delta_Time;
	}

};

