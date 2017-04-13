#pragma once
#include<iostream>
#include"Orgaznim.h"
#ifndef ROSLINY_H
#define ROSLINY_H
using namespace std;
class Rosliny : public Organizm
{
public:
	Rosliny(Swiat &swiat, int x, int y);
	void akcja();
	void kolizja(Organizm& atakujacy, Organizm& atakowany);
	virtual void rysowanie() = 0;
};
#endif