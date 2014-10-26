
#include "Encrypt.h"

Encrypter::Encrypter()
{
   //char importantChars[NUM_IMPORTANT_CHARS]={'.', ',', '!', ' ', '?', 'a'};
   char tempArrayOne[NUM_IMPORTANT_CHARS] = {'.', ',', '!', ' ', '?', 'a'};
   
   for (int i=0; i<NUM_IMPORTANT_CHARS; i++){
      importantChars[i] = tempArrayOne[i];
   }
   
   // : = 58, " = 34, \ = 92, / = 47
   //char otherChars[NUM_OTHER_CHARS]={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   char tempArrayTwo[NUM_OTHER_CHARS] = {'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'}; 
   for (int i=0; i<NUM_IMPORTANT_CHARS; i++){
      otherChars[i] = tempArrayTwo[i];
   }
   
   importantChars[5] = 34; 
   otherChars[11] = 47; otherChars[12] = 58; otherChars[13] = 92;
                
}



//int randInt = rand() % 262144;//65536 (16*16*16*16*4)4*2^4^4, or 2^18
int myRand (int i) { return std::rand()%(i);}

int Encrypter::keygenChars(char* charSpace, char* scrambledCipher, char* antiCipherChars, bool *cipherType) //For creating new rotors, reflectors and things
{
   //I think I'll split them into 5 pieces. alphabet, upperAlphabet, numbers, important characters, and extras
   char alphabet[26];
   char upperAlphabet[26];
   char importantChars[NUM_IMPORTANT_CHARS]={'.', ',', '!', ' ', '?', 'a'};
   char numbers[10];
   // : = 58, " = 34, \ = 92, / = 47
   char otherChars[NUM_OTHER_CHARS]={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   
   //bool cipherType[5];
   
   //testing
   for (int q=0; q<5; q++){cipherType[q]=true;};
   
   std::vector<char> cipherCharSpace;
   std::vector<char> cipherScrambled;

   //Special chars that are annoying.
   importantChars[5] = 34; 
   otherChars[11] = 47; otherChars[12] = 58; otherChars[13] = 92;
   
   //How many? 
   //newLine character which I'll have as "{" and a tab as "}", backspace as "~"
   
   //http://www.asciitable.com/
   
   int vectorCounter = 0;

if (cipherType[0]==true){
   for (int i='a'-'a';i<'z'-'a'+1;i++){
      alphabet[i]='a' + i;
      cout<<alphabet[i];
      cipherCharSpace.push_back(alphabet[i]);
      vectorCounter++;
   }
}
//cout<<endl;
if (cipherType[1]==true){
   for (int i='A'-'A';i<'Z'-'A' + 1;i++){
      upperAlphabet[i]='A' + i;
      cout<<upperAlphabet[i];
      cipherCharSpace.push_back(upperAlphabet[i]);
      vectorCounter++;
   }
}
//cout<<endl;
if (cipherType[2]==true){
   for (int i=0;i<NUM_IMPORTANT_CHARS;i++){
      //importantChars[i]='0' + i;
      cout<<importantChars[i];
      cipherCharSpace.push_back(importantChars[i]);
      vectorCounter++;
   }
}
//cout<<endl;

if (cipherType[3]==true){
   for (int i='0'-'0';i<'9'-'0' + 1;i++){
      numbers[i]='0' + i;
      cout<<numbers[i];
      cipherCharSpace.push_back(numbers[i]);
      vectorCounter++;
   }
}

if (cipherType[4]==true){
   for (int i=0;i<NUM_OTHER_CHARS;i++){
      //otherChars[i]='0' + i;
      cout<<otherChars[i];
      cipherCharSpace.push_back(otherChars[i]);
      vectorCounter++;
   }
}

   //add rotor complexity selection here.
   //How about antirotors, for decryption?

   srand ( time(NULL) );
   //65536
   
   //for (int i=0; i<10; ++i) cipherCharSpace.push_back(i); // 1 2 3 4 5 6 7 8 9
   cipherScrambled = cipherCharSpace;
   //randomization.
   
   for (int i=0;i<vectorCounter;i++){
      cout<< cipherCharSpace[i];   
   }
   cout<<endl;
   
   std::random_shuffle ( cipherScrambled.begin(), cipherScrambled.end() );
   std::random_shuffle ( cipherScrambled.begin(), cipherScrambled.end() , myRand);
   //Used to cause segfaults...
   
   
   std::vector<char> antiCipher (vectorCounter); int temp = 0;

   for (int j = 0; j<vectorCounter; j++){
      for (int k=0; k<vectorCounter; k++){
         if (cipherScrambled[j]==cipherCharSpace[k]){
            temp = k;
            break;
         } 
      }   
      
      antiCipher[temp] = cipherCharSpace[j];
      
   }
   /* Print path vector to console 
   copy(path.begin(), path.end(), ostream_iterator<char>(cout, " "));
   */
   
   for(int i=0; i<vectorCounter; i++){charSpace[i]=cipherCharSpace[i];}


   for(int i=0; i<vectorCounter; i++){scrambledCipher[i]=cipherScrambled[i];}
   
   for(int i=0; i<vectorCounter; i++){antiCipherChars[i]=antiCipher[i];}
   //for( std::vector<char>::const_iterator i = cipherScrambled.begin(); i != cipherScrambled.end(); i++){ std::cout << *i;}
   //cout<<endl;
   //for( std::vector<char>::const_iterator i = antiCipher.begin(); i != antiCipher.end(); i++){ std::cout << *i;}
   //cout<<endl<<endl;


//system("PAUSE");
return vectorCounter;
}

//Creates the charspace required...
std::vector <int> Encrypter::createCharSpace(bool* cipherType)
{
std::vector <int> cipherIntSpace;           
int vectorCounter = 0;
   if (cipherType[0]==true){
      for (int i='a'-'a';i<'z'-'a'+1;i++){
         cipherIntSpace.push_back(vectorCounter);
         vectorCounter++;
      }
   }

   if (cipherType[1]==true){
      for (int i='A'-'A';i<'Z'-'A' + 1;i++){
         cipherIntSpace.push_back(vectorCounter);
         vectorCounter++;
      }
   }

   if (cipherType[2]==true){
      for (int i=0;i<NUM_IMPORTANT_CHARS;i++){
         cipherIntSpace.push_back(vectorCounter);
         vectorCounter++;
      }
   }
   
   if (cipherType[3]==true){
      for (int i='0'-'0';i<'9'-'0' + 1;i++){
         cipherIntSpace.push_back(vectorCounter);
         vectorCounter++;
      }
   }
   
   if (cipherType[4]==true){
      for (int i=0;i<NUM_OTHER_CHARS;i++){
         cipherIntSpace.push_back(vectorCounter);
         vectorCounter++;
      }
   }
return cipherIntSpace;
}


//A more useful cipher, that a computer can actually use.
//cipherNum is the number of ciphers which should be made. The char mapping will only be made once though.
//Then char map is basically a salt, preventing brute force guessing.
//The keyname is a name, and does not need to have a file extension. The function will add one.
int Encrypter::keygenInts(bool* cipherType, int numCiphers, std::string keyName)
{
int vectorCounter=0;

   for (int q=0; q<5; q++){cipherType[q]=true;};
    
   std::vector<int> cipherIntSpace;
   std::vector<int> cipherScrambled;
   std::vector<int> antiCipherInts;
   cipherIntSpace = createCharSpace(cipherType);
   
vectorCounter = cipherIntSpace.size();

int temp;

std::string fileName;
fileName = keyName;
fileName += ".cip";
FileIO outputFileCipher;
FileIO outputFileAntiCipher;
outputFileCipher.textOpenFile(fileName, true);
fileName.clear(); fileName = keyName; fileName += ".acp";
outputFileAntiCipher.textOpenFile(fileName, true);



stringstream ss;
ss<<numCiphers<<" ";
for (int i=0; i<5;i++){
   if (cipherType[i]){
      ss<<"1";   
   }    
   else
   {
      ss<<"0";    
   }
}
outputFileCipher.bufferLines(ss.str());
outputFileAntiCipher.bufferLines(ss.str());
ss.str(std::string());
ss.clear();

//creating ciphers
   for (int i=0;i<numCiphers;i++){
          
      //int check = keygenChars(charSpace, cipherSalt, antiCipherSalt, cipherType);
      //if (check!=vectorCounter){/*What happened?*/};
          
      cipherScrambled = cipherIntSpace;
      
      std::random_shuffle ( cipherScrambled.begin(), cipherScrambled.end(), myRand);
      for (int k=0; k<vectorCounter; k++){
         ss<<cipherScrambled[k]<<' ';
      }
      //cout<<ss.str()<<endl;
      outputFileCipher.bufferLines(ss.str());
      ss.str(std::string());
      ss.clear();
      antiCipherInts.resize(vectorCounter + 1,0);
      //Makes the vector a size of vectorCounter plus one, and fills it with 0s.
      
      for (int j=0;j<vectorCounter;j++){  
         temp = cipherScrambled[j];
         antiCipherInts[temp]=j;
      }
      
      for (int k=0; k<vectorCounter; k++){
         ss<<antiCipherInts[k]<<' ';
      }
      outputFileAntiCipher.bufferLines(ss.str());
      ss.str(std::string());
      ss.clear();
   }

outputFileCipher.writeBuffer();
outputFileAntiCipher.writeBuffer();
return 1;
}

//This will take a cipher, and shuffle it according to the hash.
int shuffleCipher (unsigned int hash, int typeCipher, ...)
{
   va_list args;
   va_start(args, typeCipher);
   
   if (hash != 0){
      srand(hash);
   }

   
   if (typeCipher == 1){
      intRotor* cipher = va_arg(args, intRotor*);
      std::random_shuffle ( cipher -> mapping.begin(), cipher -> mapping.end() , myRand);
      va_end(args);
      return 1;
   }
   
   if (typeCipher == 2){
      byteRotor* cipher = va_arg(args, byteRotor*);
      std::random_shuffle ( cipher -> mapping.begin(), cipher -> mapping.end() , myRand);
      va_end(args);
      return 1;
   }
   
va_end(args);
return 0;
}

//The returned cipher is true for cipher, and false for anticipher.
std::vector <int> Encrypter::keygenIntsCharMap(unsigned int passwordHash, bool* cipherType, bool cipherToReturn)
{
   std::vector <int> cipherIntSpace;
   cipherIntSpace = createCharSpace(cipherType);
   std::vector<int> cipherScrambled;
   std::vector <int> antiCipher;
   int temp = 0;
   int vectorCounter = cipherIntSpace.size();
   

   
   if (cipherToReturn){
      return cipherScrambled;
   }
   
   for (int j=0;j<vectorCounter;j++){  
      temp = cipherScrambled[j];
      antiCipher[temp]=j;
   }
   return antiCipher;
}

unsigned int Encrypter::hashString( const string &key) {
   long long hashVal = 0;
   
   int arrayLargePrimes[13]={978857489, 694846171, 961990429, 
   982451581, 674506409, 963287929, 674511707, 677404667, 685269437, 
   685263743, 967395713, 690473681, 693809153};
   
   int arrayMediumPrimes[14]={16859341, 16904803, 17096459, 18347759, 25047901, 
   28977719, 30798371, 32452837, 15480901, 
   15466951, 13380331, 7643873, 4172041, 15482917};
      
   int arraySmallPrimes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 
   29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
   
   unsigned int primeCounter = (key[0]*arrayMediumPrimes[key[0]%14])%26;
   unsigned int allCharsTogether = 0;
   for(int i = 0; i<key.length();  i++){
     hashVal = ((arraySmallPrimes[primeCounter]*hashVal)%TWO_P_THIRTY_ONE_PRIME)
     +key[i];

      allCharsTogether = allCharsTogether % TWO_P_THIRTY_ONE_PRIME +key[i];
      
      if (primeCounter>=25){
         primeCounter = 0;
         continue;
      }
      primeCounter++;
   }

   
   hashVal = hashVal * (arrayLargePrimes[arraySmallPrimes[primeCounter%26]%13]
    - arrayLargePrimes[arraySmallPrimes[(primeCounter+1)%26]]);

   if(hashVal<0){
     hashVal = hashVal*(-1);// += tableSize;
   }
   cout<<hashVal<<" "<<allCharsTogether<<endl;
   return ((hashVal + allCharsTogether)%TWO_P_THIRTY_ONE_PRIME);
 }



//http://www.cse.yorku.ca/~oz/hash.html
//Knuth's Sorting and Searching
unsigned int Encrypter::passwordToHashInt(std::string password)
{
   std::string empty;
   empty += '0';
   //if (password.length()<5){return 0;}//Passwords must be a minimum length.
   if (password.length()>63){return 0;}//Passwords cannot be too large;
   unsigned int key = hashString(password);

return key;    
}

int Encrypter::createAllCiphers(bool* cipherType, int numCiphers, char* keyName, char* folderName, int totalNumCiphers)
{
   stringstream ss;
   for (int i=0; i<totalNumCiphers; i++){
      ss<<folderName<<"\\";
      
      if (keyName != NULL){
         ss<<keyName;
      }
      
      ss<<i;
      cout<<ss.str()<<endl;
      keygenInts(cipherType, numCiphers, ss.str());
      ss.str(std::string()); ss.clear();
   }
return 1;
}

int Encrypter::getCiphersFromFile(intRotor* rotors, bool* cipherType, FileIO* myFile, int maxRotors)
{
   stringstream ss;
   std::string temp;
   int counter = 0;
   (*myFile).readLine(&temp);
   ss<<temp;
   ss>>temp;
   int numCiphers = atoi(temp.c_str());
   ss>>temp;
   for (int i=0; i<5; i++){
      cipherType[i] = (temp[i] ? 1 : 0);
   }
   ss.str(std::string()); ss.clear();
   
   for (int i=0; i < min(numCiphers, maxRotors); i++){
      ss.str(std::string()); ss.clear(); temp.clear();
      if (!(*myFile).readLine(&temp)){ return 0;}//Fail at reading the file...
      ss<<temp;
      while(ss>>temp){
         rotors[i].mapping.push_back(atoi(temp.c_str()));
         counter ++;
      }
      rotors[i].rotorLength = counter;
      for (int j=0;j<5;j++){
         rotors[i].rotorType[j] = cipherType[j];
      }
      counter = 0;
   }
   
   return min(numCiphers, maxRotors);
}

bool Encrypter::iterateRotor(intRotor* rotor)
{
   (*rotor).currentNum++;
   int temp = rotor -> mapping[rotor -> mapping.back()];
   rotor -> mapping.insert(rotor -> mapping.begin(), temp);
   rotor -> mapping.pop_back();
   
   if ((*rotor).currentNum>=(*rotor).rotorLength){
      (*rotor).currentNum = 0;
      return true;   
   }
   return false;  
}

//Works for both ciphers and anti-ciphers!
char Encrypter::cipherChar(char input, intRotor* rotors, int numRotors)
{
   if (numRotors == 0){ return 0; }     

int inputNum = charToCipherInt(rotors[0].rotorType, input);     
int tempInt = inputNum; int counter = 0;
   for (int i=0; i<numRotors; i++){
      tempInt = rotors[i].mapping[tempInt];
   }
   while( (counter<numRotors) ){
      if (!iterateRotor(&(rotors[counter]))){ break;}
      counter++;
   };

   return cipherIntToChar(rotors[0].rotorType, tempInt);  
}


std::string Encrypter::encryptString(intRotor* rotors, int numRotors, std::string input)
{
   std::string output; std::vector <int> tempRotor;
   for (int i=0; i<input.length(); i++){
      output += cipherChar(input.at(i), rotors, numRotors);
   }
   return output;
}

//Password files are formated like AC2DR4IN1DS5 "endl" /PASSWORD/
std::string Encrypter::passwordAndCipherFile(std::string fileName, std::string* cipherString)
{
   FileIO myFile; //Password files are .SPW
   myFile.textOpenFile(fileName, true);
   std::string fileInput;
   myFile.readLine(&fileInput);
   *cipherString = fileInput;
   fileInput.clear();
   myFile.readLine(&fileInput);
   return fileInput;
}

int Encrypter::createPasswordFile(std::string fileName, std::string password, std::string cipherString)
{
   FileIO myFile; //Password files are .SPW
   myFile.textOpenFile(fileName, true);
   myFile.bufferLines(cipherString); myFile.bufferLines(password);
   myFile.writeBuffer();
   return 1;
}

std::vector <std::string> Encrypter::decryptFile(FileIO* myFile, intRotor* rotors, int numRotors)
{
   std::string fileInput;
   std::string decryptedLine;
   std::vector <std::string> output;
   //output.reserve(myFile.)
   while((*myFile).readLine(&fileInput)){
      //decryptedLine = encryptString(fileInput);
      output.push_back(decryptedLine);
      decryptedLine.clear();
      fileInput.clear();
   }
   
} 

//cipherString is formatted like ABCBCDBDC -> groups of 3...
int Encrypter::readCiphersFromFiles(std::string cipherString, intRotor* rotors, std::string cipherName)
{
   FileIO myFile;
   int stringLength = cipherString.length();
   char FolderLetter = 'A'; int cipherNum = 0; int cipherLineInFile = 0;
   std::string filePath;
   std::string normalPath = "Data\\";
   bool rotorType[5]; int numRotors = 0;
   
   std::string input; int count = 0; int cipherNameLength = cipherName.length();
   
   if ((stringLength % 3) != 0){ return 0;} //String is not formatted properly
   
   for (int i = 0; i < stringLength; i = i){
      FolderLetter = cipherString.at(i); i++;
      cipherNum = cipherString.at(i) - 'A'; i++;
      cipherLineInFile = cipherString.at(i) - 'A'; i++;
      filePath = normalPath + FolderLetter;
      filePath += "\\"; 
      if (cipherNameLength == 0){
         filePath+=cipherName;   
      }
      filePath += cipherNum;
      cout<<filePath<<" This is the filePath found..."<<endl;
      myFile.textOpenFile(filePath, false);
      
      while(myFile.readLine(&input)){
         if (count == 0){ 
            int temp = 0;
            while(input[temp]!= ' '&&input[temp]<='9'&&input[temp]>='0'){
               numRotors = 10*numRotors + input[temp] - '0';
            }
            temp++;
            for (int j=0; j<5; j++){
               rotorType[j] = input[temp];
               temp++;    
            }
            temp = 0;
            
            //if (rotor)
         }
         count++;
         if (count == cipherNum + 1){
            break;//cipher found
         }
      }
      numRotors = 0;
      cout<<input<<" I read this!"<<endl;
      count = 0;
   }
    
}

int Encrypter::readCiphersFromFiles(std::string cipherString, byteRotor* rotors, std::string cipherName)
{
   FileIO myFile;
   int stringLength = cipherString.length();
   char FolderLetter = 'A'; int cipherNum = 0; int cipherLineInFile = 0;
   std::string filePath;
   std::string normalPath = "Data\\Byte_Rotors";
   bool rotorType[5]; int numRotors = 0;
   
   std::string input; int count = 0; int cipherNameLength = cipherName.length();
   
   if ((stringLength % 3) != 0){ return 0;} //String is not formatted properly
   
   for (int i = 0; i < stringLength; i = i){
      FolderLetter = cipherString.at(i); i++;
      cipherNum = cipherString.at(i) - 'A'; i++;
      cipherLineInFile = cipherString.at(i) - 'A'; i++;
      filePath = normalPath + FolderLetter;
      filePath += "\\"; 
      if (cipherNameLength == 0){
         filePath+=cipherName;   
      }
      filePath += cipherNum;
      cout<<filePath<<" This is the filePath found..."<<endl;
      myFile.textOpenFile(filePath, false);
      
      while(myFile.readLine(&input)){
         count++;
         if (count == cipherNum){
            rotors[numRotors] = stringToCipher(input);
            numRotors++;
            break;//cipher found
         }
      }
      myFile.closeFile();
      
      //numRotors = 0;
      cout<<input<<" I read this!"<<endl;
      count = 0;
   }
    
}


int Encrypter::decryptFileWithPassword(std::string password, std::string cipherString, FileIO* myTextFile)
{
   intRotor rotors[cipherString.length() / 2 + 1];
//   readCiphersFromFile(cipherString, rotors)
    
}

int Encrypter::fileToFileEncrypt(FileIO* sourceFile, FileIO* destinationFile, std::string password)
{
//Add stuff here!    
}


int Encrypter::dataToFile(FileIO* destinationFile, char* data, int cipherType, std::string password)
{
   //Will add over summer!
}

int Encrypter::cipherChar(char input, byteRotor* rotors, int numRotors)
{

   
    
}

int Encrypter::keygenBytes(int numCiphers, std::string keyName)
{
   if (numCiphers>MAX_CIPHERS_IN_FILE||numCiphers<=0){
      return 0;
   }
   std::string normalPath = "Data\\Byte_Rotors";
   std::vector <unsigned char> mappingTemplate;
   std::string tempPath = normalPath;
   stringstream ss; stringstream output; byteRotor temp; int tempInt = 0;
   std::vector <unsigned char> antiCipher; antiCipher.reserve(256+1);
   
   std::string tempString; char numCiphersChar = numCiphers;
   
   FileIO cipherFile; FileIO antiCipherFile;
   
   for (int i=0; i<256; i++){
      mappingTemplate.push_back((unsigned char) i);    
   }
   

   
   for (int k=0; k<6; k++){
      for (int j=0; j<26; j++){
         temp.mapping = mappingTemplate;
         
         ss<<normalPath<<"\\"<<(char)(k + 'A')<<"\\"<<keyName<<(int)j;
         cipherFile.dataOpenFile(ss.str() + ".cib", true); 
         antiCipherFile.dataOpenFile(ss.str() + ".acb", true); 
         cout<<ss.str()<<endl;
         
         //Writes the number of ciphers
         cipherFile.writeData(sizeof(char), 1, &numCiphersChar);
         cipherFile.writeData(sizeof(char), 1, &numCiphersChar);
         
         ss.str(std::string());
         ss.clear();
         
         for (int i=0; i<numCiphers; i++){
            cout<<shuffleCipher (0, 2, &temp)<<endl;
            
            for (int l=0;l<256;l++){  
               tempInt = temp.mapping[l];
               antiCipher[tempInt]=l;
            }
            
            cout<<endl;
            
            for (int m = 0; m<256; m++){
               output<<temp.mapping[m];//No need for spaces between characters.
            }
            
            tempString = output.str();
            
            cipherFile.writeData(sizeof(unsigned char), 256, tempString.c_str());
            output.str(std::string());
            output.clear();
               
            for (int m = 0; m<256; m++){
               output<<antiCipher[m];
            }
            
            tempString = output.str();
            antiCipherFile.writeData(sizeof(unsigned char), 256, tempString.c_str());
            output.str(std::string());
            output.clear();
            
            temp.mapping = mappingTemplate;
         }
         cipherFile.closeFile(); antiCipherFile.closeFile();
      }
   }
}


int Encrypter::gameHighScoreEncryption(FileIO* destinationFile, char* data, std::string cipherString)
{
   //cipherString is temporarily AAABBBCCCDDD
   std::string temp = "AAABBBCCCDDD";
   cipherString = temp;
   byteRotor rotors[4];
   readCiphersFromFiles(temp, rotors, "A");
   
   
    
    
    
}



























