// Clément Caumes 21501810
// Yassin Doudouh 21500127
// 05 mai 2017
// Projet Metro IN403

// graphe.h du projet Metro
// Contient les signatures des fonctions de graphe.c et les structures de manipulations de graphe

#include "types.h"
#include <uvsqgraphics.h>

#ifndef __GRAPHE_H
#define __GRAPHE_H

struct sommet {
	char nom_station[TAILLE_CHAINE_CARACTERES];	//nom de la station
	int num_sommet;		// numéro du sommet dans metro.txt
	int num_ligne;		//numéro de la ligne du sommet
	POINT geolocalisation;	//coordonnées de la station dans Paris
};
typedef struct sommet SOMMET;

struct arc {
	int terminus;		//numéro du sommet du terminus /* PAS_DE_TERMINUS si c'est un changement de ligne */
	int ponderation;	//ponderation dans l'arc
};
typedef struct arc ARC;

struct dijkstra {
	int rang_deb;		//numéro du sommet de départ pour le calcul du plus court chemin
	int rang_fin;		//numéro du sommet d'arrivée
	int duree;		//durée qu'il faut pour aller de rang_deb à rang_fin
	struct elem *chemin;	//liste des stations qu'il faut traverser pour aller de rang_deb à rang_fin
};
typedef struct dijkstra DIJKSTRA;

struct graphe {
	SOMMET chemin[2];	//sélection par l'utilisateur des sommets lors du calcul du plus court chemin
	DIJKSTRA d;		//contient le plus court chemin
	int nb_sommets;		//nombre de sommets au total dans le graphe
	SOMMET *station;	//tableau des sommets du graphe
	ARC **reseau;		//tableau des arcs du graphe
};
typedef struct graphe GRAPHE;

struct metro {
	int affichage;		//AFFICHAGE_GENERAL ou ZOOM
	int mode;		//MODE_METRO ou MODE_QUITTER
	GRAPHE g;		//graphe du projet
};
typedef struct metro METRO;

struct elem {			//liste de sommets
	SOMMET s;
	struct elem *suiv;
};

int teste_liste_vide(struct elem *l);
void affiche_liste(struct elem *l);
struct elem *libere_liste(struct elem *l);
void libere_chemin_dijkstra(struct elem *l);

GRAPHE initialise_graphe(int n);
METRO initialise_metro(int n);
DIJKSTRA calcul_dijkstra(GRAPHE g, int rang_sommet_depart, int rang_fin);
GRAPHE calcul_plus_court_chemin(GRAPHE g, int a, int b);
void libere_graphe(GRAPHE g);

#endif
