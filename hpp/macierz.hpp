#ifndef macierz_hpp
#define macierz_hpp
#include "../hpp/naglowek.hpp"
#include "../hpp/wektor.hpp"
class Macierz{
	
	private:
	int rozmiar;
  	Wektor element[SIZE];
	
	public:
	void PodajRozmiar(int liczba);
	void Ustaw(Wektor wektor, int wiersz);
	Wektor Pobierz(int const wiersz) const;
	int PobierzRozmiar() const;
	void Rotacja2D(liczba_t radiany);
	void Rotacja3D(liczba_t radiany, char os);
	
	liczba_t & operator () (int wiersz, int kolumna) 
	{
	return this->element[wiersz][kolumna];
	}
	
	Wektor & operator [] (int indeks) 
	{
	return this->element[indeks];
	}

	
};
#endif

