#include "Persona.h"
#include <string.h>

Persona::Persona()
{
	this->nombre = new char[1]; 
}
Persona::Persona(const char* nombre)
{
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);	
}

Persona::~Persona()
{
	delete[] nombre;
}

char* Persona::getNombre() const
{
	return nombre;
}

void Persona::setNombre(char* nombre)
{
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
}