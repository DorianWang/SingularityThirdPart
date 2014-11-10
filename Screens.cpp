

#include "Screens.h"




ScreenType::ScreenType(int minX, int minY, int maxX, int maxY, std::string newScreenName, Keypress* keyOrig, ConsoleOptions* COrig)
{
consoleMod = COrig;
keyIO = keyOrig;
}

ScreenType::~ScreenType()
{


}
