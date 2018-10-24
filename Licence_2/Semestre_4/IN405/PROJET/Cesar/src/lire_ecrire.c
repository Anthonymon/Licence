/**
 * \file lire_ecrire.c
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient les fonctions concernant la lecture et écriture dans un fichier
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "proces_thread.h"
#include "lire_ecrire.h"
#include "cipher.h"
#include "gestion_erreurs.h"

void my_printf(char *c)
{
	int i = 0;
	int d;
	while (c[i] != '\0') {
		d = write(0, &(c[i]), 1);
		if (d == -1)
			erreur_ecriture_fichier();
		i++;
	}
}

int lecture_decalage(int file)
{
	int compteur = 0;
	int i, d;
	int retour = 0;
	char chiffre = 'a';
	while (chiffre != ';') {	//compte le nombre de chiffres dans le nombre
		d = read(file, &chiffre, 1);
		if (d == -1)
			erreur_lecture_fichier();
		compteur++;
	}
	if (compteur > 9)
		erreur_nombre_trop_grand();
	d = lseek(file, -compteur, SEEK_CUR);	//on revient au ';'
	if (d == -1)
		erreur_utilisation_lseek();
	for (i = 0; i < compteur - 1; i++) {	//formation du nombre
		d = read(file, &chiffre, 1);
		if (d == -1)
			erreur_lecture_fichier();
		retour +=
		    convertit_char_int(chiffre) * calcul_puissance_10(compteur -
								      2 - i);
	}
	return retour;
}

char lecture_sens(int file)
{
	char lettre;
	char retour;
	int d = read(file, &lettre, 1);	//lit le ';'
	if (d == -1)
		erreur_lecture_fichier();
	d = read(file, &lettre, 1);	//lit la lettre
	if (d == -1)
		erreur_lecture_fichier();
	if ((lettre != 'd') && (lettre != 'c'))
		erreur_pas_chiffrement();
	retour = lettre;
	d = read(file, &lettre, 1);	//lit le '\n';
	if (d == -1)
		erreur_lecture_fichier();
	return retour;
}

int compte_nb_caracteres(char *nomFichier)
{
	int file = open(nomFichier, O_RDONLY);
	if (file == -1)
		erreur_ouverture_fichier();
	int compteur = 0;
	int d = 1;
	int e;
	char c;
	while (d != 0) {
		d = read(file, &c, 1);
		if (d == -1)
			erreur_lecture_fichier();
		compteur++;
	}
	e = close(file);
	if (e == -1)
		erreur_fermeture_fichier();
	return compteur;
}

char *concatenation_extension(char *s)
{
	char *concat =
	    malloc(strlen(s) * sizeof(char) + strlen("_cypher") * sizeof(char) +
		   sizeof(char));
	char *final = strcat(strcpy(concat, s), "_cypher");
	final[strlen(final)] = '\0';
	return final;
}
