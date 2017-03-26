#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

	bool **a[3][3];

	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH];

	mapear(x,y);

	do
	{
		printf("Introduce cosas \n");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", frmt_str);

		if (strcmp(frmt_str, "w") == 0)
		{
			if(x==0)
			{
				printf("Mal x=0 \n");
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
				printf("Mal y=0 \n");
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
				printf("Mal y=2 \n");
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
				printf("Mal x=2 \n");
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