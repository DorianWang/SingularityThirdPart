#ifndef CHARACTERTHINGS_H_INCLUDED
#define CHARACTERTHINGS_H_INCLUDED


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


//Note that skills can be negative...
struct learnedSkills
{

//Combat skills
//{

   //Physical skills
   short stabSkill;
   short slashSkill;
   short crushSkill;
   short rangedSkill;

   //Modifies a few abilities, which are quite special.
   short beastAffinity;

   //Magic skills
   short arcaneAffinity;
   short elementalAffinity;

   //Two different skills that both provide dodge and anti-dodge. One is based off int and wis, the other is agi and end
   short foresight;
   short martialReflex;

//}

   //Skills used on both friendly and less than friendly NPCs to get them to do things you want.
   //Persuasion is int and cha, posture is cha and agi
   short persuasion;
   short posture;

   short curiosity;
   short technoScience;

   short biology; //All biology knowledge.
   short crystallography; //All crystal knowledge, improves chance of finding them, their sell value, and their efficacy.
   short geology; //All rock
   short chemistry;

   short botany;
   //TODO:

   short sneak;



   //Misc skills
   short armourer;// end and int, increases armour given by items.
   short packRat;// end and agi, gives carry space.

   short reader;// int and wis, increases ability to read items.
   short swimmer;// agi and end, allows character to swim

   int TODO;

};







#endif // CHARACTERTHINGS_H_INCLUDED
































