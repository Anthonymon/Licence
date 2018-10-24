#include <stdio.h>
#include <stdlib.h>

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

TABLEAU tri_insertion(TABLEAU t){
	int TC,p,i,temp;
	for(TC=0;TC<t.taille-1;TC++){
		p=0;
		temp=t.tab[TC+1];
		while(temp>t.tab[p]){
			p++;
		}
		for(i=TC;i>=p;i--){
			t.tab[i+1]=t.tab[i];
		}
		t.tab[p]=temp;
	}
	return t;
}

TABLEAU tri_permutation(TABLEAU t){
	int TC,i,temp;
	for(TC=1;TC<t.taille;TC++){
		for(i=t.taille-1;i>=TC;i--){
			if(t.tab[i]<t.tab[i-1]){
				temp=t.tab[i];
				t.tab[i]=t.tab[i-1];
				t.tab[i-1]=temp;
			}
		}
	}
	
	return t;
}

int rechercheRangMin(TABLEAU t1,int s){
	int i;
	int min=t1.tab[s];
	int rangMin=s;
	for(i=s;i<t1.taille;i++){
		if(min>t1.tab[i]){
			min=t1.tab[i];
			rangMin=i;
		}
	}
	return rangMin;
}

TABLEAU tri_selection(TABLEAU t){
	int TC;
	int e;
	int temp;
	for(TC=0;TC<t.taille;TC++){
		e=rechercheRangMin(t,TC);
		temp=t.tab[e];
		t.tab[e]=t.tab[TC];
		t.tab[TC]=temp;
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

int main(){
	srand(time(NULL));
	TABLEAU tab;
	tab=init_TABLEAU();
	affiche_TABLEAU(tab);
	tab=tri_insertion(tab);
	affiche_TABLEAU(tab);
	tab=tri_permutation(tab);
	affiche_TABLEAU(tab);
	tab=tri_selection(tab);
	affiche_TABLEAU(tab);
	
	return 0;
}
