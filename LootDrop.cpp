
#define NORMAL_LOOT_CHANCE 80
#define HIGHER_LOOT_CHANCE 18
#define HIGHEST_LOOT_CHANCE 2

#define FILE_LIST_PATH "Data/fileLoadList.txt"

//These limit players, and creatures armour, clothing and other choices.
//These refer to the size vs "average" (human size). A large knife is smaller
//than a normal sword, for example.

//#include "LootDrop.h"

enum itemSize { TINY, SMALL, NORMAL, LARGE, GIGANTIC };

//Humanoid (duh), Serpentine (only snakes), Shapeless (Anyone, think cloaks or magic)
//Exotic (Unique, unable to use)
enum itemShape { HUMANOID, SERPENTINE, SHAPELESS, EXOTIC };

//Shield does crushing damage,
enum itemType { EDGE_WEAPON, CRUSH_WEAPON, STAB_WEAPON, SPECIAL_WEAPON, SHIELD,
RANGED_BOW, RANGED_DART, RANGED_LARGE_PROJECTILE, RANGED_EXOTIC, //Ranged weapon with strange uses
MAGIC_TOOL, HEALING, MAGIC_HEAL, RESTORE_HEAL, ARMOUR_CLOTHES, ARMOUR_SPECIAL,
ARMOUR_MAGIC, ARMOUR_ROBES, ARMOUR_LEATHER,ARMOUR_METAL_CHAIN,
ARMOUR_METAL_SOLID, ARMOUR_LIVING, QUEST, LOOT, CRAFTING};


enum itemEnchants { ELEMENT_ICE, ELEMENT_FIRE, ELEMENT_LIGHTNING, ELEMENT_LIGHT,
ELEMENT_DARK, ELEMENT_LIFE, ELEMENT_NECRO, ELEMENT_WATER, ELEMENT_AIR, ELEMENT_ARCANE,
ELEMENT_POISON, ELEMENT_MIND , ELEMENT_TECH, ELEMENT_MUNDANE };//The last three aren't really enchants, but...




//FIX

//Should be moved to some sort of preloading object...
//int getItems()
//{
//   FileIO fileListIn; FileIO fileObjectIn;
//   fileIn.textOpenFile(FILE_LIST_PATH, false);
//   std::string tempFileName; int errorNum = 0;
//
//   while(true){
//      errorNum = fileListIn.readLine(&tempFileName)
//      if (errorNum <= 0){
//         break;
//      }
//      fileObjectIn.textOpenFile(FILE_LIST_PATH, false);//Do I want text or data?
//      //parseFile(&fileObjectIn);
//      fileObjectIn.closeFile();
//   }
//
//
//
//fileListIn.closeFile();
//}



//Items can be

//sentinal, Name, sentinal
//Item dataStorage -> Main type, (second type, third type, fourth, etc...)*optional*
//Ohter subgroups, from most to least important
//Other stuff


//Item hierarchy
/*
All Items (Root)
Equipment
   Weapons (mostly physical)
      Edge
         Sword (slash), knife (slash), axe, ;
      Crushing
         Hammer, bat, mace, axe (partial), ;
      Stabbing
         Pickaxe, knife (stab), spear, sword (stab), ;
      Special
         Gauntlet (crushing, may have stabbing), ;
   Magic Weapons (wands, staffs, etc.)
      Magic tools
         Wand, staff, magic glove, magic crystal, ;
         Small (mana) capacitor, Large (mana) capacitor, Arcane (mana) capacitor;
      Magic enhancers
         Ward, thaumometer (temp name), ;
      Spell wands - Multiuse devices that allow anyone to cast a spell (damage dependant on skill and wand quality)
            (weak, - , empowered, masterwork) Freeze, Flare, Shock, Blind, Prism, Confuse, Weaken, ;
      Spell staff - Multiuse devices that allow anyone to cast a spell (damage dependant on skill and staff quality)
      They store mana as well, require the user to equip them, and boost magic damage, but less than regular ones.
         (weak, - , flawless, masterwork) Every wand spell, upgraded (Flare becomes Flame, shock becomes Electrocute)
         In addition, staffs have 2 spells, Green grove and Hellfire (First one is special, second deals damage)
   Shields
      Wood, metal (Weapon metals), ;
   Ranged
      Bow
         Long
            Wood, metal (Weapon materials), ;
         Short
            Wood, metal (Weapon materials), ;
         Cross
            Wood, metal (Weapon materials), ;
         Arrow (ammo)
            Arrow (shaft (wood, metal), head (metal, bone, flint)) ;
            Bolt (wood, metal) ;
      Dart
         Dartgun
            Metal (Weapon materials), "tech (requires tech skill)", ;
         Blowgun
            wood, bone, metal (weapon materials), ;
      Gun
         Metal (Weapon materials), requires tech;
Consumables
   Healing
      Potion
         Weak, Moderate, Strong, Arcane
      Bandage (or other regular healing items);
         Small, Regular, Large
      Healing powder and other items
         Food, healing powder, healing salve, syrettes;
   Mana/magic restores
      Potion
         Weak, Moderate, Strong, Arcane;
      Magic storage
         Elemental crystal cluster (frozen flames, vitrified dew, essence of wind, twisted shadows, shards of light, ;),
         Empowered elemental crystal cluster (everything, plus heart of the magi [boosts all elements slightly])
         Crystaline mana, Arcane mana crystal cluster;
   Utility
      Explosives
         Smokebomb/teargas/flash/other things
            (effective, -) (smokebomb, teargas, flash), ;
         Grenade
            Fragmentation, high explosive, Thaumic, ;
         Flare (lights up target/area, increases accuracy)
            (Dim, - , Bright) (Flare), (- , Bright)(Magnesium flare [does damage])
         Tools
            (non-tech [tech<2])
            (tech [tech>=2])
Loot



Money
   Gold, Silver coins - () Most civilizations accept

   Paper currency - () civilization must be beyond tech 4, only useful in
   economically linked countries not at war.
      asdf





Items and equipment sometimes have a technology value, an intelligence value, a strength value, and/or a skill value.
-Technology controls what is required to make it, and who can
-Intelligence controls use of some easy tech. For example, if self tech value<1, then an
 intelligence greater than 2 is required for bows.
-Strength is required for some weapons. Most weapons have a default level of 3 strength or higher to use.
 Items such as hammers may take more, and something like a taser may take none.
-Skill values are required to deal complete or even some damage. (Gun skill required to hit targets often.

Metals in West Atwerca:
   Weapon materials: Copper, Bronze, Iron, Steel (low and high), traelmin ;
   Craft materials: Copper, Lead, Tin, Brass, Silver, Electrum (used for some spells, purity), Gold ;
   Other "metals" that may be used: thaumium (iron + magic, stronger than low steel),
   adamantium (very light, strong metal, very valuable), ;
Other materials used:
   Weapon materials: wood, stone, bone, flint, ;
   Craft materials: wood, stone, bone, glass, clay,




Major terrain
   Mountains

   Hills

   River

   Plain

   etc.



Local conditions
   Dirt

   Stone

   Grass

   Slope

   Cliff

   Water
      shallow, deep, ocean (slow, fast, torrential)
   etc.




*/




















