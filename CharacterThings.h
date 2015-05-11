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
   bool setInt(unsigned short setInput){ intelligence = setInput; if(checkValue ){ intelligence = MAX_STAT; return true;} return false; }
   bool setWis(unsigned short setInput){ if( setInput < MAX_STAT ){ wisdom = MAX_STAT; return true;} return false; }
   bool setCha(unsigned short setInput){ if( setInput < MAX_STAT ){ charisma = MAX_STAT; return true;} return false; }
   bool setStr(unsigned short setInput){ if( setInput < MAX_STAT ){ strength = MAX_STAT; return true;} return false; }
   bool setAgi(unsigned short setInput){ if( setInput < MAX_STAT ){ agility = MAX_STAT; return true;} return false; }
   bool setEnd(unsigned short setInput){ if( setInput < MAX_STAT ){ endurance = MAX_STAT; return true;} return false; }

   //Increments by the input value.
   bool incrInt(short setInput){ if( setInput + intelligence < MAX_STAT ){ intelligence = MAX_STAT; return true;} return false; }
   bool incrWis(short setInput){ if( setInput + wisdom < MAX_STAT ){ wisdom = MAX_STAT; return true;} return false; }
   bool incrCha(short setInput){ if( setInput + charisma < MAX_STAT ){ charisma = MAX_STAT; return true;} return false; }
   bool incrStr(short setInput){ if( setInput + strength < MAX_STAT ){ strength = MAX_STAT; return true;} return false; }
   bool incrAgi(short setInput){ if( setInput + agility < MAX_STAT ){ agility = MAX_STAT; return true;} return false; }
   bool incrEnd(short setInput){ if( setInput + endurance < MAX_STAT ){ endurance = MAX_STAT; return true;} return false; }

   bool checkValue(unsigned short Input){ if( Input < MAX_STAT ){ return true; } return false; }


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
































