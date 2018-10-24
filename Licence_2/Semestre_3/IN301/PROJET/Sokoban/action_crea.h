// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// action_crea.h du projet SOKOBAN
// Contient toute la gestion de l'interaction avec l'utilisateur pour le mode creation

#ifndef __ACTION_CREA_H
#define __ACTION_CREA_H

#include <uvsqgraphics.h>
#include "sokoban.h"
#include "types.h"

void libere_actionCreation(ACTIONCREATION a);
ACTIONCREATION initialise_action_crea(char *s);
ACTIONCREATION modifie_interface_creation(ACTIONCREATION a);
ACTIONCREATION joue_interface_creation(ACTIONCREATION a);

#endif
