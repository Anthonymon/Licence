#include <stdio.h>
#include <stdlib.h>

struct element{
	int val;
	struct element* suivant;
};
typedef struct element element;
typedef element* liste;

/*liste creerListeVide(){
	return NULL;
}*/

/*int estListeVide(liste l){
	if(l==NULL){
		return 1;
	}
	else return 0;
}*/

void afficheListe(liste l){
	if(l!=NULL){
		
	}
}

liste insere_debut(liste l,int x){
	liste new=malloc(sizeof(element));
	new->val=x;
	new->suivant=l;
	return new;								
}

void afficheListe1(liste l){
	if(estListeVide(l)){printf("VIDE ");}
	else {
		printf("%d ",l->val);
		afficheListe1(l->suivant);
	}
	printf("\n");
}

void afficheListe2(liste l){
	liste temp=l;
	while(!estListeVide(temp)){
		printf("%d",temp->val);
		temp=temp->suivant;
	}
	printf("\n");
}

void libere(liste l){
	if(!estListeVide(l)){
		libere(l->suivant);
		free(l);
	}
}



int main(){
	liste exoL;
	exoL=creerListeVide();
	exoL=insere_debut(exoL,2);
	exoL=insere_debut(exoL,35);
	afficheListe1(exoL);
	libere(exoL);
	afficheListe1(exoL);
	return 0;
}
