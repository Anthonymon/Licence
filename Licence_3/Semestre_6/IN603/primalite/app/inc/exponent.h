/**
 * \file exponent.h
 * \brief Signatures des fonctions concernant l'exponentiation rapide.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#ifndef EXPONENT__H
#define EXPONENT__H


/**
 * \fn void calcule_nombre_bits (mpz_t bits,mpz_t nb)
 * \brief Fonction qui calcule le nombre de bits d'un nombre nb.
 * \param bits Nombre de bits qui sera initialisé. 
 * \param nb Nombre à tester. 
 */
void calcule_nombre_bits(mpz_t bits,mpz_t nb);

/**
 * \fn void square_and_multiply(mpz_t r,mpz_t a,mpz_t h, mpz_t n)
 * \brief Fonction qui fait l'exponentiation modulaire a^h=r mod n.
 * \param r Résultat qui sera initialisé.
 * \param a Base de l'exponentiation modulaire. 
 * \param h Puissance de l'exponentiation modulaire. 
 * \param n Module de l'exponentiation modulaire.  
 */
void square_and_multiply(mpz_t r,mpz_t a, mpz_t h, mpz_t n);

#endif
