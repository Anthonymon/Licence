#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct { //graphe représenté par une matrice d'adjacence
  	int nombre_sommet;
  	int ** matrice_adjacence;
  	int * sommet_vu;
} graphe;


void affiche_graphe(graphe G){
	int i,j;
	printf("Graphe avec %d sommets \n",G.nombre_sommet);
	for(i = 0; i<G.nombre_sommet; i++){
		printf("Voisins de %d: ",i);
		for(j = 0; j < G.nombre_sommet; j++){
			if(G.matrice_adjacence[i][j]) printf("%d ",j);
		}
		printf("\n");
	}
}

int degre(graphe G, int i){
	if (i>G.nombre_sommet) return 0;
	else if(i<=0) return 0;
	else{
		int j;
		int compteur=0;
		for(j=0;j<G.nombre_sommet;j++){
			compteur+=(G.matrice_adjacence[i-1][j]);
		}
		return compteur;
	}
}


graphe init_graphe(int n){//créé un graphe dont tous les sommets sont isolés
	int i;
	graphe G; 
	G.nombre_sommet=n;
	G.matrice_adjacence=malloc(n*sizeof(int*));
	G.sommet_vu=calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		G.matrice_adjacence[i]=calloc(n,sizeof(int));
	}
	return G;
}

void libere_graphe(graphe G){
	int i;
	for(i=0;i<G.nombre_sommet;i++){
		free(G.matrice_adjacence[i]);
	}
	free(G.matrice_adjacence);
	free(G.sommet_vu);
}

graphe cycle_graphe(int n){//créé un cycle
	graphe G=init_graphe(n);
	int i,sup;
	for(i=0;i<n-1;i++){
		sup=i+1;
		G.matrice_adjacence[i][sup]=G.matrice_adjacence[sup][i]=1;
	}
	G.matrice_adjacence[sup][0]=G.matrice_adjacence[0][sup]=1;
	
	return G;
}


graphe complet_graphe(int n){//créé un graphe complet
	graphe G=init_graphe(n);
	int i,j;
	for(i=0;i<G.nombre_sommet;i++){
		for(j=0;j<G.nombre_sommet;j++){
			if(i!=j) G.matrice_adjacence[i][j]=1;
		}
	}
	return G;
}


graphe alea_graphe(int n){
	graphe G=init_graphe(n);
	int i,j;
	for(i=0;i<G.nombre_sommet;i++){
		for(j=0;j<G.nombre_sommet;j++){
			if(i!=j) G.matrice_adjacence[i][j]=rand()%2;
		}
	}
	return G;
}

graphe graphe_arbre(int *pere, int n){//créer un arbre couvrant à partir du tableau des pères représenté comme un graphe
	graphe G;
	return G;
}

int teste_sommets_tous_vus(graphe G){
	int i;
	for(i=0;i<G.sommet_vu[i];i++){
		if(G.sommet_vu[i]==0) return 0;
	}
	return 1;
}

graphe lit_prochain_sommet(graphe G){
	
}

void parcours_profondeur(graphe G,int debut){
	//printf("FF");
	/*if(teste_sommets_tous_vus(G)==1){
		printf("GGG");
		int i=debut;
		int j;
		while((i<G.nombre_sommet)&&(teste_sommets_tous_vus(G)!=0)){
			G.sommet_vu[i]=1;
			printf("%d\n",i);
			for(j=0;j<G.nombre_sommet;j++){
				if((G.matrice_adjacence[i][j]==1)&&(G.sommet_vu[j]==0)){
					//printf("(%d,%d) \n",i,j);
					parcours_profondeur(G,j);
				}
			
			}
			//printf("%d ",i);
			//G.sommet_vu[i]=1;
			i++;
			//printf("A\n");
		}
		for(i=0;i<G.nombre_sommet;i++){
			printf("%d",G.sommet_vu[i]);
		}
		printf("\n");
	}*/
	int i=debut;
	int j;
	while((i<G.nombre_sommet)&&(teste_sommets_tous_vus(G)!=0)){
		G.sommet_vu[i]=1;
		printf("%d\n",i);
		for(j=0;j<G.nombre_sommet;j++){
			if((G.matrice_adjacence[i][j]==1)&&(G.sommet_vu[j]==0)){
				//printf("(%d,%d) \n",i,j);
				parcours_profondeur(G,j);
			}
			
		}
		//printf("%d ",i);
		//G.sommet_vu[i]=1;
		i++;
		//printf("A\n");
	}
	for(i=0;i<G.nombre_sommet;i++){
		printf("%d",G.sommet_vu[i]);
	}
	printf("\n");
	
	if(teste_sommets_tous_vus(G)==1) printf("A\n");
	else printf("B\n");
	if(teste_sommets_tous_vus(G)==0){
		//for(i=0;i<G.nombre_sommet;i++){
			//if(G.sommet_vu[i]==0) parcours_profondeur(G,i);
		//}
	}
	//avant de quitter initialiser a 0
	//printf("\n");
}

void parcours_sommet(graphe G, int s, int *couleur, int *pere){
}

/*void*/graphe parcours_graphe(graphe G){
	//graphe res;
	int *couleur = calloc(G.nombre_sommet,sizeof(int)); // 0 est blanc, 1 gris et 2 noir
	int *pere = malloc(sizeof(int)*G.nombre_sommet);
	free(couleur);
	free(pere);
	//return G;
}

void cycle_eulerien(graphe G){//on suppose le graphe connexe
}


int main(){
	/* Tests pour vérifier si vos implémentations sont correctes*/
	srand(time(NULL));
	/*graphe G=init_graphe(12);
	int i,j;
	G.matrice_adjacence[2][3]=1;
	for(i=0;i<G.nombre_sommet;i++){
		for(j=0;j<G.nombre_sommet;j++){
			printf("%d",G.matrice_adjacence[i][j]);
		}
		printf("\n");
	}*/
	
  	//graphe G = cycle_graphe(10);
  	//graphe G = complet_graphe(10);
  	graphe G = alea_graphe(10);
  	int g;
  	for(g=0;g<G.nombre_sommet;g++){
		
	}
  	//if(teste_sommets_tous_vus(G))printf("A");
  	//else printf("B");
  	affiche_graphe(G);
  	//parcours_profondeur(G,0);
  	libere_graphe(G);
	/*graphe H = complet_graphe(5);
	affiche_graphe(H);
	graphe L = alea_graphe(10,0.2);
	affiche_graphe(L);
	graphe A = parcours_graphe(L);
	affiche_graphe(A);
	cycle_eulerien(L);
	cycle_eulerien(H);
	libere_graphe(G);
	libere_graphe(H);
	libere_graphe(L);
	libere_graphe(A);*/
	//printf(">%d\n",degre(G,1));
	return 0;
}
