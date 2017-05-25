#include "Enemigo.h"

#include <iostream>
using namespace std;


Enemigo::Enemigo():Persona()
{
	this->dificultad = 0;
}
Enemigo::Enemigo(const string nombre, int dificultad): Persona(nombre)
{
	this->dificultad = dificultad;
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


