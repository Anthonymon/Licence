//clement caumes td1 exo6
#include "graphics.h"

int rebond;

int trop_haut(POINT p,int r){
	if((p.y+r)>600){
		rebond++;
		return 1;
	}
	else {return 0;}
}

POINT init_balle(int x,int y){
	POINT p;
	p.x=x;p.y=y;
	return p;
}

POINT deplace_balle(POINT ancien,int x,int y){
	draw_fill_circle(ancien,25,noir);
	affiche_all();
	ancien=init_balle(ancien.x+x,ancien.y+y);
	
	if(rebond==0){
		draw_fill_circle(ancien,25,bleu);
	}
	else if(rebond==1){draw_fill_circle(ancien,25,rouge);}
	
	//draw_fill_circle(ancien,25,bleu);
	return ancien;
}

int main(){
	affiche_auto_off();
	init_graphics(900,600);
	POINT p;
	p=init_balle(50,50);
	draw_fill_circle(p,25,bleu);
	rebond=0;
	int i;
	POINT p2;
	int test;
	for(i=0;i<1000;i++){
		attendre(20);
		test=trop_haut(p,25);
		if((test==0)&&(rebond==0)){
			p2=deplace_balle(p,2,4);
		}
		else if((test==1)||(rebond==1)){
			p2=deplace_balle(p,2,-3);
		}
		
		p=init_balle(p2.x,p2.y);
	}
	wait_escape();
	exit(0);
}

