#include "constantes.h"
#include "graphics.h"

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

