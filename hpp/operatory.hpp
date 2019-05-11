#ifndef operatory_hpp
#define operatory_hpp
#include "naglowek.hpp"
#include "wektor.hpp"
#include "macierz.hpp"
#include "prostokat.hpp"
#include "prostopadloscian.hpp"
#include <iostream>
ostream & operator  << (ostream & wyjscie, const Wektor &w);
istream & operator >> (istream & wejscie,const Wektor &w);
ostream & operator << (ostream & wyjscie, const Prostokat &p);
ostream & operator << (ostream & wyjscie, const Prostopadloscian &p);

liczba_t operator * (const Wektor w1, const  Wektor w2);
Wektor operator * (liczba_t l, const  Wektor w);
Wektor operator * (const Macierz &m, const Wektor &w);
Wektor operator + (const Wektor &w1, const Wektor &w2);
#endif
