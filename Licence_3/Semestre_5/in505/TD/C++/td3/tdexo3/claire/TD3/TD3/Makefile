RunEx1-2: ./Ex01-2/point_color.o ./Ex01-2/forme.o
	g++ ./Ex01-2/point_color.o ./Ex01-2/forme.o ./Ex01-2/main1-2.cc -o ./Ex01-2/ex
	./Ex01-2/ex

RunEx3: List.o File.o Pile.o
	g++ -g -Wall List.o File.o Pile.o Ex03.cc -o ex
	./ex

point_color.o: ./Ex01-2/point_color.cc ./Ex01-2/point_color.hh 
	g++ -c ./Ex01-2/point_color.cc -o ./Ex01-2/point_color.o

forme.o: ./Ex01-2/forme.cc ./Ex01-2/forme.hh
	g++ -c  forme.cc -o forme.o

List.o: List.cc List.hh
	g++ -c List.cc -o List.o

File.o: File.cc File.hh List.hh
	g++ -c -Wall -g File.cc -o File.o

Pile.o: Pile.cc Pile.hh List.hh
	g++ -c -Wall -g Pile.cc -o Pile.o

clean:
	rm -f *.o ex

