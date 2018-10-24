// action.h du projet SUDOKU
// gestion de l'interaction avec l'utilisateur

// Franck.Quessette@uvsq.fr
// Novembre 2016

#ifndef ___ACTIONS_H
#define ___ACTIONS_H

// Une action est définie par la région cliquée qui donne le mode 
// et si on est dans la grille on a les coordéonnées x et y.
// Ces coordonnées sont les numéros des case et la les numéros des pixels
struct action {
	int mode;
	int x,y;
};

typedef struct action ACTION;

// Attend un clic et renvoie l'action associée
ACTION recuperer_action();

// Récupère le mode de l'action
int mode_action(ACTION A);

#endif
