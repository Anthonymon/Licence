/**
 * \file gestion_erreurs.h
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient les signatures des fonctions concernant la gestion d'erreurs
 */

#ifndef __GESTION_ERREURS_H
#define __GESTION_ERREURS_H

/**
 * \fn void erreur_ouverture_fichier()
 * \brief fonction qui se déclenche si il y a une erreur d'ouverture de fichier
 * */
void erreur_ouverture_fichier();

/**
 * \fn void erreur_lecture_fichier()
 * \brief fonction qui se déclenche si il y a une erreur de lecture de fichier
 * */
void erreur_lecture_fichier();

/**
 * \fn void erreur_ecriture_fichier()
 * \brief fonction qui se déclenche si il y a une erreur d'ecriture de fichier
 * */
void erreur_ecriture_fichier();

/**
 * \fn void erreur_pas_chiffrement()
 * \brief fonction qui se déclenche si il y a une erreur lors de la lecture du pas de chiffrement
 * */
void erreur_pas_chiffrement();

/**
 * \fn void erreur_nombre_trop_grand()
 * \brief fonction qui se déclenche si le pas de chiffrement est trop grand
 * */
void erreur_nombre_trop_grand();

/**
 * \fn void erreur_utilisation_lseek()
 * \brief fonction qui se déclenche si il y a une erreur d'utilisateur de lseek
 * */
void erreur_utilisation_lseek();

/**
 * \fn void erreur_fermeture_fichier()
 * \brief fonction qui se déclenche si il y a une erreur de fermeture de fichier
 * */
void erreur_fermeture_fichier();

/**
 * \fn void erreur_aucun_argument()
 * \brief fonction qui se déclenche si il n'y a aucun paramètre dans la ligne de commandes
 * */
void erreur_aucun_argument();

/**
 * \fn void erreur_path_invalide(char* s)
 * \brief fonction qui se déclenche si il y a une erreur de path
 * \param *s est la chaîne de caractères en question
 * */
void erreur_path_invalide(char *s);

/**
 * \fn void erreur_creation_processus()
 * \brief fonction qui se déclenche si il y a une erreur de création de processus
 * */
void erreur_creation_processus();

/**
 * \fn void erreur_creation_tube()
 * \brief fonction qui se déclenche si il y a une erreur de création de tube
 * */
void erreur_creation_tube();

/**
 * \fn void erreur_ecriture_tube()
 * \brief fonction qui se déclenche si il y a une erreur d'écriture dans un tube
 * */
void erreur_ecriture_tube();

/**
 * \fn void erreur_lecture_tube()
 * \brief fonction qui se déclenche si il y a une erreur de lecture dans un tube
 * */
void erreur_lecture_tube();

/**
 * \fn void erreur_initialisation_mutex()
 * \brief fonction qui se déclenche si il y a une erreur d'initialisation d'un mutex
 * */
void erreur_initialisation_mutex();

/**
 * \fn void erreur_destruction_mutex()
 * \brief fonction qui se déclenche si il y a une erreur de destruction de mutex
 * */
void erreur_destruction_mutex();

/**
 * \fn void erreur_verrouillage_mutex()
 * \brief fonction qui se déclenche si il y a une erreur de verrouillage de mutex
 * */
void erreur_verrouillage_mutex();

/**
 * \fn void erreur_deverrouillage_mutex()
 * \brief fonction qui se déclenche si il y a une erreur de déverrouillage de mutex
 * */
void erreur_deverrouillage_mutex();

/**
 * \fn void erreur_initialisation_condition()
 * \brief fonction qui se déclenche si il y a une erreur d'initialisation de condition
 * */
void erreur_initialisation_condition();

/**
 * \fn void erreur_attente_condition()
 * \brief fonction qui se déclenche si il y a une erreur d'attente de condition
 * */
void erreur_attente_condition();

/**
 * \fn void erreur_relance_threads_condition()
 * \brief fonction qui se déclenche si il y a une erreur de relance des threads
 * */
void erreur_relance_threads_condition();

/**
 * \fn void erreur_destruction_condition()
 * \brief fonction qui se déclenche si il y a une erreur de destruction de condition
 * */
void erreur_destruction_condition();

/**
 * \fn void erreur_creation_thread()
 * \brief fonction qui se déclenche si il y a une erreur de creation de thread
 * */
void erreur_creation_thread();

/**
 * \fn void erreur_destruction_thread()
 * \brief fonction qui se déclenche si il y a une erreur de destruction de thread
 * */
void erreur_destruction_thread();

/**
 * \fn void erreur_attente_fin_processus()
 * \brief fonction qui se déclenche si il y a une erreur d'attente d'un processus
 * */
void erreur_attente_fin_processus();

#endif
