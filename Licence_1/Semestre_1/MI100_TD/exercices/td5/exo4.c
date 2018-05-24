// ##
// exo4.c
// nov. 2014 - jmf
// ##
#include "affiche.h"

int main()
{
    
    float x,y,l,k,i,j;
    
    i = 3;
    j = 2;
    x = 2;
        
    k = i/j; //1.5
    l = x/i; //0.66
    y = i/j; //1.5
   
	aff_float(k);		// Affiche la valeur de k
	aff_float(l);		// Affiche la valeur de l
	aff_float(y);	// Affiche la valeur de y

    exit (0);
}


