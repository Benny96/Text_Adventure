#include "Personaje.h"
#include <string.h>
#include <iostream>

using namespace std;

Personaje::Personaje(): Persona()
{
	this->nump = 0;
	this->x = 0;
	this->y = 0;
	this->contrasena = new char[1];
}
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
int Personaje::getA(int pos) const
{
	return a[pos];
}
int Personaje::getB(int pos) const
{
	return b[pos];
}
char* Personaje::getContrasena() const
{
	return contrasena;
}
void Personaje::mostrarDatos() const
{
	cout << "Posicion del personaje: (" << this->x <<","<<this->y << ")" << endl;
}
void Personaje::setContrasena(char * contrasena)
{
	this->contrasena = new char[strlen(contrasena) + 1];
	strcpy(this->contrasena, contrasena);	
}
void Personaje::setNump(int nump)
{
	this->nump = nump;
}
void Personaje::setX(int x)
{
	this->x = x;
}
void Personaje::setY(int y)
{
	this->y = y;
}
void Personaje::setA(int pos, int valor)
{
	this->a[pos] = valor;
}
void Personaje::setB(int pos, int valor)
{
	//for (int i = 0; i < TAMANYO_PARTIDAS_PERSONAJE; i++)
	//{
	//	this->b[i] = b[i];
	//}
	this->b[pos] = valor;
}

