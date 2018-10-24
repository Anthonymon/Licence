/**
 * \file proces_thread.c
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient les fonctions concernant le travail des processus et des threads
 */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "types.h"
#include "proces_thread.h"
#include "lire_ecrire.h"
#include "cipher.h"
#include "gestion_erreurs.h"

struct elem *cree_liste_vide()
{
	return NULL;
}

int teste_liste_vide(struct elem *l)
{
	if (l == NULL)
		return 1;
	return 0;
}

struct elem *ajoute_elem_fin(struct elem *l, ANALYSE i)
{
	struct elem *new = malloc(sizeof(struct elem));
	new->a = i;
	new->suiv = NULL;
	if (teste_liste_vide(l)) {
		return new;
	}
	struct elem *debut = l;
	while (l->suiv)
		l = l->suiv;
	l->suiv = new;
	return debut;
}

struct elem *libere(struct elem *l)
{
	struct elem *tmp;
	while (l) {
		tmp = l->suiv;
		free(l);
		l = tmp;
	}
	return NULL;
}

void libere_liste(struct elem *l)
{
	l = libere(l);
}

int compte_nb_messages(int file)
{
	int d = 1;
	int compteur = 0;
	char c = 'a';
	while (d != 0) {
		d = read(file, &c, 1);
		if (d == -1)
			erreur_lecture_fichier();
		if (c == '\n')
			compteur++;	//à chaque saut de ligne on incrémente
	}
	int u = lseek(file, 0, SEEK_SET);
	if (u == -1)
		erreur_utilisation_lseek();
	return compteur - 1;
}

int convertit_char_int(char c)
{
	if (c == '0')
		return 0;
	else if (c == '1')
		return 1;
	else if (c == '2')
		return 2;
	else if (c == '3')
		return 3;
	else if (c == '4')
		return 4;
	else if (c == '5')
		return 5;
	else if (c == '6')
		return 6;
	else if (c == '7')
		return 7;
	else if (c == '8')
		return 8;
	else
		return 9;
}

int calcul_puissance_10(int n)
{
	if (n == 0)
		return 1;
	int i;
	int pow = 10;
	for (i = 0; i < n - 1; i++) {
		pow = pow * 10;
	}
	return pow;
}

int teste_lettre(char c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
		return 1;
	}
	return 0;
}

int teste_espace_tab_entr(char c)
{
	if (c == ' ')
		return 1;
	else if (c == '\n')
		return 1;
	else if (c == '\t')
		return 1;
	else
		return 0;
}

struct elem *analyse_messages(char *nomFichier)
{
	int file = open(nomFichier, O_RDONLY);
	if (file == -1)
		erreur_ouverture_fichier();
	int nb_messages = compte_nb_messages(file);
	char c;
	int t, d, compteur;
	struct elem *retour = cree_liste_vide();
	int i = 0;
	ANALYSE a;
	while (i < nb_messages) {
		c = 'a';
		compteur = 0;
		while (c != ';') {	//lecture du path
			d = read(file, &c, 1);
			if (d == -1)
				erreur_lecture_fichier();
			a.path[compteur] = c;
			compteur++;
		}
		a.path[compteur - 1] = '\0';
		a.pas_chiffrement = lecture_decalage(file);	//lecture du pas de chiffrement
		a.sens_chiffrement = lecture_sens(file);	//lecture du sens de chiffrement
		t = pipe(a.tube);	//creation du tube (1 par message)
		if (t == -1)
			erreur_creation_tube();
		retour = ajoute_elem_fin(retour, a);
		i++;
	}
	d = close(file);
	if (d == -1)
		erreur_fermeture_fichier();
	return retour;
}

int compte_nb_mots(char *buf, int taille)
{
	int compteur = 0;
	int i, j;
	if (!teste_espace_tab_entr(buf[0]))
		compteur++;
	for (i = 0; i < taille - 1; i++) {
		if (teste_espace_tab_entr(buf[i])) {
			j = i + 1;
			if (!teste_espace_tab_entr(buf[j])) {
				compteur++;
			}
		}
	}
	return compteur;
}

