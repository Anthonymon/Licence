// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// gestion_plateau.h du projet SOKOBAN
// Contient toutes les fonctions relatives au plateau

#ifndef __GESTION_PLATEAU_H
#define __GESTION_PLATEAU_H

void libere_plateau(PLATEAU plat);
PLATEAU remplit_plateau_vide(PLATEAU p);
PLATEAU initialise_plateau_jeu(int n);
PLATEAU copie_plateau(PLATEAU p);
int calcul_X_crea(POINT p, ACTIONCREATION a);
int calcul_Y_crea(POINT p, ACTIONCREATION a);

int teste_possibilite_poser_perso(PLATEAU plat);

int teste_niveau_gagne(PLATEAU p);
int teste_niveau_jouable(PLATEAU p);

int teste_mode_edition_sauvegardable(PLATEAU plat);
int teste_mode_resolution_sauvegardable(PLATEAU plat);

int teste_clic_bouton(POINT p, ACTIONCREATION a);
int teste_clic_sur_plateau(POINT p);
int teste_ligne_vide(PLATEAU plat, int y);
int teste_colonne_vide(PLATEAU plat, int x);

int teste_possibilite_deplac_gauche(HISTORIQUE h);
int teste_possibilite_deplac_droite(HISTORIQUE h);
int teste_possibilite_deplac_haut(HISTORIQUE h);
int teste_possibilite_deplac_bas(HISTORIQUE h);

#endif
