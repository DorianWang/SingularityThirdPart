#ifndef STATCOMPILER_H_INCLUDED
#define STATCOMPILER_H_INCLUDED

#ifndef IS_RELEASE

#include "StatReader.h"
//Need a class to get all data from files.

class statCompiler
{
   std::vector <std::string> importNames;
   statReader statInput;

   statCompiler()
   {
      importNames = statInput.testing();
   }

   nameSwitcher()
   {
      //Use this to try to change the names into the numbers, and output as a data file,
      // as opposed to a text file.
      /*
      for (int i = 0; i < (numberOfValues); i++){
         for (int j = 0; j < testList.size(); j++){
            replace (statInput.statToInt(testList[j]))
         }
      }
      */

      FileIO outputFile;






   }
















};


#endif // Has not been compiled yet.

#endif // STATCOMPILER_H_INCLUDED











