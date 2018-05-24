/**
 * \file gestion_erreurs.c
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient les fonctions concernant la gestion des erreurs
 */

#include <stdlib.h>
#include "types.h"
#include "proces_thread.h"
#include "lire_ecrire.h"
#include "cipher.h"
#include "gestion_erreurs.h"

void erreur_ouverture_fichier()
{
	my_printf("ERREUR A L'OUVERTURE DU FICHIER\n");
	exit(1);
}

void erreur_lecture_fichier()
{
	my_printf("ERREUR A LA LECTURE DU FICHIER\n");
	exit(2);
}

void erreur_pas_chiffrement()
{
	my_printf
	    ("ERREUR LORS DE LA LECTURE DU SENS DE CHIFFREMENT D'UN DES MESSAGES\n");
	exit(3);
}

void erreur_nombre_trop_grand()
{
	my_printf("ERREUR NOMBRE DEPASSANT LA LIMITE\n");
	exit(4);
}

void erreur_utilisation_lseek()
{
	my_printf("ERREUR A LORS DE L'UTILISATION DE LA PRIMITIVE LSEEK\n");
	exit(5);
}

void erreur_fermeture_fichier()
{
	my_printf("ERREUR A LA FERMETURE DU FICHIER\n");
	exit(6);
}

void erreur_aucun_argument()
{
	my_printf("AUCUN ARGUMENT SUR LA LIGNE DE COMMANDE\n");
	exit(7);
}

void erreur_creation_processus()
{
	my_printf("PROBLEME A LA CREATION D'UN PROCESSUS\n");
	exit(8);
}

void erreur_path_invalide(char *s)
{
	my_printf("ERREUR AU NIVEAU DU PATH ");
	my_printf(s);
	my_printf("\n");
	exit(9);
}

void erreur_creation_tube()
{
	my_printf("ERREUR DANS LA CREATION DU TUBE\n");
	exit(10);
}

void erreur_ecriture_tube()
{
	my_printf("ERREUR LORS DE L'ECRITURE DANS UN TUBE\n");
	exit(11);
}

void erreur_lecture_tube()
{
	my_printf("ERREUR LORS DE LA LECTURE DANS UN TUBE\n");
	exit(12);
}

void erreur_ecriture_fichier()
{
	my_printf("ERREUR LORS DE L'ECRITURE DANS UN FICHIER\n");
	exit(13);
}

void erreur_initialisation_mutex()
{
	my_printf("ERREUR LORS DE L'INITIALISATION D'UN MUTEX\n");
	exit(14);
}

void erreur_destruction_mutex()
{
	my_printf("ERREUR LORS DE LA DESTRUCTION D'UN MUTEX\n");
	exit(15);
}

void erreur_verrouillage_mutex()
{
	my_printf("ERREUR LORS DU VERROUILLAGE D'UN MUTEX\n");
	exit(16);
}

void erreur_deverrouillage_mutex()
{
	my_printf("ERREUR LORS DU DEVERROUILLAGE D'UN MUTEX\n");
	exit(17);
}

void erreur_initialisation_condition()
{
	my_printf("ERREUR LORS DE L'INITIALISATION D'UNE CONDITION\n");
	exit(18);
}

void erreur_attente_condition()
{
	my_printf("ERREUR LORS DE L'ATTENTE D'UNE CONDITION\n");
	exit(19);
}

void erreur_relance_threads_condition()
{
	my_printf("ERREUR LORS DE LA RELANCE DES THREADS\n");
	exit(20);
}

void erreur_destruction_condition()
{
	my_printf("ERREUR LORS DE LA DESTRUCTION D'UNE CONDITION\n");
	exit(21);
}

void erreur_creation_thread()
{
	my_printf("ERREUR LORS DE LA CREATION D'UN THREAD\n");
	exit(13);
}

void erreur_destruction_thread()
{
	my_printf("ERREUR LORS DE LA DESTRUCTION D'UN THREAD\n");
	exit(14);
}

void erreur_attente_fin_processus()
{
	my_printf("ERREUR LORS DE L'ATTENTE D'UN PROCESSUS\n");
}
