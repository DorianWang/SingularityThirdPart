
#include "AttackReader.h"


//Screens are always stored in the data folder.
//However, the FileIO object passed has all the necessary information.
bool attackReader::readFile(std::string newFileName, std::vector <attackType>* outputVector)
{
   std::string tempInput;
   std::vector <std::string> parserOutput;

   FileIO* file = new FileIO;
   newFileName = ATTACK_DATA_LOCATION + newFileName;

   file -> dataOpenFile(newFileName, false);

   stringFunc stringModder;

   while (true){

      if (file -> readLine(&tempInput) == false){
         break;//No more attacks to read!
      }

      tempInput = stringModder.trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

      if (tempInput.at(0) == '#'){
         continue; //Comment found.
      }

      if (tempInput.substr(0, 9) == "end file;"){
         break; //End of file.
      }

      outputVector -> push_back( addAttack(file, &stringModder) );

   }

//isGood = true;
file -> closeFile();
}

attackType attackReader::addAttack(FileIO* file, stringFunc* stringModder)
{

std::string tempInput;

   while (true){

      if (file -> readLine(&tempInput) == false){
         return attackType();//No more attacks to read!
      }

      tempInput = stringModder -> trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

      if (tempInput.at(0) == '#'){
         continue; //Comment found.
      }

      if (tempInput.substr(0, 9) == "end file;"){
         break; //End of file.
      }

      //addAttack(FileIO attackFile, stringFunc* stringModder);

   }
}



bool attackReader::addScaling(FileIO* file, stringFunc* stringModder, std::vector <statScaling>* outputVector)
{

std::string tempInput;

   while (true){

      if (file -> readLine(&tempInput) == false){
         break;//No more attacks to read!
      }

      tempInput = stringModder -> trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

      if (tempInput.at(0) == '#'){
         continue; //Comment found.
      }

      if (tempInput.substr(0, 9) == "end file;"){
         break; //End of file.
      }

      //addAttack(FileIO attackFile, stringFunc* stringModder);

   }
}


//String checker:
/*
std::string foo("--foo");
if (text.rfind(foo, 0) == string::npos){
   //Bad
}

*/













