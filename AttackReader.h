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

public:

   attackReader();

   std::vector <attackType> attacks;
   std::string fileName;

/**
Does things
@param things
@return things and stuff
*/
   bool readFile(std::string newFileName, std::vector <attackType>* outputVector);


};


}

#endif // ATTACKREADER_H_INCLUDED




