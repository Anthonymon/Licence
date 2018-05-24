#include "graphics.h"

// ##########
// 4. Le main
// ##########


int main ()
{
POINT P1, P2;

init_graphics (800,600);

// Affichage d'un disque et d'un cercle
P1.x = 200; P1.y = 300;
draw_fill_circle(P1,50,gold);
draw_circle(P1,40,silver);

// Affichage d'un rectangle avec un bord blanc
P2.x = 100; P2.y = 100;
draw_fill_rectangle(P1,P2,rouge);
draw_rectangle(P1,P2,blanc);

// Affichage de texte
P1.x = WIDTH/2 - largeur_texte("Cliquer dans la fen�tre",20)/2; 
P1.y = 2*hauteur_texte("Cliquer dans la fen�tre",20);
aff_pol("Cliquer dans la fen�tre",20,P1,gris); // 20 est la taille de la police



// Attente d'un clic
P2 = wait_clic();
// Remplissage de l'�cran en blanc
fill_screen(blanc);


// Affichage d'un cercle bleu centr� sur le point cliqu�
P1.x = WIDTH/2 - largeur_texte("Cliquer encore dans la fen�tre",20)/2; 
aff_pol("Cliquer encore dans la fen�tre",20,P1,gris);
P2 = wait_clic();
draw_fill_circle(P2,80,bleu);


// Affichage d'un cercle rouge centr� sur le point cliqu�
P2 = wait_clic();
draw_fill_circle(P2,80,rouge);

// Attente de l'appui sur la touche Echap pour terminer
wait_escape();
exit(0);
}
