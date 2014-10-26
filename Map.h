
#ifndef MAP_H
#define MAP_H

#include "Locations.h"
#include "Effects.h"

struct locationWithExtras
{
   advancedLocation locationPointer;
   std::vector <int> effects;//This stores the index of the effect in the effect
//array.
};


class mapType
{

int numLocations;
std::vector <locationWithExtras> locations;
//Array of all locations;

//std::vector <locationWithExtras*> effectLocations





};


#endif
