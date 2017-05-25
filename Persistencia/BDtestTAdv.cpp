#include "DBConnector.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

//INCLUDES PROVISIONALES, YA QUE TIENEN UN ORDEN ILOGICO, PUESTOS A MODO DE PRUEBA:

#include "../clsPersonaje.h"
#include "../Persona.h"
#include "../Enemigo.h"

using namespace std;

int main() 
{
  DBConnector dbConnector("test.sqlite");
  int result = dbConnector.db_build();
  if (result != SQLITE_OK) 
  {
    cout << "Error creating table" << endl;
    return result;
  }

  //vector <clsPersonaje> clspersonajes;

 // for (int i = 0; i < 5; i++)
  //{
  //    const char * nombre = "Pepito";
   //   clsPersonaje * a = new clsPersonaje (nombre, 0, 0, 0, "Elputoamo");
   //   clspersonajes.push_back(*a);
  //}
  //result = dbConnector.insertarKarmaPersonaje(clspersonajes.at(0).getNombre(), 1);
  result = dbConnector.insertarKarmaPersonaje("Pepito", 1);
   if (result != SQLITE_OK) 
  {
    cout << "Error añadiendo el karma" << endl;
    return result;
  }
  //result = dbConnector.insertarKarmaPersonaje(clspersonajes.at(1).getNombre(), -1);
  //result = dbConnector.insertarKarmaPersonaje("Pepito", -1);
    if (result != SQLITE_OK) 
  {
    cout << "Error añadiendo el karma" << endl;
    return result;
  }
  //result = dbConnector.deleteAllCountry();
  //if (result != SQLITE_OK) 
  //{
  //  cout << "Error deleting all countries" << endl;
  //  return result;
  //}

  //result = dbConnector.insertNewCountry("France");
  //if (result != SQLITE_OK) 
  //{
  //  cout << "Error inserting new data" << endl;
  //  return result;
  //}

  //result = dbConnector.insertNewCountryID(200, "France");
  //if (result != SQLITE_OK) 
  //{
  //  cout << "Error inserting new data with id: 200. Already exists" << endl;
  //  return result;
  //}

  //result = dbConnector.showAllCountries();
  //if (result != SQLITE_OK) 
  //{
  // cout << "Error getting all countries" << endl;
  //  return result;
  //}

  return 0;
}