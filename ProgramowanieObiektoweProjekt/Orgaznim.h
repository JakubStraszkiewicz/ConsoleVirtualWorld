#pragma once
#include<iostream>
#include"Swiat.h"
#ifndef ORGANIZM_H
#define ORGANIZM_H
using namespace std;
class Organizm
{

protected:
	int wiek;
	int sila;
	int inicjatywa;
	struct polozenie
	{
		int x;
		int y;
	}polozenie;
	Swiat &swiat;
public:
	Organizm(Swiat& swiatek, int x, int y);
	~Organizm();
	virtual void akcja() = 0;
	virtual void kolizja(Organizm& organizm1, Organizm& organizm2) = 0;
	virtual void rysowanie() = 0;
	void zwiekszWiek();
	int get_polozenie_x();
	int get_polozenie_y();
	void set_polozenie_x(int x);
	void set_polozenie_y(int y);
	int get_inicjatywa();
	int get_sila();
	void set_sila(int sila);
	int get_wiek();
	void set_wiek(int wiek);
};
#endif