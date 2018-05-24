/**
 * \file cesar.c
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient le main du projet
 */

#include "types.h"
#include "cesar.h"
#include "proces_thread.h"
#include "lire_ecrire.h"
#include "cipher.h"
#include "gestion_erreurs.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		erreur_aucun_argument();
	//exécution du travail du processus directeur
	processus_directeur(argc, argv);
	return 0;
}
