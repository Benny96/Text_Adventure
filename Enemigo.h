#ifndef _ENEMGIGO_H
#define _ENEMIGO_H

#include "Persona.h"
using namespace std;

class Enemigo: public Persona
{
	int dificultad;

public:
	Enemigo();
	Enemigo(const string nombre, int dificultad);
	int getDificultad() const;
	virtual void mostrarDatos() const;
};

#endif
