/**
 ** @Autores: 
 **
 **	Garikoitz Bereciartua (garibere13) 
 **	Imanol Echeverría (Echever) 
 **	Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** Personaje.h es el fichero de cabecera correspondiente a Personaje.c, y esta clase se
 **	encargará de definir los atributos del struct Persona, así como ciertas funciones
 ** válidas para hacer la escritura y lectura de datos en fichero binario, así como
 ** funciones de lectura de fichero de texto.
 */

#ifndef PERSONAJE_H_
#define PERSONAJE_H_

/**
 ** Directiva de preprocesador para poder integrar este código C en nuestra aplicación en C++.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 ** Constantes definidas para inicializar los atributos del struct Personaje.
 */

#define TAMANYO_CADENAS 20
#define TAMANYO_PARTIDAS_PERSONAJE 10

/**
 ** Constantes definidas para alterar el tablero gráficamente. TABLERO permite expandir o reducir
 ** las dimensiones del tablero, mientras que ESPACIADO genera el espaciado de las celdas del
 ** tablero.
 */

#define TABLERO 3
#define ESPACIADO 5

/**
 ** Constantes definidas para inicializar y acceder al fichero binario que almacena los Personajes.
 */

#define INIT_PERSONAJES 1
#define FICHERO_BINARIO "personajes.dat"

/**
 ** Constantes definidas para inicializar y acceder al fichero de texto de historia.
 */

#define TAMANYO_LINEA 150
#define FICHERO_HISTORIA "historia.txt"

typedef struct 
{
	int nump;
	int x;
	int y;
	int a[TAMANYO_PARTIDAS_PERSONAJE];
	int b[TAMANYO_PARTIDAS_PERSONAJE];
	char nombre[TAMANYO_CADENAS];
	char contrasena[TAMANYO_CADENAS];
} Personaje;

/**
 ** Función que hará la primera parte del proceso de lectura de fichero binario.
 **
 ** @Return:
 **
 ** Valor de inicializacion, variable auxiliar necesaria para hacer correctamente
 ** la lectura de fichero binario y procesos posteriores.
 */

int lecturaBinarioParteuno();

/**
 ** Función que hará la segunda parte del proceso de lectura de fichero binario.
 **
 ** @Return:
 **
 ** Valor de num, variable auxiliar para conocer el número de elementos que hay
 ** almacenados en el fichero binario y necesaria para procesos posteriores.
 */

int lecturaBinarioPartedos();

/**
 ** Función que hará la tercera parte del proceso de lectura de fichero binario.
 **
 ** @Param:
 **
 ** int num: Número de personajes almacenados en el fichero binario.
 **
 ** @Return:
 **
 ** Puntero de Personajes que contienen toda la información guardada en el fichero
 ** binario.
 */

Personaje * lecturaBinarioPartetres(int num);

/**
 ** Función que permitirá completar el proceso de guardado de fichero binario, comenzado
 ** en C++ en main.cpp.
 **
 ** @Param:
 **
 ** int num: Número de personajes almacenados en el fichero binario.
 ** Personaje * persaguardar: Puntero con los Personajes a almacenar en el fichero binario.
 */

void guardarBinarioC(int num, Personaje * persaguardar);

/**
 ** Función que hará la lectura del fichero de texto que contiene la historia.
 **
 ** @Return:
 **
 ** Triple puntero a chars, lo que sería un array bidimensional de strings en C.
 */

char *** leerFicheroTexto();

/**
 ** Función auxiliar que permite vaciar los buffers de los char* en la lectura en fgets.
 **
 ** @Param:
 **
 ** char* str: Buffer de cadena de caracteres a vaciar.
 */

void clear_if_needed(char* str);

#ifdef __cplusplus
}
#endif

#endif
