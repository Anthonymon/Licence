// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// action_crea.c du projet SOKOBAN
// Contient toute la gestion de l'interaction avec l'utilisateur
// Initialisation de la structure, Modification des boutons et des cases, Fonctions de déplacement, Modification de la structure

#include <uvsqgraphics.h>
#include "action_crea.h"
#include "lire_ecrire.h"
#include "affichage.h"
#include "gestion_plateau.h"
#include "types.h"

// Libère la mémoire réservée pour la structure ACTIONCREATION (plateau et nom de la structure)
void libere_actionCreation(ACTIONCREATION a)
{
	libere_plateau(a.plat);
	free(a.nomFichier);
}

// Initialise le plateau de création VIDE (natureCase) PAS_ELEMENT (natureElem)
PLATEAU initialise_plateau_creation()
{
	PLATEAU p;
	p.posPerso.x = p.posPerso.y = INDEFINI;
	p.nbCases = NB_CASES;
	p.tailleCases = TAILLE_CASES;
	int x;			//allocation de la mémoire
	p.T = malloc(p.nbCases * sizeof(CASE *));
	if (p.T == NULL)
		quitte_probleme_memoire();
	for (x = 0; x < p.nbCases; x++) {
		p.T[x] = malloc(p.nbCases * sizeof(CASE));
		if (p.T[x] == NULL)
			quitte_probleme_memoire();
	}
	p = remplit_plateau_vide(p);	//initialisation à vide du plateau
	return p;
}

// Initialise la structure ACTIONCREATION
ACTIONCREATION initialise_action_crea(char *s)
{
	ACTIONCREATION a;
	a.mode = MODE_EDITION;
	a.nomFichier = s;
	a.plat = initialise_plateau_creation();
	return a;
}

// Renvoie le mode que l'utilisateur a choisi par le clic
int calcul_bouton_clic_mode_resolution(ACTIONCREATION a, POINT p)
{
	if ((p.y > ((5 * HAUTEUR_INTERFACE_CREA / 6) - a.plat.tailleCases))) {
		return MODE_RECOMMENCER;
	} else if ((p.y > (4 * HAUTEUR_INTERFACE_CREA / 6) - a.plat.tailleCases)
		   && (p.y <
		       (4 * HAUTEUR_INTERFACE_CREA / 6) + a.plat.tailleCases)) {
		return MODE_SAUVEGARDER_RESOLUTION;
	} else
		return MODE_ORDINATEUR;
}

// Renvoie le mode que l'utilisateur a choisi
int retourne_bouton_clique(POINT p, ACTIONCREATION a)
{
	while (teste_clic_bouton(p, a) == HORS_ZONE) {	//Tant que le clic n'est pas sur un bouton potentiel on attend un clic
		p = wait_clic();
	}
	if (a.mode == MODE_EDITION) {
		return MODE_SAUVEGARDER_EDITION;
	} else
		return calcul_bouton_clic_mode_resolution(a, p);
}

// Fonctions qui change la case en argument en un certain élément dans l'interface de création
// Utilisable lors du choix des éléments dans le plateau à créer

ACTIONCREATION change_case_mur(ACTIONCREATION a, int x, int y)
{				//change en mur
	a.plat.T[x][y].natureCase = MUR;
	a.plat.T[x][y].natureElem = PAS_ELEMENT;
	return a;
}

ACTIONCREATION change_case_caisse_rangee(ACTIONCREATION a, int x, int y)
{				//change en caisse sur une position de rangement
	a.plat.T[x][y].natureCase = EMPLACEMENT_CAISSE;
	a.plat.T[x][y].natureElem = CAISSE;
	return a;
}

ACTIONCREATION change_case_perso(ACTIONCREATION a, int x, int y)
{				//change en personnage
	a.plat.T[x][y].natureCase = VIDE;
	a.plat.T[x][y].natureElem = PERSO;
	a.plat.posPerso.x = x;
	a.plat.posPerso.y = y;
	return a;
}

ACTIONCREATION change_case_vide(ACTIONCREATION a, int x, int y)
{				//change en case vide
	a.plat.T[x][y].natureCase = VIDE;
	a.plat.T[x][y].natureElem = PAS_ELEMENT;
	return a;
}

