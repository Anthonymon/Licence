// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// affichage.c du projet SOKOBAN
// Contient toutes les fonctions d'affichage

#include <uvsqgraphics.h>
#include "sokoban.h"
#include "action_crea.h"
#include "action_jeu.h"
#include "gestion_plateau.h"
#include "types.h"

// Initialise la fenetre graphique et le mode d'affichage dans l'interface de création
void initialise_affichage_interface_creation()
{
	init_graphics(LARGEUR_INTERFACE_CREA, HAUTEUR_INTERFACE_CREA);
	affiche_auto_off();
}

// Initialise la fenetre graphique et le mode d'affichage dans l'interface de jeu
void initialise_affichage_interface_jeu()
{
	init_graphics(LARGEUR_INTERFACE_JEU, HAUTEUR_INTERFACE_JEU);
	affiche_auto_off();
}

//Dessine des lignes verticales entre p1 et p2 espacées d'un "ecart" jusqu'à "largeur"
void dessine_lignes_verticales(POINT p1, POINT p2, int ecart, int largeur)
{
	POINT p3;
	p3.x = p1.x;
	p3.y = p2.y;
	draw_line(p1, p3, noir);
	while (p1.x < largeur) {
		p1.x = p3.x = p1.x + ecart;
		draw_line(p1, p3, noir);
	}
}

//Dessine des lignes horizontales entre p1 et p2 espacées d'un "ecart" jusqu'à "hauteur"
void dessine_lignes_horizontales(POINT p1, POINT p2, int ecart, int hauteur)
{
	POINT p3;
	p3.x = p2.x;
	p3.y = p1.x;
	while (p1.y < hauteur) {
		p1.y = p3.y = p1.y + ecart;
		draw_line(p1, p3, noir);
	}
}

// Affiche le quadrillage entre le point p1 et p2 pour le plateau
void affiche_quadrillage(POINT p1, POINT p2, int ecart)
{

	if (p1.x > p2.x) {	//intervertir si p1 n'est pas le point en bas à gauche
		POINT ptemp = p1;
		p1 = p2;
		p2 = ptemp;
	}
	int hauteur = p2.y;
	int largeur = p2.x;
	dessine_lignes_horizontales(p1, p2, ecart, hauteur);
	dessine_lignes_verticales(p1, p2, ecart, largeur);
}

// Dessine la croix sur le bouton
void dessine_bouton_croix(POINT p, COULEUR coul, int taille)
{
	POINT bg;
	POINT hd;
	bg.x = p.x - taille;
	bg.y = p.y - taille;
	hd.x = p.x + taille;
	hd.y = p.y + taille;
	draw_line(bg, hd, coul);
	int temp = bg.y;
	bg.y = hd.y;
	hd.y = temp;
	draw_line(bg, hd, coul);
}

// Dessine le carré sur le bouton
void dessine_bouton_carre(POINT p, COULEUR c, int taille)
{
	POINT bg;
	POINT hd;
	bg.x = p.x - taille;
	bg.y = p.y - taille;
	hd.x = p.x + taille;
	hd.y = p.y + taille;
	draw_fill_rectangle(bg, hd, c);
	draw_rectangle(bg, hd, black);
}

// Dessins des différents boutons pour l'interface de creation

void dessine_bouton_sauvegarde(POINT p, int taille)
{				//SAUVEGARDE
	dessine_bouton_carre(p, mediumslateblue, taille);
	POINT hg;
	hg.x = p.x - (taille / 1.5);
	hg.y = p.y + (taille * 1.4);	//ecrit bien centré dans le bouton de sauvegarde
	aff_pol("S", taille * 2, hg, black);
}

void dessine_bouton_recommencer(POINT p, int taille)
{				//RECOMMENCER
	dessine_bouton_carre(p, darkorange, taille);
	POINT hg;
	hg.x = p.x - (taille / 1.5);
	hg.y = p.y + (taille * 1.4);	//ecrit bien centré dans le bouton de sauvegarde
	aff_pol("R", taille * 2, hg, black);
}

