//exo28 td6 clement caumes
#include "graphics.h"
void dessine_croix(POINT centre, int largeur, COULEUR c)
{
	POINT p1,p2;
	p1.x=centre.x+(largeur/2); p1.y=centre.y+(largeur/2);
	p2.x=centre.x-(largeur/2); p2.y=centre.y-(largeur/2);
	draw_rectangle(p1,p2,c);
	draw_line(p1,p2,c);
	p1.x=centre.x-(largeur/2); p1.y=centre.y+(largeur/2);
	p2.x=centre.x+(largeur/2); p2.y=centre.y-(largeur/2);
	draw_line(p1,p2,c);
}

int main()
{
	init_graphics(900,600);
	int largeurCarre;
	largeurCarre=lire_entier_clavier();
	POINT pUtilisateur;
	pUtilisateur=wait_clic();
	COULEUR couleurCroix;
	couleurCroix=rouge;
	dessine_croix(pUtilisateur,largeurCarre,couleurCroix);
	
	wait_escape();
	exit(0);
}
