#include "graphics.h"

int main(){
	init_graphics(600,600);
	int T[20];
	int i;
	POINT p1,p2;
	for(i=0;i<20;i++){
		T[i]=alea_int(100);
	}
	for(i=0;i<20;i++){
		p1.x=100+20*i;p1.y=50;
		p2.x=100+20*i+19;p2.y=50+3*T[i];
		draw_fill_rectangle(p1,p2,bleu);
	}
	
	wait_escape();
	exit(0);
}
