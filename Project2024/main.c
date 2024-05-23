#include <stdio.h>
#include <math.h>


void convdecbin(void)
{
	int ite = 0;
	int ValDec = 0;
	int ValDec_initial = 0;
	float Quotient = 0;
	int Reste = 0;
	char *pt_resultat;

	//Demander une valeur comprise entre 0 et 255
	printf_s("Entrez une valeur decimale comprise entre 0 et 255 : ");
	scanf_s("%d", &ValDec_initial);

	ite = (log2(abs(ValDec_initial)) + 1);
	ValDec = ValDec_initial;
	pt_resultat = (char*)malloc(ite);
	//Tant que ValDec est différent de zéro
	for (int i = 0; i < ite; i++)
	{
		//Calculer le quotient et le reste de la division par 2
		Quotient = (ValDec / 2);
		Reste = (ValDec % 2);
		*(pt_resultat + i) = Reste;
		

		//Mettre à jour ValDec avec le quotient pour la prochaine itération
		ValDec = Quotient;
	}
	
}

//fonction Trigonomètrique
void Trigo (void)
{
	char choixAngle = " ";
	//enum  ()

	printf("affichage l'angle ? <°> ou <rad>");

	//scanf("%d", choixAngle);


}


void main(void)
{
	convdecbin();

}