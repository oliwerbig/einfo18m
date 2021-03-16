// einfo18m.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Time.h"
#include "TimeSpan.h"
#include "TimeStamp.h"
#include "Entity.h"
#include "Event.h"
#include "Direction.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<Event> events;
map<int, Entity> entities;
map<int, TimeStamp> timeStamps;

void processFile()
{
    ifstream inputFile;
    inputFile.open("ajto.txt");
    string line;
    while (getline(inputFile, line))
    {
        Event event(line);
        events.push_back(event);

        if (entities.find(event.getEntity()->getId()) == entities.end())
        {
            entities[event.getEntity()->getId()] = *event.getEntity();
        }

        if (timeStamps.find(event.getTimeStamp()->getTimeInMinutes()) == timeStamps.end())
        {
            timeStamps[event.getTimeStamp()->getTimeInMinutes()] = *event.getTimeStamp();
        }

        entities[event.getEntity()->getId()].addEvent(&events.back());
        timeStamps[event.getTimeStamp()->getTimeInMinutes()].addEvent(&events.back());

        if (event.getDirection() == In)
        {
            timeStamps[event.getTimeStamp()->getTimeInMinutes()].addEntityInside(&entities[event.getEntity()->getId()]);
        }
        else if (event.getDirection() == Out)
        {
            timeStamps[event.getTimeStamp()->getTimeInMinutes()].removeEntityInside(&entities[event.getEntity()->getId()]);
        }
    }
    inputFile.close();
}

int main()
{
    processFile();
    cout << events[3].getTimeStamp()->getHour() << endl;
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
