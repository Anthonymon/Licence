// Clément Caumes 21501810
// Yassin Doudouh 21500127
// 05 mai 2017
// Projet Metro IN403

// affichage.c du projet Metro
// Contient les fonctions relatives à l'interface graphique du projet Metro

#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "graphe.h"
#include "lire_ecrire.h"
#include "affichage.h"
#include "types.h"

// Fonction qui initialise la fenêtre
void initialise_fenetre()
{
	init_graphics(ABSCISSE_FENETRE, ORDONNEE_FENETRE);
	affiche_auto_off();
}

// Fonction qui parcourt la liste de la structure DIJKSTRA et met le sommet en surbrillance
void affiche_chemin(GRAPHE g)
{
	if ((g.d.rang_deb != INVALIDE) && (g.d.rang_fin != INVALIDE)) {
		struct elem *deb = g.d.chemin;
		struct elem *temp = g.d.chemin;
		//les sommets par lesquels on est passé lors du calcul du plus court chemin sont en jaune
		while (!teste_liste_vide(temp->suiv)) {
			draw_fill_circle(temp->s.geolocalisation, 4, gold);
			temp = temp->suiv;
		}
		//le sommet de départ est en vert et le sommet d'arrivée est en rouge
		draw_fill_circle(deb->s.geolocalisation, 4, forestgreen);
		draw_fill_circle(temp->s.geolocalisation, 4, red);
	}
}

// Fonction qui affiche tous les sommets en fonction de leur geolocalisation sur la carte
void affiche_points(GRAPHE g)
{
	POINT dessin;
	int i;
	//tous les sommets sont en bleu
	for (i = 0; i < g.nb_sommets; i++) {
		dessin.x = g.station[i].geolocalisation.x;
		dessin.y = g.station[i].geolocalisation.y;
		draw_fill_circle(dessin, 3, bleu);
	}
	//met le sommet de départ en vert et le sommet final en rouge quand on a choisi un plus court chemin entre 2 sommets
	for (i = 0; i < 2; i++) {
		if (g.chemin[i].num_sommet != INVALIDE) {
			dessin.x =
			    g.station[g.chemin[i].num_sommet].geolocalisation.x;
			dessin.y =
			    g.station[g.chemin[i].num_sommet].geolocalisation.y;
			if (i == 0)
				draw_fill_circle(dessin, 4, forestgreen);
			else
				draw_fill_circle(dessin, 4, rouge);
		}
	}
	affiche_chemin(g);
}

// Fonction qui modifie la structure du graphe en fonction de ce que veut l'utilisateur
GRAPHE ajoute_supprime_selection_sommet(GRAPHE g, POINT p)
{
	int i;
	POINT pTemp;
	int sommet_choisi;
	for (i = 0; i < g.nb_sommets; i++) {
		pTemp.x = g.station[i].geolocalisation.x;
		pTemp.y = g.station[i].geolocalisation.y;
		if (distance(pTemp, p) <= 3) {
			sommet_choisi = i;
			//si on n'a rien selectionne avant 
			//alors on sélectionne ce sommet en sommet de départ
			if ((g.chemin[0].num_sommet == INVALIDE)
			    && (g.chemin[1].num_sommet == INVALIDE)) {
				g.chemin[0].num_sommet = i;
			}
			//si 2 sommets ont ete selectionnes avant
			//alors on déselectionne le sommet choisi
			else if ((g.chemin[0].num_sommet != INVALIDE)
				 && (g.chemin[1].num_sommet != INVALIDE)) {
				if (g.chemin[0].num_sommet == sommet_choisi) {
					g.chemin[0].num_sommet = INVALIDE;
				} else if (g.chemin[1].num_sommet ==
					   sommet_choisi) {
					g.chemin[1].num_sommet = INVALIDE;
				}
			}
			//si le [0] valide et [1] invalide
			//alors on déselectionne ou non en fonction du sommet choisi
			else if ((g.chemin[0].num_sommet != INVALIDE)
				 && (g.chemin[1].num_sommet == INVALIDE)) {
				if (g.chemin[0].num_sommet == sommet_choisi) {
					g.chemin[0].num_sommet = INVALIDE;
				} else {
					g.chemin[1].num_sommet = sommet_choisi;
				}
			}
			//si le [0] invalide et [1] valide
			//alors on déselectionne ou non en fonction du sommet choisi
			else if ((g.chemin[0].num_sommet == INVALIDE)
				 && (g.chemin[1].num_sommet != INVALIDE)) {
				if (g.chemin[0].num_sommet == sommet_choisi) {
					g.chemin[0].num_sommet = sommet_choisi;
				} else if (g.chemin[1].num_sommet ==
					   sommet_choisi) {
					g.chemin[1].num_sommet = INVALIDE;
				}
			}

		}
	}
	g.d.rang_deb = g.chemin[0].num_sommet;
	g.d.rang_fin = g.chemin[1].num_sommet;
	//si on a déselectionné un sommet, on libère la structure
	if ((g.d.rang_deb == INVALIDE) || (g.d.rang_fin == INVALIDE)) {
		g.d.chemin = libere_liste(g.d.chemin);
	}
	//on calcule le plus court chemin
	g = calcul_plus_court_chemin(g, g.d.rang_deb, g.d.rang_fin);
	return g;
}

