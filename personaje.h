#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#include "Persona.h"
#include <iostream>

#define TAMANYO_PARTIDAS_PERSONAJE 10

class Personaje: public Persona
{
	int nump;
	int x;
	int y;
	int a[TAMANYO_PARTIDAS_PERSONAJE];
	int b[TAMANYO_PARTIDAS_PERSONAJE];
	//int *a;
	//int *b;
	char *contrasena;

public:
	Personaje();
	//Personaje(const char* nombre, int nump, int x, int y, int a, int b, char* contrasena);
	Personaje(const char* nombre, int nump, int x, int y, char* contrasena);

	virtual ~Personaje();
	
	int getNump() const;
	int getX() const;
	int getY() const;
	int getA(int pos) const;
	int getB(int pos) const; 
	char* getContrasena() const;
	virtual void mostrarDatos() const;
	void setContrasena(char * contrasena);
	void setNump(int nump);
	void setX(int x);
	void setY(int y);
	void setA(int pos, int valor);
	void setB(int pos, int valor);
};

#endif



/*
#ifdef __cplusplus
extern "C" {
#endif

#define TAMANYO_CADENAS 20
#define TAMANYO_ARRAYS 10

typedef struct {
	int nump;
	int x;
	int y;
	int a[TAMANYO_ARRAYS];
	int b[TAMANYO_ARRAYS];
	char nombre[TAMANYO_CADENAS];
	char contrasena[TAMANYO_CADENAS];

} Personaje;

#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
//#endif

//#endif

