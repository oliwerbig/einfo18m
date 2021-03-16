#pragma once
#include "Direction.h"
#include <string>
class TimeStamp;
class Entity;
class Event
{
protected:
    TimeStamp* timeStamp;
	Entity* entity;
	Direction direction;
public:
    Event();
    Event(std::string payload);
    TimeStamp* getTimeStamp() { return timeStamp; }
    void setTimeStamp(TimeStamp* timeStamp) { this->timeStamp = timeStamp; }
    Entity* getEntity() { return entity; }
    void setEntity(Entity* entity) { this->entity = entity; }
    Direction getDirection() { return direction; }
    void setDirection(Direction direction) { this->direction = direction; }
    std::string getDirectionAsString();
    void setDirectionFromString(std::string directionString);
    void parsePayload(std::string payload);
    const std::string directionToString[2] = { "be", "ki" };
};

