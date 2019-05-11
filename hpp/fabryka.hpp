#ifndef fabryka_hpp
#define fabryka_hpp
#include<memory>
#include "obiekt_graficzny.hpp"
class Fabryka{

static Fabryka fabryka;
shared_ptr<ObiektGraficzny> Zbuduj(typObiektu to);

public:

static Fabryka& _fabryka;

Fabryka& Pobierz();
};
#endif 
