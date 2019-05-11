#ifndef prostokat_hpp
#define prostokat_hpp
#include "naglowek.hpp"
#include "wektor.hpp"
#include "macierz.hpp"
#include "przeszkoda.hpp"
#include <iostream>
using namespace std;

class Prostokat:public Przeszkoda{

	private:
  Wektor wierzcholek[4];
	
	public:
	Prostokat();
	Prostokat(Wektor w1,Wektor w2,Wektor w3,Wektor w4);
	void Ustaw(Wektor w, int i);
	Wektor Pobierz(int const i) const;
	void Translacja(Wektor w);
	Prostokat skalowanie(liczba_t skalar);
	void rotacja(liczba_t radiany, int ilosc);
	void zapisz() const;
};

#endif


