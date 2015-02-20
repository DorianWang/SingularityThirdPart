
#ifndef NPC_H
#define NPC_H


struct baseStats
{
//I need to add a function that controls changes to prevent any funny stuff.
   unsigned short intelligence;
   unsigned short wisdom;
   unsigned short charisma;
   unsigned short strength;
   unsigned short agility;
   unsigned short endurance;


   unsigned char magicKnowledge;
   unsigned char techKnowledge;

   char basePhysicalResistance;
   char baseMagicResistance;

   int baseHealth;
   int baseMana;

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





