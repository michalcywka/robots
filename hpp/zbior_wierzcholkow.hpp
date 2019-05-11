#ifndef zbior_wierzcholkow_hpp
#define zbior_wierzcholkow_hpp

#include "../hpp/naglowek.hpp"
#include "../hpp/wektor.hpp"
#include "obiekt_graficzny.hpp"
#include<vector>

class ZbiorWierzcholkow:public std::vector<Wektor>{

	static int LiczbaAktywnych;
	static int LiczbaObiektow;
public:
ZbiorWierzcholkow();
~ZbiorWierzcholkow();

};


#endif
