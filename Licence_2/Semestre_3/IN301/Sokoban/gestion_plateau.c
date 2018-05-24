// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// gestion_plateau.c du projet SOKOBAN
// Contient toutes les fonctions relatives au plateau

#include "sokoban.h"
#include "action_crea.h"
#include "action_jeu.h"
#include "lire_ecrire.h"
#include "types.h"

// Libère la mémoire du plateau en argument
void libere_plateau(PLATEAU plat)
{
	int i;
	for (i = 0; i < plat.nbCases; i++) {
		free(plat.T[i]);
	}
	free(plat.T);
}

// Renvoie un plateau dont les valeurs sont VIDE(natureCase) et PAS_ELEMENT(natureElem)
PLATEAU remplit_plateau_vide(PLATEAU p)
{
	int x, y;
	for (x = 0; x < p.nbCases; x++) {
		for (y = 0; y < p.nbCases; y++) {
			p.T[x][y].natureCase = VIDE;
			p.T[x][y].natureElem = PAS_ELEMENT;
		}
	}
	return p;
}

// Initialise le plateau de jeu selon le paramètre n (taille du plateau)
PLATEAU initialise_plateau_jeu(int n)
{
	PLATEAU p;
	p.nbCases = n;
	p.posPerso.x = p.posPerso.y = INDEFINI;
	p.tailleCases = LARGEUR_INTERFACE_JEU / n;
	int x;
	p.T = malloc(n * sizeof(CASE *));
	if (p.T == NULL)
		quitte_probleme_memoire();
	for (x = 0; x < n; x++) {
		p.T[x] = malloc(n * sizeof(CASE));
		if (p.T[x] == NULL)
			quitte_probleme_memoire();
	}
	p = remplit_plateau_vide(p);
	return p;
}

// Renvoie une copie du plateau passé en argument
PLATEAU copie_plateau(PLATEAU p)
{
	PLATEAU new;
	int x, y;
	new.posPerso.x = p.posPerso.x;
	new.posPerso.y = p.posPerso.y;
	new.nbCases = p.nbCases;
	new.tailleCases = p.tailleCases;
	new = initialise_plateau_jeu(new.nbCases);
	for (x = 0; x < new.nbCases; x++) {
		for (y = 0; y < new.nbCases; y++) {
			new.T[x][y].natureCase = p.T[x][y].natureCase;
			new.T[x][y].natureElem = p.T[x][y].natureElem;
		}
	}
	return new;
}

// Fonctions de calcul pour connaitre les coordonnees du plateau à partir d'un clic

int calcul_X_crea(POINT p, ACTIONCREATION a)
{
	return (p.x - LARGEUR_GARDE_CREA) / a.plat.tailleCases;
}

int calcul_Y_crea(POINT p, ACTIONCREATION a)
{
	return p.y / a.plat.tailleCases;
}

/////////////////////////

// Fonction qui renvoie 1 si les deux compteurs en argument sont égaux et non nuls
int compare_compteurs(int compteurC, int compteurE)
{
	//CAS PARTICULIER SI IL NY A AUCUNE CAISSE
	if ((compteurC == 0) && (compteurE == 0)) {
		return 0;
	}
	if (compteurC == compteurE) {
		return 1;
	}
	return 0;
}

// Teste si il y a existe des caisses/emplacements et si il y a autant de caisses que d'emplacements : renvoie 1 si VRAI 0 sinon
int teste_existence_caisse_emplacement(PLATEAU p)
{
	int x, y;
	int compteurCaisse = 0;
	int compteurEmplacement = 0;
	for (x = 0; x < p.nbCases; x++) {	//on compte les emplacements les emplacements de caisses et les caisses
		for (y = 0; y < p.nbCases; y++) {
			if (p.T[x][y].natureCase == EMPLACEMENT_CAISSE) {
				compteurEmplacement++;
			}
			if (p.T[x][y].natureElem == CAISSE) {
				compteurCaisse++;
			}
		}
	}
	return compare_compteurs(compteurCaisse, compteurEmplacement);
}

