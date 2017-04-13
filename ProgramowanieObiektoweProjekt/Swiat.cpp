#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include"conio2.h"
#include"Swiat.h"
#include"Antylopa.h"
#include"Lis.h"
#include"Owca.h"
#include"Wilk.h"
#include"Zolw.h"
#include"Czlowiek.h"
#include"Guarana.h"
#include"Mlecz.h"
#include"Trawa.h"
#include"WilczeJagody.h"
#include"Wyjatek.h"
#define PLANSZAPOZIOM 20 //we wszystkich zrobic planszapoziom planaszapion
#define PLANSZAPION 20
#define KONSOLAPOZIOM 50
#define KONSOLAPION 5
#define ANTYLOPA 1
#define LIS 2
#define OWCA 3
#define WILK 4
#define ZOLW 5
#define CZLOWIEK 6
using namespace std;
void Swiat::dane()
{
	cout << "+---------------------------------------+" << endl;
	cout << "| Jakub Straszkiewicz nr indeksu 160199 |" << endl;
	cout << "+---------------------------------------+" << endl;
}
void Swiat::rysujswiat()
{
	for (int i = 0;i < 22;i++)
	{
		for (int j = 0;j <20*2+1;j++)
		{
			if(i == 0 && j == 0 || i == 21 && j == 0 || i == 0 && j == 40 || i == 21 && j == 40)
				cout << "+";
			if (i > 0 && i < 21 && j>0 && j<40)
			{
				if(j%2==1)
					cout << (char)254;
				else
					cout << " ";
			}
			else
			{
				if ((i == 0|| i==21) && j > 0 && j < 40)
					cout << "-";
				if ((j == 0 || j == 40) && i > 0 && i < 21)
					cout << "|";
			}
		}
		cout << endl;
	}
}
void Swiat::sortowanie(Organizm* taborganizm[400], int ilosc)
{
	Organizm *pom;
	for (int i = 0;i < ilosc;i++)
	{
		for (int j = 1;j < ilosc;j++)
			if ((taborganizm[j - 1]->get_wiek()) < (taborganizm[j]->get_wiek()))
			{
				pom = taborganizm[j - 1];
				taborganizm[j - 1] = taborganizm[j];
				taborganizm[j] = pom;
			}
	}
}
void Swiat::wykonajture()
{
	ofstream wyjscie("log.txt");
	wyjscie << " " << endl;
	wyjscie.close();
	srand(time(NULL));
	Organizm *taborganizm[400];
	for (int i = 0;i < 400;i++)
		taborganizm[i] = NULL;
	int k = 0, inicjatywa = 7;
	while (inicjatywa >= 0)
	{
		for (int i = 0;i < 20;i++) // wektory
		{
			for (int j = 0;j < 20;j++)
				if (organizmy[i][j] != NULL && organizmy[i][j]->get_inicjatywa() == inicjatywa)
				{
					taborganizm[k] = organizmy[i][j];
					k++;
				}
		}
		sortowanie(taborganizm, k);
		inicjatywa--;
		int pom = 0;
		while (pom <= k - 1)
		{
			if (taborganizm[pom] != NULL)
			{
				taborganizm[pom]->zwiekszWiek();
				taborganizm[pom]->rysowanie();
				taborganizm[pom]->akcja();
			}
			pom++;
		}
		k = 0;
	}
}
void Swiat::poczatkowe_Zwierzeta()
{
	int x, y,licznikzwierzat=0;
	char zwierzeta[9][19] = { "class Antylopa","class Lis","class Owca","class Wilk","class Zolw","class WilczeJagody","class Guarana","class Mlecz","class Trawa" };
	srand(time(NULL));
	while (licznikzwierzat != 36)
	{
		x = rand() % PLANSZAPOZIOM + 1;
		y = rand() % PLANSZAPION + 1;
		if (organizmy[y - 1][x - 1] == NULL)
		{
			dodaj_Organizm(zwierzeta[licznikzwierzat/4], x, y);
			organizmy[y - 1][x - 1]->rysowanie();
			licznikzwierzat++;
		}
	}
	while (organizmy[y - 1][x - 1] != NULL)
	{
		x = rand() % PLANSZAPOZIOM + 1;
		y = rand() % PLANSZAPION + 1;
		dodaj_Organizm("class Czlowiek", x, y);
		organizmy[y - 1][x - 1]->rysowanie();
		break;
	}
	
}
Swiat::Swiat()
{
	this->organizmy = new Organizm**[PLANSZAPION];
	for (int i = 0;i < PLANSZAPION;i++)
		organizmy[i] = new Organizm*[PLANSZAPOZIOM];

	for (int i = 0;i < PLANSZAPION;i++)
		for (int j = 0;j < PLANSZAPOZIOM;j++)
			organizmy[i][j] = NULL;
}
Swiat::~Swiat()
{
	delete[] this->organizmy;
}
void Swiat::dodaj_Organizm(const char* nazwa,int x,int y)
{
		if(strcmp("class Antylopa",nazwa)==0)
			organizmy[y - 1][x - 1] = new Antylopa(*this, x, y);
		if (strcmp("class Lis",nazwa)==0)
			organizmy[y - 1][x - 1] = new Lis(*this, x, y);
		if (strcmp("class Owca",nazwa)==0)
			organizmy[y - 1][x - 1] = new Owca(*this, x, y);
		if (strcmp("class Wilk",nazwa)==0)
			organizmy[y - 1][x - 1] = new Wilk(*this, x, y);
		if (strcmp("class Zolw",nazwa)==0)
			organizmy[y - 1][x - 1] = new Zolw(*this, x, y);
		if (strcmp("class Czlowiek",nazwa)==0)
			organizmy[y - 1][x - 1] = new Czlowiek(*this, x, y);
		if (strcmp("class WilczeJagody",nazwa)==0)
			organizmy[y - 1][x - 1] = new WilczeJagody(*this, x, y);
		if (strcmp("class Guarana",nazwa)==0)
			organizmy[y - 1][x - 1] = new Guarana(*this, x, y);
		if (strcmp("class Mlecz",nazwa)==0)
			organizmy[y - 1][x - 1] = new Mlecz(*this, x, y);
		if (strcmp("class Trawa",nazwa)==0)
			organizmy[y - 1][x - 1] = new Trawa(*this, x, y);
}

