#ifndef ATTACKREADER_H_INCLUDED
#define ATTACKREADER_H_INCLUDED

#include "DamageCalculator.h"
#include "libraryIncluder.h"

#define ATTACK_DATA_LOCATION "/Data/Combat/Attacks/"

class attackReader
{

FileIO file;

bool addScaling(FileIO* file, stringFunc* stringModder, std::vector <statScaling>* outputVector);
attackType addAttack(FileIO* file, stringFunc* stringModder);

public:

   std::vector <attackType> attacks;
   std::string fileName;

   bool readFile(std::string newFileName, std::vector <attackType>* outputVector);


};




#endif // ATTACKREADER_H_INCLUDED




