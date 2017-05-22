#ifndef _PERSONA_H_
#define _PERSONA_H_

class Persona
{
	char *nombre;

public:
	Persona();
	Persona(const char* nombre);
	virtual ~Persona();
	
	char* getNombre() const;
	void setNombre(char * nombre);
	virtual void mostrarDatos() const = 0;
};

#endif
