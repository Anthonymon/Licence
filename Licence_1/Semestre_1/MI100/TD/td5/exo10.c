// ##
// exo9.c
// nov. 2014 - jmf
//
// ##
#include "affiche.h"

int main()
{
	int t1[10];
	int t2[10];
    int i;
    
    for(i=0; i <= 10; i++) 
    {
		t2[i] = 12;
	}
    for(i=0; i <= 16; i++) 
    {
		t1[i] = 47;
	}

    aff_string_nl("Tableau t1:");
    for(i=0; i < 10; i++) 
    {
		aff_tab_int(t1,i);
	}
    aff_string_nl("Tableau t2:");
    for(i=0; i < 10; i++) 
    {
		aff_tab_int(t2,i);
	}

    exit(0);
}


