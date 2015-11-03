#ifndef SCRIPTVARIABLES_H_INCLUDED
#define SCRIPTVARIABLES_H_INCLUDED

#include <iostream>
#include <unordered_map>
#include <vector>



class externalVariables
{
   //Variable names must be converted from strings to ints. This class will store the map of strings.
   std::vector <int> Values;

   std::unordered_map <std::vector, int> varNameMap;

   externalVariables()
   {

   }

   int getValue(std::string input){
      try{
         return Values[varNameMap.at(input)]
      }
      catch (const std::out_of_range& oor) {
         //Add a error log
      }
   }

   int getValue (int input){
      return Values[input];
   }



















};










#endif // SCRIPTVARIABLES_H_INCLUDED
