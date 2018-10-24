all: exe
	./exe
	
exe: principal.o circonference.o surface.o 
	gcc -o exe principal.o circonference.o surface.o
	
principal.o: principal.c circonference.h surface.h
	gcc -Wall -c principal.c
	
circonference.o: circonference.c pi.h
	gcc -Wall -c circonference.c
	
surface.o: surface.c pi.h
	gcc -Wall -c surface.c 
	
clean: 
	rm -f principal
	rm -f principal.o
	rm -f circonference.o
	rm -f surface.o
	
