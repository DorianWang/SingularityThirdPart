
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "UsefulHeaders.h"


//MUSIC! http://www.youtube.com/watch?v=nDyzVV_e7WM&list=LL5I3vUh2iNfQ3pCU3sodYRA&shuffle=167714



//using namespace std;

struct interactObject
{
   std::string nameObject;
   int objectType;
   int objectAlignment; //what it is (hostile, friendly, neutral, etc)
   int numUse;
   int specialType;//normally 0, different for other things
};

struct tile
{
   char tileSymbol;
   interactObject tileEntities;
   int xCoord;
   int yCoord;
};

struct tester
{
int a;
int b;
int c;
int d;
char e;
char f;
};

#include "Bases.h"
//#include "ConsoleOptions.h"
//#include "Screens.h"
//#include "stringFunctions.h"

//#include "treeType.h"
//#include "functionChecker.h"

//#include "binaryTree.h"

#include "libraryIncluder.h"

//#include "D:\Dorian's programs\UsefulLibraries\Libraries\FileIO\FileIO.h"


// global variables
#define VERSION_NUM 0.01




//Keypress keyIO;
bool cursorVisibility = false;
bool cursorSmall = true;





void swap(int*a, int*b)
{
int temp = *a;
*a=*b;
*b = temp;
}

class foo
{

};

class bar
{
   public:
   bool operator == (const bar& op2){
      return true;//Testing
   };
};



int main(int argc, char *argv[])
{
    srand (time(NULL));
    //cout<<asdfgh<<qwe<<asdfgh<<qwe<<endl;
    //cout<<asdfgh<<asdfgh<<qwe<<asdfgh<<qwe<<endl;
    //219 -> 178 -> 177 -> 176 -> 43
   int poiu = 4321;
//   poi(4, &poiu);

   float asdf = 24;
   int asdfs = 564;
   void* temp;
   char buffer[16];
   buffer[0]='0';buffer[1]='1';buffer[2]='5';buffer[3]='h';//buffer[4]='c';buffer[5]='d';buffer[6]='q';buffer[7]='h';
   buffer[8]='Q';buffer[9]=0;

   FileIO myFile;//FileIO has been tested, and appears to work...
   //However, there is more testing to be done!

//   myFile.textOpenFile("Data/Maps/Thing.txt", false);
//   std::string them;
//   myFile.readLine(&them);
//   cout<<them<<endl;

   Keypress KeyIn;
   short a = 0;

      if(KeyIn.get_code(4)){
         cout<<"One!"<<" ";
      }
      //Nothing is 0, true is -127/65408, and toggled is 1, (toggled and down is 65409/-128)

   /*
   COptions Ebeko;
   Ebeko.changeCurrentWindowText("Rahfsdkhf");
   system("PAUSE");
   SetConsoleTitle("Adventure Game");
   */
   //Both work, but the first will only work if the front window is this one.
   //The second one always works.



std::string folderStuff = "Stuff\\";
std::string folderStuffs = "asdfasdf";

std::string tempNameFolder = "asdfasdf";

int counters = 0;


   linkedList <int> Aso();
//   SelectScreens ScreenControl;
   //cout<<Dempo.deleteFile(Dempo.getExecutablePath(), false)<<endl;


   //ScreenControl.mainScreen(VERSION_NUM);
   //^Important for code n' stuff

   //Aso.



//
//
//   treeType <int> aephoro("asdf");
//
//   aephoro.addNode("node1");
//   aephoro.addNode("node2");
//
//   treeType <int> * treePointer;
//   treePointer = aephoro.getNodeAtIndex(1);
//   if (treePointer){
//      cout<<treePointer -> getName()<<endl;
//      treePointer -> addNode("node3");
//   }
//   treePointer = treePointer -> getNodeAtIndex(0);
//
//   cout<<treePointer -> listNodePath()<<endl;//It works!
//
//   std::string nodePath = treePointer -> listNodePath();
//
//   stringFunc asdfa;
//
//   std::vector <std::string> tokenVector = asdfa.parseAllTokens(nodePath, ". ");
//
//   for (int i=0; i<tokenVector.size(); i++){
//      cout<<tokenVector[i]<<" -> ";
//   }
//   cout<<endl;
//
ConsoleOptions testConsole;

cout<<"Please press the maximize button at the top right of the screen."<<endl;
int screenX = 158; int screenY = 61;
testConsole.setConsoleSize(screenX,screenY);
Sleep(1000);
//cout<<"?"<<endl;
Keypress KeyIO;
   system("PAUSE");



/*
bool keyPressed[4]; bool keyDown[4];
system("PAUSE");
KeyIO.get_code(keyPressed, keyDown, "asdf");
system("PAUSE");
KeyIO.get_code(keyPressed, keyDown, "asdf");
std::string inputStuff;
cin>>inputStuff;

*/

//the backslash n creates a gap.
std::string stringFuncTester = "qwerty.asdf.qwerty....\n....ytr.poi.";

stringFunc stringTest;

char PERIOD = '.';

std::vector <std::string> tempVec = stringTest.parseAllTokens(stringFuncTester, ".");

for (int i=0; i<tempVec.size(); i++){
   cout << tempVec[i]<<endl;
}


   cout<<"I'm done!"<<endl;
   system("PAUSE");


   return EXIT_SUCCESS;
}















