#include "DBConnector.h"

using namespace std;

  int DBConnector::db_build()
  {
    sqlite3_stmt *stmt;

     int result;
     char sql[] = "CREATE TABLE IF NOT EXISTS KARMA("
           "ID INT PRIMARY KEY NOT NULL,"
           "NOMBRE TEXT NOT NULL,"
           "KARMA_PARTIDA INT NOT NULL);";

     result = sqlite3_exec(db, sql, NULL, NULL, NULL);
      if (result != SQLITE_OK) 
      {
        cout << "Error preparing statement (SELECT)" << endl;      
        cout << sqlite3_errmsg(db) << endl;
        return result; //Se propaga el error, devolviendo el entero.
      }
     return SQLITE_OK;
  }
    int DBConnector::insertarKarmaPersonaje(string personaje, int karma)
  {
    sqlite3_stmt *stmt;

    time_t id;
    id = time (NULL);

    char sql[] = "insert into KARMA (ID, NOMBRE, KARMA_PARTIDA) values (?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (INSERT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }
     cout << "SQL query prepared (INSERT)" << endl;

     //PUEDE PETAR; NO SE SI ES INT O NO.
     result = sqlite3_bind_int(stmt, 1, id);
    if (result != SQLITE_OK)
    {
      cout << "Error binding parameters" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, personaje.c_str(), strlen(personaje.c_str())+1, SQLITE_STATIC);
    if (result != SQLITE_OK) 
    {
      cout << "Error binding parameters" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }
    result = sqlite3_bind_int(stmt, 3, karma);
    if (result != SQLITE_OK)
    {
      cout << "Error binding parameters" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }
    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) 
    {
      cout << "Error inserting new data into KARMA table" << endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      cout << "Error finalizing statement (INSERT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    cout << "Prepared statement finalized (INSERT)" << endl;

    return SQLITE_OK;
  }
  int DBConnector::recogerKarmaPersonaje(string personaje)
  {
    sqlite3_stmt *stmt; //Statement -> Lo necesitamos en todo momento.

    string sql = "select * from KARMA;";

   // string sql1 = "select KARMA_PARTIDA from KARMA where NOMBRE = '";
   // string sql2 = personaje;
   // string sql3 = "';";
   // string sql = sql1 + sql2 + sql3;

    //char sql[] = "select KARMA_PARTIDA from KARMA where NOMBRE = ?;"; //Una QUERY.

    int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) ; //El NULL final siempre es NULL.
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (SELECT)" << endl;      
      cout << sqlite3_errmsg(db) << endl;
      return result; //Se propaga el error, devolviendo el entero.
    }

    cout << "SQL query prepared (SELECT)" << endl;

 //  result = sqlite3_bind_text(stmt, 1  , personaje.c_str(), strlen(personaje.c_str())+1, SQLITE_STATIC);
 //  if (result != SQLITE_OK) 
 //  {
 //    cout << "Error binding parameters" << endl;
 //    cout << sqlite3_errmsg(db) << endl;
 //    return result;
 //  }
    int reputacion = 0;

    //Para el resultado de la QUERY: Un do-while().
    //Step pasa por líneas de la QUERY SQL.
    //result = sqlite3_step(stmt);
    do 
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
          cout << reputacion << endl;
          reputacion += sqlite3_column_int(stmt, 2); //Para acumular la reputacion.
      }
    }
    while (result == SQLITE_ROW);

    //Cómo se cierra la transacción: Commit - Rollback.
    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      cout << "Error finalizing statement (SELECT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }
    cout << "Prepared statement finalized (SELECT)" << endl;

    return reputacion;
  }
  /*int DBConnector::showAllCountries() 
  {
    sqlite3_stmt *stmt; //Statement -> Lo necesitamos en todo momento.

    char sql[] = "select id, name from country"; //Una QUERY.

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; //El NULL final siempre es NULL.
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (SELECT)" << endl;      
      cout << sqlite3_errmsg(db) << endl;
      return result; //Se propaga el error, devolviendo el entero.
    }

    cout << "SQL query prepared (SELECT)" << endl;

    int id;
    char name[100];

    cout << endl;
    cout << endl;
    cout << "Showing countries" << endl;

    //Para el resultado de la QUERY: Un do-while().
    //Step pasa por líneas de la QUERY SQL.
    do 
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
        	id = sqlite3_column_int(stmt, 0); //Para imprimir el ID.
        	strcpy(name, (char *) sqlite3_column_text(stmt, 1)); //Para imprimir el Name.
        	cout << "ID: " << id << " Name: " << name << endl;
      }
    }
    while (result == SQLITE_ROW);

    cout << endl;
    cout << endl;

    //Cómo se cierra la transacción: Commit - Rollback.
    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      cout << "Error finalizing statement (SELECT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    cout << "Prepared statement finalized (SELECT)" << endl;

    return SQLITE_OK;
  }

  int DBConnector::deleteAllCountry() 
  {
    sqlite3_stmt *stmt;

    char sql[] = "delete from country";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (DELETE)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    cout << "SQL query prepared (DELETE)" << endl;

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) 
    {
      cout << "Error deleting data (DELETE)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      cout << "Error finalizing statement (DELETE)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    cout << "Prepared statement finalized (DELETE)" << endl;

    return SQLITE_OK;
  }

  int DBConnector::insertNewCountry(std::string country) 
  {
    sqlite3_stmt *stmt;

    char sql[] = "insert into country (id, name) values (NULL, ?)"; //Signo de interrogación: El valor del país está por definir.
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      cout << "Error preparing statement (INSERT)" << endl;
      cout <<  sqlite3_errmsg(db) << endl;
      return result;
    }

    cout << "SQL query prepared (INSERT)" << endl;
    //Metemos el String que hemos dejado vacío.
    result = sqlite3_bind_text(stmt, 1, country.c_str(), country.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) 
    {
      cout << "Error binding parameters" << endl;
      cout <<  sqlite3_errmsg(db) << endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      cout << "Error inserting new data into country table" << endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      cout << "Error finalizing statement (INSERT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    cout << "Prepared statement finalized (INSERT)" << endl;

    return SQLITE_OK;
  }*/
  /*
  int DBConnector::insertNewCountryID(int id, std::string name) {
    sqlite3_stmt *stmt;

    char sql[] = "insert into country (id, name) values (?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (INSERT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    cout << "SQL query prepared (INSERT)" << endl;

    result = sqlite3_bind_int(stmt, 1, id);
    if (result != SQLITE_OK)
    {
      cout << "Error binding parameters" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, name.c_str(), name.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) 
    {
      cout << "Error binding parameters" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) 
    {
      cout << "Error inserting new data into country table" << endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      cout << "Error finalizing statement (INSERT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }

    cout << "Prepared statement finalized (INSERT)" << endl;

    return SQLITE_OK;
  }
  */
  DBConnector::DBConnector(std::string dbFile) 
  {
    //int result = sqlite3_open("test.sqlite", &db);
    int result = sqlite3_open(dbFile.c_str(), &db); //Gestión de errores con el retorno de los valores.
    if (result != SQLITE_OK) 
    {
      cout << "Error opening database" << endl;
    }
  }

  DBConnector::~DBConnector() 
  {
    int result = sqlite3_close(db);
    if (result != SQLITE_OK) 
    {
      cout << "Error opening database" << endl;
      cout << sqlite3_errmsg(db) << endl;
    }	
  }