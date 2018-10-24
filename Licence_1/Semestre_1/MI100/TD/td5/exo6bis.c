// ##
// exo6.c
// nov. 2014 - sv
// ##
#include "affiche.h"
#include "graphics.h"

// On veut afficher un seul cercle soit rouge, soit bleu soit vert
int main()
{
     POINT p;

     init_graphics(900,600);
     
     p = wait_clic();
     if (p.x < 300)
     {
          draw_fill_circle(p,70,rouge);
     }
	 if (p.x < 600)
	 {
		 draw_fill_circle(p,50,vert);
	 }
	 if (p.x < 900)
	 {
		 draw_fill_circle(p,30,bleu);
	 }
     wait_escape();
     
     exit(1);
}
