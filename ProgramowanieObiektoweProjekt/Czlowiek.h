#pragma once
#include<iostream>
#include"Zwierzeta.h"
#ifndef CZLOWIEK_H
#define CZLOWIEK_H
using namespace std;
class Czlowiek : public Zwierzeta
{
private:
	int umiejetnosc;
	int czas_trwania;
public:
	Czlowiek(Swiat& swiat, int x, int y);
	void rysowanie();
	void akcja();
	void calopalenie(); // specjalna umiejetnosc czlowieka
	int get_umiejetnosc();
	int get_czas_trwania();
	void set_umiejetnosc(int umiejetnosc);
	void set_czas_trwania(int czas_trwania);
};
#endif