int place_rang_mot(char *buf, int taille, int nb_mots, int num_mot)
{
	if (nb_mots < num_mot)
		erreur_lecture_fichier();
	int i, j;
	int compteur = 0;
	if ((!teste_espace_tab_entr(buf[0])) && (num_mot == 0)) {
		return 0;
	}
	for (i = 0; i < taille - 1; i++) {
		if (teste_espace_tab_entr(buf[i])) {
			j = i + 1;
			if (!teste_espace_tab_entr(buf[j])) {
				compteur++;
			}
			if (compteur == num_mot) {
				return j;
			}
		}
	}
	return 0;
}

void barriere(int nbThreads, int *compteurBarriere, pthread_mutex_t * mutex,
	      pthread_cond_t * cond)
{
	int d = pthread_mutex_lock(mutex);
	if (d != 0)
		erreur_verrouillage_mutex();
	compteurBarriere++;
	if (compteurBarriere < (&nbThreads)) {
		d = pthread_cond_wait(cond, mutex);
		if (d != 0)
			erreur_attente_condition();
	} else {
		d = pthread_cond_broadcast(cond);	//relance des threads
		if (d != 0)
			erreur_relance_threads_condition();
		compteurBarriere = 0;
	}
	d = pthread_mutex_unlock(mutex);
	if (d != 0)
		erreur_deverrouillage_mutex(mutex);
}

ANALYSE initialise_thread(ANALYSE a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		a.thread[i].p_buf = a.buffer;
		a.thread[i].p_pas_chiff = &a.pas_chiffrement;
		a.thread[i].p_sens_chiff = &a.sens_chiffrement;
	}
	return a;
}

void *threads_employes(void *val)
{
	THREAD t = *((THREAD *) val);
	int pas = *t.p_pas_chiff;
	char sens = *t.p_sens_chiff;
	int i = t.num_case_buf;
	char c = t.p_buf[i];
	while ((c != ' ') && (c != '\n') && (c != '\t') && (c != '\0')) {
		t.p_buf[i] = cipher(t.p_buf[i], pas, sens);	//chiffrement/déchiffrement
		i++;
		c = t.p_buf[i];
	}
	//synchronisation des threads
	barriere(t.nb_threads_totaux, (t.compteur_threads), t.mut, t.cond);
	return NULL;
}

void ecrit_chiffrement(ANALYSE a)
{
	int i = 0;
	int d;
	char *new_path = concatenation_extension(a.path);
	my_printf("Le chiffrement du message ");
	my_printf(a.path);
	my_printf(" a été écrit dans ");
	my_printf(new_path);
	my_printf
	    ("\n-----------------------------------------------------------------------------\n");
	int file = open(new_path, FLAGS, MODES);	//création du nouveau fichier
	if (file == -1)
		erreur_ouverture_fichier();
	while (a.buffer[i] != '\0') {
		d = write(file, &(a.buffer[i]), 1);	//écriture dans le nouveau fichier
		if (d == -1)
			erreur_ecriture_fichier();
		i++;
	}
	free(new_path);
	i = close(file);
	if (i == -1)
		erreur_fermeture_fichier();
}

void ecrit_dechiffrement(ANALYSE a)
{
	int i;
	int n = compte_nb_caracteres(a.path) + 1;
	a.buffer = malloc(n * sizeof(char));
	i = read(a.tube[0], a.buffer, n);
	if (i == -1)
		erreur_lecture_tube();
	my_printf("Le déchiffrement du message ");
	my_printf(a.path);
	my_printf(" est le suivant: \n");
	my_printf(a.buffer);
	my_printf
	    ("\n-----------------------------------------------------------------------------\n");
	free(a.buffer);
}

