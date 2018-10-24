//td11 exo62 clement caumes
#include "graphics.h"

POINT p1,p2;
int T[20];
int i;
int pp;
int numero;
int transfert;

void recherche(){
	pp=T[0];
	for(i=0;i<20;i++){
		if(pp>T[i]){
			pp=T[i];
			numero=i;
		}
	}
	write_int(numero);
}

void echange(){
	transfert=T[0];
	p1.x=(100+20*0);p1.y=50;
	p2.x=(100+20*0+19);p2.y=(50+3*T[0]);
	draw_fill_rectangle(p1,p2,noir);
	T[0]=T[numero];
	T[numero]=transfert;
	
	for(i=0;i<20;i++){
		p1.x=(100+20*i);p1.y=50;
		p2.x=(100+20*i+19);p2.y=(50+3*T[i]);
		draw_fill_rectangle(p1,p2,bleu);
	}
	
}

void reaffichage(){
	for(i=0;i<20;i++){
		p1.x=(100+20*i);p1.y=50;
		p2.x=(100+20*i+19);p2.y=(50+3*T[i]);
		if(i==0){draw_fill_rectangle(p1,p2,rouge);}
		else {draw_fill_rectangle(p1,p2,bleu);}
	}
}

int main(){
	init_graphics(900,600);
	
	for(i=0;i<20;i++){T[i]=alea_int(100);}
	
	for(i=0;i<20;i++){
		p1.x=(100+20*i);p1.y=50;
		p2.x=(100+20*i+19);p2.y=(50+3*T[i]);
		draw_fill_rectangle(p1,p2,bleu);
	}
	
	recherche();
	wait_clic();
	echange();
	wait_clic();
	fill_screen(noir);
	wait_clic();
	reaffichage();
	wait_escape();
	exit(0);
}
