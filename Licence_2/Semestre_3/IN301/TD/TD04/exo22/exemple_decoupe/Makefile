all: exo
	./exo

exo: ploum.o plim.o plam.o
	gcc -o exo ploum.o plim.o plam.o

ploum.o: ploum.c plam.h plim.h
	gcc -c ploum.c
	
plim.o: plim.c
	gcc -c plim.c
	
plam.o: plam.c
	gcc -c plam.c
	
clean:
	rm -f plam.o
	rm -f plim.o
	rm -f ploum.o
	
