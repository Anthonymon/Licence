// Clément CAUMES 21501810
// 09 janvier 2017
// PROJET SOKOBAN

// lire_ecrire.c du projet SOKOBAN
// Contient toutes les fonctions relatives à la lecture/écriture des fichiers et des commandes de l'utilisateur

#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "sokoban.h"
#include "action_crea.h"
#include "action_jeu.h"
#include "gestion_plateau.h"
#include "types.h"

// Fonction qui renvoie 1 si les mots sont identiques et 0 sinon
int teste_mots_identiques(char *s1, char *s2)
{
	if (strcmp(s1, s2) == 0) {
		return 1;
	}
	return 0;
}

// Teste si la chaine de caractères s1 a l'extension .xsb
int teste_extension_xsb(char *s1)
{
	char *extansion = s1;
	int num = strlen(s1);
	extansion = s1 + num - strlen(".xsb");
	return teste_mots_identiques(extansion, ".xsb");
}

// Teste si la chaine de caractères s1 a l'extension .txt
int teste_extension_txt(char *s1)
{
	char *extansion = s1;
	int num = strlen(s1);
	extansion = s1 + num - strlen(".txt");
	return teste_mots_identiques(extansion, ".txt");
}

// Renvoie 1 si le mot contient une extension de 3 lettres à la fin, 0 sinon
int teste_presence_extension(char *mot)
{
	if (mot[strlen(mot) - 4] == '.') {
		return 1;
	}
	return 0;
}

// Renvoie la concaténation du mot avec l'extension .xsb
char *concatenation_extension(char *s)
{
	char *concat =
	    malloc(strlen(s) * sizeof(char) + strlen(".xsb") * sizeof(char) +
		   sizeof(char));
	char *final = strcat(strcpy(concat, s), ".xsb");
	final[strlen(final)] = '\0';
	return final;
}

// Alloue de la mémoire pour une copie d'une chaine de caractères en argument
char *copie_nom(char *origine)
{
	char *copie = malloc(strlen(origine) * sizeof(char) + sizeof(char));
	int compteur = 0;
	while (compteur != strlen(origine) + 1) {
		copie[compteur] = origine[compteur];
		compteur++;
	}
	return copie;
}

// Fonction qui change les 3 dernières lettres en "xsb"
char *modifie_extension(char *mot)
{
	char *final = copie_nom(mot);
	final[strlen(final) - 3] = 'x';
	final[strlen(final) - 2] = 's';
	final[strlen(final) - 1] = 'b';
	return final;
}

// Affiche sur le terminal un rappel des commandes du projet SOKOBAN
void affiche_rappel_commandes()
{
	printf("\033[01m\n");
	printf("- SI VOUS VOULEZ CREER UN NIVEAU :\n");
	printf("  ./sokoban -c ficout.xsb\n");
	printf("- SI VOUS VOULEZ JOUER AU JEU :\n");
	printf
	    ("  ./sokoban -n num ficin.xsb AVEC num UN NOMBRE SUPERIEUR A 0\n");
	printf("  ./sokoban ficin.xsb\n");
	printf("REMARQUE : VOUS POUVEZ REMPLACER L'EXTENSION .xsb PAR .txt\n");
	printf("\n\033[0m");
}

// Renvoie 0 si la chaine de caractères n'est pas un nombre, 1 sinon
int teste_nombre(char *s)
{
	int i = 0;
	while (s[i] != '\0') {
		if (isdigit(s[i]) == 0) {
			return 0;
		}
		i++;
	}
	return 1;
}

// Procédure à appeler quand il y a un problème de mémoire (lors de mallocs)
void quitte_probleme_memoire()
{
	printf("\033[01m\nPROBLEME DE MEMOIRE\n\n\033[0m");
	exit(1);
}

// Procédure à appeler quand le fichier est vide
void quitte_fichier_vide(char c, FILE * f)
{
	if (c == EOF) {
		printf("\033[01m\nFICHIER VIDE\n\033[0m");
		fclose(f);
		exit(2);
	}
}

// Procédure à appeler quand le fichier n'est pas valable
void quitte_fichier_non_valable(FILE * f)
{
	printf("\033[01m\nFICHIER NON VALABLE\n\n\033[0m");
	fclose(f);
	exit(2);
}

// Procédure à appeler quand l'utilisateur demande un fichier qui n'existe pas 
void quitte_fichier_inexistant()
{
	printf("\033[01m\nFICHIER INEXISTANT \n\n\033[0m");
	exit(2);
}

