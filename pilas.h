#ifndef PILAS_H
#define PILAS_H
#include "Constantes.h"
typedef struct _pila{
	Cadena palabraP;
	_pila *sig;
}tipoPila;

typedef tipoPila *pNodoP;
typedef tipoPila *Pila;

void apilar(Pila &, pNodoP);

bool pilaVacia(Pila piil);

pNodoP desapilar(Pila &);

pNodoP crearNodoP(Cadena);
#endif
