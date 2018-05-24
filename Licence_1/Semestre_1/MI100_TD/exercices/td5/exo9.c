// ##
// exo9.c
// nov. 2014 - jmf
//
// En math l'addition sur R, c'est associatif et commutatif. 
// En C, il faut voir.
// ##
#include "affiche.h"

int main()
{
    double x,y,z, w1, w2;
    
    x = 1.0;
    y = -1.0;
    z = 1.0e-20;
    w1 = (x+z);
    w1 = w1 + y;
    w1 = 1/w1;
    
    w2 = (x+y);
    w2 = w2 + z;
    w2 = 1/w2;
    

	aff_double(w1);
	aff_double(w2);

	exit(0);
}


