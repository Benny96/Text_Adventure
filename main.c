#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "personaje.h"

#define MAX_LENGTH	20

void clear_if_needed(char *str);



int hola=-2;
int nump_aux = 0;
int option = -1;

int main (void)
{



	FILE * file;	
	int num;
	Personaje *personajes;  /////////////////////////////Array de personajes
	Personaje *listan;    //////////////////////////////////Otro array de personajes para volcar en el los datos a la hora de guardar
	int i;
	int q;
	Personaje a;


	int xx=0;
	int yy=0;

	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH];

	file = fopen("personajes.dat", "rb");     ////////////////////////Emepzamos a leer el archivo binario
	
	//leer la cantidad de elementos
	num = fgetc(file);


	
	personajes = (Personaje*)malloc(num * sizeof(Personaje));	///////////////Reservar memoria para el array de personajes
	fread(personajes, sizeof(Personaje), num, file);  ///////////////////Pasar lainfo que hay en el fichero al array de personajes

       
	//cerrar el fichero
	fclose(file);

	

	printf("Bienvenido! \n");

	int len;
	do 
	{
		menuPrincipal();
		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%d", &option);    ////////////////////////////////////Guardamos lo que haya introducido en la direccion de option

		if(num==-1&&option==2)
			printf("No hay personajes\n");

	}while( (option!=1 && num==-1 ) || (option!=2 && option!=1) );

	memset(str, 0, 20);




	
	//Aqui empieza la opcion de cargar un personaje
	if(option==2)
	{
	printf("Ha seleccionado cargar un personaje.\n");

	if(num!=0)
	{
		printf("Estos son los nombres existentes en el sistema: \n");
		//Un for que saque por pantalla los nombres existentes en el sistema.
		for (int i = 0; i < num; i++)
		{
			printf("%s \n", personajes[i].nombre);
		}

	}

	
	printf("Introduce el nombre de tu personaje: \n");

	int aux;

	 q=-1;

	do{
	
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str); 
	
	aux=0;

	for(int i=0;i<num;i++)
	{
		if(strcmp(frmt_str,personajes[i].nombre)==0) //////////////////////Validamos que exista ese nombre en el sistema
		{
			q=i;
			aux=1;
			break;
		}

	}

	if(aux!=1)
		printf("El nombre no existe, introduce otro.\n");

	}while(aux!=1);

	memset(str, 0, 20);
	memset(frmt_str, 0, 20);
	printf("Introduce tu contrasenya: \n");


	do{
	
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str); 


	if(strcmp(frmt_str,personajes[q].contrasena)!=0)
		printf("La contrasenya es incorrecta, introduce otra.\n");

	}while(strcmp(frmt_str,personajes[q].contrasena)!=0); ////////////////////////Tambien validamos que este introduciendo la contrasenya que le correspone a ese nombre

	memset(str, 0, 20);
	memset(frmt_str, 0, 20);

  	
  	listan = (Personaje*)malloc((num) * sizeof(Personaje)); //////////////////Crear memoria para el array de personajes auxiliar

	for(int i=0;i<num;i++)
	{
		listan[i]=personajes[i];   /////////////////Copiamos todos los datos del array personaje al array listan
	}
	a=listan[q];

	nump_aux = listan[q].nump;
	}
	//Aqui acaba la opcion de cargar un personaje
	





	
	//Aqui empieza la opcion de crear un personaje
	if(option==1)
	{
	printf("Ha seleccionado crear un personaje.\n");
	printf("Introduce el nombre de tu personaje: \n");

	int aux;

	q=-1;

	do{
	
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str); 

	strcpy(a.nombre, frmt_str);

	
	aux=0;
	for(int i=0;i<num;i++)
	{
		q=i;
		if(strcmp(a.nombre,personajes[i].nombre)==0)   /////////////////////////////////Obligamos que introduzca un nombre inexistente en el sistema
		{
			
			printf("Este nombre ya existe, introduce otro.\n");
			aux=1;
		}

	}

	}while(aux==1);

	memset(str, 0, 20);
	memset(frmt_str, 0, 20);
	
	printf("Introduce la contrasenya: \n");

	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed(str);
	sscanf(str, "%s", frmt_str); //eliminar el \n final

	strcpy(a.contrasena, frmt_str);   /////////////////////////////////////La contrasenya se le asigna a ese nombre. Puede haber mas de una igual, por lo que no validamos que sea unica

	memset(str, 0, 20);
	memset(frmt_str, 0, 20);
		

	nump_aux=-1;

	if(num==-1)
  		num++;
  	
  	listan = (Personaje*)malloc((num+1) * sizeof(Personaje)); //////////////////Crear memoria para el array de personajes auxiliar

	for(int i=0;i<num;i++)
	{
		listan[i]=personajes[i];  /////////////////Copiamos todos los datos del array personaje al array listan
	}

	q=num;
	listan[num]=a;

	num++;

  }
  //Aqui acaba la opcion de crear un personaje






