
#include "Items.h"


/*
How do I plan to make the item files?

Things in () are comments and don't actaully exist in the file.

Nom:
Sword swords (singular, plural)

BSC: 
400 4 +6 0.2 0.1
(size, weight, base damage, damage increase per item level, 
damage increase per user [skill] level)

(primary item trait)
PRI:
equipment.weapon.edge.sword

(any secondary item traits)
SEC:
equipment.weapon.stab.sword
(There can be more...)


(Special things the item can do)

USE:
Weapon 3 (It is a weapon, with a threat rating of 3)
Slash/Edge(Which one?)
Stab
Lever
CanEnchant 4(Shorten to Enchant or even ECT, power of enchants)
(etc.)

(Materials it can be made from)

MAT: (The colon marks a new thing, and all tags are 3 characters)

ARWM (All regular weapon materials)
Silver +14
Iron +2 (override)

Types:

(Descriptor, low level bound, high level bound, affect of descriptor, 
Damage multiplier)

Broken 1 4 -2 *1
Flawed 2 8 -1 *1
- 3 12 0 (- means no descriptor) *1
Good 5 18 *1
(etc)


*/

//The master item file list lists every item file which must be included in the game.
//This function will load all the items into memory.
int itemParser(std::string pathToMasterItemFileList)
{
   FileIO inputFileNameList;
   inputFileNameList.textOpenFile(pathToMasterItemFileList, false);
   bool fileIsGood = true; int returnInt = 0; std::string inputLine;
   
   //Item file reading
   while(fileIsGood){
      returnInt = inputFileNameList.readLine(&inputLine);
      if (returnInt<1){ return 0; }
   }
   FileIO inputFile;
   
   
}























