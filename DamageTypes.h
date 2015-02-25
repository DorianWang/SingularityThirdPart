
#ifndef DAMAGE_TYPES_H
#define DAMAGE_TYPES_H


struct resistanceTypes
{
   short magicResist;
   short physicalResist;
   short voidResist;
   short otherResist;

   //Specific resistance types

   //Magic resistances
   short arcaneResist;
   short elementalMagicResist;

   //Physical resistances
   short stabResist;
   short slashResist;
   short crushResist;
   short poisonResist;
   short otherDOTResist;//Burning, freezing, etc.

};

struct magicDamage
{
   int arcanePower;
   int elementalPower;
};

struct physicalDamage
{
   int stabPower;
   int slashPower;
   int crushPower;
   int poisonPower;
   int DOTPower;
};

struct damagePacket
{
   physicalDamage physical;
   magicDamage magical;
   int pure;
};






#endif



















































