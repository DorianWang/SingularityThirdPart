
#include "Painter.h"
          
//   screenFill();      
      
Painter::Painter()
{
                  
}    

Painter::~Painter()
{
                                 
}      
      

bool Painter::screenWriter(int screenHeight, int screenWidth, char*screenData, int startX, int startY, int overwriteNum, HANDLE cHandle)
{
     
   int endX, endY;
   
   
   COORD cursorStart;
   if (startX<=screenWidth&&startX>0){
      
   cursorStart.X=startX;   
   }
   
   if (startY<=screenHeight&&startY>0){
   cursorStart.Y=startY;   
   }
   if (SetConsoleCursorPosition(cHandle,cursorStart)!=0){
      cout<<"asdf";
      cout<<screenData;
   return true;                                                      
   }
      
   return false;
}      

void Painter::screenWriter(int screenHeight, int screenWidth, char *screenData)
{
     
   for (int j=1;j<screenHeight;j++){
      for (int i=1;i<screenWidth;i++){ 
         //cout<<screenData[((j-1)*screenHeight)+i];
         //cout<<"hello";
      }
   }
        
        
        
        
        
}
   
//void Painter::screenRedraw(screenGraphicData *screenData, int screenHeight, int screenWidth); 
//{}    
      
      
      
      
      

