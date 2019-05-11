#include "../hpp/przeszkoda.hpp"
#include "../hpp/operatory.hpp"
#include <iostream>
#include <fstream>
using namespace std;
Przeszkoda::Przeszkoda()
{

}
Przeszkoda::Przeszkoda(Wektor w1, Wektor w2, Wektor w3, Wektor w4,unsigned int ident)
{
	id=ident;
	obszarbezpieczenstwa=3.3;
	srodek=Wektor((w1[0]+w3[0])/2,(w1[1]+w3[1])/2);
	wierzcholki.push_back(w1);
	wierzcholki.push_back(w2);	
	wierzcholki.push_back(w3);
	wierzcholki.push_back(w4);

}
Przeszkoda::~Przeszkoda()
{

}
void Przeszkoda::Translacja(Wektor w)
{
	
	for(int i=0; i<5 ;i++)
	{
	wierzcholki[i]=wierzcholki[i]+w;
	
	}
	srodek=w;

}
void Przeszkoda::ZapiszPrzeszkode()
{

ofstream plik;
liczba_t k;
Wektor pomocnik;
std::string nazwa;
nazwa="przeszkoda";
nazwa+=std::to_string(id);
nazwa+=".txt";
plik.open(nazwa);
	for(unsigned int i=0; i<4; i++)
	{
	pomocnik=wierzcholki[i];
	k=pomocnik.Pobierz(1);
	plik << k << " ";
	k=pomocnik.Pobierz(2);
	plik << k << "\n";
	}
	pomocnik=wierzcholki[0];
	k=pomocnik.Pobierz(1);
	plik << k << " ";
	k=pomocnik.Pobierz(2);
	plik << k << "\n";
plik.close();


}
