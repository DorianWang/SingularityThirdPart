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







bool makeNewScreen (std::string screenName, std::string screenLocation)
{
   FileIO inputFile;
   std::string filePath = screenLocation + "/" + screenName + ".scrn";
   inputFile.textOpenFile(filePath, false);

   ScreenType* tempScreen = new ScreenType(screenName, &inputFile);

   for (int i = 0; i < tempScreen ->instructionsString.size(); i++){
      //TODO: Turn instructions into instruct pointers.
   }

}
