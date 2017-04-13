#pragma once
#include<iostream>
#include"Rosliny.h"
#ifndef GUARANA_H
#define GUARANA_H
using namespace std;
class Guarana : public Rosliny
{

public:
	Guarana(Swiat& swiat, int x, int y);
	void kolizja(Organizm& atakujacy, Organizm& atakowany);
	void rysowanie();
};
#endif