// Clément Caumes 21501810
// Yassin Doudouh 21500127
// 05 mai 2017
// Projet Metro IN403

// affichage.h du projet Metro
// Contient la signature des fonctions de affichage.c

#include "types.h"

#ifndef __AFFICHAGE_H
#define __AFFICHAGE_H

void initialise_fenetre();
void affiche_carte(METRO m);
METRO interaction(METRO m);
void libere_fenetre();

#endif
