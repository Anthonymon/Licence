#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct { //graphe représenté par une matrice d'adjacence
  	int nombre_sommet;
  	int ** matrice_adjacence;
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
int j=0;
int compteur=0;
for(j = 0; j<G.nombre_sommet; j++){
	if(G.matrice_adjacence[i][j]==1)
		{	compteur++;					}}
	return compteur;
}


graphe init_graphe(int n){//créé un graphe dont tous les sommets sont isolés
	graphe G; 
	G.nombre_sommet	= n;
	G.matrice_adjacence = malloc(sizeof(int*)*n);
	int i;
	
	for(i=0; i<G.nombre_sommet ; i++)
	{G.matrice_adjacence[i] = calloc(n, sizeof(int));				}
	
	return G;
}

void libere_graphe(graphe G){
	int i;
	for(i=0; i<G.nombre_sommet ; i++)
	{free(G.matrice_adjacence[i]);}
	
	free(G.matrice_adjacence);
}

graphe cycle_graphe(int n){//créé un cycle
	graphe G = init_graphe(n);
	int i;
	for(i=0; i<n; i++)
	{	G.matrice_adjacence[i][(i+1)%n]=1;
		G.matrice_adjacence[(i+1)%n][i]=1;		
	}
	return G;
}


graphe complet_graphe(int n){//créé un graphe complet
	graphe G = init_graphe(n);
	int i,j;
	for(i=0; i<n; i++)
	{	for(j=0; j<n; j++)
			{if(i!=j) G.matrice_adjacence[i][j]=1;}	
	}
	
	return G;
}


graphe alea_graphe(int n, float p){
	int i,j;
	graphe G = init_graphe(n);
	for(i=0; i<n; i++)
	{for(j=i+1; j<n; j++)
	 {if(rand()%10000<p*10000)
		{G.matrice_adjacence[i][j]=1;
		G.matrice_adjacence[j][i]=1;}					}
							}
								
	return G;
}

graphe graphe_arbre(int *pere, int n){//créer un arbre couvrant à partir du tableau des pères représenté comme un graphe
	graphe G = init_graphe(n);
	int i;
	for(i = 0; i<n; i++){
		if(pere[i] != i){
			G.matrice_adjacence[i][pere[i]]=1;
			G.matrice_adjacence[pere[i]][i]=1;
			}
	
}
	
	return G;
}

void parcours_sommet(graphe G, int s, int *couleur, int *pere){
printf("Sommet : %d\n",s);
couleur[s]=1;
int i;
for(i = 0; i<G.nombre_sommet; i++){
	if(G.matrice_adjacence[s][i] && !couleur[i])
		{parcours_sommet(G,i,couleur,pere);		
		}
	}
couleur[s]=2;
//printf("Sommet : %d\n",s);
}

void parcours_graphe(graphe G){
	int *couleur = calloc(G.nombre_sommet,sizeof(int)); // 0 est blanc, 1 gris et 2 noir
	int *pere = malloc(sizeof(int)*G.nombre_sommet);
	int composante_connexe = 0;
	int i;
	for(i=0; i < G.nombre_sommet;i++){
		if(!couleur[i]) {printf("Composante %d : \n",composante_connexe);
			parcours_sommet(G,i,couleur,pere);
			pere[i]=i;
			composante_connexe++;}
	}
	
	free(couleur);
	free(pere);
}


  
void cycle_eulerien(graphe G){//on suppose le graphe connexe
}


int main(){
	/* Tests pour vérifier si vos implémentations sont correctes*/
	srand(time(NULL));
  	graphe G = cycle_graphe(10);
  	affiche_graphe(G);
	graphe H = complet_graphe(5);
	affiche_graphe(H);
	graphe L = alea_graphe(10,0.2);
	affiche_graphe(L);
	graphe A = alea_graphe(100,0.1);
	affiche_graphe(A);
	parcours_graphe(A);
	cycle_eulerien(L);
	cycle_eulerien(H);
	libere_graphe(G);
	libere_graphe(H);
	libere_graphe(L);
	libere_graphe(A);
}
