#include <uvsqgraphics.h>
#define TAILLE_POLICE 30

void initialiser_affichage() {
    init_graphics(600,400);
}

void ecrire_texte_dans_cercle(char *texte) {
    int rayon = 2 + largeur_texte(texte,TAILLE_POLICE)/2;
    POINT centre; centre.x = LARGEUR_FENETRE/2; centre.y = HAUTEUR_FENETRE/2;
    POINT bas; bas.x = centre.x; bas.y = centre.y - 50;
    fill_screen(blanc);
    int i;
    char lenombre[4];
    for (i=0 ; i<=50 ; i++) {
        draw_fill_circle(centre,rayon,gold);
        if (i%2) aff_pol_centre(texte, TAILLE_POLICE, centre, red);
        sprintf(lenombre,"%d",50-i);
        aff_pol_centre(lenombre,TAILLE_POLICE+3*i,bas,red);
        attendre(100);
    }
}

