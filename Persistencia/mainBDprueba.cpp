#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class DBConnector {

private:
  sqlite3 *db = NULL; //El pointer a nuestra base de datos.

public:
  int showAllCountries() {
    sqlite3_stmt *stmt; //Statement -> Lo necesitamos en todo momento.

    char sql[] = "select id, name from country"; //Una QUERY.

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; //El NULL final siempre es NULL.
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (SELECT)" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result; //Se propaga el error, devolviendo el entero.
    }

    std::cout << "SQL query prepared (SELECT)" << std::endl;

    int id;
    char name[100];

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Showing countries" << std::endl;

    //Para el resultado de la QUERY: Un do-while().
    //Step pasa por líneas de la QUERY SQL.
    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
	id = sqlite3_column_int(stmt, 0); //Para imprimir el ID.
	strcpy(name, (char *) sqlite3_column_text(stmt, 1)); //Para imprimir el Name.
	std::cout << "ID: " << id << " Name: " << name << std::endl;
      }
    } while (result == SQLITE_ROW);

    std::cout << std::endl;
    std::cout << std::endl;

    //Cómo se cierra la transacción: Commit - Rollback.
    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (SELECT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (SELECT)" << std::endl;

    return SQLITE_OK;
  }

  int deleteAllCountry() {
    sqlite3_stmt *stmt;

    char sql[] = "delete from country";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (DELETE)" << std::endl;

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (DELETE)" << std::endl;

    return SQLITE_OK;
  }

  int insertNewCountry(std::string country) {
    sqlite3_stmt *stmt;

    char sql[] = "insert into country (id, name) values (NULL, ?)"; //Signo de interrogación: El valor del país está por definir.
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout <<  sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (INSERT)" << std::endl;
    //Metemos el String que hemos dejado vacío.
    result = sqlite3_bind_text(stmt, 1, country.c_str(), country.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout <<  sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into country table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (INSERT)" << std::endl;

    return SQLITE_OK;
  }

  int insertNewCountryID(int id, std::string name) {
    sqlite3_stmt *stmt;

    char sql[] = "insert into country (id, name) values (?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (INSERT)" << std::endl;

    result = sqlite3_bind_int(stmt, 1, id);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, name.c_str(), name.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into country table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (INSERT)" << std::endl;

    return SQLITE_OK;
  }

  DBConnector(std::string dbFile) {
    //int result = sqlite3_open("test.sqlite", &db);
    int result = sqlite3_open(dbFile.c_str(), &db); //Gestión de errores con el retorno de los valores.
    if (result != SQLITE_OK) {
      std::cout << "Error opening database" << std::endl;

    }
  }

  ~DBConnector() {
    int result = sqlite3_close(db);
    if (result != SQLITE_OK) {
      std::cout << "Error opening database" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
    }	
  }
};

int main() {
  DBConnector dbConnector("test.sqlite");

  int result = dbConnector.deleteAllCountry();
  if (result != SQLITE_OK) {
    std::cout << "Error deleting all countries" << std::endl;
    return result;
  }

  result = dbConnector.insertNewCountry("France");
  if (result != SQLITE_OK) {
    std::cout << "Error inserting new data" << std::endl;
    return result;
  }

  result = dbConnector.insertNewCountryID(200, "France");
  if (result != SQLITE_OK) {
    std::cout << "Error inserting new data with id: 200. Already exists" << std::endl;
    return result;
  }

  result = dbConnector.showAllCountries();
  if (result != SQLITE_OK) {
    std::cout << "Error getting all countries" << std::endl;
    return result;
  }

  return 0;
}
