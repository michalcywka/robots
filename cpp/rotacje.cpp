#include <iostream>
#include <fstream>
#include <unistd.h>

#include"../hpp/naglowek.hpp"
#include"../hpp/wektor.hpp"
#include"../hpp/macierz.hpp"
#include"../hpp/prostokat.hpp"
#include"../hpp/operatory.hpp"
#include"../hpp/obiekt_graficzny.hpp"
#include"../hpp/lacze_do_gnuplota.hpp"
#include"../hpp/robot.hpp"
#include"../hpp/przeszkoda.hpp"
#include"../hpp/trojkat.hpp"
#include"../hpp/scena.hpp"
#include"../hpp/fabryka.hpp"
void WyswMenu()
{
	cout << endl << "Sterowanie robotem mobilnym" << endl;
	cout << "Przesun robota na wprost - p" << endl;
	cout << "Wybierz robota - w" << endl;
	cout << "Obrot robota - r" << endl << endl;
	cout << "Pokaz menu - m" << endl;
	cout << "Koniec programu - k" << endl << endl; 

}

using namespace std;


int main(){

	Robot *wybrany_robot;
	std::string nazwa;
	const char *nazwap;
	char opcja;
	int liczba;
	liczba_t kroki;
	liczba_t kat;
	Robot robot1=Robot(Wektor(20,10),2.5,1);
	Robot robot2=Robot(Wektor(3,3),0,2);
	Przeszkoda przeszkoda1, przeszkoda2;
	PzG::LaczeDoGNUPlota Lacze;
	Scena scena;
	Wektor poprzednie;

	przeszkoda1=Przeszkoda(Wektor(5,5),Wektor(10,5),Wektor(10,10),Wektor(5,10),11);
	przeszkoda1.ZapiszPrzeszkode();
	Lacze.DodajNazwePliku("przeszkoda11.txt",PzG::RR_Ciagly,2);
	scena.DodajPrzeszkode(przeszkoda1);
	
	przeszkoda2=Przeszkoda(Wektor(15,15),Wektor(20,15),Wektor(20,20),Wektor(15,20),12);
	przeszkoda2.ZapiszPrzeszkode();
	Lacze.DodajNazwePliku("przeszkoda12.txt",PzG::RR_Ciagly,2);
	scena.DodajPrzeszkode(przeszkoda2);

	
	robot1.Zapisz();
	Lacze.DodajNazwePliku("robot1.txt",PzG::RR_Ciagly,2);
	scena.DodajRobota(robot1);

	
	robot2.Zapisz();
	Lacze.DodajNazwePliku("robot2.txt",PzG::RR_Ciagly,2);
	scena.DodajRobota(robot2);


	remove("sciezka1.txt");
	remove("sciezka2.txt");

  Lacze.Inicjalizuj();
  Lacze.ZmienTrybRys(PzG::TR_2D);
  Lacze.UstawZakresY(-10,50);
  Lacze.UstawZakresX(-10,50);
  Lacze.Rysuj();
	
	wybrany_robot=&robot1;

cout << "Aktualnie wybrany robot numer " << wybrany_robot->PobierzID() << endl;
	
while(opcja!='k')
{
WyswMenu();
cin >> opcja;
switch(opcja)
{

cout << "Aktualnie wybrany robot numer " << wybrany_robot->PobierzID() << endl;
	
	case 'p':
	nazwa="sciezka";
	nazwa+=std::to_string(wybrany_robot->PobierzID());
	nazwa+=".txt";

	nazwap=nazwa.c_str();

	Lacze.DodajNazwePliku(nazwap,PzG::RR_Ciagly,2);
	cout << "Podaj ilosc krokow" << endl;
	cin >> liczba;
	
	kroki=((double) liczba)/10;

	poprzednie=wybrany_robot->srodek;
	
	for (int i=0; i<10; i++)
	{
	cout << poprzednie << "poprz" << endl;
	cout << scena.ObliczDystans(przeszkoda2.srodek,robot1.srodek) << "dystans1"<< endl;
	if(scena.WyliczKolizje(*wybrany_robot))
	{
	wybrany_robot->Translacja(poprzednie);
	wybrany_robot->srodek=poprzednie;
	cout << wybrany_robot->srodek << "srodek" << endl;
	cout << scena.ObliczDystans(przeszkoda2.srodek,robot1.srodek) << "dystans2" << endl;
		i = 11;
	}	
	poprzednie=wybrany_robot->srodek;
	wybrany_robot->RuchWPrzod(kroki);
	Lacze.Rysuj();
	usleep(1000000);
	}
	break;
	
	case 'r':
	cout << "Podaj kat obrotu w radianach" << endl;
	cin >> kat;
	wybrany_robot->Obrot(kat);
	Lacze.Rysuj();
	break;

	case 'w':
	cout << "Podaj ID robota" << endl;
	cin >> liczba;
	if(liczba==1) wybrany_robot=&robot1;
	if(liczba==2) wybrany_robot=&robot2;
	break;
	
	case 'm':
	break;

	case 'k':
	break;


}
}


}




