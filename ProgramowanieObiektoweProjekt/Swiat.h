#pragma once
#include<iostream>

#ifndef SWIAT_H
#define SWIAT_H
using namespace std;
class Organizm;
class Swiat
{
protected:
	Organizm*** organizmy;
public:
	Swiat(); //konstruktoe
	~Swiat(); //destruktor
	void dane(); // wypisuje imie nazwisko nr albumu
	void sortowanie(Organizm* taborganizm[400], int ilosc); //sortuje tablice wzgledem wieku
	void rysujswiat(); // rysuje czysty swiat
	void wykonajture(); //gra
	void dodaj_Organizm(const char* nazwa,int x,int y); 
	void usun_Organizm(Organizm& organizm);
	void poczatkowe_Zwierzeta(); // dodaje zwierzeta na poczatek gry
	Organizm*** get_organizm(); // zwraca wskaznik tablicy z obiektami
	void set_organizm(int y, int x,Organizm* naco); // ustawia organizm
	void log_smierc(Organizm& zabity, Organizm& wygrany); //wypisuje log gdy zwierze ginie
	void log_rozmnazanie(Organizm& organizm); // wypisuje log gdy organizm sie rozmnozy
	void log_umiejetnosc(Organizm& organizm); // wypisuje log gdy organizm uzyje umiejetnosci
	void log_czytaj(int poczatkowy_wiersz); // wypisuje log na konsole
	static void wyczysc_konsole(); // czysci konsole
	void zapis(); 
	void wczytaj();
};
#endif