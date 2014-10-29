

#include "Screens.h"




SelectScreens::SelectScreens()
{
   functionToLetter = "Press 1 for ";
   //need to complete;
}

//SelectScreens::~SelectScreens()
//{
//}

//this takes a string like asdfgqASDFGQ, checks to see if
int SelectScreens::stringThing(int inputNum, int outputNum, int stringLength)
{
//An easier implementaion would involve returning true false, instead of numbers.

   if (inputNum==outputNum){
      return outputNum;
   }

   if ((inputNum-(stringLength/2))==outputNum){
      return outputNum;
   }

return FAILURE_NUM;
}

//This toggles mostly cursor options.
void SelectScreens::optionsScreen(){

system("CLS");

int input;
int stringTest;

int stringLength;
std::string inCharString;

inCharString="asdfgqASDFGQ";
stringLength= inCharString.length();

cursorMod.cursorControl(7);
cout<<"Press A to make the cursor visible, S to make it invisible"<<endl;
cout<<"D to change the text colour, F to return it to defaults"<<endl;
cout<<"G forces the cursor to toggle visibility"<<endl;
cout<<"Press Q to close the options screen"<<endl;
cursorMod.cursorControl(8);
cout<<"Test line"; // 9 characters
do{
   input = keyIO.get_code(inCharString);

   //stringTest = stringThing

      if (input!=FAILURE_NUM){

          if (stringThing(input, 0, stringLength)==0){//input==0||input==6){
             cursorMod.cursorControl(0);
          }
          if (stringThing(input, 1, stringLength)==1){//input==1||input==7){
          cursorMod.cursorControl(1);
          }
          if (stringThing(input, 2, stringLength)==2){//input==2||input==8){
          cursorMod.cursorControl(2);
          }
          if (stringThing(input, 3, stringLength)==3){//input==3||input==9){
          cursorMod.cursorControl(3);
          }
          if (stringThing(input, 4, stringLength)==4){//input==4||input==10){
          cursorMod.cursorControl(4);
          }
          if (stringThing(input, 5, stringLength)==5){//input==5||input==11){
          Sleep(PRESSDELAY);
          break;
          //closer
          }

          cout << string(9 ,'\b');
          cout <<"Test line";
          Sleep(PRESSDELAY);
      }

} while(true);

}//options screen

int SelectScreens::functionRun()
{
int input;

int stringLength;
std::string inCharString;

inCharString="dswpqDSWPQ";
stringLength= inCharString.length();

bool isGame;
isGame=false;
int whichGame;//if it is a game, chooses which one and returns the value that corresponds to the game
whichGame=-1;
//returns a single digit number if it is a program. Games go in the format of 2 digit numbers. 12 would be 1 - (super easy), 2 - (game 3)


system("CLS");

cout<<"Please select your function"<<endl<<endl;

cout<<"Dwarf game - D"<<endl;
cout<<"Tree sort - S"<<endl;
cout<<"Hello World - W"<<endl;
cout<<"Plans for future stuff - P"<<endl;
cout<<"Quit - Q"<<endl;

do{
   input=keyIO.get_code(inCharString);
   if (input!=FAILURE_NUM){

      if (stringThing(input, 0, stringLength)==0){
         whichGame=0;
         isGame=true;
         break;
      }

      if (stringThing(input, 1, stringLength)==1){
         return 1;
         break;
      }

      if (stringThing(input, 2, stringLength)==2){
         return 2;
         break;
      }

      if (stringThing(input, 3, stringLength)==3){
         return 3;
         break;
      }

      if (stringThing(input, 4, stringLength)==4){
         return 4;
         break;
      }//current quit key

      if (stringThing(input, 9, stringLength)==9){
         return 9;
         break;
      }//maximum amount it can go for programs.
      //If there are too many functions for this screen to control, I will make pressing 9 show additional options.

   }
}while(true);

if (isGame){
   cout<<"Please select your difficulty."<<endl<<endl;

   cout<<"Super easy - Z"<<endl;
   cout<<"Easy - A"<<endl;
   cout<<"Normal - S"<<endl;
   cout<<"Hard - D"<<endl;
   cout<<"Nintendo Hard - N"<<endl;

   do{

      input=keyIO.get_code("zasdnZASDN");

      if (input!=FAILURE_NUM){
         continue;
      }
      if (input>4){
         return (input-5);
      }
      else if (input<4&&input>-1){
         return input;
      }
      else
      {

         //???

      }

   }while(true);

}//end isGame if statement

}//end function


