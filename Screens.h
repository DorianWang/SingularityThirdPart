
#ifndef SCREENS_H
#define SCREENS_H

#include <fstream>
#include <vector>
//#include <map>
#include <stdarg.h>
#include <stdio.h>
#include <sstream>
#include <iostream>

#include "libraryIncluder.h"

#include "ScreenInstructions.h"

#define PRESSDELAY 5
#define SUCCESS_NUM 1
#define FAILURE_NUM -1
#define FAILURE_NUM_OTHER -2

#define MAX_LINE_LENGTH 510

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 80

#define NUM_FUNCTIONS

using namespace std;



class ScreenType
{


public:
;;

ScreenType(int minX, int minY, int maxX, int maxY, std::string newScreenName, std::string screenFileLocation, FileIO* screenInput);

~ScreenType();

//Should this return a string for the parent to output, modify an internal buffer which the parent can output, or draw by itself?
void redraw();

std::vector <char> expectedInput;

private:


std::string screenName;

std::vector <screenInstruct <int>> instructions;
;;
int botX; int botY; int topX; int topY;//The screen's area of influence. This is inclusive.



void parseScreenFile(FileIO* file, std::string screenFileName);


};

#endif





