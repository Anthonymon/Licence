/**
 * \file interface.h
 * \brief Signatures des fonctions concernant l'interface.
 * \author Clément Caumes - Yassin Doudouh
 * \date 26 Avril 2018
 *
 * Programme de test de primalité de Solovay-Strassen.
 *
 */

#ifndef INTERFACE__H
#define INTERFACE__H

/**
 * \fn void affiche_presentation()
 * \brief Fonction qui affiche la présentation du projet.
 */
void affiche_presentation();

/**
 * \fn void affiche_erreur()
 * \brief Fonction qui affiche le message d'erreur.
 */
void affiche_erreur();

/**
 * \fn void affiche_nombre(mpz_t nb)
 * \brief Fonction qui affiche le nombre à tester.
 * 
 * \param nb Nombre à tester.
 */
void affiche_nombre(mpz_t nb);

/**
 * \fn int initialise_arg(int argc,char** argv,mpz_t n,mpz_t k)
 * \brief Fonction qui initialise les paramètres choisis par l'utilisateur.
 *
 * \param argc Nombre d'arguments choisis par l'utilisateur.
 * \param argv Paramètres choisis par l'utilisateur.
 * \param n Nombre à tester.
 * \param k Nombre d'itérations pour le test de Strassen.
 * \return 1 si tout se passe bien, 0 si il y a un problème.
 */
int initialise_arg(int argc,char** argv,mpz_t n,mpz_t k);

/**
 * \fn void libere_arg(mpz_t n,mpz_t k)
 * \brief Fonction qui libère les allocations créées pour le test.
 * \param n Nombre testé.
 * \param k Nombre d'itérations pour le test de Strassen.
 */
void libere_arg(mpz_t n,mpz_t k);

#endif
