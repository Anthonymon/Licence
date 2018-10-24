/**
 * \file proces_thread.h
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient les signatures et les structures majeures du projet
 */

#include <pthread.h>

#ifndef __PROCES_THREAD_H
#define __PROCES_THREAD_H

/**
 * \struct THREAD
 * \brief structure qui contient toutes les informations relatives
 * aux travaux des threads 
 * */
typedef struct {
	int num_case_buf;	/*!< numero de la première lettre du mot à chiffrer/déchiffrer */
	char *p_buf;		/*!< pointeur sur le buffer */
	int *p_pas_chiff;	/*!< pointeur sur le pas de chiffrement */
	char *p_sens_chiff;	/*!< pointeur sur le sens de chiffrement */
	pthread_t thr;		/*!< thread associé au mot */
	pthread_mutex_t *mut;	/*!< pointeur sur le mutex de synchronisation */
	pthread_cond_t *cond;	/*!< pointeur sur la condition de synchronisation */
	int nb_threads_totaux;	/*!< utile pour la fonction barriere (synchronisation des threads) */
	int *compteur_threads;	/*!< utile pour la fonction barriere (synchrnonisation) */
} THREAD;

/**
 * \struct ANALYSE
 * \brief structure qui contient toutes les informations générales aux messages à chiffrer/déchiffrer
 * */
typedef struct {
	char path[256];		/*!< chemin vers le message */
	int pas_chiffrement;	/*!< pas de chiffrement du message */
	char sens_chiffrement;	/*!< sens de chiffrement du message */
	pid_t pid;		/*!< pid du processus associé au message */
	char *buffer;		/*!< contient le message (alloué par le chef d'équipe) */
	THREAD *thread;		/*!< contient les informations pour chaque thread (chaque mot) */
	int tube[2];		/*!< tube de communication entre chef d'équipe et directeur */
} ANALYSE;

/**
 * \struct elem
 * \brief structure pour implémenter une liste chaînée d'élements ANALYSE
 * */
struct elem {
	ANALYSE a;		/*!< élément de la liste */
	struct elem *suiv;	/*!< pointeur sur l'élément suivant */
};

/* Fonctions relatives à la manipulation de listes */
/**
 * \fn struct elem* cree_liste_vide(void)
 * \brief crée une liste vide
 * \return retourne une liste vide (qui pointe sur NULL)
 * */
struct elem *cree_liste_vide();

/**
 * \fn int teste_liste_vide(struct elem* l)
 * \brief teste si la liste est vide
 * \param *l liste que l'on veut tester
 * \return retourne 1 si c'est vide et 0 sinon
 * */
int teste_liste_vide(struct elem *l);

/**
 * \fn struct elem* ajoute_elem_fin(struct elem* l,ANALYSE i)
 * \brief ajoute à la fin de la liste l'élément i
 * \param *l est la liste à modifier et i l'élément à insérer
 * \param i est l'élément à insérer
 * \return retourne la nouvelle liste où l'élément a été inséré
 * */
struct elem *ajoute_elem_fin(struct elem *l, ANALYSE i);

/**
 * \fn struct elem* libere(struct elem* l)
 * \brief libère la mémoire allouée pour la liste 
 * \param l est la liste à libérer
 * \return retourne NULL
 * */
struct elem *libere(struct elem *l);

/**
 * \fn void libere_liste(struct elem* l)
 * \brief libère la mémoire allouée pour la liste (fonction à utiliser)
 * \param l est la liste à libérer
 * */
void libere_liste(struct elem *l);

/* Fin des fonctions relatives à la manipulation de listes */

/**
 * \fn int compte_nb_messages(int file)
 * \brief fonction qui compte le nombre de messages contenus dans le fichier principal
 * \param file est le descripteur du fichier où l'on veut compter les messages
 * \return nombre de messages écrit dans file
 * */
int compte_nb_messages(int file);

/**
 * \fn int convertit_char_int(char c)
 * \brief fonction qui convertit les caractères de '0' à '9' en chiffre
 * \param c est le caractère à convertir
 * \return nombre de messages écrit dans file
 * */
int convertit_char_int(char c);

/**
 * \fn int calcul_puissance_10(int n)
 * \brief fonction qui calcule 10^n
 * \param n est la puissance de 10 à calculer
 * \return puissance de 10^n
 * */
int calcul_puissance_10(int n);

/**
 * \fn int teste_lettre(char c)
 * \brief teste si il s'agit d'une lettre de l'alphabet
 * \param c est le caractère à tester
 * \return 1 si c'est une lettre, 0 sinon
 * */
