#ifndef trojkat_hpp
#define trojkat_hpp

#include "wektor.hpp"
#include "macierz.hpp"
#include "przeszkoda.hpp"
#include "zbior_wierzcholkow.hpp"
class Trojkat:public Przeszkoda
{
 
  ZbiorWierzcholkow wierzcholki;
  /*Wektor srodek;
  liczba_t promien;
  liczba_t kat;*/

public:
	~Trojkat();
  Trojkat();
  Trojkat(Wektor srodek_, liczba_t kat_, liczba_t promien_);
  void Zapisz();
};


#endif
