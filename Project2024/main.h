#ifndef MAIN_H
#define MAIN_H
typedef struct 
{
	float abscisse;
	float coteopp;
	float hypotenuse;
	float sinun;
	float cosinus;
	float tangeante;
	float angle_alpha;
}str_parameters;
typedef enum {
	abscisse = 1,
	coteopp = 2,
	hypotenuse = 3,

}EnParams;
typedef union {
	int degreeangle;
	float radianangle;
}u_unitAngle;

#endif