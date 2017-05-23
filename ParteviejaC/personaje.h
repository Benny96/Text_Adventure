#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#define TAMANYO_CADENAS 20
#define TABLERO 3
#define ESPACIADO 5

typedef struct {
	int nump;
	int x;
	int y;
	int a[10];
	int b[10];
	char nombre[TAMANYO_CADENAS];
	char contrasena[TAMANYO_CADENAS];

} Personaje;

void mapear(int x, int y);

#endif
