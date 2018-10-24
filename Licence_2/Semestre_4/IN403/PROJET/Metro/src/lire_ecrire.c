// Clément Caumes 21501810
// Yassin Doudouh 21500127
// 05 mai 2017
// Projet Metro IN403

// lire_ecrire.c du projet Metro
// Contient les fonctions relatives à la lecture de metro.txt et à l'écriture dans le terminal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uvsqgraphics.h>
#include "lire_ecrire.h"
#include "graphe.h"
#include "affichage.h"
#include "types.h"

// Fonction en cas d'erreur 
void erreur1()
{
	printf("ERREUR DIJKSTRA: RANG DU SOMMET DE DEPART INVALIDE\n");
	exit(1);
}

// Fonction qui compte le nombre de sommets dans le fichier (nom en argument)
int compte_nb_sommets(char *nomFichier)
{
	FILE *f = fopen(nomFichier, "r");
	int i = 0;
	char c;
	char d = 'a';
	while (i < 3) {		//parcourt les 3 premières lignes
		c = fgetc(f);
		if (c == '\n')
			i++;
	}
	i = 1;
	do {
		c = fgetc(f);
		if (c == '\n') {
			d = fgetc(f);
			if (d == 'V') {
				i++;
			}
		}
	} while (d != 'E');
	fclose(f);
	return i;
}

// Fonction qui lit le fichier nomFichier et remplit la structure GRAPHE
GRAPHE initialise_stations(char *nomFichier, GRAPHE g)
{
	FILE *f = fopen(nomFichier, "r");
	char c;
	int num_s;
	int num_l;
	int x, y;
	int i = 0;
	int j = 0;
	while (i < 3) {		//on lit les 3 premières lignes qui ne sont que des commentaires
		c = fgetc(f);
		if (c == '\n')
			i++;
	}
	//pour chaque sommet, on lit son numero de sommet, son numero de ligne, ses coordonnees geographiques et son nom
	//chaque sommet correspond à une station d'une ligne
	//Attention: on peut avoir plusieurs stations avec le même nom (pas la même ligne)
	for (i = 0; i < g.nb_sommets; i++) {
		c = fgetc(f);
		fscanf(f, "%d %d %d %d ", &num_s, &num_l, &x, &y);
		j = 0;
		while (c != '\n') { //lecture du nom de la station
			c = fgetc(f);
			g.station[i].nom_station[j] = c;
			j++;
		}
		g.station[i].nom_station[j - 1] = '\0';
		g.station[i].num_sommet = num_s;
		g.station[i].num_ligne = num_l;
		g.station[i].geolocalisation.x = x;
		g.station[i].geolocalisation.y = y;
	}
	fclose(f);
	return g;
}

// Fonction qui lit le fichier nomFichier et initialise les arcs entre les sommets
GRAPHE initialise_reseau(char *nomFichier, GRAPHE g)
{
	FILE *f = fopen(nomFichier, "r");
	char c, d = 'a';
	while (d != 'E') {	//on lit jusqu'à lire le 'E' signifiant le début des arcs
		c = fgetc(f);
		if (c == '\n')
			d = fgetc(f);
	}
	d = ungetc(d, f);
	int test = 0;
	int absci, ordon, ponder, direc1, direc2;
	int i, j;
	//on met d'abord aucun terminus et aucun arc entre chaque sommet
	//comme ça les sommets avec les mêmes noms n'auront pas de terminus car c'est juste un changement de ligne
	for (i = 0; i < g.nb_sommets; i++) {
		for (j = 0; j < g.nb_sommets; j++) {
			g.reseau[i][j].terminus = PAS_DE_TERMINUS;
			g.reseau[i][j].ponderation = AUCUN_ARC;
		}
	}
	while (test != 1) {	//on lit le fichier jusqu'à la fin
		fscanf(f, "%c %d %d %d %d %d ", &c, &absci, &ordon, &ponder,
		       &direc1, &direc2);
		d = fgetc(f);
		if (d == EOF)
			test = 1;
		d = ungetc(d, f);
		//ponder correspond à la pondération dans un arc
		//direc1 correspond au terminus entre le premier et le deuxieme sommet
		//direc2 correspond au terminus entre le deuxieme et le premier sommet
		g.reseau[absci][ordon].ponderation = ponder;
		g.reseau[absci][ordon].terminus = direc1;
		//le symétrique est aussi initialisé car les lignes de metro vont dans les 2 sens
		g.reseau[ordon][absci].ponderation = ponder;
		g.reseau[ordon][absci].terminus = direc2;
	}
	fclose(f);
	return g;
}

// Fonction qui calcule le nombre d'heures en fonction d'une durée
int calcul_heures(int duree)
{
	return duree / 3600;
}

// Fonction qui calcule le nombre de minutes en fonction d'une durée
int calcul_minutes(int duree)
{
	return duree / 60;
}

// Fonction qui écrit le plus court chemin entre les 2 sommets sélectionnés dans le terminal
void ecrit_chemin(GRAPHE g, DIJKSTRA d)
{
	int h, m, s;
	h = calcul_heures(d.duree);
	m = calcul_minutes(d.duree - h);
	s = d.duree - (h * 3600 + m * 60);
	struct elem *p1 = d.chemin;
	struct elem *p2 = d.chemin->suiv;
	struct elem *temp;
	printf("- Vous êtes à %s.\n", g.station[d.rang_deb].nom_station);
	while (!teste_liste_vide(p2)) {
		if ((g.reseau[p1->s.num_sommet][p2->s.num_sommet].terminus !=
		     PAS_DE_TERMINUS) && ((p1->s.num_sommet) == d.rang_deb)) {
			temp = p1->suiv;
			if (p1->s.num_ligne == 30)
				printf("- Prenez la ligne 3bis");
			else if (p1->s.num_ligne == 70)
				printf("- Prenez la ligne 7bis");
			else
				printf("- Prenez la ligne %d", p1->s.num_ligne);
			printf(" direction %s. \n",
			       g.station[g.
					 reseau[p1->s.num_sommet][temp->s.
								  num_sommet].
					 terminus].nom_station);
		}
		//si on change de ligne
		if (g.reseau[p1->s.num_sommet][p2->s.num_sommet].terminus ==
		    PAS_DE_TERMINUS) {
			printf("- A %s, prenez la ligne ", p1->s.nom_station);
			if (p1->s.num_ligne == 30)
				printf("3bis ");
			else if (p1->s.num_ligne == 70)
				printf("7bis ");
			else
				printf("%d ", p1->s.num_ligne);
			if (p2->s.num_sommet != d.rang_fin) {
				temp = p2->suiv;
				printf("direction %s.\n",
				       g.station[g.
						 reseau[p2->s.num_sommet][temp->
									  s.
									  num_sommet].
						 terminus].nom_station);
			} else
				printf("\n");
		}
		p1 = p1->suiv;
		p2 = p2->suiv;
	}
	//écrit le temps qu'il faut pour aller entre 2 sommets
	printf("- Vous devriez arriver à %s dans ",
	       g.station[d.rang_fin].nom_station);
	if (h > 1)
		printf("%d heures ", h);
	else if (h == 1)
		printf("%d heure ", h);
	if (m > 1)
		printf("%d minutes ", m);
	else if (m == 1)
		printf("%d minute ", m);
	if (s > 1)
		printf("%d secondes.\n", s);
	else if (s == 1)
		printf("%d seconde.\n", s);
	printf("------------------------------------------------------------");
	printf("\n\n");
}