// Teste si il y a des couples de CAISSES-EMPLACEMENT et si il existe des CAISSES non rangees
int teste_presence_caisse_non_rangee(PLATEAU p)
{
	int x, y;
	if (teste_existence_caisse_emplacement(p) == 0) {
		return 0;
	} else {
		for (x = 0; x < p.nbCases; x++) {
			for (y = 0; y < p.nbCases; y++) {
				if ((p.T[x][y].natureElem == CAISSE)
				    && (p.T[x][y].natureCase !=
					EMPLACEMENT_CAISSE)) {
					return 1;
				}
			}
		}
	}
	return 0;
}

// Teste si l'entrepot est bien vide
int teste_entrepot_vide(PLATEAU plat)
{
	int x, y;
	for (x = 0; x < plat.nbCases; x++) {
		for (y = 0; y < plat.nbCases; y++) {
			if ((plat.T[x][y].natureCase != VIDE)
			    || (plat.T[x][y].natureElem != PAS_ELEMENT)) {
				return 0;
			}
		}
	}
	return 1;
}

// Teste si on peut poser un perso sur le plateau en mode EDITION
int teste_possibilite_poser_perso(PLATEAU plat)
{
	int x, y;
	int compteur = 0;
	for (x = 0; x < plat.nbCases; x++) {
		for (y = 0; y < plat.nbCases; y++) {
			if (plat.T[x][y].natureElem == PERSO) {
				compteur++;
			}
		}
	}
	if (compteur == 0) {
		return 1;
	}
	return 0;
}

// Compte le nombre de PERSO sur le niveau (similaire à la fonction du dessus)
int compte_nombre_persos(PLATEAU plat)
{
	int x, y;
	int compteur = 0;
	for (x = 0; x < plat.nbCases; x++) {
		for (y = 0; y < plat.nbCases; y++) {
			if (plat.T[x][y].natureElem == PERSO) {
				compteur++;
			}
		}
	}
	return compteur;
}

// Teste si le personnage est sur le bord droit, gauche, haut ou bas du plateau
int teste_perso_presence_bord_plateau(PLATEAU plat)
{
	if ((plat.posPerso.x == 0) || (plat.posPerso.x == plat.nbCases - 1)) {
		return 1;
	}
	if ((plat.posPerso.y == 0) || (plat.posPerso.y == plat.nbCases - 1)) {
		return 1;
	}
	return 0;
}

// Teste si le niveau joué est gagné par l'utilisateur
int teste_niveau_gagne(PLATEAU p)
{
	int x, y;
	if (!teste_existence_caisse_emplacement(p)) {
		return 0;
	} else {		//recherche si il existe des caisses mal placées si oui alors renvoie 0
		for (x = 0; x < p.nbCases; x++) {
			for (y = 0; y < p.nbCases; y++) {
				if ((p.T[x][y].natureCase == EMPLACEMENT_CAISSE)
				    && (p.T[x][y].natureElem != CAISSE)) {
					return 0;
				}
			}
		}
		return 1;
	}
}

// Renvoie 1 si le personnage est sur un bord du plateau, 0 sinon
int teste_presence_perso_bord(PLATEAU p)
{
	if ((p.posPerso.x == 0) || (p.posPerso.x == p.nbCases - 1)) {
		return 1;
	}
	if ((p.posPerso.y == 0) || (p.posPerso.y == p.nbCases - 1)) {
		return 1;
	}
	return 0;
}

