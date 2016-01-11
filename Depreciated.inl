//
//#include <cstdarg>
//#include <iostream>
//#include <fstream>
//
//using namespace std;
////For dataType,
////0 for int, 1 for char, 2 for float, 3 for double, 4 for short, 5 for long long, 6 for unsigned int...
////7 for unsigned short,  More may be added later.
//
////numWanted is the length of the array. (note, a pointer to a single thing is still treated like an array)
////returns 0 for failure, else 1
//int readData(int dataType, int arrayLength, ...)
//{
//   //int *asdf;
//   char buffer[256];
//   void * output;
//   //void * temp;
//   int bytesToGet=4;
//   int j = 0;
//   if (dataType>=5||dataType<=-1){
//      return 0;
//   }
//
//   if (arrayLength<0) return 0;
//
//   bytesToGet = 1;
//
//   if (dataType==1){ bytesToGet = 1;}
//
//   if (dataType==3||dataType==5){ bytesToGet = 8;}
//
//   if (dataType==4){ bytesToGet = 2;}
//
//   va_list ap;
//   //va_start(ap, numWanted);
//
//   output = va_arg(ap, void *);
//
//   if (output==0) return 0;
//
//   for (j=0;j<arrayLength;j++){
      //read bytes, chance to fail...
      //myfile.read(buffer, bytesToGet);
      //if (myfile.eof()&&myfile.fail()) return 0; //hit end of file...
      //switch (dataType) {
//         case 0:
//            *((int*)output) = cToI(buffer);
//            break;
//         case 1:
//            *((char*)output) = buffer[j];
//            break;
//         case 2:
//            *((float*)output) = *((float*)((buffer)));
//            break;
//         case 3:
//            *((double*)output) = *((double*)((buffer)));
//            break;
//         case 4:
//            *((short*)output) = cToS(buffer);
//            break;
//         case 5:
//            *((long long*)output) = *((long long*)((buffer)));
//            break;
//         case 6:
//            *((unsigned int*)output) = cToUI(buffer);
//            break;
//         case 7:
//            *((unsigned short*)output) = cToUS(buffer);
//            break;
//         case 8:
//            //*((long long*)output) = *((long long*)((buffer)));
//            break;
//
//      }

   }
   //http://www.dreamincode.net/forums/topic/47339-writing-floats-to-a-file/
   //in.read((char *)&f2,sizeof(float));
   //*((int *)output) = qwer;
//return 1;
}//Unfinished


/*
bool getProfile(std::string name)
{

ifstream myfile;
std::string fileName;
fileName= "saves/"+name+".dat";
myfile.open (fileName.c_str());

   if (myfile.is_open()) {
      cout<<"yey!";
      return true;
   }

}

bool makeProfile(std::string name)
{

ofstream myfile;
std::string fileName;
fileName = "saves/"+name+".dat";
myfile.open(fileName.c_str());

if (myfile.is_open()){
   cout<<"yey!";
   myfile << "Writing this to a file.\n";
}

}

*/
//   switch (dataType) {
//      case 0:
//         *((int*)output) = cToI(buffer);
//         break;
//      case 1:
//         *((char*)output) = buffer[j];
//         break;
//      case 2:
//         *((float*)output) = *((float*)((buffer)));
//         break;
//      case 3:
//         *((double*)output) = *((double*)((buffer)));
//         break;
//      case 4:
//         *((short*)output) = cToS(buffer);
//         break;
//      case 5:
//         *((long long*)output) = *((long long*)((buffer)));
//         break;
//      case 6:
//         *((unsigned int*)output) = cToUI(buffer);
//         break;
//      case 7:
//         *((unsigned short*)output) = cToUS(buffer);
//         break;
//      case 8:
//         //*((long long*)output) = *((long long*)((buffer)));
//         break;
// }
   //http://www.dreamincode.net/forums/topic/47339-writing-floats-to-a-file/
   //in.read((char *)&f2,sizeof(float));
   //*((int *)output) = qwer;



   //int asos[512];
