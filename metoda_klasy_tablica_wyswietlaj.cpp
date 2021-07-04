#include "tablica.h"
#include <iostream>
#include <cstdlib>
#include "parametry_konkretnych_klockow.h"
#include "funkcje.hpp"
#include "gra.h"
#include "gracz.h"
#include <conio.h>
#include <Windows.h>  //bibl do bufora
#include <cstdlib> //losowosc
#include <time.h>  // wymagana do czasu  
#include <cstring>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////
// metoda wyswietla tablice na ekran
void tablica::wyswietlaj()
{
	char ksztalt = 219;//79//219  // kszta�t klock�w
	HANDLE hOut; //uchwyt dla kolor�w

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int y = 0, koniec_linii = 0;
	for (y = 0; y<348; y++)
	{
		if (y == koniec_linii + 11)
		{
			koniec_linii += 12;
			cout << pobierz_element(y) << endl;//pobiera i wy�wietla warto�� elementu tablicy o indeksie y po czym przechodzi do nast�pnej linii
		}
		else
		{
			switch (pobierz_element(y)) //w zale�no�ci od warto�ci zapisanej w tablicy (0-6 - s� to warto�ci kolor z klasy klocek) zmienia kolor czcionki na t� jaki ma by� klocek, po czym wraca do  domy�lnej
			{
			case 0://///////////////////////////////////////////////////////////
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << ksztalt;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				break;
			case 1://///////////////////////////////////////////////////////////
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << ksztalt;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				break;
			case 2://///////////////////////////////////////////////////////////
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << ksztalt;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				break;
			case 3://///////////////////////////////////////////////////////////////
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				cout << ksztalt;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				break;
			case 4://///////////////////////////////////////////////////////////////
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << ksztalt;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				break;
			case 5://///////////////////////////////////////////////////////////////
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
				cout << ksztalt;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				break;
			case 6://///////////////////////////////////////////////////////////////
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				cout << ksztalt;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				break;
			default://///////////////////////////////////////////////////////////
				cout << pobierz_element(y);
				break;
			}
		}
	}
}