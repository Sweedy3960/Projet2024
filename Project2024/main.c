#include <stdio.h>

#include "main.h"
#include "ConvBin.h"




//fonction Trigonomètrique
void Trigo(u_unitAngle* units, str_parameters* actual)
{
	char choixAngle;
	char setting;
	char numberSettingsAlreadySet = 0;

	printf("unité d'affichage l'angle ? 0 pour <°> / 1 pour <rad>");
	scanf("%d", &choixAngle);

	if (choixAngle)
	{
		while (numberSettingsAlreadySet <= 1)
		{
			printf("witch params 1 pour abscisse / 2 pour le cote oppose / 3 l hypethenuse");
			scanf("%d", &setting);
			//scanf("%d", );
			switch (setting)
			{
			case abscisse:
				printf("gimme abscisse");
				scanf("%d", &actual->abscisse);
				break;
			case coteopp:
				printf("gimme cote opp ");
				scanf("%d", &actual->coteopp);
				break;
			case hypotenuse:
				printf("gimme hyp ");
				scanf("%d", &actual->hypotenuse);
				break;
			default:
				break;
			}
			numberSettingsAlreadySet++;
		}




	}




	//scanf("%d", choixAngle);


}


void main(void)
{
	u_unitAngle units;
	EnParams settings;
	str_parameters actual;

	Trigo(&units, &actual);
	convdecbin();

}