//   for (int i=0;i<512;i++){
//      asos[i]=i%26+65;cout<<asos[i]<<" "<<i<<endl;
//   }
//   testingSize.a = 1;testingSize.b = 2; testingSize.c = 3; testingSize.d = 4;
//   testingSize.e = 'q'; testingSize.f = 'w';
//
//   //poi(sizeof(testingSize), &testingSize);
//   cout<<"..."<<endl;
//   myFile.goStart(0);
//   myFile.writeData(sizeof(asos[0]), 512, asos);
//
//   for (int i=0;i<512;i++){
//      asos[i]=0;
//   }
//
//   cout<<myFile.readData(0, 512, asos);
//   system("PAUSE");
//
//   for (int i=0;i<(512/2);i++){//Sort of works... Why?
//   //   asos[i]=i*2;
//   cout<<asos[i*2]<<" "<<asos[i*2+1]<<": "<<i<<endl;
//   }


//   cout<<"???1"<<endl;
//   myFile.textOpenFile("Data/test.txt", true);//Putting true there overwrites the original data.
//   cout<<"???2"<<endl;
//   myFile.bufferLines("Hello!");
//   cout<<"???3"<<endl;
//   myFile.bufferLines("Can you hear me?");
//   cout<<"???4"<<endl;
//   myFile.bufferLines("Now for other stuff!");
//   cout<<"???5";
//   myFile.writeBuffer();
//   system("PAUSE");
//   myFile.bufferLines("Hello!X2");
//   system("PAUSE");
//   myFile.writeBuffer();
//   myFile.bufferAddition("Adding to buffer...");myFile.bufferAddition("\nAdding to buffer...");
//   myFile.writeBuffer(true);
//   system("PAUSE");
//   myFile.bufferAddition(" Does this work? ...");//This doesn't work...
//   system("PAUSE");
//   myFile.bufferLines(" Done buffering!");
//   system("PAUSE");
//   myFile.writeBuffer();



//int powerTo(int base, int exponential){
//   unsigned int output = 1;
//   if (exponential<=0){
//      return 1;//No fractions!
//   }
//
//   for (int i=0; i<exponential; i++){
//      output = output * exponential;
//   }
//
//   return output;
//}
//
//std::vector <std::string> createTestCases(int testCaseSize)
//{
//   cout<<testCaseSize<<endl;
//   std::string temp;
//   std::vector <std::string> output;
//   std::vector <std::string> inputOutput;
//   output.reserve(powerTo(52, testCaseSize) + powerTo(52, testCaseSize/2));
//   int counter=0;
//   char allChars[52];//All the chars I want. Only letters for now.
//   //65 - 90, 97 - 122
//   //cout<<"Stuff!"<<endl;
//   for (int i='a';i<='z';i++){
//      allChars[i-'a']=i;
//   }
//   for (int i='A'; i<='Z';i++){
//      allChars[i + 'z' - 'a' - 'A' + 1] = i;
//   }
//
//   //cout<<"End stuff!"<<endl;
//   //cout<<"Why you so sad!"<<" "<<testCaseSize<<endl;
//   int currentInt[testCaseSize];//={65};
//
//   for (int i=0; i<testCaseSize;i++){
//      currentInt[i] = allChars[0] - 'a';
//   }
//
//   while(true){
//
//      for (int i=testCaseSize-1; i>=0;i--){
//         cout<<"One loop done!"<<endl;
//         if (currentInt[i]>=52){
//            if (i==(0)){
//               if (testCaseSize>1){
//                  inputOutput = createTestCases(testCaseSize - 1);
//                  output.insert(output.end(), inputOutput.begin(), inputOutput.end());
//               }
//
//               return output;
//            }
//            currentInt[i-1]+=1; currentInt[i] = 0;
//
//         }
//      }
//
//      for (int i = 0; i<testCaseSize; i++){
//         temp += allChars[currentInt[i]];
//      }
//      output.push_back(temp);
//      temp.clear();
//      counter++;
//
//   currentInt[testCaseSize-1]+=1;
//   }
//}






