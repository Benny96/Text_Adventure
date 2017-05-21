#include "Personaje.h"
#include <string.h>

//Personaje::Personaje(const char* nombre, int nump, int x, int y, int *a, int *b, char* contrasena): Persona(nombre)
Personaje::Personaje(const char* nombre, int nump, int x, int y, char* contrasena): Persona(nombre)
{
	this->nump = nump;
	this->x = x;
	this->y = y;
	//this->a = a;
	//this->b = b;

	this->contrasena = new char[strlen(contrasena) + 1];
	strcpy(this->contrasena, contrasena);	
}


Personaje::~Personaje()
{
	delete[] contrasena;
}



int Personaje::getNump() const
{
	return nump;
}
int Personaje::getX() const
{
	return x;
}
int Personaje::getY() const
{
	return y;
}
/*int* Personaje::getA() const
{
	return a;
}
int* Personaje::getB() const
{
	return b;
}*/
char* Personaje::getContrasena() const
{
	return contrasena;
}
void Personaje::mostrarDatos() const
{
	cout << "Posicion del personaje: (" << this->x <<","<<this->y << ")" << endl;
}