// Fonction qui renvoie un plateau de cases non testées
PLATEAU initialise_copie_plateau_test(PLATEAU plat)
{
	PLATEAU p;
	int x, y;
	p.nbCases = plat.nbCases;
	p.T = malloc(p.nbCases * sizeof(CASE *));
	if (p.T == NULL)
		quitte_probleme_memoire();
	for (x = 0; x < p.nbCases; x++) {
		p.T[x] = malloc(p.nbCases * sizeof(CASE));
		if (p.T[x] == NULL)
			quitte_probleme_memoire();
	}
	for (x = 0; x < p.nbCases; x++) {
		for (y = 0; y < p.nbCases; y++) {
			p.T[x][y].natureCase = CASE_NON_TESTEE;
		}
	}
	return p;
}

// Fonction qui va sur les voisins direct du personnage et qui sont mis a CASE_TESTEE
PLATEAU met_valeurs_debut_test(PLATEAU temp, PLATEAU plat)
{
	if ((plat.T[plat.posPerso.x - 1][plat.posPerso.y].natureCase != MUR)) {
		temp.T[plat.posPerso.x - 1][plat.posPerso.y].natureCase =
		    CASE_TESTEE;
	}
	if ((plat.T[plat.posPerso.x + 1][plat.posPerso.y].natureCase != MUR)) {
		temp.T[plat.posPerso.x + 1][plat.posPerso.y].natureCase =
		    CASE_TESTEE;
	}
	if ((plat.T[plat.posPerso.x][plat.posPerso.y - 1].natureCase != MUR)) {
		temp.T[plat.posPerso.x][plat.posPerso.y - 1].natureCase =
		    CASE_TESTEE;
	}
	if ((plat.T[plat.posPerso.x][plat.posPerso.y + 1].natureCase != MUR)) {
		temp.T[plat.posPerso.x][plat.posPerso.y + 1].natureCase =
		    CASE_TESTEE;
	}
	return temp;
}

// Fonction qui diffuse la valeur CASE_TESTEE aux voisins (voisins directs)de chaque case du plateau 
PLATEAU diffuse_valeurs_test(PLATEAU temp, PLATEAU plat)
{
	int compteur = 1;
	int x, y;
	while (compteur != 0) {
		compteur = 0;
		for (x = 0; x < plat.nbCases; x++) {
			for (y = 0; y < plat.nbCases; y++) {
				if ((x % plat.nbCases != 0) && (temp.T[x][y].natureCase == CASE_TESTEE)) {	//a gauche
					if ((plat.T[x - 1][y].natureCase != MUR)
					    && (temp.T[x - 1][y].natureCase ==
						CASE_NON_TESTEE)) {
						temp.T[x - 1][y].natureCase =
						    CASE_TESTEE;
						compteur++;
					}
				}
				if ((x % plat.nbCases != plat.nbCases - 1) && (temp.T[x][y].natureCase == CASE_TESTEE)) {	//a droite
					if ((plat.T[x + 1][y].natureCase != MUR)
					    && (temp.T[x + 1][y].natureCase ==
						CASE_NON_TESTEE)) {
						temp.T[x + 1][y].natureCase =
						    CASE_TESTEE;
						compteur++;
					}
				}
				if ((y % plat.nbCases != 0) && (temp.T[x][y].natureCase == CASE_TESTEE)) {	//en bas
					if ((plat.T[x][y - 1].natureCase != MUR)
					    && (temp.T[x][y - 1].natureCase ==
						CASE_NON_TESTEE)) {
						temp.T[x][y - 1].natureCase =
						    CASE_TESTEE;
						compteur++;
					}
				}
				if ((y % plat.nbCases != plat.nbCases - 1) && (temp.T[x][y].natureCase == CASE_TESTEE)) {	//en haut
					if ((plat.T[x][y + 1].natureCase != MUR)
					    && (temp.T[x][y + 1].natureCase ==
						CASE_NON_TESTEE)) {
						temp.T[x][y + 1].natureCase =
						    CASE_TESTEE;
						compteur++;
					}
				}
			}
		}
	}
	return temp;
}

