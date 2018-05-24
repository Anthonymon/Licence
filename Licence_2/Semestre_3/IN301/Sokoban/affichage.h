// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// affichage.h du projet SOKOBAN
// Contient toutes les fonctions d'affichage

#ifndef __AFFICHAGE_H
#define __AFFICHAGE_H

#include "sokoban.h"

void initialise_affichage_interface_creation();
void initialise_affichage_interface_jeu();

void affiche_interface_creation(ACTIONCREATION a);
void affiche_interface_jeu(ACTIONJEU a);

#endif
