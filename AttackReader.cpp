
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
         return true;//No more attacks to read!
         //TODO: Add some way of adding errors to an error log.
         //TODO: Add an event log.
         //This one would be "Warning: Unable to continue reading file."
      }

      tempInput = stringModder.trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

      if (tempInput.at(0) == '#'){
         continue; //Comment found.
      }

      if (tempInput.substr(0, 9) == "end file;"){
         return true; //End of file.
      }

      outputVector -> push_back( addAttack(file, &stringModder, tempInput) );

   }

//isGood = true;
file -> closeFile();
}

attackType attackReader::addAttack(FileIO* file, stringFunc* stringModder, std::string newAttackName)
{

std::string tempInput;
int tempLength = 5 + newAttackName.size();
attackType tempAttack;

   while (true){

      if (file -> readLine(&tempInput) == false){
         return attackType();//No more attacks to read!
      }

      tempInput = stringModder -> trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

      if (tempInput.at(0) == '#'){
         continue; //Comment found.
      }

      if (tempInput.substr(0, tempLength) == "end " + newAttackName + ';'){
         break; //End of file.
      }

      //This doesn't have to be hard coded, but this should catch my mistakes as opposed to other ways.
      if (tempInput.substr(0, 5) == "physical"){
         addScaling(file, stringModder, &(tempAttack.scaling), "physical");
         continue;
      }

      if (tempInput.substr(0, 5) == "magic"){
         addScaling(file, stringModder, &(tempAttack.scaling), "magic");
         continue;
      }

      if (tempInput.substr(0, 5) == "void"){
         addScaling(file, stringModder, &(tempAttack.scaling), "void");
         continue;
      }
   }
}



bool attackReader::addScaling(FileIO* file, stringFunc* stringModder, attackScaling* outputScalings, std::string scalingname)
{
/*
struct attackScaling
{
   std::vector <statScaling> arcaneScaling;
   std::vector <statScaling> elementalScaling;

   std::vector <statScaling> stabScaling;
   std::vector <statScaling> slashScaling;
   std::vector <statScaling> crushScaling;
   std::vector <statScaling> poisonScaling;
   std::vector <statScaling> DOTScaling;

   std::vector <statScaling> voidScaling;
};
*/
std::vector <std::string> nameOfScalings = {"arcane", "elemental", "stab", "slash", "crush", "poison", "DOT", "void"};

std::string tempInput;

   while (true){

      if (file -> readLine(&tempInput) == false){
         break;//No more attacks to read!
      }

      tempInput = stringModder -> trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

      if (tempInput.at(0) == '#'){
         continue; //Comment found.
      }

      for (int i = 0; i < nameOfScalings.size(); i++){
         if (tempInput.substr(0, 9) == "end " + scalingname + ';'){
            break; //End of file.
         }
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













