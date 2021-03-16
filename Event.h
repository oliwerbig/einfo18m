#pragma once
#include "Direction.h"
#include "Time.h"
#include <string>
class TimeStamp;
class Entity;
class Event
    : public Time
{
protected:
	int entityId = 0;
	Direction direction = In;
public:
    Event();
    Event(std::string payload);
    int getEntityId() { return entityId; }
    void setEntityId(int entityId) { this->entityId = entityId; }
    Direction getDirection() { return direction; }
    void setDirection(Direction direction) { this->direction = direction; }
    std::string getDirectionAsString();
    void setDirectionFromString(std::string directionString);
    void parsePayload(std::string payload);
    const std::string directionToString[2] = { "be", "ki" };
};

