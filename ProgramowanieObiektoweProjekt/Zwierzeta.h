#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Orgaznim.h"
#ifndef ZWIERZETA_H
#define ZWIERZETA_H
using namespace std;
class Zwierzeta : public Organizm
{

public:
	Zwierzeta(Swiat &swiat, int x, int y);
	void akcja();
	void kolizja(Organizm& organizm1, Organizm& organizm2);
	void ruch(int ile,int kierunek);
	virtual void rysowanie()=0;
};
#endif
