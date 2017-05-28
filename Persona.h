/**
 ** @Autores: 
 **
 **	Garikoitz Bereciartua (garibere13) 
 **	Imanol Echeverría (Echever) 
 **	Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** Persona.h es el fichero de cabecera correspondiente a Persona.cpp, y esta clase se
 **	encargará de definir los atributos y métodos de la clase abstracta Persona.
 */

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

	/**
	 ** Constructor vacío de un objeto Persona.
	 */

	Persona();

	/**
	 ** Constructor con parámetros de un objeto Persona.
	 **
	 ** @Param:
	 **
	 ** string nombre: Nombre de la nueva Persona a generar.
	 ** int x: Coordenada X de la nueva Persona.
	 ** int y: Coordenada Y de la nueva Persona.
	 */

	Persona(string nombre, int x, int y);

	/**
	 ** Destructor de Persona. Sabemos que NO ES NECESARIO, al no haber punteros,
	 ** pero lo hemos incluido para que haya constancia de ello de cara a la
	 ** evaluación del proyecto.
	 */

	virtual ~Persona();

	/**
	 ** Método que devolverá el nombre de una persona.
	 **
	 ** @Return:
	 **
	 ** Nombre de la persona.
	 */
	
	string getNombre() const;

	/**
	 ** Método que devolverá el valor de la coordenada X de una persona.
	 **
	 ** @Return:
	 **
	 ** Valor de la coordenada X de la persona.
	 */

	int getX() const;

	/**
	 ** Método que devolverá el valor de la coordenada Y de una persona.
	 **
	 ** @Return:
	 **
	 ** Valor de la coordenada Y de la persona.
	 */

	int getY() const;

	/**
	 ** Método que establecerá el nombre de una persona.
	 **
	 ** @Param:
	 **
	 ** string nombre: Nombre a establecer de la persona.
	 */

	void setNombre(string nombre);

	/**
	 ** Método que establecerá el valor de la coordenada X de una persona.
	 **
	 ** @Param:
	 **
	 ** int x: Valor de la coordenada X a establecer.
	 */

	void setX(int x);

	/**
	 ** Método que establecerá el valor de la coordenada Y de una persona.
	 **
	 ** @Param:
	 **
	 ** int y: Valor de la coordenada Y a establecer.
	 */

	void setY(int y);

	/**
	 ** Método abstracto sin implementación que se dará a las clases hijas para que
	 ** estas lo reimplementen.
	 */

	virtual void mostrarDatos() const = 0;
};

#endif
