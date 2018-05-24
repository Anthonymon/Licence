/**
 * \file lire_ecrire.h
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient les signatures des fonctions concernant la lecture/écriture
 */

#ifndef __LIRE_ECRIRE_H
#define __LIRE_ECRIRE_H

/**
 * \fn void my_printf(char* c)
 * \brief fonction qui affiche dans le terminal la chaine de caractères en argument
 * \param *c chaîne de caractères à afficher
 * */
void my_printf(char *c);

/**
 * \fn int lecture_decalage(int file)
 * \brief fonction qui renvoie le décalage du message (là où on est dans le fichier principal)
 * \param file est le descripteur du fichier à lire
 * \return int est l'entier représentant le décalage lu
 * */
int lecture_decalage(int file);

/**
 * \fn char lecture_sens(int file)
 * \brief fonction qui renvoie la lettre représentant le sens de chiffrement
 * \param file est le descripteur du fichier à lire
 * \return char est le caractère représentant le sens de chiffrement lu
 * */
char lecture_sens(int file);

/**
 * \fn int compte_nb_caracteres(char* nomFichier)
 * \brief fonction qui compte le nombre de caractères dans nomFichier
 * \param nomFichier est la chaîne de caractères représentant le nom du fichier à lire
 * \return int représente le nombre de caractères lu dans nomFichier
 * */
int compte_nb_caracteres(char *nomFichier);

/**
 * \fn char* concatenation_extension(char* s)
 * \brief fonction qui concatène une chaîne de caractères et "_cypher"
 * \param *s chaîne de caractères à concatener
 * \return char* est le pointeur sur la nouvelle chaîne de caractères concaténée avec "_cypher"
 * */
char *concatenation_extension(char *s);

#endif
