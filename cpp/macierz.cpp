#include "../hpp/macierz.hpp"
#include <iostream>
#include <cmath>
void Macierz::PodajRozmiar(int liczba)
{
	if(liczba<0 || liczba>100)
	{
	cout << "Klasa Macierz, blad rozmiaru: niepoprawna liczba" << endl;
	}
	else{
	rozmiar=liczba;
	}
}

void Macierz::Ustaw(Wektor wektor, int wiersz)
{
	int rozmiarek=Macierz::PobierzRozmiar();
	if(wiersz>rozmiarek || wiersz<0)
	{
		cout << "Klasa Macierz, blad ustawiania: przekroczono rozmiar " << endl;
	}
	else{
	element[wiersz-1]=wektor;
	}
}

Wektor Macierz::Pobierz(int const wiersz) const
{
	int rozmiarek=Macierz::PobierzRozmiar();
	if(wiersz>rozmiarek || wiersz<0)
	{
	  Wektor blad;
	  blad.PodajRozmiar(2);
	  blad.Ustaw(0,1);
	  blad.Ustaw(0,2);
		cout << "Klasa Macierz, blad pobierania: przekroczono rozmiar " << endl;
		return blad;
	}
	else{
	return element[wiersz-1];
	}
}
int Macierz::PobierzRozmiar() const
{
	return rozmiar;
}
void Macierz::Rotacja2D(liczba_t radiany)
{
	PodajRozmiar(2);
	Wektor pomocnik;
	
	pomocnik.PodajRozmiar(2);
	pomocnik.Ustaw(cos(radiany),1);
	pomocnik.Ustaw(-sin(radiany),2);
	Ustaw(pomocnik,1);
	pomocnik.Ustaw(sin(radiany),1);
	pomocnik.Ustaw(cos(radiany),2);
	Ustaw(pomocnik,2);
}

void Macierz::Rotacja3D(liczba_t radiany, char os)
{
PodajRozmiar(3);
Wektor pomocnik;
pomocnik.PodajRozmiar(3);
	switch (os)
{

	case 'z':
	
	
	pomocnik.Ustaw(cos(radiany),1);
	pomocnik.Ustaw(-sin(radiany),2);
	pomocnik.Ustaw(0,3);
	Ustaw(pomocnik,1);

	pomocnik.Ustaw(sin(radiany),1);
	pomocnik.Ustaw(cos(radiany),2);
	pomocnik.Ustaw(0,3);
	Ustaw(pomocnik,2);
	
	pomocnik.Ustaw(0,1);
	pomocnik.Ustaw(0,2);
	pomocnik.Ustaw(1,3);
	Ustaw(pomocnik,3);
	break;

case 'y':

	pomocnik.Ustaw(cos(radiany),1);
	pomocnik.Ustaw(0,2);
	pomocnik.Ustaw(sin(radiany),3);
	Ustaw(pomocnik,1);

	pomocnik.Ustaw(0,1);
	pomocnik.Ustaw(1,2);
	pomocnik.Ustaw(0,3);
	Ustaw(pomocnik,2);
	
	pomocnik.Ustaw(-sin(radiany),1);
	pomocnik.Ustaw(0,2);
	pomocnik.Ustaw(cos(radiany),3);
	Ustaw(pomocnik,3);
	break;


case 'x':

	pomocnik.Ustaw(1,1);
	pomocnik.Ustaw(0,2);
	pomocnik.Ustaw(0,3);
	Ustaw(pomocnik,1);

	pomocnik.Ustaw(0,1);
	pomocnik.Ustaw(cos(radiany),2);
	pomocnik.Ustaw(-sin(radiany),3);
	Ustaw(pomocnik,2);
	
	pomocnik.Ustaw(0,1);
	pomocnik.Ustaw(sin(radiany),2);
	pomocnik.Ustaw(cos(radiany),3);
	Ustaw(pomocnik,3);
	break;
default:
break;
}
}
