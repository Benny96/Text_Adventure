/**
 ** @Autores: 
 **
 **	Garikoitz Bereciartua (garibere13) 
 **	Imanol Echeverría (Echever) 
 **	Beñat Galdós (Benny96)
 **
 ** @Objetivo:
 **
 ** clsPersonaje.h es el fichero de cabecera correspondiente a clsPersonaje.cpp, y esta clase se
 **	encargará de definir los atributos y métodos de nuestro objeto principal en el programa: clsPersonaje.
 */

#ifndef CLS_PERSONAJE_H_
#define CLS_PERSONAJE_H_

#include "Persona.h"
#include "Personaje.h"

using namespace std;

/**
 ** Constante utilizada para poder inicializar los datos del jugador.
 */

#define TAMANYO_PARTIDAS_PERSONAJE 10

/**
 ** Constante utilizada para poder generar un "combate" con el Enemigo.
 */

#define CONSTANTE_PERSONAJE 100

class clsPersonaje: public Persona
{
	int nump;
	int a[TAMANYO_PARTIDAS_PERSONAJE];
	int b[TAMANYO_PARTIDAS_PERSONAJE];
	string contrasena;

public:

	/**
	 ** Constructor que recibe un puntero de Personaje para convertirlo a un objeto clsPersonaje,
	 ** que llamará al constructor de Persona.
	 **
	 ** @Param:
	 **
	 ** Personaje *p: Puntero de struct (Personaje) que recoge los datos del fichero binario.
	 */

	clsPersonaje(Personaje *p);

	/**
	 ** Constructor vacío de un objeto clsPersonaje.
	 */

	clsPersonaje();

	/**
	 ** Constructor con parámetros de un objeto clsPersonaje, que llamará al constructor de Persona.
	 **
	 ** @Param:
	 **
	 ** string nombre: Nombre del clsPersonaje a generar.
	 ** int x: Coordenada X del nuevo clsPersonaje.
	 ** int y: Coordenada Y del nuevo clsPersonaje.
	 ** int nump: Nump del nuevo clsPersonaje.
	 ** string contrasena: Contraseña del nuevo clsPersonaje.
	 */

	clsPersonaje(string nombre, int x, int y, int nump, string contrasena);

	/**
	 ** Destructor de clsPersonaje. Sabemos que NO ES NECESARIO, pero lo hemos incluido para que
	 ** haya constancia de ello de cara a la evaluación del proyecto.
	 */

	virtual ~clsPersonaje();
	
	/**
	 ** Método que devolverá el valor de nump de un personaje.
	 **
	 ** @Return:
	 **
	 ** Valor de nump del personaje.
	 */

	int getNump() const;

	/**
	 ** Método que devolverá el valor de a en una posición determinada.
	 **
	 ** @Param:
	 **
	 ** int pos: Posición del array a a devolver.
	 **
	 ** @Return:
	 **
	 ** Valor de a en la posición determinada del array.
	 */

	int getA(int pos) const;

	/**
	 ** Método que devolverá el valor de b en una posición determinada.
	 **
	 ** @Param:
	 **
	 ** int pos: Posición del array b a devolver.
	 **
	 ** @Return:
	 **
	 ** Valor de b en la posición determinada del array.
	 */

	int getB(int pos) const; 

	/**
	 ** Método que devolverá el valor de la contraseña de un personaje.
	 **
	 ** @Return:
	 **
	 ** Contraseña a devolver.
	 */

	string getContrasena() const;

	/**
	 ** Método heredado de Persona que permitirá mostrar algunos datos, para diferenciarlo del
	 ** método implementado en Enemigo.
	 */

	virtual void mostrarDatos() const;

	/**
	 ** Método que establecerá el valor de la contraseña de un personaje.
	 **
	 ** @Param:
	 **
	 ** string contrasena: Contraseña a guardar.
	 */

	void setContrasena(string contrasena);

	/**
	 ** Método que establecerá el valor de nump de un personaje.
	 **
	 ** @Param:
	 **
	 ** int nump: Valor de nump a guardar.
	 */

	void setNump(int nump);

	/**
	 ** Método que insertará el valor de a en una posición determinada.
	 **
	 ** @Param:
	 **
	 ** int pos: Posición en la que se introducirá el valor.
	 ** int valor: Valor a introducir.
	 */

	void setA(int pos, int valor);

	/**
	 ** Método que insertará el valor de b en una posición determinada.
	 **
	 ** @Param:
	 **
	 ** int pos: Posición en la que se introducirá el valor.
	 ** int valor: Valor a introducir.
	 */

	void setB(int pos, int valor);
};

#endif

/**
 ** Método que sobrecargará el operador >> para poder introducir los datos de un jugador directamente.
 **
 ** @Param:
 **
 ** istream &in: Una referencia al torrente de entrada.
 ** clsPersonaje &p: Una referencia al personaje que queramos construir con dichos datos.
 **
 ** @Return:
 **
 ** Referencia a istream para poder usarlo con el cin.
 */

istream& operator>>(istream &in, clsPersonaje &p);

/**
 ** Método que sobrecargará el operador >> para poder mostrar los datos de un jugador directamente.
 **
 ** @Param:
 **
 ** ostream &out: Una referencia al torrente de salida
 ** const clsPersonaje p: El personaje que queremos mostrar mediante el cout.
 **
 ** @Return:
 **
 ** Referencia a ostream para poder usarlo con el cout.
 */

ostream& operator<<(ostream &out, const clsPersonaje p);