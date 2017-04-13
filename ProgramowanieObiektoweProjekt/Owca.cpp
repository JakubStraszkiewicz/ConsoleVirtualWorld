#include<iostream>
#include"Owca.h"
#include"conio2.h"
using namespace std;
Owca::Owca(Swiat& swiat, int x, int y) : Zwierzeta(swiat, x, y)
{
	this->inicjatywa = 4;
	this->sila = 4;
}
void Owca::rysowanie()
{
	gotoxy(this->polozenie.x * 2, this->polozenie.y + 4);
	cout << "O";
}