void dessine_bouton_ordinateur(POINT p, int taille)
{				//ORDI
	dessine_bouton_carre(p, cyan, taille);
	POINT hg;
	hg.x = p.x - (taille / 1.5) - 2;
	hg.y = p.y + (taille * 1.4);	//ecrit bien centré dans le bouton Ordinateur
	aff_pol("O", taille * 2, hg, black);
}

//////////////////////////////

// Dessins des différents boutons pour l'interface de jeu

void dessine_bouton_undo()
{				//UNDO
	POINT p1, p2;
	p1.x = 0;
	p1.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	p2.x = LARGEUR_INTERFACE_JEU / 6;
	p2.y = HAUTEUR_INTERFACE_JEU;
	draw_fill_rectangle(p1, p2, white);
	draw_rectangle(p1, p2, black);
	p1.x = p1.x + 33;
	p1.y = p2.y - 2;
	aff_pol("UNDO", 15, p1, black);
}

void dessine_bouton_redo()
{				//REDO
	POINT p1, p2;
	p1.x = LARGEUR_INTERFACE_JEU / 6;
	p1.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	p2.x = 2 * LARGEUR_INTERFACE_JEU / 6;
	p2.y = HAUTEUR_INTERFACE_JEU;
	draw_fill_rectangle(p1, p2, white);
	draw_rectangle(p1, p2, black);
	p1.x = p1.x + 30;
	p1.y = p2.y - 2;
	aff_pol("REDO", 15, p1, black);
}

void dessine_bouton_init()
{				//INIT
	POINT p1, p2;
	p1.x = 2 * LARGEUR_INTERFACE_JEU / 6;
	p1.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	p2.x = 3 * LARGEUR_INTERFACE_JEU / 6;
	p2.y = HAUTEUR_INTERFACE_JEU;
	draw_fill_rectangle(p1, p2, forestgreen);
	draw_rectangle(p1, p2, black);
	p1.x = p1.x + 40;
	p1.y = p2.y - 2;
	aff_pol("INIT", 15, p1, black);
}

void dessine_bouton_precedent()
{				//PREC
	POINT p1, p2;
	p1.x = 3 * LARGEUR_INTERFACE_JEU / 6;
	p1.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	p2.x = 4 * LARGEUR_INTERFACE_JEU / 6;
	p2.y = HAUTEUR_INTERFACE_JEU;
	draw_fill_rectangle(p1, p2, white);
	draw_rectangle(p1, p2, black);
	p1.x = p1.x + 12;
	p1.y = p2.y - 2;
	aff_pol("PRECEDENT", 15, p1, black);
}

void dessine_bouton_suivant()
{				//SUIV
	POINT p1, p2;
	p1.x = 4 * LARGEUR_INTERFACE_JEU / 6;
	p1.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	p2.x = 5 * LARGEUR_INTERFACE_JEU / 6;
	p2.y = HAUTEUR_INTERFACE_JEU;
	draw_fill_rectangle(p1, p2, white);
	draw_rectangle(p1, p2, black);
	p1.x = p1.x + 17;
	p1.y = p2.y - 2;
	aff_pol("SUIVANT", 15, p1, black);
}

void dessine_bouton_quit()
{				//QUIT
	POINT p1, p2;
	p1.x = 5 * LARGEUR_INTERFACE_JEU / 6;
	p1.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	p2.x = LARGEUR_INTERFACE_JEU;
	p2.y = HAUTEUR_INTERFACE_JEU;
	draw_fill_rectangle(p1, p2, indianred);
	draw_rectangle(p1, p2, black);
	p1.x = p1.x + 35;
	p1.y = p2.y - 2;
	aff_pol("QUIT", 15, p1, black);
}

////////////////////////////////

// Dessins des différents types de cases du plateau

