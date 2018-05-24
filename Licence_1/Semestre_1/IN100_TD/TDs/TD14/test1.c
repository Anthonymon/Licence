#include "graphics.h"

POINT calcul_centre2(int co){ //calcul le centre de la case en fonction du numero de cette case
	POINT p1;
	p1.x=10;p1.y=100;
	if(co==0){p1.x=100;p1.y=100;return p1;}
	else if(co==1){p1.x=300;p1.y=100;return p1;}
	else if(co==2){p1.x=500;p1.y=100;return p1;}
	else if(co==3){p1.x=100;p1.y=300;return p1;}
	else if(co==4){p1.x=300;p1.y=300;return p1;}
	else if(co==5){p1.x=500;p1.y=300;return p1;}
	else if(co==6){p1.x=100;p1.y=500;return p1;}
	else if(co==7){p1.x=300;p1.y=500;return p1;}
	else if(co==8){p1.x=500;p1.y=500;return p1;}
}

int main(){
	init_graphics(600,600);
	wait_escape();
	exit(0);
}
