
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

#define PRESSDELAY 5
#define SUCCESS_NUM 1
#define FAILURE_NUM -1
#define FAILURE_NUM_OTHER -2

#define MAX_LINE_LENGTH 510

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 80

#define NUM_FUNCTIONS

using namespace std;


//typedef struct screenGraphicData //user defined datatype
//{
//};



class ScreenType
{

ConsoleOptions* cursorMod;
Keypress* keyIO;
;;
std::string studentDrive;
std::string functionToLetter;
;;
public:
;;

ScreenType(int minX, int minY, int maxX, int maxY, std::string screenName, std::string screenSourceName);
ScreenType(int minX, int minY, int maxX, int maxY, std::string screenName, std::string screenSourceName, Keypress* keyOrig, ConsoleOptions* COrig);

~ScreenType();

private:




};

#endif





