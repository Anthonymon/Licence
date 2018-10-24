#include "graphics.h"

struct element{
  POINT p;
  struct element *suiv;
};
typedef struct element *Liste;
