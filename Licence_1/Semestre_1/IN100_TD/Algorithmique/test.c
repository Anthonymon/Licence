#include "graphics.h"

int T[20];
int i,j;

void hasard(){
	for(i=0;i<20;i++){
		T[i]=alea_int(10);
	}
}

void affiche_tableau(){
	for(i=0;i<20;i++){
		write_int(T[i]);
		write_text(" ");
	}
}

void echange(int a,int b){
	int passage;
	passage=T[a];
	T[a]=T[b];
	T[b]=passage;
}

void inversion(){
	for(i=0;i<(20/2);i++){
			echange(T[i],T[20-1-i]);
			affiche_tableau();
			writeln();
		
	}
}

int main(){
	init_graphics(600,600);
	hasard();
	affiche_tableau();
	writeln();
	echange(1,2);
	affiche_tableau();
	writeln();
	writeln();
	inversion();
	wait_escape();
	exit(0);
}
