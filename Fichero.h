#ifndef FICHERO_H_
#define FICHERO_H_
#include "Personaje.h"

#ifdef __cplusplus
extern "C" {
#endif

//#define FICHERO_BINARIO "personajes.dat"
#define INIT_PERSONAJES 5
#define FICHERO_HISTORIA "historia.txt"
#define TABLERO 3
#define TAMANYO_LINEA 80

//Personaje ** leerFicheroPersonajes();
//void escribirFicheroPersonajes(Personaje ** p);
char *** lecturaHistoria(char hist [TABLERO][TABLERO][TAMANYO_LINEA]);

#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif


#endif