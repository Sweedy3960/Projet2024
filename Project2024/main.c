#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"
#include "ConvBin.h"
#include <string.h>



//fonction Trigonom�trique
void Trigo(void)
{
	char i;
	int etat_angle;
	int etat_cote;
	int etat_calcule = 0;
	str_triangle triangle;
	u_angle unite_angle;

	/********************************/
	/*SAISIE DES DONNEES UTILISATEUR*/
	/********************************/

	printf("unitee de l'angle : (1)rad ou (2)deg\n");

	scanf("%d", &etat_angle);

	//choix de l'unitée de l'angle
	switch (etat_angle)
	{
	case rad:

		unite_angle.angle_radian;

		break;
	case deg:

		unite_angle.angle_degre;

		break;
	default:
		;
	}


	printf("choisir le cote a calculer parmis : (1)abscisse, (2)cote oppose et (3)hypotenuse \n");

	scanf("%d", &etat_cote);

	//choix du côté du triangle à calculer
	switch (etat_cote)
	{
	case abscisse:

		//saisi des autres côtés du traingle
		printf("valeur de l hypotenuse et le cote oppose \n");

		scanf("%f %f", &triangle.hypotenuse, &triangle.cote_oppose);

		//affiche une erreur dans le cas ou l'hypoténuse n'est pas le plus grand côtés
		if (triangle.cote_oppose >= triangle.hypotenuse)
		{
			printf("l hypotenuse doit etre le plus grand cote \n rerentrez une valeur pour le cote oppose\n");

			scanf("%f", &triangle.cote_oppose);

		}


		etat_calcule = calcul_abscisse;

		break;
	case cote_oppose:

		//saisi des autres côtés du traingle
		printf("valeur de l abscisse et l hypotenuse\n");

		scanf("%f %f", &triangle.abscisse, &triangle.hypotenuse);

		//affiche une erreur dans le cas ou l'hypoténuse n'est pas le plus grand côtés
		if (triangle.abscisse >= triangle.hypotenuse)
		{
			printf("l hypotenuse doit etre le plus grand cote \n rerentrez une valeur pour l abscisse\n");

			scanf("%f", &triangle.abscisse);
		}

		etat_calcule = calcul_cote_oppose;

		break;
	case hypotenuse:

		printf("valeur de l abscisse et le cote oppose\n");

		scanf("%f %f", &triangle.abscisse, &triangle.cote_oppose);

		etat_calcule = calcul_hypotenuse;

		break;
	default:
		;
	}
	/******************************/
	/*CALCULE DU CÔTES SELECTIONNE*/
	/******************************/
	switch (etat_calcule)
	{
	case calcul_abscisse:

		// calcule de l'angle alpha en radian
		triangle.alpha = asin((double)triangle.cote_oppose / (double)triangle.hypotenuse);

		triangle.abscisse = (double)triangle.hypotenuse * sin((double)triangle.alpha);

		// calcule de l'angle alpha en degré
		if (etat_angle == deg)
		{
			triangle.alpha = triangle.alpha * CENTHUITANTE / PI;
		}

		printf("alpha = %f\n", triangle.alpha);

		printf("abscisse = %f\n", triangle.abscisse);

		break;

	case calcul_cote_oppose:

		// calcule de l'angle alpha en radian
		triangle.alpha = acos((double)triangle.abscisse / (double)triangle.hypotenuse);

		triangle.cote_oppose = (double)triangle.abscisse * cos((double)triangle.alpha);

		// calcule de l'angle alpha en degré
		if (etat_angle == deg)
		{
			triangle.alpha = triangle.alpha * CENTHUITANTE / PI;
		}

		printf("alpha = %f\n", triangle.alpha);

		printf("cote oppose = %f\n", triangle.cote_oppose);

		break;

	case calcul_hypotenuse:

		// calcule de l'angle alpha en radian
		triangle.alpha = atan((double)triangle.cote_oppose / (double)triangle.abscisse);

		triangle.hypotenuse = (double)triangle.abscisse / cos((double)triangle.alpha);

		// calcule de l'angle alpha en degré
		if (etat_angle == deg)
		{
			triangle.alpha = triangle.alpha * CENTHUITANTE / PI;
		}

		printf("alpha = %f\n", triangle.alpha);

		printf("hypotenuse = %f\n", triangle.hypotenuse);

		break;
	}
	


}

