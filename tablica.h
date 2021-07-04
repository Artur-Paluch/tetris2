#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "gracz.h"
using namespace std;
//deklaracje  klas, �eby mo�na ich by�o uzywa� w przyja�niach
class klocek;
class	S_poziomo;
class	S_pionowo;
class	palka_poziomo;
class	palka_pionowo;
class	kwadrat;
class	piramida_up;
class	piramida_down;
class	piramida_right;
class	piramida_left;
class	L_left;
class	L_right;
class	L_down;
class	L_up;
class	Odwr_L_up;
class	Odwr_L_left;
class	Odwr_L_right;
class	Odwr_L_down;
class	Z_poziomo;
class	Z_pionowo;

class tablica
{
private:
	char tabl[384];
	char *wsk;

public:
	void  twoz_tabele();//metoda tworzy tablic� do gry
	void wyswietlaj(); // metoda wyswietla tablice na ekran
	tablica();
	~tablica();
	char pobierz_element(int);// metoda zwraca element tablicy tabl o podanym w argumencie indeksie
	void ustaw_element(int, char);// metoda ustawia warto�� zmiennej tablicy tabl o podanym indeksie
	int  funkcja_sprawdzaj_linie(tablica *jakas_tablica, int z, int y); // metoda sprawdza czy linia pozioma w tablicy po po�o�enia klocka jest zape�niona. Zwraca 1 je�li jest 0 je�li nie
	int  sprawdzaj_czy_ta_sama_linia(int n1, int n2);// metoda sprawdza czy z1 i z2 podane w argumentach s� na tej samej lini
	void czy_punkt(tablica *jakas_tablica, klocek* jakis_klocek, gracz * jakis_gracz);// metoda zliczajaca punkty
	void funkcja_oposc(tablica *jakas_tablica, int x, int z, gracz* jakis_gracz);
};

