/**
 ** @Autores: 
 **
 ** Garikoitz Bereciartua (garibere13) 
 ** Imanol Echeverría (Echever) 
 ** Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** Implementar los métodos definidos en el archivo de cabecera clsPersonaje.h.
 */

#include "Personaje.h"
#include "clsPersonaje.h"

using namespace std;

clsPersonaje::clsPersonaje(Personaje *p): Persona(string(p->nombre), p->x,p->y)
{
	this->nump = p->nump;
	this->contrasena = string(p->contrasena);
	for (int i = 0; i < TAMANYO_PARTIDAS_PERSONAJE; i++)
	{
		setA(i, p->a[i]);
		setB(i, p->b[i]);
	}
}
clsPersonaje::clsPersonaje(): Persona()
{
	this->nump = 0;
	this->contrasena = string("");
}
clsPersonaje::clsPersonaje(string nombre, int x, int y, int nump, string contrasena): Persona(nombre,x,y)
{
	this->nump = nump;
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
void clsPersonaje::setA(int pos, int valor)
{
	this->a[pos] = valor;
}
void clsPersonaje::setB(int pos, int valor)
{
	this->b[pos] = valor;
}

istream& operator>>(istream &in, clsPersonaje &p)
{
	cout << "Introduce el nombre de tu personaje:" << endl; 
	char * aux = new char[TAMANYO_CADENAS];
	cin >> aux;
	rewind(stdin);
	p.setNombre(aux);

	cout << "Introduce la contrasena de tu personaje:" << endl; 
	char * aux2 = new char[TAMANYO_CADENAS];
	cin >> aux2;
	rewind(stdin);
	p.setContrasena(aux2);
}
ostream& operator<<(ostream &out, const clsPersonaje p)
{
	out << "\t" << p.getNombre() << endl;
	return out;
}