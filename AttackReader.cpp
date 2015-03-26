
#include "AttackReader.h"


//Screens are always stored in the data folder.
//However, the FileIO object passed has all the necessary information.
bool attackReader::readFile(std::string newFileName)
{
   std::string tempInput;
   std::vector <std::string> parserOutput;

   FileIO* file = new FileIO;
   newFileName = ATTACK_DATA_LOCATION + newFileName;

   file -> dataOpenFile(newFileName, false);

   stringFunc stringModder;

while (true){

   if (file -> readLine(&tempInput) == false){
      break;//No more attacks to read!
   }

   if (tempInput.at(0) == '#'){
      continue; //Comment found.
   }

   tempInput = stringModder.trimWhitespace(tempInput, " /t"); // Remove leading and trailing spaces.

   if (tempInput.substr(0, 9) == "end file;"){
      break; //End of file.
   }

   }

//isGood = true;
file -> closeFile();
}

}


bool attackReader::addScaling(FileIO* file, std::vector <attackScaling>* outputVector)
{

}


//String checker:
/*
std::string foo("--foo");
if (text.rfind(foo, 0) == string::npos){
   //Bad
}

*/













