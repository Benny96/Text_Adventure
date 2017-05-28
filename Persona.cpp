/**
 ** @Autores: 
 **
 ** Garikoitz Bereciartua (garibere13) 
 ** Imanol Echeverría (Echever) 
 ** Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** Implementar los métodos definidos en el archivo de cabecera Persona.h.
 */

#include "Persona.h"

using namespace std;

Persona::Persona()
{
	this->nombre = string(""); 
	this->x = 0;
	this->y = 0;
}
/*
No hemos añadido constructores copia debido a que no los necesitamos para el contexto de nuestra aplicación.
*/
Persona::Persona(string nombre, int x, int y)
{
	this->nombre = nombre;
	this->x = x;
	this->y = y;
}
/*
Al estar utilizando std::string, no necesitamos liberar ningun puntero. Con lo cual, el destructor tiene codigo vacio.
{LO HEMOS PUESTO A MODO ILUSTRATIVO}
*/
Persona::~Persona()
{}

string Persona::getNombre() const
{
	return nombre;
}
int Persona::getX() const
{
	return x;
}
int Persona::getY() const
{
	return y;
}
void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}
void Persona::setX(int x)
{
	this->x = x;
}
void Persona::setY(int y)
{
	this->y = y;
}
