
#ifndef COPTIONS_H
#define COPTIONS_H

#include <cstdarg>//Variable lists

#include "windows.h"
#include "stdio.h"
#include <cstdlib>
#include <iostream>

enum class textColour {BLACK, DARK_BLUE, GREEN_BLUE, BLUE_GREEN, DARK_RED, PURPLE, GOLD, SILVER, GREY, BLUE, BRIGHT_GREEN, CYAN, RED, PINK, YELLOW, WHITE};

using namespace std;

class COptions
{

bool cursorVisibility;
bool cursorSmall;
HANDLE consoleHandle;

int currentColour;

public:

inline COptions();
inline ~COptions();

inline int toggleColour(HANDLE cHandle);

inline void returnDefault(HANDLE cHandle);
inline void toggleCursorSize(HANDLE cHandle);
inline void toggleCursor(HANDLE cHandle);
inline void tempColourChange(bool isDiff, HANDLE cHandle, int targetColour);
inline void changeCursorInsert(HANDLE cHandle, bool insertMode);


inline bool changeCursorPos(short cursorX, short cursorY);

inline void cursorControl(int optionNum);//Controls all other functions. 0 for cursor visible. 1 for opposite, 2 for colour change, 5 for defaults, etc.

inline int setColour(int newColour, int backgroundColour);
inline int letterCodeToColourInt(char input);
inline char colourIntToletterCode(int input);

//inline void changeCurrentWindowText(const char* newText);//Changes the currently selected console's name.

};


//Stuff is below




//#define ENABLE_INSERT_MODE 0x0020
//#define ENABLE_EXTENDED_FLAGS 0x0080

using namespace std;

COptions::COptions()
{

cursorVisibility = true;
cursorSmall = true;
currentColour = 7;
consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

}

COptions::~COptions()
{

}

void COptions::toggleCursor(HANDLE cHandle)
{

   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;

   if (cursorVisibility){
   cursorVisibility = false;
   info.bVisible = cursorVisibility;
   }
   else
   {
   cursorVisibility = true;
   info.bVisible = cursorVisibility;
   }

   SetConsoleCursorInfo(cHandle, &info);

}

void COptions::toggleCursorSize(HANDLE cHandle)
{
//doesn't do stuff
   CONSOLE_CURSOR_INFO info;


   if (cursorSmall){
   cursorSmall=false;
   info.dwSize = 100;
   }
   else
   {
   cursorSmall=true;
   info.dwSize = 20;
   }

   SetConsoleCursorInfo(cHandle, &info);
}

int COptions::toggleColour(HANDLE cHandle)
{

    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(cHandle, &con_info);
    int cursorColour = con_info.wAttributes;

    if (cursorColour > 14){
       cursorColour = 0;
       currentColour = 0;
    }

    cursorColour += 1;
    currentColour += 1;
    SetConsoleTextAttribute(cHandle, cursorColour);

    return cursorColour;
    //0 is black, 1 is dark blue, 2 is green, 3 is cyan, 4 is dark red, 5 is magenta, 6 is gold, 7 is white, 8 is grey, 9 is blue, 10 is light green
    //11 is light blue, 12 is red, 13 is magenta, 14 is yellow, 15 is light grey, 16+ is highlighted

}// changes cursor colour

//enum class textColour
//{BLACK, DARK_BLUE, GREEN_BLUE, BLUE_GREEN, DARK_RED, PURPLE, GOLD,
//SILVER, GREY, BLUE, BRIGHT_GREEN, CYAN, RED, PINK, YELLOW, WHITE};
int COptions::letterCodeToColourInt(char input)
{
   switch (input){
      case 'l':
         return (int) textColour::BLACK;
         break;
      case 'b':
         return (int) textColour::DARK_BLUE;
         break;
      case 'g':
         return (int) textColour::GREEN_BLUE;
         break;
      case 'u':
         return (int) textColour::BLUE_GREEN;
         break;
      case 'r':
         return (int) textColour::DARK_RED;
         break;
      case 'p':
         return (int) textColour::PURPLE;
         break;
      case 'o':
         return (int) textColour::GOLD;
         break;
      case 's':
         return (int) textColour::SILVER;
         break;
      case 'a':
         return (int) textColour::GREY;
         break;
      case 'B':
         return (int) textColour::BLUE;
         break;
      case 'G':
         return (int) textColour::BRIGHT_GREEN;
         break;
      case 'c':
         return (int) textColour::CYAN;
         break;
      case 'R':
         return (int) textColour::RED;
         break;
      case 'P':
         return (int) textColour::PINK;
         break;
      case 'y':
         return (int) textColour::YELLOW;
         break;
      case 'w':
         return (int) textColour::WHITE;
         break;
      default:
         return (int) textColour::WHITE;
         break;
   }
}

