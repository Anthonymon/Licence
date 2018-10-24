# Clément Caumes 21501810
# Yassin Doudouh 21500127
# 05 mai 2017
# Projet Metro IN403

# Makefile du projet Metro

CFLAGS=-c -g -Wall

run: clean compil
	./metro
	
valgrind: compil
	valgrind --leak-check=full ./metro
	
compil: metro.o lire_ecrire.o graphe.o affichage.o
	gcc -Wall -o metro metro.o lire_ecrire.o affichage.o graphe.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

metro.o: metro.c graphe.h lire_ecrire.h affichage.h types.h
	gcc $(CFLAGS) `sdl-config --cflags` metro.c
	
lire_ecrire.o: lire_ecrire.c lire_ecrire.h graphe.h affichage.h types.h
	gcc $(CFLAGS) `sdl-config --cflags` lire_ecrire.c
	
affichage.o: affichage.c affichage.h graphe.h types.h
	gcc $(CFLAGS) `sdl-config --cflags` affichage.c
	
graphe.o: graphe.c graphe.h affichage.h lire_ecrire.h types.h
	gcc $(CFLAGS) `sdl-config --cflags` graphe.c
	
indent: 
	indent -linux *.h
	indent -linux *.c
	rm -f *.h~
	rm -f *.c~
	
clean:
	rm -f metro
	rm -f metro.o
	rm -f lire_ecrire.o
	rm -f graphe.o
	rm -f affichage.o
