#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

//#include <fstream.h>

#include "clsPersonaje.h"
#include "Personaje.h"
#include <vector>
//#include "Fichero.h"

using namespace std;

#define MAX_LENGTH 20
#define TABLERO 3
#define ESPACIADO 5
#define FICHERO_BINARIO "personajes.dat"
#define FICHERO_HISTORIA "historia.txt"
#define TAMANYO_LINEA 80
#define INIT_PERSONAJES 5

void menu_personajes();
void menu_partidas();
void clear_if_needed(char *str);
void mapear(int x, int y);

int main (void)
{
	FILE * file;	
	int num;
	int inicializacion;
	Personaje *personajes;
	Personaje *persaguardar;
	int i;
	int q;
	clsPersonaje * a = new clsPersonaje();
	int option = -1;
	int nump_aux = 0;
	int hola=-2;
	
	int xx=0;
	int yy=0;

	char str[MAX_LENGTH];
	char frmt_str[MAX_LENGTH];

	/*Proceso de lectura del archivo binario:*/
	file = fopen("personajes.dat", "rb");
	
	/*Obtenemos la cantidad de personajes guardados*/
	num = fgetc(file);

	if (num == 0)
	{
		//AÑADIR VARIABLE AUXILIAR PARA SABER QUE SE HA ENTRADO AQUI
		num = INIT_PERSONAJES;
		inicializacion = 1;
	}
	personajes = (Personaje*)malloc(num * sizeof(Personaje));	///////////////Reservar memoria para el array de personajes
	fread(personajes, sizeof(Personaje), num, file);  ///////////////////Pasar lainfo que hay en el fichero al array de personajes

	//cerrar el fichero
	fclose(file);

	vector <clsPersonaje> clspersonajes;
	cout << "AQUI PETA!!!!" << endl;
	for (int i = 0; i < num; i++)
	{
		clsPersonaje * clasePers = new clsPersonaje(personajes[i]);
		clspersonajes.push_back(*clasePers);
		delete clasePers;
	}

	vector <clsPersonaje> listan;
	for (int i = 0; i < num; i++)
	{
		clsPersonaje * clasePers = new clsPersonaje();
		listan.push_back(*clasePers);
		delete clasePers;
	}
	/*
	A modificar:
	Si se combina con un new de Personaje *personajes, puede que no haya problema.
	Pero para esto necesitamos un constructor...
	Personaje *personajes = leerFicheroPersonajes();
	*/
	if (inicializacion == 1)
	{
		num = -1;
	}
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
			//for (int i = 0; i < num; i++)
		  	//{
		  		//delete personajes[i];
		  		//delete listan[i];
		  	//}
			delete a;
			free(personajes);
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
				cout << clspersonajes.at(i).getNombre() << endl;
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
				if(strcmp(frmt_str,clspersonajes.at(i).getNombre())==0) //////////////////////Validamos que exista ese nombre en el sistema
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
			if(strcmp(frmt_str,clspersonajes.at(i).getContrasena())!=0)
				{
					cout << "La contrasenya es incorrecta, introduce otra." << endl;
				}
		}
		while(strcmp(frmt_str,clspersonajes.at(i).getContrasena())!=0); ////////////////////////Tambien validamos que este introduciendo la contrasenya que le correspone a ese nombre

		//listan = (Personaje*)malloc(num * sizeof(Personaje));
		//listan = new Personaje [num]; //////////////////Crear memoria para el array de personajes auxiliar

		for(int i=0;i<num;i++)
		{
			listan[i]=clspersonajes.at(i);   /////////////////Copiamos todos los datos del array personaje al array listan
		}
		//a=listan[q];
		nump_aux = listan.at(q).getNump();
	}
	//Aqui acaba la opcion de cargar un personaje

	//Aqui empieza la opcion de crear un personaje
	if(option==1)
	{
		cout << "Ha seleccionado crear un personaje." << endl;
		cout << "Introduce el nombre de tu personaje:" << endl; 
		int aux;
		char * aux2 = new char[MAX_LENGTH];
		q=-1;
		do
		{
			cin >> aux2;
			a-> setNombre(aux2);
			aux=0;
			for(int i=0;i<num;i++)
			{
				q=i;
				if(strcmp(a->getNombre(), clspersonajes.at(i).getNombre())==0)   /////////////////////////////////Obligamos que introduzca un nombre inexistente en el sistema
				{	
					cout << "Este nombre ya existe, introduce otro." << endl;
					aux=1;
				}
			}
		}
		while(aux==1);

		cout << "Introduce la contrasenya" << endl;
		char * contra = new char [MAX_LENGTH];
		cin >> contra;
		a-> setContrasena(contra); /////////////////////////////////////La contrasenya se le asigna a ese nombre. Puede haber mas de una igual, por lo que no validamos que sea unica
		nump_aux=-1;
		a->setNump(-1);

		if(num==-1)
		{
  			num++;
		}
		//listan = (Personaje*)malloc(num * sizeof(Personaje));
  		//listan = new Personaje [num];

		for(int i=0;i<num;i++)
		{
			listan.at(i)=clspersonajes.at(i);  /////////////////Copiamos todos los datos del array personaje al array listan
		}
		listan.push_back(*a);
		num++;
  	}
  //Aqui acaba la opcion de crear un personaje

	option=3;
	do 
	{
		menu_partidas();
		cin >> option;
		cout << "HOLAAAAAAAAAAAAAAA" << endl;
		if(a->getNump()==-1 && option==2)
		{
			cout << "No hay partidas guardadas" << endl;
		}
		if (option == 3)
		{
			cout << "Agur!" << endl;
			//for (int i = 0; i < num; i++)
		  	//{
		  		//delete personajes[i];
		  		//delete listan[i];
		  	//}
			delete a;
			free(personajes);
			return 0;
		}
		else if(option!=1 && option!=2 && option!=3)
		{
			cout << "Esta no es una opcion valida." << endl;
		}
	}
	while((option!=1 && a->getNump()==-1 ) || (option!=2 && option!=1));

	if(option==1)///////////////////////////////////////////////Si escoge la opcion 1, empezamos en la posicion (0, 0)
	{
		a->setX(0);
		a->setY(0);
	}

	if(option==2)///////////////////////////////////////Si escoge la opcion 2, le mostraremos todas las partidas que tiene guardadas, si es que las hay
	{
		if(a->getNump()!=-1)
		{
			int i;
			for(i=0;i<=a->getNump();i++)
			{
				cout << "Introduce " << i << " para iniciar la partida en la que la posicion era (" << a->getA(i) << ", " << a->getB(i) << ")" << endl;
			}		
			do
			{
				cout << "Introduce la partida que quieras cargar:" << endl;
				cin >> hola;
				if(hola>a->getNump() || hola<0)
				{
					cout << "No es una opcion valida." << endl;
				}
			}
			while(hola>a->getNump() || hola<0);
			xx=a->getA(hola);
			yy=a->getB(hola);
		}
		else
		{
			cout << "No hay partidas que mostrar" << endl;
		}
	}

	char hist[TABLERO][TABLERO][80]; ///////////////////////////////////////////Esto es un array bidimensional de lo que en Java llamabamos Strings
	//hist -> lecturaHistoria(hist);
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

	if(option=1)
	{
		a->setX(0);
		a->setY(0);
	}
	a->setX(xx);
	a->setY(yy);
	mapear(a->getX(),a->getY());
	do
	{
		cout << "Desplazate hasta abajo a la derecha usando 'w', 'a', 's', 'd' ('g' para guardar la partida)." << endl;
		cout << "Info de la casilla (" << a->getX() << ", "<< a->getY() << "): " << hist[a->getX()][a->getY()] << endl;
		cin >> frmt_str;
		if (strcmp(frmt_str, "g") == 0)
		{
			int me;
			int cago;
			if(hola!=-2)
			{
				me=a->getX();
				cago=a->getY();
				listan.at(q).setA(hola, me);
				listan.at(q).setB(hola, cago);
				break;
			}
			else
			{
				nump_aux=nump_aux+1;
				a->setA(nump_aux, a->getX());
				a->setB(nump_aux, a->getY());
				listan.at(q).setNump(nump_aux);
				listan.at(q).setA(nump_aux, a->getX());
				listan.at(q).setB(nump_aux, a->getY());
				listan.at(q).setContrasena(a->getContrasena());
				listan.at(q).setNombre(a->getNombre());
				listan.at(q).setX(a->getX());
				listan.at(q).setY(a->getY());
				break;
			}
		}
		if (strcmp(frmt_str, "w") == 0)
		{
			if(a->getX()==0)
			{
				cout << "No se puede ir mas arriba." << endl;
			}
			else
			{
				a->setX(a->getX()-1);
			}
		}
		else if(strcmp(frmt_str, "a") == 0)
		{
			if(a->getY()==0)
			{
				cout << "No se puede ir mas a la izquierda." << endl;
			}
			else
			{
				a->setY(a->getY()-1);
			}
		}
		else if(strcmp(frmt_str, "d") == 0)
		{
			if(a->getY()==2)
			{
				cout << "No se puede ir mas a la derecha." << endl;
			}
			else
			{
				a->setY(a->getY()+1);
			}
		}
		else if(strcmp(frmt_str, "s") == 0)
		{
			if(a->getX()==2)
			{
				cout << "No se puede ir mas abajo." << endl;
			}
			else
			{
				a->setX(a->getX()+1);
			}
		}
		else
		{
			cout << "Introduce una tecla valida." << endl;
		}

		mapear(a->getX(),a->getY());   ////////////////////////Renovamos el mapa una vez que haya introducido una tecla

		if((a->getX()==(TABLERO-1) && a->getY()==(TABLERO-1)) && hola!=-2)
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
					listan.at(q).setA(i-1, listan.at(q).getA(i));
					listan.at(q).setB(i-1, listan.at(q).getB(i));
				}
			}
			listan.at(q).setNump(nump_aux-1);
			listan.at(q).setContrasena(a->getContrasena());
			listan.at(q).setNombre(a->getNombre());
			listan.at(q).setX(a->getX());
			listan.at(q).setY(a->getY());
		}
	}
	while(!(a->getX()==2 && a->getY()==2));
	cout << "El juego se ha acabado. Agur!" << endl;
	file = fopen(FICHERO_BINARIO, "wb");
  
  	//escribir la cantidad de elementos
  	if(num==0)
  		num++;
  	fputc(num, file);
  	//escribir datos binarios
	persaguardar = (Personaje*)malloc(num * sizeof(Personaje));
	for (int i = 0; i < num; i++)
	{
		Personaje pers;
		pers.nump = listan.at(i).getNump(); 
		pers.x = listan.at(i).getX(); 
		pers.y = listan.at(i).getY();
		for (int j = 0; j < TAMANYO_PARTIDAS_PERSONAJE; j++)
		{
			pers.a[j] = listan.at(i).getA(j);
			pers.b[j] = listan.at(i).getB(j);
		}
		pers.nombre = listan.at(i).getNombre();
		//pers.nombre = new char[strlen(listan.at(i).getNombre().c_str()) + 1];
		pers.nombre = new char[strlen(listan.at(i).getNombre()) + 1];
		strcpy(pers.nombre, listan.at(i).getNombre());	
		//pers.contrasena = new char[strlen(listan.at(i).getContrasena().c_str()) + 1];
		pers.contrasena = new char[strlen(listan.at(i).getContrasena()) + 1];
		strcpy(pers.contrasena, listan.at(i).getContrasena());
		persaguardar[i] = pers; 
	}
  	fwrite(persaguardar, sizeof(Personaje), num, file);
  
   	//cerrar fichero
  	fclose(file);

  	free(persaguardar);
  	free(personajes);
  	delete a;
  	//delete[] listan;
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