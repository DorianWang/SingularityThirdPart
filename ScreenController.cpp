#include "ScreenController.h"



bool ScreenControl::popFirstUnsetInstructPointer(instructDataOut* output)
{
   if (UnsetPointerList.size() > 0){
      instructDataOut tempData;
      tempData = UnsetPointerList.front();
      UnsetPointerList.pop_front();
      *output = tempData;
      return true;
   }
   return false;
}


std::vector <instructDataOut> ScreenControl::getAllUnsetInstruct()
{
   std::vector <instructDataOut> tempVector;

   for (std::list <instructDataOut>::iterator it = UnsetPointerList.begin(); it != UnsetPointerList.end(); ++it){
      tempVector.push_back(*it);
   }
UnsetPointerList.clear();
return tempVector;
}







int ScreenControl::makeNewScreen (std::string screenName, std::string screenLocation)
{
   FileIO inputFile;
   std::string filePath = DATA_FOLDER + screenLocation + "/" + screenName + ".sc";
   inputFile.textOpenFile(filePath, false);

   if (! inputFile.isOpen){
      return -1;
   }

   ScreenType* tempScreen = new ScreenType(screenName, &inputFile);

   if (!tempScreen -> isGood){
      return -1;
   }
   screenArray.push_back(tempScreen);

//Things to list of stuff
//{

   for (int i = 0; i < tempScreen -> instructionsString.size(); i++){
      instructDataOut tempInstruct;
      tempScreen -> instructionsString[i] -> dataOutGet = true;

      tempInstruct.macroInstruct = tempScreen -> instructionsString[i] -> dataOutName;
      tempInstruct.variablePointerPointer = (void*) tempScreen -> instructionsString[i] -> dataOut;

      UnsetPointerList.push_back(tempInstruct);
   }

   for (int i = 0; i < tempScreen -> instructionsInt.size(); i++){
      instructDataOut tempInstruct;
      tempScreen -> instructionsString[i] -> dataOutGet = true;

      tempInstruct.macroInstruct = tempScreen -> instructionsInt[i] -> dataOutName;
      tempInstruct.variablePointerPointer = (void*) tempScreen -> instructionsInt[i] -> dataOut;

      UnsetPointerList.push_back(tempInstruct);
   }

   for (int i = 0; i < tempScreen -> instructionsDouble.size(); i++){
      instructDataOut tempInstruct;
      tempScreen -> instructionsString[i] -> dataOutGet = true;

      tempInstruct.macroInstruct = tempScreen -> instructionsDouble[i] -> dataOutName;
      tempInstruct.variablePointerPointer = (void*) tempScreen -> instructionsDouble[i] -> dataOut;

      UnsetPointerList.push_back(tempInstruct);
   }

//}

return screenArray.size() - 1;//Good! I think...
}




int ScreenControl::getScreenIndex(std::string screenNameSearch)
{
   for (int i = 0; i < screenArray.size(); i++){
      if (screenArray[i] -> screenName == screenNameSearch){
         return i;
      }
   }
   return -1;
}

std::string ScreenControl::parseInstruct(std::string input, char inputType, ...)
{
   //Void / NULL
   if (inputType == 'v'){
      return input;
   }

   va_list args;
   va_start(args, inputType);
   std::stringstream ss(stringstream::in | stringstream::out);

   stringFunc stringTest; //What do I plan to use for the delimiter?
   //'@'? It is not used much in normal writing, so...

   //Breaks the input into components, separated by the '@' character.
   //First finds the location of the '@'

   size_t delim = input.find('@', 0);

   std::string firstString = input.substr(0, delim);
   std::string secondString = input.substr(delim + 1) ;

   ss<<firstString;

   //Int
   if (inputType == 'i'){
      int* inputVar = va_arg(args, int*);
      ss << *inputVar;
   }

   //Percent output, takes doubles.
   //1 digit after decimal.
   else if (inputType == 'p'){
      double* inputVar = va_arg(args, double*);

      if (*inputVar < 0.001){
         ss << "0%";
         //Basically 0.
      }
      else if (*inputVar < 0.01){
         ss << "<0.1%";
         //Very unlikely, but can happen. Assumes less than 0.1%, but greater than 0.01%
      }
      else if (*inputVar < 0.1){
         //Conversion to percent. Two decimals. "9.98%".
         ss << std::setprecision(2) << fixed ;
         ss << (*inputVar * 100)  << '%';
      }
      else {
         //Conversion to percent. One decimal. "64.8%".
         ss << std::setprecision(1) << fixed ;
         ss << (*inputVar * 100)  << '%';
      }

   }

   //Double
   //Always has 5 character or less, including the dot.
   //Has three modes, tiny, small, and large
   else if (inputType == 'd'){
      double* inputVar = va_arg(args, double*);


      //Tiny
      if (*inputVar < 1.00){
         ss << std::setprecision(3) << fixed;
         ss << *inputVar;
      }
      //Small
      else if (*inputVar < 10000.0){
         ss << std::setprecision(4) << fixed;
         ss << *inputVar;
      }
      //Large
      else
      {
         ss.unsetf(ios_base::floatfield);
         ss << std::setprecision(5);
      }

   }

   //String
   else if (inputType == 's'){
      std::string* inputVar = va_arg(args, std::string*);
      ss << *inputVar;
   }

   //Default return, this shouldn't happen, but is not a crash worthy error.
   else {
      return std::string();//empty string, not good.
   }

   //Completes the instruction.
   ss<< secondString;
   return ss.str();

}




bool ScreenControl::outputScreen(int screenIndex)
{
   //If the input cannot be in the array, return false.
   if (screenArray.size() <= screenIndex || screenIndex < 0){
      return false;
   }

   //Loop until done
   //{
   for (int i = 0; i < screenArray[screenIndex] -> instructionsInt.size(); i++){
         //TODO: change location, create parseInstruct, and finish
      //cout << parseInstruct(screenArray[screenIndex] -> instructionsInt[i]);
   }

   for (int i = 0; i < screenArray[screenIndex] -> instructionsInt.size(); i++){
         return i;

   }

   for (int i = 0; i < screenArray[screenIndex] -> instructionsInt.size(); i++){
         return i;

   }



}




