// Fonction qui renvoie 1 si il existe une CASE_NON_TESTEE sur les bords du plateau 
// Permet de savoir si le personnage est bien enfermé dans l'entrepot
int teste_diffusion_valeurs_test(PLATEAU temp, PLATEAU plat)
{
	int x, y;
	for (y = 0; y < plat.nbCases; y++) {	//test sur les bords horizontaux
		if ((temp.T[0][y].natureCase == CASE_NON_TESTEE)
		    && (plat.T[0][y].natureCase == VIDE)) {
			return 1;
		}
		if ((temp.T[plat.nbCases - 1][y].natureCase == CASE_NON_TESTEE)
		    && (plat.T[plat.nbCases - 1][y].natureCase == VIDE)) {
			return 1;
		}
	}
	for (x = 0; x < plat.nbCases; x++) {	//test sur les bords verticaux
		if ((temp.T[x][0].natureCase == CASE_NON_TESTEE)
		    && (plat.T[x][0].natureCase == VIDE)) {
			return 1;
		}
		if ((temp.T[x][plat.nbCases - 1].natureCase == CASE_NON_TESTEE)
		    && (plat.T[x][plat.nbCases - 1].natureCase == VIDE)) {
			return 1;
		}
	}
	return 0;
}

// Teste si le personnage est bien à l'interieur de l'entrepot
int teste_perso_interieur_entrepot(PLATEAU plat)
{
	if (plat.posPerso.x == INDEFINI)
		return 0;
	if (teste_presence_perso_bord(plat))
		return 0;
	PLATEAU pCopie = initialise_copie_plateau_test(plat);
	pCopie = met_valeurs_debut_test(pCopie, plat);
	pCopie = diffuse_valeurs_test(pCopie, plat);
	int test = teste_diffusion_valeurs_test(pCopie, plat);
	libere_plateau(pCopie);
	return test;
}

// Teste si le niveau est jouable ou non
int teste_niveau_jouable(PLATEAU p)
{
	if (compte_nombre_persos(p) == 1) {	// il faut qu'il y ait un unique personnage
		if (teste_perso_interieur_entrepot(p)) {	// que ce personnage soit à l'intérieur de l'entrepot
			if (teste_existence_caisse_emplacement(p)) {	// que l'on puisse gagner en mettant toutes les caisses sur des emplacements
				return 1;
			}
		}
	}
	return 0;
}

// Teste si les bords du plateau sont tous des murs
int teste_entrepot_maximal(PLATEAU plat)
{
	int x, y;
	//si il existe un élément différent de MUR 
	for (y = 0; y < plat.nbCases; y++) {	//test sur les bords horizontaux
		if (plat.T[0][y].natureCase != MUR) {
			return 0;
		}
		if (plat.T[plat.nbCases - 1][y].natureCase != MUR) {
			return 0;
		}
	}
	for (x = 0; x < plat.nbCases; x++) {	//test sur les bords verticaux
		if (plat.T[x][0].natureCase != MUR) {
			return 0;
		}
		if (plat.T[x][plat.nbCases - 1].natureCase != MUR) {
			return 0;
		}
	}
	return 1;
}

// Teste si il existe une caisse sur le plateau
int teste_caisse_posee(PLATEAU plat)
{
	int x, y;
	for (x = 0; x < plat.nbCases; x++) {
		for (y = 0; y < plat.nbCases; y++) {
			if ((plat.T[x][y].natureElem == CAISSE)) {
				return 1;
			}
		}
	}
	return 0;
}

// Teste si le niveau créé est sauvegardable ou non
int teste_mode_edition_sauvegardable(PLATEAU plat)
{
	//si le perso n'est pas encore posé alors FAUX
	if (teste_possibilite_poser_perso(plat) == 1) {
		return 0;
	} else if (teste_possibilite_poser_perso(plat) == 0) {
		//si le perso est sur les bords du plateau alors FAUX car il n'est pas dans l'entrepot
		if (teste_perso_presence_bord_plateau(plat) == 1) {
			return 0;
		}
		if (teste_entrepot_maximal(plat) == 1) {	//si l'entrepot est maximal alors VRAI
			return 1;
		}
		if ((teste_perso_interieur_entrepot(plat) == 1) && (teste_caisse_posee(plat) == 1)) {	//si le perso est a l'interieur et qu'il y a une caisse VRAI
			return 1;
		}
	}
	return 0;
}

