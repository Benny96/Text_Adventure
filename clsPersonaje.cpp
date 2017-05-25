#include "Personaje.h"
#include "clsPersonaje.h"
#include <string.h>
#include <iostream>

using namespace std;

clsPersonaje::clsPersonaje(Personaje *p): Persona(string(p->nombre))
{
	this->nump = p->nump;
	this->x = p->x;
	this->y = p->y;

	this->contrasena = string(p->contrasena);
	for (int i = 0; i < TAMANYO_PARTIDAS_PERSONAJE; i++)
	{
		setA(i, p->a[i]);
		setB(i, p->b[i]);
	}
}
clsPersonaje::clsPersonaje(): Persona()
{
	cout << "constructor vacio clsPersonaje" << endl;
	this->nump = 0;
	this->x = 0;
	this->y = 0;
	
	this->contrasena = string("");
}
clsPersonaje::clsPersonaje(string nombre, int nump, int x, int y, string contrasena): Persona(nombre)
{
	cout << "constructor con todo clsPersonaje" << endl;
	this->nump = nump;
	this->x = x;
	this->y = y;
	for(int i=0; i<TAMANYO_PARTIDAS_PERSONAJE; i++)
	{
		setA(i, 0);
		setB(i, 0);
	}
	this->contrasena = contrasena;
}
/*
Al estar utilizando std::string, no necesitamos liberar ningun puntero. Con lo cual, el destructor tiene codigo vacio.
{LO HEMOS PUESTO A MODO ILUSTRATIVO}
*/
clsPersonaje::~clsPersonaje()
{}
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
string clsPersonaje::getContrasena() const
{
	return contrasena;
}
void clsPersonaje::mostrarDatos() const
{
	cout << "Posicion del personaje: (" << this->x <<","<<this->y << ")" << endl;
}
void clsPersonaje::setContrasena(string contrasena)
{
	this->contrasena = contrasena;
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
	this->b[pos] = valor;
}