#ifndef przeszkoda_hpp
#define przeszkoda_hpp
#include "wektor.hpp"
#include "obiekt_graficzny.hpp"
#include "zbior_wierzcholkow.hpp"
#include <vector>
#include <iostream>
#include <list>
using namespace std;

class Przeszkoda:public ObiektGraficzny
{
	ZbiorWierzcholkow wierzcholki;

	public:
	~Przeszkoda();
	Przeszkoda();
	Przeszkoda(Wektor w1, Wektor w2, Wektor w3, Wektor w4,unsigned int ident);
	void Translacja(Wektor w);
	void ZapiszPrzeszkode();
};

#endif
