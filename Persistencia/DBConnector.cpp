/**
 ** @Autores: 
 **
 ** Garikoitz Bereciartua (garibere13) 
 ** Imanol Echeverría (Echever) 
 ** Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** Implementar los métodos definidos en el archivo de cabecera DBConnector.h.
 */

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
      return result;
    }
    return SQLITE_OK;
  }
  int DBConnector::insertarKarmaPersonaje(string personaje, int karma)
  {
    sqlite3_stmt *stmt;
    time_t id;
    id = time (NULL);
    char sql[] = "insert into KARMA (ID, NOMBRE, KARMA_PARTIDA) values (?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
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
    sqlite3_stmt *stmt;
    char sql[] = "select * from KARMA WHERE NOMBRE = ?";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (SELECT)" << endl;      
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }
    result = sqlite3_bind_text(stmt, 1  , personaje.c_str(), strlen(personaje.c_str())+1, SQLITE_STATIC);
    if (result != SQLITE_OK) 
    {
      cout << "Error binding parameters" << endl;
      cout << sqlite3_errmsg(db) << endl;
      return result;
    }
    int reputacion = 0;
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
    sqlite3_stmt *stmt;
    char sql[] = "select * from KARMA WHERE NOMBRE = ?";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) 
    {
      cout << "Error preparing statement (SELECT)" << endl;      
      cout << sqlite3_errmsg(db) << endl;
      int * resultpoint = new int;
      * resultpoint = result;
      return resultpoint;
    }
    result = sqlite3_bind_text(stmt, 1, personaje.c_str(), strlen(personaje.c_str())+1, SQLITE_STATIC);
    if (result != SQLITE_OK) 
    {
      cout << "Error binding parameters" << endl;
      cout << sqlite3_errmsg(db) << endl;
       int * resultpoint = new int;
        * resultpoint = result;
        return resultpoint;
    }
    int victorias = 0;
    int derrotas = 0;
    int huidas = 0;
    int finalizadas = 0;
    do 
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
          if (sqlite3_column_int(stmt,2)==-5)
          {
             victorias++; //Para acumular las victorias.
          } 
          if (sqlite3_column_int(stmt,2)==5)
          {
             derrotas++; //Para acumular las derrotas.
          }
          if (sqlite3_column_int(stmt,2)==-3)
          {
             huidas++; //Para acumular las partidas huidas.
          }
          finalizadas++; //Para acumular las partidas finalizadas.
      }
    }
    while (result == SQLITE_ROW);
    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      cout << "Error finalizing statement (SELECT)" << endl;
      cout << sqlite3_errmsg(db) << endl;
       int * resultpoint = new int;
      * resultpoint = result;
      return resultpoint;
    }
    int * informacion = new int [4];
    informacion[CELDA_VICTORIAS] = victorias;
    informacion[CELDA_DERROTAS] = derrotas;
    informacion[CELDA_HUIDAS] = huidas;
    informacion[CELDA_FINALIZADAS] = finalizadas;
    return informacion;
  }
  DBConnector::DBConnector(std::string dbFile) 
  {
    int result = sqlite3_open(dbFile.c_str(), &db);
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