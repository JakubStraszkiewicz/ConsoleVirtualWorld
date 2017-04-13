#pragma once
#include<iostream>
#include"Rosliny.h"
#ifndef MLECZ_H
#define MLECZ_H
using namespace std;
class Mlecz : public Rosliny
{

public:
	Mlecz(Swiat& swiat, int x, int y);
	void rysowanie();
	void akcja();
};
#endif