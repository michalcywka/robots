a.out: o/rotacje.o o/lacze_do_gnuplota.o o/wektor.o o/macierz.o  o/prostokat.o o/prostopadloscian.o o/operatory.o o/zbior_wierzcholkow.o o/sciezka.o o/obiekt_graficzny.o o/przeszkoda.o o/trojkat.o o/robot.o o/scena.o o/fabryka.o
	g++ -g -O0 o/wektor.o o/macierz.o o/prostokat.o o/operatory.o o/prostopadloscian.o o/lacze_do_gnuplota.o o/rotacje.o o/zbior_wierzcholkow.o o/przeszkoda.o o/sciezka.o o/obiekt_graficzny.o o/robot.o o/scena.o o/trojkat.o o/fabryka.o
o/rotacje.o: cpp/rotacje.cpp hpp/naglowek.hpp hpp/wektor.hpp hpp/macierz.hpp hpp/prostokat.hpp hpp/prostopadloscian.hpp hpp/operatory.hpp hpp/robot.hpp
	g++ -Wall -pedantic -std=c++11 -c cpp/rotacje.cpp -o o/rotacje.o
o/fabryka.o: hpp/fabryka.hpp cpp/fabryka.cpp
	g++ -Wall -pedantic -std=c++11 -c cpp/fabryka.cpp -o o/fabryka.o
o/operatory.o: hpp/operatory.hpp cpp/operatory.cpp hpp/prostokat.hpp
	g++ -Wall -pedantic -std=c++11 -c cpp/operatory.cpp -o o/operatory.o
o/lacze_do_gnuplota.o: hpp/lacze_do_gnuplota.hpp cpp/lacze_do_gnuplota.cpp
	g++ -Wall -pedantic -std=c++11 -c cpp/lacze_do_gnuplota.cpp -o o/lacze_do_gnuplota.o
o/scena.o: hpp/scena.hpp cpp/scena.cpp hpp/obiekt_graficzny.hpp
	g++ -Wall -pedantic -std=c++11 -c cpp/scena.cpp -o o/scena.o
o/robot.o: hpp/robot.hpp cpp/robot.cpp hpp/zbior_wierzcholkow.hpp cpp/zbior_wierzcholkow.cpp hpp/obiekt_graficzny.hpp
	g++ -Wall -pedantic -std=c++11 -c cpp/robot.cpp -o o/robot.o
o/obiekt_graficzny.o: hpp/naglowek.hpp hpp/obiekt_graficzny.hpp cpp/obiekt_graficzny.cpp hpp/robot.hpp
	g++ -Wall -pedantic -std=c++11 -c cpp/obiekt_graficzny.cpp -o o/obiekt_graficzny.o
o/sciezka.o: hpp/naglowek.hpp hpp/wektor.hpp hpp/zbior_wierzcholkow.hpp hpp/sciezka.hpp cpp/sciezka.cpp
	g++ -Wall -pedantic -std=c++11 -c cpp/sciezka.cpp -o o/sciezka.o
o/trojkat.o: hpp/trojkat.hpp cpp/trojkat.cpp hpp/obiekt_graficzny.hpp
	g++ -Wall -pedantic -std=c++11 -c cpp/trojkat.cpp -o o/trojkat.o
o/zbior_wierzcholkow.o: hpp/naglowek.hpp hpp/zbior_wierzcholkow.hpp cpp/zbior_wierzcholkow.cpp 
	g++ -Wall -pedantic -std=c++11 -c cpp/zbior_wierzcholkow.cpp -o o/zbior_wierzcholkow.o
o/prostopadloscian.o: hpp/naglowek.hpp hpp/prostopadloscian.hpp cpp/prostopadloscian.cpp hpp/wektor.hpp hpp/macierz.hpp hpp/operatory.hpp
	g++ -Wall -pedantic -lm -std=c++11 -c cpp/prostopadloscian.cpp -o o/prostopadloscian.o
o/prostokat.o: hpp/naglowek.hpp cpp/prostokat.cpp hpp/prostokat.hpp hpp/wektor.hpp hpp/macierz.hpp hpp/przeszkoda.hpp
	g++ -Wall -pedantic -lm -std=c++11 -c cpp/prostokat.cpp -o o/prostokat.o
o/przeszkoda.o: hpp/przeszkoda.hpp cpp/przeszkoda.cpp hpp/prostokat.hpp hpp/obiekt_graficzny.hpp
	g++ -Wall -pedantic -std=c++11 -c cpp/przeszkoda.cpp -o o/przeszkoda.o
o/macierz.o: hpp/naglowek.hpp cpp/macierz.cpp hpp/macierz.hpp 
	g++ -Wall -pedantic -lm -std=c++11 -c cpp/macierz.cpp -o o/macierz.o
o/wektor.o: hpp/naglowek.hpp hpp/wektor.hpp cpp/wektor.cpp 
	g++ -Wall -pedantic -std=c++11 -c cpp/wektor.cpp -o o/wektor.o
