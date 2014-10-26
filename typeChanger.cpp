
#include "typeChanger.h"


int cToI(char* buffer)
{
   unsigned int unsignedOutput = 0;
   int output=0;
   //0-255 per byte. X^256 per increasing byte
   for (int i=0;i<4;i++){
      unsignedOutput+=buffer[i]+unsignedOutput*(256);
   }
   
   if (unsignedOutput>=TWO_THIRTY_ONE){
      output = (-1)*(TWO_THIRTY_TWO - unsignedOutput);   
   }
return output;
}

unsigned int cToUI(char* buffer)
{
   unsigned int output = 0;
   //0-255 per byte. X^256 per increasing byte
   for (int i=0;i<4;i++){
      output+=buffer[i]+output*(TWO_EIGHT);
       
   }
return output;
}

short cToS(char* buffer)
{
   unsigned short unsignedOutput = 0;   
   short output = 0;   
   for (int i=0;i<2;i++){
      unsignedOutput+=buffer[i]+unsignedOutput*(TWO_EIGHT);
   }
   
   if (unsignedOutput>=TWO_FIFTEEN){
      output = (-1)*(TWO_SIXTEEN - unsignedOutput);      
   }
return output;   
}

unsigned short cToUS(char* buffer)
{
   unsigned short unsignedOutput = 0;   
   short output = 0;   
   for (int i=0;i<2;i++){
      unsignedOutput+=buffer[i]+unsignedOutput*(TWO_EIGHT);
   }
   
   if (unsignedOutput>=TWO_FIFTEEN){
      output = (-1)*(TWO_SIXTEEN - unsignedOutput);      
   }
return output;   
}

//changes a integer that is in a string to an integer. "1342" to 1342, "0960" to 960
int cIToI(char* buffer, int* output)
{
   bool isNegative; 
   int temp = 0;
   if(buffer[0]=='-'){
      for (int i=1;i<4;i++){
         if(buffer[i]>'9'||buffer[i]<'0'){
            return 0;
         }
         temp = temp*10 + buffer[i];
      }
      *output = temp*(-1);
   return 1;
   }
   
   if(buffer[0]>'9'||buffer[0]<'0'){
      for (int j=0;j<4;j++){
         if(buffer[j]>'9'||buffer[j]<'0'){
            return 0;
         }
         temp = temp*10 + buffer[j];
      }                                 
      *output = temp;  
   return 1;                    
   }

return 0;//not a number
}


int iToC(int input, char* output)
{
   char buffer[4];
   //unsignedOutput+=buffer[i]+unsignedOutput*(256);

   for (int i=3;i>=0;i--){
      buffer[i]=input&0xFF;//does stuff
      input>>8;
   }
   
   for(int j=0;j<4;j++){
      output[j]=buffer[j];        
   }
return 1;
}


































