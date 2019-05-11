#include "../hpp/prostokat.hpp"
#include "../hpp/operatory.hpp"
#include <fstream>
#include <cmath>
Prostokat::Prostokat()
{

}
Prostokat::Prostokat(Wektor w1,Wektor w2,Wektor w3,Wektor w4)
{
wierzcholek[0]=w1;
wierzcholek[1]=w2;
wierzcholek[2]=w3;
wierzcholek[3]=w4;
}

void Prostokat::Ustaw(Wektor w, int i)
{	
	if(i<1 || i>4 || w.PobierzRozmiar()!=2)
	{
		cout << "Klasa prostokat, blad ustawiania: zly wymiar wektora lub podaj liczbe z zakersu <1;4>." << endl;
	}
	else
	{
		wierzcholek[i-1]=w;
	}
}

Wektor Prostokat::Pobierz(int const i) const

{
	if(i<1 || i>4)
	{
		Wektor pobrany;
		cout << "Klasa Prostokat, blad pobierania: podaj liczbe z zakresu <1;4>" << endl;
		pobrany.Ustaw(0,1);
		pobrany.Ustaw(0,2);
		return pobrany;
	}
	else
	{
		return wierzcholek[i-1];
	}
}
void Prostokat::Translacja(Wektor w)
{
if(w.PobierzRozmiar()!=2)
	{
		cout << "Klasa prostokat, blad translacji: zly wymiar wektora" << endl;
	}

	for(int i=1; i<=4; i++)
	{
  wierzcholek[i]=wierzcholek[i]+w;
	}


}
Prostokat Prostokat::skalowanie(liczba_t skalar)

{
  Prostokat poskalowaniu;
  Wektor w;
  liczba_t pomoc;
	
for(int i=1; i<=4; i++){
  
  	w=wierzcholek[i];
  	pomoc=w.Pobierz(1);
  	pomoc=pomoc*skalar;
  	w.Ustaw(pomoc,1);
  	pomoc=w.Pobierz(2);
  	pomoc=pomoc*skalar;
  	w.Ustaw(pomoc,2);
  	poskalowaniu.Ustaw(w,i);
}
  return poskalowaniu;

}

void Prostokat::rotacja(liczba_t radiany, int ilosc)
{
	
	Macierz obrot;
	Wektor pomocnik;
	Prostokat obrocony;

	obrot.Rotacja2D(radiany);

	pomocnik.PodajRozmiar(2);

	
	for(int i=1; i<=ilosc; i++)
	{
		for(int j=1; j<=4 ;j++)
		{
		pomocnik=Pobierz(j);
		Ustaw(obrot*pomocnik,j);
		}
		
	}
	

}

void Prostokat::zapisz() const
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
	plik << k << "\n";
	}
	w=Pobierz(1);
	k=w.Pobierz(1);
	plik << k << " ";
	k=w.Pobierz(2);
	plik << k << "\n";
  plik.close();
}
