/**
 ** @Autores: 
 **
 ** Garikoitz Bereciartua (garibere13) 
 ** Imanol Echeverría (Echever) 
 ** Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** Implementar los métodos definidos en el archivo de cabecera Enemigo.h.
 */

#include "Enemigo.h"

using namespace std;

Enemigo::Enemigo():Persona()
{
	this->dificultad = NIVEL_DIFICULTAD;
}
Enemigo::Enemigo(string nombre, int x, int y, int dificultad): Persona(nombre, x, y)
{
	this->dificultad = NIVEL_DIFICULTAD + dificultad;
}

int Enemigo::getDificultad() const
{
	return dificultad;
}
void Enemigo::mostrarDatos() const
{
	cout << "Datos del enemigo:" << endl;
	cout << "\tNombre: " << this->nombre << endl;
	cout << "\tDificultad: " << this-> dificultad << endl;  
}