void processus_chef_dequipe(ANALYSE a)
{
	////////////////////////////////////
	pthread_cond_t condi;
	int e = pthread_cond_init(&condi, NULL);
	if (e != 0)
		erreur_initialisation_condition();
	pthread_mutex_t mutex_synchro;
	e = pthread_mutex_init(&mutex_synchro, NULL);
	if (e != 0)
		erreur_initialisation_mutex();
	int compteurThreads = 0;
	///////////////////////////////////////////:
	int file = open(a.path, O_RDONLY);
	if (file == -1)
		erreur_path_invalide(a.path);
	char c = 'a';
	int d = 1;
	int i, k;
	int compteur = 0;
	while (d != 0) { //lecture et stockage du buffer
		d = read(file, &c, 1);
		if (d == -1)
			erreur_lecture_fichier();
		compteur++;
	}
	compteur--;
	//allocation du buffer par le chef d'équipe
	a.buffer = malloc(compteur * sizeof(char) + sizeof(char));
	int u = lseek(file, 0, SEEK_SET);
	if (u == -1)
		erreur_utilisation_lseek();
	for (i = 0; i < compteur; i++) {
		d = read(file, &c, 1);
		if (d == -1)
			erreur_lecture_fichier();
		a.buffer[i] = c;
	}
	a.buffer[i] = '\0';
	/////////////////////////////
	int taille = i + 1;
	my_printf("- Le contenu du message ");
	my_printf(a.path);
	my_printf(" est :\n");
	my_printf(a.buffer);
	my_printf("\n");
	int nb_mots = compte_nb_mots(a.buffer, compteur);
	//allocation du nombre de THREAD en fonction du nombre de mots
	a.thread = malloc(nb_mots * sizeof(THREAD));
	a = initialise_thread(a, nb_mots);
	for (i = 0; i < nb_mots; i++) { //initialisation des threads 
		a.thread[i].nb_threads_totaux = nb_mots;
		a.thread[i].compteur_threads = &compteurThreads;
		a.thread[i].mut = &mutex_synchro;	//1 mutex de synchronisation par message
		a.thread[i].cond = &condi;	//1 condition de synchronisation par message
		a.thread[i].num_case_buf =
		    place_rang_mot(a.buffer, compteur, nb_mots, i);
		k = pthread_create(&(a.thread[i].thr), NULL, threads_employes,
				   &(a.thread[i]));
		if (k != 0)
			erreur_creation_thread();
	}
	for (i = 0; i < nb_mots; i++) {
		k = pthread_join(a.thread[i].thr, NULL);
		if (k != 0)
			erreur_destruction_thread();
	}
	if (a.sens_chiffrement == 'c') {
		ecrit_chiffrement(a); //écriture dans un nouveau fichier
	}
	k = close(a.tube[0]);
	if (k == -1)
		erreur_fermeture_fichier();
	int j = write(a.tube[1], a.buffer, taille);
	if (j == -1)
		erreur_ecriture_tube();
	k = close(a.tube[1]);
	if (k == -1)
		erreur_fermeture_fichier();
	free(a.buffer);
	free(a.thread);
	///////////////////////////////////////
	e = pthread_cond_destroy(&condi);
	if (e != 0)
		erreur_destruction_condition();
	e = pthread_mutex_destroy(&mutex_synchro);
	if (e != 0)
		erreur_destruction_mutex();
}

void processus_directeur(int argc, char **argv)
{
	struct elem *liste = analyse_messages(argv[1]);
	struct elem *temp1 = liste;
	int status;
	int k;
	while (!teste_liste_vide(temp1)) {
		temp1->a.pid = fork();
		if (temp1->a.pid == -1)
			erreur_creation_processus();
		if (temp1->a.pid == 0) {	//fils
			processus_chef_dequipe(temp1->a);
			break;
		} else {	//pere;
			k = wait(&status);
			if (k == -1)
				erreur_attente_fin_processus();
			if (temp1->a.sens_chiffrement == 'd') {
				ecrit_dechiffrement(temp1->a);
			}
		}
		temp1 = temp1->suiv;
	}
	libere_liste(liste);
}
