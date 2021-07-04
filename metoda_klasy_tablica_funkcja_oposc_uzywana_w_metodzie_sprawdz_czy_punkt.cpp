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
////////////////////////////////
//metoda pocz�wszy od najbardziej na prawo elementu od zX, a� do pocz�tku pola gry nadpisuje kolejne elementy elementami o indeksach i-12
//np  tab[100] nadpisuje elementem tab[88], czyli poziom wy�ej, nast�pnie tab[99] elementem  tab[87] itd.
void tablica::funkcja_oposc(tablica *jakas_tablica, int x, int z, gracz* jakis_gracz)
{
	int i, zm_z;//zm_z - zmienna pokazuj�ca lini� w kt�rej umieszczony jest element z w tablicy.
	//wyszukiwanie linii w kt�rej znajduje si� z
	if (z > 108 && z < 119)  zm_z = 1;
	if (z > 120 && z < 131)  zm_z = 2;
	if (z > 132 && z < 143)  zm_z = 3;
	if (z > 144 && z < 155)  zm_z = 4;
	if (z > 156 && z < 167)  zm_z = 5;
	if (z > 168 && z < 179)  zm_z = 6;
	if (z > 180 && z < 191)  zm_z = 7;
	if (z > 192 && z < 203)  zm_z = 8;
	if (z > 204 && z < 215)  zm_z = 9;
	if (z > 216 && z < 227)  zm_z = 10;
	if (z > 228 && z < 239)  zm_z = 11;
	if (z > 240 && z < 251)  zm_z = 12;
	if (z > 252 && z < 263)  zm_z = 13;
	if (z > 264 && z < 275)  zm_z = 14;
	if (z > 276 && z < 287)  zm_z = 15;
	if (z > 288 && z < 299)  zm_z = 16;
	if (z > 300 && z < 311)  zm_z = 17;
	if (z > 312 && z < 323)  zm_z = 18;
	if (z > 324 && z < 335)  zm_z = 19;
	//od skrajnego prawego kra�ca linii do pozycji 107 nadpisywanie warto�ci w pozycji warto�ci� z pozycji i-12 (czyli poziom wy�ej)
	for (i = (zm_z + 9) * 12 - 1; i > 108; i--)
	// +9 , bo dziewi�� linii przed g�rn� granic�
	// 12-1 - bo skrajny prawy element tablicy w 1 linii ma id 11, w kolejnej linii o 12 wi�kszy
	{
		if (i == 119 || i == 336) // pomijanie opuszczania klocka z g�rnym ograniczeniem
			continue;
		else
			// nadpisuje zmienn� o lini� wy�sz�
			jakas_tablica->ustaw_element(i, jakas_tablica->pobierz_element(i - 12));
	}
	jakis_gracz->zmien_wynik(1);

}


		
