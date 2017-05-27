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
    return SQLITE_OK;
  }
  int DBConnector::recogerKarmaPersonaje(string personaje)
  {
    sqlite3_stmt *stmt; //Statement -> Lo necesitamos en todo momento.

    char sql[] = "select * from KARMA WHERE NOMBRE = ?";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; //El NULL final siempre es NULL.
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (SELECT)" << endl;      
      cout << sqlite3_errmsg(db) << endl;
      return result; //Se propaga el error, devolviendo el entero.
    }

  result = sqlite3_bind_text(stmt, 1  , personaje.c_str(), strlen(personaje.c_str())+1, SQLITE_STATIC);
  if (result != SQLITE_OK) 
  {
    cout << "Error binding parameters" << endl;
    cout << sqlite3_errmsg(db) << endl;
    return result;
  }
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
    return reputacion;
  }
    int* DBConnector::recogerDatosPersonaje(string personaje)
  {
    sqlite3_stmt *stmt; //Statement -> Lo necesitamos en todo momento.

    char sql[] = "select * from KARMA WHERE NOMBRE = ?";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; //El NULL final siempre es NULL.
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (SELECT)" << endl;      
      cout << sqlite3_errmsg(db) << endl;
      int * resultpoint = new int;
      * resultpoint = result;
      return resultpoint; //Se propaga el error, devolviendo el entero.
    }

  result = sqlite3_bind_text(stmt, 1  , personaje.c_str(), strlen(personaje.c_str())+1, SQLITE_STATIC);
  if (result != SQLITE_OK) 
  {
    cout << "Error binding parameters" << endl;
    cout << sqlite3_errmsg(db) << endl;
     int * resultpoint = new int;
      * resultpoint = result;
      return resultpoint; //Se propaga el error, devolviendo el entero.
  }
    int victorias = 0;
    int derrotas = 0;
    int huidas = 0;
    int finalizadas = 0;
    //Para el resultado de la QUERY: Un do-while().
    //Step pasa por líneas de la QUERY SQL.
    //result = sqlite3_step(stmt);
    do 
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
          if (sqlite3_column_int(stmt,2)==-5)
          {
             victorias++;
          } //Para acumular la reputacion.
          if (sqlite3_column_int(stmt,2)==5)
          {
             derrotas++;
          } //Para acumular la reputacion.
          if (sqlite3_column_int(stmt,2)==-3)
          {
             huidas++;
          } //Para acumular la reputacion.
          finalizadas++;
      }
    }
    while (result == SQLITE_ROW);

    //Cómo se cierra la transacción: Commit - Rollback.
    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      cout << "Error finalizing statement (SELECT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
       int * resultpoint = new int;
      * resultpoint = result;
      return resultpoint; //Se propaga el error, devolviendo el entero.
    }
    int * informacion = new int [4];
    informacion[CELDA_VICTORIAS] = victorias;
    informacion[CELDA_DERROTAS] = derrotas;
    informacion[CELDA_HUIDAS] = huidas;
    informacion[CELDA_FINALIZADAS] = finalizadas;
    return informacion;
  }
  /*/*

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