#include<iostream>
#include"Czlowiek.h"
#include"conio2.h"
#define GORA_STRZALKA 72
#define DOL_STRZALKA 80
#define PRAWO_STRZALKA 77
#define LEWO_STRZALKA 75
#define UMIEJETNOSC 'q'
#define GORA 1
#define DOL 2
#define PRAWO 3
#define LEWO 4
using namespace std;
Czlowiek::Czlowiek(Swiat& swiat, int x, int y) : Zwierzeta(swiat, x, y)
{
	this->inicjatywa = 4;
	this->sila = 5;
	this->umiejetnosc = 0;
	this->czas_trwania = 0;
}
void Czlowiek::rysowanie()
{
	gotoxy(this->polozenie.x * 2, this->polozenie.y + 4);
	cout << "C";
}
void Czlowiek::calopalenie()
{
	
	if (umiejetnosc > 0)
	{
		for (int i = polozenie.y - 1;i <= polozenie.y + 1;i++)
			for (int j = polozenie.x - 1;j <= polozenie.x + 1;j++)
				if (i <= 20 && i >= 1 && j <= 20 && j >= 1 && swiat.get_organizm()[i - 1][j - 1] != NULL && swiat.get_organizm()[i - 1][j - 1] != swiat.get_organizm()[polozenie.y - 1][polozenie.x - 1])
				{
					swiat.usun_Organizm(*swiat.get_organizm()[i - 1][j - 1]);
				}
		umiejetnosc--;
		swiat.log_umiejetnosc(*this);
	}
	czas_trwania--;
}
void Czlowiek::akcja()
{
	int x = polozenie.x,y=polozenie.y,klawisz;
	calopalenie();
	if (getch() == 0)
		switch (getch())
		{
		case GORA_STRZALKA:
			if (y - 1 >= 1)
				if (swiat.get_organizm()[y - 2][x - 1] == NULL)
					this->ruch(1, GORA);
				else
					if (typeid(*swiat.get_organizm()[y - 2][x - 1]).name() == typeid(*this).name())
						swiat.get_organizm()[y - 2][x - 1]->kolizja(*this, *swiat.get_organizm()[y - 2][x - 1]);
					else
					{
						swiat.get_organizm()[y - 2][x - 1]->kolizja(*this, *swiat.get_organizm()[y - 2][x - 1]);
						if (swiat.get_organizm()[y - 2][x - 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
							this->ruch(1, GORA);
					}
			break;
		case DOL_STRZALKA:
			if (y + 1 <= 20)
				if (swiat.get_organizm()[y][x - 1] == NULL)
				{
					this->ruch(1, DOL);
				}
				else
					if (typeid(*swiat.get_organizm()[y][x - 1]).name() == typeid(*this).name())
						swiat.get_organizm()[y][x - 1]->kolizja(*this, *swiat.get_organizm()[y][x - 1]);
					else
					{
						swiat.get_organizm()[y][x - 1]->kolizja(*this, *swiat.get_organizm()[y][x - 1]);
						if (swiat.get_organizm()[y][x - 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
							this->ruch(1, DOL);
					}
			break;
		case LEWO_STRZALKA:
			if (x - 1 >= 1)
				if (swiat.get_organizm()[y - 1][x - 2] == NULL)
				{
					this->ruch(1, LEWO);
				}
				else
					if (typeid(*swiat.get_organizm()[y - 1][x - 2]).name() == typeid(*this).name())
						swiat.get_organizm()[y - 1][x - 2]->kolizja(*this, *swiat.get_organizm()[y - 1][x - 2]);
					else
					{
						swiat.get_organizm()[y - 1][x - 2]->kolizja(*this, *swiat.get_organizm()[y - 1][x - 2]);
						if (swiat.get_organizm()[y - 1][x - 2] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
							this->ruch(1, LEWO);
					}
			break;
		case PRAWO_STRZALKA:
			if (x + 1 <= 20)
				if (swiat.get_organizm()[y - 1][x] == NULL)
					this->ruch(1, PRAWO);
				else
					if (typeid(*swiat.get_organizm()[y - 1][x]).name() == typeid(*this).name())
						swiat.get_organizm()[y - 1][x]->kolizja(*this, *swiat.get_organizm()[y - 1][x]);
					else
					{
						swiat.get_organizm()[y - 1][x]->kolizja(*this, *swiat.get_organizm()[y - 1][x]);
						if (swiat.get_organizm()[y - 1][x] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
							this->ruch(1, PRAWO);
					}
			break;
		}
	else
	{
		if (czas_trwania <= 0 )
		{
			umiejetnosc = 5;
			czas_trwania = 10;
			calopalenie();
		}
	}
}
int Czlowiek::get_umiejetnosc()
{
	return this->umiejetnosc;
}
int Czlowiek::get_czas_trwania()
{
	return this->czas_trwania;
}
void Czlowiek::set_umiejetnosc(int umiejetnosc)
{
	this->umiejetnosc = umiejetnosc;
}
void Czlowiek::set_czas_trwania(int czas_trwania)
{
	this->czas_trwania = czas_trwania;
}