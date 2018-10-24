// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// lire_ecrire.h du projet SOKOBAN
// Contient toutes les fonctions relatives à la lecture/écriture des fichiers et des commandes de l'utilisateur

#ifndef __LIRE_ECRIRE_H
#define __LIRE_ECRIRE_H

void quitte_probleme_memoire();
int calcul_niveau_max(char *nomFichier);
int teste_commande(int num, char **chaineCarac);

char *calcul_nom_interface_creation(char **chaineCarac);
char *calcul_nom_interface_jeu(int num, char **chaineCarac);
void ecrire_fichier(char *nomFichier, ACTIONCREATION p);

int retourne_num_niveau_demande(int num, char **chaineCarac);
int retourne_taille_plateau(ACTIONJEU a, char *nomFichier, int num);
PLATEAU calcul_plateau_niveau(int nbCases, ACTIONJEU a);

#endif