//////////////////////

// Gère la gestion des changements de nature des cases que l'utilisateur a choisi
// Clic par intermitence sur une case : VIDE->MUR->CAISSE->PERSO->VIDE ...
ACTIONCREATION modifie_mode_edition_plateau(ACTIONCREATION a, POINT p)
{
	int x, y;
	x = calcul_X_crea(p, a);
	y = calcul_Y_crea(p, a);
	if ((a.plat.T[x][y].natureCase == VIDE)
	    && (a.plat.T[x][y].natureElem == PAS_ELEMENT)) {
		a = change_case_mur(a, x, y);
	} else if ((a.plat.T[x][y].natureCase == MUR)
		   && (a.plat.T[x][y].natureElem == PAS_ELEMENT)) {
		a = change_case_caisse_rangee(a, x, y);
	} else if ((a.plat.T[x][y].natureCase == EMPLACEMENT_CAISSE)
		   && (a.plat.T[x][y].natureElem == CAISSE)) {
		if (teste_possibilite_poser_perso(a.plat)) {
			a = change_case_perso(a, x, y);
		} else
			a = change_case_vide(a, x, y);
	} else if ((a.plat.T[x][y].natureCase == VIDE)
		   && (a.plat.T[x][y].natureElem == PERSO)) {
		a.plat.posPerso.x = INDEFINI;
		a.plat.posPerso.y = INDEFINI;
		a = change_case_vide(a, x, y);
	}
	return a;
}

// Modifie ACTIONCREATION dans le MODE_EDITION en fonction des actions de l'utilisateur
ACTIONCREATION modifie_mode_edition(ACTIONCREATION a)
{
	POINT p = wait_clic();
	if (teste_clic_sur_plateau(p)) {
		a = modifie_mode_edition_plateau(a, p);
	} else {
		if ((p.y >
		     (4 * HAUTEUR_INTERFACE_CREA / 6) - a.plat.tailleCases)
		    && (p.y <
			(4 * HAUTEUR_INTERFACE_CREA / 6) +
			a.plat.tailleCases)) {
			if (teste_mode_edition_sauvegardable(a.plat)) {
				a.mode = MODE_RESOLUTION;
			}
		}
	}
	return a;
}

// Fonctions de modification des champs de ACTIONCREATION en fonction des boutons cliqués

// Change le MODE_EDITION en MODE_RESOLUTION dans l'interface de création
ACTIONCREATION action_bouton_sauvegarder_edition(ACTIONCREATION a, POINT p)
{
	a.mode = MODE_RESOLUTION;
	return a;
}

ACTIONCREATION action_bouton_sauvegarder_resolution(ACTIONCREATION a)
{				// passe du MODE _RESOLUTION au MODE_QUITTER : SAUVEGARDER
	a.mode = MODE_QUITTER;
	return a;
}

ACTIONCREATION recommencer_mode_edition(ACTIONCREATION a)
{				// change les cases quand on a cliqué sur RECOMMENCER
	int x, y;
	for (x = 0; x < a.plat.nbCases; x++) {
		for (y = 0; y < a.plat.nbCases; y++) {
			//on supprime les caisses non placées correctement
			if ((a.plat.T[x][y].natureCase == VIDE)
			    && (a.plat.T[x][y].natureElem == CAISSE)) {
				a.plat.T[x][y].natureElem = PAS_ELEMENT;
			}
			//on remet toutes les caisses sur leurs emplacements
			if (a.plat.T[x][y].natureCase == EMPLACEMENT_CAISSE) {
				a.plat.T[x][y].natureElem = CAISSE;
			}
		}
	}
	return a;
}

ACTIONCREATION action_bouton_recommencer(ACTIONCREATION a)
{				// passe du MODE_RESOLUTION au MODE_EDITION
	a = recommencer_mode_edition(a);
	a.mode = MODE_EDITION;
	return a;
}

/////////////////////////////

// Renvoie une valeur aléatoire entre 0 et 2 mais avec une exception "a" qui est en paramètre
int renvoie_val_alea_except(int a)
{				// utile pour le déplacement aléatoire des caisses
	int x = alea_int(3);
	while (x == -a) {
		x = alea_int(3);
	}			// 0 BAS,1 HAUT, 2 GAUCHE, 3 DROITE
	return x;
}

