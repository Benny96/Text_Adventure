#ifndef DBCONNECTOR_H_
#define DBCONNECTOR_H_

#include <iostream>

class DBConnector
{
	private:
  		sqlite3 *db = NULL; //El pointer a nuestra base de datos.
  	public:
  		int showAllCountries();
  		int deleteAllCountry();
  		int insertNewCountry(std::string country);
  		int insertNewCountryID(int id, std::string name);
  		DBConnector(std::string dbFile);
  		~DBConnector();
}


#endif