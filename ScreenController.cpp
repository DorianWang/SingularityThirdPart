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
   std::string filePath = screenLocation + "/" + screenName + ".scrn";
   inputFile.textOpenFile(filePath, false);

   ScreenType* tempScreen = new ScreenType(screenName, &inputFile);
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
      cout << parseInstruct(screenArray[screenIndex] -> instructionsInt[i]);
   }

   for (int i = 0; i < screenArray[screenIndex] -> instructionsInt.size(); i++){
      screenArray[screenIndex] -> screenName == screenNameSearch){
         return i;
      }
   }

   for (int i = 0; i < screenArray[screenIndex] -> instructionsInt.size(); i++){
      if (screenArray[i] -> screenName == screenNameSearch){
         return i;
      }
   }
   \\}


}




