//enum class textColour
//{BLACK, DARK_BLUE, GREEN_BLUE, BLUE_GREEN, DARK_RED, PURPLE, GOLD,
//SILVER, GREY, BLUE, BRIGHT_GREEN, CYAN, RED, PINK, YELLOW, WHITE};
char COptions::colourIntToletterCode(int input)
{
   switch (input){
      case (int) textColour::BLACK:
         return 'l';
         break;
      case (int) textColour::DARK_BLUE:
         return 'b';
         break;
      case (int) textColour::GREEN_BLUE :
         return 'g';
         break;
      case (int) textColour::BLUE_GREEN :
         return 'u';
         break;
      case (int) textColour::DARK_RED :
         return 'r';
         break;
      case (int) textColour::PURPLE :
         return 'p';
         break;
      case (int) textColour::GOLD :
         return 'o';
         break;
      case (int) textColour::SILVER :
         return 's';
         break;
      case (int) textColour::GREY :
         return 'a';
         break;
      case (int) textColour::BLUE :
         return 'B';
         break;
      case (int) textColour::BRIGHT_GREEN :
         return 'G';
         break;
      case (int) textColour::CYAN :
         return 'c';
         break;
      case (int) textColour::RED :
         return 'R';
         break;
      case (int) textColour::PINK :
         return 'P';
         break;
      case (int) textColour::YELLOW :
         return 'y';
         break;
      case (int) textColour::WHITE:
         return  'w';
         break;
      default:
         return  'w';
         break;
   }
}

int COptions::setColour(int newColour, int backgroundColour)
{

    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(consoleHandle, &con_info);
    //int cursorColour = con_info.wAttributes;

    SetConsoleTextAttribute(consoleHandle, newColour + backgroundColour * 16);

    return newColour + backgroundColour * 16;
    //0 is black, 1 is dark blue, 2 is green, 3 is cyan, 4 is dark red, 5 is magenta, 6 is gold, 7 is white, 8 is grey, 9 is blue, 10 is light green
    //11 is light blue, 12 is red, 13 is magenta, 14 is yellow, 15 is light grey, 16+ is highlighted

}// changes cursor colour

void COptions::returnDefault(HANDLE cHandle)
{

    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(cHandle, &con_info);
    int cursorColour = con_info.wAttributes;

    //if (cursorColour!=15){
    currentColour = 15;
    cursorColour = 15;
    SetConsoleTextAttribute(cHandle, cursorColour);
    //}

    if (cursorVisibility){
       toggleCursor(cHandle);
    }

    if (cursorSmall == false){
       toggleCursorSize(cHandle);
    }

}// changes cursor colour

void COptions::tempColourChange(bool isDiff, HANDLE cHandle, int targetColour)
{
   //if isDiff is true, change the colour to the target colour, otherwise, change it back

    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(cHandle, &con_info);
    int cursorColour = con_info.wAttributes;

    if(isDiff == false){
    currentColour = cursorColour;
    SetConsoleTextAttribute(cHandle, targetColour);
    }

    if(isDiff){
    cursorColour = currentColour;
    SetConsoleTextAttribute(cHandle, cursorColour);
    }

}

void COptions::cursorControl(int optionNum)
{
     bool debugDetector = true;
     if (optionNum == 0){

        if (cursorVisibility == false){
           toggleCursor(consoleHandle);
        }

        debugDetector = false;
     }//if cursor is false, make true

     if (optionNum == 1){

        if (cursorVisibility){
           toggleCursor(consoleHandle);
        }

        debugDetector = false;
     }//if cursor is true, make false

     if (optionNum == 2){
        toggleColour(consoleHandle);
        debugDetector = false;
     }//change colour

     if (optionNum == 3){
        returnDefault(consoleHandle);
        debugDetector = false;
     }//returns defaults

     if (optionNum == 4){
        toggleCursor(consoleHandle); //force toggle
        debugDetector = false;
     }

     if (optionNum == 5){
        changeCursorInsert(consoleHandle, true);//Insert mode
        debugDetector=false;
     }

     if (optionNum == 6){
        changeCursorInsert(consoleHandle, false);//no Insert mode
        debugDetector=false;
     }

     if (optionNum == 7){
        tempColourChange(false, consoleHandle, 15);
        debugDetector=false;
     }

     if (optionNum == 8){
        tempColourChange(true,consoleHandle, 15);
        debugDetector=false;
     }

     if (optionNum == 9){
        //changeWindowText("Stuff", consoleHandle);
        debugDetector=false;
     }

     //beyond this are unused

     if (optionNum==10){
        debugDetector=false;
     }

     if (debugDetector){
     cout<<"Something broke in CursorOptions.cpp"<<endl;
     }


}


bool COptions::changeCursorPos(short cursorX, short cursorY)
{

   int returningNum;
   COORD coord;
   coord.X = cursorX;
   coord.Y = cursorY;

   returningNum = SetConsoleCursorPosition(consoleHandle, coord);

   if (returningNum == 0){
      return false;
   }

   return true;
}

void COptions::changeCursorInsert(HANDLE cHandle, bool insertMode)
{
//DWORD mode = 0;
//DWORD otherThing = ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
//DWORD thing = ENABLE_EXTENDED_FLAGS;
//GetConsoleMode(cHandle, &mode);

   if (insertMode){
   SetConsoleMode(cHandle, ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS);
   }
   else
   {
   SetConsoleMode(cHandle, ENABLE_EXTENDED_FLAGS);
   }

}





#endif
