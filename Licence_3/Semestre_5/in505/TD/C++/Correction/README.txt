Pour compiler Dico.cc :
Se placer dans le répertoire td1
Supprimer ou commenter le main de CString.cc (sélectionner le texte, ctrl + E, sur geany)
	g++ -c CString.cc
	g++ -c Dico.cc
	g++ CString.o Dico.o

Pour compiler Dico2.cc :
Se placer dans le répertoire td2
Supprimer ou commenter le main de CString2.cc
	g++ -c CString2.cc
	g++ -c Dico2.cc
	g++ CString2.o Dico2.o

Pour compiler getmax.cc :
Se placer dans le répertoire td4
Supprimer ou commenter le main de CString.cc
	g++ -c ../td1/CString.cc
	g++ -c getmax.cc
	g++ CString.o getmax.o
	
Pour compiler ListeTemplates.cc :
Se placer dans le répertoire td4
Supprimer ou commenter le main de CString.cc
	g++ -c ../td1/CString.cc
	g++ -c ListeTemplates.cc
	g++ CString.o ListeTemplates.o
