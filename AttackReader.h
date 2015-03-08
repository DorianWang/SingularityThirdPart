#ifndef ATTACKREADER_H_INCLUDED
#define ATTACKREADER_H_INCLUDED

#include "DamageCalculator.h"
#include "libraryIncluder.h"

#define ATTACK_DATA_LOCATION "\Data\Combat\Attacks"

class attackReader
{

FileIO file;



public:

   std::vector <attackType> attacks;
   std::string fileName;

   bool readFile(std::string newFileName);


};




#endif // ATTACKREADER_H_INCLUDED




