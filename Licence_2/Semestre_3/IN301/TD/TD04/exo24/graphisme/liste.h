struct element{
  POINT p;
  struct element *suiv;
};

typedef struct element *Liste;
Liste ajoutDebut(Liste l, POINT p);
Liste supprimeDebut(Liste l);
void dessineListeRec(Liste l);
void dessineListe(Liste l);
