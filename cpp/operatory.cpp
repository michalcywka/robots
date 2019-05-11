#include "../hpp/operatory.hpp"
#include "../hpp/naglowek.hpp"
#include "../hpp/wektor.hpp"
#include "../hpp/macierz.hpp"
#include "../hpp/prostokat.hpp"
#include "../hpp/prostopadloscian.hpp"
#include <iostream>
using namespace std;

ostream & operator  << (ostream & wyjscie, const Wektor &w)
{
	int rozmiarek=w.PobierzRozmiar();
	for(int i=1;i<=rozmiarek;i++)
	{
	cout << w.Pobierz(i) << " ";
	}
	return wyjscie;
}

istream & operator >> (istream & wejscie, Wektor &w)
{
	int rozmiar;
	liczba_t numerek;

	cout << "Podaj rozmiar wektora: " << endl;
	cin >> rozmiar;

	w.PodajRozmiar(rozmiar);

	cout << "Podaj " << rozmiar << " liczby" << endl;

	for(int i=1; i<=rozmiar; i++)
	{
		cin >> numerek;
		w.Ustaw(numerek, i);
	}
	return wejscie;
	
}

ostream & operator << (ostream & wyjscie, const Prostokat &p)
{
	Wektor pomocnik;
	for(int i=1; i<=4; i++)
	{
		pomocnik=p.Pobierz(i);
		cout << pomocnik << "\n";
	}
	return wyjscie;
}
ostream & operator << (ostream & wyjscie, const Prostopadloscian &p)
{
	Wektor pomocnik;
	for(int i=1; i<=8; i++)
	{
		pomocnik=p.Pobierz(i);
		cout << pomocnik << "\n";
	}
	return wyjscie;
}
liczba_t operator * (Wektor w1, Wektor w2)
{
  liczba_t wynik;
	if(w1.PobierzRozmiar()!=w2.PobierzRozmiar())
	{
		cout << "Blad mnozenia wektorow: wymiary sie nie zgadzaja" << endl;
		wynik=0;
		return wynik;
	}
if(w1.PobierzRozmiar()==2){
  wynik=w1.Pobierz(1)*w2.Pobierz(1)+w1.Pobierz(2)*w2.Pobierz(2);
  return wynik;
	}
if(w1.PobierzRozmiar()==3){
  wynik=w1.Pobierz(1)*w2.Pobierz(1)+w1.Pobierz(2)*w2.Pobierz(2)+w1.Pobierz(3)*w2.Pobierz(3);
  return wynik;
	}
cout << "Blad mnozenia wektorow: wymiar" << endl;
wynik=0;
return wynik;
}
Wektor operator * (liczba_t l, const  Wektor w)
{
	Wektor wynik;
	wynik.PodajRozmiar(w.PobierzRozmiar());
	for(int i=0; i<w.PobierzRozmiar(); i++)
	{
		wynik[i]=l*w[i];	
	}
	
return wynik;

}
Wektor operator * (const Macierz &m, const Wektor &w)
{
Wektor wynik;

if(m.PobierzRozmiar()!=w.PobierzRozmiar())
	{
		cout << "Blad mnozenia macierzy: wymiary sie nie zgadzaja" << endl;
		wynik.PodajRozmiar(1);
		wynik.Ustaw(1,1);
	return wynik;
	}
if(w.PobierzRozmiar()==2)
{
	
		wynik.PodajRozmiar(2);
		wynik.Ustaw(m.Pobierz(1)*w,1);
		wynik.Ustaw(m.Pobierz(2)*w,2);
	return wynik;
	}

if(w.PobierzRozmiar()==3)
{
		wynik.PodajRozmiar(3);
		wynik.Ustaw(m.Pobierz(1)*w+m.Pobierz(1)*w,1);
		wynik.Ustaw(m.Pobierz(2)*w+m.Pobierz(2)*w,2);
		wynik.Ustaw(m.Pobierz(3)*w+m.Pobierz(3)*w,3);
	return wynik;

}
cout << "Blad mnozenia macierzy przez wektor: wymiar" << endl;
wynik.PodajRozmiar(1);
wynik.Ustaw(1,1);
return wynik;	
}

Wektor operator + (const Wektor &w1, const Wektor &w2)
{
  Wektor wynik;
	if(w1.PobierzRozmiar()==2){
  wynik.PodajRozmiar(2);
  wynik.Ustaw(w1.Pobierz(1)+w2.Pobierz(1),1);
  wynik.Ustaw(w1.Pobierz(2)+w2.Pobierz(2),2);
  return wynik;
}
  wynik.PodajRozmiar(3);
  wynik.Ustaw(w1.Pobierz(1)+w2.Pobierz(1),1);
  wynik.Ustaw(w1.Pobierz(2)+w2.Pobierz(2),2);
wynik.Ustaw(w1.Pobierz(3)+w2.Pobierz(3),3);
  return wynik;
}

