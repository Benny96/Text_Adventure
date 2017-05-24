#include "Fichero.h"

#include <stdio.h>
//#include <string.h>
#include <stdlib.h>


//#include <stdbool.h>

Personaje * leerFicheroPersonajes()
{
	FILE * file;	
	int num;
	/*Proceso de lectura del archivo binario:*/
//	file = fopen(NOMBRE_BINARIO, "rb");
//	
//	/*Obtenemos la cantidad de personajes guardados*/
//	num = fgetc(file);
//
//	if (num == 0)
//	{
//		num = INIT_PERSONAJES;
//	}
//	
//	Personaje * personajes = (Personaje*)malloc(num * sizeof(Personaje));	///////////////Reservar memoria para el array de personajes
//	fread(personajes, sizeof(Personaje), num, file);  ///////////////////Pasar la info que hay en el fichero al array de personajes
//
//	//cerrar el fichero
//	fclose(file);
//	return personajes;
//}

//void escribirFicheroPersonajes(Personaje ** p)
//{
//	FILE * file;
//	int num;
//	file = fopen(FICHERO_BINARIO, "wb");
  	//escribir la cantidad de elementos
//  	if(num==0)
//  		num++;
//  	fputc(num, file);
  	//escribir datos binarios
// 	fwrite(&p, sizeof(Personaje), num, file);
//  	fclose(file);
//  	free(p);
   	//cerrar fichero
//}
char *** lecturaHistoria (char hist [TABLERO][TABLERO][TAMANYO_LINEA])
{
	int o;
	int p;
	int mn=0;
	FILE* fd1;
	fd1 = fopen(FICHERO_HISTORIA, "r"); ///////////////////////////////Ahora vamos a leer del fichero de texto
	char str2[TAMANYO_LINEA];
	char frmt_str2[TAMANYO_LINEA];
	int d;
	while(fgets(str2, TAMANYO_LINEA, fd1)) 
	{
    	d = 0;
	    if(sscanf(str2, "%d", &d) == 0) 
	    {
	    	sscanf(str2, "%[^\n]s", frmt_str2);
	    }
	    if(mn==0)
	    {
	    	o=d;
	    	mn++;
	    }
	    else if(mn==1)
	    {
	    	p=d;
	    	mn++;
	    }
	    else if(mn==2)
	    {
	    	mn=0;
	       	strncpy(hist[o][p], frmt_str2, TAMANYO_LINEA);
	    }
	    clear_if_needed(str2);
	}
	fclose(fd1); ////////////////////////////Cerramos el fichero de texto
	return hist;
}