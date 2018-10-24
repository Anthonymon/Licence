all: exo29
	./exo29
	
exo29: exo29.c	
	gcc -o exo29 exo29.c `sdl-config --cflags` -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf
	
clean:
	rm -f exo29