// Fonctions qui teste si on peut se déplacer dans une certaine direction
// il faut que les deux cases de l'axe soient libres (car le personnage doit pouvoir pousser la caisse à l'endroit)

int teste_deplace_possible_bas(ACTIONCREATION a, int x, int y)
{				// teste vers le bas
	if ((y == 0) || (y == 1))
		return 0;
	if ((a.plat.T[x][y - 1].natureCase == VIDE)
	    && (a.plat.T[x][y - 1].natureElem == PAS_ELEMENT)) {
		if ((a.plat.T[x][y - 2].natureCase == VIDE)
		    && (a.plat.T[x][y - 2].natureElem == PAS_ELEMENT)) {
			return 1;
		}
	}
	return 0;
}

int teste_deplace_possible_haut(ACTIONCREATION a, int x, int y)
{				// teste vers le haut
	if ((y % a.plat.nbCases == a.plat.nbCases - 1)
	    || (y % a.plat.nbCases == a.plat.nbCases - 2))
		return 0;
	if ((a.plat.T[x][y + 1].natureCase == VIDE)
	    && (a.plat.T[x][y + 1].natureElem == PAS_ELEMENT)) {
		if ((a.plat.T[x][y + 2].natureCase == VIDE)
		    && (a.plat.T[x][y + 2].natureElem == PAS_ELEMENT)) {
			return 1;
		}
	}
	return 0;
}

int teste_deplace_possible_gauche(ACTIONCREATION a, int x, int y)
{				// teste vers la gauche
	if ((x == 0) || (x == 1))
		return 0;
	if ((a.plat.T[x - 1][y].natureCase == VIDE)
	    && (a.plat.T[x - 1][y].natureElem == PAS_ELEMENT)) {
		if ((a.plat.T[x - 2][y].natureCase == VIDE)
		    && (a.plat.T[x - 2][y].natureElem == PAS_ELEMENT)) {
			return 1;
		}
	}
	return 0;
}

int teste_deplace_possible_droite(ACTIONCREATION a, int x, int y)
{				// test vers la droite
	if ((x % a.plat.nbCases == a.plat.nbCases - 1)
	    || (x % a.plat.nbCases == a.plat.nbCases - 2))
		return 0;
	if ((a.plat.T[x + 1][y].natureCase == VIDE)
	    && (a.plat.T[x + 1][y].natureElem == PAS_ELEMENT)) {
		if ((a.plat.T[x + 2][y].natureCase == VIDE)
		    && (a.plat.T[x + 2][y].natureElem == PAS_ELEMENT)) {
			return 1;
		}
	}
	return 0;
}

/////////////////////////

// Fonction qui fait le déplacement aléatoire des cases pour le MODE_RESOLUTION à l'envers
ACTIONCREATION deplace_alea_caisse(ACTIONCREATION a, int x, int y)
{
	int alea;
	int xx = x;
	int yy = y;
	int compteur = 0;
	if ((a.plat.T[xx][yy].natureCase == EMPLACEMENT_CAISSE)
	    && (a.plat.T[xx][yy].natureElem == CAISSE)) {
		alea = renvoie_val_alea_except(-1);
		while (compteur < CONST_ALEA) {
			alea = renvoie_val_alea_except(alea);
			if ((alea == 0)
			    && (teste_deplace_possible_bas(a, xx, yy))) {
				a.plat.T[xx][yy].natureElem = PAS_ELEMENT;
				yy--;
				a.plat.T[xx][yy].natureElem = CAISSE;
			}
			if ((alea == 1)
			    && (teste_deplace_possible_haut(a, xx, yy))) {
				a.plat.T[xx][yy].natureElem = PAS_ELEMENT;
				yy++;
				a.plat.T[xx][yy].natureElem = CAISSE;
			}
			if ((alea == 2)
			    && (teste_deplace_possible_gauche(a, xx, yy))) {
				a.plat.T[xx][yy].natureElem = PAS_ELEMENT;
				xx--;
				a.plat.T[xx][yy].natureElem = CAISSE;
			}
			if ((alea == 3)
			    && (teste_deplace_possible_droite(a, xx, yy))) {
				a.plat.T[xx][yy].natureElem = PAS_ELEMENT;
				xx++;
				a.plat.T[xx][yy].natureElem = CAISSE;
			}
			compteur++;
		}
	}
	return a;
}

