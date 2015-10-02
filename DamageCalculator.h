#ifndef DAMAGECALULATOR_H_INCLUDED
#define DAMAGECALULATOR_H_INCLUDED

#include "DamageTypes.h"
#include <cmath>

#include "UsefulHeaders.h"


#define MAGIC_BREAKPOINT_ZERO 0

#define ARMOUR_CONST_HALF 100.0
#define MAGIC_CONST_HALF 100.0
#define VOID_CONST_HALF 200.0

//TODO:
//These are a ratio of the armour or magic resistance which directly reduces damage.
#define ARMOUR_CONST_THRESHOLD 0.12500 // 1/8
#define MAGIC_CONST_THRESHOLD 0.12500 // 1/8
//Void damage has no threshold.

#define ARMOUR_MAX_PERCENT_RESIST 100.00

#define ARMOUR_STAB 80
#define ARMOUR_SLASH 100
#define ARMOUR_CRUSH 60
#define ARMOUR_POISON 10
#define ARMOUR_DOT 20

#define MAGIC_ARCANE_RESIST 100
#define MAGIC_ELEMENTAL_RESIST 80

namespace attackScaling
{


class defenceCalculator{


//Defence calculations
//{





//double calculatePhysical(physicalDamage inputDamage, resistanceTypes* inputResistances);
//double calculateMagical(magicDamage inputDamage, resistanceTypes* inputResistances);

//By using defined constants, the compiler should replace them with constant values (100.0/100.0 with 1.0). Constant folding!
double calculatePhysical(physicalDamage inputDamage, resistanceTypes* inputResistances)
{
   double tempResist = ARMOUR_CONST_HALF/(ARMOUR_CONST_HALF + inputResistances -> physicalResist);
   double tempOutput = 0.000000;

   //Crushing damage.
   tempOutput += inputDamage.crushPower * (ARMOUR_CRUSH / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances -> crushResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Slashing damage.
   tempOutput += inputDamage.slashPower * (ARMOUR_SLASH / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances -> slashResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Stabbing power.
   tempOutput += inputDamage.stabPower * (ARMOUR_STAB / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances -> stabResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Poison power. Poison tends to be rare, so it checks first.
   if (inputDamage.poisonPower != 0){
      tempOutput += inputDamage.poisonPower * (ARMOUR_POISON / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances -> poisonResist/ARMOUR_MAX_PERCENT_RESIST) ;
   }

   //Other DOT power. Damage over time effects tend to be rare, so it checks first.
   if (inputDamage.DOTPower != 0){
      tempOutput += inputDamage.DOTPower * (ARMOUR_POISON / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances -> otherDOTResist/ARMOUR_MAX_PERCENT_RESIST) ;
   }

   //Returns the total, modified by the base armour.
   tempOutput = tempResist * tempOutput;

   if (tempOutput > ARMOUR_CONST_THRESHOLD * inputResistances -> physicalResist){
      return tempOutput - ARMOUR_CONST_THRESHOLD * inputResistances -> physicalResist;
   }
   return 0.00000000;

}


//The calculation for magic resistance is done by percentage.
//TODO:
double calculateMagical(magicDamage inputDamage, resistanceTypes* inputResistances)
{
   double tempResist = MAGIC_CONST_HALF/(MAGIC_CONST_HALF + inputResistances -> magicResist);
   double tempOutput = 0.000000;

   //Arcane damage.
   tempOutput += inputDamage.arcanePower * (MAGIC_ARCANE_RESIST / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances -> arcaneResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Elemental damage.
   tempOutput += inputDamage.elementalPower * (MAGIC_ELEMENTAL_RESIST / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances -> elementalMagicResist/ARMOUR_MAX_PERCENT_RESIST) ;

   //Returns the total, modified by the base resistance.
   if (tempOutput > MAGIC_CONST_THRESHOLD * inputResistances -> magicResist){
      return tempOutput - MAGIC_CONST_THRESHOLD * inputResistances -> magicResist;
   }
   return 0.00000000;
}



int calculateTotalDamage(damagePacket inputDamage, resistanceTypes* inputResistances)
{
   double tempDamage;
   tempDamage += calculatePhysical(inputDamage.physical, inputResistances);
   tempDamage += calculateMagical(inputDamage.magical, inputResistances);
   tempDamage += inputDamage.pure * VOID_CONST_HALF/(VOID_CONST_HALF + inputResistances -> voidResist);
   return round(tempDamage);
}




//}


};





//Attack calculations
//{


struct statScaling
{
   int statNum; double scaling;
};

struct attackScaling
{
   std::vector <statScaling> Scalings;
   /*
   std::vector <statScaling> arcaneScaling;
   std::vector <statScaling> elementalScaling;

   std::vector <statScaling> stabScaling;
   std::vector <statScaling> slashScaling;
   std::vector <statScaling> crushScaling;
   std::vector <statScaling> poisonScaling;
   std::vector <statScaling> DOTScaling;

   std::vector <statScaling> voidScaling;
   */
};

struct attackType
{
   std::string name;
   attackScaling scaling;
   //Add a costType later.
   //costType cost;
   //damagePacket baseDamage;
};



//}

}






#endif // DAMAGECALULATOR_H_INCLUDED































