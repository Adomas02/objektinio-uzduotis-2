run: Source.o lis_funk.o deq_funk.o vect_funkcijos.o SarasuGeneravimas.o
	g++ -I "C:\Program Files\boost_1_78_0" Source.cpp lis_funk.cpp deq_funk.cpp vect_funkcijos.cpp SarasuGeneravimas.cpp -o run

SarasuGeneravimas.o: SarasuGeneravimas.cpp
	g++ -I -c SarasuGeneravimas.cpp

source.o: Source.cpp
	g++ -c Source.cpp

lis_funk.o: lis_funk.cpp
	g++ -c lis_funk.cpp

deq_funk.o: deq_funk.cpp
	g++ -c deq_funk.cpp

vect_funkcijos.o: vect_funkcijos.cpp
	g++ -c vect_funkcijos.cpp

clean: rm *.o run