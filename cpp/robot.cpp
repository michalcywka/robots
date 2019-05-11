#include "../hpp/robot.hpp"
#include"../hpp/macierz.hpp"
#include "../hpp/sciezka.hpp"
#include <iostream>
#include <fstream>
#include<unistd.h>
#include<cmath>
#include<vector>
bool Robot::WyliczKolizje()
{
	return 0;
} 
void Robot::Zapisz()
{
ofstream plik;
liczba_t k;
Wektor pomocnik;

std::string nazwa="robot";

nazwa+=std::to_string(id);
nazwa+=".txt";
plik.open(nazwa);

	for(int i=0; i<6; i++)
	{
	pomocnik=globalne[i];
	
	k=pomocnik.Pobierz(1);
		plik << k << " ";
		k=pomocnik.Pobierz(2);
		plik << k << "\n";
	}
	pomocnik=globalne[1];
	k=pomocnik.Pobierz(1);
	plik << k << " ";
	k=pomocnik.Pobierz(2);
	plik << k << "\n";

		
	pomocnik=globalne[0];
	k=pomocnik.Pobierz(1);
	plik << k << " ";
	k=pomocnik.Pobierz(2);
	plik << k << "\n";
  plik.close();
}
void Robot::Obrot(liczba_t kat)
{
	Macierz rotacja;
	Wektor pomocnik;
	katrotacji=katrotacji+kat;
	rotacja.Rotacja2D(kat);
	for(int i=0; i<6; i++)
	{
	pomocnik=lokalne[i];
	lokalne[i]=rotacja*pomocnik;
	}
	LokalneNaGlobalne();
	Zapisz();
	
}
void Robot::Translacja(Wektor w)
{
	
	for(int i=0; i<6 ;i++)
	{
	
	globalne[i]=lokalne[i]+w;
	
	}
	srodek=w;

}
Robot::Robot(Wektor w1, liczba_t kat_rotacji, unsigned int numerek){
id=numerek;
obszarbezpieczenstwa=2;
srodek.PodajRozmiar(2);
for( unsigned int i=0; i<6; i++)
{
globalne.push_back(Wektor(0,0));
}

lokalne.push_back(Wektor(1,0));
lokalne.push_back(Wektor(2,0));
lokalne.push_back(Wektor(1,1.5));
lokalne.push_back(Wektor(-1,1.5));
lokalne.push_back(Wektor(-1,-1.5));
lokalne.push_back(Wektor(1,-1.5));
Obrot(kat_rotacji);
katrotacji=kat_rotacji;
Translacja(w1);

Zapisz();
}

Robot::~Robot()
{


}


void Robot::LokalneNaGlobalne()
{
	for(int i=0; i<6 ;i++)
	{
	globalne[i]=lokalne[i]+srodek;
	}
}


void Robot::RuchWPrzod(liczba_t krok)
{

	sciezka.DodajDoTrasy(srodek);
	srodek[0]=srodek[0]+krok*cos(katrotacji);
	srodek[1]=srodek[1]+krok*sin(katrotacji);
	sciezka.DodajDoTrasy(globalne[0]);
	LokalneNaGlobalne();
	sciezka.ZapiszTrase(id);
	Zapisz();


}

unsigned int Robot::PobierzID()
{

	return this->id;

}

Robot::Robot()
{

}

