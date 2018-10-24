// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// action_jeu.c du projet SOKOBAN
// Contient toute la gestion de l'interaction avec l'utilisateur
// Gestion de l'historique, Initialisation de la structure, Modification des boutons, Fonctions de déplacement, Modification de la structure

#include <uvsqgraphics.h>
#include "action_jeu.h"
#include "lire_ecrire.h"
#include "affichage.h"
#include "gestion_plateau.h"
#include "types.h"

// Fonctions relatives à la gestion des historiques

// Renvoie 1 si la pile est vide, 0 sinon
int teste_pile_vide(struct elem *e)
{
	if (e == NULL)
		return 1;
	return 0;
}

// Crée une pile vide
struct elem *creer_pile_vide()
{
	return NULL;
}

// Renvoie la taille de la pile en argument
int compte_taille_pile(struct elem *e)
{
	struct elem *temp = e;
	if (teste_pile_vide(temp) == 1)
		return 0;
	return 1 + compte_taille_pile(temp->suiv);
}

// Renvoie la liste dont on a inséré une copie du premier élément : utilisable pour INIT
struct elem *copie_premier_liste(struct elem *a, ACTIONJEU ac, int nbCases)
{
	int allocationPlateau =
	    nbCases * sizeof(CASE *) * nbCases * sizeof(CASE);
	int allocationGen =
	    allocationPlateau + sizeof(int) + sizeof(struct elem *);
	struct elem *new = malloc(allocationGen);
	if (new == NULL)
		quitte_probleme_memoire();
	struct elem *premier = a;
	while (premier->suiv != NULL) {
		premier = premier->suiv;
	}
	new->p = copie_plateau(premier->p);
	new->nbCoups = 0;
	new->p.posPerso.x = premier->p.posPerso.x;
	new->p.posPerso.y = premier->p.posPerso.y;
	new->suiv = a;
	return new;
}

// Libère la mémoire de la pile en argument
struct elem *libere_pile(struct elem *e, ACTIONJEU ac)
{
	struct elem *temp;
	while (teste_pile_vide(e) == 0) {
		temp = e->suiv;
		libere_plateau(e->p);
		free(e);
		e = temp;
	}
	return NULL;
}

// Libère la mémoire de l'historique de la structure ACTIONJEU
void libere_actionJeu(ACTIONJEU a)
{
	a.h.redo = libere_pile(a.h.redo, a);
	a.h.undo = libere_pile(a.h.undo, a);
}

// Insère un élément à la pile passée en argument : quand l'utilisateur joue et déplace le perso
struct elem *insere_pile(struct elem *r, ACTIONJEU ac, PLATEAU plat,
			 int nbCases)
{
	int allocationPlateau =
	    nbCases * sizeof(CASE *) * nbCases * sizeof(CASE);
	int allocationGen =
	    allocationPlateau + sizeof(int) + sizeof(struct elem *);
	struct elem *new = malloc(allocationGen);
	if (new == NULL)
		quitte_probleme_memoire();
	new->nbCoups = ac.h.redo->nbCoups;
	new->p = plat;
	new->suiv = r;
	return new;
}

// Initialise la pile Redo qui possède dès le debut le plateau de départ
struct elem *initialise_redo(int nbCases, struct elem *r, ACTIONJEU ac)
{
	if (nbCases == 0)
		nbCases = 1;	//CAS PARTICULIER NECESSAIRE SI IL Y A UN NIVEAU VIDE
	int allocationPlateau =
	    nbCases * sizeof(CASE *) * nbCases * sizeof(CASE);
	int allocationGen =
	    allocationPlateau + sizeof(int) + sizeof(struct elem *);
	struct elem *a = malloc(allocationGen);
	if (a == NULL)
		quitte_probleme_memoire();
	PLATEAU plat = calcul_plateau_niveau(nbCases, ac);
	a->nbCoups = 0;
	a->p = plat;
	a->suiv = r;
	return a;
}

