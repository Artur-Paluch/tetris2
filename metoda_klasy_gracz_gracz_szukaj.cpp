#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// funkcja wyszukiwania gracza o danym nicku
int gracz::gracz_szukaj(string szukany_nick)
{
	int z = 0;
	fstream plik_graczy;
	gracz *y = new gracz; //obiekt typu gracz
	plik_graczy.open("plik_graczy.bin", ios::in | ios::binary); //otwieranie pliku bin. w trybie do odczytu
	if (plik_graczy.good() == false) //b��d odczytu
	{
		cout << "Brak pliku z danymi";
	}
	else
	{
		while (!plik_graczy.eof()) //do ko�ca pliku
		{
			plik_graczy.read((char*)y, sizeof(gracz)); //pobiera obiekt gracz
			if (y->nick != szukany_nick)//je�li nick w pliku nie jest taki sam jak nick do wyszukania wraca do p�tli i pobiera nast�pny obiekt
			{
			}
			else
			{
				z = 1;
				break;
			}
		}
		//zamykanie pliku
		plik_graczy.close();
		plik_graczy.clear();
	}
	return z; //zwracanie zmiennej okre�laj�cej czy znaleziono czy nie
}