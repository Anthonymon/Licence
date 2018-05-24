#construit le fichier binaire graphics.o

run: exe
	./exe

exe: main.o graphics.o liste.o
	gcc -o exe main.o graphics.o liste.o `sdl-config --libs` -lSDL_ttf -lm

main.o: main.c graphics.h
	gcc -c main.c
	
liste.o: liste.c graphics.h types.h
	gcc -c liste.c

graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c

clean: main.o graphics.o exe
	rm -f main.o 
	rm -f graphics.o
	rm -f exe
