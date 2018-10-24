/**
 * \file cipher.c
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient les fonctions concernant le chiffrement/déchiffrement de lettres
 */

#include "types.h"
#include "proces_thread.h"
#include "lire_ecrire.h"
#include "cipher.h"
#include "gestion_erreurs.h"

char cipher(char c, int pas, char sens)
{
	if (!teste_lettre(c))
		return c;	//si ce n'est pas une lettre on ne la modifie pas
	else {
		if (sens == 'c') {	//si c'est un chiffrement
			if ((c >= 'A') && (c <= 'Z')) {	//majuscule
				c = (c - 'A' + pas) % 26 + 'A';
			} else
				c = (c - 'a' + pas) % 26 + 'a';	//minuscule
		} else {	//si c'est un déchiffrement
			if ((c >= 'A') && (c <= 'Z')) {	//majuscule
				c = ((c - 'A' - pas) % 26);
				if (c < 0)
					c = 'Z' + c + 1;
				else
					c = c + 'A';
			} else {	//minuscule
				c = ((c - 'a' - pas) % 26);
				if (c < 0)
					c = 'z' + c + 1;
				else
					c = c + 'a';
			}
		}
	}
	return c;
}
