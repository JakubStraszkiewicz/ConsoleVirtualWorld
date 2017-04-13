#include"Main.h"
using namespace std;

int main()
{
	Swiat swiat;
	swiat.dane();
	swiat.rysujswiat();
	swiat.poczatkowe_Zwierzeta();
/*	Wilk *wilk1 = new Wilk(swiat,0,0); konstruktor kopiujacy
	wilk1->set_wiek(100);
	Wilk *wilk2 = new Wilk(*wilk1,swiat,1,1);*/

	/*Wilk *wilk1 = new Wilk(swiat, 0, 0); przypisanie
	wilk1->set_wiek(100);
	Wilk* wilk2 = new Wilk(swiat, 1, 1);
	wilk2 = wilk1;*/

	int polecenie, wiersz = 0;
	while ((polecenie=getch())!='c')
	{
		if (polecenie == RUCH)
		{
			swiat.wyczysc_konsole();
			swiat.wykonajture();
			wiersz = 0;
			swiat.log_czytaj(wiersz);
		}
		if (polecenie == PRZEWIN)
		{
			swiat.wyczysc_konsole();
			wiersz++;
			swiat.log_czytaj(wiersz);
		}
		if(polecenie== WROC)
		{
			swiat.wyczysc_konsole();
			wiersz--;
			swiat.log_czytaj(wiersz);
		}
		if (polecenie == ZAPIS)
			swiat.zapis();
		if (polecenie == WCZYTAJ)
			swiat.wczytaj();
	}
}