int teste_lettre(char c);

/**
 * \fn int teste_espace_tab_entr(char c)
 * \brief teste si il s'agit d'un espace, d'une tabulation ou d'un retour à la ligne
 * \param c est le caractère à tester
 * \return 1 si c'est c'est un espace/tabulation/retour à la ligne, 0 sinon
 * */
int teste_espace_tab_entr(char c);

/**
 * \fn struct elem* analyse_messages(char* nomFichier)
 * \brief fonction qui remplit la liste de struct elem* des informations issues du fichier principal
 * \param *nomFichier chaîne de caractères qui correspond au nom du fichier
 * \return liste d'éléments ANALYSE qui contiennent les informations des messages à chiffrer/déchiffrer
 * */
struct elem *analyse_messages(char *nomFichier);

/**
 * \fn int compte_nb_mots(char* buf,int taille)
 * \brief fonction qui renvoie le nombre de mots dans la chaîne de caractères de taille "taille"
 * \param buf est la chaîne de caractères à tester
 * \param taille est le nombre de caractères de buf
 * \return int nombre de mots dans buf
 * */
int compte_nb_mots(char *buf, int taille);

/**
 * \fn int place_rang_mot(char *buf, int taille, int nb_mots, int num_mot)
 * \brief fonction qui renvoie le numero de la case de la première lettre du num_mot dans la chaine de caractères buf
 * \param buf est la chaîne de caractères
 * \param taille est le nombre de caractères de buf
 * \param nb_mots est le nombre de mots dans buf
 * \param num_mot est le numéro du mot à choisir
 * \return int rang de la première lettre du num_mot mot
 * */
int place_rang_mot(char *buf, int taille, int nb_mots, int num_mot);

/**
 * \fn void barriere(int nbThreads, int *compteurBarriere, pthread_mutex_t * mutex,pthread_cond_t * cond)
 * \brief fonction qui permet de synchroniser les threads
 * \param nbThreads est le nombre total de threads qui agissent sur la même chaîne de caractères
 * \param compteurBarriere est un pointeur sur le nombre de threads qui ont été arrêtés par barriere
 * \param mutex est un pointeur sur un mutex (utilisé pour la barriere)
 * \param cond est un pointeur sur une condition (utilisé pour la barriere)
 * */
void barriere(int nbThreads, int *compteurBarriere, pthread_mutex_t * mutex,
	      pthread_cond_t * cond);

/**
 * \fn ANALYSE initialise_thread(ANALYSE a, int n)
 * \brief fonction qui initialise les n threads de a
 * \param a est la structure dans laquelle on va initialiser les threads
 * \param n est le nombre de threads dans a
 * \return ANALYSE est a initialisé
 * */
ANALYSE initialise_thread(ANALYSE a, int n);

/**
 * \fn void ecrit_chiffrement(ANALYSE a)
 * \brief fonction qui écrit le chiffrement dans un nouveau fichier créé
 * \param a est la structure qui contient toutes les informations utiles pour créer ce nouveau fichier
 * */
void ecrit_chiffrement(ANALYSE a);

/**
 * \fn void ecrit_dechiffrement(ANALYSE a)
 * \brief fonction qui écrit le déchiffrement sur le terminal
 * \param a est la structure qui contient toutes les informations utiles pour écrire le déchiffrement
 * */
void ecrit_dechiffrement(ANALYSE a);

/* Fonctions principales qui correspondent aux travaux des différents acteurs */

/**
 * \fn void *threads_employes(void *val)
 * \brief fonction qui fait le travail des employés. En fonction du mot donné, l'employé va chiffrer/déchiffrer le mot en entier et modifier la structure buffer
 * du chef d'équipe grâce à un pointeur sur celui-ci
 * \param val sera transformé en type THREAD
 * \return retourne NULL
 * */
void *threads_employes(void *val);

/**
 * \fn void processus_chef_dequipe(ANALYSE a)
 * \brief Fonction qui fait le travail des chefs d'équipe
 * Le chef d'équipe va créer pour chaque mot du message un thread
 * \param a est la structure qui contient toutes les informations pour le chef d'équipe
 * */
void processus_chef_dequipe(ANALYSE a);

/**
 * \fn void processus_directeur(int argc,char** argv)
 * \brief Fonction qui fait le travail du chef directeur. Pour chaque message il va créer un processus qui va le chiffrer/déchiffrer
 * \param argc est le nombre de mots dans les commandes
 * \param **argv est le tableau des mots des commandes
 * */
void processus_directeur(int argc, char **argv);

#endif
