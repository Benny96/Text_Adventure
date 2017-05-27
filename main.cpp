#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
#include <vector>

#include "Personaje.h"

#include "clsPersonaje.h"
#include "Enemigo.h"
#include "Persistencia/DBConnector.h"


using namespace std;

#define TAMANYO_LINEA 80
#define CONSTANTE_PERSONAJE 100
#define FICHERO_BINARIO "personajes.dat"
#define FICHERO_HISTORIA "historia.txt"
#define FICHERO_BD "datos.bd"

void menu_personajes();
void menu_partidas();
void clear_if_needed(char *str);
void mapear(int x, int y, int ex, int ey);
int lucha (Enemigo &e, clsPersonaje &p);
void guardar(int num, vector <clsPersonaje> listan);
void mostrarEstadisticas (int num, DBConnector &dbConnector, vector <clsPersonaje> &clspersonajes);

int main (void)
{
	FILE * file;	
	int num;
	int inicializacion = 0;
	Personaje *personajes;
	int karma;
	int i;
	int q;
	clsPersonaje * a = new clsPersonaje();
	int option = -1;
	int nump_aux = -1;
	int hola=-2;
	
	int xx=0;
	int yy=0;

	char frmt_str[TAMANYO_CADENAS];

	DBConnector dbConnector(FICHERO_BD);
	int result = dbConnector.db_build();
	if (result != SQLITE_OK) 
	{
	  	cout << "Error creating table" << endl;
	  	return result;
	}
	//Proceso de lectura del archivo binario:
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
	if (num == -1)
	{
		num = INIT_PERSONAJES;
		inicializacion = 1;
	}
	if (inicializacion == 0 || file != NULL)
	{
		personajes = (Personaje*)malloc(num * sizeof(Personaje));	///////////////Reservar memoria para el array de personajes
		fread(personajes, sizeof(Personaje), num, file);  ///////////////////Pasar lainfo que hay en el fichero al array de personajes
	}
	
	//cerrar el fichero
	if (file != NULL)
	{
	fclose(file);
	}
	vector <clsPersonaje> clspersonajes;
	if (inicializacion == 1)
	{
		for (int i = 0; i < num; i++)
		{
			clsPersonaje * clasePers = new clsPersonaje();
			clspersonajes.push_back(*clasePers);
		}
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			clsPersonaje * clasePers = new clsPersonaje();	
			clasePers->setNombre(personajes[i].nombre);
			clasePers->setContrasena(personajes[i].contrasena);
			clasePers->setNump(personajes[i].nump);
			clasePers->setX(personajes[i].x);
			clasePers->setY(personajes[i].y);
			for (int j = 0; j < TAMANYO_PARTIDAS_PERSONAJE; j++)
			{
				clasePers->setA(j,personajes[i].a[j]);
				clasePers->setB(j,personajes[i].b[j]);
			}
			clspersonajes.push_back(*clasePers);
		}
	}
	vector <clsPersonaje> listan;
	if (inicializacion == 0)
		{
			for (int i = 0; i < num; i++)
			{
				listan.push_back(clspersonajes.at(i));
			}
		}
	if (inicializacion == 1)
	{
		num = -1;
	}
	cout << "Bienvenido" << endl;
	do 
	{
		option = 0;
		menu_personajes();

		cin >> option;
		if(!cin) // or if(cin.fail())
		{
		    cin.clear(); // reset failbit
		    cin.ignore(); //skip bad input
		    option = 0;
		    cout << "Mete un caracter valido" << endl;
		}
		else
		{
			if(num==-1 && option==2)
			{
				cout << "No hay personajes" << endl;
			}
			if (option == 3)
			{
				mostrarEstadisticas (num, dbConnector, clspersonajes);
			}
			if (option == 4)
			{
				cout << "Agur!" << endl;
				delete a;
				free(personajes);
				return 0;
			}
		if(option!=1 && option!=2 && option!=3 && option !=4)
			{
				cout << "Introduce una opcion valida" << endl;
			}
		}
	}
	while( (option!=1 && num==-1 ) || (option!=1 && option!=2) );

	//Aqui empieza la opcion de crear un personaje
	if(option==1)
	{
		cout << "Ha seleccionado crear un personaje." << endl;

		int aux = 0;
		do
		{
			aux = 0;
			cin >> *a;
			for(int i=0;i<num;i++)
			{
				q=i;
				if(strcmp(a->getNombre().c_str(), clspersonajes.at(i).getNombre().c_str())==0)   /////////////////////////////////Obligamos que introduzca un nombre inexistente en el sistema
				{	
					cout << "Este nombre de usuario ya existe, introduce otro." << endl;
					aux=1;
				}
			}
		}
		while(aux==1);
		

		a->setNump(-1);

		if(num==-1)
		{
  			num++;
		}
		listan.push_back(*a);
		q = num;
		num++;
  	}
  //Aqui acaba la opcion de crear un personaje

