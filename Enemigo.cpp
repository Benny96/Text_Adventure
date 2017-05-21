#include "Enemigo.h"

Enemigo::Enemigo(const char* nombre, int dificultad): Persona(nombre)
{
	this->dificultad = dificultad;
}

int Enemigo::getDificultad() const
{
	return dificultad;
}
void Personaje::mostrarDatos() const
{
	cout << "Posicion del personaje: (" << this->nombre <<","<<this->dificultad << ")" << endl;
}

