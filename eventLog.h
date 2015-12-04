#ifndef EVENTLOG_H_INCLUDED
#define EVENTLOG_H_INCLUDED

#include "libraryIncluder.h"
#include <ctime>


#define EVENT_LOG_LOCATION "Data\\Event_logs\\"
//#define EVENT_LOG_LOCATION ""
#define EVENT_LOG_NAME "STP_Log.txt"

#define MAX_FILE_LINE_LENGTH 4096
#define NORMAL_BUFFER_SIZE 8
//Defaults of 4096 and 8.

#define DEBUG_FILE_LINE_LENGTH 2048
#define DEBUG_BUFFER_SIZE 1

#define DEBUG_MODE true
#define NO_DEBUG_MODE false

namespace eventRecorder
{


class eventLog
{

FileIO* logFile;
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
logFile = NULL;
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
   system("PAUSE");
   ptm = localtime (&timer);
   strftime(cStr, 30, "%Y_%m_%d_%H_%M", ptm);
   //http://www.cplusplus.com/reference/ctime/strftime/
   fileName = EVENT_LOG_LOCATION;
   fileName += (std::string)cStr;
   fileName += (std::string)"_LOG.txt";
   system("PAUSE");

   FileIO* tempFile = new FileIO;
   tempFile -> textOpenFile(fileName, true);
   if (logFile != NULL){
      logFile -> closeFile();
      delete logFile;
   }
   logFile = tempFile;
   //cout << fileName << " " << tempFile <<endl;
}


void addNewLog(std::string input)
{
   buffer += input ;
   lineBufferLength++;

   if (lineBufferLength >= bufferMaxSize){
      pushBuffer();
   }
   else
   {
      buffer += "\n";
   }
};


bool pushBuffer()
{
   if (lineBufferLength <= 0){
      lineBufferLength = 0;
      return false;
   }
   cout << buffer << endl;
   logFile -> writeLine(buffer);

   buffer = std::string("");

   fileMaxSize += lineBufferLength;
   lineBufferLength = 0;

   if (fileLineLength >= fileMaxSize){
      newFile();
   }
return true;
};

};
//End eventLog class

}

#endif // EVENTLOG_H_INCLUDED

extern eventRecorder::eventLog* eventLogger;












