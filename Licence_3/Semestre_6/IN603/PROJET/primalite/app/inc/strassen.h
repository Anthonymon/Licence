/**
 * \file strassen.h
 * \brief Signatures des fonctions concernant l'algorithme de Strassen.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#ifndef STRASSEN__H
#define STRASSEN__H

#define COMPOSE 1
#define PROBABLEMENT_PREMIER 2

/**
 * \fn int teste_primalite_strassen(mpz_t n,mpz_t k)
 * \brief Fonction qui fait le test de primalité Solovay-Strassen.
 * \param n Nombre à tester.
 * \param k Nombre d'itérations à effectuer. 
 * \return COMPOSE si le nombre est composé, PROBABLEMENT PREMIER si le 
 * nombre est premier selon l'algorithme (probablement). 
 */
int teste_primalite_strassen(mpz_t n,mpz_t k);

#endif
