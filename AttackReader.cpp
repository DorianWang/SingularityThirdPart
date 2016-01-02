
#include "AttackReader.h"
namespace attackScaling
{

   attackReader::attackReader()
   {
      statReader statTable;
      scalingMap = statTable.getStatMap();
      scalingList = statTable.getStatList();
      readScalingFile("Data/Attacks/Base_Attack_Scalings.txt");
   }

void attackReader::readScalingFile(const std::string inputFilePath)
{

   FileIO file;
   file.textOpenFile(inputFilePath, false);
   stringFunc stringModder;
   std::string readInput; std::string input;
   for (int i = 0; i < scalingMap.size(); i++){

   }


   while(file.readLine(&readInput)){

      input = stringModder.trimWhitespace(readInput, " \t");
      if (input != std::string() && input.at(0) != '#'){

         int curSize = scalingMap.size();
         scalingMap.insert(std::pair<std::string, int>(input, scalingList.size()));

         if (scalingMap.size() != curSize){
            scalingList.push_back(input);
            continue;
         }
         std::cout << input << " " << scalingMap[input] << std::endl;
         eventLogger -> addNewLog("File: AttackReader.cpp; Warning: Input: " + input + " already exists in the system.");
      }
   }
}



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
         eventLogger -> addNewLog("File: AttackReader.cpp; WARNING: Unexpected end of file: " + newFileName);
         break;
      }
      tempInput = stringModder.trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

      if (tempInput.at(0) == '#'){
         continue; //Comment found.
      }

      if (tempInput.substr(0, 9) == "end file;"){
         eventLogger -> addNewLog("File: AttackReader.cpp; INFO: No more attacks to read from file: " + newFileName);
         return true; //End of file.
      }

      outputVector -> push_back( addAttack(file, &stringModder, tempInput) );
   }

   file -> closeFile();
   eventLogger -> addNewLog("INFO: Closing file: " + newFileName);
   return true;
}

attackType attackReader::addAttack(FileIO* file, stringFunc* stringModder, std::string newAttackName)
{
   std::string tempInput;

   attackType tempAttack;
   tempAttack.name = newAttackName;
   //TODO: Make this function.
   //addCostScaling();

   addSubtypeScaling(file, stringModder, &(tempAttack.scaling));
}


bool attackReader::addSubtypeScaling(FileIO* file, stringFunc* stringModder, attackScaling* outputScalings)
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

std::string tempInput;

   while (true){

      if (file -> readLine(&tempInput) == false){
         return false;//No more attacks to read!
      }

      tempInput = stringModder -> trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

      if (tempInput.at(0) == '#'){
         continue; //Comment found.
      }

      for (int i = 0; i < nameOfScalings.size(); i++){
         if (tempInput.substr(0, 9) == nameOfScalings[i] + ';'){
            return addScaling(file, stringModder, &(outputScalings -> Scalings), nameOfScalings[i]);
         }
      }
   }
}


bool attackReader::addScaling(FileIO* file, stringFunc* stringModder, std::vector <statScaling>* outputScalings, const std::string scalingname)
{

   //Tested.

   stringFunc strMod;

   std::string tempInput;
   std::string tempParsedInput;
   double scalingValue;

      while (true){

         if (file -> readLine(&tempInput) == false){
            eventLogger -> addNewLog("WARNING: Unexpected end of file in function: addScaling");
            return false; //This shouldn't happen
         }

         tempInput = stringModder -> trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

         std::cout << tempInput << std::endl;

         if ( (tempInput.empty()) || tempInput.at(0) == '#'){
            continue; //Comment found.
         }
         std::cout << tempInput.substr(0, scalingname.length() + 1) << ' ' << scalingname + ';' << std::endl;
         if (tempInput.substr(0, scalingname.length() + 1) == scalingname + ';'){
            return true; //End of scaling block.
         }

         try {
            std::string token = strMod.parseFirstToken(tempInput, " \t");
            std::cout << token << std::endl;
            int newStatNum = scalingMap.at(token);
            token = strMod.popFirstToken(tempInput, " \t");
            statScaling newStatScaling;

            double scalingNum = std::strtod(token.c_str(), NULL);
            if (scalingNum != 0.0 && abs(scalingNum) != HUGE_VAL){
               newStatScaling.statNum = newStatNum; newStatScaling.scaling = scalingNum;
            }

            std::cout << newStatScaling.scaling << std::endl;

            outputScalings -> push_back(newStatScaling);;;
            eventLogger -> addNewLog("INFO: added scaling for: " + scalingname);
         }
         catch (const std::out_of_range& oor){
            eventLogger -> addNewLog("ERROR: no scaling for: " + strMod.parseFirstToken(tempInput, " \t")); //The string is not in the map. Most likely a spelling error.
         }
      }
   }

}











