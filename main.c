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
	Personaje a;

	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH];

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


	printf("Bienvenido \n");

	int len;
	int option;
	do 
	{
		printf("Introduce:  \n");
		printf(" 1 para crear un peraonaje  \n");
		printf(" 2 para cargar un peraonaje  \n");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%d", &option);


	}while(option!=2 && option!=1);

	if(option==2)
	{
	printf("Introduce el nombre de tu personaje \n");

	int aux;

	int q=-1;

	do{
	
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str); //eliminar el \n final

	

	
	aux=0;

	printf("El numero es %i\n",num  );

	for(int i=0;i<(num+1);i++)
	{
		
		if(strcmp(frmt_str,personajes[i].nombre)==0)
		{
			q=i;
			printf("Perfecto  \n");
			aux=1;
		}

	}

	if(aux!=1)
		printf("El nombre no existe introduce otro  \n");

	}while(aux!=1);


	printf("Introduce tu contraseña \n");


	do{
	
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str); //eliminar el \n final

	//reservar la memoria justa para la cadena almacenada
	//a.nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char));
	
	
	
	

	if(strcmp(frmt_str,personajes[i].contrasena)!=0)
		printf("La contrasena es incorrecta introduce otra  \n");

	}while(strcmp(frmt_str,personajes[q].contrasena)!=0);


	a=personajes[q];
	}

	
	if(option==1)
	{
	

	printf("Introduce el nombre de tu personaje \n");

	int aux;

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
		q=i;
		if(strcmp(a.nombre,personajes[i].nombre)==0)
		{
			
			printf("Este nombre ya existe  \n");
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

	a.nump=0;

	//a.nump=2;

	/*a.a[0]=1;
	a.a[1]=1;
	a.a[2]=2;

	a.b[2]=0;
	a.b[1]=1;
	a.b[0]=2;
	*/

	personajes[q+1]=a;

  	

	//bool **a[3][3];
  }

  do 
	{
		printf("Introduce:  \n");
		printf(" 1 comenzar una partida  \n");
		printf(" 2 para cargar una partida  \n");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%d", &option);


	}while(option!=2 && option!=1);


	if(option==1)
	{
		a.nump++;
		a.x=0;
		a.y=0;

	}
	if(option==2)
	{
		if(a.nump!=0)
		{

			int i;
			for(i=0;i<a.nump;i++)
			{
				printf("Intrdoduce %d para iniciar la partida en la que la posición era x= %d e y= %d \n",i, a.a[i],a.b[i]);
				
			}
			int hola;
			do
			{
				printf("Introduce una opcion  \n");
				fgets(str, MAX_LENGTH, stdin);
				clear_if_needed(str);
				sscanf(str, "%d", &hola);

				if(hola>a.nump || hola<0)
					printf("No es una opcion valida  \n");

			}while(hola>a.nump || hola<0);

			a.x=a.a[hola];
			a.y=a.b[hola];
		}
		else
		{
			printf("No hay partidas que mostrar \n");

		}
		
	}


	mapear(a.x,a.y);

	do
	{
		printf("Desplazate hasta abajo a la derecha usando w ,a,s y d , g para guardar \n");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", frmt_str);

		if (strcmp(frmt_str, "g") == 0)
		{
			a.a[a.nump]=a.x;
			a.a[a.nump]=a.y;
			break;
		}

		if (strcmp(frmt_str, "w") == 0)
		{
			if(a.x==0)
			{
				printf("No se puede ir más para arriba \n");
			}
			else
			{
				a.x--;
			}
		}
		else if(strcmp(frmt_str, "a") == 0)
		{
			if(a.y==0)
			{
				printf("No se puede ir más para la izquierda \n");
			}
			else
			{
				a.y--;
			}
		}
		else if(strcmp(frmt_str, "d") == 0)
		{
				if(a.y==2)
			{
				printf("No se puede ir más para la derecha  \n");
			}
			else
			{
				a.y++;
			}
		}
		else if(strcmp(frmt_str, "s") == 0)
		{
			if(a.x==2)
			{
				printf("No se puede ir más para abajo  \n");
			}
			else
			{
				a.x++;
			}
		}
		else
		{
			printf("Mal \n");
		}


		mapear(a.x,a.y);

	}while(!(a.x==2 && a.y==2));

	printf("Llegaste, fin del juego  \n");

	file = fopen("personajes.dat", "wb");
  

  	//escribir la cantidad de elementos
  	fputc(num+1, file); 
  	//escribir datos binarios
  	fwrite(personajes, sizeof(Personaje), num+1, file);
  
  
  	//cerrar fichero
  	fclose(file);


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