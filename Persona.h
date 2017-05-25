#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <string>
using namespace std;

class Persona
{
	string nombre;

public:
	Persona();
	Persona(const string nombre);
	virtual ~Persona();
	
	string getNombre() const;
	void setNombre(string nombre);
	virtual void mostrarDatos() const = 0;
};

#endif
