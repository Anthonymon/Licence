all: 
	qmake -makefile -o MakefileProjet app/fractales.pro
	make -f MakefileProjet
	./fractales
	
first: install 
	qmake -makefile -o MakefileProjet app/fractales.pro
	make -f MakefileProjet
	./fractales

compil: 
	qmake -makefile -o MakefileProjet app/fractales.pro
	make -f MakefileProjet
	
run: compil
	./fractales
	
clean: 
	rm -f *.o
	rm -f fractales
	rm -f MakefileProjet
	rm -f moc_*
	rm -f /doc/rapport/rapport.aux
	rm -f /doc/rapport/rapport.dvi
	rm -f /doc/rapport/rapport.log
	rm -f /doc/rapport/rapport.out
	rm -rf doc/html
	rm -rf doc/latex

indent:
	indent -linux app/head/*.hh
	indent -linux app/src/*.cc
	
doxygen:
	doxygen Doxyfile
	
listing: doxygen
	firefox doc/html/files.html
	
rapport: 
	evince doc/rapport/rapport.pdf

install:
	sudo apt-get update
	sudo apt-get install g++
	sudo apt-get install libqt4-dev 
	sudo apt-get install libgl1-mesa-dev
	sudo apt-get install libglu1-mesa-dev
	sudo apt-get install freeglut3 freeglut3-dev 
	sudo apt-get install libgtkmm-3.0-dev
