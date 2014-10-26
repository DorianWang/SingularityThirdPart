
#ifndef TAKE_GAME_FILE_READER_H
#define TAKE_GAME_FILE_READER_H

#include "MapLoader.h"
//#include "InteractionStuff.h"


#include "UsefulHeaders.h"

#define MASTER_FILE_PATH "Data/"

#define FIRST_CHECK_INT 0x03092014
#define SECOND_CHECK_INT 0xACAD1A01
#define THIRD_CHECK_INT 0xF92343F9
#define FOURTH_CHECK_INT 0xABCDEF98

class takeGameFileReader
{

   FileIO masterFile;
   std::string masterFileName;

   FileIO currentFile;
   std::string currentFileName;

   bool isFileCompiled;

   public:


   bool isFileOpen;

   takeGameFileReader(std::string inputMasterFileName);
   ~takeGameFileReader();

   void initialize();

   void resetMasterFile(std::string input);
};

#endif















