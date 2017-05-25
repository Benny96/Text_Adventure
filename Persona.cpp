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

Persona::~Persona()
{
	cout << "destructor Persona" << endl;
}

string Persona::getNombre() const
{
	return nombre;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}