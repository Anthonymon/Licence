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
void initialise_tableau(int T[],int N,int valeur){
	for(i=0;i<N;i++){
		T[i]=valeur;
	}
}

int main(){
	init_graphics(600,300);
	mettre_hasard();
	affiche_tableau();
	writeln();
	initialise_tableau(T,20,12);
	writeln();
	affiche_tableau();
	wait_escape();
	exit(0);
}
