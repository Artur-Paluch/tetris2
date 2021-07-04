#pragma once
#include "tablica.h"
#include "gracz.h"
//deklaracje  klas, �eby mo�na ich by�o uzywa� w przyja�niach
class tablica;
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

class klocek
:public tablica
{
private:
	int y; //pionowa zmienna po�o�enia klocka(co obni�enie zwi�ksza si� o 12, czyli d�ugo�� tablicy w poziomie)
		   // s� liczone od zera, czyli po lewej kraw�dzi tablicy
		   //y jest na poziomie najni�szej cz�ci klocka
	int x; //pozioma zmienna po�o�enia klocka(zmienia si� o -1/+1 w zalezno�ci od naci�ni�cia strza�ki lewo/prawo)
	int zm; // zmienna okre�la id klocka na kt�ry klocek ma si� zamieni� po naci�ni�ciu strza�ki w g�r�
	int id; // numer identyfikacyjny klocka
	//zmienne okre�laj�ce uk�ad klocka w tablicy 
	//z0 najwy�ej i najbardziej w lweo, z1 kolejny w prawo, lub je�li nie ma to pierwszy 1 poziom ni�ej najbardziej po lewej
	//kolejne analogicznie. Je�li klocek ma mniej p�l ni� jest zmiennych, to brakuj�ce maj� t� sam� warto�� co ostatnia istniej�ca
	int z0;
	int z1;
	int z2;
	int z3;
	int z4;
	//zmienne dolnych p�l klocka. 
	//n0 - pierwsza zmienna z* od lewej, kt�ra nie ma pod sob� innej cz�ci klocka. 
	//n1 - kolejna w prawo zmienna z* kt�ra nie ma pod sob� innej cz�ci klocka
	//Je�li klocek ma mniej p�l ni� jest zmiennych, to brakuj�ce maj� t� sam� warto�� co ostatnia istniej�ca
	int n0;
	int n1;
	int n2;
	int n3;
	int n4;
	//zmienne okre�laj�ce skrajnie lewe cz�ci klocka.
	//l0- z* skrajne z lewej i najwy�ej
	//l4- z* skrajne z lewej i najni�ej
	int l0;
	int l1;
	int l2;
	int l3;
	int l4;
	//zmienne okre�laj�ce skrajnie prawe cz�ci klocka.
	//r0- z* skrajne z prawe i najwy�ej
	//r4- z* skrajne z prawe i najni�ej
	int r0;
	int r1;
	int r2;
	int r3;
	int r4;
	//zmienna okresla kolor klocka
	char kolor;
	//przyja�nie klasy klocek
	friend class	S_poziomo;
	friend class	S_pionowo;
	friend class	palka_poziomo;
	friend class	palka_pionowo;
	friend class	kwadrat;
	friend class	piramida_up;
	friend class	piramida_down;
	friend class	piramida_right;
	friend class	piramida_left;
	friend class	L_left;
	friend class	L_right;
	friend class	L_down;
	friend class	L_up;
	friend class	Odwr_L_up;
	friend class	Odwr_L_left;
	friend class	Odwr_L_right;
	friend class	Odwr_L_down;
	friend class	Z_poziomo;
	friend class	Z_pionowo;
public:
	klocek();
	klocek(const klocek&kopia); //konstruktor kopiuj�cy deklaracja
	~klocek(); //destruktor deklaracja
	void ustaw_z(int, int, int, int, int);//metoda ustawia zmienn� z klocka. W argumentach przyjmuje warto�ci kolejnych z0-z4
	int pobierz_z(int);//metoda zwraca warto�� zx ( x podany w argumencie)
	void ustaw_n(int, int, int, int, int);//metoda ustawia zmienn� n klocka. W argumentach przyjmuje warto�ci kolejnych n0-n4
	int pobierz_n(int);//metoda zwraca warto�� nx ( x podany w argumencie)
	void ustaw_l(int, int, int, int, int);//metoda ustawia zmienn� l klocka. W argumentach przyjmuje warto�ci kolejnych l0-l4
	int pobierz_l(int);//metoda zwraca warto�� lx ( x podany w argumencie)
	void ustaw_r(int, int, int, int, int);//metoda ustawia zmienn� r klocka. W argumentach przyjmuje warto�ci kolejnych r0-r4
	int pobierz_r(int);//metoda zwraca warto�� rx ( x podany w argumencie)
	void ustaw_x(int);//metoda ustawia zmienn� x klocka o podanej w argumencie warto�ci
	int pobierz_x();//metoda zwraca warto�� zmiennej x
	void ustaw_y(int);//metoda ustawia zmienn� z klocka o podanej w argumencie warto�ci
	int pobierz_y();//metoda zwraca warto�� zmiennej y
	int pobierz_kolor();//metoda zwraca warto�� zmiennej kolor
	int pobierz_zm();//metoda zwraca warto�� zmiennej zm
	void przesun_L(tablica *tab, klocek* jakis_klocek); //  je�li jest wolne miejsce, metoda aktualizuje zmienne klocka zmniejszaj�c je o 1. Aktualizuje tablic� o zmienione zmienne klocka
	void przesun_P(tablica *tab, klocek* jakis_klocek);//  je�li jest wolne miejsce, metoda aktualizuje zmienne klocka zwiekszajac je o 1. Aktualizuje tablic� o zmienione zmienne klocka
	klocek funkcja_obrotu(tablica *jakas_tablica, klocek *klocek_obecny, klocek* tablica_klocek[]); //metoda obraca klockiem i aktualizuje tablic�
	int obnizaj(tablica *tab, klocek* jakis_klocek, klocek* tab_klocek[], gracz* zalogowany, int tablica_wylosowanych[], int u); // metoda obni�aj�ca pozycj� klocka w tablicy. U�ywana tylko przy obni�aniu co 250 ms
	int obnizaj_do_konca(tablica *jakas_tablica, klocek* jakis_klocek, klocek* tab_klocek[], gracz* zalogowany, int tablica_wylosowanych[]);//metoda obni�a klocek najni�ej jak si� da
};