#include "Personaje.h"

int lecturaBinarioParteuno()
{
	FILE * file;
	file = fopen(FICHERO_BINARIO, "rb");
	int inicializacion = 0;
	if (file == NULL)
	{
		inicializacion = 1;
	}
	fclose(file);
	return inicializacion;
}
int lecturaBinarioPartedos()
{
	FILE * file;
	file = fopen(FICHERO_BINARIO, "rb");
	int num = 0;
	if (file == NULL)
	{
		num = -1;
	}
	else
	{
		num = fgetc(file); 	//Obtenemos la cantidad de personajes guardados
	}
	if (num == -1)
	{
		num = INIT_PERSONAJES;
	}
	fclose(file);
	return num;
}
Personaje * lecturaBinarioPartetres(int num)
{
	Personaje *personajes;
	FILE * file;
	file = fopen(FICHERO_BINARIO, "rb");
	if (file == NULL)
	{
		num = -1;
	}
	else
	{
		num = fgetc(file);
	}
	//Obtenemos la cantidad de personajes guardados
	if (file != NULL)
	{
		personajes = (Personaje*)malloc(num * sizeof(Personaje));	///////////////Reservar memoria para el array de personajes
		fread(personajes, sizeof(Personaje), num, file);  ///////////////////Pasar lainfo que hay en el fichero al array de personajes
		fclose(file);
	}
	//cerrar el fichero
	return personajes;
}

char *** leerFicheroTexto()
{

/*Bloque que se podría intentar mover*/
	char *** hist = (char ***) malloc (TABLERO * sizeof(char**));
	int i = 0;
	int j = 0;
	for (i = 0; i < TABLERO; i++)
	{
		hist[i] = (char**) malloc (TABLERO * sizeof(char*));
	}
	for (i = 0; i < TABLERO; i++)
	{
		for (j = 0; j < TABLERO; j++)
		{
			hist[i][j] = (char*) malloc (TAMANYO_LINEA * sizeof(char));
		}
	}
	int o = 0;
	int p = 0;
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
	/*Fin del bloque*/
}
void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}
void guardarBinarioC(int num, Personaje * persaguardar)
{
	FILE * file;
	file = fopen(FICHERO_BINARIO, "wb");
  	//escribir la cantidad de elementos
  	fputc(num, file);
  	fwrite(persaguardar, sizeof(Personaje), num, file);
  	free(persaguardar);
   	//cerrar fichero
  	fclose(file);
}