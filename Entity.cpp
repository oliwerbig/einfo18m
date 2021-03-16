#include "Entity.h"
#include "Event.h"
#include "TimeStamp.h"


void Entity::addEvent(Event* event)
{
    events.push_back(event);
}

int Entity::getNumOfEvents()
{
    return getEvents().size();
}