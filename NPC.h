
#ifndef NPC_H
#define NPC_H

#include "DamageCalculator.h"
#include "CharacterThings.h"

#define MAX_STAT 200




class basicChar
{
public:
   std::string nameShown;
   unsigned short species;

   std::string description;
};

class advancedChar : public basicChar
{
public:

   int temporaryVariable;
   unsigned short faction; //Who is this? Who do they belong to?
   std::vector <short> unassignedVars;
};

class fightingChar : public advancedChar
{

public:
   bool isHostile;//If it is not hostile, it will not attack first.
   //equipmentContainer equipItems;
   std::vector <short> unassignedVars;
   baseStats thisStats;

};





#endif




















