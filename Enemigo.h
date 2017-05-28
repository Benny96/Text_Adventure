/**
 ** @Autores: 
 **
 **	Garikoitz Bereciartua (garibere13) 
 **	Imanol Echeverría (Echever) 
 **	Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** Enemigo.h es el fichero de cabecera correspondiente a Enemigo.cpp, y esta clase se
 **	encargará de definir los atributos y métodos del objeto Enemigo.
 */

#ifndef _ENEMIGO_H
#define _ENEMIGO_H

#include "Persona.h"

/**
 ** Constantes utilizadas para poder inicializar los datos del enemigo.
 */

#define NIVEL_DIFICULTAD 100
#define NOMBRE_DEL_MALO "Darth Vader"

using namespace std;

class Enemigo: public Persona
{
	int dificultad;

public:

	/**
	 ** Constructor vacío de un objeto clsPersonaje.
	 */

	Enemigo();

	/**
	 ** Constructor con parámetros de un objeto Enemiigo, que llamará al constructor de Persona.
	 **
	 ** @Param:
	 **
	 ** string nombre: Nombre del Enemigo a generar.
	 ** int x: Coordenada X del nuevo Enemigo.
	 ** int y: Coordenada Y del nuevo Enemigo.
	 ** int dificultad: Dificultad del nuevo Enemigo.
	 */

	Enemigo(string nombre, int x, int y, int dificultad);

	/**
	 ** Método que devolverá el valor de la dificultad de un enemigo.
	 **
	 ** @Return:
	 **
	 ** Valor de la dificultad del enemigo.
	 */

	int getDificultad() const;

	/**
	 ** Método heredado de Persona que permitirá mostrar algunos datos, para diferenciarlo del
	 ** método implementado en clsPersonaje.
	 */

	virtual void mostrarDatos() const;
};

#endif