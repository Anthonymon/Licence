// Clément Caumes 21501810
// Yassin Doudouh 21500127
// 05 mai 2017
// Projet Metro IN403

// metro.c du projet Metro
// Contient le main du projet

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "affichage.h"
#include "lire_ecrire.h"
#include "types.h"

int main()
{
	//initialisation des données
	METRO m = initialise_metro(compte_nb_sommets("metro.txt"));
	m.g = initialise_stations("metro.txt", m.g);
	m.g = initialise_reseau("metro.txt", m.g);
	initialise_fenetre();

	//interaction de l'utilisateur avec l'application
	affiche_carte(m);
	while (m.mode != MODE_QUITTER)
		m = interaction(m);

	//libération de la mémoire
	libere_graphe(m.g);
	libere_chemin_dijkstra(m.g.d.chemin);
	libere_fenetre();
	return 0;
}
