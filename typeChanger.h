
#ifndef TYPE_CHANGER_H
#define TYPE_CHANGER_H 

//Constants, to increase speed, or at least I hope...
//2 to the power of...
#define TWO_THIRTY_TWO 4294967296LL//32
#define TWO_THIRTY_ONE 2147483648LL//31
#define TWO_SIXTEEN 65536//16
#define TWO_FIFTEEN 32768//15
#define TWO_EIGHT 256//8
#define TWO_SEVEN 128//7

int cToI(char* buffer);
unsigned int cToUI(char* buffer);

short cToS(char* buffer);
unsigned short cToUS(char* buffer);

int cIToI(char* buffer, int* output);




#endif


/*

system example : DIR 
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int i;
	printf ("Checking if processor is available...");
	if (system(NULL)) puts ("Ok");
	else exit (1);
	printf ("Executing Calc...\n");
	i = system ("c:/windows/system32/calc.exe");                                               
	printf ("The value returned was: %d.\n",i);

	getchar();
	return 0;
}




*/
