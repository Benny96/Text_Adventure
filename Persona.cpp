#include "Persona.h"
#include <string.h>
#include <iostream>

using namespace std;

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
	cout << "EEEEEEEEEEEEEEEEEEEEE" << endl;
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