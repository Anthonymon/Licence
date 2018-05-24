// ##
// exo8.c
// nov. 2014 - jmf
//
// Ils sont tous egaux mais les loups sont plus egaux que les autres
// ##
#include "affiche.h"

int fact(int j)
{
    int k,f ;
    f =1;
    for (k=1;k<=j;k++) {f*=k;}
    return(f);
}

int main()
{
    int i;
    
    i = fact(10)/(fact(2)*fact(8));
    aff_int(i);  

    i = fact(30)/(fact(20)*fact(10));
    aff_int(i);  

    i = fact(50)/(fact(20)*fact(30));
    aff_int(i);  

	exit (0);
}


