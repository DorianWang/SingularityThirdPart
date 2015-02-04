
#ifndef LIBRARYINCLUDER_H_INCLUDED
#define LIBRARYINCLUDER_H_INCLUDED

//Inline ALL the things!
//http://stackoverflow.com/questions/212006/multiple-definition-error-including-c-header-file-with-inline-code-from-multip
//http://stackoverflow.com/questions/14909997/why-arent-my-include-guards-preventing-recursive-inclusion-and-multiple-symbol


//#include "libraryIncluder.h"
/*
#define INCLUDE_FILE_IO

#define INCLUDE_BINARY_TREE

#define INCLUDE_ITEM_TREE

#define INCLUDE_KEY_IO

#define INCLUDE_LINKED_LIST

#define INCLUDE_CONSOLE_OPTIONS

#define INCLUDE_UTILITIES
*/
//#include "_libraryController.h"

#include "Libraries\Binary tree\BinaryTree.h"

#ifndef FILEIO_H_INCLUDED
   #define FILEIO_H_INCLUDED
   #include "Libraries\FileIO\FileIO.h"
#endif

#include "Libraries\itemTree\treeType.h"

#include "Libraries\KeyIO\keys.h"

#include "Libraries\Linked list\Container.h"

#include "Libraries\usefulHeaders file\functionChecker.h"

#include "Libraries\usefulHeaders file\UsefulHeaders.h"

//{
//enum class textColour
//{BLACK, DARK_BLUE, GREEN_BLUE, BLUE_GREEN, DARK_RED, PURPLE, GOLD,
//SILVER, GREY, BLUE, BRIGHT_GREEN, CYAN, RED, PINK, YELLOW, WHITE};
/*
'l':textColour::BLACK;
'b':textColour::DARK_BLUE;
'g':textColour::GREEN_BLUE;
'u':textColour::BLUE_GREEN;
'r':textColour::DARK_RED;
'p':textColour::PURPLE;
'o':textColour::GOLD;
's':textColour::SILVER;
'a':textColour::GREY;
'B':textColour::BLUE;
'G':textColour::BRIGHT_GREEN;
'c':textColour::CYAN;
'R':textColour::RED;
'P':textColour::PINK;
'y':textColour::YELLOW;
'w':textColour::WHITE;
default:textColour::WHITE;
*/

//}
//}


#include "Libraries\Windows console stuff\ConsoleOptions.h"




#endif // LIBRARYINCLUDER_H_INCLUDED









