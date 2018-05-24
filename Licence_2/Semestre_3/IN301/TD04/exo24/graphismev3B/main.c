#include "graphics.h"

// ############################
// 1. Les structures de données
// ############################

#define LARGEUR    800
#define HAUTEUR    800
#define COUL_FOND  noir
#define NB_POINTS  20
 

struct element{
  POINT p;
  struct element *suiv;
};
typedef struct element *Liste;


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

// ############################
// 3. Simulation
// ############################


void simulChaine(){
  Liste l = NULL;
  int i = 0;
  char c;
  POINT p;
  while(i < NB_POINTS){
    p = wait_key_or_clic(&c);
    if(c == 0){//ajoute un point
      l = ajoutDebut(l, p);
      i++;
    }
    else if(c == 'a'){//annule le dernier point
      l = supprimeDebut(l);
      i--;
    }
    dessineListe(l);
  }
}




// ##########
// 4. Le main
// ##########

int main(){

  init_graphics(LARGEUR,HAUTEUR);
  affiche_auto_off();
  fill_screen(COUL_FOND);
  affiche_all();

  simulChaine();



  wait_escape();
  return 0;
}
