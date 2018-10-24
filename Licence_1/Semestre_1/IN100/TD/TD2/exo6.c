/*TD2 exercice 6 clement caumes*/
#include "graphics.h"
int main()
{
	init_graphics(900,600);
	int a,b,c;
	a=lire_entier_clavier();
	b=lire_entier_clavier();
	c=(a+b)/2;
	write_int(c);
	
	wait_escape();
	exit(0);
}


