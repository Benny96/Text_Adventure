#ifndef CLS_PERSONAJE_H_
#define CLS_PERSONAJE_H_

#include "Persona.h"
#include "Personaje.h"

using namespace std;

#define TAMANYO_PARTIDAS_PERSONAJE 10

class clsPersonaje: public Persona
{
	int nump;
	int x;
	int y;
	int a[TAMANYO_PARTIDAS_PERSONAJE];
	int b[TAMANYO_PARTIDAS_PERSONAJE];
	string contrasena;

public:
	clsPersonaje(Personaje *p);
	clsPersonaje();
	clsPersonaje(string nombre, int nump, int x, int y, string contrasena);

	virtual ~clsPersonaje();
	
	int getNump() const;
	int getX() const;
	int getY() const;
	int getA(int pos) const;
	int getB(int pos) const; 
	string getContrasena() const;
	virtual void mostrarDatos() const;
	void setContrasena(string contrasena);
	void setNump(int nump);
	void setX(int x);
	void setY(int y);
	void setA(int pos, int valor);
	void setB(int pos, int valor);
};

#endif