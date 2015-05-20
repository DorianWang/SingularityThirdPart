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
   bool checkOutput(unsigned short* Input){ if( *Input > MAX_STAT ){ *Input = MAX_STAT; return false; } return true; };
   bool checkInput(unsigned short* Input, short setInput){ if (setInput < 0 && setInput * (-1) > *Input){ *Input = 0; return false; }; return true; };


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
   bool setInt(unsigned short setInput){ intelligence = setInput; return checkOutput(&intelligence) == false; }
   bool setWis(unsigned short setInput){ wisdom = setInput; return checkOutput(&wisdom) == false; }
   bool setCha(unsigned short setInput){ charisma = setInput; return checkOutput(&charisma) == false; }
   bool setStr(unsigned short setInput){ strength = setInput; return checkOutput(&strength) == false; }
   bool setAgi(unsigned short setInput){ agility = setInput; return checkOutput(&agility) == false; }
   bool setEnd(unsigned short setInput){ endurance = setInput; return checkOutput(&endurance) == false; }

   //Increments by the input value.
   bool incrInt(short setInput){ if (!checkInput(&intelligence, setInput)){ return false; }; intelligence = intelligence + setInput; return checkOutput(&intelligence); }
   bool incrWis(short setInput){ if (!checkInput(&wisdom, setInput)){ return false; }; wisdom = wisdom + setInput; return checkOutput(&wisdom); }
   bool incrCha(short setInput){ if (!checkInput(&charisma, setInput)){ return false; }; charisma = charisma + setInput; return checkOutput(&charisma); }
   bool incrStr(short setInput){ if (!checkInput(&strength, setInput)){ return false; }; strength = strength + setInput; return checkOutput(&strength); }
   bool incrAgi(short setInput){ if (!checkInput(&agility, setInput)){ return false; }; agility = agility + setInput; return checkOutput(&agility); }
   bool incrEnd(short setInput){ if (!checkInput(&endurance, setInput)){ return false; }; endurance = endurance + setInput; return checkOutput(&endurance); }

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
































