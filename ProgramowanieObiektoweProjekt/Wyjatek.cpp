#include<iostream>
#include"Wyjatek.h"
using namespace std;
string Wyjatek::get_tekst()
{
	return tekst;
}
Wyjatek::Wyjatek(string polecenie)
{
	tekst = polecenie;
}