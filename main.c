#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "personaje.h"

#define MAX_LENGTH	20

void clear_if_needed(char *str);

void dibujar(bool **a)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			{

				
				if(a[i][j])
				{
					
				}
				else
				{

				}
			}
			printf("\n");	
	}
}

void mapear(int x, int y)
{
	for(int i=0;i<=3*5;i++)
	{
		
		for(int j=0;j<=3*5;j++)
		{
			
			if(j%5==0 || i%5==0)
				printf("*");
			else
			{
				if(i==(x*5 +2) && j==(y*5 +2))
				{
					printf("Tu");
				}
				else if (i==(x*5 +2) && j<(y*5 +2) && j>((y*5)-1))
				{
					/* code */
				}
				else
					printf(" ");
			}
				
			

			
		}
		printf("\n");
	}
}
int main (void)
{
	int x=0;
	int y=0;


	FILE * file;	
	int num;
	Personaje personajes[20];
	int i;

	file = fopen("personajes.dat", "rb");
	
	//leer la cantidad de elementos
	num = fgetc(file);
	//crear memoria para guardar los datos
	//personajes = (Personaje*)malloc(num * sizeof(Personaje));	
	//leer los datos binarios al array
	fread(personajes, sizeof(Personaje), num, file);

       
	//leer la longitud de la cadena de char
	//cerrar el fichero
	fclose(file);


	Personaje a;

	printf("Introduce el nombre de tu personaje \n");

	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH];

	int aux;

	printf("dfghj  %d\n",num);
	int q=-1;

	do{
	
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str); //eliminar el \n final

	//reservar la memoria justa para la cadena almacenada
	//a.nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char));
	strcpy(a.nombre, frmt_str);

	
	aux=0;
	for(int i=0;i<num;i++)
	{
		printf("iiiiiiiiiii  %d\n",i);
		printf("ssssssssssss   %s\n", personajes[i].nombre);
		q=i;
		if(strcmp(a.nombre,personajes[i].nombre)==0)
		{
			printf("Introduce otro nombre este ya esta \n");
			aux=1;
		}
	}

	}while(aux==1);

	printf("Introduce la contrasena  \n");

	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str); //eliminar el \n final

	//reservar la memoria justa para la cadena almacenada
	//a.contrasena = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char));
	strcpy(a.contrasena, frmt_str);

		 //abrir fichero

	a.x=0;
	a.y=0;

	printf("aaaaaaaaaaaaaaaaaaaaaaaaaaa%i\n", q);
	personajes[q+1]=a;

  	file = fopen("personajes.dat", "wb");
  

  	//escribir la cantidad de elementos
  	fputc(num+1, file); 
  	//escribir datos binarios
  	fwrite(personajes, sizeof(Personaje), num+1, file);
  
  
  	//cerrar fichero
  	fclose(file);

	//bool **a[3][3];


	mapear(x,y);

	do
	{
		printf("Desplazate hasta abajo a la derecha usando w ,a,s y d \n");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", frmt_str);

		if (strcmp(frmt_str, "w") == 0)
		{
			if(x==0)
			{
				printf("No se puede ir más para arriba \n");
			}
			else
			{
				x--;
			}
		}
		else if(strcmp(frmt_str, "a") == 0)
		{
			if(y==0)
			{
				printf("No se puede ir más para la izquierda \n");
			}
			else
			{
				y--;
			}
		}
		else if(strcmp(frmt_str, "d") == 0)
		{
				if(y==2)
			{
				printf("No se puede ir más para la derecha  \n");
			}
			else
			{
				y++;
			}
		}
		else if(strcmp(frmt_str, "s") == 0)
		{
			if(x==2)
			{
				printf("No se puede ir más para abajo  \n");
			}
			else
			{
				x++;
			}
		}
		else
		{
			printf("Mal \n");
		}


		mapear(x,y);

	}while(!(x==2 &&y==2));

	printf("Llegaste, fin del juego  \n");

	
	return 0;
}


void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}