// Fonction qui affiche la carte en fonction de ce que l'utilisateur a choisi (affichage general ou zoom)
void affiche_carte(METRO m)
{
	POINT p;
	p.x = 0;
	p.y = ORDONNEE_FENETRE;
	if (m.affichage == AFFICHAGE_GENERAL) {
		affiche_image("metro.bmp", p, 500, 500);
		affiche_points(m.g);
	} else if (m.affichage == ZOOM_BD) {
		affiche_image("zoom_bd.bmp", p, 500, 500);
	} else if (m.affichage == ZOOM_BG) {
		affiche_image("zoom_bg.bmp", p, 500, 500);
	} else if (m.affichage == ZOOM_HD) {
		affiche_image("zoom_hd.bmp", p, 500, 500);
	} else
		affiche_image("zoom_hg.bmp", p, 500, 500);

	affiche_all();
}

//Fonction qui change les paramètres généraux en fonction des actions de l'utilisateur
METRO interaction(METRO m)
{
	POINT p;
	int touch;
	char carac;
	int i = wait_key_arrow_clic(&carac, &touch, &p);
	if (m.affichage == AFFICHAGE_GENERAL) {	//si on est pas en zoom
		if (i == EST_TOUCHE) {
			if (carac == 'Z') {	// le zoom a été choisi
				m.affichage = ZOOM_BD;
			} else if (carac == 'Q')
				m.mode = MODE_QUITTER;	//l'utilisateur veut quitter
		} else if (i == EST_CLIC) {	//l'utilisateur a choisi un sommet
			m.g = ajoute_supprime_selection_sommet(m.g, p);
		}
	} else {
		if (i == EST_TOUCHE) {
			if (carac == 'Z') {
				m.affichage = AFFICHAGE_GENERAL;
			} else if (carac == 'Q')
				m.mode = MODE_QUITTER;
		} else if (i == EST_FLECHE) {	//déplacement du zoom
			if ((touch == FLECHE_DROITE)
			    && (m.affichage == ZOOM_BG)) {
				m.affichage = ZOOM_BD;
			} else if ((touch == FLECHE_DROITE)
				   && (m.affichage == ZOOM_HG)) {
				m.affichage = ZOOM_HD;
			} else if ((touch == FLECHE_GAUCHE)
				   && (m.affichage == ZOOM_BD)) {
				m.affichage = ZOOM_BG;
			} else if ((touch == FLECHE_GAUCHE)
				   && (m.affichage == ZOOM_HD)) {
				m.affichage = ZOOM_HG;
			} else if ((touch == FLECHE_HAUT)
				   && (m.affichage == ZOOM_BD)) {
				m.affichage = ZOOM_HD;
			} else if ((touch == FLECHE_HAUT)
				   && (m.affichage == ZOOM_BG)) {
				m.affichage = ZOOM_HG;
			} else if ((touch == FLECHE_BAS)
				   && (m.affichage == ZOOM_HD)) {
				m.affichage = ZOOM_BD;
			} else if ((touch == FLECHE_BAS)
				   && (m.affichage == ZOOM_HG)) {
				m.affichage = ZOOM_BG;
			}
		}
	}
	affiche_carte(m);
	return m;
}

// Fonction qui libere la fenetre
void libere_fenetre()
{
	wait_escape();
}
