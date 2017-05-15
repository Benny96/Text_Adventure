#include "personaje.h"
#include <stdio.h>

#define ESPACIADO 5
#define TABLERO 3

void mapear(int x, int y)
{
	for(int i=0;i<=TABLERO*ESPACIADO;i++)
	{
		
		for(int j=0;j<=TABLERO*ESPACIADO;j++)
		{
			
			if(j%ESPACIADO==0 || i%ESPACIADO==0)
				printf("*");
			else
			{
				if(i==(x*ESPACIADO +2) && j==(y*ESPACIADO +2))
				{
					printf("Tu");
				}
				else if (i==(x*ESPACIADO +2) && j<(y*ESPACIADO +2) && j>((y*ESPACIADO)-1))
				{
					
				}
				else
					printf(" ");
			}
				
			

			
		}
		printf("\n");
	}
}

