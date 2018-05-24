/*td2 exo9 clement caumes*/
#include"graphics.h"
int main()
{
	init_graphics(900,600);
	//parties 1 et 2
	int a, b, c, d;
	a=lire_entier_clavier();
	b=lire_entier_clavier();
	c=a/b;
	d=a%b;
	write_int(c);
	writeln();
	write_int(d);
	writeln();
	//parties 3
	a=b*c+d;
	write_int(a);
	
	
	
	wait_escape();
	exit(0);
}
