#include "TimeStamp.h"
#include "TimeSpan.h"
#include "Entity.h"


TimeSpan TimeStamp::calculateTimeElapsed(TimeStamp* otherTimeStamp)
{
    TimeSpan timeElapsed(otherTimeStamp->getTimeInMinutes() - getTimeInMinutes());
    return timeElapsed;
}

void TimeStamp::addEntityInside(Entity* entity)
{
    getEntitiesInside()[entity->getId()] = entity;
}

void TimeStamp::removeEntityInside(Entity* entity)
{
    getEntitiesInside().erase(entity->getId());
}

int TimeStamp::getNumOfEntitiesInside()
{
    return getEntitiesInside().size();
}

void TimeStamp::addEvent(Event* event)
{
    getEvents().push_back(event);
}

int TimeStamp::getNumOfEvents()
{
    return getEvents().size();
}