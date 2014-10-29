
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

struct treeNodeBinary
{

int intData;
int metaData;
char moreMetaData;

treeNodeBinary* parent;
treeNodeBinary* left;
treeNodeBinary* right;

};

//typedef int(*FuncP)(int A, ...);//for functions

class SelectScreens
{

COptions cursorMod;
Keypress keyIO;
;;
std::string studentDrive;
std::string functionToLetter;
;;
public:
;;

SelectScreens();
//~SelectScreens();

int mainScreen(int versionNum);
void optionsScreen();
int functionRun();
int gameStart();

int contextMenu(struct tile graphicData[SCREEN_HEIGHT][SCREEN_WIDTH]);

void programRun(int programNum);

void findMyDocsWindows(char* myDocsPath);

int emptyFunction();

int treeSort();
int helloWorld();
int futurePlans();

int dwarfGame(int difficulty);

//FuncP functions[NUM_FUNCTIONS];//array of function pointers

;;
private:

int stringThing(int inputNum, int outputNum, int stringLength);


};

#endif





