#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

#include "Personaje.h"
#include "Fichero.h"

using namespace std;

#define MAX_LENGTH 20
#define TABLERO 3
#define ESPACIADO 5

void menu_personajes();
void menu_partidas();
void clear_if_needed(char *str);
void mapear(int x, int y);

int main (void)
{
	/*Inicializamos una serie de variables que usaremos en nuestro main:
		FILE * file: Puntero que nos permitirá gestionar el fichero binario "personajes.dat".
		num: int que nos permitirá guardar el número de personajes que hay en el fichero binario.
		Personaje *personajes: Array/puntero de personajes.
		Personaje *listan: Array de personajes en el que se volcarán los datos a la hora de guardar.

		i, q, a, option, nump_aux, hola, xx e yy: Variables auxiliares que utilizaremos a lo largo
		del programa.
	*/
	FILE * file;	
	int num;
	Personaje *listan;
	int i;
	int q;
	Personaje a;
	int option = -1;
	int nump_aux = 0;
	int hola=-2;
	
	int xx=0;
	int yy=0;

	char frmt_str[MAX_LENGTH];

	/*Proceso de lectura del archivo binario:*/
	file = fopen(FICHERO_BINARIO, "rb");
	
	/*Obtenemos la cantidad de personajes guardados*/
	num = fgetc(file);

	if (num == 0)
	{
		num = INIT_PERSONAJES;
	}
	
	//Personaje * personajes = (Personaje*)malloc(num * sizeof(Personaje));	///////////////Reservar memoria para el array de personajes
	Personaje * personajes = new Personaje [num * sizeof(Personaje)];
	fread(personajes, sizeof(Personaje), num, file);  ///////////////////Pasar la info que hay en el fichero al array de personajes

	//cerrar el fichero
	fclose(file);

	/*
	A modificar:
	Si se combina con un new de Personaje *personajes, puede que no haya problema.
	Pero para esto necesitamos un constructor...
	Personaje *personajes = leerFicheroPersonajes();
	*/

	cout << "Bienvenido" << endl;
	do 
	{
		menu_personajes();
		cin >> option;
		if(num==-1 && option==2)
		{
			cout << "No hay personajes" << endl;
		}
		if (option == 3)
		{
			cout << "Agur!" << endl;
			delete [] personajes;
			return 0;
		}
		if(option!=1 && option!=2 && option!=3)
		{
			cout << "Introduce una opcion valida" << endl;
		}
	}
	while( (option!=1 && num==-1 ) || (option!=2 && option!=1) );

	//Aqui empieza la opcion de cargar un personaje
	if(option==2)
	{
		cout << "Ha seleccionado cargar un personaje." << endl;
		if(num!=0)
		{
			cout << "Estos son los nombres existentes en el sistema" << endl;
			//Un for que saque por pantalla los nombres existentes en el sistema.
			for (int i = 0; i < num; i++)
			{
				cout << personajes[i].nombre << endl;
			}
		}	
		cout << "Introduce el nombre de tu personaje" << endl;
		int aux;
		q=-1;
		do
		{
			cin >> frmt_str;
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
			{
				cout << "El nombre no existe, introduce otro." << endl;
			}
		}
		while(aux!=1);

		cout << "Introduce tu contrasenya:" << endl;
		do
		{
			cin >> frmt_str;
			if(strcmp(frmt_str,personajes[q].contrasena)!=0)
				{
					cout << "La contrasenya es incorrecta, introduce otra." << endl;
				}
		}
		while(strcmp(frmt_str,personajes[q].contrasena)!=0); ////////////////////////Tambien validamos que este introduciendo la contrasenya que le correspone a ese nombre

		listan = new Personaje [num*sizeof(Personaje)]; //////////////////Crear memoria para el array de personajes auxiliar

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
		cout << "Ha seleccionado crear un personaje." << endl;
		cout << "Introduce el nombre de tu personaje:" << endl; 
		int aux;
		q=-1;
		do
		{
			cin >> a.nombre;
			aux=0;
			for(int i=0;i<num;i++)
			{
				q=i;
				if(strcmp(a.nombre,personajes[i].nombre)==0)   /////////////////////////////////Obligamos que introduzca un nombre inexistente en el sistema
				{	
					cout << "Este nombre ya existe, introduce otro." << endl;
					aux=1;
				}
			}
		}
		while(aux==1);

		cout << "Introduce la contrasenya" << endl;
		cin >> a.contrasena; /////////////////////////////////////La contrasenya se le asigna a ese nombre. Puede haber mas de una igual, por lo que no validamos que sea unica
		nump_aux=-1;
		a.nump=-1;

		if(num==-1)
		{
  			num++;
		}
  		listan = new Personaje [num*sizeof(Personaje)];

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
		menu_partidas();
		cin >> option;
		if(a.nump==-1 && option==2)
		{
			cout << "No hay partidas guardadas" << endl;
		}
		if (option == 3)
		{
			cout << "Agur!" << endl;
			delete [] listan;
			delete [] personajes;
			return 0;
		}
		else if(option!=1 && option!=2 && option!=3)
		{
			cout << "Esta no es una opcion valida." << endl;
		}
	}
	while((option!=1 && a.nump==-1 ) || (option!=2 && option!=1));

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
				cout << "Introduce " << i << " para iniciar la partida en la que la posicion era (" << a.a[i] << ", " << a.b[i] << ")" << endl;
			}		
			do
			{
				cout << "Introduce la partida que quieras cargar:" << endl;
				cin >> hola;
				if(hola>a.nump || hola<0)
				{
					cout << "No es una opcion valida." << endl;
				}
			}
			while(hola>a.nump || hola<0);
			xx=a.a[hola];
			yy=a.b[hola];
		}
		else
		{
			cout << "No hay partidas que mostrar" << endl;
		}
	}

	char hist[TABLERO][TABLERO][80]; ///////////////////////////////////////////Esto es un array bidimensional de lo que en Java llamabamos Strings
	int o;
	int p;
	int mn=0;
	FILE* fd1;
	fd1 = fopen("historia.txt", "r"); ///////////////////////////////Ahora vamos a leer del fichero de texto
	char str2[80];
	char frmt_str2[80];
	while(fgets(str2, 80, fd1)) 
	{
    	int d;
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
	       	strncpy(hist[o][p], frmt_str2, 80);
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
		cout << "Desplazate hasta abajo a la derecha usando 'w', 'a', 's', 'd' ('g' para guardar la partida)." << endl;
		cout << "Info de la casilla (" << a.x << ", "<< a.y << "): " << hist[a.x][a.y] << endl;
		cin >> frmt_str;
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
				cout << "No se puede ir mas arriba." << endl;
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
				cout << "No se puede ir mas a la izquierda." << endl;
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
				cout << "No se puede ir mas a la derecha." << endl;
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
				cout << "No se puede ir mas abajo." << endl;
			}
			else
			{
				a.x++;
			}
		}
		else
		{
			cout << "Introduce una tecla valida." << endl;
		}

		mapear(a.x,a.y);   ////////////////////////Renovamos el mapa una vez que haya introducido una tecla

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
	}
	while(!(a.x==2 && a.y==2));
	cout << "El juego se ha acabado. Agur!" << endl;
	file = fopen(FICHERO_BINARIO, "wb");
  
  	//escribir la cantidad de elementos
  	if(num==0)
  		num++;
  	fputc(num, file);
  	//escribir datos binarios
  	fwrite(listan, sizeof(Personaje), num, file);
  
   	//cerrar fichero
  	fclose(file);

  	delete[] personajes;
  	delete[] listan;
	return 0;
}

void menu_personajes()
{
	cout << "Introduce:" << endl;
	cout << "1.- Crear un personaje." << endl;
	cout << "2.- Cargar un personaje." << endl;
	cout << "3.- Salir." << endl;
}
void menu_partidas()
{
	cout << "Introduce:" << endl;
	cout << "1.- Comenzar una partida nueva" << endl;
	cout << "2.- Cargar una partida existente." << endl;
	cout << "3.- Salir." << endl;
}

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}
void mapear(int x, int y)
{
	for(int i=0;i<=TABLERO*ESPACIADO;i++)
	{
		
		for(int j=0;j<=TABLERO*ESPACIADO;j++)
		{
			
			if(j%ESPACIADO==0 || i%ESPACIADO==0)
				cout << "*";
			else
			{
				if(i==(x*ESPACIADO +2) && j==(y*ESPACIADO +2))
				{
					cout << "Tu";
				}
				else if (i==(x*ESPACIADO +2) && j<(y*ESPACIADO +2) && j>((y*ESPACIADO)-1))
				{}
				else
					cout << " ";
			}	
		}
		cout << endl;
	}
}