// Procédure à appeler quand l'utilisateur (pour la création) demande un nom d'un fichier qui existe déjà
void quitte_fichier_deja_existant(FILE * f, char *nom)
{
	printf("\033[01m\nFICHIER DEJA EXISTANT\n\n\033[0m");
	free(nom);
	fclose(f);
	exit(2);
}

// Procédure à appeler quand le nom proposé par l'utilisateur n'est pas valable
void quitte_nom_pas_valable()
{
	printf("\033[01m\nNOM DU FICHIER NON VALABLE\n\033[0m");
	affiche_rappel_commandes();
	exit(3);
}

// Procédure à appeler quand le niveau demandé par l'utilisateur n'est pas disponible
void quitte_niveau_demande_indisponible()
{
	printf("\033[01m\nNIVEAU DEMANDE INDISPONIBLE\n\n\033[0m");
	exit(3);
}

// Procédure à appeler quand l'utilisateur n'a pas tapé les bonnes commandes
void quitte_commande_introuvable()
{
	affiche_rappel_commandes();
	exit(3);
}

// Teste si le fichier respecte les regles d'ecriture d'un fichier pour sokoban
int calcul_niveau_max(char *nomFichier)
{
	FILE *f = fopen(nomFichier, "r");
	char c = fgetc(f);
	quitte_fichier_vide(c, f);	//on teste d'abord si le fichier est vide
	ungetc(c, f);
	int num = 0;
	int temp;
	do {			//on recherche les ';' et si il y a un chiffre derrière
		c = fgetc(f);
		if (c == ';') {
			fgetc(f);
			c = fgetc(f);
			if (isdigit(c)) {
				ungetc(c, f);
				fscanf(f, "%d", &temp);
				if (temp == num + 1) {	//il faut que les niveaux soient rangés dans un ordre croissant
					num = temp;
				} else
					quitte_fichier_non_valable(f);
			} else if (isdigit(c) == 0)
				quitte_fichier_non_valable(f);
		}
	} while (c != EOF);
	fclose(f);
	return num;
}

// Retourne MODE_JEU si le fichier est valable, 0 sinon
int retourne_mode(FILE * f, char *nom)
{
	if (f == NULL)
		quitte_fichier_inexistant();
	else {
		fclose(f);
		if (calcul_niveau_max(nom) >= 1) {
			return MODE_JEU;
		}
	}
	return 0;
}

// Renvoie le mode que l'utilisateur a choisi sur le terminal
int teste_commande(int num, char **chaineCarac)
{
	if (num == 3) {		// MODE_CREATIF choisi
		if (teste_mots_identiques(chaineCarac[1], "-c") == 1) {
			return MODE_CREATIF;
		}
	} else if (num == 2) {	// MODE_JEU choisi
		FILE *f = fopen(chaineCarac[1], "r");
		return retourne_mode(f, chaineCarac[1]);
	} else if (num == 4) {	//MODE_JEU choisi
		if (teste_mots_identiques(chaineCarac[1], "-n") == 1) {
			if (teste_nombre(chaineCarac[2]) == 1) {
				FILE *f = fopen(chaineCarac[3], "r");
				return retourne_mode(f, chaineCarac[3]);
			}
		}
	}
	quitte_commande_introuvable();
	return 0;
}

// Renvoie le nom du fichier choisi par l'utilisateur selon les commandes possibles dans l'interface de création
char *calcul_nom_interface_creation(char **chaineCarac)
{
	char *nom;
	if ((teste_extension_xsb(chaineCarac[2]) == 1)
	    || (teste_extension_txt(chaineCarac[2]) == 1)) {
		nom = copie_nom(chaineCarac[2]);	//si le nom a la bonne extension on renvoie la copie de chaineCarac
	} else {
		if (teste_presence_extension(chaineCarac[2]) == 1) {
			printf
			    ("\033[01m\nLE NOM DU FICHIER A ETE MODIFIE POUR AVOIR UNE EXTENSION VALIDE\033[0m\n");
			nom = modifie_extension(chaineCarac[2]);	//si le nom a la mauvaise extension on renvoie une modification
		} else {	//si il n'y a pas d'extension on fait la concatenation de chaineCarac avec ".xsb"
			printf
			    ("\033[01m\nL'EXTENSION .xsb A ETE RAJOUTEE\033[0m\n");
			nom = concatenation_extension(chaineCarac[2]);
		}
	}
	FILE *f = fopen(nom, "r");
	if (f != NULL) {
		quitte_fichier_deja_existant(f, nom);
	}
	return nom;
}

