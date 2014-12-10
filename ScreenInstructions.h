
#ifndef SCREEN_TYPE_H
#define SCREEN_TYPE_H

#include <iostream>
#include <vector>

#include "libraryIncluder.h"

#define EXPECTED_INSTRUCTION_SIZE 4


//http://stackoverflow.com/questions/6423729/get-current-cursor-position


template <typename Q> class screenInstruct
{

    typedef T type;




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
   dataOutGet = false;
   dataOut = NULL;
}

template <typename Q> bool screenInstruct<Q>::parseInput(std::string input)
{
   std::vector <std::string> parsedInput;
   stringFunc stringParser;

   parsedInput = stringParser.parseAllTokens(input, "\\");

   if (parsedInput.size() != EXPECTED_INSTRUCTION_SIZE){
      return false;
   }

   //http://stackoverflow.com/questions/7647958/how-to-check-if-the-template-parameter-of-the-function-has-a-certain-type
   if (type = )

   //Ignore the first token, as it contains the type data.
   //If this becomes an issue,
   //http://www.cplusplus.com/reference/stdexcept/invalid_argument/
   Xpos = atoi(parsedInput.at(1).c_str()); Ypos = atoi(parsedInput.at(2).c_str());

   std::string tempString = parsedInput.at(3);

   int i = 0;
   while (tempString.at(i) != 0){
      if (tempString.at(i) == '{'){
         break;
      }
      i++;
   }

   //std::string tempDataIn

   //dataOutName = ;
   //instructionText =

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
