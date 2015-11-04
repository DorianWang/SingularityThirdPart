#ifndef ATTACKREADER_H_INCLUDED
#define ATTACKREADER_H_INCLUDED

#include "DamageCalculator.h"
#include "libraryIncluder.h"
#include "eventLog.h"
#include "StatReader.h"

#define ATTACK_DATA_LOCATION "/Data/Combat/Attacks/"

namespace attackScaling
{

class attackReader
{

FileIO file;

bool addScaling(FileIO* file, stringFunc* stringModder, std::vector <statScaling>* outputScalings, std::string scalingname);
bool addSubtypeScaling(FileIO* file, stringFunc* stringModder, attackScaling* outputScalings);
attackType addAttack(FileIO* file, stringFunc* stringModder, std::string newAttackName);



std::vector <std::string> nameOfScalings = {"arcane", "elemental", "stab", "slash", "crush", "poison", "DOT", "void"};
//TODO: get scaling names from file, and make attackScaling dynamic as well.

public:

   attackReader();
   void readScalingFile(std::string inputFilePath);

   std::vector <attackType> attacks;
   std::string fileName;

   std::vector <std::string> scalingList;
   std::map <std::string, int> scalingMap;

/**
Does things
@param things
@return things and stuff
*/
   bool readFile(std::string newFileName, std::vector <attackType>* outputVector);


};


}

#endif // ATTACKREADER_H_INCLUDED










































