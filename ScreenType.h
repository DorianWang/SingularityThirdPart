
#ifndef SCREEN_TYPE_H
#define SCREEN_TYPE_H

#include <iostream>
#include <vector>

#include "libraryIncluder.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

struct letterButton
{
   std::string buttonName;
   unsigned char buttonType;
   char letterMatch;
   bool isStrangeChar;//If true, compare to control, escape, etc.
};


//http://stackoverflow.com/questions/6423729/get-current-cursor-position
class screenType
{

public:

screenType();
~screenType();

bool areButtonsValid();
void addButton(std::string buttonTage, unsigned char butType, char buttonChar, bool isStrangeButtonChar);

private:
Keypress keyIn;


};








#endif