//   //system("PAUSE");
//   std::string password = "TESING STUFF";
//   std::string newPass;
//   std::vector<std::string> testCases ;
//   std::vector<unsigned int> testAnswers;
//   unsigned int tempInt;
//   stringstream ss;
//   int numCollisions = 0;
//   //std::getline (std::cin, password);//Unlimited size of passwords
//   //std::cin.getline(password, 64);//Passwords are up to 64 chars in size
//   //Bromo.passwordToInt(password);
//
//   int k=0;
//   testCases = createTestCases(4);//(testCaseSize)
//   int vectorSize = testCases.size();
//   cout<<vectorSize<<endl;
//   //system("PAUSE");
//
//   for (int i=0; i<vectorSize;i++){
//      cout<<i<<endl;
//      newPass.clear();
//      newPass = testCases[i];
//      if (newPass.empty()){
//         break;
//      }
//      cout<<newPass<<endl;
//      tempInt = Bromo.passwordToHashInt(newPass);
//      //cout<<tempInt<<" Hash things!"<<endl;
//      testAnswers.push_back(tempInt);
//      //system("PAUSE");
//   }
//
//
//
//   cout<<"Is this bad?"<<vectorSize<<endl;
//   std::sort (testAnswers.begin(), testAnswers.end());
//   //system("PAUSE");
//   int numMult=0; unsigned int currentNumFound = testAnswers[0];
//   for (int i=0; i<20;i++){
//      cout<<testAnswers[i]<<endl;
//   }
//
//   for(int i=0; i<vectorSize;i++){
//           cout<<i<<endl;
//      while(true){
//         if (i==(vectorSize-1)){
//            cout<<"The END!"<<endl;
//            break;
//         }
//
//         if (currentNumFound!=testAnswers[i]){
//            i--;
//            currentNumFound = testAnswers[i+1];
//            if (numMult>2){
//               cout<<"There are "<<numMult<<" of the number "
//               <<testAnswers[i+1]<<endl;
//               ss<<"There are "<<numMult<<" of the number "
//               <<testAnswers[i+1]<<endl;
//               numCollisions +=numMult;
//               myFile.bufferLines(ss.str());
//               ss.str( std::string() );
//               ss.clear();
//            }
//            numMult = 0;
//            break;
//         }
//         numMult++;
//         i++;
//         cout<<i<<" "<<numMult<<" "<<testAnswers[i]<<endl;
//         //system("PAUSE");
//      }
//   }
//   ss.str( std::string() );
//   ss.clear();
//   ss<<numCollisions<<" "<<vectorSize<<endl;
//   myFile.bufferLines(ss.str());
//   ss.str( std::string() );
//   ss.clear();
//   float percentError=0.000;
//   percentError = (float)numCollisions / (float)vectorSize;
//   percentError = percentError*100.000;
//   ss<<"The percent collision was "<<percentError<<"% !"<<endl;
//   myFile.bufferLines(ss.str());
//   myFile.writeBuffer();
//


//   Keypress keyReader;
//
//   int keyIn;
//   while(true){
//      keyIn = keyReader.get_code();
//      if (keyIn != -1){
//         cout<<keyIn<<endl;
//         break;
//      }
//   }


//   myFile.textOpenFile("Data/Aso.txt", false);
//   std::string asos;
//   std::vector <std::string> fileBuffer;
//
//   while(myFile.readLine(&asos)){
//      fileBuffer.push_back(asos);
//   }
//
//   for (int i=0; i<fileBuffer.size();i++){
//      cout<<fileBuffer[i]<<"!"<<endl;;
//   }

//   myFile.closeFile();

//   myFile.dataOpenFile("Data/Aso.bin", true);
//   int intArray[5] = {65, 66, 67, 68, 69};
//   char strings[23] = "This is another test!!";//22
//   char inputString[23];//
//   int newArray[5];
//   cout<<myFile.writeData(sizeof(int), 5, intArray)<<endl;
//   cout<<myFile.writeData(sizeof(char), 23, strings)<<endl;
//   cout<<myFile.goStart(1)<<endl;
//   int otherStuff = 0;
//   int* stuff = &otherStuff;
//   myFile.readData(sizeof(int), 5, stuff, newArray);
//   cout<<otherStuff<<" Debug!"<<endl;
//
//   myFile.readData(sizeof(char), 23, stuff, inputString);
//   cout<<otherStuff<<endl;
//
//   for (int i=0; i<5; i++){
//      cout<<newArray[i]<<" ";
//   }
//   cout<<endl;
//   cout<<inputString;
//   cout<<endl;
//   myFile.closeFile();
//
//   myFile.dataOpenFile("Data/Bromo.bin", true);
//   int otherArray[4] = {4, 5, 6, 7};
//   cout<<myFile.writeData(sizeof(int), 4, otherArray)<<endl;
//   char strings2[23] = "Tihs is another tset??";//22
//   cout<<myFile.writeData(sizeof(char), 23, strings2)<<endl;
//   cout<<myFile.goStart(1)<<endl;
//   int otherStuff2 = 0;
//   int* stuff2 = &otherStuff2;
//
//   myFile.readData(sizeof(int), 4, stuff, newArray);
//   cout<<otherStuff<<" Debug!"<<endl;
//
//   myFile.readData(sizeof(char), 23, stuff, inputString);
//   cout<<otherStuff<<endl;


