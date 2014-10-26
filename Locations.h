
#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

#include "Interactive.h"
#include "NPC.h"

struct mapCoord
{
   short xCoord;
   short yCoord;
};

class basicLocation
{

public:
   std::string nameShown;
   std::string description;

   unsigned short type; //This is what the land is.

};

class advancedLocation : public basicLocation
{

public:
   unsigned char numConnections;

   mapCoord thisCoord;
   //This is set in the map loading, with location
   //at index 0 being {0,0}.

   short connections[10];
   //0 is north, 1 is west, .. 3 is east, 4 is up, 5 is down, 6 is NE, 9 is SE, etc.
   //If there is nothing in that direction, -1 will be found. Otherwise, the
   //index of the connection in the map array will be found.



   std::vector <advancedInteractive> objects;

   std::vector <advancedChar> characters;

   std::vector <fightingChar> enemies;

   unsigned short tag;//This allows on enter/exit effects;
};



#endif
