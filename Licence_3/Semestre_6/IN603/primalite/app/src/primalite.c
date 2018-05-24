/**
 * \file primalite.c
 * \brief Fichier principal.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#include "../inc/strassen.h"
#include "../inc/interface.h"

/**
 * \fn int main(int argc,char** argv)
 * \brief Fonction principale du test de primalité de Solovay-Strassen.
 *
 * \param argc Nombre d'arguments choisis par l'utilisateur.
 * \param argv Paramètres choisis par l'utilisateur.
 * \return 0 dans tous les cas.
 */
int main(int argc,char** argv){
	if(argc==1) affiche_presentation();
	else if(argc==3){
		mpz_t n,k;
		int test_arg=initialise_arg(argc,argv,n,k);
		if(test_arg==0) affiche_erreur();
		int test=teste_primalite_strassen(n,k);
		affiche_nombre(n);
		if(test==COMPOSE) printf(" --> COMPOSE\n");
		else printf(" --> PROBABLEMENT PREMIER\n");
		libere_arg(n,k);
	}
	else affiche_erreur();
	
	return 0;
}
