// ############################################
//       UVSQ -- Licence UFR des Sciences
//
// Licence Informatique : IN100, IN200, IN301, ...
// FSI -- Formation à la Science Informatique pour l'ISN
//
// Franck QUESSETTE -- Franck.Quessette@uvsq.fr
// Yann STROZECKI
// Pierre COUCHENEY
// Version de novembre 2016
//
// SOMMAIRE
//
// 1. TYPES, VARIABLES, CONSTANTES ... ligne  43
// 2. AFFICHAGE ...................... ligne 107
// 3. GESTION D'ÉVÉNEMENTS ........... ligne 133
// 4. DESSIN D'OBJETS ................ ligne 198
// 5. ÉCRITURE DE TEXTE .............. ligne 244
// 6. LECTURE D'ENTIER ............... ligne 288
// 7. GESTION DU TEMPS ............... ligne 297
// 8. VALEUR ALÉATOIRES .............. ligne 319
// 9. DIVERS ......................... ligne 330
// #############################################

#ifndef ___UVSQGRAPHICS_QST
#define ___UVSQGRAPHICS_QST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <SDL.h>

// A décommenter si on fonctionne sur un host puissant
// A laisser commenté si on est dans une machine virtuelle
#define EN_LOCAL

// #####################################
// 1. TYPES, VARIABLES, CONSTANTES (qst)
// #####################################

	// 1.1 TYPES

	// Définition du type POINT
	typedef struct point {int x,y;} POINT;

	// Définition du type COULEUR
	typedef Uint32 COULEUR;

	// Les booléens
	typedef int BOOL;
	
	// 1.2 VARIABLES
	// Taille de l'affichage
	int WIDTH;
	int HEIGHT;
#define HAUTEUR_FENETRE HEIGHT
#define LARGEUR_FENETRE WIDTH

	// 1.3 CONSTANTES
	// Déplacement minimal lorsque l'on utilise les flèches.
	#define MINDEP 1

	// Constantes de couleur
	#include <uvsqcouleur.h>

	// Constantes booléennes
	#define TRUE 1
	#define True 1
	#define true 1
	#define FALSE 0
	#define False 0
	#define false 0

	// Les caractères accentués en iso-8859, qui est utilisé par TTF_font
	#define agrave "\xe0"
	#define aacute "\xe1"
	#define acirc  "\xe2"
	#define auml   "\xe4"
	#define ccedil "\xe7"
	#define egrave "\xe8"
	#define eacute "\xe9"
	#define ecirc  "\xea"
	#define euml   "\xeb"
	#define icirc  "\xee"
	#define iuml   "\xef"
	#define ocirc  "\xf4"
	#define ugrave "\xf9"
	#define ucirc  "\xfb"
	#define uuml   "\xfc"
	#define Ccedil "\xc7"
	#define Egrave "\xc8"
	#define Eacute "\xc9"
	#define Ecirc  "\xca"

	// Encodage interne
	#define NORMAL   0x00
	#define GRAS     0x01
	#define ITALIQUE 0x02
	#define SOULIGNE 0x04

// ##################
// 2. AFFICHAGE (qst)
// ##################

	// 2.1 Initialisation de la fenêtre sur laquelle on dessine
	void init_graphics(int W, int H);

	// 2.2 Affichage automatique ou manuel
	// Si l'affichage est automatique, chaque objet dessiné
	// est automatiquement affiché.
	// Sinon, il faut explicitement appeler la fonction
	// affiche_all() pour afficher les objets
	// synchro() est identique à affiche_all()
	void affiche_auto_on();
	void affiche_auto_off();
	void affiche_all();
	void synchro();

	// 2.3 Création de couleur
	// r g et b dans l'intervalle 0 .. 255
	COULEUR couleur_RGB(int r, int g, int b);

	// 2.4 Affichage ou non du curseur de la souris
	void mouse_on();
	void mouse_off();

