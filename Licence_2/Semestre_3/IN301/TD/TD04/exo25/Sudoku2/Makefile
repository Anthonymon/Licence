# Makefile du projet SUDOKU
# Franck.Quessette@uvsq.fr
# Novembre 2016

CFLAGS=-c -g -Wall

all: sudoku
	./sudoku

sudoku: sudoku.o affichage.o action.o
	gcc -o sudoku sudoku.o affichage.o action.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

sudoku.o: sudoku.c sudoku.h constantes.h
	gcc $(CFLAGS) sudoku.c

affichage.o: affichage.c affichage.h sudoku.h constantes.h
	gcc $(CFLAGS) `sdl-config --cflags` affichage.c

action.o: action.c action.h constantes.h
	gcc $(CFLAGS) `sdl-config --cflags` action.c

clean:
	rm -f sudoku
	rm -f sudoku.o
	rm -f affichage.o
	rm -f action.o
