

#ifndef STATREADER_H_INCLUDED
#define STATREADER_H_INCLUDED

#include "libraryIncluder.h"
#include "eventLog.h"

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <map>
#include <string>
#include <sstream>

#define SKILL_FILE_LOCATION std::string("Data/Skills/")
#define FILE_LEARNED_SKILLS std::string("learnedSkills.txt")


class statReader
{

   FileIO statFile;

   std::vector <std::string> statList;
   std::map <std::string, int> statMap;

   stringFunc stringModder;

   bool parseInput(std::string input);

public:

   statReader();
   ~statReader();

   int statToInt(std::string input);
   std::string intToStat(int input);

   std::vector <std::string> getStatList();
   std::map <std::string, int> getStatMap();


};













#endif // STATREADER_H_INCLUDED































