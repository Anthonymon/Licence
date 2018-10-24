#construit le fichier binaire graphics.o

all: exe
	./exe

exe: main.o graphics.o
	gcc -o exe main.o graphics.o `sdl-config --libs` -lSDL_ttf -lm
	

main.o: main.c graphics.h 
	gcc -c main.c 

graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c
	
	

