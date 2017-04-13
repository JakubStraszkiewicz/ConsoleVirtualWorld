#include<iostream>
#include"WilczeJagody.h"
#include"conio2.h"
using namespace std;
WilczeJagody::WilczeJagody(Swiat& swiat, int x, int y) : Rosliny(swiat, x, y)
{
	this->inicjatywa = 0;
	this->sila = 99;
}
void WilczeJagody::rysowanie()
{
	textattr(BLUE);
	gotoxy(this->polozenie.x * 2, this->polozenie.y + 4);
	cout << "J";
	textattr(WHITE);
}
void WilczeJagody::kolizja(Organizm& atakujacy, Organizm& atakowany)
{
	swiat.usun_Organizm(atakujacy);
	swiat.usun_Organizm(atakowany);
	swiat.log_smierc(atakujacy, atakowany);
}
