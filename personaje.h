#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANYO_CADENAS 20
#define TABLERO 3
#define ESPACIADO 5
#define INIT_PERSONAJES 1
#define TAMANYO_PARTIDAS_PERSONAJE 10
#define FICHERO_BINARIO "personajes.dat"

#define TAMANYO_LINEA 150
#define FICHERO_HISTORIA "historia.txt"

typedef struct {
	int nump;
	int x;
	int y;
	int a[TAMANYO_PARTIDAS_PERSONAJE];
	int b[TAMANYO_PARTIDAS_PERSONAJE];
	char nombre[TAMANYO_CADENAS];
	char contrasena[TAMANYO_CADENAS];
} Personaje;

int lecturaBinarioParteuno();
int lecturaBinarioPartedos();
Personaje * lecturaBinarioPartetres(int num);
void guardarBinarioC(int num, Personaje * persaguardar);
char *** leerFicheroTexto();
void clear_if_needed(char* str);

#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif

#endif
