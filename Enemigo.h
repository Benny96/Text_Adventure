#ifndef _ENEMGIGO_H
#define _ENEMIGO_H

#include "Persona.h"

class Enemigo: public Persona
{
	int dificultad;

public:
	Enemigo(const char* nombre, int dificultad);
	int getDificultad() const;
};

#endif