void dessine_case_vide(POINT p, int demiTaille)
{				//CASE VIDE
	POINT bg, hd;
	bg.x = p.x - demiTaille;
	bg.y = p.y - demiTaille;
	hd.x = p.x + demiTaille;
	hd.y = p.y + demiTaille;
	draw_fill_rectangle(hd, bg, COUL_VIDE);
	draw_rectangle(hd, bg, black);
}

void dessine_case_mur(POINT p, int demiTaille)
{				//MUR
	POINT bg, hd;
	bg.x = p.x - demiTaille;
	bg.y = p.y - demiTaille;
	hd.x = p.x + demiTaille;
	hd.y = p.y + demiTaille;
	draw_fill_rectangle(hd, bg, COUL_MUR);
	draw_rectangle(hd, bg, black);
}

void dessine_case_emplacement_caisse(POINT p, int demiTaille)
{				//CAISSE SUR UN EMPLACEMENT DE CAISSE
	POINT bg, hd;
	bg.x = p.x - demiTaille;
	bg.y = p.y - demiTaille;
	hd.x = p.x + demiTaille;
	hd.y = p.y + demiTaille;
	draw_fill_rectangle(hd, bg, COUL_EMPLACEMENT);
	draw_rectangle(hd, bg, black);
}

void dessine_case_perso(POINT p, int demiTaille)
{				//PERSO
	int taille = demiTaille - 5;
	draw_fill_circle(p, taille, COUL_PERSO);
	draw_circle(p, taille, black);
}

void dessine_case_caisse(POINT p, COULEUR c, int demiTaille)
{				//CAISSE PAS SUR UN EMPLACEMENT
	POINT bg, hd;
	bg.x = p.x - demiTaille;
	bg.y = p.y - demiTaille;
	hd.x = p.x + demiTaille;
	hd.y = p.y + demiTaille;
	draw_fill_rectangle(bg, hd, c);
	draw_rectangle(bg, hd, black);
	draw_line(bg, hd, black);
	bg.y = hd.y;
	hd.y = hd.y - demiTaille * 2;
	draw_line(bg, hd, black);
}

// Dessine la case avec natureCase=EMPLACEMENT_CAISSE
void dessine_case_nature_emplacement_caisse(POINT p, int x, int y, PLATEAU plat)
{
	if (plat.T[x][y].natureElem == PERSO) {	//si natureElem est un personnage
		dessine_case_emplacement_caisse(p, plat.tailleCases / 2);
		dessine_case_perso(p, plat.tailleCases / 2);
	}
	if (plat.T[x][y].natureElem == CAISSE) {	//si natureCase est une caisse
		dessine_case_caisse(p, COUL_CAISSE_RANGEE,
				    plat.tailleCases / 2);
	} else if (plat.T[x][y].natureElem == PAS_ELEMENT) {	//si il n'y a pas d'élément
		dessine_case_emplacement_caisse(p, plat.tailleCases / 2);
	}
}

// Dessine la case avec natureCase=VIDE
void dessine_case_nature_vide(POINT p, int x, int y, PLATEAU plat)
{
	if (plat.T[x][y].natureElem == PERSO) {	//si natureCase est un personnage
		dessine_case_vide(p, plat.tailleCases / 2);
		dessine_case_perso(p, plat.tailleCases / 2);
	} else if (plat.T[x][y].natureElem == CAISSE) {	//si natureCase est une caisse
		dessine_case_caisse(p, COUL_CAISSE_NON_RANGEE,
				    plat.tailleCases / 2);
	} else if (plat.T[x][y].natureElem == PAS_ELEMENT) {	//si il n'y a pas d'élément
		dessine_case_vide(p, plat.tailleCases / 2);
	}
}

/////////////////////

// Dessine la case en fonction du plateau ACTIONCREATION, du point central et de la case du plateau
void dessine_case(POINT p, int x, int y, PLATEAU plat)
{
	if (plat.T[x][y].natureCase == MUR) {
		dessine_case_mur(p, plat.tailleCases / 2);
	}

	else if (plat.T[x][y].natureCase == EMPLACEMENT_CAISSE) {
		dessine_case_nature_emplacement_caisse(p, x, y, plat);
	}

	else if (plat.T[x][y].natureCase == VIDE) {
		dessine_case_nature_vide(p, x, y, plat);
	}
}

