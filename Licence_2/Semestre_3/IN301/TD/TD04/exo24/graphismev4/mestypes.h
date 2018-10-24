#define LARGEUR    800
#define HAUTEUR    800
#define COUL_FOND  noir
#define NB_POINTS  20

struct element{
  POINT p;
  struct element *suiv;
};
typedef struct element *Liste;