// Initialise les piles Redo et Undo d'HISTORIQUE de ACTIONJEU
HISTORIQUE initialise_historique(int nbCases, ACTIONJEU ac)
{
	HISTORIQUE h;
	h.redo = creer_pile_vide();
	h.undo = creer_pile_vide();
	h.redo = initialise_redo(nbCases, h.redo, ac);
	return h;
}

/////////////////////

// Initialise la structure ACTIONJEU
ACTIONJEU initialise_action_jeu(char *nom, int num)
{
	ACTIONJEU a;
	a.mode = MODE_JEU;
	a.nomFichier = nom;
	a.niveauMax = calcul_niveau_max(nom);
	a.num = num;
	int nbCases = retourne_taille_plateau(a, nom, a.num);
	a.h = initialise_historique(nbCases, a);
	return a;
}

// Fonction qui modifie ACTIONJEU lorsque l'on choisit de faire UNDO
ACTIONJEU modifie_undo(ACTIONJEU a)
{
	if (compte_taille_pile(a.h.redo) >= 2) {
		struct elem *dernier = a.h.redo;
		a.h.redo = a.h.redo->suiv;	//on déplace le dernier élément de undo vers redo
		dernier->suiv = a.h.undo;
		a.h.undo = dernier;
	}
	return a;
}

// Fonction qui modifie ACTIONJEU avec REDO
ACTIONJEU modifie_redo(ACTIONJEU a)
{
	if (compte_taille_pile(a.h.undo) >= 1) {
		struct elem *dernier = a.h.undo;
		a.h.undo = a.h.undo->suiv;	// on déplace le dernier élément de redo vers undo
		dernier->suiv = a.h.redo;
		a.h.redo = dernier;
	}
	return a;
}

// Fonction qui modifie ACTIONJEU avec INIT
ACTIONJEU modifie_init(ACTIONJEU a)
{
	if (compte_taille_pile(a.h.redo) >= 2) {
		a.h.redo = copie_premier_liste(a.h.redo, a, a.h.redo->p.nbCases);	//on copie le premier élément de la pile REDO à la fin
		a.h.undo = libere_pile(a.h.undo, a);	// on libère la pile UNDO
	}
	return a;
}

// Fonction qui modifie ACTIONJEU en fonction du clic de l'utilisateur
ACTIONJEU modifie_interface_jeu_clic(ACTIONJEU a, POINT p)
{
	if (p.y < HAUTEUR_INTERFACE_JEU - LARGEUR_GARDE_JEU / 2) {
		return a;
	} else {
		int i = p.x / (LARGEUR_INTERFACE_JEU / 6);
		if ((i == 0) && (!teste_niveau_gagne(a.h.redo->p))) {	//undo
			if (teste_niveau_jouable(a.h.redo->p)) {
				return modifie_undo(a);
			}
		} else if ((i == 1) && (!teste_niveau_gagne(a.h.redo->p))) {	//redo
			if (teste_niveau_jouable(a.h.redo->p)) {
				return modifie_redo(a);
			}
		} else if (i == 2) {	//init
			return modifie_init(a);
		} else if (i == 3) {	//prec
			if (a.num != 1) {
				libere_actionJeu(a);
				return initialise_action_jeu(a.nomFichier,
							     a.num - 1);
			}
		} else if (i == 4) {	//suiv
			if (a.num != a.niveauMax) {
				libere_actionJeu(a);
				return initialise_action_jeu(a.nomFichier,
							     a.num + 1);
			}
		} else if (i == 5) {	//quit
			a.mode = MODE_QUITTER;
		}
		return a;
	}
}

//Fonctions de déplacements du joueur dans l'interface de jeu

ACTIONJEU deplac_possib_1_2(ACTIONJEU a, PLATEAU new, int x, int y, int dx,
			    int dy)
{				// déplacement du personnage sans déplacement de caisse
	new.T[x][y].natureElem = PAS_ELEMENT;
	new.posPerso.x = new.posPerso.x + dx;
	new.posPerso.y = new.posPerso.y + dy;
	new.T[x + dx][y + dy].natureElem = PERSO;
	a.h.redo = insere_pile(a.h.redo, a, new, a.h.redo->p.nbCases);
	a.h.undo = libere_pile(a.h.undo, a);	//on libère UNDO a chaque déplacement
	return a;
}

