/*td2 exo11 clement caumes*/
#include"graphics.h"
int main()
{
	init_graphics(900,600);
	
	int a, b, c;
	a=lire_entier_clavier();
	b=lire_entier_clavier();
	c=lire_entier_clavier();
	int resultat1, resultat2, resultat3;
	resultat1=a/b/c;
	write_int(resultat1);
	writeln();
	resultat2=(a/b)/c;
	write_int(resultat2);
	writeln();
	resultat3=a/(b/c);
	write_int(resultat3);
	writeln();
	

	
	wait_escape();
	exit(0);
}
