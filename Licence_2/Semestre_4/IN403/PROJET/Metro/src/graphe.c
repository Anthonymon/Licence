// Clément Caumes 21501810
// Yassin Doudouh 21500127
// 05 mai 2017
// Projet Metro IN403

// graphe.c du projet Metro
// Contient les fonctions relatives à la gestion du graphe

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "lire_ecrire.h"
#include "types.h"

/* Fonctions de manipulations de listes */

// Fonction pour créer une liste
struct elem *creer_liste()
{
	return NULL;
}

// Teste si la liste passée en argument est vide
int teste_liste_vide(struct elem *l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

// Fonction qui affiche le contenu de la liste avec le nom des stations et de sa ligne
void affiche_liste(struct elem *l)
{

	if (teste_liste_vide(l)) {
		printf("La liste du chemin est vide \n");
	}
	while (l) {
		printf("%d: %s -> ligne ", l->s.num_sommet, l->s.nom_station);
		if (l->s.num_ligne == 30)
			printf("3bis\n");
		else if (l->s.num_ligne == 70)
			printf("7bis\n");
		else
			printf("%d\n", l->s.num_ligne);
		l = l->suiv;
	}
	printf("\n");
}

// Fonction qui vide la mémoire d'une liste
struct elem *libere_liste(struct elem *l)
{
	struct elem *tmp;
	while (l) {
		tmp = l->suiv;
		free(l);
		l = tmp;
	}
	return NULL;
}

// Fonction qui libère la liste dans la structure dijkstra
void libere_chemin_dijkstra(struct elem *l)
{
	l = libere_liste(l);
}

// Fonction qui ajoute à la fin un sommet à la liste l
struct elem *ajoute_elem_fin(struct elem *l, SOMMET s)
{
	struct elem *new = malloc(sizeof(struct elem));
	new->s = s;
	new->suiv = NULL;
	if (teste_liste_vide(l))
		return new;
	struct elem *debut = l;
	while (l->suiv)
		l = l->suiv;
	l->suiv = new;
	return debut;
}

// Fonction qui ajoute au début un sommet à la liste l
struct elem *ajoute_elem_debut(struct elem *l, SOMMET i)
{
	struct elem *new = malloc(sizeof(struct elem));
	new->s = i;
	new->suiv = l;
	return new;
}

/*--------------------------------------------------*/

// Fonction d'initialisation de la structure dijkstra entre les sommets de rangs a et b
DIJKSTRA initialise_dijkstra(int a, int b)
{
	DIJKSTRA d;
	d.rang_deb = a;
	d.rang_fin = b;
	d.chemin = creer_liste();
	d.duree = 0;
	return d;
}

// Fonction d'initialisation du graphe à n sommets
// @affichage: AFFICHAGE_GENERAL car le zoom n'est pas activé
// @mode: MODE_METRO pour ne pas quitter l'application
// @d: le calcul entre 2 sommets n'est pas fait car le graphe n'est même pas encore initialisé
// @station: on alloue n fois dans le tableau des sommets
// @reseau: on alloue n*n fois dans le tableau des arcs
GRAPHE initialise_graphe(int n)
{
	int i;
	GRAPHE g;
	g.nb_sommets = n;
	g.d = initialise_dijkstra(INVALIDE, INVALIDE);
	g.station = malloc(n * sizeof(SOMMET));
	g.reseau = malloc(n * sizeof(ARC *));
	for (i = 0; i < n; i++) {	//on met 0 dans les ponderations des arcs
		g.reseau[i] = calloc(n, sizeof(ARC));
	}
	for (i = 0; i < 2; i++) {	//pas de chemin choisi pour l'instant
		g.chemin[i].num_sommet = INVALIDE;
	}
	return g;
}

// Fonction d'initialisation de la structure METRO
METRO initialise_metro(int n)
{
	METRO m;
	m.affichage = AFFICHAGE_GENERAL;
	m.mode = MODE_METRO;
	m.g = initialise_graphe(n);
	return m;
}

// Fonction qui met dans le tableau t de taille n les valeurs égales à val
void initialise_tableau(int *t, int n, int val)
{
	int i;
	for (i = 0; i < n; i++) {
		t[i] = val;
	}
}

// Fonction booléenne pour savoir si tous les sommets ont été traités
int teste_tous_sommets_traites(int *t, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		if (t[i] == NON_TRAITE)
			return 0;
	}
	return 1;
}

// Fonction qui permet d'ajouter une station parmi le chemin à parcourir lors du calcul de DIJKSTRA
DIJKSTRA ajoute_dijkstra(DIJKSTRA d, SOMMET s)
{
	d.chemin = ajoute_elem_debut(d.chemin, s);
	return d;
}

