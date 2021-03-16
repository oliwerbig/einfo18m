#include "Entity.h"
#include "Event.h"


void Entity::addEvent(Event* event)
{
    getEvents().push_back(event);
}

int Entity::getNumOfEvents()
{
    return getEvents().size();
}
