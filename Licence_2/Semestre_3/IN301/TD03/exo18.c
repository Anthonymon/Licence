#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea(int n){
	return rand()%n;
}


struct Tableau{
	int taille;
	int tab[100];
};
typedef struct Tableau TABLEAU ;

TABLEAU init_TABLEAU(){
	TABLEAU t;
	t.taille=10;
	int i;
	for(i=0;i<t.taille;i++){
		t.tab[i]=alea(20);
	}
	return t;
}

void affiche_TABLEAU(TABLEAU t){
	int i;
	printf("Les elements du tableau sont : ");
	for(i=0;i<t.taille;i++){
		printf("%d ",t.tab[i]);
	}
	printf("\n");
}

int produit(TABLEAU t){
	int i;
	int prod=1;
	for(i=0;i<t.taille;i++){
		prod*=t.tab[i];
	}
	return prod;
}

int min(TABLEAU t){
	int i;
	int min=t.tab[0];
	for(i=0;i<t.taille;i++){
		if(min>t.tab[i]){
			min=t.tab[i];
		}
	}
	return min;
}

int posMin(TABLEAU t,int deb){
	int i;
	int min=t.tab[deb];
	int pos=deb;
	for(i=deb+1;i<t.taille;i++){
		if(min>t.tab[i]){
			min=t.tab[i];
			pos=i;
		}
	}
	return pos;
}

TABLEAU decalage(TABLEAU Texo){
	Texo.taille=Texo.taille+1;
	int i;
	for(i=Texo.taille;i>0;i--){
		Texo.tab[i]=Texo.tab[i-1];
	}
	Texo.tab[0]=0;
	return Texo;
}

int tableauTrie(TABLEAU T){
	int i;
	for(i=0;i<T.taille;i++){
		if(T.tab[i]>T.tab[i+1]){
			return 0;
		}
	}
	return 1;
}

TABLEAU echangeValeurs(TABLEAU T,int i,int j){
	int temp;
	temp=T.tab[i];
	T.tab[i]=T.tab[j];
	T.tab[j]=temp;
	return T;
}

TABLEAU tri(TABLEAU T){
	int etape=0;
	int positionMin;

	while(etape<T.taille){
		positionMin=posMin(T,etape);
		T=echangeValeurs(T,etape,positionMin);
		etape++;
	}
	return T;
}

TABLEAU tri

int main(){
	srand(time(NULL));
	
	TABLEAU Texo;
	Texo=init_TABLEAU();
	affiche_TABLEAU(Texo);
	affiche_TABLEAU(tri(Texo));


	
	return 0;
}
