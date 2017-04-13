#pragma once
#include<iostream>
#include"Zwierzeta.h"
#ifndef WILK_H
#define WILK_H
using namespace std;
class Wilk: public Zwierzeta
{
	
public:
	Wilk(Swiat& swiat,int x,int y);
	void rysowanie();
	//Wilk(const Wilk& oryginal,Swiat& swiat,int x,int y);
	//Wilk& operator=(const Wilk& right);
};
#endif