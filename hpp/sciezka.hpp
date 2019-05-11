#ifndef sciezka_hpp
#define sciezka_hpp
#include "../hpp/naglowek.hpp"
#include "../hpp/wektor.hpp"
#include "../hpp/zbior_wierzcholkow.hpp"
#include "obiekt_graficzny.hpp"
#include <vector>

class Sciezka:public ObiektGraficzny
{
	private:
	unsigned int ostatni;
	ZbiorWierzcholkow trasa;
	public:
	void DodajDoTrasy(Wektor w);
	void ZapiszTrase(unsigned int id);
	Sciezka();
	~Sciezka();
};

#endif
