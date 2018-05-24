/*td2 exo7 clement caumes*/

#include "graphics.h"
int main()
{
	init_graphics(900,600);
	int a;
	int b;
	a=2;
	b=a;
	a=a+2;
	write_int(b);
	
	
	wait_escape();
	exit(0);
}