// Teste si on peut resoudre le niveau créé (c'est a dire qu'il existe au moins une caisse mal placée)
int teste_mode_resolution_sauvegardable(PLATEAU plat)
{
	int x, y;
	for (x = 0; x < plat.nbCases; x++) {
		for (y = 0; y < plat.nbCases; y++) {
			//il faut que l'entrepot contienne au moins une caisse non placé sur son emplacement
			if ((plat.T[x][y].natureCase == VIDE)
			    && (plat.T[x][y].natureElem == CAISSE)) {
				return 1;
			}
		}
	}
	return 0;
}

// Fonctions relatives au clic sur le plateau de l'utilisateur 
// Correspond aux différentes possibilités du clic

// Renvoie 1 si il est trop bas, trop haut, trop a gauche ou trop a droite sinon renvoie 0
int teste_clic_a_cote(POINT p, ACTIONCREATION a)
{
	if (p.y < (HAUTEUR_INTERFACE_CREA / 6 - TAILLE_CASES)) {	//si le clic est trop bas
		return 1;
	}
	if (a.mode == MODE_RESOLUTION) {
		if (p.y < (3 * HAUTEUR_INTERFACE_CREA / 6) - TAILLE_CASES) {
			return 1;
		}
	}
	if (p.y > (5 * HAUTEUR_INTERFACE_CREA / 6 + TAILLE_CASES)) {	//si le clic est trop haut
		return 1;
	}
	if (p.x < ((LARGEUR_GARDE_CREA / 2) - TAILLE_CASES)) {	//si le clic est trop à gauche par rapport aux boutons
		return 1;
	}
	if (p.x > ((LARGEUR_GARDE_CREA / 2) + TAILLE_CASES)) {	//si le clic est trop à droite par rapport aux boutons
		return 1;
	}
	return 0;
}

// Teste si le clic a été fait entre les boutons
int teste_clic_ecart_bouton(POINT p)
{
	// si le clic est entre le premier bouton et le deuxieme
	if ((p.y > (HAUTEUR_INTERFACE_CREA / 6 + TAILLE_CASES))
	    && (p.y < (2 * HAUTEUR_INTERFACE_CREA / 6 - TAILLE_CASES))) {
		return 1;
	}
	//si le clic est entre le deuxieme et le troisieme
	if ((p.y > (2 * HAUTEUR_INTERFACE_CREA / 6 + TAILLE_CASES))
	    && (p.y < (3 * HAUTEUR_INTERFACE_CREA / 6 - TAILLE_CASES))) {
		return 1;
	}
	//si le clic est entre le troisieme et le quatrieme 
	if ((p.y > (3 * HAUTEUR_INTERFACE_CREA / 6 + TAILLE_CASES))
	    && (p.y < (4 * HAUTEUR_INTERFACE_CREA / 6 - TAILLE_CASES))) {
		return 1;
	}
	//si le clic est entre le quatrieme et le cinquieme
	if ((p.y > (4 * HAUTEUR_INTERFACE_CREA / 6 + TAILLE_CASES))
	    && (p.y < (5 * HAUTEUR_INTERFACE_CREA / 6 - TAILLE_CASES))) {
		return 1;
	}
	return 0;
}

