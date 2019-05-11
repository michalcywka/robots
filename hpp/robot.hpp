#ifndef robot_hpp
#define robot_hpp
#include "wektor.hpp"
#include "operatory.hpp"
#include "zbior_wierzcholkow.hpp"
#include "obiekt_graficzny.hpp"
#include "sciezka.hpp"


class Robot:public ObiektGraficzny{
private:
	Sciezka sciezka;
	ZbiorWierzcholkow globalne;
	ZbiorWierzcholkow lokalne;
public:
	virtual void Translacja(Wektor w);
	Robot();
	Robot(Wektor w1, liczba_t kat_rotacji, unsigned int numerek);
	~Robot();
	void Zapisz();
	void Obrot(liczba_t kat);
	void LokalneNaGlobalne();
	void RuchWPrzod(liczba_t kroki);
	bool WyliczKolizje();
	unsigned int PobierzID();
	


};



#endif
