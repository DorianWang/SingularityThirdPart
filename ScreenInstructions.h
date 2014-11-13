
#ifndef SCREEN_TYPE_H
#define SCREEN_TYPE_H

#include <iostream>
#include <vector>

#include "libraryIncluder.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

//http://stackoverflow.com/questions/6423729/get-current-cursor-position


template <typename Q> class screenInstruct
{


   public:
int Xpos; int Ypos;

screenInstruct();

std::string instructionText;

Q* dataOut;
};


template <typename Q> screenInstruct<Q>::screenInstruct()
{
   dataOut = NULL;
}



/*
struct screenInstructionsInt
{
int Xpos; int Ypos;

std::string instructionText;
//Example: Health: [PLAYER_HEALTH]

//Remember to set to zero when created.
int* dataOut;

};
*/





#endif
