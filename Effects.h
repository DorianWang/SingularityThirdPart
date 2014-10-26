
#ifndef EFFECTS_GAME_H
#define EFFECTS_GAME_H


enum allEffects
{
   MOD_HP, MOD_MP, MOD_UN_ONE, MOD_UN_TWO, MOD_INT, MOD_WIS, MOD_CHA, MOD_STR,
   MOD_AGL, MOD_END, MOD_UN_THREE, MOD_UN_FOUR, MOD_MGC_KNL, MOD_TCH_KNL,
   MOD_BASE_MGC_RST, MOD_BASE_PHYS_RST,


   SPAWN_ENTITY,

   KILL_ENTITY//,
};

struct baseEffects
{
   allEffects effect;
};

struct advancedEffects
{
   baseEffects* primaryEffect;
   int effectStrength;
   int effectType;
   int descriptionIndex;
   bool effectTypeDependant;
};
//Effects that modify stats use effectType for a timer. -1 for permanant, 0 for
//until next heal, and otherwise the time in ticks until it goes away.
//timing dependant effects use their effectType as well as description.





#endif
