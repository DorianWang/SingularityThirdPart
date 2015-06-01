
#include "StatReader.h"







statReader::statReader()
{
   statFile.textOpenFile(SKILL_FILE_LOCATION + FILE_LEARNED_SKILLS, false);
}
