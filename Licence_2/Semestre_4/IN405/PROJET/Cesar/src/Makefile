# Clément Caumes 21501810
# 30 avril 2017
# Projet Ave Cesar IN405

# Makefile du projet Ave Cesar

CFLAGS=-c -g -Wall -pthread

test: clean compil
	./cesar mon_fichier
	
valgrind: clean compil
	valgrind --leak-check=full ./cesar mon_fichier

compil: clean cesar.o proces_thread.o lire_ecrire.o cipher.o gestion_erreurs.o
	gcc -Wall -pthread -o cesar cesar.o proces_thread.o lire_ecrire.o cipher.o gestion_erreurs.o

cesar.o: cesar.c proces_thread.h lire_ecrire.h gestion_erreurs.h cipher.h types.h
	gcc $(CFLAGS) cesar.c

proces_thread.o: proces_thread.c proces_thread.h lire_ecrire.h gestion_erreurs.h cipher.h types.h
	gcc $(CFLAGS) proces_thread.c	

cipher.o: cipher.c proces_thread.h lire_ecrire.h gestion_erreurs.h cipher.h types.h
	gcc $(CFLAGS) cipher.c
	
lire_ecrire.o: lire_ecrire.c proces_thread.h lire_ecrire.h gestion_erreurs.h cipher.h types.h
	gcc $(CFLAGS) lire_ecrire.c
	
gestion_erreurs.o: gestion_erreurs.c gestion_erreurs.h proces_thread.h lire_ecrire.h cipher.h types.h
	gcc $(CFLAGS) gestion_erreurs.c
	
indent: 
	indent -linux *.h
	indent -linux *.c
	rm -f *.h~
	rm -f *.c~
	
doxygen:
	doxygen *.h
	doxygen *.c

clean:
	rm -f cesar
	rm -f *.o
	rm -f *_cypher
