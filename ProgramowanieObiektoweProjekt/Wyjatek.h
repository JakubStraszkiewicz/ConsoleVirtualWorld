#pragma once
#include<iostream>
#include<string>
using namespace std;
class Wyjatek
{
private:
	string tekst;
public:
	string get_tekst();
	Wyjatek(string polecenie);
};