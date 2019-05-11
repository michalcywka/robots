#include "../hpp/prostokat.hpp"
#include "../hpp/operatory.hpp"
#include <cmath>
#include <fstream>

Prostopadloscian::Prostopadloscian(){

wierzcholek[0].PodajRozmiar(3);
wierzcholek[1].PodajRozmiar(3);
wierzcholek[2].PodajRozmiar(3);
wierzcholek[3].PodajRozmiar(3);
wierzcholek[4].PodajRozmiar(3);
wierzcholek[5].PodajRozmiar(3);
wierzcholek[6].PodajRozmiar(3);
wierzcholek[7].PodajRozmiar(3);

}

void Prostopadloscian::Ustaw(Wektor w, int i)
{	
	if(i<1 || i>8 || w.PobierzRozmiar()!=3)
	{
		cout << "Klasa prostopadloscian, blad ustawiania: zly wymiar wektora lub liczba spoza zakersu <1;8>." << endl;
	}
	else
	{
		wierzcholek[i-1]=w;
	}
}

Wektor Prostopadloscian::Pobierz(int const i) const

{
	if(i<1 || i>8)
	{
		Wektor pobrany;
		cout << "Klasa prostopadloscian, blad pobierania: podaj liczbe z zakresu <1;8>" << endl;
		pobrany.PodajRozmiar(3);
		pobrany.Ustaw(0,1);
		pobrany.Ustaw(0,2);
		pobrany.Ustaw(0,3);
		return pobrany;
	}
	else
	{
		return wierzcholek[i-1];
	}
}
void Prostopadloscian::translacja(Wektor w)
{

	if(w.PobierzRozmiar()!=3)
	{
	cout << "Klasa prostopadloscian, blad translacji: podaj wektor 3D" << endl;
	}

  Wektor pomocnik,rezultat;


  rezultat.PodajRozmiar(3);
  pomocnik.PodajRozmiar(3);

	for(int i=1; i<=8; i++)
	{
	
  	pomocnik=Pobierz(i);
 	rezultat=pomocnik+w;
  	Ustaw(rezultat,i);
	}

}



void Prostopadloscian::rotacja(liczba_t radiany, int ilosc, char os)
{


	Macierz obrot;
	Wektor pomocnik;

	obrot.Rotacja3D(radiany,os);
	pomocnik.PodajRozmiar(3);
	
	for(int i=1; i<=ilosc; i++)
	{
		for(int j=1; j<=8 ;j++)
		{
		pomocnik=Pobierz(j);
		Ustaw(obrot*pomocnik,j);
		}
		
	}

}
void Prostopadloscian::zapisz() const
{
ofstream plik;
liczba_t k;
Wektor w;
  plik.open("prost.txt");
	for(int i=1; i<=4; i++)
	{
	w=Pobierz(i);
	k=w.Pobierz(1);
	plik << k << " ";
	k=w.Pobierz(2);
	plik << k << " ";
	k=w.Pobierz(3);
	plik << k << "\n";
	}
	w=Pobierz(1);
	k=w.Pobierz(1);
	plik << k << " ";
	k=w.Pobierz(2);
	plik << k << " ";
	k=w.Pobierz(3);
	plik << k << "\n";
	for(int i=5; i<=8; i++)
	{
	w=Pobierz(i);
	k=w.Pobierz(1);
	plik << k << " ";
	k=w.Pobierz(2);
	plik << k << " ";
	k=w.Pobierz(3);
	plik << k << "\n";
	w=Pobierz(i-4);
	k=w.Pobierz(1);
	plik << k << " ";
	k=w.Pobierz(2);
	plik << k << " ";
	k=w.Pobierz(3);
	plik << k << "\n";
	w=Pobierz(i);
	k=w.Pobierz(1);
	plik << k << " ";
	k=w.Pobierz(2);
	plik << k << " ";
	k=w.Pobierz(3);
	plik << k << "\n";
	}
	w=Pobierz(5);
	k=w.Pobierz(1);
	plik << k << " ";
	k=w.Pobierz(2);
	plik << k << " ";
	k=w.Pobierz(3);
	plik << k << "\n";
  plik.close();
}
