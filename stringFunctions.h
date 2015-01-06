
#ifndef STR_FUNCTIONS_H
#define STR_FUNCTIONS_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <cstdarg>


//It only works if I have the class. Why?
class stringFunc
{

public:

inline std::string parseFirstToken(std::string input, const char* delim);
inline std::string popFirstToken(std::string input, const char* delim);

inline std::vector <std::string> parseAllTokens(std::string input, const char* delim);

inline std::string tokensToString(std::vector <std::string> input, const char* delim);

//0 is the first character. Input of ("Hello", "In", 0) returns "Inllo"
inline std::string insertStringIntoString(std::string original, std::string input, int startIndex);

//inline bool stringToOther(std::string input; std::string outputType, ...);
};




//Implementation
//{


std::string stringFunc::parseFirstToken(std::string input, const char* delim)
{
   std::string output; int inputLength = input.length();
   int delimLength = strlen(delim);
   for (int i = 0; i < inputLength; i++){
      for (int j = 0; j < delimLength; j++){
         if (input.at(i) == delim[j]){
            return output;
         }
      }
      output += input.at(i);
   }
   return output;
}

std::string stringFunc::popFirstToken(std::string input, const char* delim)
{
   std::string output; int inputLength = input.length();
   std::string temp = parseFirstToken(input, delim);

   if (temp == input){ return NULL; }

   input.erase(0, temp.length());
   output = input;
   return output;
}


std::vector <std::string> stringFunc::parseAllTokens(std::string input, const char* delim)
{
   std::vector <std::string> tempVector;
   char tempCString[input.length()]; char* tempToken;
   strcpy(tempCString, input.c_str());
   tempToken = strtok(tempCString, delim);

   while(tempToken != NULL){
      tempVector.push_back(tempToken);
      tempToken = strtok(NULL, delim);
   }

   return tempVector;
}


//delim is automatically added in between tokens
std::string stringFunc::tokensToString(std::vector <std::string> input, const char* delim)
{
   std::string output;

   if (input.size() < 1){ return output; }//Returns an empty string.

   if (delim != NULL){
      output = input[0];
      for (int i = 1; i < input.size(); i++){
         output = output + delim + input[i];
      }
   }
   else
   {
      for (int i = 0; i < input.size(); i++){
         output = output + input[i];
      }
   }

   return output;
}

std::string stringFunc::insertStringIntoString(std::string original, std::string input, int startIndex)
{
   if ( input == std::string() ){
      return original;
   }

   if ( original.length() < startIndex + input.length() ){
      original.resize(startIndex, ' ');
      original = original + input;
   }

}



//}












#endif
