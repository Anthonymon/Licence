/**
 * \file exponent.c
 * \brief Fonctions concernant l'exponentiation rapide.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/**
 * \fn void calcule_nombre_bits (mpz_t bits,mpz_t nb)
 * \brief Fonction qui calcule le nombre de bits d'un nombre nb.
 * \param bits Nombre de bits qui sera initialisé. 
 * \param nb Nombre à tester. 
 */
void calcule_nombre_bits (mpz_t bits,mpz_t nb){
	//si nb==0 bits=0;
	if(mpz_sgn(nb)==0){ 
		mpz_set_d(bits,0);
	}
	else{ 
		//on incrémente à chaque bits pour connaître la taille de nb
		mpz_set_d(bits,0);
		while(mpz_cmp_d(nb,1)!=0){
			mpz_add_ui(bits,bits,1);
			mpz_tdiv_q_2exp(nb,nb,1);
		}
		mpz_add_ui(bits,bits,1);
	}
}

/**
 * \fn void square_and_multiply(mpz_t r,mpz_t a,mpz_t h, mpz_t n)
 * \brief Fonction qui fait l'exponentiation modulaire a^h=r mod n.
 * \param r Résultat qui sera initialisé.
 * \param a Base de l'exponentiation modulaire. 
 * \param h Puissance de l'exponentiation modulaire. 
 * \param n Module de l'exponentiation modulaire.  
 */
void square_and_multiply(mpz_t r,mpz_t a,mpz_t h, mpz_t n){
	mpz_set(r,a);	//r <- a

	mpz_t t,copie;
	mpz_init(t);
	mpz_init(copie);
	mpz_set (copie,h);
	
	// t représente le nombre de bits dans h
	calcule_nombre_bits(t,copie);
	
	// la boucle commence de t-1
	mpz_sub_ui(t,t,1);
	
	unsigned long int i=mpz_get_ui(t);

	// boucle de t-1 à 0
	while(i>0){
		mpz_mul(r,r,r);
		mpz_mod(r,r,n); // r<-r*r [n]
		
		i--;
		// si le bit numero i de h vaut 1 
		if(mpz_tstbit (h,i)==1){ 
			mpz_mul(r, r, a); 
			mpz_mod(r, r, n); // r <- r*a [n]
		}
	}
	mpz_clear(t);
	mpz_clear(copie);
}
