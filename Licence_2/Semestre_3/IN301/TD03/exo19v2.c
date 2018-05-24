#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea(int n){
	return rand()%n;
}

struct elem{ ////question a
	int val;
	struct elem* suiv;
};

struct elem* creer_liste_vide(){ ////question b
	return NULL;
}

int tester_liste_vide(struct elem* e){ /////question b
	if(e==NULL){
		return 1;
	}
	else {return 0;}
}

void libere_memoire(struct elem* e){ //////question b
	while(tester_liste_vide(e)==0){
		struct elem* temp=e;
		e=e->suiv;
		free(temp);
	}
}

struct elem* ajouter_debut(struct elem* e,int n){ ////question c
	struct elem* a;
	a=malloc(sizeof(struct elem)); //important 
	a->val=n;
	a->suiv=e;
	return a;
}

struct elem* ajouter_fin(struct elem* e,int n){
	struct elem* a=malloc(sizeof(struct elem));
	a->val=n;
	a->suiv=NULL;
	struct elem* ee=e;
	while(tester_liste_vide(ee->suiv)==0){
		ee=ee->suiv;
	}
	ee->suiv=a;
	return e;
}

/*struct elem* ajouter_fin_iteratif(struct elem* e,int n){
	struct elem* a;
	
	if(e==NULL){
		a=malloc(sizeof(struct elem));		
		a->val=n;
		a->suiv=NULL;
		return a;
	}
	a=malloc(sizeof(struct elem));
	a->suiv=ajouter_fin(a->suiv,n);
}*/

/*struct elem* ajouter_fin2(struct elem* e,int n){
	struct elem* a;
	if(e==NULL){
		//struct elem* a;
		if(!(a=malloc(sizeof(struct elem)))) exit(1);
		a->val=n;
		a->suiv=NULL;
		return a;
	}
	a->suiv=insere_fin2(a->suiv,n);
	return a;
}*/

void afficher_liste(struct elem* e){
	if(e==NULL){
		printf("VIDE");
	}
	else {
		while(tester_liste_vide(e)!=1){
			printf("%d ",e->val);
			e=e->suiv;
		}
		
	}
	printf("\n");
}


struct elem* inserer_alea(){
	struct elem* a=creer_liste_vide();
	int u=alea(20);
	while(u!=0){
		a=ajouter_debut(a,u);
		u=alea(20);
	}
	return a;
}


int tester_liste_tri(struct elem* e){
	if(tester_liste_vide(e)==0){
		int etat=1;
		struct elem* temp=e;
		while((etat==1)&&(tester_liste_vide(temp->suiv)==0)){
			if((temp->val)>(temp->suiv->val)){
				return 0;
			}
			temp=temp->suiv;
		}
		return 1;
	}
	return 1;
}

struct elem* ajouter_tri(struct elem* e,int n){

	struct elem* new;
	if(tester_liste_tri(e)==1){
		if((tester_liste_vide(e)==1)||(n<=(e->val))){
			new=malloc(sizeof(struct elem));
			if(new==NULL){exit(1);}
			new->val=n;
			new->suiv=e;
			return new;
		}
		e->suiv=ajouter_tri(e->suiv,n);
		return e;
	}
	
}

int rechercher_nb_elem(struct elem* e){
	struct elem* a=e;
	if(a==NULL){
		return 0;
	}
	else{
		while(tester_liste_vide(a)==0){
			return 1+rechercher_nb_elem(e->suiv);
		}
	}
}

int rechercher_elem(struct elem* e,int n){
	if(tester_liste_vide(e)==1){
		return 0;
	}
	else if((e->val)==n){return 1;}
	else{
		return rechercher_elem(e->suiv,n);
	}
}

struct elem* supprimer_elem(struct elem* e,int n){
	if(tester_liste_vide(e)==1){return e;}
	if(e->val==n){
		struct elem* tmp=e->suiv;
		free(e);
		return supprimer_elem(tmp,n);
	}
	else{
		e->suiv=supprimer_elem(e->suiv,n);
		return e;
	}
}

struct elem* concatener_listes(struct elem* e,struct elem* f){
	struct elem* temp=e;
	while(tester_liste_vide(temp->suiv)==0){
		temp=temp->suiv;
	}
	temp->suiv=f;
	return e;
	
}

/*struct elem* creer_liste_vide_tri(){
	struct elem* a=malloc(sizeof(struct elem));
	if(a==NULL){exit(1);}
	int compteur=0;
	//int n=alea(20);
	a=ajouter_debut(a,alea(20));
	while(compteur<10){
		a=ajouter_debut(a,alea(20));
	}
	return a;
}*/


int main(){
	srand(time(NULL));
	
	struct elem* eExo1;
	struct elem* eExo2;
	//eExo1=creer_liste_vide_tri();
	eExo2=inserer_alea();
	//afficher_liste(eExo1);
	afficher_liste(eExo2);
	
	//libere_memoire(eExo1);
	libere_memoire(eExo2);

	return 0;
}
