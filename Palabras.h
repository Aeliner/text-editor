#ifndef PALABRAS_H
#define PALABRAS_H

#include "Constantes.h"
#include "Diccionario.h"

struct _palabra{
	Cadena palabra;
	struct _palabra *sigP;
};
typedef struct _palabra *Palabras;

// Crea un conjunto de palabras vacio
Palabras CrearPalabras();

// Inserta una palabra en la posicion dada.
TipoRetorno InsertarPalabra(Palabras &palabras, Posicion posicionPalabra,
	Cadena palabraAIngresar);

// Borra la palabra que se encuentra en la posición dada.
TipoRetorno BorrarPalabra(Palabras &palabras, Posicion posicionPalabra);

// Borra todas las ocurrencias de una palabra.
TipoRetorno BorrarOcurrenciasPalabra(Palabras &palabras, Cadena palabraABorrar);

// Borrar todo.
void BorrarTodoPalabras(Palabras &palabras);

// Imprime la línea en pantalla.
void ImprimirPalabras(Palabras palabras);

// Devuelve la cantidad de palabras.
unsigned int CantidadPalabras(Palabras palabras);

// Devuelve en palabra una copia de la palabra que se encuentra
// en la posición dada.
TipoRetorno PalabraEnPosicion(Palabras palabras, Posicion posicionPalabra,
	Cadena &palabra);

//------------------Para Parte 2------------------------
// Muestra solamente las palabras que no se encuentran en el dicionario.
TipoRetorno ImprimirPalabrasIncorrectas(Palabras palabras, Diccionario D);

#endif
