#ifndef SCREENCONTROLLER_H_INCLUDED
#define SCREENCONTROLLER_H_INCLUDED

#include "libraryIncluder.h"
#include "Screens.h"

struct instructDataOut
{
   std::string macroInstruct;
   void* variablePointerPointer;
};



class ScreenControl
{
public:

instructDataOut getNextUnsetInstructPointer();
std::vector <instructDataOut> getAllUnsetInstruct();

private:

FileIO fileReader;

std::vector <ScreenType*> screenArray;
//Need something to keep track of screens in use...




};





#endif // SCREENCONTROLLER_H_INCLUDED