// ##################################
// 3. GESTION D'ÉVÉNEMENTS (qst + ys)
// ##################################

// 3.1 CLAVIER

	// 3.1.1 Renvoie le code ascii du caractère de la dernière touche 
	// du clavier qui a été pressée.
	// Si aucune touche n'a été pressée, renvoie -1
	// Fonction non bloquante.
	int get_key(); // Made by ys

	// 3.1.2 Attend que l'on tape Echap et quitte
	// Fonction bloquante
	void wait_escape();

	// 3.1.3 Renvoie le ou les flèches appuyées
	// sous forme d'un déplacement en 
	// x négatif = nombre d'appuis sur la flèche gauche
	// x positif = nombre d'appuis sur la flèche droite
	// y négatif = nombre d'appuis sur la flèche bas
	// y positif = nombre d'appuis sur la flèche haut
	// Fonction non bloquante, si aucune flèche n'a été
	// appuyée les champs x et y vaudront 0.
	POINT get_arrow();

// 3.2 SOURIS

	// 3.2.1 Renvoie la position de la souris
	POINT get_mouse();

	// 3.2.2 Attend que l'utilisateur clique avec le bouton gauche
	// Renvoie les coordonnées du point cliqué
	// Fonction bloquante
	POINT wait_clic();

	// 3.2.3 Attend que l'on clique et renvoie dans button le bouton cliqué :
	// *button vaut soit 'G' (pour Gauche), soit 'M' (pour milieu),
	// soit 'D' (pour Droit) en fonction du bouton cliqué
	// Fonction bloquante
	POINT wait_clic_GMD(char *button);

	// 3.2.4 Renvoie la position du dernier clic de souris.
	// Si le bouton gauche n'a pas été pressée, renvoie (-1,-1)
	// Fonction non bloquante.
	POINT get_clic(); // Made by ys

#define EST_RIEN   0
#define EST_FLECHE 1
#define EST_TOUCHE 2
#define EST_CLIC   3

#define FLECHE_GAUCHE 270
#define FLECHE_DROITE  90
#define FLECHE_DROIT FLECHE_DROITE
#define FLECHE_BAS 180
#define FLECHE_HAUTE 0
#define FLECHE_HAUT FLECHE_HAUTE

	// 3.2.5 Attend que l'on appuie soit sur une lettre, une flèche ou que l'on clique.
	// La fonction modifie la touche la flèche ou le point selon le premier événement qui arrive.
	// La fonction renvoie le type d'événement (touche, fleche ou point) 
	// Cette fonction est bloquante.
	int wait_key_arrow_clic (char *touche, int *fleche, POINT *P); // Made by qst & pc

// ########################
// 4. DESSIN D'OBJETS (qst)
// ########################
void affiche_image(char *nomfic, POINT bg, int w, int h);

	// 4.1 Remplissage de tout l'écran
	void fill_screen(COULEUR coul);

	// 4.2 Dessine un pixel
	void draw_pixel(POINT p, COULEUR coul);

	// 4.3 Dessine un segment
	void draw_line(POINT p1, POINT p2, COULEUR coul);

	// 4.4 Dessine un rectangle non rempli
	// Les deux points sont deux points quelconques 
	// non adjacents du rectangle
	void draw_rectangle(POINT p1, POINT p2, COULEUR coul);

	// 4.5 Dessine un rectangle rempli
	// Les deux point sont deux points quelconques 
	// non adjacents du rectangle
	void draw_fill_rectangle(POINT p1, POINT p2, COULEUR coul);

	// 4.6 Dessine un cercle non rempli
	void draw_circle(POINT centre, int rayon, COULEUR coul);

	// 4.7 Dessine un cercle rempli
	void draw_fill_circle(POINT centre, int rayon, COULEUR coul);

	// 4.8 Dessine des quarts de cercle
	void draw_circle_HD(POINT centre, int rayon, COULEUR coul);
	void draw_circle_BD(POINT centre, int rayon, COULEUR coul);
	void draw_circle_HG(POINT centre, int rayon, COULEUR coul);
	void draw_circle_BG(POINT centre, int rayon, COULEUR coul);

	// 4.9 Dessine une ellipse remplie, F1 et F2 sont les foyers
	void draw_fill_ellipse(POINT F1, POINT F2, int r, COULEUR coul);

	// 4.10 Dessine un triangle
	void draw_triangle(POINT p1, POINT p2, POINT p3, COULEUR coul);

	// 4.11 Dessine un triangle rempli
	void draw_fill_triangle(POINT p1, POINT p2, POINT p3, COULEUR coul);


