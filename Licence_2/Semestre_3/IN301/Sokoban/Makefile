# Clément CAUMES 21501810
# 09 janvier 2017
# PROJET SOKOBAN

# Makefile du projet SOKOBAN 

CFLAGS=-c -g -Wall

run: compil
	./sokoban
	
test: clean compil
	./sokoban -n 8 sasquatch1.xsb

compil: sokoban.o action_crea.o action_jeu.o affichage.o lire_ecrire.o gestion_plateau.o
	gcc -Wall -o sokoban sokoban.o action_crea.o action_jeu.o affichage.o lire_ecrire.o gestion_plateau.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

sokoban.o: sokoban.c sokoban.h action_crea.h action_jeu.h lire_ecrire.h affichage.h gestion_plateau.o types.h
	gcc $(CFLAGS) `sdl-config --cflags` sokoban.c

action_crea.o: action_crea.c action_crea.h lire_ecrire.h affichage.h gestion_plateau.h types.h 
	gcc $(CFLAGS) `sdl-config --cflags` action_crea.c

action_jeu.o: action_jeu.c action_jeu.h lire_ecrire.h affichage.h gestion_plateau.h types.h 
	gcc $(CFLAGS) `sdl-config --cflags` action_jeu.c	

affichage.o: affichage.c sokoban.h action_crea.h action_jeu.h gestion_plateau.h types.h 
	gcc $(CFLAGS) `sdl-config --cflags` affichage.c
	
lire_ecrire.o: lire_ecrire.c sokoban.h action_crea.h action_jeu.h gestion_plateau.h types.h
	gcc $(CFLAGS) `sdl-config --cflags` lire_ecrire.c
	
gestion_plateau.o: gestion_plateau.c sokoban.h action_crea.h action_jeu.h lire_ecrire.h types.h
	gcc $(CFLAGS) `sdl-config --cflags` gestion_plateau.c
	
indent: 
	indent -linux *.h
	indent -linux *.c
	rm -f *.h~
	rm -f *.c~
	
clean:
	rm -f sokoban
	rm -f sokoban.o
	rm -f action_crea.o
	rm -f action_jeu.o
	rm -f affichage.o
	rm -f lire_ecrire.o
	rm -f gestion_plateau.o
