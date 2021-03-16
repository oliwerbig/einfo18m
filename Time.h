#pragma once
#include <string>
class Time
{
protected:
	int timeInMinutes = 0;
public:
	explicit Time();
	explicit Time(int timeInMinutes);
	int getTimeInMinutes() { return timeInMinutes; }
	void setTimeInMinutes(int timeInMinutes) { this->timeInMinutes = timeInMinutes; }
	int getHour();
	int getMinute();
	void setTime(int hour, int minute);
	std::string getTimeAsString() { return std::to_string(getHour()) + ":" + std::to_string(getMinute()); }
};

