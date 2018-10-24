#include "graphics.h"
#include <graphicC.pdf>

int main(){
	init_graphics(900,600);
	POINT p=wait_clic();
	affiche_image("graphicC",p,600,456);
	wait_escape();
	exit(0);
}
