#include "../hpp/scena.hpp"
#include "../hpp/operatory.hpp"
#include <cmath>
Scena::Scena()
{

}

Scena::~Scena()
{

}
liczba_t Scena::ObliczDystans(Wektor o1, Wektor o2)
{

	return sqrt( pow(o1[0] - o2[0], 2) + pow(o1[1] - o2[1], 2) );

}
bool Scena::WyliczKolizje(ObiektGraficzny obiekt)
{

unsigned int pobraneID=obiekt.PobierzID();
  for(list<shared_ptr<ObiektGraficzny> >::iterator it=roboty.begin(); it != roboty.end(); ++it)
	{
	if((*it)->id!=pobraneID){
		if(ObliczDystans(obiekt.srodek,((*it)->srodek))<=(obiekt.obszarbezpieczenstwa+(*it)->obszarbezpieczenstwa))
		{
		cout << "Wykryto kolizje, robot zatrzymany" << endl;
		return 1;
		}
		}
	}
  for(list<shared_ptr<ObiektGraficzny> >::iterator it=przeszkody.begin(); it != przeszkody.end(); ++it)
	{
	
	if((*it)->id!=pobraneID){
		if(ObliczDystans(obiekt.srodek,((*it)->srodek))<=(obiekt.obszarbezpieczenstwa+(*it)->obszarbezpieczenstwa))
		{
		cout << "Wykryto kolizje, robot zatrzymany" << endl;
		return 1;
		}
		}
	}
return 0;

}

void Scena::DodajRobota(Robot robot)
{
	roboty.push_back(make_shared<ObiektGraficzny> (robot));
}

void Scena::DodajPrzeszkode(Przeszkoda przeszkoda)
{
	przeszkody.push_back(make_shared<ObiektGraficzny> (przeszkoda));
}


