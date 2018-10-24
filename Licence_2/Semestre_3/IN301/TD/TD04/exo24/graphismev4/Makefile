#construit le fichier binaire graphics.o

run: exe
	./exe

exe: main.o graphics.o 
	gcc -Wall -o exe main.o graphics.o  `sdl-config --libs` -lSDL_ttf -lm

main.o: main.c graphics.h mestypes.h simul.h liste.h
	gcc -c main.c
	
liste.o: liste.c mestypes.h
	gcc -c liste.c
	
simul.o: simul.c mestypes.h liste.h
	gcc -c simul.c

graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c
	
clean: main.o graphics.o
	rm -f main.o 
	rm -f graphics.o
	rm -f exe