void Swiat::usun_Organizm(Organizm& organizm)
{
	int x = organizm.get_polozenie_x(), y = organizm.get_polozenie_y();
	gotoxy(x * 2, y + 4);
	cout << (char)254;
	organizmy[y - 1][x - 1] = NULL;
	delete organizmy[y - 1][x - 1];
}
Organizm*** Swiat::get_organizm()
{
	return organizmy;
}
void Swiat::set_organizm(int y, int x,Organizm* naco)
{
	organizmy[y][x] = naco;
}


void Swiat::log_smierc(Organizm& zabity, Organizm& wygrany)
{
	string wyg = typeid(wygrany).name(), zab = typeid(zabity).name();
	ofstream wyjscie("log.txt", ios::app);
	if (wyg.erase(0,6) == "WilczeJagody")
		wyjscie << zab.erase(0, 6) << " zjada " << wyg.erase(0, 6) << " i ginie" << endl;
	else
		wyjscie << wyg << " zjada " << zab.erase(0,6) << endl;
	wyjscie.close();
}
void Swiat::log_rozmnazanie(Organizm& organizm)
{
	string org = typeid(organizm).name();
	ofstream wyjscie("log.txt", ios::app);
	wyjscie <<"Organizm "<< org.erase(0,6) << " rozmnozyl sie "<< endl;
	wyjscie.close();
}
void Swiat::log_umiejetnosc(Organizm& organizm)
{
	string org = typeid(organizm).name();
	ofstream wyjscie("log.txt", ios::app);
	if(org.erase(0, 6) == "Czlowiek")
		wyjscie <<org << " uzyl umiejetnosci calopalenie " << endl;
	if (org == "Zolw")
		wyjscie << org << " odparl atak" << endl;
	if (org == "Antylopa")
		wyjscie << org << " ucieka przed walka" << endl;
	wyjscie.close();
}
void Swiat::log_czytaj(int pierwszy_wiersz)
{
	string wiersz;
	int numer_wiersza = 0;
	ifstream wejscie("log.txt");
	while (!wejscie.eof())
	{
		getline(wejscie, wiersz);
		if (numer_wiersza >= pierwszy_wiersz+1 && numer_wiersza < pierwszy_wiersz + 4 && wiersz!="")
		{
			gotoxy(KONSOLAPOZIOM, KONSOLAPION);
			cout << numer_wiersza << ". " << wiersz << endl;
			getline(wejscie, wiersz);
			if (wiersz != "")
			{
				numer_wiersza++;
				gotoxy(KONSOLAPOZIOM, KONSOLAPION+1);
				cout << numer_wiersza << ". " << wiersz << endl;
				getline(wejscie, wiersz);
			}
			if (wiersz != "")
			{
				numer_wiersza++;
				gotoxy(KONSOLAPOZIOM, KONSOLAPION+2);
				cout << numer_wiersza << ". " << wiersz << endl;
			}
		}
		numer_wiersza++;
	}
	wejscie.close();
}
void Swiat::wyczysc_konsole()
{
	for (int i = KONSOLAPION;i < 8;i++)
		for (int j = KONSOLAPOZIOM;j < 95;j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
}
void Swiat::zapis()
{
	string nazwa;
		ofstream wyjscie("zapis.txt");
		
		for (int i = 0;i < PLANSZAPION;i++)
		{
			for (int j = 0;j < PLANSZAPOZIOM;j++)
			{
				if (organizmy[i][j] != NULL)
				{
					nazwa = typeid(*organizmy[i][j]).name();
					nazwa = nazwa.erase(0, 6);
					if (nazwa == "Antylopa")
						wyjscie << "A ";
					if (nazwa == "Czlowiek")
						wyjscie << "C ";
					if (nazwa == "Guarana")
						wyjscie << "G ";
					if (nazwa == "Lis")
						wyjscie << "L ";
					if (nazwa == "Mlecz")
						wyjscie << "M ";
					if (nazwa == "Owca")
						wyjscie << "O ";
					if (nazwa == "Trawa")
						wyjscie << "T ";
					if (nazwa == "WilczeJagody")
						wyjscie << "J ";
					if (nazwa == "Wilk")
						wyjscie << "W ";
					if (nazwa == "Zolw")
						wyjscie << "Z ";
					wyjscie << organizmy[i][j]->get_polozenie_y() << " ";
					wyjscie << organizmy[i][j]->get_polozenie_x() << " ";
					wyjscie << organizmy[i][j]->get_sila() << " ";
					wyjscie << organizmy[i][j]->get_wiek() << " ";
					wyjscie << endl;
				}
				else
					wyjscie << "X " << endl;
			}
		}
		wyjscie.close();
}
void Swiat::wczytaj()
{
	system("CLS");
	for (int i = 0;i < PLANSZAPION;i++)
		for (int j = 0;j < PLANSZAPOZIOM;j++)
			organizmy[i][j] = NULL;
	try {

		ifstream wejscie("zapis.txt");
		if (!wejscie.good())
			throw Wyjatek("Plik nie zostal otwarty");
		string nazwa;
		int x, y, sila,wiek;
		while (!wejscie.eof())
		{
			wejscie >> nazwa;
			if (nazwa != "X")
			{
				wejscie >> y;
				wejscie >> x;
				wejscie >> sila;
				wejscie >> wiek;
				if (nazwa == "A")
					dodaj_Organizm("class Antylopa", x, y);
				if (nazwa == "C")
					dodaj_Organizm("class Czlowiek", x, y);
				if (nazwa == "G")
					dodaj_Organizm("class Guarana", x, y);
				if (nazwa == "L")
					dodaj_Organizm("class Lis", x, y);
				if (nazwa == "M")
					dodaj_Organizm("class Mlecz", x, y);
				if (nazwa == "O")
					dodaj_Organizm("class Owca", x, y);
				if (nazwa == "T")
					dodaj_Organizm("class Trawa", x, y);
				if (nazwa == "J")
					dodaj_Organizm("class WilczeJagody", x, y);
				if (nazwa == "W")
					dodaj_Organizm("class Wilk", x, y);
				if (nazwa == "Z")
					dodaj_Organizm("class Zolw", x, y);
				organizmy[y - 1][x - 1]->set_sila(sila);
				organizmy[y - 1][x - 1]->set_wiek(wiek);

			}
		}
		wejscie.close();
		dane();
		rysujswiat();
		for (int i = 0;i < PLANSZAPION;i++)
			for (int j = 0;j < PLANSZAPOZIOM;j++)
				if (organizmy[i][j] != NULL)
					organizmy[i][j]->rysowanie();
	}
	catch (Wyjatek &w) {
		cout << w.get_tekst();
	}
}