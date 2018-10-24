/**
 * \file interface.c
 * \brief Fonctions concernant l'interface.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "../inc/interface.h"
#include "../inc/strassen.h"

/**
 * \fn void affiche_presentation()
 * \brief Fonction qui affiche la présentation du projet.
 */
void affiche_presentation(){                            
	printf("\033[31m\033[01m   _____       _                                   _____ _                                \n");
	printf("  / ____|     | |                                 / ____| |                               \n");
	printf(" | (___   ___ | | _____   ____ _ _   _   ______  | (___ | |_ _ __ __ _ ___ ___  ___ _ __  \n");
	printf("  \\___ \\ / _ \\| |/ _ \\ \\ / / _` | | | | |______|  \\___ \\| __| '__/ _` / __/ __|/ _ \\ '_ \\ \n");
	printf("  ____) | (_) | | (_) \\ V / (_| | |_| |           ____) | |_| | | (_| \\__ \\__ \\  __/ | | |\n");
	printf(" |_____/ \\___/|_|\\___/ \\_/ \\__,_|\\__, |          |_____/ \\__|_|  \\__,_|___/___/\\___|_| |_|\n");
	printf("                                  __/ |                  \n");
	printf("                                 |___/     \n");
	printf("\n\n\033[0m");
	printf("Projet réalisé par Clément Caumes et Yassin Doudouh - IN603\n");
	printf("Ce projet implémente le test de primalité Solovay-Strassen.\n\n");
	printf("\033[34m\033[01m./primalite n k \033[0mavec n le nombre à tester et k le nombre d'itérations pour le test. \n\n");
}

/**
 * \fn void affiche_erreur()
 * \brief Fonction qui affiche le message d'erreur.
 */
void affiche_erreur(){
	printf("\033[34m\033[01m./primalite n k \033[0mavec n le nombre à tester et k le nombre d'itérations pour le test. \n");
	printf("Conditions : n>=0 et k>0. \n");
	exit(0);
}

/**
 * \fn void affiche_nombre(mpz_t nb)
 * \brief Fonction qui affiche le nombre à tester.
 * 
 * \param nb Nombre à tester.
 */
void affiche_nombre(mpz_t nb){
	printf("N=");
	mpz_out_str (stdout,10,nb);
}

/**
 * \fn int initialise_arg(int argc,char** argv,mpz_t n,mpz_t k)
 * \brief Fonction qui initialise les paramètres choisis par l'utilisateur.
 *
 * \param argc Nombre d'arguments choisis par l'utilisateur.
 * \param argv Paramètres choisis par l'utilisateur.
 * \param n Nombre à tester.
 * \param k Nombre d'itérations pour le test de Strassen.
 * \return 1 si tout se passe bien, 0 s'il y a un problème.
 */
int initialise_arg(int argc,char** argv,mpz_t n,mpz_t k){
	mpz_init(n);
	mpz_init(k);
		
	int i;
	i=mpz_set_str (n,argv[1],10);
	if(i!=0) {
		printf("Premier argument non reconnu\n");
		return 0;
	}
	i=mpz_set_str(k,argv[2],10);
	if(i!=0){
		printf("Deuxieme argument non reconnu\n");
		return 0;
	}
	// si n<0 return 0
	if(mpz_sgn(n)==-1) return 0;
	// si k<0 return 0
	if(mpz_sgn(k)==-1) return 0;
	// si k==0 return 0
	if(mpz_sgn(k)==0) return 0;
	return 1;
}

/**
 * \fn void libere_arg(mpz_t n,mpz_t k)
 * \brief Fonction qui libère les allocations créées pour le test.
 * \param n Nombre testé.
 * \param k Nombre d'itérations pour le test de Strassen.
 */
void libere_arg(mpz_t n,mpz_t k){
	mpz_clear(n);
	mpz_clear(k);
}
