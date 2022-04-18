run: Source.o list_funk.o deq_funk.o vect_funkcijos.o SarasuGeneravimas.o
	g++ Source.cpp list_funk.cpp deq_funk.cpp vect_funkcijos.cpp SarasuGeneravimas.cpp -o run -std=c++20

SarasuGeneravimas.o: SarasuGeneravimas.cpp
	g++ -c SarasuGeneravimas.cpp -std=c++20

source.o: Source.cpp
	g++ -c Source.cpp -std=c++20

list_funk.o: list_funk.cpp
	g++ -c list_funk.cpp -std=c++20

deq_funk.o: deq_funk.cpp
	g++ -c deq_funk.cpp -std=c++20

vect_funkcijos.o: vect_funkcijos.cpp
	g++ -c vect_funkcijos.cpp -std=c++20

clean: rm *.o run