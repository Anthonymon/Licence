//td11 exo63 clement caumes
#include "graphics.h"

POINT p1,p2;
int T[20];
int i;
int j;
int pg;

void affichage(){
	for(i=0;i<20;i++){T[i]=alea_int(100);}
	
	for(i=0;i<20;i++){
		p1.x=(100+20*i);p1.y=50;
		p2.x=(100+20*i+19);p2.y=(50+3*T[i]);
		draw_fill_rectangle(p1,p2,bleu);
	}
}


void swap(int i,int j){
	p1.x=(100+20*i);p1.y=50;
	p2.x=(100+20*i+19);p2.y=(50+3*T[i]);
	draw_fill_rectangle(p1,p2,noir);
	p1.x=(100+20*j);p1.y=50;
	p2.x=(100+20*j+19);p2.y=(50+3*T[j]);
	draw_fill_rectangle(p1,p2,noir);
	int temp;
	temp=T[i];
	T[i]=T[j];
	T[j]=temp;
	p1.x=(100+20*i);p1.y=50;
	p2.x=(100+20*i+19);p2.y=(50+3*T[i]);
	draw_fill_rectangle(p1,p2,bleu);
	p1.x=(100+20*j);p1.y=50;
	p2.x=(100+20*j+19);p2.y=(50+3*T[j]);
	draw_fill_rectangle(p1,p2,bleu);
}

int plus_grand(int deb,int fin){
	pg=deb;
	for(i=deb;i<fin;i++){
		if(T[i]>T[pg]){pg=i;}
	}
	return pg;
}

void tri(){
	for(j=20;i>0;j--){
		pg=plus_grand(0,j);
		swap(pg,j-1);
		wait_clic();
		for(i=0;i<20;i++){
			p1.x=(100+20*i);p1.y=50;
			p2.x=(100+20*i+19);p2.y=(50+3*T[i]);
			draw_fill_rectangle(p1,p2,bleu);
		}
	}
}

int main(){
	init_graphics(900,600);
	affichage();
	wait_clic();
	tri();
	
	wait_escape();
	exit(0);
}

