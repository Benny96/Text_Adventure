#include "Persona.h"
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

Persona::Persona()
{
	cout << "constructor vacio Persona" << endl;
	this->nombre = string(""); 
}

Persona::Persona(const string nombre)
{
	this->nombre = nombre;
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

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}