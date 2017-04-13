#include<iostream>
#include"Antylopa.h"
#include"conio2.h"
#define GORA 1
#define DOL 2
#define PRAWO 3
#define LEWO 4
using namespace std;
Antylopa::Antylopa(Swiat& swiat, int x, int y) : Zwierzeta(swiat, x, y)
{
	this->inicjatywa = 4;
	this->sila = 4;
}
void Antylopa::rysowanie()
{
	gotoxy(this->polozenie.x * 2, this->polozenie.y + 4);
	cout << "A";
}
void Antylopa::akcja()
{
	int ruch, x = polozenie.x, y = polozenie.y;
	srand(time(NULL));
	ruch = rand() % 4 + 1;
	switch (ruch)
	{
	case GORA:
		if (y - 2 >= 1)
			if (swiat.get_organizm()[y - 3][x - 1] == NULL)
				this->ruch(2, GORA);
			else
				if (typeid(*swiat.get_organizm()[y - 3][x - 1]).name() == typeid(*this).name())
					swiat.get_organizm()[y - 3][x - 1]->kolizja(*this, *swiat.get_organizm()[y - 3][x - 1]);
				else
				{
					swiat.get_organizm()[y - 3][x - 1]->kolizja(*this, *swiat.get_organizm()[y - 3][x - 1]);
					if (swiat.get_organizm()[y - 3][x - 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
						this->ruch(2, GORA);
				}
		break;
	case DOL:
		if (y + 2 <= 20)
			if (swiat.get_organizm()[y + 1][x - 1] == NULL)
			{
				this->ruch(2, DOL);
			}
			else
				if (typeid(*swiat.get_organizm()[y + 1][x - 1]).name() == typeid(*this).name())
					swiat.get_organizm()[y + 1][x - 1]->kolizja(*this, *swiat.get_organizm()[y + 1][x - 1]);
				else
				{
					swiat.get_organizm()[y + 1][x - 1]->kolizja(*this, *swiat.get_organizm()[y + 1][x - 1]);
					if (swiat.get_organizm()[y + 1][x - 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
						this->ruch(2, DOL);
				}
		break;
	case LEWO:
		if (x - 2 >= 1)
			if (swiat.get_organizm()[y - 1][x - 3] == NULL)
			{
				this->ruch(2, LEWO);
			}
			else
				if (typeid(*swiat.get_organizm()[y - 1][x - 3]).name() == typeid(*this).name())
					swiat.get_organizm()[y - 1][x - 3]->kolizja(*this, *swiat.get_organizm()[y - 1][x - 3]);
				else
				{
					swiat.get_organizm()[y - 1][x - 3]->kolizja(*this, *swiat.get_organizm()[y - 1][x - 3]);
					if (swiat.get_organizm()[y - 1][x - 3] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
						this->ruch(2, LEWO);
				}
		break;
	case PRAWO:
		if (x + 2 <= 20)
			if (swiat.get_organizm()[y - 1][x + 1] == NULL)
				this->ruch(2, PRAWO);
			else
				if (typeid(*swiat.get_organizm()[y - 1][x + 1]).name() == typeid(*this).name())
					swiat.get_organizm()[y - 1][x + 1]->kolizja(*this, *swiat.get_organizm()[y - 1][x + 1]);
				else
				{
					swiat.get_organizm()[y - 1][x + 1]->kolizja(*this, *swiat.get_organizm()[y - 1][x + 1]);
					if (swiat.get_organizm()[y - 1][x + 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
						this->ruch(2, PRAWO);
				}
		break;
	}
}
void Antylopa::kolizja(Organizm& atakujacy, Organizm& atakowany)
{
	srand(time(NULL));
	int czy_uciekam = rand() % 2 + 1,x=atakujacy.get_polozenie_x(),y=atakujacy.get_polozenie_y();
	if (typeid(atakujacy).name() == typeid(atakowany).name())
	{
		for (int i = y - 1;i <= y + 1;i++)
			for (int j = x - 1;j <= x + 1;j++)
				if (i <= 20 && i >= 1 && j <= 20 && j >= 1 && swiat.get_organizm()[i - 1][j - 1] == NULL)
				{
					swiat.dodaj_Organizm(typeid(atakujacy).name(), j, i);
					swiat.get_organizm()[i - 1][j - 1]->rysowanie();
					swiat.log_rozmnazanie(atakujacy);
					return;
				}
	}
	else
	{
		if (czy_uciekam % 2 == 0)
		{
			if (atakujacy.get_sila() > atakowany.get_sila())
			{
				swiat.usun_Organizm(atakowany);
				swiat.log_smierc(atakowany, atakujacy);
			}
			else
				if (atakujacy.get_sila() < atakowany.get_sila())
				{
					swiat.usun_Organizm(atakujacy);
					swiat.log_smierc(atakujacy, atakowany);
				}
				else
					if (atakujacy.get_sila() == atakowany.get_sila())
					{
						swiat.usun_Organizm(atakowany);
						swiat.log_smierc(atakowany, atakujacy);
					}
		}
		else
			swiat.log_umiejetnosc(atakowany);
	}
}