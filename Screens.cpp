

#include "Screens.h"




ScreenType::ScreenType(int minX, int minY, int maxX, int maxY, std::string newScreenName, std::string screenFileLocation, FileIO* screenInput)
{
botX = minX; botY = minY; topX = maxX; topY = maxY;

parseScreenFile(screenInput, screenFileLocation);
}

ScreenType::~ScreenType()
{


}


//Screens are always stored in the data folder.
//However, the screenFileLocation string will provide all the necessary file structure information.
void ScreenType::parseScreenFile(FileIO* file, std::string screenFileName)
{
   std::string tempInput;
   file -> textOpenFile(screenFileName, false);

while (file -> readLine(&tempInput)){
   if (tempInput.empty()){
      continue;
   }

   if (createInstruction(tempInput)){
      continue;
   }


}

file -> closeFile();
}







bool ScreenType::createInstruction(std::string instructionText)
{
   stringFunc stringParse;
   std::string tokenStr;
   tokenStr = stringParse.parseFirstToken(instructionText, "\\");
   //Using '\' for parsing. Might need to change it later.
   bool returnBool;

   if (tokenStr == "INT"){
      screenInstruct <int>* tempInstruct = new screenInstruct <int>;

      returnBool = tempInstruct -> parseInput(instructionText);
      if (returnBool){
         instructionsInt.push_back(tempInstruct);
         return returnBool;
      }

      //Nothing happened. Why?
      delete tempInstruct;
      return returnBool;
   }

   if (tokenStr == "STR"){
      screenInstruct <std::string>* tempInstruct = new screenInstruct <std::string>;

      returnBool = tempInstruct -> parseInput(instructionText);
      if (returnBool){
         instructionsString.push_back(tempInstruct);
         return returnBool;
      }

      //Nothing happened. Why?
      delete tempInstruct;
      return returnBool;
   }

   if (tokenStr == "DBL"){
      screenInstruct <double>* tempInstruct = new screenInstruct <double>;

      returnBool = tempInstruct -> parseInput(instructionText);
      if (returnBool){
         instructionsDouble.push_back(tempInstruct);
         return returnBool;
      }

      //Nothing happened. Why?
      delete tempInstruct;
      return returnBool;
   }

   if (!(tokenStr == "INT" || tokenStr == "STR" || tokenStr != "DBL")){
      return false; //Not an instruction.
   }
}



















