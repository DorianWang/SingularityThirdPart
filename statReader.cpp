
#include "StatReader.h"







statReader::statReader()
{
   statFile.textOpenFile(SKILL_FILE_LOCATION + FILE_LEARNED_SKILLS, false);
}

std::string statReader::intToStat(int input)
{
   std::string returnStat = "";
   try
   {
      returnStat = statList.at(input);
   }
      catch (const std::out_of_range& oor)
   {
      stringstream ss; ss << "intToStat() failed to find " << input << ".";
      eventLogger -> addNewLog(ss.str());
      returnStat = -1;
   }
   return returnStat;
}


int statReader::statToInt(std::string input)
{
   int returnInt = 0;
   try
   {
      returnInt = statMap.at(input);
   }
      catch (const std::out_of_range& oor)
   {
      eventLogger -> addNewLog("statToInt() failed to find " + input + ".");
      returnInt = -1;
   }
   return returnInt;
}










