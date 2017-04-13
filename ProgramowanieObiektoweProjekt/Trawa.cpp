#include<iostream>
#include"Trawa.h"
#include"conio2.h"
using namespace std;
Trawa::Trawa(Swiat& swiat, int x, int y) : Rosliny(swiat, x, y)
{
	this->inicjatywa = 0;
	this->sila = 0;
}
void Trawa::rysowanie()
{
	textattr(GREEN);
	gotoxy(this->polozenie.x * 2, this->polozenie.y + 4);
	cout << "T";
	textattr(WHITE);
}
