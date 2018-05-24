//exo27 td6 clement caumes
#include "graphics.h"

void dessine_triangle(POINT p1, POINT p2, POINT p3)
{
	draw_line(p1,p2,bleu);
	draw_line(p2,p3,blanc);
	draw_line(p3,p1,rouge);
}
/* partie 1
int main()
{
	init_graphics(900,600);
	POINT p1Utilisateur;
	POINT p2Utilisateur;
	POINT p3Utilisateur;
	p1Utilisateur=wait_clic();
	p2Utilisateur=wait_clic();
	p3Utilisateur=wait_clic();
	dessine_triangle(p1Utilisateur,p2Utilisateur,p3Utilisateur);
	
	wait_escape();
	exit(0);
}*/

int main()
{
	init_graphics(900,600);
	POINT p1Utilisateur;
	POINT p2Utilisateur;
	POINT p3Utilisateur;
	p1Utilisateur.x=0;p1Utilisateur.y=0;
	p2Utilisateur.y=300;p2Utilisateur.y=600;
	p3Utilisateur.x=600;p3Utilisateur.y=0;
	dessine_triangle(p2Utilisateur,p3Utilisateur,p1Utilisateur);
	
	wait_escape();
	exit(0);
}
