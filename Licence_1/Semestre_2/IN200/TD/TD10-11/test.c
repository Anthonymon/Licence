#include "graphics.h"

int main(){
	init_graphics(900,600);
	wait_clic();
	POINT p;
	while(1){
	p=get_arrow();
	write_int(p.x);
	write_int(p.y);
	attendre(10);
	fill_screen(black);
	//attendre(10);
}
	wait_escape();
	exit(0);
}