// Fonction qui remplit la liste des stations à parcourir lors du calcul du plus court chemin
DIJKSTRA cree_chemin(DIJKSTRA d, int *tab_peres, GRAPHE g)
{
	int temp;
	int s = d.rang_fin;
	d = ajoute_dijkstra(d, g.station[s]);
	while (s != d.rang_deb) {
		temp = s;
		s = tab_peres[temp];
		d.duree += g.reseau[temp][tab_peres[temp]].ponderation;
		d = ajoute_dijkstra(d, g.station[s]);
	}
	return d;
}

// Fonction principale du projet qui calcule le plus court chemin par l'algorithme de Dijkstra
// en utilisant @GRAPHE g le graphe cette fonction remplit la structure DIJKSTRA 
// avec le plus court chemin entre rang_sommet_depart et rang_fin
DIJKSTRA calcul_dijkstra(GRAPHE g, int rang_sommet_depart, int rang_fin)
{
	DIJKSTRA d = initialise_dijkstra(rang_sommet_depart, rang_fin);
	int i, min, sommet_a_traiter;
	if (rang_fin >= g.nb_sommets)
		erreur1();
	if (rang_sommet_depart >= g.nb_sommets)
		erreur1();
	if ((rang_sommet_depart == INVALIDE) || (rang_fin == INVALIDE))
		return d;
	int station_traitee[g.nb_sommets];	//contient 0 ou 1 si la station a ete vu ou non
	int station_pere[g.nb_sommets];	//contient le pere du sommet i par lequel le chemin est le plus court
	int tdijkstra[g.nb_sommets];	//contient les plus petites distances entre le sommet de depart et lelement

	//initialisation lors du calcul du plus court chemin
	initialise_tableau(station_traitee, g.nb_sommets, NON_TRAITE);	//aucun sommet n'a été traité
	initialise_tableau(station_pere, g.nb_sommets, AUCUN_PERE);	//aucun sommet n'a encore de père
	station_traitee[rang_sommet_depart] = TRAITE;	//le sommet est traité

	for (i = 0; i < g.nb_sommets; i++) {	//premiere iteration qui met les pondérations sur les arcs des successeurs du sommet de départ
		if (g.reseau[rang_sommet_depart][i].ponderation != AUCUN_ARC) {
			tdijkstra[i] =
			    g.reseau[rang_sommet_depart][i].ponderation;
			station_pere[i] = rang_sommet_depart;
		} else
			tdijkstra[i] = AUCUN_ARC;
	}
	tdijkstra[rang_sommet_depart] = 0;	//la plus petite distance entre le sommet de départ et lui-même est 0

	//tant que tous les sommets ne sont pas traites
	while (!teste_tous_sommets_traites(station_traitee, g.nb_sommets)) {
		min = INFINI;
		//recherche du prochain sommet à traiter (qui a la plus petite distance)
		for (i = 0; i < g.nb_sommets; i++) {
			if ((station_traitee[i] == NON_TRAITE)
			    && (tdijkstra[i] < min)) {
				sommet_a_traiter = i;
				min = tdijkstra[i];
			}
		}
		station_traitee[sommet_a_traiter] = TRAITE;	//on traite ce sommet
		// ici on connait le sommet a traiter
		for (i = 0; i < g.nb_sommets; i++) {
			//si on améliore la plus petite distance en passant par ce sommet
			if (g.reseau[sommet_a_traiter][i].ponderation !=
			    AUCUN_ARC) {
				if (tdijkstra[i] >=
				    (tdijkstra[sommet_a_traiter] +
				     g.reseau[sommet_a_traiter][i].
				     ponderation)) {
					tdijkstra[i] =
					    tdijkstra[sommet_a_traiter] +
					    g.reseau[sommet_a_traiter][i].
					    ponderation;
					station_pere[i] = sommet_a_traiter;	// alors le pere de ce sommet est le sommet traité de départ
				}
			}
		}
	}
	d = cree_chemin(d, station_pere, g);	//crée la liste des stations qu'il faut traverser
	return d;
}

// Fonction qui calcule le plus court chemin entre a et b 
GRAPHE calcul_plus_court_chemin(GRAPHE g, int a, int b)
{
	if ((a == INVALIDE) || (b == INVALIDE))
		return g;
	g.d = calcul_dijkstra(g, a, b);
	affiche_liste(g.d.chemin);
	ecrit_chemin(g, g.d);
	return g;
}

// Fonction pour libérer la mémoire de toutes les allocations de GRAPHE
void libere_graphe(GRAPHE g)
{
	int i;
	free(g.station);
	for (i = 0; i < g.nb_sommets; i++) {
		free(g.reseau[i]);
	}
	free(g.reseau);
}
