// sudoku.h du projet SUDOKU
// Franck.Quessette@uvsq.fr
// Novembre 2016

// Contient le type SUDOKU utilisé oartout dans le projet

#include "constantes.h"

#ifndef ___SUDOKU_H
#define ___SUDOKU_H
struct une_case {
	int val;
	int modifiable;
};

struct sudoku {
	int mode;
	struct une_case la_case [N][N];
};

typedef struct sudoku SUDOKU;

#endif
