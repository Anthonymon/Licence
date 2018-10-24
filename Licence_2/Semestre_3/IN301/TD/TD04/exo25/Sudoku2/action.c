// action.c du projet SUDOKU
// gestion de l'interaction avec l'utilisateur

// Franck.Quessette@uvsq.fr
// Novembre 2016

#include "action.h"
#include <uvsqgraphics.h>
#include "constantes.h"

ACTION recuperer_action() {
	ACTION A;
	POINT P = wait_clic();
	if (P.y < N*TAILLE_CASE) {
		A.mode = GRILLE;
		A.x = P.x/TAILLE_CASE;
		A.y = P.y/TAILLE_CASE;
		return A;
	}
	if (P.x <   LARG_BOUTON) { A.mode = SAISIR;   return A; }
	if (P.x < 2*LARG_BOUTON) { A.mode = JOUER;    return A; }
	if (P.x < 3*LARG_BOUTON) { A.mode = RESOUDRE; return A; }
	A.mode = QUITTER; 
	return A;
}

int mode_action(ACTION A) {
	return A.mode;
}
