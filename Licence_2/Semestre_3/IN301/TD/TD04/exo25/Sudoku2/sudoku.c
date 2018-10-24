// sudoku.c du projet SUDOKU
// Le fichier principal qui contient le main et les fonctions de gestion du sudoku
// du projet SUDOKU

// Franck.Quessette@uvsq.fr
// Novembre 2016

#include <stdlib.h>
#include "sudoku.h"
#include "action.h"
#include "affichage.h"

// Initialise le sudoku à vide
SUDOKU initialiser_sudoku (){
	SUDOKU S;
	S.mode = JOUER;
	int x,y;
	for (x=0 ; x<N ; x++)
		for (y=0 ; y<N ; y++) {
			S.la_case[x][y].modifiable = 1;
			S.la_case[x][y].val = VIDE;
		}
	return S;
}


// Fonction qui calcule la solution du sudoku
SUDOKU resoudre_sudoku(SUDOKU S) {
	// A FINIR
	return S;
}

// Si v est dans la valeur de la case x, y de S,
// la fonction essaye les valeurs de v+1 à 9 et
// renvoie la première valeur qui est ni dans la ligne x ni dans la colonne y ni dans le bloc qui contient la case x,y
// Si aucune valeur n'est trouvée, elle renvoie 0
int valeur_suivante(SUDOKU S, int x, int y) {
	// A FINIR
	// Pour le moment on renvoie la valeur+1 sans vérifier ligne, colonne et bloc
	return (S.la_case[x][y].val + 1)%10;
}


// Modifie le sudoku en fonction de l'action
SUDOKU modifier_sudoku_action (SUDOKU S, ACTION A) {
	// CAS 1 : Clic sur un bouton : on change de mode 
	if (A.mode != GRILLE) { 
		S.mode = A.mode; 
		if (S.mode == RESOUDRE) S = resoudre_sudoku(S);
		return S; 
	}

	// CAS 2 : Clic dans la grille
	// Etape 1 : Si on est en mode SAISIR, on rend la la case  modifiable
	if (S.mode == SAISIR) S.la_case[A.x][A.y].modifiable = 1;
	// Etape 2 : Si la case est modifiable on la modifie
	if (S.la_case[A.x][A.y].modifiable) S.la_case[A.x][A.y].val = valeur_suivante(S,A.x,A.y);
	// Etape 3 : La case est non modifiable si on est en mode SAISIR et qu'elle n'est pas VIDE
	if ((S.mode == SAISIR) && (S.la_case[A.x][A.y].val != VIDE)) S.la_case[A.x][A.y].modifiable = 0;
	
	return S;
}


// Le main
int main() {
	SUDOKU S;
	ACTION A;
	initialiser_affichage();
	S = initialiser_sudoku();
	afficher_sudoku(S);
	do {
		A = recuperer_action();
		S = modifier_sudoku_action(S,A);
		afficher_sudoku(S);
	} while (mode_action(A) != QUITTER);
	//wait_escape();
	exit (0);
}	
