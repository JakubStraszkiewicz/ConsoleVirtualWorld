#include<iostream>
#include<ctime>
#include"Mlecz.h"
#include"conio2.h"
#define PRAWDOPODOBIENSTWO 3
using namespace std;
Mlecz::Mlecz(Swiat& swiat, int x, int y) : Rosliny(swiat, x, y)
{
	this->inicjatywa = 0;
	this->sila = 0;
}
void Mlecz::rysowanie()
{
	textattr(YELLOW);
	gotoxy(this->polozenie.x * 2, this->polozenie.y + 4);
	cout << "M";
	textattr(WHITE);
}
void Mlecz::akcja()
{
	for (int i = 0;i < 3;i++)
	{
		Rosliny::akcja();
	}
}