/*Aqui empieza la opcion de cargar un personaje*/
	if(option==2)
	{
		cout << "Ha seleccionado cargar un personaje." << endl;
		if(num!=0)
		{
			cout << "Estos son los nombres existentes en el sistema" << endl;
			//Un for que saque por pantalla los nombres existentes en el sistema.
			for (int i = 0; i < num; i++)
			{
				cout << clspersonajes.at(i);
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
				if(strcmp(frmt_str,clspersonajes.at(i).getNombre().c_str())==0) //////////////////////Validamos que exista ese nombre en el sistema
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
			if(strcmp(frmt_str,clspersonajes.at(q).getContrasena().c_str())!=0)
				{
					cout << "La contrasenya es incorrecta, introduce otra." << endl;
				}
		}
		while(strcmp(frmt_str,clspersonajes.at(q).getContrasena().c_str())!=0); ////////////////////////Tambien validamos que este introduciendo la contrasenya que le correspone a ese nombre
		*a=listan.at(q);
		nump_aux = listan.at(q).getNump();
	}
	//Aqui acaba la opcion de cargar un personaje

	option=3;
	do 
	{
		menu_partidas();
		cin >> option;
		if(!cin) // or if(cin.fail())
		{
		    cin.clear(); // reset failbit
		    cin.ignore(); //skip bad input
		    option = 0;
		    cout << "Mete un caracter valido" << endl;
		}
		else
		{
			if(a->getNump()==-1 && option==2)
			{
				cout << "No hay partidas guardadas" << endl;
			}
			if (option == 3)
			{
				cout << "Agur!" << endl;
				guardar (num, listan);
				delete a;
				free(personajes);
				return 0;
			}
			else if(option!=1 && option!=2 && option!=3)
			{
				cout << "Esta no es una opcion valida." << endl;
			}
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
				if(!cin) // or if(cin.fail())
				{
				    cin.clear(); // reset failbit
				    cin.ignore(); //skip bad input
				    hola = -2;
				    cout << "Mete un caracter valido" << endl;
				}
				else
				{
					if(hola>a->getNump() || hola<0)
					{
						cout << "No es una opcion valida." << endl;
					}
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

	//char **** hist = leerFicheroTexto();
	/*Bloque que se podría intentar mover*/
	
	char hist[TABLERO][TABLERO][80]; ///////////////////////////////////////////Esto es un array bidimensional de lo que en Java llamabamos Strings
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

	/*Fin del bloque*/

	if(option=1)
	{
		a->setX(0);
		a->setY(0);
	}
	a->setX(xx);
	a->setY(yy);

	int reputacion = 0;
	reputacion = dbConnector.recogerKarmaPersonaje(listan.at(q).getNombre());
	cout << "VALOR DE REPUTACION: " << reputacion << endl;

	 /* Inicializar semilla variable con respecto al tiempo: */
  	srand (time(NULL));
  	int enemposX;
  	int enemposY;
  	do
  	{
  		/* genera un número aleatorio entre 0 y 2, hasta que no se de el caso de una posición (0,0): */
  		enemposX = rand()%3;
  		enemposY = rand()%3;
  	}
  	while ((enemposX == 0 && enemposY == 0) || (enemposX == 2 && enemposY == 2));

		//////////////////////////////////////////////////////////////////////////////
  	Enemigo * e = new Enemigo (NOMBRE_DEL_MALO, enemposX, enemposY, -reputacion); 	//- reputacion hace que todo el Karma positivo acumulado por los anteriores personajes haga que la dificultad del enemigo sea mas baja.
  	//////////////////////////////////////////////////////////////////////////////


	mapear(a->getX(),a->getY(), e->getX(), e->getY());


  	
  	int haluchado = 0;
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
				if (e->getX()==a->getX() && e->getY()==a->getY() && haluchado == 0)
				{
					karma = lucha (*e, *a);
					haluchado = 1;
				}	
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
				if (e->getX()==a->getX() && e->getY()==a->getY() && haluchado == 0)
				{
					karma = lucha (*e, *a);
					haluchado = 1;
				}		
			}
		}
		else if(strcmp(frmt_str, "d") == 0)
		{
			if(a->getY()==(TABLERO-1))
			{
				cout << "No se puede ir mas a la derecha." << endl;
			}
			else
			{
				a->setY(a->getY()+1);
				if (e->getX()==a->getX() && e->getY()==a->getY() && haluchado == 0)
				{
					karma = lucha (*e, *a);
					haluchado = 1;
				}	
			}
		}
		else if(strcmp(frmt_str, "s") == 0)
		{
			if(a->getX()==(TABLERO-1))
			{
				cout << "No se puede ir mas abajo." << endl;
			}
			else
			{
				a->setX(a->getX()+1);
				if (e->getX()==a->getX() && e->getY()==a->getY() && haluchado == 0)
				{
					karma = lucha (*e, *a);
					haluchado = 1;
				}		
			}
		}
		else
		{
			cout << "Introduce una tecla valida." << endl;
		}


		mapear(a->getX(),a->getY(), e->getX(), e->getY());   ////////////////////////Renovamos el mapa una vez que haya introducido una tecla
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
	while(!(a->getX()==(TABLERO-1) && a->getY()==(TABLERO-1)));

	cout << "El juego se ha acabado. Agur!" << endl;

	if (haluchado == 1)
	{
		result = dbConnector.insertarKarmaPersonaje(listan.at(q).getNombre(), karma);
		if (result != SQLITE_OK) 
		{
			cout << "Error añadiendo el karma" << endl;
			return result;
		}
	}
	guardar (num, listan);
  	//for (int i = 0; i < TABLERO; i++)
  	//{
  	//	for (int j = 0; j < TABLERO; j++)
  	//	{
  	//		for (int k = 0; k < TAMANYO_LINEA; k++)
  	//		{
  	//			free(hist[i][j][k]);
  	//		}
  	//	}
  	//}
  	//for (int i = 0; i < TABLERO; i++)
  	//{
  	//	for (int j = 0; j < TABLERO; j++)
  	//	{
  	//		free(hist[i][j]);
  	//	}
  	//}
  	//for (int i = 0; i < TABLERO; i++)
  	//{
  	//	free(hist[i]);
  	//}
  	//free(hist);
	if (file != NULL)
	{
		free(personajes);
	}
  	delete e;
  	delete a;
  	clspersonajes.clear();
  	listan.clear();
	return 0;
}

void menu_personajes()
{
	cout << "Introduce:" << endl;
	cout << "1.- Crear un personaje." << endl;
	cout << "2.- Cargar un personaje." << endl;
	cout << "3.- Estadisticas de cada personaje." << endl;
	cout << "4.- Salir." << endl;
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
void mapear(int x, int y, int ex, int ey)
{
	for(int i=0;i<=TABLERO*ESPACIADO;i++)
	{
		for(int j=0;j<=TABLERO*ESPACIADO;j++)
		{
			
			if(j%ESPACIADO==0 || i%ESPACIADO==0)
				cout << "*";
			else
			{
				if(i==(ex*ESPACIADO +2) && j==(ey*ESPACIADO +2))
				{
					cout << "+";
				}
				else if (i==(ex*ESPACIADO +1) && j<(ey*ESPACIADO +2) && j>((ey*ESPACIADO)-1))
				{}
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
int lucha (Enemigo &e, clsPersonaje &p)
{	
	Persona* pers [2];
	pers[0] = &e;
	pers[1] = &p;
	cout << " Hay un enemigo (o amigo) en esta posicion. Deseas hablar con la persona?" << endl;
	cout << " Introduce 1 si quieres pegarte con el, y 2 si quieres ignorarlo." << endl;
	int aux = 0;
	do
	{
		aux = 0;
		cin >> aux;
		if(!cin) // or if(cin.fail())
		{
		    cin.clear(); // reset failbit
		    cin.ignore(); //skip bad input
		    aux = 3;
		    cout << "Mete un caracter valido" << endl;
		}
		else
		{
			if(aux == 1)
			{
				//AQUI DEBERIA SER LA LUCHA.
				for (int i = 0; i < 2; i++)
				{
					pers[i]->mostrarDatos();
				}
				srand (time(NULL));
				int valorPersona = rand()%CONSTANTE_PERSONAJE;
				int valorEnemigo = rand()%e.getDificultad();
				if (valorPersona > valorEnemigo)
				{
					cout << "Le has vapuleado wey, pero a la siguiente no te costara tan poco..." << endl;
					return -5; //DEVOLVEMOS EL KARMA QUE HA CONSEGUIDO 
				}
				if (valorPersona <= valorEnemigo)
				{
					cout << "Te han vapuleado wey, aunque a la siguiente tendra mas piedad contigo..." << endl;
					return 5; //DEVOLVEMOS EL KARMA QUE HA CONSEGUIDO
				}
			}
			if(aux == 2)
			{
				cout << "Puedes irte tranquilo... Pero todo tiene su coste." << endl;
				return -3;
			}
			if(aux != 1 && aux != 2)
			{
				cout << "Introduce una opcion valida" << endl;
			}
		}
	}
	while((aux != 1 && aux != 2)||(aux == 3));
}
void guardar(int num, vector <clsPersonaje> listan)
{
	FILE * file;
	Personaje * persaguardar;
	file = fopen(FICHERO_BINARIO, "wb");
  	//escribir la cantidad de elementos
  	if(num==0)
	{
  		num++;
	}
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
		strcpy(pers.nombre, listan.at(i).getNombre().c_str());
		strcpy(pers.contrasena, listan.at(i).getContrasena().c_str());
		persaguardar[i] = pers; 
	}
  	fwrite(persaguardar, sizeof(Personaje), num, file);
  	free(persaguardar);
   	//cerrar fichero
  	fclose(file);
}

void mostrarEstadisticas (int num, DBConnector &dbConnector, vector <clsPersonaje> &clspersonajes)
{
	if (num == -1)
	{
		cout << "No hay estadisticas que mostrar, al no haber personajes registrados." << endl;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			int * resultados = dbConnector.recogerDatosPersonaje(clspersonajes.at(i).getNombre());
			cout << "Personaje: " << clspersonajes.at(i).getNombre() << endl;
			if (resultados[CELDA_FINALIZADAS]==0)
			{
				cout << "Este personaje no ha finalizado ninguna partida." << endl;
			}
			else
			{
				cout << "\tNum. veces que ha vencido en combate: " << resultados[CELDA_VICTORIAS] << endl;
				cout << "\tNum. veces que ha caido en combate: " << resultados[CELDA_DERROTAS] << endl;
				cout << "\tNum. veces que ha huido del combate: " << resultados[CELDA_HUIDAS] << endl;
				cout << "\tNum. veces que ha finalizado (sin necesariamente haberse encontrado con el enemigo): " << resultados[CELDA_FINALIZADAS] << endl;
			}
			delete resultados;
			cout << endl;
		}
	}
}
	