option=3;
  do 
	{
		menuPartida();

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%d", &option);

	}while((option!=1 && a.nump==-1 ) || (option!=2 && option!=1));


	if(option==1)///////////////////////////////////////////////Si escoge la opcion 1, empezamos en la posicion (0, 0)
	{
		a.x=0;
		a.y=0;
	}


	if(option==2)///////////////////////////////////////Si escoge la opcion 2, le mostraremos todas las partidas que tiene guardadas, si es que las hay
	{
		if(a.nump!=-1)
		{

			int i;
			for(i=0;i<=a.nump;i++)
			{
				printf("Intrdoduce %d para iniciar la partida en la que la posicion era (%d, %d)\n",i, a.a[i], a.b[i]);
				
			}
			
			do
			{
				printf("Introduce la partida que quieras cargar:\n");
				fgets(str, MAX_LENGTH, stdin);
				clear_if_needed(str);
				sscanf(str, "%d", &hola);

				if(hola>a.nump || hola<0)
					printf("No es una opcion valida.\n");

			}while(hola>a.nump || hola<0);

			xx=a.a[hola];
			yy=a.b[hola];
		}
		else
		{
			printf("No hay partidas que mostrar \n");

		}
		
	}


	char hist[2][2][20]; ///////////////////////////////////////////Esto es un array bidimensional de lo que en Java llamabamos Strings

	int o;
	int p;
	int mn=0;
	FILE* fd1;
  fd1 = fopen("historia.txt", "r"); ///////////////////////////////Ahora vamos a leer del fichero de texto
  char str2[20];
  char frmt_str2[20];
  while(fgets(str2, 20, fd1)) {
    int d;

    if(sscanf(str2, "%d", &d) == 0) {
      sscanf(str2, "%s", frmt_str2);
    }
    else 
    {
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
       	strncpy(hist[o][p], frmt_str2, 20);

    	memset(frmt_str2, 0, 20);
    }
    clear_if_needed(str2);

}
	fclose(fd1); ////////////////////////////Cerramos el fichero de texto



if(option=1)
{
	a.x=0;
	a.y=0;
}


	a.x=xx;
	a.y=yy;
	mapear(a.x,a.y);

	do
	{
		printf("Desplazate hasta abajo a la derecha usando 'w', 'a', 's', 'd' ('g' para guardar la partida).\n");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", frmt_str);

		
		memset(str, 0, 20);

		if (strcmp(frmt_str, "g") == 0)
		{
			int me;
			int cago;
			if(hola!=-2)
			{
				me=a.x;
				cago=a.y;
				listan[q].a[hola]=me;
				listan[q].b[hola]=cago;
				break;
			}
			else
			{
			nump_aux=nump_aux+1;

			a.a[nump_aux]=a.x;
			a.b[nump_aux]=a.y;

			listan[q].nump=nump_aux;
			listan[q].a[nump_aux]=a.x;
			listan[q].b[nump_aux]=a.y;
			strncpy(listan[q].contrasena, a.contrasena, 20);
			strncpy(listan[q].nombre, a.nombre, 20);

			listan[q].x=a.x;
			listan[q].y=a.y;

			break;
			}

		}

		if (strcmp(frmt_str, "w") == 0)
		{
			if(a.x==0)
			{
				printf("No se puede ir mas arriba.\n");
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
				printf("No se puede ir mas a la izquierda.\n");
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
				printf("No se puede ir mas a la derecha.\n");
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
				printf("No se puede ir mas abajo  \n");
			}
			else
			{
				a.x++;
			}
		}
		else
		{
			printf("Introduce una tecla valida.\n");
		}

		mapear(a.x,a.y);   ////////////////////////Renovamos el mapa una vez que haya introducido una tecla
		memset(frmt_str, 0, 20);

		if((a.x==2 && a.y==2) && hola!=-2)
		{
			int h=-2;
			for(int i=0;i<=nump_aux;i++)
			{

				if(hola==i)
				{
					h=hola;
				}
				else if(h!=-2)
				{
					listan[q].a[i-1]=listan[q].a[i];
					listan[q].b[i-1]=listan[q].b[i];
				}
			}
			listan[q].nump=nump_aux-1;

			strncpy(listan[q].contrasena, a.contrasena, 20);
			strncpy(listan[q].nombre, a.nombre, 20);

			listan[q].x=a.x;
			listan[q].y=a.y;
		}
	}while(!(a.x==2 && a.y==2));

	printf("El juego se ha acabado, Agur!\n");

	file = fopen("personajes.dat", "wb");
  

  	//escribir la cantidad de elementos
  	if(num==0)
  		num++;
  	fputc(num, file); 
  	//escribir datos binarios
  	fwrite(listan, sizeof(Personaje), num, file);
  
   	//cerrar fichero
  	fclose(file);

  	free(personajes);///////////////////////////////Liberar memoria del array personajes
  	free(listan); ///////////////////////////////Liberar memoria del array listan
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