int SelectScreens::mainScreen(int versionNum)
{

stringstream ss (stringstream::in | stringstream::out);

ss<<versionNum;
string out = ss.str();
int input;

int programFunction;
programFunction=FAILURE_NUM;
cursorMod.cursorControl(3);

char chars[]="abcdefghijklmnop"; // c string

cout<<"Welcome to version " + out + " of singularity."<<endl<<endl;
system("PAUSE");
system("CLS");


cout<<"Press A to start the game, S to change settings and Q to quit"<<endl;
//screenPaint.screenWriter(24,80, &chars[2]);

do{
   input = keyIO.get_code("asqASQ");

      if (input!=FAILURE_NUM){

          if (input==0||input==3){
          programFunction=gameStart();
          system("CLS");
             if (programFunction!=FAILURE_NUM){
                programRun(programFunction);
                system("CLS");
                cout<<"Press A to start the game, S to change settings and Q to quit"<<endl;
             }
          }

          if (input==1||input==4){

          optionsScreen();

          system("CLS");
          cout<<"Press A to start the game, S to change settings and Q to quit"<<endl;
//          screenPaint.screenWriter(24,80, &chars[2]);
          }

          if (input==2||input==5){

          return FAILURE_NUM;

          }

      }

} while(true);

cout<<input<<endl;

return FAILURE_NUM_OTHER;
}


int SelectScreens::contextMenu(tile graphicData[SCREEN_HEIGHT][SCREEN_WIDTH])
{
return 0;
}

int SelectScreens::emptyFunction()
{
   cout<<"???"<<endl;
   return 1;
}

int SelectScreens::futurePlans()
{
cout<<"Plan - Finish treeSort, and then this function"<<endl<<endl;
system("PAUSE");
return 1;
}


void SelectScreens::findMyDocsWindows(char* myDocsPath)
{

char path[256];
GetEnvironmentVariable("USERPROFILE",path,sizeof(path));

int letterNum;
int counter=0;

do{
   letterNum=path[counter];
   if (letterNum>0){
      counter++;
   }
}while (letterNum>0);

   for (int i=0;i<counter;i++){
      myDocsPath[i]=path[i];
   }

}

