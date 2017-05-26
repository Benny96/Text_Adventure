#ifndef CLS_PERSONAJE_H_
#define CLS_PERSONAJE_H_

#include "Persona.h"
#include "Personaje.h"

using namespace std;

#define TAMANYO_PARTIDAS_PERSONAJE 10

class clsPersonaje: public Persona
{
	int nump;
	int a[TAMANYO_PARTIDAS_PERSONAJE];
	int b[TAMANYO_PARTIDAS_PERSONAJE];
	string contrasena;

public:
	clsPersonaje(Personaje *p);
	clsPersonaje();
	clsPersonaje(string nombre, int x, int y, int nump, string contrasena);

	virtual ~clsPersonaje();
	
	int getNump() const;
	int getA(int pos) const;
	int getB(int pos) const; 
	string getContrasena() const;
	virtual void mostrarDatos() const;
	void setContrasena(string contrasena);
	void setNump(int nump);
	void setA(int pos, int valor);
	void setB(int pos, int valor);
};

#endif

istream& operator>>(istream &in, clsPersonaje &p);
ostream& operator<<(ostream &out, const clsPersonaje p);