ACTIONJEU deplac_possib_3(ACTIONJEU a, PLATEAU new, int x, int y, int dx,
			  int dy)
{				// déplacement du personnage avec déplacement de caisse
	new.T[x][y].natureElem = PAS_ELEMENT;
	new.posPerso.x = new.posPerso.x + dx;
	new.posPerso.y = new.posPerso.y + dy;
	new.T[x + dx][y + dy].natureElem = PERSO;
	new.T[x + 2 * dx][y + 2 * dy].natureElem = CAISSE;
	a.h.redo = insere_pile(a.h.redo, a, new, a.h.redo->p.nbCases);
	a.h.undo = libere_pile(a.h.undo, a);	//on libère UNDO 
	(a.h.redo->nbCoups)++;	//on ajoute 1 pour le nombre de coups
	return a;
}

////////////////////

// Fonctions de modifications de ACTIONJEU en fonction des flèches cliquées par l'utilisateur

ACTIONJEU modifie_fleche_gauche(ACTIONJEU a)
{				//à gauche
	int test = teste_possibilite_deplac_gauche(a.h);
	if (test == PAS_DEPLAC_POSSIB)
		return a;
	else {
		int x = a.h.redo->p.posPerso.x;
		int y = a.h.redo->p.posPerso.y;
		PLATEAU new = copie_plateau(a.h.redo->p);
		new.posPerso.x = x;
		new.posPerso.y = y;
		if (test == DEPLAC_POSSIB_1) {
			return deplac_possib_1_2(a, new, x, y, -1, 0);
		}
		if (test == DEPLAC_POSSIB_2) {
			return deplac_possib_1_2(a, new, x, y, -1, 0);
		}
		if (test == DEPLAC_POSSIB_3) {
			return deplac_possib_3(a, new, x, y, -1, 0);
		}
		return a;
	}
}

ACTIONJEU modifie_fleche_droite(ACTIONJEU a)
{				//à droite
	int test = teste_possibilite_deplac_droite(a.h);
	if (test == PAS_DEPLAC_POSSIB)
		return a;
	else {
		int x = a.h.redo->p.posPerso.x;
		int y = a.h.redo->p.posPerso.y;
		PLATEAU new = copie_plateau(a.h.redo->p);
		new.posPerso.x = x;
		new.posPerso.y = y;
		if (test == DEPLAC_POSSIB_1) {
			return deplac_possib_1_2(a, new, x, y, 1, 0);
		}
		if (test == DEPLAC_POSSIB_2) {
			return deplac_possib_1_2(a, new, x, y, 1, 0);
		}
		if (test == DEPLAC_POSSIB_3) {
			return deplac_possib_3(a, new, x, y, 1, 0);
		}
		return a;
	}
}

ACTIONJEU modifie_fleche_haut(ACTIONJEU a)
{				//en haut
	int test = teste_possibilite_deplac_haut(a.h);
	if (test == PAS_DEPLAC_POSSIB)
		return a;
	else {
		int x = a.h.redo->p.posPerso.x;
		int y = a.h.redo->p.posPerso.y;
		PLATEAU new = copie_plateau(a.h.redo->p);
		new.posPerso.x = x;
		new.posPerso.y = y;
		if (test == DEPLAC_POSSIB_1) {
			return deplac_possib_1_2(a, new, x, y, 0, 1);
		}
		if (test == DEPLAC_POSSIB_2) {
			return deplac_possib_1_2(a, new, x, y, 0, 1);
		}
		if (test == DEPLAC_POSSIB_3) {
			return deplac_possib_3(a, new, x, y, 0, 1);
		}
		return a;
	}
}

