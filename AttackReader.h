#ifndef ATTACKREADER_H_INCLUDED
#define ATTACKREADER_H_INCLUDED

#include "DamageCalculator.h"
#include "libraryIncluder.h"

#define ATTACK_DATA_LOCATION "/Data/Combat/Attacks/"

class attackReader
{

FileIO file;

bool addScaling(FileIO* file, stringFunc* stringModder, statScaling* outputScalings, std::string scalingname);
bool addSubtypeScaling(FileIO* file, stringFunc* stringModder, attackScaling* outputScalings);
attackType addAttack(FileIO* file, stringFunc* stringModder, std::string newAttackName);

public:

   std::vector <attackType> attacks;
   std::string fileName;

   bool readFile(std::string newFileName, std::vector <attackType>* outputVector);


};




#endif // ATTACKREADER_H_INCLUDED




