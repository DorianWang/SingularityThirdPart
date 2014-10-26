#include "Encrypt.h"


int Encrypter::charToCipherInt(bool* cipherType, char input)
{
   char importantChars[NUM_IMPORTANT_CHARS]={'.', ',', '!', ' ', '?', 'a'};
   // : = 58, " = 34, \ = 92, / = 47
   char otherChars[NUM_OTHER_CHARS]={'@', '#', '$', '%', '^', '&', '*', '(', ')', ';', 'a', 'b', 'c', 'd', '~', '<', '>', '-', '_', '=', '+', '{', '}'};     
   importantChars[5] = 34; 
   otherChars[11] = 47; otherChars[12] = 58; otherChars[13] = 92;
   
   int typeCounter = 0;
   if (cipherType[0]){
      if(input>='a'&&input<='z'){
         return input - 'a' + typeCounter;
      }
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[1]){
      if(input>='A'&&input<='Z'){
         return input - 'A' + typeCounter;
      }
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[2]){
      for (int i=0; i<NUM_IMPORTANT_CHARS; i++){
         if(input==otherChars[i]){
            return i + typeCounter;
         }
      }
      typeCounter = typeCounter + NUM_IMPORTANT_CHARS;
   }

   if (cipherType[3]){
      if(input<='9'&&input>='0'){
         return input - '0' + typeCounter;
      }
      typeCounter = typeCounter + NUM_NUMBERS;
   }
   
   if (cipherType[4]){
      for (int i=0; i<NUM_OTHER_CHARS; i++){
         if(input==otherChars[i]){
            return i + typeCounter;
         }
      }
      //typeCounter = typeCounter + NUM_OTHER_CHARS;
      //Not needed...
   }
    
return -1; //not in cipher
}


char Encrypter::cipherIntToChar(bool* cipherType, int input)
{

   
   
   int typeCounter = 0; int temp = 0;
   if (cipherType[0]){
      temp = input - typeCounter;
      if(temp>=0&&temp<NUM_LETTERS){
         return input + 'a';// + typeCounter;
      }
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[1]){
      temp = input - typeCounter;
      if(temp>=0&&temp<NUM_LETTERS){
         return temp + 'A';
      }
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[2]){
      temp = input - typeCounter;
      if(temp<NUM_IMPORTANT_CHARS&&temp>=0){
         return importantChars[temp];
      }
      typeCounter = typeCounter + NUM_IMPORTANT_CHARS;
   }

   if (cipherType[3]){
      temp = input - typeCounter;
      if(temp<NUM_NUMBERS&&temp>=0){
         return temp + '0';
      }
      typeCounter = typeCounter + NUM_NUMBERS;
   }
   
   if (cipherType[4]){
      temp = input - typeCounter;
      if(temp<NUM_OTHER_CHARS&&temp>=0){
         return temp + typeCounter;
      }
      //typeCounter = typeCounter + NUM_OTHER_CHARS;
      //Not needed...
   }
    
return 0; //not in cipher
}

int predictedCipherSize(bool cipherType[])
{
   int typeCounter = 0;
   if (cipherType[0]){
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[1]){
      typeCounter = typeCounter + NUM_LETTERS;
   }
   
   if (cipherType[2]){
      typeCounter = typeCounter + NUM_IMPORTANT_CHARS;
   }

   if (cipherType[3]){
      typeCounter = typeCounter + NUM_NUMBERS;
   }
   
   if (cipherType[4]){
      typeCounter = typeCounter + NUM_OTHER_CHARS;
   }
   return typeCounter;
}

     
intRotor Encrypter::stringToCipher(std::string cipherIn, bool cipherType[], int* errorNum)
{
   intRotor tempOutput;
   tempOutput.rotorLength = predictedCipherSize(cipherType); //Set the rotor's size
   std::vector <unsigned int> tempCipher;
   
   int stringLength = cipherIn.length();
   char tempString[MAX_CIPHER_SIZE];
   for (int i=0; i<=stringLength; i++){
      cipherIn.c_str();
   }
   char* pch; 
   pch = strtok (tempString," ");
   while(pch != NULL){
      tempCipher.push_back(atoi(pch));
      pch = strtok(NULL, " ");
   }
   
   if (tempCipher.size() != tempOutput.rotorLength){
      *errorNum = -1;   
      return tempOutput;
   }
   tempOutput.mapping = tempCipher; //Set the mapping
   
   for (int i=0; i<5; i++){
      tempOutput.rotorType[i] = cipherType[i]; //Sets the rotor type to the requested type
   }
   tempOutput.currentNum = 0;//Sets the rotor to 0. This should be changed for use.
   return tempOutput;//Return!
}
         
byteRotor Encrypter::stringToCipher(std::string cipherIn)
{
   int stringLength = cipherIn.length();//This should always be the same. Testing?
   std::vector <unsigned char> tempCipher; byteRotor output;
   char tempString[MAX_BYTE_CIPHER_SIZE];
   if (cipherIn.length() > MAX_BYTE_CIPHER_SIZE){ output.currentNum = 256; return output;}//not good...
   
   int i=0;
   while (cipherIn.at(i)!=0){
      tempString[i] = cipherIn.at(i);
      i++;
   }
   tempString[i] = 0;
   char* pch;
   pch = strtok (tempString," ");
   
   while(pch != NULL){
      tempCipher.push_back(atoi(pch));
      pch = strtok(NULL, " ");
   }
   
   output.mapping = tempCipher;
   output.currentNum = 0;
   return output;
}










