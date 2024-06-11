#include "ConvBin.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
	//https://www.geeksforgeeks.org/implement-itoa/
}

void convdecbin(void)
{
	char ite = 0;
	char itera = 0;
	int ValDec = 0;
	float ValDec_initial = 0;
	float Quotient = 0;
	char Reste = 0;
	bool neg = false;
	int i = 0;
	int formatAffichage = 0;
	char resultat[33] = { 0 };
	float fraction;
	//Demander une valeur comprise entre 0 et 255
	printf("Entrez une valeur decimale comprise entre 0 et 255 : ");
	scanf("%f", &ValDec_initial);

	printf("choix format affichage ''/'8'/'16'/'32' : ");
	scanf("%d", &formatAffichage);
	ValDec = (int)ValDec_initial; // partie entière

	fraction = ValDec_initial - ValDec; // partie fractionnaire


	neg = ((unsigned char)ValDec_initial > 0x7F) ? true : false;


	ite = (log2(abs(ValDec_initial)) + 1);
	if (neg)
	{
		if (fraction)
		{
			for (i = 31; i >= 29; i--)
			{
				Reste = fraction * 2;
				resultat[i] = (Reste) ? '1' : '0';
				Reste -= 1;
			}
			resultat[i--] = '.';
			i--;
		}
		else
		{
			i = 31;
		}

		for (int j = i; j >= (i - ite); j--)
		{
			//Calculer le quotient et le reste de la division par 2
			Quotient = (float)(ValDec / 2);
			Reste = (ValDec % 2);
			resultat[j] = (Reste) ? '1' : '0';
			//Mettre à jour ValDec avec le quotient pour la prochaine itération
			ValDec = Quotient;
		}
		resultat[32] = '\0';
		reverse(resultat, 32);
		//cpl2 

		


	}
	else
	{
		if (fraction)
		{
			for (i = 31; i >= 29; i--)
			{
				Reste = fraction * 2;
				resultat[i] = (Reste) ? '1' : '0';
				Reste -= 1;
			}
			resultat[i--] = '.';
			i--;
		}
		else
		{
			i = 31;
		}

		for (int j = i; j >= (i - ite); j--)
		{
			//Calculer le quotient et le reste de la division par 2
			Quotient = (float)(ValDec / 2);
			Reste = (ValDec % 2);
			resultat[j] = (Reste) ? '1' : '0';
			//Mettre à jour ValDec avec le quotient pour la prochaine itération
			ValDec = Quotient;
		}
		resultat[32] = '\0';
		reverse(resultat, 32);
		for (i = 0; i <= formatAffichage; i++)
		{

			printf("%c", resultat[formatAffichage - i]);
		}
	}
}
