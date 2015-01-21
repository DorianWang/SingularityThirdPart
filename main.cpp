
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "UsefulHeaders.h"

#include "ScreenInstructions.h"
#include "ScreenController.h"

#include "stringFunctions.h"

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
   //short a = 0;

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

//cout<<"Please press the maximize button at the top right of the screen."<<endl;
int screenX = 158; int screenY = 61;
testConsole.setConsoleSize(screenX, screenY);
testConsole.changeCurrentWindowText("New name!");

//Sleep(1000);
//cout<<"?"<<endl;
Keypress KeyIO;
//   system("PAUSE");



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
std::string stringFuncTester = "qwerty.asdf.qwerty....This is a line break!\n....ytr.poi.";

stringFunc stringTest;

char PERIOD = '.';

/*
cout << stringTest.parseFirstToken(stringFuncTester, ".")<<endl;
cout << stringTest.parseFirstToken(stringFuncTester, ".")<<endl;
*/

ScreenControl screenTest;


screenTest.makeNewScreen("screenTest", "Screens");

ScreenControl testScreen;
std::string qpow = "This is a @.";
double testDouble = 0.1;


std::string testingStringInsert = stringTest.insertStringIntoString("Hellohoifea", "world!", 20);


cout <<endl;

cout << "---" << endl;



std::string testingMacroString = "Asdf!";
short testShort = 20;
int health = 100;
while (true){


//Should I add macro conventions? Maybe INT_HEALTH for an integer, or STR_STRINGTHING for a string?

instructDataOut* newInstruct;
if (screenTest.popFirstUnsetInstructPointer(&newInstruct) == false){
   break;
}

if (newInstruct -> macroInstruct == "TEST_MACRO"){
   std::string ** tempPointer = (std::string **)(newInstruct -> variablePointerPointer);
   *tempPointer = &testingMacroString;
}
else if (newInstruct -> macroInstruct == "MACRO"){
   short ** tempPointer = (short **)(newInstruct -> variablePointerPointer);
   *tempPointer = &testShort;
}
else if (newInstruct -> macroInstruct == "HEALTH"){
   int ** tempPointer = (int **)(newInstruct -> variablePointerPointer);
   *tempPointer = &health;
}
else{
   cout << "whut?" << endl;
}

delete newInstruct;

}

cout << screenTest.outputScreen(0) <<endl;

cout << "---" << endl;

/*
for (int i=0; i<tempVec.size(); i++){
   cout << tempVec[i]<<endl;
}
*/

double PI = 3.14159265359;

srand (static_cast <unsigned> (time(0)));

   system("PAUSE");
   system ("CLS");

/*
for (int i = 0; i < 1000; i++){
   //double r = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);

   double r = i/1000.0;

   double result = sin (r*PI*4);

   testConsole.cursorOptions.setColour(rand() % 15 + 1, 'a');
   testConsole.cursorOptions.changeCursorPos(round(r * 100), round (result * 20 + 22));
   cout << 'A';
}

*/


int a = 1;
int b = -6;
int c = -1;
int d = 30;

if (d < 0){
for (int i = d; i <= -1; i++){
   for (int j = -abs(a); j <= abs(a); j++){
      if (j == 0){
         continue;
      }

      int temp1 = d/i;
      int temp2 = a/j;
      int temp3 = (c-j*temp1)/i;
      if (temp1*i == d && temp2*j == a){
         if (b == i*temp2 + j*temp3 && c == j*temp1 + i*temp3){
            cout << "found solution: " << '(' << j << "x + " << i << ")(" << temp2 << "x^2 + " << temp3 << "x + " << temp1 << ")" << endl;
         }
      }
   }
}
}
else
{
for (int i = 1; i <= d; i++){
   for (int j = -abs(a); j <= abs(a); j++){
      if (j == 0){
         continue;
      }

      int temp1 = d/i;
      int temp2 = a/j;
      int temp3 = (c-j*temp1)/i;
      if (temp1*i == d && temp2*j == a){
         if (b == i*temp2 + j*temp3 && c == j*temp1 + i*temp3){
            cout << "found solution: " << '(' << j << "x + " << i << ")(" << temp2 << "x^2 + " << temp3 << "x + " << temp1 << ")" << endl;
         }
      }
   }
}

}

/*
for (int i = 1; i <= abs(d); i++){
   for (int j = -abs(a); j <= abs(a); j++){
      if (j == 0){
         continue;
      }

      int temp1 = d/i;
      int temp2 = a/j;
      int temp3 = (c-j*temp1)/i;
      if (temp1*i == d && temp2*j == a){
         if (b == i*temp2 + j*temp3){
            cout << "found solution: " << i << ' ' << j << ' ' << temp1 << ' ' << temp2 << ' ' << temp3 << endl;
         }
      }
   }
}
*/



   testConsole.cursorOptions.changeCursorPos(0, 54);
   cout<<"I'm done!"<<endl;
   system("PAUSE");


   return EXIT_SUCCESS;
}















