/**
 ** @Autores: 
 **
 **	Garikoitz Bereciartua (garibere13) 
 **	Imanol Echeverría (Echever) 
 **	Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** DBConnector.h es el fichero de cabecera correspondiente a DBConnector.cpp, y esta clase se
 **	encargará de permitir la interacción con la Base de Datos de nuestro sistema.
 ** Esta BD la usamos, esencialmente, para hacer un recuento del karma de cada personaje. Para ello
 ** guardamos 3 tipos de dato por cada fila:
 **
 ** a) Un ID, generado a partir del tiempo de sistema.
 ** b) El nombre del jugador, que es único en el sistema.
 ** c) El Karma que ha generado en la partida, considerando su interacción con el enemigo. Esta celda
 ** puede tener los valores -5, -3, 0 o 5.
 */

#ifndef DBCONNECTOR_H_
#define DBCONNECTOR_H_

#include <stdio.h>
#include <string.h>
#include <time.h> //Para permitir la gestión del tiempo en los IDs.

#include <iostream>
#include <string>

#include "sqlite3.h"

using namespace std;

/**
 ** Constantes utilizadas para enviar los datos referentes a estadísticas de cada jugador.
 */

#define CELDA_VICTORIAS 0
#define CELDA_DERROTAS 1
#define CELDA_HUIDAS 2
#define CELDA_FINALIZADAS 3

/**
 ** Dirección del fichero de Base de Datos en el que se almacenarán los datos de cada jugador.
 */

#define FICHERO_BD "datos.bd"

class DBConnector
{
	private:
  		sqlite3 *db = NULL;
  	public:

  		/**
		 ** Método que se lanzará para crear la tabla KARMA (en caso de que no exista).
		 **
		 ** @Return:
		 **
		 ** Entero que representa un error de la Base de Datos, en caso de que lo hubiera.
		 */

  		int db_build();

  		/**
		 ** Método que insertará el Karma generado por un personaje determinado al acabar una partida.
		 **
		 ** @Param:
		 **
		 ** string personaje: Indica el nombre del personaje seleccionado.
		 ** int karma: Determina el valor de Karma que se ha adjudicado al acabar la partida.
		 **
		 ** @Return:
		 **
		 ** Entero que representa un error de la Base de Datos, en caso de que lo hubiera.
		 */

  		int insertarKarmaPersonaje(string personaje, int karma);

  		/**
		 ** Método que recogerá el Karma acumulado asociado a un personaje determinado.
		 **
		 ** @Param:
		 ** 
		 ** string personaje: Indica el nombre del personaje seleccionado.
		 **
		 ** @Return:
		 **
		 ** Entero que representa un error de la Base de Datos, en caso de que lo hubiera.
		 */

      	int recogerKarmaPersonaje(string personaje);

      	/**
		 ** Método que recogerá la cantidad de veces que ha vencido o ha caído contra el enemigo, así
		 ** como las veces que ha huido, y el número total de veces que ha finalizado las partidas.
		 **
		 ** @Param:
		 ** 
		 ** string personaje: Indica el nombre del personaje seleccionado.
		 **
		 ** @Return:
		 **
		 ** Puntero a enteros que representa el array de datos de un personaje seleccionado. 
		 ** También puede señalar un error de la Base de Datos en un puntero, en caso de que lo hubiera.
		 */

      	int* recogerDatosPersonaje(string personaje);

      	/**
		 ** Constructor de la clase DBConnector.
		 **
		 ** @Param:
		 ** 
		 ** string dbFile: Indica el nombre del fichero a utilizar para la Base de Datos.
		 */

  		DBConnector(string dbFile);

  		/**
		 ** Dirección del fichero de Base de Datos en el que se almacenarán los datos de cada jugador.
		 */

  		~DBConnector();
};

#endif