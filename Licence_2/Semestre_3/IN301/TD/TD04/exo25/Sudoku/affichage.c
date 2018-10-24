// affichage.c du projet SUDOKU
// Contient les fonctions liées à l'affichage

// Franck.Quessette@uvsq.fr
// Novembre 2016

#include <uvsqgraphics.h>
#include "affichage.h"
#include "constantes.h"
#include "sudoku.h"


// Initialise la fenêtre graphique et le mode d'affichage
void initialiser_affichage() {
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	affiche_auto_off();
}


// Affiche le contenu d'une case de la grille
void afficher_une_case(SUDOKU S, int x, int y) {
	POINT bg, hd, centre;
	bg.x = x*TAILLE_CASE;      bg.y = y*TAILLE_CASE;
	hd.x = bg.x + TAILLE_CASE; hd.y = bg.y + TAILLE_CASE;
	centre.x = (bg.x+hd.x)/2;     centre.y = (bg.y+hd.y)/2;
	draw_fill_rectangle(bg,hd,COUL_FOND);
	draw_rectangle(bg,hd,COUL_BORD);
	// Si la case vaut 0 c'est qu'elle est vide
	if (S.la_case[x][y].val != VIDE) {
		char texte[8];
		sprintf(texte,"%d",S.la_case[x][y].val);
		COULEUR coul_ch = COUL_CHIFFRE;
		if ( ! S.la_case[x][y].modifiable ) {
			coul_ch = COUL_CHIFFRE_NON_MODIFIABLE;
			pol_style(GRAS);
		}
		aff_pol_centre(texte,TAILLE_POLICE,centre,coul_ch);
		pol_style(NORMAL);
	}
}

void dessine_gros_traits_verticaux(POINT p1,POINT p2){
	POINT pTemp1,pTemp2;
	pTemp1.x=p1.x-1;pTemp1.y=p1.y;
	pTemp2.x=p2.x-1;pTemp2.y=p2.y;
	draw_line(p1,p2,noir);
	draw_line(pTemp1,pTemp2,noir);
}

void dessine_gros_traits_horizontaux(POINT p1,POINT p2){
	POINT pTemp1,pTemp2;
	pTemp1.x=p1.x;pTemp1.y=p1.y-1;
	pTemp2.x=p2.x;pTemp2.y=p2.y-1;
	draw_line(p1,p2,noir);
	draw_line(pTemp1,pTemp2,noir);
}


// Affiche en gros les trois qui séparent les blocs
void affiche_gros_traits() {
	POINT p1;POINT p2;
	p1.x=TAILLE_CASE*3;p1.y=0;
	p2.x=TAILLE_CASE*3;p2.y=TAILLE_CASE*9;
	dessine_gros_traits_verticaux(p1,p2);
	p1.x=TAILLE_CASE*6;p1.y=0;
	p2.x=TAILLE_CASE*6;p2.y=TAILLE_CASE*9;
	dessine_gros_traits_verticaux(p1,p2);
	
	p1.x=0;p1.y=TAILLE_CASE*3;
	p2.x=TAILLE_CASE*9;p2.y=TAILLE_CASE*3;
	dessine_gros_traits_horizontaux(p1,p2);
	p1.x=0;p1.y=TAILLE_CASE*6;
	p2.x=TAILLE_CASE*9;p2.y=TAILLE_CASE*6;
	dessine_gros_traits_horizontaux(p1,p2);
}


// Affiche la grille
void afficher_grille(SUDOKU S) {
	int x,y;
	for (x=0 ; x<N ; x++)
		for (y=0 ; y<N ; y++) afficher_une_case(S,x,y);
	affiche_gros_traits();
}


// Affiche un bouton
// numero donne le rang du bouton en les comptant à partir de la gauche et à partir de 0
// texte est le texte dans le bouton
// la_selection vaut 1 si c'est le mode actif et 0 sinon
void afficher_un_bouton(int numero, char *texte, int la_selection) {
	// rouge si c'est le bouton actif et noir sinon
	COULEUR coul_texte = la_selection*rouge + (1 - la_selection)*noir;

	POINT bg, hd, centre;
	bg.x = numero*LARG_BOUTON; bg.y = HAUT_FENETRE-HAUT_BOUTON;
	hd.x = bg.x + LARG_BOUTON; hd.y = bg.y + HAUT_BOUTON;
	centre.x = (bg.x+hd.x)/2;  centre.y = (bg.y+hd.y)/2;

	draw_fill_rectangle(bg,hd,COUL_FOND);
	draw_rectangle(bg,hd,COUL_BORD);
	aff_pol_centre(texte,TAILLE_POLICE,centre,coul_texte);
}


// Affiche les 4 boutons
void afficher_les_boutons(SUDOKU S) {
	// Le 3ème argument vaut 0 ou 1 selon que c'est le mode actif ou non
	afficher_un_bouton(0,"SAISIR", S.mode==SAISIR);
	afficher_un_bouton(1,"JOUER",  S.mode==JOUER);
	afficher_un_bouton(2,"SOLVE",  S.mode==RESOUDRE);
	afficher_un_bouton(3,"QUITTER",S.mode==QUITTER);
}


// Affiche l'ensemble du sudoku
void afficher_sudoku(SUDOKU S) {
	fill_screen(noir);
	afficher_grille(S);
	afficher_les_boutons(S);
	affiche_all();
}
