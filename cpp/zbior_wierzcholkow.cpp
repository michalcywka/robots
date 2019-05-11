#include "../hpp/zbior_wierzcholkow.hpp"
#include<vector>
#include<iostream>

int ZbiorWierzcholkow::LiczbaAktywnych=0;
int ZbiorWierzcholkow::LiczbaObiektow=0;

ZbiorWierzcholkow::ZbiorWierzcholkow()
{
	LiczbaAktywnych++;
	LiczbaObiektow++;
}
ZbiorWierzcholkow::~ZbiorWierzcholkow()
{
	LiczbaAktywnych--;
}
