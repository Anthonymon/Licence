// Clément Caumes 21501810
// Yassin Doudouh 21500127
// 05 mai 2017
// Projet Metro IN403

// lire_ecrire.h du projet Metro
// Contient les signatures des fonctions de lire_ecrire.c

#include "types.h"
#include "graphe.h"

#ifndef __LIRE_ECRIRE_H
#define __LIRE_ECRIRE_H

void erreur1();

int compte_nb_sommets(char *nomFichier);
GRAPHE initialise_stations(char *nomFichier, GRAPHE g);
GRAPHE initialise_reseau(char *nomFichier, GRAPHE g);
void ecrit_chemin(GRAPHE g, DIJKSTRA d);

#endif
