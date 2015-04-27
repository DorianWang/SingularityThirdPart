#ifndef EVENTLOG_H_INCLUDED
#define EVENTLOG_H_INCLUDED

#include "libraryIncluder.h"


#define EVENT_LOG_LOCATION "\Data\Event_logs"
#define EVENT_LOG_NAME "STP_Log.txt"

#define MAX_FILE_LINE_LENGTH 4096
#define NORMAL_BUFFER_SIZE 8
//Defaults of 4096 and 8.
//In debug mode, it is 2048 and 1.

class eventLog
{

FileIO logFile;
std::string buffer;
int lineBufferLength;



public:

eventLog()
{
   lineBufferLength = 0;
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

   if (lineBufferLength >= NORMAL_BUFFER_SIZE){
      pushBuffer();
   }

};


bool pushBuffer()
{
   logFile.bufferAddition(buffer);
   logFile.writeBuffer();
}





};


extern eventLog* eventLogger;




#endif // EVENTLOG_H_INCLUDED
