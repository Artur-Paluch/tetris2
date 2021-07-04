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


/////////////////////////////////// 
// metoda sprawdza czy linia pozioma w tablicy po po�o�enia klocka jest zape�niona. Zwraca 1 je�li jest 0 je�li nie
int tablica::funkcja_sprawdzaj_linie(tablica *jakas_tablica, int z, int y)
{
	int i = 0;
	//je�li z pobrany z obiektu klocek jest wi�kszy od y+84  (+84 bo y jest liczone od 0 a wy�ej s� jeszcze znaki)
	// s� liczone od zera, czyli po lewej kraw�dzi tablicy
	//y jest na poziomie najni�szej cz�ci klocka
	if (z>y + 84)
	{
		for (i = y +1 + 84; i<y + 11 + 84; i++)
			// od lewego, g�rnego rogu tablicy, powi�kszonego o 84 (do poziomu gdzie zaczyna si� operowanie klockeim) +1 bo sprawdzane jest pole gry
			//do +11 bo obszar gry ma 10 p�l w poziomie
		{
			if (jakas_tablica->pobierz_element(i) != ' ') //je�li kratka jest zaj�ta
			{
				continue;
			}
			else {//kratka by�a pusta, linia nie jest zaj�ta
				return 0;
			}
		}
		return 1;
	}
	///////////////////////////////////////////////////////
	if (z<y + 84 && (z>y - 12 + 84))
		//z jest o 1 poziom wy�ej od y 

	{
		for (i = y - 12 + 1 + 84; i<y - 12 + 11 + 84; i++)
		{
			if (jakas_tablica->pobierz_element(i) != ' ')
			{
				continue;
			}
			else {
				return 0;
			}
			// linia gdzies pusta
		}
		return 1;
		//  linia zapelniona
	}
	///////////////////////////////////////////////////////
	if ((z<y - 12 + 84) && (z>(y - 24 + 84)))
	{//z jest o 2 poziomy wy�ej od y 
		for (i = y - 24 + 1 + 84; i<y - 24 + 11 + 84; i++)
		{
			if (jakas_tablica->pobierz_element(i) != ' ')
			{
				continue;
			}
			else {
				return 0;
			}
			// linia gdzies pusta
		}
		return 1;
		//  linia zapelniona
	}
	///////////////////////////////////////////////////////
	if ((z<y - 24 + 84) && (z>(y - 36 + 84)))
	{//z jest o 3 poziomy wy�ej od y 
		for (i = y - 36 + 1 + 84; i<y - 36 + 11 + 84; i++)
		{
			if (jakas_tablica->pobierz_element(i) != ' ')
			{
				continue;
			}
			else {
				return 0;
			}
			// linia gdzies pusta
		}
		return 1;
		//  linia zapelniona
	}
	///////////////////////////////////////////////////////
	if ((z<y - 36 + 84) && (z>(y - 48 + 84)))
	{//z jest o 4 poziomy wy�ej od y 
		for (i = y - 48 + 1 + 84; i<y - 48 + 11 + 84; i++)
		{
			if (jakas_tablica->pobierz_element(i) != ' ')
			{
				continue;
			}
			else {
				return 0;
			}
			// linia gdzies pusta
		}
		return 1;
		//  linia zapelniona
	}
}