// Teste si le clic correspond à un bouton selon les modes EDITION et RESOLUTION : renvoie 1 si c'est à coté
int teste_clic_bouton_cas_specifiques(POINT p, ACTIONCREATION a)
{
	//si on est dans le mode EDITION et on ne peut pas cliquer sur le bouton sauver
	if (a.mode == MODE_EDITION) {
		if (teste_mode_edition_sauvegardable(a.plat) == 0) {
			if ((p.y <
			     (4 * HAUTEUR_INTERFACE_CREA / 6) + TAILLE_CASES)
			    && (p.y >
				(4 * HAUTEUR_INTERFACE_CREA / 6 -
				 TAILLE_CASES))) {
				return 1;
			}
		}
	}
	//si on est dans le mode RESOLUTION et on ne peut pas cliquer sur le bouton sauver
	if (a.mode == MODE_RESOLUTION) {
		if (teste_mode_resolution_sauvegardable(a.plat) == 0) {
			if ((p.y <
			     (4 * HAUTEUR_INTERFACE_CREA / 6) + TAILLE_CASES)
			    && (p.y >
				(4 * HAUTEUR_INTERFACE_CREA / 6 -
				 TAILLE_CASES))) {
				return 1;
			}
		}
		if ((p.y < (3 * HAUTEUR_INTERFACE_CREA / 6) + TAILLE_CASES)
		    && (p.y > (3 * HAUTEUR_INTERFACE_CREA / 6 - TAILLE_CASES))) {
			return 0;
		}
	}
	return 0;
}

// Teste si le clic sur le plateau correspond à un bouton : renvoie DANS_ZONE si c'est vrai HORS_ZONE sinon
int teste_clic_bouton(POINT p, ACTIONCREATION a)
{
	if (teste_clic_a_cote(p, a) == 1) {
		return HORS_ZONE;
	}
	if (teste_clic_ecart_bouton(p) == 1) {
		return HORS_ZONE;
	}
	if (teste_clic_bouton_cas_specifiques(p, a) == 1) {
		return HORS_ZONE;
	}
	return DANS_ZONE;
}

// Renvoie 1 si le clic est sur le plateau, 0 sinon
int teste_clic_sur_plateau(POINT p)
{
	if (p.x > LARGEUR_GARDE_CREA) {
		return 1;
	}
	return 0;
}

/////////////////////////////////////////

// Teste si sur la ligne il y a des éléments
int teste_ligne_vide(PLATEAU plat, int y)
{
	int x;
	for (x = 0; x < plat.nbCases; x++) {
		if ((plat.T[x][y].natureCase != VIDE)
		    || (plat.T[x][y].natureElem != PAS_ELEMENT)) {
			return 0;
		}
	}
	return 1;
}

// Teste si sur la colonne il y a des éléments
int teste_colonne_vide(PLATEAU plat, int x)
{
	int y;
	for (y = plat.nbCases - 1; y > 0; y--) {
		if ((plat.T[x][y].natureCase != VIDE)
		    || (plat.T[x][y].natureElem != PAS_ELEMENT)) {
			return 0;
		}
	}
	return 1;
}

// Teste si on peut déplacer le personnage sur la gauche (flèche gauche)
int teste_possibilite_deplac_gauche(HISTORIQUE h)
{
	int x = h.redo->p.posPerso.x;
	int y = h.redo->p.posPerso.y;
	if ((x == 0) || (x == 1))
		return PAS_DEPLAC_POSSIB;
	//si la case d'a cote est une case VIDE SANS ELEMENT
	if ((h.redo->p.T[x - 1][y].natureCase == VIDE)
	    && (h.redo->p.T[x - 1][y].natureElem == PAS_ELEMENT)) {
		return DEPLAC_POSSIB_1;
	}
	//si la case d'a cote est EMPLACEMENT CAISSE SANS ELEMENT
	if ((h.redo->p.T[x - 1][y].natureCase == EMPLACEMENT_CAISSE)
	    && (h.redo->p.T[x - 1][y].natureElem == PAS_ELEMENT)) {
		return DEPLAC_POSSIB_2;
	}
	//si la case d'a cote est CAISSE et que la suivante n'est ni MUR ni CAISSE
	if ((h.redo->p.T[x - 1][y].natureElem == CAISSE)) {
		if ((h.redo->p.T[x - 2][y].natureCase != MUR)
		    && (h.redo->p.T[x - 2][y].natureElem != CAISSE)) {
			return DEPLAC_POSSIB_3;
		}
	}
	return PAS_DEPLAC_POSSIB;
}

