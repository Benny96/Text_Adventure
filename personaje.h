#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#define TAMANYO_CADENAS 20
#define TABLERO 3
#define ESPACIADO 5

#define TAMANYO_PARTIDAS_PERSONAJE 10

typedef struct {
	int nump;
	int x;
	int y;
	int a[TAMANYO_PARTIDAS_PERSONAJE];
	int b[TAMANYO_PARTIDAS_PERSONAJE];
	char nombre[TAMANYO_CADENAS];
	char contrasena[TAMANYO_CADENAS];
} Personaje;

#endif
