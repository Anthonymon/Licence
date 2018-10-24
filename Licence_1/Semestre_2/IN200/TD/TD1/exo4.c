#include "graphics.h"

int main()
{
POINT p;

init_graphics(900,900);

// Par défaut on est en "affiche_auto_on"
p = wait_clic();
draw_fill_circle(p,200,bleu);
p = wait_clic();
draw_fill_circle(p,200,rouge);


// On passe en off
affiche_auto_off();
p = wait_clic();
draw_fill_circle(p,200,vert);
p = wait_clic();
draw_fill_circle(p,200,jaune);
// Il faut faire affiche_all pour que ca s'affiche
//wait_clic();
affiche_all();
// On est toujours en off
p = wait_clic();
draw_fill_circle(p,200,gris);
p = wait_clic();
draw_fill_circle(p,200,orange);
// Il faut faire affiche_all pour que ca s'affiche
affiche_all();

// On passe en on
// Plus besoin d'affiche_all
affiche_auto_on();
p = wait_clic();
draw_fill_circle(p,200,cyan);
p = wait_clic();
draw_fill_circle(p,200,magenta);


wait_escape();
exit(0);
}
