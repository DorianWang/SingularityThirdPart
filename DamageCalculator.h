#ifndef DAMAGECALULATOR_H_INCLUDED
#define DAMAGECALULATOR_H_INCLUDED

#include "DamageTypes.h"
#include <cmath>


#define MAGIC_BREAKPOINT_ZERO 0

#define ARMOUR_CONST_HALF 100.0
#define MAGIC_CONST_HALF 100.0
#define VOID_CONST_HALF 200.0

//TODO:
#define ARMOUR_CONST_THRESHOLD
#define MAGIC_CONST_THRESHOLD
//Void damage has no threshold.

#define ARMOUR_MAX_PERCENT_RESIST 100.0

#define ARMOUR_STAB 80
#define ARMOUR_SLASH 100
#define ARMOUR_CRUSH 60
#define ARMOUR_POISON 10
#define ARMOUR_DOT 20

#define MAGIC_ARCANE_RESIST 100


int calculateTotalDamage(damagePacket inputDamage, resistanceTypes* inputResistances)
{
   double tempDamage;
   tempDamage += calculatePhysical(inputDamage.physical, inputResistances);
   tempDamage += calculatePhysical(inputDamage.magical, inputResistances);
   tempDamage += inputDamage.pure * VOID_CONST_HALF/(VOID_CONST_HALF + inputResistances.voidResist);
   return round();
}

//By using defined constants, the compiler should replace them with constant values (100.0/100.0 with 1.0).
double calculatePhysical(physicalDamage inputDamage, resistanceTypes* inputResistances)
{
   double tempResist = ARMOUR_CONST_HALF/(ARMOUR_CONST_HALF + inputResistances.physicalResist);
   double tempOutput = 0.000000;

   //Crushing damage.
   tempOutput += inputDamage.crushPower * (ARMOUR_CRUSH / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances.crushResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Slashing damage.
   tempOutput += inputDamage.slashPower * (ARMOUR_SLASH / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances.slashResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Stabbing power.
   tempOutput += inputDamage.stabPower * (ARMOUR_STAB / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances.stabResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Poison power. Poison tends to be rare, so it checks first.
   if (inputDamage.poisonPower != 0){
      tempOuput += inputDamage.poisonPower * (ARMOUR_POISON / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances.poisonResist/ARMOUR_MAX_PERCENT_RESIST) ;
   }

   //Other DOT power. Damage over time effects tend to be rare, so it checks first.
   if (inputDamage.DOTPower != 0){
      tempOuput += inputDamage.DOTPower * (ARMOUR_POISON / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances.otherDOTResist/ARMOUR_MAX_PERCENT_RESIST) ;
   }

   //Returns the total, modified by the base armour.
   return tempResist * tempOutput;
}


//The calculation for magic resistance is done by percentage.
//TODO:
double calculateMagical(magicDamage inputDamage, resistanceTypes* inputResistances)
{
   double tempResist = MAGIC_CONST_HALF/(MAGIC_CONST_HALF + inputResistances.magicResist);
   double tempOutput = 0.000000000;

   //Crushing damage.
   tempOutput += inputDamage.arcanePower * (ARMOUR_CRUSH / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances.crushResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Slashing damage.
   tempOutput += inputDamage.slashPower * (ARMOUR_SLASH / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances.slashResist/ARMOUR_MAX_PERCENT_RESIST) ;


   //Returns the total, modified by the base armour.
   return tempResist * tempOutput;

}



#endif // DAMAGECALULATOR_H_INCLUDED
















