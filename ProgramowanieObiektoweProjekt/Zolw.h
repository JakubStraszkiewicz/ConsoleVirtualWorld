#pragma once
#include<iostream>
#include"Zwierzeta.h"
#ifndef ZOLW_H
#define ZOLW_H
using namespace std;
class Zolw : public Zwierzeta
{
public:
	Zolw(Swiat& swiat, int x, int y);
	void rysowanie();
	void akcja();
	void kolizja(Organizm& atakujacy, Organizm& atakowany);
};
#endif