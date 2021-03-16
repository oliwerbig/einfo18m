#pragma once
#include "Time.h"
#include <vector>
#include <map>
class TimeSpan;
class Entity;
class Event;
class TimeStamp :
    public Time
{
    using Time::Time;
protected:
    std::vector<Event*> events;
    std::map<int, Entity*> entitiesInside;
public:
    void addEvent(Event* event);
    std::vector<Event*> getEvents() { return events; }
    int getNumOfEvents();
    void addEntityInside(Entity* entity);
    void removeEntityInside(Entity* entity);
    std::map<int, Entity*> getEntitiesInside() { return entitiesInside; }
    int getNumOfEntitiesInside();
    TimeSpan calculateTimeElapsed(TimeStamp* otherTimeStamp);
};

