#include "Time.h"


Time::Time()
{
    //ctor
}

Time::Time(int timeInMinutes)
{
    setTimeInMinutes(timeInMinutes);
}

int Time::getHour()
{
    return timeInMinutes / 60;
}

int Time::getMinute()
{
    return timeInMinutes % 60;
}

void Time::setTime(int hour, int minute)
{
    setTimeInMinutes(hour * 60 + minute);
}