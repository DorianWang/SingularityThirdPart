
#ifndef SCREEN_TYPE_H
#define SCREEN_TYPE_H

#include <iostream>
#include <vector>

#include "libraryIncluder.h"

#define EXPECTED_INSTRUCTION_SIZE 4


//http://stackoverflow.com/questions/6423729/get-current-cursor-position


template <typename Q> class screenInstruct
{


bool isVoid;

   public:
int Xpos; int Ypos;

screenInstruct();

bool parseInput(std::string input);



std::string instructionText;

std::string dataOutName;
//Name of the macro that the main function will provide.

bool dataOutGet;
Q* dataOut;
};


template <typename Q> screenInstruct<Q>::screenInstruct()
{

   isVoid = std::is_same<Q, void>::value;
   dataOutGet = false;
   dataOut = NULL;
}


//This function parses input, obtaining the x and y coordinates, as well as
//the macro required. The macro is then replaced by a '@'.
template <typename Q> bool screenInstruct<Q>::parseInput(std::string input)
{
   std::vector <std::string> parsedInput;
   stringFunc stringParser;

   parsedInput = stringParser.parseAllTokens(input, "\\");

   if (parsedInput.size() != EXPECTED_INSTRUCTION_SIZE){
      return false;
   }



   //Ignore the first token, as it contains the type data.
   //If this becomes an issue,
   //http://www.cplusplus.com/reference/stdexcept/invalid_argument/
   Xpos = atoi(parsedInput.at(1).c_str()); Ypos = atoi(parsedInput.at(2).c_str());

   std::string tempString = parsedInput.at(3);

   //http://stackoverflow.com/questions/7647958/how-to-check-if-the-template-parameter-of-the-function-has-a-certain-type
   if (isVoid){
      instructionText = tempString;
      return true;
   }


   int i = 0;
   std::size_t firstBracket = tempString.find('{');
   std::size_t secondBracket = tempString.find('}', firstBracket+1);

   if (firstBracket == npos || secondBracket == npos){
      //Bad stuff happened. Stop here.
   }

   //Get the macro in between the two brackets, and then remove it and the brackets.

   instructionText = tempString.substr(firstBracket + 1, secondBracket - firstBracket - 1);
   tempString.erase(firstBracket, secondBracket - firstBracket +1);
   tempString.insert(firstBracket, "@");



   //std::string tempDataIn

   //dataOutName = ;


return true;
}


/*
struct screenInstructionsInt
{
int Xpos; int Ypos;

std::string instructionText;
//Example: Health: [PLAYER_HEALTH]

//Remember to set to zero when created.
int* dataOut;

};
*/





#endif
