#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Constantes.h"

struct _diccionario
{
	Cadena palabraD;
	_diccionario *izq;
	_diccionario *der;
};

typedef struct _diccionario *Diccionario, *pNodoD;

Diccionario CrearDiccionario();

// Agrega una palabra al diccionario.
// Ingresa una palabra al diccionario si ésta no se encuentra en el mismo.
TipoRetorno IngresarPalabraDiccionario(Diccionario &D, Cadena palabraAIngresar);

// Borra una palabra del diccionario si se encuentra en el mismo.
TipoRetorno BorrarPalabraDiccionario(Diccionario &D, Cadena palabraABorrar);

// Devuelve true si y sólo si la palabra pertenece al diccionario
bool PerteneceDiccionario(Diccionario D, Cadena palabra);

// Muestra las palabras del diccionario odenadas alfabéticamente, de menor a
// mayor.
// Cuando el diccionario no tiene palabras debe mostrarse el mensaje
// "Diccionario vacio".
TipoRetorno ImprimirDiccionario(Diccionario D);

int contarPalabrasDiccionario(Diccionario);

Diccionario unir(Diccionario, Diccionario);

#endif
