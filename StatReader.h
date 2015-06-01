

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


#define SKILL_FILE_LOCATION "Data/Skills/"
#define FILE_LEARNED_SKILLS "learnedSkills.txt"


class statReader
{

FileIO statFile;





public:

   statReader();
   ~statReader();


   std::vector <std::string> statList;

};













#endif // STATREADER_H_INCLUDED































