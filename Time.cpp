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
    return getTimeInMinutes() / 60;
}

int Time::getMinute()
{
    return getTimeInMinutes() % 60;
}

void Time::setTime(int hour, int minute)
{
    setTimeInMinutes(hour * 60 + minute);
}