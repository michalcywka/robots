#include "../hpp/wektor.hpp"
#include <iostream>


void Wektor::PodajRozmiar(int liczba)
{
	if(liczba<0 || liczba>100)
	{
	cout << "Klasa Wektor, blad rozmiaru: niepoprawna liczba" << endl;
	}
	else{
	rozmiar=liczba;
	}
}

void Wektor::Ustaw(liczba_t liczba, int miejsce)
{
	int rozmiarek=Wektor::PobierzRozmiar();
	if(miejsce>rozmiarek || miejsce<0)
	{
		cout << "Klasa Wektor, blad ustawiania: przekroczono rozmiar " << endl;
	}
	else{
	element[miejsce-1]=liczba;
	}
}

liczba_t Wektor::Pobierz(int miejsce) const
{
	int rozmiarek=Wektor::PobierzRozmiar();
	if(miejsce>rozmiarek || miejsce<0)
	{
		cout << "Klasa Wektor, blad pobierania: przekroczono rozmiar " << endl;
		return 0;
	}
	else{
	return element[miejsce-1];
	}
}
int Wektor::PobierzRozmiar() const
{
	return rozmiar;
}
Wektor::Wektor()
{

}
Wektor::Wektor(liczba_t x, liczba_t y)
{

	PodajRozmiar(2);
	Ustaw(x,1);
	Ustaw(y,2);

}
