#include "graphics.h"

int main(){
	init_graphics(600,600);
	POINT T1[20];
	int T2[20];
	int i;
	for(i=0;i<20;i++){
		T2[i]=alea_int(21);}
	for(i=0;i<20;i++){
		T1[i].x=alea_int(601);
		T1[i].y=alea_int(601);
	}
	
	for(i=0;i<20;i++){
		draw_fill_circle(T1[i],T2[i],rouge);
	}
	
	wait_escape();
	exit(0);
}