ACTIONJEU modifie_fleche_bas(ACTIONJEU a)
{				//en bas
	int test = teste_possibilite_deplac_bas(a.h);
	if (test == PAS_DEPLAC_POSSIB)
		return a;
	else {
		int x = a.h.redo->p.posPerso.x;
		int y = a.h.redo->p.posPerso.y;
		PLATEAU new = copie_plateau(a.h.redo->p);
		new.posPerso.x = x;
		new.posPerso.y = y;
		if (test == DEPLAC_POSSIB_1) {
			return deplac_possib_1_2(a, new, x, y, 0, -1);
		}
		if (test == DEPLAC_POSSIB_2) {
			return deplac_possib_1_2(a, new, x, y, 0, -1);
		}
		if (test == DEPLAC_POSSIB_3) {
			return deplac_possib_3(a, new, x, y, 0, -1);
		}
		return a;
	}
}

///////////////////

// Fonction générale qui modifie ACTIONJEU en fonction de la fleche appuyée par l'utilisateur
ACTIONJEU modifie_interface_jeu_fleche(ACTIONJEU a, int touch)
{
	if (touch == FLECHE_GAUCHE) {
		a = modifie_fleche_gauche(a);
	}
	if (touch == FLECHE_DROITE) {
		a = modifie_fleche_droite(a);
	}
	if (touch == FLECHE_BAS) {
		a = modifie_fleche_bas(a);
	}
	if (touch == FLECHE_HAUT) {
		a = modifie_fleche_haut(a);
	}
	attendre(100);		//déplacement trop rapide si il n'y a pas de délai
	return a;
}

// Fonction générale qui modifie ACTIONJEU en fonction de la touche cliquee par l'utilisateur
ACTIONJEU modifie_interface_jeu_touche(ACTIONJEU a, char carac)
{
	if (carac == 'Q') {	//QUITTER
		a.mode = MODE_QUITTER;
		return a;
	} else if ((carac == 'U') && (!teste_niveau_gagne(a.h.redo->p))) {	//UNDO
		if (teste_niveau_jouable(a.h.redo->p)) {
			return modifie_undo(a);
		}
	} else if ((carac == 'R') && (!teste_niveau_gagne(a.h.redo->p))) {	//REDO
		if (teste_niveau_jouable(a.h.redo->p)) {
			return modifie_redo(a);
		}
	} else if (carac == 'I') {	//INIT
		return modifie_init(a);
	} else if (carac == 'P') {	//PRECEDENT
		if (a.num != 1) {
			libere_actionJeu(a);
			return initialise_action_jeu(a.nomFichier, a.num - 1);
		}
	} else if (carac == 'S') {	//SUIVANT
		if (a.num != a.niveauMax) {
			libere_actionJeu(a);
			return initialise_action_jeu(a.nomFichier, a.num + 1);
		}
	}
	return a;
}

// Fonction qui modifie ACTIONJEU en fonction de l'action de l'utilisateur (CLIC, TOUCHE ou FLECHE)
ACTIONJEU modifie_interface_jeu(ACTIONJEU a)
{
	POINT p;
	int touch;
	char carac;
	int i = wait_key_arrow_clic(&carac, &touch, &p);
	if (i == EST_CLIC) {
		a = modifie_interface_jeu_clic(a, p);
	}
	if ((i == EST_FLECHE) && (!teste_niveau_gagne(a.h.redo->p))) {
		if (teste_niveau_jouable(a.h.redo->p)) {
			a = modifie_interface_jeu_fleche(a, touch);
		}
	}
	if (i == EST_TOUCHE) {
		a = modifie_interface_jeu_touche(a, carac);
	}
	return a;
}

// Fonction pour manipuler les plateaux de niveaux dans l'interface de jeu
ACTIONJEU joue_interface_jeu(ACTIONJEU a)
{
	while (a.mode != MODE_QUITTER) {
		a = modifie_interface_jeu(a);
		affiche_interface_jeu(a);
	}
	return a;
}
