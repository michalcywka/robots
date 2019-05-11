#ifndef prostopadloscian_hpp
#define prostopadloscian_hpp

#include "../hpp/naglowek.hpp"
#include "../hpp/wektor.hpp"
#include "../hpp/macierz.hpp"
#include <iostream>
using namespace std;

class Prostopadloscian{
	
	private:
	Wektor wierzcholek[8];
	
	public:
	Prostopadloscian();
	void Ustaw(Wektor w, int i);
	Wektor Pobierz(int const i) const;
	void translacja(Wektor w);
	void rotacja(liczba_t radiany, int ilosc,char os);
	void zapisz() const;

};

#endif
