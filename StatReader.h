

#ifndef STATREADER_H_INCLUDED
#define STATREADER_H_INCLUDED

#include "libraryIncluder.h"

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <map>


#define SKILL_FILE_LOCATION std::string("Data/Skills/")
#define FILE_LEARNED_SKILLS std::string("learnedSkills.txt")


class statReader
{

FileIO statFile;

   std::vector <std::string> statList;
   std::map <std::string, int> statMap;


public:

   statReader();
   ~statReader();

   int statToInt(std::string input);
   std::string intToStat(int input);

};













#endif // STATREADER_H_INCLUDED































