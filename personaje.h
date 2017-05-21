#ifndef PERSONAJE_H_
#define PERSONAJE_H_

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
#endif

#endif
