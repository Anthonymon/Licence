// ## 
// exo1.c
// nov. 2014 - jmf
// ##
#include "affiche.h"

int main()
{
    int i;
    int sum;
    int prod;
    sum=0;
    prod=1;
    
    for(i=0; i<10; i++) 
    {
        sum = sum + i;
    }
    aff_int(sum); // Permet d'afficher la valeur de la variable sum
    
    for(i=1; i<10; i++) 
    {
        prod = prod * i;
    }
    aff_int(prod); // Permet d'afficher la valeur de la variable prod
    
    exit(0);
}
