
RunEx3: List.o File.o Pile.o
	g++ -g -Wall List.o File.o Pile.o Ex03.cc -o ex
	./ex

List.o: List.cc List.hh
	g++ -c List.cc -o List.o

File.o: File.cc File.hh List.hh
	g++ -c -Wall -g File.cc -o File.o

Pile.o: Pile.cc Pile.hh List.hh
	g++ -c -Wall -g Pile.cc -o Pile.o

clean:
	rm -f *.o ex

