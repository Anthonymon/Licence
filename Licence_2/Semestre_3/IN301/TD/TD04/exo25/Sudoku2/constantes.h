// constantes.h du projet SUDOKU
// Franck.Quessette@uvsq.fr
// Novembre 2016

// Contient les constantes utilisées un peu partour dans le projet.

#ifndef ___CONSTANTES_H
#define ___CONSTANTES_H
// La taille du sudoku
#define N 9

// La valeur pour une case
#define VIDE 0

// Les actions et le mode
#define QUITTER  0
#define SAISIR   1
#define JOUER    2
#define RESOUDRE 3
#define GRILLE   4

// Constantes liées à l'affichage
#define TAILLE_CASE 40
#define LARG_BOUTON ((N*TAILLE_CASE)/4)
#define HAUT_BOUTON (TAILLE_CASE)
#define LARG_FENETRE (N*TAILLE_CASE)
#define HAUT_FENETRE (N*TAILLE_CASE + HAUT_BOUTON)
#define TAILLE_POLICE 20

// Les différentes couleurs
#define COUL_BORD tan
#define COUL_FOND antiquewhite
#define COUL_CHIFFRE sienna
#define COUL_CHIFFRE_NON_MODIFIABLE rouge

#endif
