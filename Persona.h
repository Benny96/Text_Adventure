#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <string.h>

#include <string>
#include <iostream>

using namespace std;

class Persona
{
protected:
	string nombre;
	int x;
	int y;
public:
	Persona();
	Persona(const string nombre, int x, int y);
	virtual ~Persona();
	
	string getNombre() const;
	void setNombre(string nombre);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	virtual void mostrarDatos() const = 0;
};

#endif
