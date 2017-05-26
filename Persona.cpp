#include "Persona.h"
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

Persona::Persona()
{
	this->nombre = string(""); 
	this->x = 0;
	this->y = 0;
}

Persona::Persona(const string nombre, int x, int y)
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
