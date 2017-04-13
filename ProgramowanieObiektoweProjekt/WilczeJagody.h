#pragma once
#include<iostream>
#include"Rosliny.h"
#ifndef WILCZEJAGODY_H
#define WILCZEJAGODY_H
using namespace std;
class WilczeJagody : public Rosliny
{

public:
	WilczeJagody(Swiat& swiat, int x, int y);
	void kolizja(Organizm& atakujacy, Organizm& atakowany);
	void rysowanie();
};
#endif