// Modifie le plateau avec un déplacement aléatoires des caisses (MODE_RESOLUTION) : ORDINATEUR
ACTIONCREATION action_bouton_ordinateur(ACTIONCREATION a)
{
	int x, y;
	for (x = 0; x < a.plat.nbCases; x++) {
		for (y = 0; y < a.plat.nbCases; y++) {
			a = deplace_alea_caisse(a, x, y);
		}
	}
	return a;
}

// Fonction de modification de ACTIONCREATION en fonction des clics de l'utilisateur : MODE_RESOLUTION
ACTIONCREATION modifie_mode_resolution_clic(ACTIONCREATION a, POINT p)
{
	if (teste_clic_sur_plateau(p) == 1) {
		return a;
	}
	if (teste_clic_bouton(p, a) == HORS_ZONE) {
		return a;
	}
	if (retourne_bouton_clique(p, a) == MODE_SAUVEGARDER_RESOLUTION) {	//si le bouton cliqué est le bouton de SAUVEGARDE
		a = action_bouton_sauvegarder_resolution(a);
	}
	if (retourne_bouton_clique(p, a) == MODE_RECOMMENCER) {	//si le buton cliqué est le bouton pour RECOMMENCER
		a = action_bouton_recommencer(a);
	}
	if (retourne_bouton_clique(p, a) == MODE_ORDINATEUR) {	//si le bouton cliqué est le bouton de JOUER A L'ENVERS PAR L'ORDINATEUR
		a = action_bouton_ordinateur(a);
	}
	return a;
}

// Fonctions pour permettre au joueur de gérer les actions du personnage à l'envers dans l'interface de création

ACTIONCREATION modifie_a_lenvers_fleche_gauche(ACTIONCREATION a)
{				// flèche gauche
	if (a.plat.posPerso.x % a.plat.nbCases != 0) {	//Cas particulier si le perso est sur le bord gauche
		//si a gauche du perso n'est pas un mur et qu'il n'y a pas d'élément
		if ((a.plat.T[a.plat.posPerso.x - 1][a.plat.posPerso.y].
		     natureCase != MUR)
		    && (a.plat.T[a.plat.posPerso.x - 1][a.plat.posPerso.y].
			natureElem != CAISSE)) {
			a.plat.T[a.plat.posPerso.x -
				 1][a.plat.posPerso.y].natureElem = PERSO;
			a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y].
			    natureElem = PAS_ELEMENT;
			a.plat.posPerso.x = a.plat.posPerso.x - 1;
			//tire la caisse a cote si il y en a une
			if (a.plat.T[a.plat.posPerso.x +
				     2][a.plat.posPerso.y].natureElem ==
			    CAISSE) {
				a.plat.T[a.plat.posPerso.x +
					 2][a.plat.posPerso.y].natureElem =
				    PAS_ELEMENT;
				a.plat.T[a.plat.posPerso.x +
					 1][a.plat.posPerso.y].natureElem =
				    CAISSE;
			}
		}
	}
	return a;
}

ACTIONCREATION modifie_a_lenvers_fleche_droite(ACTIONCREATION a)
{				// flèche droite
	if (a.plat.posPerso.x % a.plat.nbCases != a.plat.nbCases - 1) {	//Cas particulier si le perso est sur le bord droit
		//si a droite du perso n'est pas un mur et qu'il n'y a pas d'élément
		if ((a.plat.T[a.plat.posPerso.x + 1][a.plat.posPerso.y].
		     natureCase != MUR)
		    && (a.plat.T[a.plat.posPerso.x + 1][a.plat.posPerso.y].
			natureElem != CAISSE)) {
			a.plat.T[a.plat.posPerso.x +
				 1][a.plat.posPerso.y].natureElem = PERSO;
			a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y].
			    natureElem = PAS_ELEMENT;
			a.plat.posPerso.x = a.plat.posPerso.x + 1;
			//tire la caisse a cote si il y en a une
			if (a.plat.T[a.plat.posPerso.x -
				     2][a.plat.posPerso.y].natureElem ==
			    CAISSE) {
				a.plat.T[a.plat.posPerso.x -
					 2][a.plat.posPerso.y].natureElem =
				    PAS_ELEMENT;
				a.plat.T[a.plat.posPerso.x -
					 1][a.plat.posPerso.y].natureElem =
				    CAISSE;
			}
		}
	}
	return a;
}

