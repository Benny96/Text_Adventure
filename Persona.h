#ifndef _PERSONA_H_
#define _PERSONA_H_

class Persona
{
	char *nombre;

public:
	Persona(const char* nombre);
	virtual ~Persona();
	
	char* getNombre() const;
	virtual void mostrarDatos() const = 0;
};

#endif