// Renvoie le nom du fichier choisi par l'utilisateur selon les commandes possibles dans l'interface de jeu
char *calcul_nom_interface_jeu(int num, char **chaineCarac)
{
	if (num == 2) {
		return chaineCarac[1];
	} else
		return chaineCarac[3];
}

// Fonction qui écrit un caractère en fonction de la nature de la case du plateau
void ecrire_caractere(FILE * fichier, PLATEAU p, int x, int y)
{
	if ((p.T[x][y].natureCase == MUR)) {
		fprintf(fichier, "#");	//un mur est représenté par "#"
	}
	if ((p.T[x][y].natureCase == VIDE) && (p.T[x][y].natureElem == CAISSE)) {
		fprintf(fichier, "$");	//une caisse par "$"
	}
	if ((p.T[x][y].natureCase == VIDE) && (p.T[x][y].natureElem == PERSO)) {
		fprintf(fichier, "@");	//un personnage sur une case vide par "@"
	}
	if ((p.T[x][y].natureCase == EMPLACEMENT_CAISSE)
	    && (p.T[x][y].natureElem == CAISSE)) {
		fprintf(fichier, "*");	//une caisse sur un emplacement par "*"
	}
	if ((p.T[x][y].natureCase == EMPLACEMENT_CAISSE)
	    && (p.T[x][y].natureElem == PERSO)) {
		fprintf(fichier, "+");	//un personnage sur un emplacement par "+"
	}
	if ((p.T[x][y].natureCase == EMPLACEMENT_CAISSE)
	    && (p.T[x][y].natureElem == PAS_ELEMENT)) {
		fprintf(fichier, ".");	//un emplacement vide par "."
	}
	if ((p.T[x][y].natureCase == VIDE)
	    && (p.T[x][y].natureElem == PAS_ELEMENT)) {
		fprintf(fichier, " ");	//une case vide par " "
	}
}

