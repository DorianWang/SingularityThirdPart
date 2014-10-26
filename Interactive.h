
#ifndef INTERACTIVE_H
#define INTERACTIVE_H

class basicInteractive
{
public:
   std::string nameShown;
   
   std::string description;
   
   unsigned short tag; //This is what is looked for when the object does something.
   //When it is interacted with, the thing pointed to by the tag is done.
};

class advancedInteractive : public basicInteractive
{
public:

   std::string assocFile;
   unsigned short assocFileNum;
   //The file number gives the location of the file in the main file container.   

};







#endif
