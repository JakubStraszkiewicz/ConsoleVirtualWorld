#include<iostream>
#include"Lis.h"
#include"conio2.h"
#define GORA 1
#define DOL 2
#define PRAWO 3
#define LEWO 4
using namespace std;
Lis::Lis(Swiat& swiat, int x, int y) : Zwierzeta(swiat, x, y)
{
	this->inicjatywa = 7;
	this->sila = 3;
}
void Lis::rysowanie()
{
	gotoxy(this->polozenie.x * 2, this->polozenie.y + 4);
	cout << "L";
}
void Lis::akcja() //randomowe pole
{
	int ruch, x = polozenie.x, y = polozenie.y;
	ruch = rand() % 4 + 1;
	switch (ruch)
	{
	case GORA:
		if (y - 1 >= 1)
			if (swiat.get_organizm()[y - 2][x - 1] == NULL)
				this->ruch(1, GORA);
			else
				if (typeid(*swiat.get_organizm()[y - 2][x - 1]).name() == typeid(*this).name())
					swiat.get_organizm()[y - 2][x - 1]->kolizja(*this, *swiat.get_organizm()[y - 2][x - 1]);
				else
					if (swiat.get_organizm()[y - 2][x - 1]->get_sila() <= this->sila)
					{
						swiat.get_organizm()[y - 2][x - 1]->kolizja(*this, *swiat.get_organizm()[y - 2][x - 1]);
						if (swiat.get_organizm()[y - 2][x - 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
							this->ruch(1, GORA);
					}
		break;
	case DOL:
		if (y + 1 <= 20)
			if (swiat.get_organizm()[y][x - 1] == NULL)
				this->ruch(1, DOL);
			else
				if (typeid(*swiat.get_organizm()[y][x - 1]).name() == typeid(*this).name())
					swiat.get_organizm()[y][x - 1]->kolizja(*this, *swiat.get_organizm()[y][x - 1]);
				else
					if (swiat.get_organizm()[y][x - 1]->get_sila() <= this->sila)
					{
						swiat.get_organizm()[y][x - 1]->kolizja(*this, *swiat.get_organizm()[y][x - 1]);
						if (swiat.get_organizm()[y][x - 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
							this->ruch(1, DOL);
					}
		break;
	case LEWO:
		if (x - 1 >= 1)
			if (swiat.get_organizm()[y - 1][x - 2] == NULL)
				this->ruch(1, LEWO);
			else
				if (typeid(*swiat.get_organizm()[y - 1][x - 2]).name() == typeid(*this).name())
					swiat.get_organizm()[y - 1][x - 2]->kolizja(*this, *swiat.get_organizm()[y - 1][x - 2]);
				else
					if (swiat.get_organizm()[y - 1][x - 2]->get_sila() <= this->sila)
					{
						swiat.get_organizm()[y - 1][x - 2]->kolizja(*this, *swiat.get_organizm()[y - 1][x - 2]);
						if (swiat.get_organizm()[y - 1][x - 2] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
							this->ruch(1, LEWO);
					}
		break;
	case PRAWO:
		if (x + 1 <= 20)
			if (swiat.get_organizm()[y - 1][x]== NULL)
				this->ruch(1, PRAWO);
			else
				if (typeid(*swiat.get_organizm()[y - 1][x]).name() == typeid(*this).name())
					swiat.get_organizm()[y - 1][x]->kolizja(*this, *swiat.get_organizm()[y - 1][x]);
				else
					if (swiat.get_organizm()[y - 1][x]->get_sila() <= this->sila)
					{
						swiat.get_organizm()[y - 1][x]->kolizja(*this, *swiat.get_organizm()[y - 1][x]);
						if (swiat.get_organizm()[y - 1][x] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
							this->ruch(1, PRAWO);
					}
		break;
	}
}