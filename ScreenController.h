#ifndef SCREENCONTROLLER_H_INCLUDED
#define SCREENCONTROLLER_H_INCLUDED

#include "libraryIncluder.h"
#include "Screens.h"
#include "ScreenInstructions.h"

#include <iomanip>
#include <list>

#define DATA_FOLDER "Data/"

struct instructDataOut
{
   std::string macroInstruct;
   void* variablePointerPointer;
};



class ScreenControl
{
public:

//Macros : Stuff and stuff {THIS_IS_A_MACRO} more stuff and things.
//have already been replaced by the instruct input function.
//So the above would be Stuff and stuff @ more stuff and things.
bool popFirstUnsetInstructPointer(instructDataOut* output);
std::vector <instructDataOut> getAllUnsetInstruct();

int makeNewScreen (std::string screenName, std::string screenLocation);

int getScreenIndex(std::string screenNameSearch);

bool outputScreen(int screenIndex);

private:

FileIO fileReader;

std::vector <ScreenType*> screenArray;

std::list <instructDataOut> UnsetPointerList;

//Need something to keep track of screens in use...

std::string parseInstruct(std::string input, char inputType, ...);


};





#endif // SCREENCONTROLLER_H_INCLUDED
