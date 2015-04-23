#ifndef EVENTLOG_H_INCLUDED
#define EVENTLOG_H_INCLUDED

#define EVENT_LOG_LOCATION "\Data\Event_logs"
#define EVENT_LOG_NAME "STP_Log.txt"

#define MAX_FILE_LINE_LENGTH 4096
#define NORMAL_BUFFER_SIZE 8

class eventLog
{

FileIO logFile;
std::string buffer;




public:

void addNewLog(std::string input)
{
   buffer << input << "\n" ;



};


bool pushBuffer();





};


extern eventLog* eventLogger;




#endif // EVENTLOG_H_INCLUDED