// Ecrit sur le coté de l'écran dans quel mode on est (INTERFACE DE CREATION)
void affiche_info_nom_mode(ACTIONCREATION a)
{
	POINT p;
	p.x = 2;
	p.y = HAUTEUR_INTERFACE_CREA - 10;
	if (a.mode == MODE_EDITION) {
		aff_pol("MODE EDITION", 12, p, red);
	}
	p.x = 10;
	if (a.mode == MODE_RESOLUTION) {
		aff_pol("MODE RESOLUTION", 8, p, red);
	}
}

// Ecrit sur l'ecran le nom du fichier dans l'interface de jeu
void affiche_nom_fichier(ACTIONJEU a)
{
	POINT p;
	p.x = 10;
	p.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	aff_pol(a.nomFichier, 15, p, red);
}

// Ecrit sur l'ecran le nombre de coups actuel
void affiche_nombre_coups(ACTIONJEU a)
{
	POINT p;
	p.x = 220;
	p.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	aff_pol("NOMBRE DE COUPS : ", 15, p, red);
	p.x = 385;
	aff_int(a.h.redo->nbCoups, 15, p, red);
}

// Ecrit sur l'ecran le numero du niveau
void affiche_numero_niveau(ACTIONJEU a)
{
	POINT p;
	p.x = 540;
	p.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2;
	aff_pol("NIVEAU : ", 15, p, red);
	p.x = 615;
	aff_int(a.num, 15, p, red);
}

// Ecrit en très gros au milieu de l'écran "GAGNE"
void affiche_gagne()
{
	POINT p;
	p.x = 80;
	p.y = HAUTEUR_INTERFACE_JEU / 2 + 50;
	aff_pol("GAGNE", 120, p, darkgreen);
}

// Ecrit en très gros au milieu de l'écran "INJOUABLE"
void affiche_niveau_injouable()
{
	POINT p;
	p.x = 50;
	p.y = HAUTEUR_INTERFACE_JEU / 2 + 50;
	aff_pol("INJOUABLE", 100, p, firebrick);
}

// Affiche les boutons en fonction du plateau pour l'interface de création dans le mode resolution
void affiche_boutons_mode_resolution(ACTIONCREATION a)
{
	POINT p;
	p.x = 50;
	p.y = 5 * (HAUTEUR_INTERFACE_CREA / 6);
	dessine_bouton_recommencer(p, a.plat.tailleCases);

	if (teste_mode_resolution_sauvegardable(a.plat) == 1) {
		p.y = 4 * (HAUTEUR_INTERFACE_CREA / 6);
		dessine_bouton_sauvegarde(p, a.plat.tailleCases);
	}
	p.y = 3 * (HAUTEUR_INTERFACE_CREA / 6);
	dessine_bouton_ordinateur(p, a.plat.tailleCases);
}

// Affiche les boutons en fonction du plateau pour l'interface de création dans le mode edition
void affiche_boutons_mode_edition(ACTIONCREATION a)
{
	POINT p;
	p.x = 50;
	//si le niveau est sauvegardable (si l'entrepot est fermé et que le perso est à l'interieur)
	if (teste_mode_edition_sauvegardable(a.plat) == 1) {
		p.y = 4 * (HAUTEUR_INTERFACE_CREA / 6);
		dessine_bouton_sauvegarde(p, a.plat.tailleCases);
	}
}

// Affichage général les boutons en fonction du mode dans l'interface de création
void affiche_boutons_interface_creation(ACTIONCREATION a)
{
	if (a.mode == MODE_EDITION) {
		affiche_boutons_mode_edition(a);
	}
	if (a.mode == MODE_RESOLUTION) {
		affiche_boutons_mode_resolution(a);
	}
	affiche_info_nom_mode(a);
}

