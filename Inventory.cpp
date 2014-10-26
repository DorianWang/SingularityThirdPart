#include "ItemDeclaration.h"




inventory::inventory()
{
   carryingCapacityWeight = 0;
   carryingCapacitySize = 0;

   overloadedCheck = false;

   currentlySortedAs = 0;//Unsorted

   currentStorageWeight = 0;
   currentStorageSpace = 0;
}

inventory::~inventory()
{
   for (int i = 0; i < equipment.size(); i++){
      delete (equipment[i]);
   }
   equipment.clear();
   currentlyEquiped.clear();
   consumables.clear();
   shinyThings.clear();
   keyItems.clear();
}



/*

void inventory::sortInventory(char sortType)
{
   bool resorting = false;
   if (currentlySortedAs == sortType && numberChangesSinceLastSort <= MAX_CHANGES_INSERT_SORT){
      resorting = true;
   }
   currentlySortedAs = sortType;


   if (sortType == SORT_BY_ALPHABET){
      if (resorting){//Bubble sort, for the best case of n operations!

      }
      for (int i = 0; i < equipment.size(); i++){

      }
   }

   if (sortType == SORT_BY_SIZE){

   }

   if (sortType == SORT_BY_WEIGHT){

   }

}

*/


int inventory::isOverloaded()
{
   int halfWeightCap = carryingCapacityWeight/2; int halfSizeCap = carryingCapacitySize/2;

   overloadedCheck = true;

   if ((currentStorageWeight - 1 > carryingCapacityWeight * 2)
   ||(currentStorageSpace - 1 > carryingCapacitySize * 2)){
      return 3;//Completely overloaded
   }

   if ((currentStorageWeight - 1 > carryingCapacityWeight + halfWeightCap)
   ||(currentStorageSpace - 1 > carryingCapacitySize + halfSizeCap)){
      return 2;//Overloaded
   }

   if ((currentStorageWeight - 1 > carryingCapacityWeight)
   ||(currentStorageSpace - 1 > carryingCapacitySize)){
      return 1;//Slightly overloaded
   }


return 0;//Not overloaded
}
















