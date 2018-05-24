#include "graphics.h"

int T[20];
int i;

void mettre_hasard(){
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

void echange(int n, int m){
	int inter;
	inter=T[n];
	T[n]=T[m];
	T[m]=inter;
}

int main(){
	init_graphics(600,300);
	mettre_hasard();
	affiche_tableau();
	writeln();
	echange(2,3);
	affiche_tableau();
	
	wait_escape();
	exit(0);
}