ACTIONCREATION modifie_a_lenvers_fleche_bas(ACTIONCREATION a)
{				// flèche du bas
	if (a.plat.posPerso.y % a.plat.nbCases != 0) {	//Cas particulier si le perso est sur le bord bas
		if ((a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y - 1].
		     natureCase != MUR)
		    && (a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y - 1].
			natureElem != CAISSE)) {
			a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y -
						    1].natureElem = PERSO;
			a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y].
			    natureElem = PAS_ELEMENT;
			a.plat.posPerso.y = a.plat.posPerso.y - 1;
			if (a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y +
							2].natureElem ==
			    CAISSE) {
				a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y +
							    2].natureElem =
				    PAS_ELEMENT;
				a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y +
							    1].natureElem =
				    CAISSE;
			}
		}
	}
	return a;
}

ACTIONCREATION modifie_a_lenvers_fleche_haut(ACTIONCREATION a)
{				//flèche du haut
	if (a.plat.posPerso.y % a.plat.nbCases != a.plat.nbCases - 1) {	//Cas particulier si le perso est sur le bord haut
		if ((a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y + 1].
		     natureCase != MUR)
		    && (a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y + 1].
			natureElem != CAISSE)) {
			a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y +
						    1].natureElem = PERSO;
			a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y].
			    natureElem = PAS_ELEMENT;
			a.plat.posPerso.y = a.plat.posPerso.y + 1;
			if (a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y -
							2].natureElem ==
			    CAISSE) {
				a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y -
							    2].natureElem =
				    PAS_ELEMENT;
				a.plat.T[a.plat.posPerso.x][a.plat.posPerso.y -
							    1].natureElem =
				    CAISSE;
			}
		}
	}
	return a;
}

// Fonction qui modifie le plateau lors des déplacements du personnage a l'envers avec les flèches
ACTIONCREATION modifie_mode_resolution_fleche(ACTIONCREATION a, int touch)
{
	if (touch == FLECHE_GAUCHE) {
		a = modifie_a_lenvers_fleche_gauche(a);
	}
	if (touch == FLECHE_DROITE) {
		a = modifie_a_lenvers_fleche_droite(a);
	}
	if (touch == FLECHE_BAS) {
		a = modifie_a_lenvers_fleche_bas(a);
	}
	if (touch == FLECHE_HAUT) {
		a = modifie_a_lenvers_fleche_haut(a);
	}
	attendre(100);		//attendre à chaque déplacement car sinon c'est beaucoup trop rapide
	return a;
}

// Fonction qui renvoie le plateau modifié en fonction des actions de l'utilisateur
ACTIONCREATION modifie_mode_resolution(ACTIONCREATION a)
{
	POINT p;
	int touch;
	char carac;
	int i = wait_key_arrow_clic(&carac, &touch, &p);
	if (i == EST_CLIC) {
		return modifie_mode_resolution_clic(a, p);
	} else if (i == EST_FLECHE) {
		return modifie_mode_resolution_fleche(a, touch);
	}
	return a;
}

// Fonction qui réalise les différents modes possibles de l'interface de création
ACTIONCREATION modifie_interface_creation(ACTIONCREATION a)
{
	if (a.mode == MODE_EDITION) {
		a = modifie_mode_edition(a);
	} else if (a.mode == MODE_RESOLUTION) {
		a = modifie_mode_resolution(a);
	}
	return a;
}

// Fonction pour manipuler le plateau dans l'interface de creation
ACTIONCREATION joue_interface_creation(ACTIONCREATION a)
{
	while (a.mode != MODE_QUITTER) {
		a = modifie_interface_creation(a);
		affiche_interface_creation(a);
	}
	return a;
}
