#ifndef ITEMDECLARATION_H
#define ITEMDECLARATION_H





//User defined folding points
//This one contains header files
//{
#include "iostream"
#include "string"
#include "vector"
//}

// #define
//{
#define SORT_BY_ALPHABET 'a'
#define SORT_BY_SIZE 's'
#define SORT_BY_WEIGHT 'w'
#define SORT_BY_VALUE 'v'
#define SORT_BY_UNIQUE 'u'

#define MAX_CHANGES_INSERT_SORT 4
#define MAX_ITEMS_INSERT_SORT 8
//}

enum usesItem {
WP_ONE_HAND, WP_TWO_HAND, AR_CHEST, AR_HEAD, AR_ARM, AR_LEG, AR_FOOT, AR_NECK,
AR_HAND,
//Jewelry. These are in their own slot, unless they also have an armour/weapon slot.
JWL_NECK, JWL_WRIST, JWL_EAR, JWL_HAND, JWL_HEAD, JWL_CHEST, JWL_LEG, JWL_FOOT,

//Tool items. They do things, and limit actions. CARRY is for bags, and CONTAINER is for liquid containers
TOOL_BLADE, TOOL_STAB, TOOL_CARRY, TOOL_CONTAINER,

//TODO

};


enum usesConsume {

//Restoratives
POTION_HEAL, BANDAGE, OTHER_MEDICAL, POTION_MANA, ELEMENT_CLUSTER, POWER_ELEMENT_CLUSTER, CRYSTAL_MANA,

//Used to cause damage, blind the enemy, etc.
EXPLODE_DISABLE, EXPLODE_DAMAGE, EXPLODE_FLARE,

//These all have special effects.
TRANSFORM_MAGIC, TRANSFORM_TECH,

//Not yet used.
FOOD

};


struct descriptorEffects
{
   std::string descriptorName;
   int lowLvlLmt;
   int highLvlLmt;
   short damageEffectChange;
   float damageEffectMod;

   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;

   int valueIncrease;
   float valueMod;
};





class itemBaseType
{
   public:
   std::string singularName;
   std::string pluralName;
   std::string descriptor;

//https://www.youtube.com/watch?v=Dgvz5FLSNcg&feature=youtu.be&t=9h18m50s

   short size;
   short weight;

   int value;

   bool isUnique; //Tells the game to look at this differently
   std::string uniqueEffectsKey;
};




class equipmentTypeBase : itemBaseType
{
   std::vector <descriptorEffects> descriptor;


   int baseDamage; //Note that damage can be negative...
   float damageIncrItemLvl;
   float damageIncrUserLvl;
   unsigned char assocSkill;
   short enchantType; //Mostly for staffs, but also for some other things

   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;
   std::vector <unsigned char> materials;

};

class consumeTypeBase : itemBaseType
{
//https://www.youtube.com/watch?v=Dgvz5FLSNcg&feature=youtu.be&t=9h18m50s

   int effectStrength;
   float effectIncrItemLvl;
   float effectIncrUserLvl;//For healing items, etc.
   unsigned char assocSkill;

   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <usesConsume> uses;

};




class equipmentType : itemBaseType
{

   int baseDamage; //Note that damage can be negative...
   float damageIncrItemLvl;
   float damageIncrUserLvl;
   unsigned char assocSkill;
   short enchantType; //Mostly for staffs, but also for some other things

   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;
   std::vector <unsigned char> materials;

   int itemLevel;


   equipmentTypeBase* itemBase;

};

class consumeType : itemBaseType //https://www.youtube.com/watch?v=Dgvz5FLSNcg&feature=youtu.be&t=9h18m50s
{

   int effectStrength;
   float effectIncrItemLvl;
   float effectIncrUserLvl;//For healing items, etc.
   unsigned char assocSkill;

   int itemLevel;

   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;

   bool isUnique; //Tells the game to look at this differently
   std::string pathToUniqueEffects;

   equipmentTypeBase* consumeTypeBase;

};

class junkType : itemBaseType
{

   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses;

};

class keyItemType : itemBaseType
{
   std::string primaryItemType;
   std::string secondaryItemTypes;
   std::vector <unsigned char> uses; //https://www.youtube.com/watch?v=Dgvz5FLSNcg&feature=youtu.be&t=9h18m50s

   unsigned short tag;
};



class inventory
{
public:

   bool overloadedCheck;

   int carryingCapacityWeight;
   int carryingCapacitySize;

   char currentlySortedAs;
   long long numberChangesSinceLastSort;

   inventory();
   ~inventory();

   int showInventory();//The return will be changed later...

   bool addItem(int itemType, ...); //Change int into an enum?
   bool removeItem(int itemType, std::string itemName);

   int isOverloaded();//Returns 0 for no, 1 for slightly, 2 for quite a bit, and 3 for crushing weight (basically can't move).

   int changeCarryWeight();
   int changeCarrySize();
   int testItem(int weight, int size);//This will return the overloaded int if the item used is added.

   int sortInventory (const char sortType);
   void reverseInventory();

private:

   int currentStorageWeight;
   int currentStorageSpace;

   std::vector <equipmentType*> equipment;

   std::vector <equipmentType*> currentlyEquiped;

   std::vector <consumeType*> consumables;

   std::vector <junkType*> shinyThings;

   std::vector <keyItemType*> keyItems;

   //Sorting functions >>>
   int sortByBaseName(itemBaseType one, itemBaseType two);
   int sortByBaseSize(itemBaseType one, itemBaseType two);
   int sortByBaseWeight(itemBaseType one, itemBaseType two);
   int sortByBaseValue(itemBaseType one, itemBaseType two);
   // <<<

};





#endif // ITEMDECLARATION_H
