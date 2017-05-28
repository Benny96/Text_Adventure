#ifndef DBCONNECTOR_H_
#define DBCONNECTOR_H_

#include <stdio.h>
#include <string.h>
//PARA LA GESTION DEL TIEMPO EN LOS IDS:
#include <time.h>

#include <iostream>
#include <string>

#include "sqlite3.h"

using namespace std;

#define TAMANYO_CONSULTA 250
#define CELDA_VICTORIAS 0
#define CELDA_DERROTAS 1
#define CELDA_HUIDAS 2
#define CELDA_FINALIZADAS 3
#define FICHERO_BD "datos.bd"

class DBConnector
{
	private:
  		sqlite3 *db = NULL;
  	public:
  		int db_build();
  		int insertarKarmaPersonaje(string personaje, int karma);
      int recogerKarmaPersonaje(string personaje);
      int* recogerDatosPersonaje(string personaje);
  		DBConnector(std::string dbFile);
  		~DBConnector();
};

#endif