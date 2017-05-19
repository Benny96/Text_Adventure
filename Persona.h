#ifndef _PERSONA_H_
#define _PERSONA_H_

class Persona
{
	char *nombre;

public:
	Persona(const char* nombre);
	~Persona();
	
	char* getNombre() const;
};

#endif
