// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// sokoban.c du projet SOKOBAN
// Contient le main du sokoban

#include <stdlib.h>
#include <stdio.h>
#include <uvsqgraphics.h>
#include "sokoban.h"
#include "action_crea.h"
#include "action_jeu.h"
#include "lire_ecrire.h"
#include "affichage.h"
#include "types.h"

int main(int argc, char **argv)
{
	// 2 modes possibles MODE_CREATIF ou MODE_JEU
	// découpage : initialisation-action-liberation
	int mode = teste_commande(argc, argv);
	if (mode == MODE_CREATIF) {
		char *nom = calcul_nom_interface_creation(argv);
		initialise_affichage_interface_creation();
		ACTIONCREATION actionCrea;
		actionCrea = initialise_action_crea(nom);
		affiche_interface_creation(actionCrea);
		actionCrea = joue_interface_creation(actionCrea);
		ecrire_fichier(actionCrea.nomFichier, actionCrea);
		libere_actionCreation(actionCrea);
	}

	if (mode == MODE_JEU) {
		ACTIONJEU actionJ;
		char *nom = calcul_nom_interface_jeu(argc, argv);
		int n = retourne_num_niveau_demande(argc, argv);
		actionJ = initialise_action_jeu(nom, n);
		initialise_affichage_interface_jeu();
		affiche_interface_jeu(actionJ);
		actionJ = joue_interface_jeu(actionJ);
		libere_actionJeu(actionJ);
	}
	wait_escape();
	exit(0);
}
