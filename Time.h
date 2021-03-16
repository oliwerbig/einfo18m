#pragma once
class Time
{
protected:
	int timeInMinutes;
public:
	explicit Time();
	explicit Time(int timeInMinutes);
	int getTimeInMinutes() { return timeInMinutes; }
	void setTimeInMinutes(int timeInMinutes) { this->timeInMinutes = timeInMinutes; }
	int getHour();
	int getMinute();
	void setTime(int hour, int minute);
};

