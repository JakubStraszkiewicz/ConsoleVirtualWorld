#include<iostream>
#include"Orgaznim.h"
Organizm::Organizm(Swiat& swiatek, int x, int y) : swiat(swiatek)
{
		this->polozenie.x = x;
		this->polozenie.y = y;
		this->wiek = 0;
}
Organizm::~Organizm(){}
void Organizm::zwiekszWiek()
{
	this->wiek++;
}
int Organizm::get_polozenie_x()
{
	return polozenie.x;
}
int Organizm::get_polozenie_y()
{
	return polozenie.y;
}
void Organizm::set_polozenie_x(int x)
{
	this->polozenie.x = x;
}
void Organizm::set_polozenie_y(int y)
{
	this->polozenie.y = y;
}
int Organizm::get_inicjatywa()
{
	return inicjatywa;
}
int Organizm::get_sila()
{
	return sila;
}
void Organizm::set_sila(int sila)
{
	this->sila = sila;
}
int Organizm::get_wiek()
{
	return wiek;
}
void Organizm::set_wiek(int wiek)
{
	this->wiek = wiek;
}