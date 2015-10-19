#ifndef DAMAGECALULATOR_H_INCLUDED
#define DAMAGECALULATOR_H_INCLUDED

#include "DamageTypes.h"
#include <cmath>
#include <algorithm>

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


//Guidelines for armour stats.
/*
#define ARMOUR_STAB_MODIFIER 0.80
#define ARMOUR_SLASH_MODIFIER 1.00
#define ARMOUR_CRUSH_MODIFIER 0.60
#define ARMOUR_POISON_MODIFIER 0.05
#define ARMOUR_DOT_MODIFIER 0.10
*/

#define MAGIC_ARCANE_RESIST 1.00
#define MAGIC_ELEMENTAL_RESIST 0.80

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
   tempOutput += std::max(inputDamage.crushPower * (1 - inputResistances -> crushResist/ARMOUR_MAX_PERCENT_RESIST)
                     - inputResistances -> crushResist * ARMOUR_CONST_THRESHOLD,
                     0.000000 //Does not add a negative number to tempOutput.
                     ) ;

   //Slashing damage.
   tempOutput += std::max(inputDamage.slashPower * (1 - inputResistances -> slashResist/ARMOUR_MAX_PERCENT_RESIST)
                     - inputResistances -> slashResist * ARMOUR_CONST_THRESHOLD,
                     0.000000 //Does not add a negative number to tempOutput.
                     ) ;

   //Stabbing power.
   tempOutput += std::max(inputDamage.stabPower * (1 - inputResistances -> stabResist/ARMOUR_MAX_PERCENT_RESIST)
                     - inputResistances -> stabResist * ARMOUR_CONST_THRESHOLD,
                     0.000000 //Does not add a negative number to tempOutput.
                     ) ;

   //Poison power. Poison tends to be rare, so it checks first.
   if (inputDamage.poisonPower != 0){
//      tempOutput += inputDamage.poisonPower * (1 - (inputResistances -> poisonResist * ARMOUR_POISON_MODIFIER)/ARMOUR_MAX_PERCENT_RESIST) ;
      tempOutput += std::max(inputDamage.poisonPower * (1 - inputResistances -> poisonResist/ARMOUR_MAX_PERCENT_RESIST)
                     - inputResistances -> poisonResist * ARMOUR_CONST_THRESHOLD,
                     0.000000 //Does not add a negative number to tempOutput.
                     ) ;
   }

   //Other DOT power. Damage over time effects tend to be rare, so it checks first.
   if (inputDamage.DOTPower != 0){
  //    tempOutput += inputDamage.DOTPower * (ARMOUR_DOT_MODIFIER / ARMOUR_MAX_PERCENT_RESIST) * (1 - inputResistances -> otherDOTResist/ARMOUR_MAX_PERCENT_RESIST) ;
         tempOutput += std::max(inputDamage.DOTPower * (1 - inputResistances -> otherDOTResist/ARMOUR_MAX_PERCENT_RESIST)
                     - inputResistances -> otherDOTResist * ARMOUR_CONST_THRESHOLD,
                     0.000000 //Does not add a negative number to tempOutput.
                     ) ;
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































