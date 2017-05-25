#ifndef _PERSONA_H_
#define _PERSONA_H_


#include <string>
using namespace std;

class Persona
{
	char *nombre;

public:
	Persona();
	Persona(const char* nombre);
	Persona(const string nombre);
	virtual ~Persona();
	
	char* getNombre() const;
	void setNombre(char * nombre);
	virtual void mostrarDatos() const = 0;
};

#endif
