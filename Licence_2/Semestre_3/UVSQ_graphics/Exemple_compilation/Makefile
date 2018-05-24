all: principal
	./principal

principal: principal.o affiche.o
	gcc -o principal principal.o affiche.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

principal.o: principal.c affiche.h
	gcc -c principal.c

affiche.o: affiche.c affiche.h
	gcc -c `sdl-config --cflags` affiche.c

clean:
	rm -f affiche.o
	rm -f principal.o
	rm -f principal
