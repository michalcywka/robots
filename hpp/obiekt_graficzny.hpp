#ifndef obiekt_graficzny_hpp
#define obiekt_graficzny_hpp
#include "wektor.hpp"
#include <iostream>
using namespace std;

class ObiektGraficzny
{

	public:
	unsigned int id;
	liczba_t katrotacji;
	Wektor srodek;
	liczba_t obszarbezpieczenstwa;
	
	virtual void Translacja(Wektor w){}

	
	virtual bool WyliczKolizje()
	{
		return false;
	}
	virtual unsigned int PobierzID()
	{
		return this->id;
	}
};

#endif
