// ##
// exo6bis.c
// nov. 2014 - jmf
//
// Le seul infini en informatique c'est la betise des programmeurs  
// ##
#include "affiche.h"

int main()
{
    long int i;
    double S;
    double oldS;
    
    oldS =0.0;
    S=2.0;
    i=1;
    while ((S-oldS) > 0.000000001) {
        i++;
        oldS = S;
        if ((i%2)==0) {S += 1.0/i;}
        else {S += 2.0/i;} 
    }
    aff_string("La somme vaut : "); aff_double(S);
    aff_string("Nombre d'itérations : "); aff_long_int(i);
    
    exit (0);
}

