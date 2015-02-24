
#ifndef NPC_H
#define NPC_H

#include "DamageCalculator.h"


#define MAX_STAT 200




class baseStats
{
//I need to add a function that controls changes to prevent any funny stuff.
   unsigned short intelligence;
   unsigned short wisdom;
   unsigned short charisma;
   unsigned short strength;
   unsigned short agility;
   unsigned short endurance;

   resistanceTypes resistance;

   int baseHealth;
   int baseMana;

public:

   //{

   //Gets the current value.
   unsigned short getInt(){ return intelligence; }
   unsigned short getWis(){ return wisdom; }
   unsigned short getCha(){ return charisma; }
   unsigned short getStr(){ return strength; }
   unsigned short getAgi(){ return agility; }
   unsigned short getEnd(){ return endurance; }

   //Sets the value of the selected stat
   bool getInt(unsigned short setInput){ if( setInput < MAX_STAT ){ intelligence = MAX_STAT; return true;} return false; }
   bool getWis(unsigned short setInput){ if( setInput < MAX_STAT ){ wisdom = MAX_STAT; return true;} return false; }
   bool getCha(unsigned short setInput){ if( setInput < MAX_STAT ){ charisma = MAX_STAT; return true;} return false; }
   bool getStr(unsigned short setInput){ if( setInput < MAX_STAT ){ strength = MAX_STAT; return true;} return false; }
   bool getAgi(unsigned short setInput){ if( setInput < MAX_STAT ){ agility = MAX_STAT; return true;} return false; }
   bool getEnd(unsigned short setInput){ if( setInput < MAX_STAT ){ endurance = MAX_STAT; return true;} return false; }

   //Increments by the input value.
   bool incrInt(short setInput){ if( setInput + intelligence < MAX_STAT ){ intelligence = MAX_STAT; return true;} return false; }
   bool incrWis(short setInput){ if( setInput + wisdom < MAX_STAT ){ wisdom = MAX_STAT; return true;} return false; }
   bool incrCha(short setInput){ if( setInput + charisma < MAX_STAT ){ charisma = MAX_STAT; return true;} return false; }
   bool incrStr(short setInput){ if( setInput + strength < MAX_STAT ){ strength = MAX_STAT; return true;} return false; }
   bool incrAgi(short setInput){ if( setInput + agility < MAX_STAT ){ agility = MAX_STAT; return true;} return false; }
   bool incrEnd(short setInput){ if( setInput + endurance < MAX_STAT ){ endurance = MAX_STAT; return true;} return false; }


   //}

};

struct learnedSkills
{
   int swordSkill;
   int TODO;

};


class basicChar
{
public:
   std::string nameShown;
   std::string species;

   std::string description;

   unsigned short tag;
};

class advancedChar : public basicChar
{
public:

   int temporaryVariable;
   int faction; //Who is this? Who do they belong to?
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