// Teste si on peut déplacer le personnage sur la droite (flèche droite)
int teste_possibilite_deplac_droite(HISTORIQUE h)
{
	int x = h.redo->p.posPerso.x;
	int y = h.redo->p.posPerso.y;
	if ((x == h.redo->p.nbCases - 1) || (x == h.redo->p.nbCases - 2))
		return PAS_DEPLAC_POSSIB;
	if ((h.redo->p.T[x + 1][y].natureCase == VIDE)
	    && (h.redo->p.T[x + 1][y].natureElem == PAS_ELEMENT)) {
		return DEPLAC_POSSIB_1;
	}
	if ((h.redo->p.T[x + 1][y].natureCase == EMPLACEMENT_CAISSE)
	    && (h.redo->p.T[x + 1][y].natureElem == PAS_ELEMENT)) {
		return DEPLAC_POSSIB_2;
	}
	if ((h.redo->p.T[x + 1][y].natureElem == CAISSE)) {
		if ((h.redo->p.T[x + 2][y].natureCase != MUR)
		    && (h.redo->p.T[x + 2][y].natureElem != CAISSE)) {
			return DEPLAC_POSSIB_3;
		}
	}
	return PAS_DEPLAC_POSSIB;
}

// Teste si on peut déplacer le personnage en bas (flèche bas)
int teste_possibilite_deplac_bas(HISTORIQUE h)
{
	int x = h.redo->p.posPerso.x;
	int y = h.redo->p.posPerso.y;
	if ((y == 0) || (y == 1))
		return PAS_DEPLAC_POSSIB;
	if ((h.redo->p.T[x][y - 1].natureCase == VIDE)
	    && (h.redo->p.T[x][y - 1].natureElem == PAS_ELEMENT)) {
		return DEPLAC_POSSIB_1;
	}
	if ((h.redo->p.T[x][y - 1].natureCase == EMPLACEMENT_CAISSE)
	    && (h.redo->p.T[x][y - 1].natureElem == PAS_ELEMENT)) {
		return DEPLAC_POSSIB_2;
	}
	if ((h.redo->p.T[x][y - 1].natureElem == CAISSE)) {
		if ((h.redo->p.T[x][y - 2].natureCase != MUR)
		    && (h.redo->p.T[x][y - 2].natureElem != CAISSE)) {
			return DEPLAC_POSSIB_3;
		}
	}
	return PAS_DEPLAC_POSSIB;
}

// Teste si on peut déplacer le personnage en haut (flèche haut)
int teste_possibilite_deplac_haut(HISTORIQUE h)
{
	int x = h.redo->p.posPerso.x;
	int y = h.redo->p.posPerso.y;
	if ((y == h.redo->p.nbCases - 1) || (y == h.redo->p.nbCases - 2))
		return PAS_DEPLAC_POSSIB;
	if ((h.redo->p.T[x][y + 1].natureCase == VIDE)
	    && (h.redo->p.T[x][y + 1].natureElem == PAS_ELEMENT)) {
		return DEPLAC_POSSIB_1;
	}
	if ((h.redo->p.T[x][y + 1].natureCase == EMPLACEMENT_CAISSE)
	    && (h.redo->p.T[x][y + 1].natureElem == PAS_ELEMENT)) {
		return DEPLAC_POSSIB_2;
	}
	if ((h.redo->p.T[x][y + 1].natureElem == CAISSE)) {
		if ((h.redo->p.T[x][y + 2].natureCase != MUR)
		    && (h.redo->p.T[x][y + 2].natureElem != CAISSE)) {
			return DEPLAC_POSSIB_3;
		}
	}
	return PAS_DEPLAC_POSSIB;
}
