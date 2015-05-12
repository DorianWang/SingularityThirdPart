#ifndef CHARACTERTHINGS_H_INCLUDED
#define CHARACTERTHINGS_H_INCLUDED

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
//TODO: Fix all the things here


   //{

   //Gets the current value.
   unsigned short getInt(){ return intelligence; }
   unsigned short getWis(){ return wisdom; }
   unsigned short getCha(){ return charisma; }
   unsigned short getStr(){ return strength; }
   unsigned short getAgi(){ return agility; }
   unsigned short getEnd(){ return endurance; }

   //Sets the value of the selected stat
   //Returning false means the value was set to the max.
   bool setInt(unsigned short setInput){ intelligence = setInput; if( checkValue(intelligence) == false ){ intelligence = MAX_STAT; return false;} return true; }
   bool setWis(unsigned short setInput){ wisdom = setInput; if( checkValue(wisdom) == false ){ wisdom = MAX_STAT; return false;} return true; }
   bool setCha(unsigned short setInput){ charisma = setInput; if( checkValue(charisma) == false ){ charisma = MAX_STAT; return false;} return true; }
   bool setStr(unsigned short setInput){ strength = setInput; if( checkValue(strength) == false ){ strength = MAX_STAT; return false;} return true; }
   bool setAgi(unsigned short setInput){ agility = setInput; if( checkValue(agility) == false ){ agility = MAX_STAT; return false;} return true; }
   bool setEnd(unsigned short setInput){ endurance = setInput; if( checkValue(endurance) == false ){ endurance = MAX_STAT; return false;} return true; }

   //Increments by the input value.
   bool incrInt(short setInput){ intelligence = intelligence + setInput; if( setInput + intelligence < MAX_STAT ){ intelligence = MAX_STAT; return true;} return false; }
   bool incrWis(short setInput){ if( setInput + wisdom < MAX_STAT ){ wisdom = MAX_STAT; return true;} return false; }
   bool incrCha(short setInput){ if( setInput + charisma < MAX_STAT ){ charisma = MAX_STAT; return true;} return false; }
   bool incrStr(short setInput){ if( setInput + strength < MAX_STAT ){ strength = MAX_STAT; return true;} return false; }
   bool incrAgi(short setInput){ if( setInput + agility < MAX_STAT ){ agility = MAX_STAT; return true;} return false; }
   bool incrEnd(short setInput){ if( setInput + endurance < MAX_STAT ){ endurance = MAX_STAT; return true;} return false; }

   bool checkValue(unsigned short* Input){ if( Input < MAX_STAT ){ return true; } return false; }


   //}

};


class learnedSkills
{
std::vector <double> skills;
};

class getLearnedSkills
{
   std::vector <std::string> skillInput;


public:
   getLearnedSkills(std::string skillsFile, std::string displayNameFile)
   {

   };

   int stringToSkill(std::string input);
   std::string skillToString(int input);

};






#endif // CHARACTERTHINGS_H_INCLUDED
































