#include "graphics.h"

int T[20];
int i;
int numerocase;

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

int recherche(int n){
	for(i=0;i<20;i++){
		if(T[i]==n){
			return i;
		}
	}
}

int main(){
	init_graphics(600,300);
	mettre_hasard();
	affiche_tableau();
	writeln();
	numerocase=recherche(5);
	write_int(numerocase);
	wait_escape();
	exit(0);
}
