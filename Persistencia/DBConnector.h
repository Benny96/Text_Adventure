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

class DBConnector
{
	private:
  		sqlite3 *db = NULL; //El pointer a nuestra base de datos.
  	public:
  		int db_build();
  		int insertarKarmaPersonaje(string personaje, int karma);
      int recogerKarmaPersonaje(string personaje);
  		/*int showAllCountries();
  		int deleteAllCountry();
  		int insertNewCountry(std::string country);
  		int insertNewCountryID(int id, std::string name);
  		*/
  		DBConnector(std::string dbFile);
  		~DBConnector();
};

#endif