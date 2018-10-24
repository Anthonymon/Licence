// ## 
// exo 2
// nov. 2014 - jmf
// ##
#include "affiche.h"

int main()
{
    int i;
    int sum;
    
    
    sum=0;
    
    if (sum==1) aff_string_nl("Attention");

    
    for(i=0; i<10; i++) 
    {
        sum = sum + i;
    }
    aff_int(sum);
    
    exit(0);
}
