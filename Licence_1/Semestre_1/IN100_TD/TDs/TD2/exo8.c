/*td2 exo8 clement caumes*/
#include"graphics.h"
int main()
{
	init_graphics(900,600);
	int a, b;
	a=(10/3)*3;
	b=(10*3)/3;
	write_int(a);
	writeln();
	write_int(b);
	
	
	wait_escape();
	return(0);
}
