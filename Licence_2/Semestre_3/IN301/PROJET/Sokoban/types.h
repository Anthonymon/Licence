// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// types.h du projet SOKOBAN
// Contient les constantes utilisées dans le projet SOKOBAN 

#ifndef __TYPES_H
#define __TYPES_H

// Constantes liées à l'affichage
#define CONST_ALEA 10
#define NB_CASES 30
#define TAILLE_CASES 22
#define LARGEUR_MARGE_INTERFACE_CREATION
#define LARGEUR_GARDE_CREA 100
#define LARGEUR_GARDE_JEU 50
#define LARGEUR_INTERFACE_CREA ((NB_CASES*TAILLE_CASES)+LARGEUR_GARDE_CREA)
#define HAUTEUR_INTERFACE_CREA (NB_CASES*TAILLE_CASES)
#define LARGEUR_INTERFACE_JEU  (NB_CASES*TAILLE_CASES)
#define HAUTEUR_INTERFACE_JEU ((NB_CASES*TAILLE_CASES)+LARGEUR_GARDE_JEU)

// Types possibles de natureCase dans la structure CASE
#define MUR 1
#define VIDE 2
#define EMPLACEMENT_CAISSE 3
// Types possibles de natureElem dans la structure CASE
#define PERSO 4
#define CAISSE 5
#define PAS_ELEMENT 6

// Constantes de mode et d'action
#define MODE_CREATIF 7
#define MODE_JEU 8
#define MODE_EDITION 9
#define MODE_RESOLUTION 11
#define MODE_QUITTER 12
#define MODE_SAUVEGARDER_RESOLUTION 13
#define MODE_SAUVEGARDER_EDITION 14
#define MODE_RECOMMENCER 15
#define MODE_ORDINATEUR 16

#define INDEFINI -1
#define HORS_ZONE 18
#define DANS_ZONE 19
#define CASE_TESTEE 20
#define CASE_NON_TESTEE 21
#define DEPLAC_POSSIB_1 23
#define DEPLAC_POSSIB_2 24
#define DEPLAC_POSSIB_3 25
#define PAS_DEPLAC_POSSIB 26

// Constantes de couleur
#define COUL_CAISSE_RANGEE forestgreen
#define COUL_CAISSE_NON_RANGEE saddlebrown
#define COUL_MUR slategray
#define COUL_PERSO navajowhite
#define COUL_VIDE ivory
#define COUL_EMPLACEMENT gold
#define COUL_JEU silver

#endif
