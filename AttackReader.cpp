
#include "AttackReader.h"


//Screens are always stored in the data folder.
//However, the FileIO object passed has all the necessary information.
bool attackReader::readFile(std::string newFileName)
{
   std::string tempInput;
   std::vector <std::string> parserOutput;

   //file -> textOpenFile(screenFileName, false);
   //No longer needed.

   stringFunc stringParcer;

   if (file -> readLine(&tempInput)){
      attacks.push_back(parseLine(tempInput, "\\"));
   }
   else
   {
      //Wut? Broken
   }



while (file -> readLine(&tempInput)){
   //Empty lines are skipped.
   if (tempInput.empty()){
      continue;
   }

   //Lines with a pound at the beginning are ignored, these are comments.
   if (tempInput.at(0) == '#'){
      //cout << "Read comment: " << tempInput << endl;
      continue;
   }


   if (createInstruction(tempInput)){
      //cout << tempInput << endl;
      continue;
   }

//Something bad happened.
}

isGood = true;
file -> closeFile();
}




