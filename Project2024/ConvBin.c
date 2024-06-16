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
void doiing(char *tb_to_use, int formatAffichage, float ValDec_initial,char *debutTrame, char dumb)
{
	char ite = 0;
	char itera = 0;
	int ValDec = 0;
	float fraction;
	bool neg = false;
	int i = 0;
	int j = 0;
	float Quotient = 0;
	char Reste = 0;

	int len = dumb-1;
	ValDec = (int)ValDec_initial; // partie enti�re

	fraction = ValDec_initial - ValDec; // partie fractionnaire


	neg = ((unsigned)ValDec_initial > 0x7FFF) ? true : false;


	ite = (log2(abs(ValDec_initial)) + 1);
	if (neg)
	{
		if (fraction)
		{
			for (i = len-2; i >= len-4; i--)
			{
				Reste = fraction * 2;
				tb_to_use[i] = (Reste) ? '1' : '0';
				Reste -= 1;
			}
			tb_to_use[i--] = '.';
			i--;
		}
		else
		{
			i = len-2;
		}

		for (j = i; j >= (i - ite); j--)
		{
			//Calculer le quotient et le reste de la division par 2
			Quotient = (float)(ValDec / 2);
			Reste = (ValDec % 2);
			tb_to_use[j] = (Reste) ? '1' : '0';
			//Mettre � jour ValDec avec le quotient pour la prochaine it�ration
			ValDec = Quotient;
		}
		tb_to_use[len] = '\0';
		reverse(tb_to_use, len);
		//cpl2 
		for (i = 0; i < len; i++)
		{
			if (tb_to_use[i] == '0')
			{
				tb_to_use[i] = '0';
			}
			else
			{
				tb_to_use[i] = '1';
				itera = i + 1;
				break;
			}
		}
		for (i = itera; i < len; i++)
		{
			if (tb_to_use[i] == '1')
			{
				tb_to_use[i] = '0';
			}
			else
			{
				tb_to_use[i] = '1';
			}
		}




	}
	else
	{
		if (fraction)
		{
			for (i = len; i >= (len-3); i--)
			{
				Reste = fraction * 2;
				tb_to_use[i] = (Reste) ? '1' : '0';
				Reste -= 1;
			}
			tb_to_use[i--] = '.';
			i--;
		}
		else
		{
			i = (len-2);
		}

		for (int j = i; j >= (i - ite); j--)
		{
			//Calculer le quotient et le reste de la division par 2
			Quotient = (float)(ValDec / 2);
			Reste = (ValDec % 2);
			tb_to_use[j] = (Reste) ? '1' : '0';
			//Mettre � jour ValDec avec le quotient pour la prochaine it�ration
			ValDec = Quotient;
		}
		tb_to_use[len] = '\0';
		reverse(tb_to_use, len);
	}
	/*
	printf("0b");
	for (i = 0; i <= formatAffichage; i++)
	{
		printf("%c", resultat[formatAffichage - i]);
	}
	*/
	/*
	
	printf("%s", tb_to_use);
	*/
	/*
	for ( i = 0; i < len; i++)
	{
		debutTrame[2 + i] = tb_to_use[len-i];
		
	}*/
	//debutTrame[i] = '\0';

	//reverse(tb_to_use, len);
	strcat(&debutTrame[2],&tb_to_use[1]);
	//debutTrame[sizeof(debutTrame) - 1] = '\0';
	//printf("%s", debutTrame);
}
void fillarray(char *arraytofill,char dumb)
{
	int len = dumb-1;
	
	for (int i = 0; i <= len; i++)
	{

		arraytofill[i] = '0';

	}
	arraytofill[len] = '\0';
}

float convdecbin(char* debutTrame)
{
	
	float ValDec_initial = 0;
	char dumb;
	
	int formatAffichage = 0;
    char resultat32[33];
	char resultat16[17];
	char resultat8[9];




	//Demander une valeur comprise entre 0 et 255
	printf("Entrez une valeur decimale: ");
	scanf("%f", &ValDec_initial);

	printf("choix format affichage ''/'8'/'16'/'32' : ");
	scanf("%d", &formatAffichage);


	switch (formatAffichage)
	{
		case 8:
			dumb = sizeof(resultat8);
			fillarray(resultat8,dumb);
			formatAffichage = 8;
			doiing(resultat8, formatAffichage, ValDec_initial, debutTrame, dumb);
			printf("%.10s", debutTrame);
			break;
		case 16:
			dumb = sizeof(resultat16);
			fillarray(resultat16, dumb);
			formatAffichage = 16;
			doiing(resultat16, formatAffichage, ValDec_initial, debutTrame, dumb);
			printf("%.18s", debutTrame);
			break;
		case 32:
			dumb = sizeof(resultat32);
			fillarray(resultat32,dumb);
			formatAffichage = 32;
			doiing(resultat32, formatAffichage, ValDec_initial, debutTrame, dumb);
			printf("%.34s", debutTrame);
			break;

		default:
			formatAffichage = 3;
			break;

	}
	
	//reverse(resultat, formatAffichage);
	//strcat(&debutTrame[2],&resultat[1]);
	//debutTrame[sizeof(debutTrame) - 1] = '\0';
	//printf("%s", debutTrame);

	return ValDec_initial;
}
