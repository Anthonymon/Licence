#include "graphics.h"
#include "constantes.h"
#include "liste.h"

// ############################
// 1. Les structures de données
// ############################
 




// ############################
// 2. Fonctions listes chainees
// ############################


Liste ajoutDebut(Liste l, POINT p){
  Liste tmp = malloc(sizeof(struct element));
  tmp->p = p;
  tmp->suiv = l;
  return tmp;
}

Liste supprimeDebut(Liste l){
  Liste ll;
  if(l != NULL){
    ll = l;
    l = l->suiv;
    free(ll);
  }
  return l;
}


void dessineListeRec(Liste l){
  if(l != NULL){
    draw_fill_circle(l->p, 5, bleu);
    if(l->suiv != NULL)
      draw_line(l->p, l->suiv->p, rouge);
    dessineListeRec(l->suiv);
  }
}

void dessineListe(Liste l){
  fill_screen(COUL_FOND);
  dessineListeRec(l);
  affiche_all();
}
