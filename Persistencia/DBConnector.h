#ifndef DBCONNECTOR_H_
#define DBCONNECTOR_H_

#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
//PARA LA GESTION DEL TIEMPO EN LOS IDS:
#include <time.h>

#define TAMANYO_CONSULTA 250

class DBConnector
{
	private:
  		sqlite3 *db = NULL; //El pointer a nuestra base de datos.
  	public:
  		int db_build();
  		int insertarKarmaPersonaje(const char * personaje, int karma);
  		/*int showAllCountries();
  		int deleteAllCountry();
  		int insertNewCountry(std::string country);
  		int insertNewCountryID(int id, std::string name);
  		*/
  		DBConnector(std::string dbFile);
  		~DBConnector();
};

#endif