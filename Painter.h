
#ifndef PAINTER_H
#define PAINTER_H 

#include "windows.h"  
#include "CursorOptions.h"

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 80

#include <string>
#include <cstdlib>
#include <iostream>


using namespace std;

class Painter
{
   COptions colourC;
      
    
   HANDLE consoleHandle;   
   int stuff;
      
   public:
          
   Painter();
   ~Painter();
   bool screenWriter(int screenHeight, int screenWidth, char*screenData, int startX, int startY, int overwriteNum, HANDLE cHandle);
   void screenWriter(int screenHeight, int screenWidth, char* screenData);
   //void screenRedraw(tile screenTiles[24][80], int screenHeight, int screenWidth);
   
   //tile *screenTiles[24][80]
   
   
};

#endif
