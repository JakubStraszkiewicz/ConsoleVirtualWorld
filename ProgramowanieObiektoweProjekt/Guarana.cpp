#include<iostream>
#include"Guarana.h"
#include"conio2.h"
using namespace std;
Guarana::Guarana(Swiat& swiat, int x, int y) : Rosliny(swiat, x, y)
{
	this->inicjatywa = 0;
	this->sila = 0;
}
void Guarana::rysowanie()
{
	textattr(RED);
	gotoxy(this->polozenie.x * 2, this->polozenie.y + 4);
	cout << "G";
	textattr(WHITE);
}
void Guarana::kolizja(Organizm& atakujacy, Organizm& atakowany)
{
	atakujacy.set_sila(atakujacy.get_sila()+3);
	swiat.usun_Organizm(atakowany);
	swiat.log_smierc(atakowany, atakujacy);
}
