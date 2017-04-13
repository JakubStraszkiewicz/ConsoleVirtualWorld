#pragma once
#include<iostream>
#include"Zwierzeta.h"
#ifndef ANTYLOPA_H
#define ANTYLOPA_H
using namespace std;
class Antylopa : public Zwierzeta
{
public:
	Antylopa(Swiat& swiat, int x, int y);
	void rysowanie();
	void akcja();
	void kolizja(Organizm& atakujacy, Organizm& atakowany);
};
#endif