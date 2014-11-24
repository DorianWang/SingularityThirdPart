#include "ScreenController.h"



instructDataOut ScreenControl::popFirstUnsetInstructPointer()
{
   instructDataOut tempData;
   tempData = UnsetPointerList.front();
   UnsetPointerList.pop_front();
   return tempData;
}