//int poi(int size, ...)
//{
//   va_list ap;
//   int j=0;
//   char* asdf;
//   va_start(ap, size); //Requires the last fixed parameter (to get the address)
//   asdf=va_arg(ap, char*); //Requires the type to cast to. Increments ap to the next argument.
//   va_end(ap);
//   cout<<sizeof(asdf)<<"asdfasdf"<<endl;
//   int counter=0;
//
//   for (int i=0;i<(size/4)-1;i++){
//      cout<<(int)((unsigned char)(*(asdf+i*4)))<<"."<<endl;
//      counter=i;
//   }
//   cout<<(char)((unsigned char)(*(asdf+counter*(4+1)+1)))<<"."<<endl;
//   cout<<(char)((unsigned char)(*(asdf+counter*(4+1)+2)))<<"."<<endl;
//   //Yey! I can read/write structures!
//
//   //for (int i=3;i>=0;i--){
////      cout<<(int)((unsigned char)(*(asdf+i)))<<"."<<endl;
////      j = (j*256) + (int)((unsigned char)(*(asdf+i)));
////   }
//
////
//
//   cout<<j<<"qqq"<<endl;
//}

/*

//Dempo.directoryPath = "D:\\Test\\";
//Dempo.deleteFolder("asdfasdf", NULL);
//cout<<Dempo.deleteFolder(&folderStuff, &tempNameFolder)<<endl;


//std::string something = "D:/Test/Stuff/";
//std::string something2 = "D:/Test/";
//std::string something3 = "Stuff/";
//wchar_t stuffs[512];


//int lengthWString = Dempo.charPToWCharP(something.c_str(), stuffs, 512);
//stuffs

//Returns one is true, else 0;
//cout<<RemoveDirectory(something.c_str())<<endl;

//std::vector<WIN32_FIND_DATA> uaehr;


//cout<<Dempo.findAllFilesInFolder(something.c_str(), NULL, &uaehr)<<" asdf"<<endl;
//^ Yey! It works now!
//cout<<Dempo.deleteFolder(NULL, &something3)<<endl;
//cout<<RemoveDirectory("D:\\Test\\Stuff\\qwer\\qwerqwer")<<" aukshfiuh "<<"D:\\Test\\Stuff\\qwer\\qwerqwer"<<endl;
//uaehr.clear();



//cout<<Dempo.findAllFilesInFolder(something.c_str(), NULL, &uaehr)<<" asdf"<<endl;

//cout<<Dempo.getExecutablePath()<<endl;

//std::string ijn = "Testing stuff";



//Dempo.charPToWCharP(ijn.c_str(), stuffs, 512);












int x; int y;

while(true){
   system("CLS");

   testConsole.cursorOptions.changeCursorPos(0, 0);
   testConsole.cursorOptions.cursorControl(3);
   cout<<"This is a random number test!"<<endl;

   for (int counterPixel = 0; counterPixel < 1600000; counterPixel++){
      x = rand() % screenX; y = rand() % (screenY - 3) + 2;
      testConsole.cursorOptions.changeCursorPos(x, y);
      cout<<(char)178;
      testConsole.cursorOptions.cursorControl(2);
      Sleep(0.5);
   }

   testConsole.cursorOptions.changeCursorPos(0, 1);
   testConsole.cursorOptions.cursorControl(3);
   cout<<"Test complete!"<<endl;

Sleep(2000);
}







testConsole.cursorOptions.changeCursorPos(50, 50);
cout<<"Is it working?"<<endl;
testConsole.cursorOptions.changeCursorPos(50, 51);
cout<<"This should work too!"<<endl;
Sleep(6000);
Beep(700, 300);//Beep!
testConsole.cursorOptions.changeCursorPos(50, 50);
cout<<"Did this do anything?"<<endl;



*/


/*
bool keyPressed[4]; bool keyDown[4];
system("PAUSE");
KeyIO.get_code(keyPressed, keyDown, "asdf");
system("PAUSE");
KeyIO.get_code(keyPressed, keyDown, "asdf");
std::string inputStuff;
cin>>inputStuff;

*/















