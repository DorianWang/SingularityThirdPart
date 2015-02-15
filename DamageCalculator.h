#ifndef DAMAGECALULATOR_H_INCLUDED
#define DAMAGECALULATOR_H_INCLUDED

#include "DamageTypes.h"
#include <cmath>


#define MAGIC_BREAKPOINT_ZERO 0

#define ARMOUR_CONST_HALF 50.0
#define MAGIC_CONST_HALF 50.0
#define VOID_CONST_HALF 100.0

//TODO:
#define ARMOUR_CONST_THRESHOLD
#define MAGIC_CONST_THRESHOLD
//Void damage has no threshold.

#define ARMOUR_STAB 80
#define ARMOUR_SLASH 100
#define ARMOUR_CRUSH 60
#define ARMOUR_POISON 10
#define ARMOUR_DOT 20


int calculateTotalDamage(damagePacket inputDamage, resistanceTypes* inputResistances)
{
   double tempDamage;
   tempDamage += calculatePhysical(inputDamage.physical, inputResistances);
   tempDamage += calculatePhysical(inputDamage.magical, inputResistances);
   tempDamage += inputDamage.pure * VOID_CONST_HALF/(VOID_CONST_HALF + inputResistances.voidResist);
   return round();
}


double calculatePhysical(physicalDamage inputDamage, resistanceTypes* inputResistances)
{
   double tempResist = ARMOUR_CONST_HALF/(ARMOUR_CONST_HALF + inputResistances.physicalResist);
   double tempOutput;
   tempOutput += inputDamage.crushPower *

}


//The calculation for magic resistance is done by percentage.
double calculateMagical(magicDamage inputDamage, resistanceTypes* inputResistances)
{
   double tempResist = MAGIC_CONST_HALF/(MAGIC_CONST_HALF + inputResistances.magicResist);
   double tempOutput;
}



#endif // DAMAGECALULATOR_H_INCLUDED
















