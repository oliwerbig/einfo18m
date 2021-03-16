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
#include <vector>
#include <map>

using namespace std;

vector<Event> events;
map<int, Entity> entities;
map<int, TimeStamp> timeStamps;

void processFile();
Entity findEntityFirstIn();
Entity findEntityLastOut();
void writeEntityAndNumOfEventsToFile();
map<int, Entity*> findEntitiesStillIn();
TimeStamp findTimeStampWithMostEntitiesIn();
TimeSpan calculateTotalTimeInOfEntity(Entity* entity);

int main()
{
    setlocale(LC_ALL, "hun");

    // 1.
    processFile();

    // 2.
    cout << endl;
    cout << "2. feladat" << endl;
    cout << "Az els� bel�p�: " << findEntityFirstIn().getId() << endl;
    cout << "Az utols� kil�p�: " << findEntityLastOut().getId() << endl;

    // 3.
    writeEntityAndNumOfEventsToFile();

    // 4.
    cout << endl;
    cout << "4. feladat" << endl;
    cout << "A v�g�n a t�rsalg�ban voltak: ";
    map<int, Entity*> entitiesStillIn = findEntitiesStillIn();
    for (pair<int, Entity*> entity : entitiesStillIn)
    {
        cout << entity.second->getId() << " ";
    }
    cout << endl;

    // 5.
    cout << endl;
    cout << findTimeStampWithMostEntitiesIn().getTimeAsString() + "-kor voltak a legt�bben a t�rsalg�ban." << endl;

    // 6.
    cout << endl;
    cout << "6. feladat" << endl;
    cout << "Adja meg a szem�ly azonos�t�j�t! ";
    int input;
    cin >> input;

    // 7.
    /// for (Event* event : entities[input].getEvents()) // Valahol anom�lia van, a biztons�g kedv��rt m�shogy csin�lom
    cout << endl;
    cout << "7. feladat" << endl;
    for (Event event : events)
    {
        if (event.getEntityId() == input)
        {
            if (event.getDirection() == In)
            {
                cout << event.getTimeAsString() << "-";
            }
            else if (event.getDirection() == Out)
            {
                cout << event.getTimeAsString() << endl;
            }
        }
    }
    cout << endl;

    // 8.
    cout << endl;
    cout << "8. feladat" << endl;
    TimeSpan totalTimeInOfEntity = calculateTotalTimeInOfEntity(&entities[input]);
    if (entitiesStillIn.find(input) == entitiesStillIn.end())
    {
        cout << "A(z) " << input << "-es szem�ly �sszesen " << totalTimeInOfEntity.getTimeInMinutes() << " percet volt bent, a megfigyel�s v�g�n nem volt a t�rsalg�ban." << endl;
    }
    else
    {
        cout << "A(z) " << input << "-es szem�ly �sszesen " << totalTimeInOfEntity.getTimeInMinutes() << " percet volt bent, a megfigyel�s v�g�n a t�rsalg�ban volt." << endl;
    }

    return 0;
}

void processFile()
{
    ifstream inputFile;
    inputFile.open("ajto.txt");
    string line;
    while (getline(inputFile, line))
    {
        Event event(line);
        events.push_back(event);

        if (entities.find(event.getEntityId()) == entities.end())
        {
            Entity entity;
            entity.setId(event.getEntityId());
            entities[event.getEntityId()] = entity;
        }

        if (timeStamps.find(event.getTimeInMinutes()) == timeStamps.end())
        {
            TimeStamp timeStamp(event.getTimeInMinutes());
            timeStamps[event.getTimeInMinutes()] = timeStamp;
        }

        entities[event.getEntityId()].addEvent(&events.back());
        timeStamps[event.getTimeInMinutes()].addEvent(&events.back());

        for (Event e : events)
        {
            if (e.getDirection() == In)
            {
                timeStamps[event.getTimeInMinutes()].addEntityInside(&entities[e.getEntityId()]);
            }
            else if (e.getDirection() == Out)
            {
                timeStamps[event.getTimeInMinutes()].removeEntityInside(&entities[e.getEntityId()]);
            }
        }
    }
    inputFile.close();
}

Entity findEntityFirstIn()
{
    Entity entityFirstIn;
    for (Event event : events)
    {
        if (event.getDirection() == In)
        {
            entityFirstIn = entities[event.getEntityId()];
            break;
        }
    }

    return entityFirstIn;
}

Entity findEntityLastOut()
{
    Entity entityLastOut;
    for (Event event : events)
    {
        if (event.getDirection() == Out)
        {
            entityLastOut = entities[event.getEntityId()];
        }
    }

    return entityLastOut;
}

void writeEntityAndNumOfEventsToFile()
{
    ofstream outputFile;
    outputFile.open("athaladas.txt");
    for (pair<int, Entity> entity : entities)
    {
        outputFile << entity.first << " " << entity.second.getNumOfEvents() << endl;
    }
    outputFile.close();
}

map<int, Entity*> findEntitiesStillIn()
{
    map<int, Entity*> entitiesStillIn;
    TimeStamp lastTimeStamp;

    for (pair<int, TimeStamp> timeStamp : timeStamps)
    {
        if (timeStamp.second.getTimeInMinutes() > lastTimeStamp.getTimeInMinutes())
        {
            entitiesStillIn = timeStamp.second.getEntitiesInside();
        }
    }

    return entitiesStillIn;
}

TimeStamp findTimeStampWithMostEntitiesIn()
{
    TimeStamp timeStampWithMostEntitiesIn;
    for (pair<int, TimeStamp> timeStamp : timeStamps)
    {
        if (timeStamp.second.getNumOfEntitiesInside() > timeStampWithMostEntitiesIn.getNumOfEntitiesInside())
        {
            timeStampWithMostEntitiesIn = timeStamps[timeStamp.second.getTimeInMinutes()];
        }
    }

    return timeStampWithMostEntitiesIn;
}

TimeSpan calculateTotalTimeInOfEntity(Entity* entity) //Itt is valami nem m�k�d�tt j�l, ez�rt hanyagoltam az OO megold�st
{
    TimeSpan totalTimeIn;

    std::vector<Event> in;
    std::vector<Event> out;
    for (Event event : events)
    {
        if(event.getEntityId() == entity->getId())
        if (event.getDirection() == In)
        {
            in.push_back(event);
        }
        else if (event.getDirection() == Out)
        {
            out.push_back(event);
        }
    }
    Event endOfLogging;
    endOfLogging.setTimeInMinutes(900);
    out.push_back(endOfLogging);

    TimeStamp a;
    TimeStamp b;
    for (int i = 0; i < in.size(); i++)
    {
        a.setTimeInMinutes(in[i].getTimeInMinutes());
        b.setTimeInMinutes(out[i].getTimeInMinutes());
        totalTimeIn.setTimeInMinutes(totalTimeIn.getTimeInMinutes() + a.calculateTimeElapsed(&b).getTimeInMinutes());
    }

    return totalTimeIn;
}