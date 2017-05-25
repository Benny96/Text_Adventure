#include "Personaje.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Personaje * leerPersonajes()
//{
//	FILE * file;
//	int num = -1;
//	int inicializacion;
//	Personaje * personajes;
//	//Proceso de lectura del archivo binario:
//	file = fopen(FICHERO_BINARIO, "rb");
//	
//	//Obtenemos la cantidad de personajes guardados
//	num = fgetc(file);
//	if (num == -1)
//	{
//		num = INIT_PERSONAJES;
//		inicializacion = 1;
//	}
//	if (inicializacion == 0)
//	{
//		personajes = (Personaje*)malloc(num * sizeof(Personaje));	///////////////Reservar memoria para el array de personajes
//		fread(personajes, sizeof(Personaje), num, file);  ///////////////////Pasar lainfo que hay en el fichero al array de personajes
//	}
//	
//	//cerrar el fichero
//	fclose(file);
//	return personajes;
//}//