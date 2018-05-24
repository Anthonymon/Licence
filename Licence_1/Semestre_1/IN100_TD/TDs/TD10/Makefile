CC=gcc
CFLAGS=-O2 -Wall `sdl-config --cflags`
LIBS=`sdl-config --libs` -lm -lSDL_ttf
TARDIR=UVSQ_graphics

install: sdl xox
	echo "Taper ./xox [H [L]]"

sdl:
	sudo apt-get install libsdl1.2-dev
	sudo apt-get install libsdl-ttf2.0-dev


#Cible generique pour Linux
%: graphics.o %.c
	rm -f $@
	$(CC) $(CFLAGS) graphics.o $@.c -o $@ $(LIBS)

#Cible generique pour free BSD
.c .o: graphics.o
	rm -f $@
	$(CC) $(CFLAGS) graphics.o $@.c -o $@ $(LIBS)

graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	$(CC) $(CFLAGS) -c graphics.c -o graphics.o


## sans_ttf:
## 	rm -f police.h
## 	touch police.h
## 	$(CC) $(CFLAGS) -c graphics.c
## 	$(CC) $(CFLAGS) graphics.o exemple.c -o exemple $(LIBS)
## 	./exemple


demo: demo_1 demo_2 demo_3
	./demo_1
	./demo_2
	./demo_3


tar: clean
	rm -rf $(TARDIR)
	mkdir $(TARDIR)
	cp demo*.c $(TARDIR)
	cp graphics.c $(TARDIR)
	cp graphics.h $(TARDIR)
	cp couleur.h $(TARDIR)
	cp Makefile $(TARDIR)
	cp *.ttf $(TARDIR)
	cp exo*.c $(TARDIR)
	tar cvf $(TARDIR).tar $(TARDIR)
	rm -rf $(TARDIR)

clean:
	rm -f *core
	rm -f *.o
	rm -f police.h
	rm -f demo_1
	rm -f demo_2
	rm -f demo_3
	rm -f *.tar
	rm -f *.tgz
	rm -rf $(TARDIR)
