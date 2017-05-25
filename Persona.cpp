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
//Persona::Persona(const char* nombre)
//{
//	cout << "constructor normal persona" << endl;
//	this->nombre = new char[strlen(nombre) + 1];
//	strcpy(this->nombre, nombre);	
//}

Persona::Persona(const string nombre)
{
	cout << "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"  << endl;
	this->nombre = nombre;
	//this->nombre=new char[strlen(nombre.c_str())+1];
	//strcpy(this->nombre, nombre.c_str());
}

Persona::~Persona()
{
	cout << "destructor Persona" << endl;
	//delete[] nombre;
}

string Persona::getNombre() const
{
	//cout << nombre << endl;
	return nombre;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
	//this->nombre = new char[strlen(nombre) + 1];
	//strcpy(this->nombre, nombre);
}