// Fonction qui écrit le plateau de ACTIONCREATION dans un fichier nommé "nomFichier"
void ecrire_fichier(char *nomFichier, ACTIONCREATION a)
{
	FILE *f = fopen(nomFichier, "w");
	fprintf(f, "\n");
	fprintf(f, "; 1\n");
	fprintf(f, "\n");
	int x, y;
	for (y = a.plat.nbCases - 1; y >= 0; y--) {
		while ((teste_ligne_vide(a.plat, y) == 1) && (y > 0)) {
			y--;
		}
		for (x = 0; x < a.plat.nbCases; x++) {
			while ((teste_colonne_vide(a.plat, x) == 1)
			       && (x < a.plat.nbCases - 1)) {
				x++;
			}
			ecrire_caractere(f, a.plat, x, y);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	printf
	    ("\033[01m\nLE NIVEAU A ETE CORRECT ET A ETE SAUVEGARDE DANS %s\n\n\033[0m",
	     nomFichier);
}

// Fonction qui permet de lire jusqu'à la fin de la ligne sans sauvegarder les caractères
char parcourt_fin_ligne(char c, FILE * f)
{
	do {
		c = fgetc(f);
	} while ((c != '\n') && (c != EOF));
	return c;
}

// Fonction qui calcule la longueur maximale du plateau dans le case ou le niveau est unique
int calcul_taille_plateau_niveau_unique(FILE * f, int n)
{
	int maxHauteur = 0;
	int maxLargeur = 0;
	int compteurLargeur = 0;
	char c = 'a';
	c = parcourt_fin_ligne(c, f);
	if (c == EOF)
		return 1;	//cas particulier si le niveau est vide
	while ((c != EOF)) {	//parcourt jusqu'à la fin du fichier et cherche le max entre la hauteur et la largeur du plateau
		c = fgetc(f);
		printf("\033[01m%c\033[0m", c);
		compteurLargeur++;
		if (c == '\n') {
			compteurLargeur--;
			if (compteurLargeur > maxLargeur)
				maxLargeur = compteurLargeur;
			compteurLargeur = 0;
			maxHauteur++;
		}
	}
	if (maxHauteur > maxLargeur)
		return maxHauteur;
	else
		return maxLargeur;
}

// Fonction qui calcule la longueur maximale du plateau sur lequel on est
int calcul_taille_plateau(FILE * f, int n)
{
	int maxHauteur = 0;
	int maxLargeur = 0;
	int compteurLargeur = 0;
	char c = 'a';
	c = parcourt_fin_ligne(c, f);
	while ((c != ';') && (c != EOF)) {	//va jusqu'au prochain ';' ou la fin du fichier
		c = fgetc(f);
		printf("\033[01m%c\033[0m", c);
		compteurLargeur++;
		if (c == '\n') {
			compteurLargeur--;
			if (compteurLargeur > maxLargeur)
				maxLargeur = compteurLargeur;
			maxHauteur++;
			compteurLargeur = 0;
		}
	}
	if (maxHauteur > maxLargeur)
		return maxHauteur;	//retourne le max entre la hauteur et la largeur
	else
		return maxLargeur;
}

// Retourne le numero du niveau demandé par l'utilisateur
int retourne_num_niveau_demande(int num, char **chaineCarac)
{
	if (num == 4) {
		return atoi(chaineCarac[2]);
	} else
		return 1;
}

// Retourne la taille du plateau de ACTIONJEU
int retourne_taille_plateau(ACTIONJEU a, char *nomFichier, int num)
{
	if (num <= 0)
		quitte_niveau_demande_indisponible();
	if (num > a.niveauMax)
		quitte_niveau_demande_indisponible();
	else {
		FILE *f = fopen(nomFichier, "r");
		char c = 'a';
		int nombre = -1;
		while (c != EOF) {
			c = fgetc(f);
			if (c == ';') {
				fscanf(f, "%d", &nombre);	//cherche le numero associé à chaque niveau
				if (num == nombre) {
					printf
					    ("\033[01mNIVEAU TROUVE : %d\n\n\033[0m",
					     nombre);
					a.num = nombre;
					do {
						c = fgetc(f);
					} while ((c != '\n') && (c != EOF));
					if (c == EOF) {	//cas particulier si le niveau est vide 
						fclose(f);
						return 1;
					}
					if (a.niveauMax == 1)
						return
						    calcul_taille_plateau_niveau_unique
						    (f, num);
					int cal = calcul_taille_plateau(f, num);	//calcule la taille du plateau
					fclose(f);
					return cal;
				}
			}
		}
		fclose(f);
		quitte_niveau_demande_indisponible();
	}
	return 1;
}

// Remplit le plateau en argument en fonction du caractère
PLATEAU remplit_plateau(PLATEAU p, char c, int x, int y)
{
	if (c == '#') {
		p.T[x][y].natureCase = MUR;
	}
	if (c == '$') {
		p.T[x][y].natureCase = VIDE;
		p.T[x][y].natureElem = CAISSE;
	}
	if (c == '@') {
		p.T[x][y].natureCase = VIDE;
		p.T[x][y].natureElem = PERSO;
		p.posPerso.x = x;
		p.posPerso.y = y;
	}
	if (c == '*') {
		p.T[x][y].natureCase = EMPLACEMENT_CAISSE;
		p.T[x][y].natureElem = CAISSE;
	}
	if (c == '+') {
		p.T[x][y].natureCase = EMPLACEMENT_CAISSE;
		p.T[x][y].natureElem = PERSO;
		p.posPerso.x = x;
		p.posPerso.y = y;
	}
	if (c == '.') {
		p.T[x][y].natureCase = EMPLACEMENT_CAISSE;
		p.T[x][y].natureElem = PAS_ELEMENT;
	}
	if (c == ' ') {
		p.T[x][y].natureCase = VIDE;
		p.T[x][y].natureElem = PAS_ELEMENT;
	}
	return p;
}

// Renvoie un plateau de taille nbCases*nbCases correspondant au niveau demandé
PLATEAU calcul_plateau_niveau(int nbCases, ACTIONJEU a)
{
	PLATEAU p;
	p = initialise_plateau_jeu(nbCases);
	if (nbCases == 1)
		return p;	//cas particulier si le niveau est vide
	FILE *f = fopen(a.nomFichier, "r");
	if (f == NULL)
		exit(2);
	char c = 'a';
	int nombre = -1;
	int x = 0, y = nbCases - 1;
	while (c != EOF) {
		c = fgetc(f);
		if (c == ';') {
			fscanf(f, "%d", &nombre);
			if (a.num == nombre) {	//recherche le niveau
				c = parcourt_fin_ligne(c, f);
				while ((c != ';') && (c != EOF)) {
					c = fgetc(f);
					while (y >= 0) {
						while (x < nbCases) {
							if ((c == ';')
							    || (c == EOF)) {
								fclose(f);
								return p;
							}
							p = remplit_plateau(p, c, x, y);	//remplit la case X,Y avec le caractère c
							c = fgetc(f);
							x++;
							if ((c == '\n')) {
								break;
							}
						}
						if ((c != '\n')
						    && (x = nbCases))
							y++;
						x = 0;
						y--;	//x revient a 0 et y décrémenté à chaque fois qu'on change de ligne
					}
				}
			}
		}
	}
	fclose(f);
	return p;
}
