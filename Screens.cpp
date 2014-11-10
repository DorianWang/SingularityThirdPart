

#include "Screens.h"




ScreenType::ScreenType(int minX, int minY, int maxX, int maxY, std::string newScreenName, std::string screenFileLocation, FileIO* screenInput)
{
botX = minX; botY = minY; topX = maxX; topY = maxY;

parseScreenFile(screenInput, screenFileLocation);
}

ScreenType::~ScreenType()
{


}


//Screens are always stored in the data folder.
//However, the screenFileLocation string will provide all the necessary file structure information.
void ScreenType::parseScreenFile(FileIO* file, std::string screenFileName)
{
   std::string tempInput;
   file.textOpenFile(std::string fileName, false);

while (file.readLine(&tempInput)){

}

file.closeFile();
}



