// Fonction pour créer le fichier de logs et initialiser les compteurs
char createregisterLogs(char* counterval)
// Renvoie 1 si le fichier est créé, 0 sinon + valeur du compteur
{
    FILE* fp;
    int countBinairy = 0;
    int countTrigo = 0;
    char buffer_counter_val[35] = { 0 };

    // Ouvrir le fichier en mode lecture
    fp = fopen("LOGS.txt", "r");

    // Si le fichier n'existe pas, le créer et initialiser les compteurs
    if (fp == NULL) {
        fputs("ya pas de fichier !!! création ...\n", fp);
        fp = fopen("LOGS.txt", "w"); // Ouvrir le fichier en mode écriture
        fputs("compteur fonction binaire: %d\n", countBinairy, fp);
        fputs("compteur fonction Trigo: %d\n", countTrigo, fp);
        fclose(fp);
        return 1;
    }
    else
    {
        // Lire les valeurs des compteurs à partir du fichier
        fgets(buffer_counter_val, sizeof buffer_counter_val, fp);
        printf("\"%s\"\n", buffer_counter_val);
        counterval[0] = getnumbers(&buffer_counter_val);

        fgets(buffer_counter_val, sizeof buffer_counter_val, fp);
        printf("\"%s\"\n", buffer_counter_val);
        counterval[1] = getnumbers(&buffer_counter_val);

    }
    fclose(fp);
    return 0;
}

// Fonction pour extraire un nombre à partir d'une chaîne de caractères
int getnumbers(char* buffer_counter_val)
{
    int i;
    int j = 0;
    char number[100] = { 0 };
    int numb = 0;

    // Rechercher le caractère ':' dans la chaîne
    for (i = 34; i > 0; i--)
    {
        if (buffer_counter_val[i] == ':')
        {
            break;
        }
        number[(34 - i)] = buffer_counter_val[i];
    }
    number[sizeof(number - 1)] = '\0';
    // Supprimer le caractère de fin de ligne
    for (i = 34; i > 0; i--)
    {
        if (number[i] == '\n')
        {
            number[i] = 0;
            break;
        }
        number[i] = number[i];
    }

    // Extraire le nombre à partir de la chaîne
    for (i = 34; i > 0; i--)
    {
        if (number[i] != 0x00)
        {
            number[j] = number[i];
            number[i] = 0x00;
            j++;
            if (j >= 3)
            {
                break;
            }
        }
    }
    numb = atoi(number);
    return numb;
}

// Fonction pour enregistrer les logs
void registerLogs(char* counterval, char* buffer_time, char* buffer_user_choix, float* choixuser, char* buffer_results)
{
    FILE* fp;
    char buffer_counter_val_bin[35] = "compteur fonction binaire :";
    char buffer_counter_val_trig[35] = "compteur fonction Trigo :";
    char value[20];
    char choix_user[100];
    char pos;

    // Convertir la valeur en chaîne de caractères

    itoa(counterval[0], value, 10);
    strcat(buffer_counter_val_bin, value);
    buffer_counter_val_bin[34] = '\n';
    fp = fopen("LOGS.txt", "r+"); // Ouvrir le fichier en mode lecture/écriture
    rewind(fp);
    fputs(buffer_counter_val_bin, fp);
    fputs("\n", fp);
    buffer_counter_val_trig[34] = '\n';
    fputs(buffer_counter_val_trig, fp);
    fclose(fp);

    // Écrire les logs
    fp = fopen("LOGS.txt", "a"); // Ouvrir le fichier en mode ajout
    fputs(buffer_time, fp);
    fputs(buffer_user_choix, fp);
    fputs("/", fp);
    gcvt(*choixuser, 3, value);
    fputs(value, fp);
    fputs("/", fp);
    fputs(buffer_results, fp);
    fputs("\n", fp);
    fclose(fp);
}

// Fonction pour écrire les valeurs de l'utilisateur
void writteUserVal(char* buffer_time)
{
    FILE* fp;
    fp = fopen("LOGS.txt", "a"); // Ouvrir le fichier en mode ajout
    fputs("\n", fp);
    fputs(buffer_time,fp);
    fclose(fp);
}

// Fonction pour afficher le menu
char menu(void)
{
    int userChoix;
    printf("____________________________________\n");
    printf("What u want to do ? Convertisseur = 0 TrigoCalulator =1\n");
    scanf("%d", &userChoix);
    return userChoix;
}

// Fonction principale
void main(void)
{
    time_t timeNow;
    struct tm* info;
    char buffer_time[80];
    char buffer_user_choix[8] = { 0 };
    char counterval[2] = { 0 };
    float buffer_results[2];
    char debutTrame[35] = "0b";
    float choixuser = 0;

    createregisterLogs(counterval);
    time(&timeNow);
    info = localtime(&timeNow);
    strftime(buffer_time, 80, "%x ,%X,", info);

    if (menu())
    {
        strcpy(buffer_user_choix, "TrigCal");
        Trigo();
        counterval[1] = counterval[1] + 1;
        //registerLogs(counterval,buffer_time, buffer_user_choix, &choixuser, buffer_results);
    }
    else
    {
        strcpy(buffer_user_choix, "ConvDec");
        choixuser = convdecbin(debutTrame);
        counterval[0] = counterval[0] + 1;
        registerLogs(counterval, buffer_time, buffer_user_choix, &choixuser, debutTrame);
    }
}