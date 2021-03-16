#pragma once
#include "TimeSpan.h"
#include <vector>
class Event;
class Entity
{
protected:
	int id = 0;
	std::vector<Event*> events;
public:
    int getId() { return id; }
    void setId(int id) { this->id = id; }
    void addEvent(Event* event);
    std::vector<Event*> getEvents() { return events; }
    int getNumOfEvents();
};

