#include "graphics.h"

int T[20];
int i;
int numerocase;
int min;
int numero;
int max;

void mettre_hasard(){
	for(i=0;i<20;i++){
		T[i]=alea_int(300);
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

int recherchemin(){
	min=T[0];
	for(i=0;i<20;i++){
		if(min>T[i]){
			min=T[i];
			numero=i;
		}
	}
	return numero;
}

int recherchemax(){
	max=T[0];
	for(i=0;i<20;i++){
		if(max<T[i]){
			max=T[i];
			numero=i;
		}
	}
	return numero;
}

int main(){
	init_graphics(600,300);
	mettre_hasard();
	affiche_tableau();
	writeln();
	numerocase=recherchemin();
	write_int(numerocase);
	writeln();
	numerocase=recherchemax();
	write_int(numerocase);
	wait_escape();
	exit(0);
}
