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

   time_t timer; struct tm* ptm;
   timer = time(NULL);
   ptm = localtime (&timer);
   strftime(cStr, 20, "%F", ptm);
   //http://www.cplusplus.com/reference/ctime/strftime/
}

~eventLog()
{
   if (lineBufferLength > 0){
      pushBuffer();
   }
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
   logFile.bufferAddition(buffer);
   logFile.writeBuffer();

   fileMaxSize += lineBufferLength;
   lineBufferLength = 0;

   if (fileLineLength >= fileMaxSize){

   }

}





};


extern eventLog* eventLogger;




#endif // EVENTLOG_H_INCLUDED