// Affiche les boutons dans l'interface de jeu
void affiche_boutons_interface_jeu(ACTIONJEU a)
{
	if ((compte_taille_pile(a.h.redo) >= 2)
	    && (!teste_niveau_gagne(a.h.redo->p))) {
		dessine_bouton_undo();
	}
	if ((compte_taille_pile(a.h.undo) >= 1)
	    && (!teste_niveau_gagne(a.h.redo->p))) {
		dessine_bouton_redo();
	}
	if (compte_taille_pile(a.h.redo) >= 2) {
		dessine_bouton_init();
	}
	if (a.num != 1)
		dessine_bouton_precedent();
	if (a.num != a.niveauMax)
		dessine_bouton_suivant();
	dessine_bouton_quit();
}

// Affiche le nom du fichier, le nombre de coups et le numero du niveau dans l'interface de jeu
void affiche_informations_interface_jeu(ACTIONJEU a)
{
	POINT p1, p2;
	p1.x = 0;
	p1.y = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU;
	p2.x = LARGEUR_INTERFACE_JEU;
	p2.y = HAUTEUR_INTERFACE_JEU;
	draw_fill_rectangle(p1, p2, white);
	draw_rectangle(p1, p2, black);
	affiche_nom_fichier(a);
	affiche_nombre_coups(a);
	affiche_numero_niveau(a);
	if (teste_niveau_gagne(a.h.redo->p))
		affiche_gagne();
	if (!teste_niveau_jouable(a.h.redo->p))
		affiche_niveau_injouable();
}

// Affiche le plateau en fonction du contenu de a.plat
void affiche_plateau_creation(ACTIONCREATION a)
{
	int abscisse, ordonnee;
	POINT p;
	for (abscisse = 0; abscisse < a.plat.nbCases; abscisse++) {
		for (ordonnee = 0; ordonnee < a.plat.nbCases; ordonnee++) {
			p.x =
			    abscisse * a.plat.tailleCases + LARGEUR_GARDE_CREA +
			    (a.plat.tailleCases / 2);
			p.y =
			    (ordonnee * a.plat.tailleCases +
			     (a.plat.tailleCases / 2));
			dessine_case(p, abscisse, ordonnee, a.plat);
		}
	}
}

// Affiche le plateau en fonction du contenu du dernier élément de la pile redo de ACTIONJEU
void affiche_plateau_jeu(ACTIONJEU a)
{
	int abscisse, ordonnee;
	int nbCases = a.h.redo->p.nbCases;
	int taille = LARGEUR_INTERFACE_JEU / nbCases;
	POINT p;
	for (abscisse = 0; abscisse < nbCases; abscisse++) {
		for (ordonnee = 0; ordonnee < nbCases; ordonnee++) {
			p.x = abscisse * taille + taille / 2;
			p.y = ordonnee * taille + taille / 2;
			dessine_case(p, abscisse, ordonnee, a.h.redo->p);
		}
	}
}

// Affiche l'interface de création
void affiche_interface_creation(ACTIONCREATION a)
{
	POINT bg, hd;
	bg.x = LARGEUR_GARDE_CREA;
	bg.y = 0;
	hd.x = LARGEUR_INTERFACE_CREA;
	hd.y = HAUTEUR_INTERFACE_CREA;

	fill_screen(COUL_JEU);
	affiche_quadrillage(bg, hd, TAILLE_CASES);
	affiche_boutons_interface_creation(a);
	affiche_plateau_creation(a);
	affiche_all();
}

// Affiche l'interface de jeu 
void affiche_interface_jeu(ACTIONJEU a)
{
	POINT bg, hd;
	bg.x = 0;
	bg.y = 0;
	hd.x = HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU;
	hd.y = LARGEUR_INTERFACE_JEU;

	fill_screen(COUL_JEU);
	affiche_plateau_jeu(a);
	affiche_quadrillage(bg, hd,
			    LARGEUR_INTERFACE_JEU / a.h.redo->p.nbCases);
	affiche_informations_interface_jeu(a);
	affiche_boutons_interface_jeu(a);
	affiche_all();
}
