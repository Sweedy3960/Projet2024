#ifndef MAIN_H
#define MAIN_H

#define PI 3.14159265359
#define CENTHUITANTE 180







typedef enum { rad = 1, deg = 2 }e_angle;
typedef enum { abscisse = 1, cote_oppose = 2, hypotenuse = 3 }e_choix_cote;
typedef enum { calcul_abscisse = 1, calcul_cote_oppose = 2, calcul_hypotenuse = 3 }e_etat_calcule;

typedef union
{
	float angle_degre;  // 4 octets
	float angle_radian; // 4 octets

}u_angle;				//4 octets

typedef struct
{
	float abscisse;		// 4 octets
	float cote_oppose;	// 4 octets
	float hypotenuse;	// 4 octets
	float sinus;		// 4 octets
	float cosinus;		// 4 octets
	float tangente;		// 4 octets
	float alpha;		// 4 octets
}str_triangle;
void Trigo(void);
#endif