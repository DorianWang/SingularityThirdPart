
#include "AttackReader.h"


//Screens are always stored in the data folder.
//However, the FileIO object passed has all the necessary information.
bool attackReader::readFile(std::string newFileName)
{
   std::string tempInput;
   std::vector <std::string> parserOutput;

   FileIO* file = new FileIO;

   file -> dataOpenFile(newFileName, false);

   stringFunc stringParcer;

while (true){
   attackType newAttack;

   if (file -> readLine(&tempInput)){
      newAttack.name = file -> readLine(&tempInput);
   }
   else
   {
      break;//No more attacks to read!
   }



   while (true){

      if (file -> readLine(&tempInput) == false){
         return false; //Broken things!
      }

      //Empty lines are skipped.
      if (tempInput.empty()){
         continue;
      }

      //Lines with a pound at the beginning are ignored, these are comments.
      if (tempInput.at(0) == '#'){
         //cout << "Read comment: " << tempInput << endl;
         continue;
      }

      if (tempInput == "end;")
      //std::size_t stringEnd = tempInput.find(';', tempInput.begin());

      if (true/*createInstruction(tempInput)*/){
         //cout << tempInput << endl;
         continue;
      }

   }

//isGood = true;
file -> closeFile();
}

}


bool attackReader::addScaling(FileIO* file, std::vector <attackScaling>* outputVector)
{

}


//String checker:
/*
std::string foo("--foo");
if (text.rfind(foo, 0) == string::npos){
   //Bad
}

*/













