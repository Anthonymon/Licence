//exo29 td6 clement caumes
#include "graphics.h"

void dessine_mickey(POINT centre, int rayon, COULEUR c)
{
	draw_fill_circle(centre,rayon,c);
	POINT p1;
	p1.x=centre.x+rayon; p1.y=centre.y+rayon;
	int rayonOreilles;
	rayonOreilles=rayon/2;
	draw_fill_circle(p1,rayonOreilles,c);
	p1.x=centre.x-rayon; p1.y=centre.y+rayon;
	draw_fill_circle(p1,rayonOreilles,c);
}
	

int main()
{
	init_graphics(900,600);
	COULEUR couleurMickey;
	couleurMickey=rouge;
	int taille;
	taille=lire_entier_clavier();
	POINT pUtilisateur;
	pUtilisateur=wait_clic();
	dessine_mickey(pUtilisateur,taille,couleurMickey);
	wait_escape();
	exit(0);
}
