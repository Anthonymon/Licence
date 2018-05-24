// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// sokoban.h du projet SOKOBAN
// Contient les structures du sokoban utilisées partout dans le projet

#include "types.h"

#ifndef __SOKOBAN_H
#define __SOKOBAN_H

struct casePlateau {
	int natureCase;		//MUR ou VIDE ou EMPLACEMENT_CAISSE
	int natureElem;		//PERSO ou CAISSE ou PAS_ELEMENT
};
typedef struct casePlateau CASE;

struct positionPerso {
	int x;
	int y;
};
typedef struct positionPerso POSITIONPERSO;

struct plateau {
	CASE **T;
	POSITIONPERSO posPerso;
	int nbCases;
	int tailleCases;
};
typedef struct plateau PLATEAU;

struct elem {
	PLATEAU p;
	int nbCoups;
	struct elem *suiv;
};

struct historique {
	struct elem *redo;
	struct elem *undo;
};
typedef struct historique HISTORIQUE;

struct actionCreation {
	int mode;		// MODE_EDITION ou MODE_RESOLUTION
	char *nomFichier;
	PLATEAU plat;
};
typedef struct actionCreation ACTIONCREATION;

struct actionJeu {
	int mode;		//MODE_JEU ou MODE_QUITTER
	char *nomFichier;
	int num;
	int niveauMax;
	HISTORIQUE h;
};
typedef struct actionJeu ACTIONJEU;

#endif
