/**
 * \file jacobi.h
 * \brief Signatures des fonctions concernant l'algorithme de Jacobi.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#ifndef JACOBI__H
#define JACOBI__H

/**
 * \fn int pgcd_binary(mpz_t result,mpz_t a,mpz_t b)
 * \brief Fonction qui calcule le PGCD. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int pgcd_binary(mpz_t result,mpz_t a,mpz_t b);

/**
 * \fn int pgcd_recursif(mpz_t result,mpz_t a,mpz_t b)
 * \brief Fonction qui calcule le PGCD. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int pgcd_recursif(mpz_t result,mpz_t a,mpz_t b);

/**
 * \fn int premier_entre_eux_iteratif(mpz_t a,mpz_t b)
 * \brief Fonction qui teste si deux nombres sont premiers entre eux. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int premier_entre_eux_iteratif(mpz_t a,mpz_t b);

/**
 * \fn int premier_entre_eux_recursif(mpz_t a,mpz_t b)
 * \brief Fonction qui teste si deux nombres sont premiers entre eux. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int premier_entre_eux_recursif(mpz_t a,mpz_t b);

/**
 * \fn int premier_entre_eux_binaire(mpz_t a,mpz_t b)
 * \brief Fonction qui teste si deux nombres sont premiers entre eux. 
 * \param a Premier nombre du pgcd.
 * \param b Deuxième nombre du pgcd. 
 * \return 1 si a et b sont premiers entre eux, 0 sinon.
 */
int premier_entre_eux_binaire(mpz_t a,mpz_t b);

/**
 * \fn void reduit_num_mod_denom(mpz_t nouv,mpz_t n,mpz_t m)
 * \brief Fonction qui calcule le modulo d'un nombre. 
 * \param nouv Résultat qui sera initialisé.
 * \param n Base du calcul. 
 * \param m Module du calcul. 
 */
void reduit_num_mod_denom(mpz_t nouv,mpz_t n,mpz_t m);

/**
 * \fn int jacobi(mpz_t num,mpz_t denum)
 * \brief Fonction qui calcule le symbole de Jacobi. 
 * \param num Numérateur du symbole de Jacobi.
 * \param denum Dénominateur du symbole de Jacobi. 
 * \return 0, 1 ou -1 résultats possibles du symbole de Jacobi.
 */
int jacobi(mpz_t num,mpz_t denum);

#endif

