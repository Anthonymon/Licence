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

void inversion(){
	int j;
		for(j=0;j<(20/2);j++){// je ne comprend pas la difference entre cette boucle et ...
			echange(j,20-1-j);
			affiche_tableau();
			writeln();
		}
		
}

int main(){
	init_graphics(600,600);
	mettre_hasard();
	affiche_tableau();
	writeln();
	inversion();
	
	
	
	wait_escape();
	exit(0);
}
