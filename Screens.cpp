

#include "Screens.h"




ScreenType::ScreenType(std::string newScreenName, FileIO* screenInput)
{
//botX = minX; botY = minY; topX = maxX; topY = maxY;
//Get these from the parsed file...

screenName = newScreenName;

parseScreenFile(screenInput);
}

ScreenType::~ScreenType()
{


}


//Screens are always stored in the data folder.
//However, the FileIO object passed has all the necessary information.
void ScreenType::parseScreenFile(FileIO* file)
{
   std::string tempInput;
   std::vector <std::string> parserOutput;
   file -> textOpenFile(screenFileName, false);
   stringFunc stringParcer;

   if (file -> readLine(&tempInput)){

   }
   else
   {
      //Wut? Broken
   }

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



















