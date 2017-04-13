#pragma once
#include<iostream>
#include"Zwierzeta.h"
#ifndef OWCA_H
#define OWCA_H
using namespace std;
class Owca : public Zwierzeta
{
public:
	Owca(Swiat& swiat, int x, int y);
	void rysowanie();
};
#endif