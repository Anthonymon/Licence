#include "graphics.h"
int T[20];
int i;
POINT p1,p2;
int numero_plus_petit;
int numero_plus_grand;
int plus_petit;
int plus_grand;



void affiche_plus_grand(){
	for(i=0;i<20;i++){
		if(plus_grand<T[i]){
			numero_plus_grand=i;
			plus_grand=T[i];
		}
	}
	p1.x=100+20*numero_plus_grand;p1.y=50;
	p2.x=100+20*numero_plus_grand+19;p2.y=50+3*T[numero_plus_grand];
	draw_fill_rectangle(p1,p2,vert);
}

void affiche_plus_petit(){
	for(i=0;i<20;i++){
		if(plus_petit>T[i]){
			plus_petit=T[i];
			numero_plus_petit=i;
		}
	}
	p1.x=100+20*numero_plus_petit;p1.y=50;
	p2.x=100+20*numero_plus_petit+19;p2.y=50+3*T[numero_plus_petit];
	draw_fill_rectangle(p1,p2,rouge);
}

int main(){
	init_graphics(600,600);
	
	for(i=0;i<20;i++){
		T[i]=alea_int(100);
	}
	plus_petit=T[0];
	plus_grand=T[0];
	for(i=0;i<20;i++){
		p1.x=100+20*i;p1.y=50;
		p2.x=100+20*i+19;p2.y=50+3*T[i];
		draw_fill_rectangle(p1,p2,bleu);
	}
	affiche_plus_grand();
	affiche_plus_petit();
	
	wait_escape();
	exit(0);
}

