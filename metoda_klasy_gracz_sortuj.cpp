#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// funkcja sortuje wyniki w pliku
void gracz::sortuj()
{
	fstream plik_wynikow;//zmienna  stream pliku

	plik_wynikow.open("plik_wynikow.bin", ios::in | ios::out | ios::binary); //otwieranie pliku binarnego do odczytu i zapisu
	if (plik_wynikow.good() == false)//je�li plik nie wczytany
	{
		cout << "Brak pliku z danymi";
		_getch();
		system("cls");
		wyswietl_intro(1);	
	}
	else
	{
		gracz *b = NULL;
		b = new gracz;
		gracz *a;
		int tab_wynikow[99];

		string tab_nickow[99];
		string pom2;
		int i = 0, pom1 = 0;
		while (!plik_wynikow.eof()) //do ko�ca pliku
		{	
			if (b->wynik <= 0) //je�li zmienna wynik >0
			{
			}
			else
			{
				tab_nickow[i] = b->nick; //wpisz  do tablicy o indeksie i warto�� zmiennej nick obiektu b
				tab_wynikow[i] = b->wynik;//wpisz  do tablicy o indeksie i warto�� zmiennej wynik obiektu b
				i++;
			}
			plik_wynikow.read((char*)b, sizeof(gracz));// wczytuj obiekt z pliku
		}
		i = 0;

		while (tab_nickow[i] != "") //do ko�ca tablicy
		{
			if (tab_wynikow[i]<tab_wynikow[i + 1])
				//je�li warto�� elementu o indeksie i  <  warto�ci elementu o indeksie i+1  zamienia te warto�ci miejscami i zaczyna sprawdza� tablic� od pocz�tku
			{
				pom1 = tab_wynikow[i];
				pom2 = tab_nickow[i];

				tab_wynikow[i] = tab_wynikow[i + 1];
				tab_nickow[i] = tab_nickow[i + 1];

				tab_wynikow[i + 1] = pom1;
				tab_nickow[i + 1] = pom2;
				i = 0;
			}
			else // je�li warto�� w i>=  warto�ci w i+1 sprawdzaj zmienne o indeksach o 1 wi�kszych
			{
				i++;
			}
		}
		i = 0;
		plik_wynikow.close();
		plik_wynikow.clear();
		remove("plik_wynikow.bin");//kasowanie pliku

		plik_wynikow.open("plik_wynikow.bin", ios::app | ios::binary);//tworzenie nowego pliku binarnego z wynikami z opcj� zapisu na ko�cu
		while (tab_wynikow[i] >= 0) //dop�ki warto�ci w tablicy >=0 do pliku zapisywane s� kolejne obiekty z zmiennymi pobranymi z tablic
		{
			a = new gracz;
			a->ustaw_nick(tab_nickow[i]);
			a->zmien_wynik(tab_wynikow[i]);
			plik_wynikow.write((char*)a, sizeof(gracz));
			i++;
		}
		//zamykanie pliku
		plik_wynikow.close();
		plik_wynikow.clear();
	
	}
}