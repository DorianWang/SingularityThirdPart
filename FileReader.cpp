
#include "FileReader.h"



takeGameFileReader::takeGameFileReader(std::string inputMasterFileName)
{
   masterFileName = inputMasterFileName;
   initialize();
   
   
   
}

takeGameFileReader::~takeGameFileReader()
{
   
   
   
   
}

void takeGameFileReader::initialize()
{
   isFileCompiled = false;
   isFileOpen = false;
   
   currentFile.closeFile();
   currentFileName.erase();
   
   resetMasterFile(masterFileName);

}



void takeGameFileReader::resetMasterFile(std::string input)
{
   masterFileName = input; int errorNum = 0; int returnNum = 0;
   int checkForCompilation[4];
   
   masterFile.closeFile();
   
   masterFile.dataOpenFile(MASTER_FILE_PATH + input, false);
   
   isFileOpen = masterFile.checkIfOpen();
   
   if (isFileOpen){
      returnNum = masterFile.readData(sizeof(int), 4, &errorNum, checkForCompilation);
      if (returnNum > 0 && errorNum > 0){
         if ((checkForCompilation[0] == FIRST_CHECK_INT) && 
         (checkForCompilation[1] == SECOND_CHECK_INT) && 
         (checkForCompilation[2] == THIRD_CHECK_INT) && 
         (checkForCompilation[3] == FOURTH_CHECK_INT)){
            isFileCompiled = true;
         }
      }
      isFileCompiled = false;
   }

}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
