#include "../hpp/naglowek.hpp"
#include "../hpp/wektor.hpp"
#include "../hpp/sciezka.hpp"
#include "../hpp/operatory.hpp"
#include <vector>
#include <fstream>
Sciezka::Sciezka()
{

ostatni=0;
}

Sciezka::~Sciezka()
{
}
void Sciezka::DodajDoTrasy(Wektor w)
{
	trasa.push_back(w);

}

void Sciezka::ZapiszTrase(unsigned int id)
{

ofstream plik;
liczba_t k;
Wektor pomocnik;
std::string nazwa;
nazwa="sciezka";
nazwa+=std::to_string(id);
nazwa+=".txt";
plik.open(nazwa,std::ios::app);
	for(unsigned int i=ostatni; i<trasa.size(); i++)
	{
	ostatni++;
	pomocnik=trasa[i];
	k=pomocnik.Pobierz(1);
	plik << k << " ";
	k=pomocnik.Pobierz(2);
	plik << k << "\n";
	}
plik.close();

}
