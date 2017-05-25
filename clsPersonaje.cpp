#include "Personaje.h"
#include "clsPersonaje.h"
#include <string.h>
#include <iostream>

using namespace std;

clsPersonaje::clsPersonaje(Personaje p): Persona(p.nombre)
{
		//cout << "AQUI PETAAAAAAAAAAAAAAA" << endl;
	cout << "personajeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" << endl;
	this->nump = p.nump;
	this->x = p.x;
	this->y = p.y;
	this->contrasena = new char[strlen(p.contrasena) + 1];
	strcpy(this->contrasena, p.contrasena);
	//PUEDE PETAR.
	for (int i = 0; i < TAMANYO_PARTIDAS_PERSONAJE; i++)
	{
		setA(i, 0;
		setB(i, 0);
	}
	//this->a = p.a;
	//this->b = p.b;
}
clsPersonaje::clsPersonaje(): Persona()
{
	cout << "constructor vacio clsPersonaje" << endl;
	this->nump = 0;
	this->x = 0;
	this->y = 0;
	this->contrasena = new char[1];
}
//Personaje::Personaje(const char* nombre, int nump, int x, int y, int *a, int *b, char* contrasena): Persona(nombre)
clsPersonaje::clsPersonaje(const char* nombre, int nump, int x, int y, char* contrasena): Persona(nombre)
{
	cout << "constructor con todo clsPersonaje" << endl;
	this->nump = nump;
	this->x = x;
	this->y = y;

	for(int i=0; i<TAMANYO_PARTIDAS_PERSONAJE; i++)
	{
		setA(i, p.a[i]);
		setB(i, p.b[i]);
	}
	//this->a = a;
	//this->b = b;

	this->contrasena = new char[strlen(contrasena) + 1];
	strcpy(this->contrasena, contrasena);	
}


clsPersonaje::~clsPersonaje()
{
	cout << "Destructor clsPersonaje" << endl;
	delete[] contrasena;
}



int clsPersonaje::getNump() const
{
	return nump;
}
int clsPersonaje::getX() const
{
	return x;
}
int clsPersonaje::getY() const
{
	return y;
}
int clsPersonaje::getA(int pos) const
{
	return a[pos];
}
int clsPersonaje::getB(int pos) const
{
	return b[pos];
}
char* clsPersonaje::getContrasena() const
{
	return contrasena;
}
void clsPersonaje::mostrarDatos() const
{
	cout << "Posicion del personaje: (" << this->x <<","<<this->y << ")" << endl;
}
void clsPersonaje::setContrasena(char * contrasena)
{
	this->contrasena = new char[strlen(contrasena) + 1];
	strcpy(this->contrasena, contrasena);	
}
void clsPersonaje::setNump(int nump)
{
	this->nump = nump;
}
void clsPersonaje::setX(int x)
{
	this->x = x;
}
void clsPersonaje::setY(int y)
{
	this->y = y;
}
void clsPersonaje::setA(int pos, int valor)
{
	this->a[pos] = valor;
}
void clsPersonaje::setB(int pos, int valor)
{
	//for (int i = 0; i < TAMANYO_PARTIDAS_PERSONAJE; i++)
	//{
	//	this->b[i] = b[i];
	//}
	this->b[pos] = valor;
}

