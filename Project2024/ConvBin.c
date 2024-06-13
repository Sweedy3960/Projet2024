#include "ConvBin.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include<string.h>
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

float convdecbin(char *debutTrame)
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
	printf("Entrez une valeur decimale: ");
	scanf("%f", &ValDec_initial);

	printf("choix format affichage ''/'8'/'16'/'32' : ");
	scanf("%d", &formatAffichage);
	ValDec = (int)ValDec_initial; // partie enti�re

	fraction = ValDec_initial - ValDec; // partie fractionnaire


	neg = ((unsigned) ValDec_initial > 0x7FFF) ? true : false;


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
			//Mettre � jour ValDec avec le quotient pour la prochaine it�ration
			ValDec = Quotient;
		}
		resultat[32] = '\0';
		reverse(resultat, 32);
		//cpl2 
		for (int i = 0; i < 32; i++)
        {
            if (resultat[i] == '0')
			{
                resultat[i] = '0';
			}
            else
			{
                resultat[i] = '1';
				itera = i+1;
				break;
			}
        }
		for (int i = itera; i < 32; i++)
        {
            if (resultat[i] == '1')
            {
                resultat[i] = '0';
            }
			else
			{
                resultat[i] = '1';
			}
        }

		


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
			//Mettre � jour ValDec avec le quotient pour la prochaine it�ration
			ValDec = Quotient;
		}
		resultat[32] = '\0';
		reverse(resultat, 32);
	}

	printf("0b");
	for (i = 0; i <= formatAffichage; i++)
	{
		printf("%c", resultat[formatAffichage - i]);
	}
	//reverse(resultat, 32);
	strcat(&debutTrame[2],resultat);
	debutTrame[sizeof(debutTrame) - 1] = '\0';
	

	return ValDec_initial;
}
