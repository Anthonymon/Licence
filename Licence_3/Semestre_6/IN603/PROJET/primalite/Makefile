# CAUMES Clément - DOUDOUH Yassin 
# PROJET Primalite Solovay-Strassen

CFLAGS=-c -g -Wall

compil: strassen.o exponent.o interface.o jacobi.o
	gcc -o primalite app/src/primalite.c app/src/interface.c app/src/strassen.c app/src/exponent.c app/src/jacobi.c -lgmp

run: compil 
	./primalite
	
valgrind: compil
	valgrind --leak-check=full ./primalite
	
test: clean test.o strassen.o exponent.o interface.o jacobi.o 
	gcc -o test app/src/interface.c app/src/strassen.c app/src/exponent.c app/src/jacobi.c  app/test/test.c -lcunit -lgmp
	./test
	
doxygen:
	sudo apt-get install doxygen
	doxygen Doxyfile
	firefox doc/html/files.html

strassen.o: 
	gcc $(CFLAGS) app/src/strassen.c -lgmp
	
jacobi.o:
	gcc $(CFLAGS) app/src/jacobi.c -lgmp
	
exponent.o:
	gcc $(CFLAGS) app/src/exponent.c -lgmp
	
interface.o:
	gcc $(CFLAGS) app/src/interface.c -lgmp
	
test.o: strassen.o exponent.o jacobi.o interface.o
	gcc $(CFLAGS) app/test/test.c -lcunit -lgmp
	
clean: 
	rm -f *.o
	rm -f test 
	rm -f primalite

install_gmp: 
	tar xf gmp-6.1.2.tar.xz 
	gmp-6.1.2/configure
	
install_cunit:
	sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
	
