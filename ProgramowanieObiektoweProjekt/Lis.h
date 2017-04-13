#pragma once
#include<iostream>
#include"Zwierzeta.h"
#ifndef LIS_H
#define LIS_H
using namespace std;
class Lis : public Zwierzeta
{
public:
	Lis(Swiat& swiat, int x, int y);
	void rysowanie();
	void akcja();
};
#endif