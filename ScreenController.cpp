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
   if (inputType = 'v'){
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


   //Int
   if (inputType == 'i'){
      int* inputVar = va_arg(args, int*);
      ss << *inputVar;

   return ss.str();
   }



   //Double
   if (inputType == 'd'){
      double* inputVar = va_arg(args, double*);

      //Conversion to percent.

      if (*inputVar){

      }

      ss<<std::setprecision(4);
      ss<< (*inputVar * 100)  << '%' <<endl;

   return ss.str();
   }

   //String
   if (inputType == 's'){
      std::string* inputVar = va_arg(args, std::string*);

   return ss.str();
   }

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




















