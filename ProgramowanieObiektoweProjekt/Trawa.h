#pragma once
#include<iostream>
#include"Rosliny.h"
#ifndef TRAWA_H
#define Trawa_H
using namespace std;
class Trawa : public Rosliny
{

public:
	Trawa(Swiat& swiat, int x, int y);
	void rysowanie();
};
#endif