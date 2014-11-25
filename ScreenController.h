#ifndef SCREENCONTROLLER_H_INCLUDED
#define SCREENCONTROLLER_H_INCLUDED

#include "libraryIncluder.h"
#include "Screens.h"
#include <list>

struct instructDataOut
{
   std::string macroInstruct;
   void* variablePointerPointer;
};



class ScreenControl
{
public:

bool popFirstUnsetInstructPointer(instructDataOut* output);
std::vector <instructDataOut> getAllUnsetInstruct();

bool makeNewScreen (std::string screenName, std::string screenLocation);

private:

FileIO fileReader;

std::vector <ScreenType*> screenArray;

std::list <instructDataOut> UnsetPointerList;

//Need something to keep track of screens in use...




};





#endif // SCREENCONTROLLER_H_INCLUDED
