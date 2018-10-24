/**
 * \file strassen.c
 * \brief Fonctions concernant l'algorithme de Strassen.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include "../inc/exponent.h"
#include "../inc/jacobi.h"

/**
 * \def COMPOSE
 * Nombre Composé.
 */
#define COMPOSE 1

/**
 * \def PROBABLEMENT_PREMIER
 * Nombre Probablement Premier.
 */
#define PROBABLEMENT_PREMIER 2

/**
 * \def INVALIDE
 * Nombre Invalide.
 */
#define INVALIDE (-1)

/**
 * \fn int teste_primalite_strassen(mpz_t n,mpz_t k)
 * \brief Fonction qui fait le test de primalité Solovay-Strassen.
 * \param n Nombre à tester.
 * \param k Nombre d'itérations à effectuer. 
 * \return COMPOSE si le nombre est composé, PROBABLEMENT PREMIER si le 
 * nombre est premier selon l'algorithme (probablement). 
 */
int teste_primalite_strassen(mpz_t n,mpz_t k){
	// si n<0 ERREUR
	if(mpz_sgn(n)==-1) exit(0);
	// si k<0 ERREUR
	if(mpz_sgn(k)==-1) exit(0);
	// si k==0 ERREUR
	if(mpz_sgn(k)==0) exit(0);
	// si n==0 COMPOSE
	if(mpz_cmp_d (n,0)==0){
		return COMPOSE;
	}
	// si n==1 COMPOSE
	if(mpz_cmp_d (n,1)==0){
		return COMPOSE;
	}
	// si n==2 PREMIER
	if(mpz_cmp_d (n,2)==0){
		return PROBABLEMENT_PREMIER;
	}
	// si n==3 PREMIER
	if(mpz_cmp_d (n,3)==0){
		return PROBABLEMENT_PREMIER;
	}
	//si n est pair COMPOSE
	else if(mpz_tstbit (n,0)==0){
		return COMPOSE;
	}
	
	// initialisation de la suite pseudo-aléatoire de GMP
	gmp_randstate_t state;
	gmp_randinit_default(state);
	gmp_randseed_ui(state,(unsigned)time(NULL));
	
	mpz_t i,n_moins_un,r,a_puissance,puiss,deux,a;
	mpz_init(i);
	mpz_init(n_moins_un);
	mpz_init(r);
	mpz_init(a_puissance);
	mpz_init(puiss);
	mpz_init(deux);
	mpz_init(a);
	mpz_set(i,k);
	mpz_set_ui(deux,2);
	mpz_sub_ui(n_moins_un,n,1);
	
	// pour i de 1 a k
	while(mpz_sgn(i)>0){
		
		// choisir a entre 0 et n-1, différent de 0,1 ou 2
		mpz_urandomm (a,state,n_moins_un);
		while((mpz_cmp_d (a,0)==0)||(mpz_cmp_d (a,1)==0)||(mpz_cmp_d (a,2)==0)){
			mpz_urandomm (a,state,n_moins_un);
		}
		
		// r <- Symbole Jacobi (a/n)
		int jac=jacobi(a,n);
		if(jac==-1){
			mpz_set(r,n);
			mpz_sub_ui(r,n,1);
		}
		else mpz_set_ui(r,jac);
		
		mpz_sub_ui(puiss,n,1); //puiss=n-1
		mpz_cdiv_q (puiss,puiss,deux);  //puiss=(n-1)/2
		
		// a_puissance <- a^((n-1)/2) mod n
		square_and_multiply(a_puissance,a,puiss,n);
		
		// si r==0 ou si a^((n-1)/2)!=r mod n ----> COMPOSE
		if((mpz_cmp_d (r,0)==0)||(mpz_cmp(a_puissance,r)!=0)){
			gmp_randclear (state);
			mpz_clear(i);
			mpz_clear(r);
			mpz_clear(n_moins_un);
			mpz_clear(a_puissance);
			mpz_clear(puiss);
			mpz_clear(deux);
			mpz_clear(a);
			return COMPOSE;
		}
		
		// décrémentation i
		mpz_sub_ui(i,i,1);
	}
	
	gmp_randclear (state);
	mpz_clear(i);
	mpz_clear(n_moins_un);
	mpz_clear(r);
	mpz_clear(puiss);
	mpz_clear(a_puissance);
	mpz_clear(deux);
	mpz_clear(a);
	// si les k tests ont été concluants ----> PROBABLEMENT PREMIER
	return PROBABLEMENT_PREMIER;
}
