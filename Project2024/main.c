#include <stdio.h>
#include <time.h>
#include "main.h"
#include "ConvBin.h"




//fonction Trigonom�trique
void Trigo(u_unitAngle* units, str_parameters* actual)
{
	char choixAngle;
	char setting;
	char numberSettingsAlreadySet = 0;
	char buffer_choix[3][2];
	printf("unit� d'affichage l'angle ? 0 pour <�> / 1 pour <rad>");
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
				strcpy(&buffer_choix[0][numberSettingsAlreadySet],"adj");
				break;
			case coteopp:
				printf("gimme cote opp ");
				scanf("%d", &actual->coteopp);
				strcpy(&buffer_choix[0][numberSettingsAlreadySet],"opp");
				break;
			case hypotenuse:
				printf("gimme hyp ");
				scanf("%d", &actual->hypotenuse);
				strcpy(&buffer_choix[0][numberSettingsAlreadySet],"hyp");
				break;
			default:
				break;
			}
			numberSettingsAlreadySet++;
		}
	}
	




	//scanf("%d", choixAngle);


}

char registerLogs()
{
	FILE *fp;
    fp = fopen("LOGS.csv", "a"); // open file in write mode

    if (fp == NULL) {
        printf("ya pas de fichier !!!\n");
        return 1;
    }
	fprintf(fp,"euh");
	fclose(fp);

}
char menu(void)
{
	char userChoix;
	printf("____________________________________");
	printf("What u want to do ? Convertisseur = 0 TrigoCalulator =1");
	scanf("%d", &userChoix);
}

void main(void)
{
	time_t timeNow;
	struct tm *info;
	u_unitAngle units;
	EnParams settings;
	str_parameters actual;
	char buffer_time[80];
	char buffer_user_choix[8];
   	time(&timeNow);
   	info = localtime( &timeNow );
   	strftime(buffer_time,80,"%x ,%X,", info);
	if(menu())
	{
		strcpy(buffer_user_choix ,"TrigCal");
		Trigo(&units, &actual);
	}
	else
	{
		strcpy(buffer_user_choix ,"ConvDec");
		convdecbin();
	}
	
	
	
	
}