// ##########################
// 5. ÉCRITURE DE TEXTE (qst)
// ##########################

	// 5.0 Fonctions générales
	// La largeur, en pixel, du texte
	int largeur_texte(char *a_ecrire, int taille);
	// La hauteur, en pixel, du texte
	int hauteur_texte(char *a_ecrire, int taille);

	// Permet de changer le style.
	// Les styles possibles sont : NORMAL, GRAS, ITALIQUE et SOULIGNE
	// Le style est appliqué jusqu'au prochain appel de la fonction
	void pol_style(int style);

	// 5.1 Affiche du texte avec
	// Le texte est passé dans l'argument "a_ecrire" 
	// la police est celle définie par la constante POLICE_NAME 
	// dans graphics.c
	// la taille est passée en argument
	// l'argument hg de type POINT est le point en haut à gauche
	// à partir duquel le texte s'affiche
	// la COULEUR coul passée en argument est la couleur d'affichage
	// Nécessite l'installation  de SDL_ttf.h
	void aff_pol(char *a_ecrire, int taille, POINT hg, COULEUR coul);
	// Idem ci-dessus mais en passant le point central et non plus en haut à gauche
	void aff_pol_centre(char *a_ecrire, int taille, POINT centre, COULEUR coul);

	// 5.2 Affiche un entier
	// Meme sémantique que aff_pol()
	void aff_int(int n, int taille, POINT hg, COULEUR coul);

	// 5.3 Affiche dans la fenêtre graphique comme dans une fenêtre
	// shell mais sans déroulement. Commence en haut et
	// se termine en bas.
	void write_text(char *a_ecrire);
	void write_int(int n);
	void write_float(float x);
	void write_bool(BOOL b);
	// Retour à la ligne
	void write_ln();
	// Pour compatibilité avec l'ancienne version
	void writeln();

// #########################
// 6. LECTURE D'ENTIER (qst)
// #########################

	// 6.1 Renvoie l'entier tapé au clavier.
	// Cette fonction est bloquante
	int lire_entier_clavier();


// #########################
// 7. GESTION DU TEMPS (qst)
// #########################

	// 7.1 Chronomètre élémentaire
	// Déclenchement du chrono
	// Le remet à zéro s'il était déjà lancé
	void chrono_start();
	// Renvoie la valeur du chrono et ne l'arrête pas
	float chrono_lap();
	
	// 7.2 Attend le nombre de millisecondes passé en argument
	void attendre(int millisecondes);

	// 7.3.1 Renvoie l'heure de l'heure courante
	int heure();
	// 7.3.2 Renvoie le nombre de minutes de l'heure courante
	int minute();
	// 7.3.3 Renvoie le nombre de secondes.microsecondes de l'heure courante
	float seconde();


// ##########################
// 8. VALEUR ALÉATOIRES (qst)
// ##########################

	// 8.1 Renvoie un float dans l'intervalle [0;1[
	float alea_float();
	// 8.2 Renvoie un int dans l'intervalle [0..N[
	// soit N valeurs différentes de 0 à N-1
	int alea_int(int N);


// ###############
// 9. DIVERS (qst)
// ###############

	// 9.1 Renvoie la distance entre deux points
	float distance(POINT P1, POINT P2);
#endif
