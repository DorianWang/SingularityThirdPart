
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>



#include "UsefulHeaders.h"

#include "ScreenInstructions.h"
#include "ScreenController.h"

#include "stringFunctions.h"
#include "eventLog.h"
#include "StatReader.h"

#include "AttackReader.h"


//MUSIC! http://www.youtube.com/watch?v=nDyzVV_e7WM&list=LL5I3vUh2iNfQ3pCU3sodYRA&shuffle=167714

eventRecorder::eventLog* eventLogger = new eventRecorder::eventLog(DEBUG_MODE);

//using namespace std;

#include "Bases.h"

#include "libraryIncluder.h"
//#include "D:\Dorian's programs\UsefulLibraries\Libraries\FileIO\FileIO.h"

#include "GLFWLoop.h"

// ---- Global Variables ---- //
#define VERSION_NUM 0.02


//Keypress keyIO;
bool cursorVisibility = false;
bool cursorSmall = true;


int main(int argc, char *argv[])
{
   srand (time(NULL));


   FileIO myFile;//FileIO has been tested, and appears to work...
   //However, there is more testing to be done!

//   myFile.textOpenFile("Data/Maps/Thing.txt", false);
//   std::string them;
//   myFile.readLine(&them);
//   cout<<them<<endl;

   myFile.textOpenFile(std::string("test.txt"), false);

   std::string testingString;
   while (myFile.readLine(&testingString)){
      cout << testingString << "!" << endl;
   }
   system("PAUSE");
   system ("CLS");


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
//
ConsoleOptions testConsole;

//cout<<"Please press the maximize button at the top right of the screen."<<endl;
int screenX = 158; int screenY = 81;
testConsole.setConsoleSize(screenX, screenY);
testConsole.changeCurrentWindowText("New name!");

//Sleep(1000);
//cout<<"?"<<endl;
Keypress KeyIO;
//   system("PAUSE");




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
cout <<screenTest.makeNewScreen("screenTest2", "Screens")<< endl;
system("PAUSE");


std::string qpow = "This is a @.";
double testDouble = 0.1;


std::string testingStringInsert = stringTest.insertStringIntoString("Hellohoifea", "world!", 20);


cout <<endl;

cout << "---" << endl;


std::string testingMacroString = "Asdf!";
short testShort = 20;
int health = 100;
double worthMe = 0.98423;

while (false){
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
   else if (newInstruct -> macroInstruct == "WORTH"){
      double ** tempPointer = (double **)(newInstruct -> variablePointerPointer);
      *tempPointer = &worthMe;
   }
   else{
      cout << "whut?" << endl;
   }

   delete newInstruct;
}

//screenTest.outputScreen(0);


cout << "---" << endl;

   time_t timer; struct tm* ptm; char cStr[22];
   timer = time(NULL);
   ptm = localtime (&timer);
   strftime(cStr, 20, "%F", ptm);
   //http://www.cplusplus.com/reference/ctime/strftime/


double PI = 3.14159265359;

srand (static_cast <unsigned> (time(0)));

testConsole.cursorOptions.setColour(15, 0);

cout << "Testing colours" << endl;


   system("PAUSE");
   system ("CLS");
   cout << "Testing OpenGL!" << endl;

   firstGameLoop::gameMain.openGLTest();


   system("PAUSE");
   system ("CLS");

   statReader statInput; attackScaling::attackReader attackInput;


   FileIO newFile; stringFunc stringThings; std::vector <attackScaling::statScaling> outputScalings;
   newFile.textOpenFile("Data/Attacks/Attack_Test.txt", false);


   attackInput.addScaling(&newFile, &stringThings, &outputScalings, "TestScaling");

   for (int i = 0; i < outputScalings.size(); i++){
      cout << outputScalings[i].statNum << endl;
   }

   system("PAUSE");
   system ("CLS");

//screenTest.outputScreen(1);


/*
for (int i = 0; i < screenTest.testVector.size(); i++){
   cout << screenTest.testVector[i]<<endl;
}
*/

   testConsole.cursorOptions.changeCursorPos(0, 0);


   attackScaling::attackReader thingsAndStuff;

   std::cout << "I'm done!" << std::endl;


   system("PAUSE");

   eventLogger -> addNewLog("End Program successfully!");
   eventLogger -> pushBuffer();

   return EXIT_SUCCESS;
}


























