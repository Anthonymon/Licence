// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// action_jeu.h du projet SOKOBAN
// Contient toute la gestion de l'interaction avec l'utilisateur pour le mode jeu

#ifndef __ACTION_JEU_H
#define __ACTION_JEU_H

#include <uvsqgraphics.h>
#include "sokoban.h"
#include "types.h"

int compte_taille_pile(struct elem *e);
void libere_actionJeu(ACTIONJEU a);
ACTIONJEU initialise_action_jeu(char *nom, int num);
ACTIONJEU modifie_interface_jeu(ACTIONJEU a);
ACTIONJEU joue_interface_jeu(ACTIONJEU a);

#endif
