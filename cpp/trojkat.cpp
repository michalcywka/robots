#include "../hpp/trojkat.hpp"
#include "../hpp/operatory.hpp"
#include <iostream>
#include <cmath>
#include<fstream>

using namespace std;
Trojkat::~Trojkat()
{

}
Trojkat::Trojkat()
{

}
Trojkat::Trojkat(Wektor srodek, liczba_t kat, liczba_t promien)
{
  
 
  Wektor pomocnik;
  pomocnik.PodajRozmiar(2);
  srodek.PodajRozmiar(2);
	pomocnik=srodek;

 pomocnik[0]=pomocnik[0]*cos(kat);
 cout << pomocnik[1] << endl;
 pomocnik[1]=pomocnik[1]*sin(kat);
 cout << pomocnik[1] << endl;;

 wierzcholki.push_back(srodek+pomocnik);

 pomocnik=srodek;
 kat=kat+2.0943951;
 pomocnik[0]=pomocnik[0]*cos(kat);
 pomocnik[1]=pomocnik[1]*sin(kat);

 wierzcholki.push_back(srodek+pomocnik);

 pomocnik=srodek;

 kat=kat+2.0943951;

  pomocnik[0]=pomocnik[0]*cos(kat);
 pomocnik[1]=pomocnik[1]*sin(kat);
 wierzcholki.push_back(srodek+pomocnik);
}

void Trojkat::Zapisz()
{


ofstream plik;
liczba_t k;
Wektor pomocnik;
plik.open("trojkat.txt");
	for(int i=0; i<3; i++)
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

