#include <uvsqgraphics.h>
// ############################
// Démo 1 de l'API uvsqgraphics
// Dans geany, cliquer sur <.> ou la roue dentée pour compiler
// et sur la coche à droite pour exécuter
// ############################


int main () {
    POINT P1, P2;
    init_graphics (800,600);
    char *a_ecrire = "Cliquer dans la fen"ecirc"tre";

// Affichage d'un disque et d'un cercle
    P1.x = 200; P1.y = 300;
    draw_fill_circle(P1,50,gold);
    draw_circle(P1,40,silver);

// Affichage d'un rectangle avec un bord blanc
    P2.x = 100; P2.y = 100;
    draw_fill_rectangle(P1,P2,rouge);
    draw_rectangle(P1,P2,blanc);

// Affichage de texte de taille 20
    P1.x = LARGEUR_FENETRE/2 - largeur_texte(a_ecrire,20)/2; 
    P1.y = 2*hauteur_texte(a_ecrire,20);
    aff_pol(a_ecrire,20,P1,gris);

// Attente d'un clic
    P2 = wait_clic();
// Remplissage de l'écran en blanc
    fill_screen(blanc);
// Affichage d'un cercle bleu centré sur le point cliqué
    P1.x = LARGEUR_FENETRE/2 - largeur_texte(a_ecrire,20)/2; 
    aff_pol(a_ecrire,20,P1,gris);
    P2 = wait_clic();
    draw_fill_circle(P2,80,bleu);

// Affichage d'un cercle rouge centré sur le point cliqué
    P2 = wait_clic();
    draw_fill_circle(P2,80,rouge);

// Attend de taper la touche 'Esc' ou 'Echap.' pour terminer
    wait_escape();
    exit(0);
}
