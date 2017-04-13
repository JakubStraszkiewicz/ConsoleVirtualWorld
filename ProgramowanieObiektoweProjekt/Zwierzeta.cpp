#pragma once
#include<iostream>
#include"Zwierzeta.h"
#include"conio2.h"
#define GORA 1
#define DOL 2
#define PRAWO 3
#define LEWO 4
#define WYKONANORUCH 0
using namespace std;
Zwierzeta::Zwierzeta(Swiat& swiat, int x, int y) : Organizm(swiat, x, y)
{

}
void Zwierzeta::ruch(int ile,int kierunek)
{
	switch (kierunek)
	{
	case GORA:
		this->polozenie.y = this->polozenie.y - ile;
		swiat.set_organizm(polozenie.y - 1, polozenie.x - 1, swiat.get_organizm()[polozenie.y - 1 + ile][polozenie.x - 1]);
		swiat.set_organizm(polozenie.y-1+ile,polozenie.x-1,NULL);
		gotoxy(polozenie.x * 2, polozenie.y + ile + 4); cout << (char)254;
		gotoxy(polozenie.x * 2, polozenie.y + 4); this->rysowanie();
		break;
	case DOL:
		this->polozenie.y = this->polozenie.y + ile;
		swiat.set_organizm(polozenie.y - 1, polozenie.x - 1, swiat.get_organizm()[polozenie.y - 1 - ile][polozenie.x - 1]);
		swiat.set_organizm(polozenie.y - 1 - ile, polozenie.x - 1, NULL);
		gotoxy(polozenie.x * 2, polozenie.y - ile + 4); cout << (char)254;
		gotoxy(polozenie.x * 2, polozenie.y + 4); this->rysowanie();
		break;
	case LEWO:
		this->polozenie.x = this->polozenie.x - ile;
		swiat.set_organizm(polozenie.y - 1, polozenie.x - 1, swiat.get_organizm()[polozenie.y - 1][polozenie.x - 1 + ile]);
		swiat.set_organizm(polozenie.y - 1,polozenie.x - 1 + ile,NULL);
		gotoxy(polozenie.x * 2 + ile*2, polozenie.y + 4); cout << (char)254;
		gotoxy(polozenie.x * 2, polozenie.y + 4); this->rysowanie();
		break;
	case PRAWO:
		this->polozenie.x = this->polozenie.x + ile;
		swiat.set_organizm(polozenie.y - 1,polozenie.x - 1,swiat.get_organizm()[polozenie.y - 1][polozenie.x - 1 - ile]);
		swiat.set_organizm(polozenie.y - 1,polozenie.x - 1 - ile,NULL);
		gotoxy(polozenie.x * 2 - ile*2, polozenie.y + 4); cout << (char)254;
		gotoxy(polozenie.x * 2, polozenie.y + 4); this->rysowanie();
		break;
	}
}
void Zwierzeta::akcja()
{
	int ruch,x=polozenie.x,y=polozenie.y;
	ruch = rand() % 4 + 1;
	switch (ruch)
	{
	case GORA:
		if (y - 1 >= 1)
			if (swiat.get_organizm()[y - 2][x - 1] == NULL)
				this->ruch(1,GORA);
			else
				if (typeid(*swiat.get_organizm()[y - 2][x - 1]).name() == typeid(*this).name())
					swiat.get_organizm()[y - 2][x - 1]->kolizja(*this, *swiat.get_organizm()[y - 2][x - 1]);
				else
				{
					swiat.get_organizm()[y - 2][x - 1]->kolizja(*this, *swiat.get_organizm()[y - 2][x - 1]);
					if (swiat.get_organizm()[y - 2][x - 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
						this->ruch(1,GORA);
				}
		break;
	case DOL:
		if (y + 1 <= 20)
			if (swiat.get_organizm()[y][x - 1] == NULL)
			{
				this->ruch(1, DOL);
			}
			else
				if (typeid(*swiat.get_organizm()[y][x - 1]).name() == typeid(*this).name())
					swiat.get_organizm()[y][x - 1]->kolizja(*this,*swiat.get_organizm()[y][x - 1]);
				else
				{
					swiat.get_organizm()[y][x - 1]->kolizja(*this, *swiat.get_organizm()[y][x - 1]);
					if (swiat.get_organizm()[y][x - 1] == NULL && swiat.get_organizm()[y - 1][x - 1] != NULL)
						this->ruch(1, DOL);
				}
		break;
	case LEWO:
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
	case PRAWO:
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
}
void Zwierzeta::kolizja(Organizm& atakujacy,Organizm& atakowany)
{
	int x = atakujacy.get_polozenie_x(), y = atakujacy.get_polozenie_y();
	if (typeid(atakujacy).name() == typeid(atakowany).name())
	{
		for (int i = y - 1;i <= y+1;i++)
			for (int j = x - 1;j <= x+1;j++)
				if ( i <= 20 && i >= 1 && j <= 20 && j >= 1 && swiat.get_organizm()[i - 1][j - 1] == NULL)
				{
					swiat.dodaj_Organizm(typeid(atakujacy).name(), j, i);
					swiat.get_organizm()[i - 1][j - 1]->rysowanie();
					swiat.log_rozmnazanie(atakujacy);
					return;
				}
	}
	else
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
}
