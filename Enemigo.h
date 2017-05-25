#ifndef _ENEMGIGO_H
#define _ENEMIGO_H

#include "Persona.h"

#define NIVEL_DIFICULTAD 50
#define NOMBRE_DEL_MALO "Darth Vader"

using namespace std;

class Enemigo: public Persona
{
	int dificultad;

public:
	Enemigo();
	Enemigo(const string nombre, int x, int y, int dificultad);
	int getDificultad() const;
	virtual void mostrarDatos() const;
};

#endif
