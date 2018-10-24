// ##
// exo5.c
// nov. 2014 - jmf
// ##
#include "affiche.h"

int main()
{
    int i;
    int min;

    // On déclare un tableau de 10 entiers et on initialise les valeurs en même temps.
    int t[10] = {1 ,2, 4, 10, -3, 6, 1, 2, 9, 12};
    
    min = t[0];
         
    for(i = 0; i < 10; i++) 
    {
        if (t[i] < min) { min = t[i];}
    }
    aff_int(min); // Afficher la valeur de la variable min
    
    exit(0);
}


