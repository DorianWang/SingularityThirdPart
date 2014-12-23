

#include "Screens.h"




ScreenType::ScreenType(std::string newScreenName, FileIO* screenInput)
{
//botX = minX; botY = minY; topX = maxX; topY = maxY;
//Get these from the parsed file...

screenName = newScreenName;
isGood = false;

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

   //file -> textOpenFile(screenFileName, false);
   //No longer needed.

   stringFunc stringParcer;

   cout<<"1";

   if (file -> readLine(&tempInput)){
      parserOutput = stringParcer.parseAllTokens(tempInput, "\\");
   }
   else
   {
      //Wut? Broken
      cout<<"2";
   }

   botX = atoi(parserOutput.at(0).c_str()); botY = atoi(parserOutput.at(1).c_str());
   topX = atoi(parserOutput.at(2).c_str()); topY = atoi(parserOutput.at(3).c_str());

   screenID = parserOutput.at(4);

   cout<<"3";

while (file -> readLine(&tempInput)){
      cout<<"4";
   //Empty lines are skipped.
   if (tempInput.empty()){
      continue;
   }

   //Lines with a pound at the beginning are ignored, these are comments.
   if (tempInput.at(0) == '#'){
         cout<<"Read comment: "<<tempInput<<endl;
      continue;
   }


   if (createInstruction(tempInput)){
      cout<<tempInput<<endl;
      continue;
   }

//Something bad happened.
}

cout<<"5"<<endl;
isGood = true;
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

   //Percent, for formatted output. 99.9%, <0.01%, etc.
   if (tokenStr == "PCT"){
      screenInstruct <double>* tempInstruct = new screenInstruct <double>;

      returnBool = tempInstruct -> parseInput(instructionText);
      if (returnBool){
         instructionsPercentDouble.push_back(tempInstruct);
         return returnBool;
      }

      //Nothing happened. Why?
      delete tempInstruct;
      return returnBool;
   }


   if (tokenStr == "NUL"){
      screenInstruct <void>* tempInstruct = new screenInstruct <void>;
      returnBool = tempInstruct -> parseInput(instructionText);

      if (returnBool){
         instructionsVoid.push_back(tempInstruct);
         return returnBool;
      }

      delete tempInstruct;
      return returnBool;
   }

   if (!(tokenStr == "INT" || tokenStr == "STR" || tokenStr != "DBL")){
      return false; //Not a valid instruction.
   }
}



















