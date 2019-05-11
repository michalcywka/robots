#ifndef wektor_hpp
#define wektor_hpp
#include "../hpp/naglowek.hpp"
using namespace std;


class Wektor {
	private:
	int rozmiar;
	liczba_t element[SIZE];

	public:
	Wektor();
	Wektor(liczba_t x, liczba_t y);
	void PodajRozmiar(int liczba);
	void Ustaw(liczba_t liczba, int miejsce);
	liczba_t Pobierz(int miejsce) const;
	int PobierzRozmiar() const;
	
	liczba_t & operator [] (int indeks) 
	{
	return this->element[indeks];
	}

	const liczba_t & operator [] (int indeks) const 
	{
	return this->element[indeks];
	}

};

#endif





