
#include "StatReader.h"







statReader::statReader()
{
   statFile.textOpenFile(SKILL_FILE_LOCATION + FILE_LEARNED_SKILLS, false);
}

std::string statReader::intToStat(int input)
{

}


int statReader::statToInt(std::string input)
{
   try
   {
      statMap.at(input);
   }
      catch (const std::out_of_range& oor)
   {
      eventLogger -> addNewLog("statToInt() failed to find " + input + ".")
   }

}


