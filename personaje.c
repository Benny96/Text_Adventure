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

//char **** leerFicheroTexto()
//{
//
///*Bloque que se podría intentar mover*/
//	char *** hist = (char ***) malloc (TABLERO * sizeof(char**));
//	for (int i = 0; i < TABLERO; i++)
//	{
//		hist[i] = (char**) malloc (TABLERO * sizeof(char*));
//	}
//	for (int i = 0; i < TABLERO; i++)
//	{
//		for (int j = 0; j < TABLERO; j++)
//		{
//			hist[i][j] = (char*) malloc (TAMANYO_LINEA * sizeof(char));
//		}
//	}
//	int o;
//	int p;
//	int mn=0;
//	FILE* fd1;
//	fd1 = fopen(FICHERO_HISTORIA, "r"); ///////////////////////////////Ahora vamos a leer del fichero de texto
//	char str2[TAMANYO_LINEA];
//	char frmt_str2[TAMANYO_LINEA];
//	int d;
//	while(fgets(str2, TAMANYO_LINEA, fd1)) 
//	{
//    	d = 0;
//	    if(sscanf(str2, "%d", &d) == 0) 
//	    {
//	    	sscanf(str2, "%[^\n]s", frmt_str2);
//	    }
//	    if(mn==0)
//	    {
//	    	o=d;
//	    	mn++;
//	    }
//	    else if(mn==1)
//	    {
//	    	p=d;
//	    	mn++;
//	    }
//	    else if(mn==2)
//	    {
//	    	mn=0;
//	       	strncpy(hist[o][p], frmt_str2, TAMANYO_LINEA);
//	    }
//	    clear_if_needed(str2);
//	}
//	fclose(fd1); ////////////////////////////Cerramos el fichero de texto
//	return *hist;
//	/*Fin del bloque*/
//}
//void clear_if_needed(char *str)
//{
//	if (str[strlen(str) - 1] != '\n')
//	{
//		int c;    
//    	while ( (c = getchar()) != EOF && c != '\n');
//    }
//}//