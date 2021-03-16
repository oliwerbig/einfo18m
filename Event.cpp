#include "Event.h"
#include "Entity.h"
#include "TimeStamp.h"
#include <string>
#include <vector>
#include <map>
#include <sstream>


Event::Event()
{
    //ctor
}

Event::Event(std::string payload)
{
    parsePayload(payload);
}

std::string Event::getDirectionAsString()
{
    return directionToString[getDirection()];
}

void Event::setDirectionFromString(std::string directionString)
{
    if (directionString == directionToString[In])
    {
        setDirection(In);
    }
    else if (directionString == directionToString[Out])
    {
        setDirection(Out);
    }
}


void Event::parsePayload(std::string payload)
{
    char splitDelimiter = ' ';
    std::vector<std::string> values;
    std::stringstream stringStream(payload);
    std::string item;
    while (getline(stringStream, item, splitDelimiter)) {
        values.push_back(item);
    }

    setTime(stoi(values[0]), stoi(values[1]));
    setEntityId(stoi(values[2]));
    setDirectionFromString(values[3]);
}