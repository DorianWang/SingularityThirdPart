#ifndef EVENTLOG_H_INCLUDED
#define EVENTLOG_H_INCLUDED

#include "libraryIncluder.h"
#include <ctime>


#define EVENT_LOG_LOCATION "\Data\Event_logs"
#define EVENT_LOG_NAME "STP_Log.txt"

#define MAX_FILE_LINE_LENGTH 4096
#define NORMAL_BUFFER_SIZE 8
//Defaults of 4096 and 8.

#define DEBUG_FILE_LINE_LENGTH 2048
#define DEBUG_BUFFER_SIZE 1

class eventLog
{

FileIO logFile;
std::string fileName;

std::string buffer;

int lineBufferLength;
int fileLineLength;

int bufferMaxSize;
int fileMaxSize;

public:

eventLog(bool debugMode)
{
   lineBufferLength = 0;
   fileLineLength = 0;

   if (debugMode){
      bufferMaxSize = DEBUG_BUFFER_SIZE;
      fileMaxSize = DEBUG_FILE_LINE_LENGTH;
   }
   else
   {
      bufferMaxSize = NORMAL_BUFFER_SIZE;
      fileMaxSize = MAX_FILE_LINE_LENGTH;
   }

newFile();


}

~eventLog()
{
   if (lineBufferLength > 0){
      pushBuffer();
   }
}

void newFile()
{
   time_t timer; struct tm* ptm; char cStr[32];
   timer = time(NULL);
   ptm = localtime (&timer);
   strftime(cStr, 30, "%Y_%m_%d_%H_%M", ptm);
   //http://www.cplusplus.com/reference/ctime/strftime/

   fileName = cStr + "_LOG.txt";

   FileIO tempFile;
   tempFile.textOpenFile(fileName, true);
   logFile.closeFile();
   logFile = tempFile;
}



void addNewLog(std::string input)
{
   buffer << input << "\n" ;
   lineBufferLength++;

   if (lineBufferLength >= bufferMaxSize){
      pushBuffer();
   }

};


bool pushBuffer()
{
   if (lineBufferLength <= 0){
      lineBufferLength = 0;
      return false;
   }
   logFile.bufferAddition(buffer);
   logFile.writeBuffer();

   fileMaxSize += lineBufferLength;
   lineBufferLength = 0;

   if (fileLineLength >= fileMaxSize){
      newFile();
   }
return true;
}





};


extern eventLog* eventLogger;




#endif // EVENTLOG_H_INCLUDED
