#include<iostream>
#include"Wilk.h"
#include"conio2.h"
using namespace std;
Wilk::Wilk(Swiat& swiat,int x,int y) : Zwierzeta(swiat,x,y)
{
	this->inicjatywa = 5;
	this->sila = 9;
}
void Wilk::rysowanie()
{
	gotoxy(this->polozenie.x*2, this->polozenie.y+4);
	cout << "W";
}
/*Wilk::Wilk(const Wilk& oryginal,Swiat& swiat,int x,int y) : Zwierzeta(swiat,x,y)
{
	wiek = oryginal.wiek;
	sila = oryginal.sila;
	inicjatywa = oryginal.inicjatywa;
	polozenie.x = oryginal.polozenie.x;
	polozenie.y = oryginal.polozenie.y;
	swiat = oryginal.swiat;
}*/
/*Wilk& Wilk::operator=(const Wilk& right)
{
	wiek = right.wiek;
	sila = right.sila;
	inicjatywa = right.inicjatywa;
	polozenie.x = right.polozenie.x;
	polozenie.y = right.polozenie.y;
	swiat = right.swiat;
	return *this;
}*/