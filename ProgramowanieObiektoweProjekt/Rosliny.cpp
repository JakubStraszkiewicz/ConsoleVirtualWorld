#pragma once
#include<iostream>
#include<ctime>
#include"Rosliny.h"
#include"conio2.h"
#define GORA 1
#define DOL 2
#define PRAWO 3
#define LEWO 4
#define PRAWDOPODOBIENSTWO 5 //im wieksze tym trudniej sie rozmnazac
using namespace std;
Rosliny::Rosliny(Swiat &swiat, int x, int y) : Organizm(swiat, x, y)
{ 

}
void Rosliny::akcja()
{
	int x = polozenie.x, y = polozenie.y,czy_rozmnozy_sie=0;
	czy_rozmnozy_sie = rand() % PRAWDOPODOBIENSTWO + 1;
	if (czy_rozmnozy_sie%PRAWDOPODOBIENSTWO == 0)
	{
		for (int i = y - 1;i <= y + 1;i++)
			for (int j = x - 1;j <= x + 1;j++)
				if (i <= 20 && i >= 1 && j <= 20 && j >= 1 && swiat.get_organizm()[i - 1][j - 1] == NULL)
				{
					swiat.dodaj_Organizm(typeid(*this).name(), j, i);
					swiat.get_organizm()[i - 1][j - 1]->rysowanie();
					swiat.log_rozmnazanie(*this);
					return;
				}
	}
}
void Rosliny::kolizja(Organizm& atakujacy, Organizm& atakowany)
{
	swiat.usun_Organizm(atakowany);
	swiat.log_smierc(atakowany, atakujacy);
}