int SelectScreens::treeSort()
{

stringstream ss (stringstream::in | stringstream::out);
//ss<<versionNum;
//std::string out
// = ss.str();


fstream myfile;
std::string keyInput;

std::string fileNameIn;
std::string fileName;
std::string fileLocation;

char myDocsPath[256];
char* P_myDocsPath = myDocsPath;
int counting=0;

char* pch; //char* for strtok (tokenizer)
std::string nextLine = "";// getting next line from file
char empty = 0;// empty char, to add to the end of strings, to catch errors



// get the char* using &writable[0] or &*writable.begin()

bool fileOpen=false;

do{myDocsPath[counting]=0;counting++;}while(counting<256);

std::string filePath;//entire thing together

system("CLS");

cout<<"What is the name of your file?"<<endl;
cin>>fileNameIn;
cout<<fileName;
//std::getline (std::cin,fileName);

bool option1,option2,option3;
char letter;
letter='/';
int letterInt;
cout<<fileName.length()<<endl;
for (int i=0;i<fileNameIn.length();i++){
   //cout<<fileName.length()<<endl;
   letter=fileNameIn.at(i);

   letterInt=letter;

   if (letterInt<123&&letterInt>63){
      option1=true ;
   }
   if (letterInt==32){
      option2=true;
   }
   if (letterInt>47&&letterInt<58){
      option3=true;
   }

   if (option1||option2||option3){
      if(letterInt!=92&&letterInt!=94&&letterInt!=96){
         fileName+=letter;
      }
   }


}
cout<<"asdfasdf"<<endl;
system("PAUSE");

system("CLS");
cout<<"I read the file name as "<<fileName<<"."<<endl;
cout<<"Is the file located in the Data folder of this program, or in My Documents?"<<endl;
cout<<"Or even press 3 for your student Data folder."<<endl;
cout<<"Enter 1, 2 or 3"<<endl;
cin>>keyInput;

if (keyInput=="1"){//atoi(keyInput.c_str())==1){
   filePath="Data/"+fileName;
   cout<<filePath<<endl;
   myfile.open(filePath.c_str());
}
else if (keyInput=="2")
{

   std::string myDocsPathTemp= "";
   findMyDocsWindows(P_myDocsPath);
   //str.shrink_to_fit();
   //filePath=P_myDocsPath;
   int letterNum;
   bool endOfArray=false;

   for (int k=0;k<256;k++){
      letterNum=myDocsPath[k];
      if (letterNum<1){
         endOfArray=true;
      }
      if (endOfArray!=true){
      filePath+=myDocsPath[k];
      }
   }

   //filePath.shrink_to_fit();
   filePath+="/Data/";
   filePath+=fileName;
   cout<<filePath<<endl;
   myfile.open(filePath.c_str());
}
else if (keyInput=="3")
{
   studentDrive="P:/";
   filePath=studentDrive;
   filePath+="Data/";
   filePath+=fileName;
   myfile.open(filePath.c_str());
   cout<<filePath<<endl;
}
else
{
   cout<<"I don't know..."<<endl;
}

if (myfile.is_open()){
   cout<<"File found and opened."<<endl;
   fileOpen=true;
}
else
{
   cout<<"File does not exist, or cannot be opened"<<endl;
   system("PAUSE");
   system("CLS");
   fileOpen=false;
   return FAILURE_NUM;
}

system("PAUSE");
system("CLS");


if (myfile.eof()){
   cout<<"File is empty, or some other thing happened"<<endl;
}

//if(myfile.eof()!=true){
//getline(myfile,nextLine);
//pch = strtok ()
//cout<<nextLine<<endl;
//}

std::vector<char> writable(MAX_LINE_LENGTH + 1);// for use in
std::string tempString = "";

while (myfile.eof()!=true){
   getline(myfile,nextLine);
   if (nextLine.length()!=0){
      if (nextLine.at(0)!=0&&nextLine.at(0)!=32){
         nextLine+=empty;
         std::copy(nextLine.begin(), nextLine.end(), writable.begin());
         pch = strtok (&*writable.begin(), " ,");
         while (pch!=NULL){
            cout<<pch<<endl;
            tempString=pch;
            pch = strtok(NULL, " ,");
         }
      }
   }
}
//code currently outputs each token on a new line. I will later put the tokens in an array.

//char asdfasdf[] ="1 2 3 4 5 6 7 8 9 asdf";
//char* pch;
//std::string asdfasdfa="0";
//pch = strtok (asdfasdf," ,.-");
//
//while(pch!=NULL){
//   cout<<pch<<endl;
//   asdfasdfa+=pch;
//   pch=strtok (NULL," ,.-");
//
//}
//cout<<asdfasdfa<<endl;
system("PAUSE");

treeNodeBinary* rootNode;



//rootNode.

ifstream treeDataFile;




//cout<<"Would you like to save the sorted data?"<,endl;
//ofstream treeOutputData;

return 1;
}

int SelectScreens::helloWorld()
{
char s1[254]="Hello worl";
char s2[254];
int counter=0;
int counter2=0;

s2[0]='d';
s2[1]='!';
s2[2]=0;

//cout<<s1<<endl;
//system("PAUSE");

do{
   if (s1[counter]!=0){
      counter++;
   }
   if (s1[counter]==0){
      do{
         s1[counter]=s2[counter2];
         counter++;
         counter2++;
      }while(s2[counter2]!=0);
      break;
   }


}while(true);

cout<<s1<<endl<<endl;
system("PAUSE");

return 1;
}

int SelectScreens::dwarfGame(int difficulty)
{
//struct tile graphicDataDwarf[SCREEN_WIDTH*SCREEN_HEIGHT];
system("CLS");





return 1;
}



























