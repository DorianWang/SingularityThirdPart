
#include "Screens.h"

//move some of the switch statements over to here.

int SelectScreens::gameStart()
{
int input=0;
input = keyIO.get_code("asqASQ");             

   if (input!=FAILURE_NUM){      
         
   }   
return -1;
}

void SelectScreens::programRun(int programNum)
{
int functionRan; 
functionRan=-1;

switch(programNum)
{
   case 0:
   break;//not supposed to get here  
   
   case 1:
   functionRan=treeSort();
   break;

   case 2:
   functionRan=helloWorld();
   break;
   
   case 3:
   functionRan=futurePlans();     
   break;
   
   case 4:
   functionRan=helloWorld();
   break;
   //nothing   
   case 5:
   break;
   //nothing      
   case 6:
   break;
   //nothing as well
   case 9:
   break;
   //could be used later     
   case 10:
   functionRan=dwarfGame(1);
   break;
   //more things to be added later
   
}


if (functionRan==FAILURE_NUM){
   cout<<"Failure to do stuff"<<endl;
}

}//end programRun


