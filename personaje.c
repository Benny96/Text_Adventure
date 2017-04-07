#include "personaje.h"
#include <stdio.h>


void menuPrincipal()
{
	printf("Introduce:  \n");
	printf("1.- Crear un personaje.\n");
	printf("2.- Cargar un personaje.\n");
}

void menuPartida()
{
	printf("Introduce:  \n");
	printf("1.- Comenzar una partida nueva.\n");
	printf("2.- Cargar una partida existente.\n");
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
					
				}
				else
					printf(" ");
			}
				
			

			
		}
		printf("\n");
	}
}

