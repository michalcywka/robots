#ifndef scena_hpp
#define scena_hpp
#include "naglowek.hpp"
#include "wektor.hpp"
#include "zbior_wierzcholkow.hpp"
#include "obiekt_graficzny.hpp"
#include "sciezka.hpp"
#include "robot.hpp"
#include<list>
#include<memory>

class Scena:public ObiektGraficzny
{
	list< std::shared_ptr<ObiektGraficzny> > roboty;
	list< std::shared_ptr<ObiektGraficzny> > przeszkody;
	list< std::shared_ptr<ObiektGraficzny> > sciezki;
	public:
	Scena();
	~Scena();
 	bool WyliczKolizje(ObiektGraficzny obiekt);
	void DodajRobota(Robot robot);
	void DodajPrzeszkode(Przeszkoda przeszkoda);
	liczba_t ObliczDystans(Wektor o1, Wektor o2);
	ObiektGraficzny ZnajdzRobota(int unsigned ident);
	
};
#endif
